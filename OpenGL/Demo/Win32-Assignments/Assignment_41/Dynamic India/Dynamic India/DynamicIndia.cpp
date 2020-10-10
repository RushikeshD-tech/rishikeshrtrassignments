#include<windows.h>
#include<stdio.h>
#include<math.h>
#include"resource.h"
#include<gl/GL.h>
#include<gl/GLU.h>
//#include <GL/glut.h>
#pragma once
#pragma comment(lib, "Opengl32.lib") //lib-import library
#pragma comment(lib,"glu32.lib")
#define Win_Width 800
#define Win_Height 600
#define GL_PI 3.1415f
#define Thickness 10.0000

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
FILE* gpFile = NULL;
RECT rcWnd;

// global Variable declarations
DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
bool gbFullscreen = false;
bool gbActiveWindow = false;
bool Bdone = false;
HWND ghwnd = NULL;
HDC ghdc = NULL;
HGLRC ghrc = NULL;
GLfloat I1x1 = -3.0f;
GLfloat Ny1 = -3.0f;
GLfloat Dz1 = -3.0f;
GLfloat I2y2 = -3.0f;
GLfloat Ax2 = -3.0f;


// WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function declarations 
	void Initialize(void);
	void uninitialize(void);
	void Display(void);
	//void circle(void);
	//retupRC();

	// variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");
	bool BDone = false;


	if (fopen_s(&gpFile, "RADLog.txt", "w") != 0)
	{
		MessageBox(NULL, TEXT("Can Not Open Desired File"), TEXT("Error"), MB_OK);
		exit(0);
	}
	else
	{
		//fprintf(gpFile, "LOG File Successfully Created.Program Started SuccessFully");
	}
	// code
	// intialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	//wndclass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	//wndclass.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);

	// register above class
	RegisterClassEx(&wndclass);

	//create window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
		szAppName,
		TEXT("Rishikesh Dumbre"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		100,
		100,
		Win_Width,
		Win_Height,
		NULL,
		NULL,
		hInstance,
		NULL);

	GetWindowRect(hwnd, &rcWnd);

	rcWnd.left = ((GetSystemMetrics(SM_CXSCREEN) - (rcWnd.right - rcWnd.left)) / 2);
	rcWnd.top = ((GetSystemMetrics(SM_CYSCREEN) - (rcWnd.bottom - rcWnd.top)) / 2);

	SetWindowPos(hwnd, NULL, rcWnd.left, rcWnd.top, 800, 600, SWP_NOSIZE | SWP_NOZORDER);

	ghwnd = hwnd;
	Initialize();
	ShowWindow(hwnd, iCmdShow);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	// Message loop // Game loop
	while (BDone == false)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				BDone = true;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

		}
		else
		{
			if (gbActiveWindow == true)
			{
				//HERE YOU SHOULD CALL UPDATE FUNCTION FOR OPENGL RENDERING.........
				//HERE YOU SHOULD CALL DISPLAY FUNCTION FOR OPENGL RENDERING...........
				Display();
				//circle();
			}
		}

	}
	return((int)msg.wParam);

}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	// local function declaration
	void ToggleFullScreen(void);
	void Resize(int, int);
	void unintialize(void);
	//void Display(void);
	void circle(void);
	// local variable declarations

	TCHAR str[] = TEXT("Hello World!!!");

	switch (iMsg)
	{
	case WM_SETFOCUS:
		gbActiveWindow = true;
		break;
	case WM_KILLFOCUS:
		gbActiveWindow = false;
		break;
	case WM_ERASEBKGND:
		return(0);
	case WM_SIZE:
		Resize(LOWORD(lParam), HIWORD(lParam));
		break;
		//case WM_PAINT:
			//Display();
			//break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
			break;
		case 0x46:       // Capital 'F' hexadecimal value of 70
		case 0x66:       // Small 'f' hexadecimal value of 102
			ToggleFullScreen();
			break;
		default:
			break;
		}
		break;
		//case WM_CLOSE:
			//DestroyWindow(hwnd);
			//break;
	case WM_DESTROY:
		unintialize();
		PostQuitMessage(0);
		break;

		//}//break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void ToggleFullScreen(void)
{
	//function declaration
	void Resize(int, int);

	// local Variable declaration
	MONITORINFO mi{ sizeof(MONITORINFO) };

	// code
	if (gbFullscreen == false)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);

			}
		}
		ShowCursor(FALSE);
		gbFullscreen = true;
	}
	else
	{
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);
		gbFullscreen = false;
	}

}
void Initialize(void)
{
	//function declaration
	void Resize(int, int);

	//variable declaration
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex;

	//code
	ghdc = GetDC(ghwnd);
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixelFormate Function Failed");
		DestroyWindow(ghwnd);

	}
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat Function Failed");
		DestroyWindow(ghwnd);
	}
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext Function Failed");
		DestroyWindow(ghwnd);

	}
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, ("wglMakeCurrent Function Failed"));
		DestroyWindow(ghwnd);
	}
	//set clearcolor

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Resize(Win_Width, Win_Height);  // warmup call to resize
}
void Resize(int width, int height)
{
	//code
	if (height == 0)
	{
		height = 1;

	}


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}


//Drawing function
void Display(void)
{
	//Function declarations
	void I1(void);
	void N(void);
	void D(void);
	void I2(void);
	void A(void);
	void ColorLines(void);


//	I1 Translate 
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(I1x1, 0.0f, -3.0f);
	
	if (I1x1 <= -1.8f)
	{
		I1x1 = I1x1 + 0.0005f;
	}

	glScalef(0.6f, 0.6f, 0.0f);
	I1();
	
// N Translate
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-0.99f, -Ny1, -3.0f);

	if (Ny1 <= -0.001f)
	{
		Ny1 = Ny1 + 0.0005f;
	}

	glScalef(0.6f, 0.6f, 0.0f);
	N();

// D Translate	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glTranslatef(0.0f, 0.0f, Dz1);
	if (Dz1 <= 0.0f)
	{
		Dz1 = Dz1 + 0.0005f;
	}
	glScalef(0.6f, 0.6f, 0.0f);
	D();

//  I2 Translate

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.70f, I2y2, -3.0f);

	if (I2y2 <= 0.001f)
	{
		I2y2 = I2y2 + 0.0005f;
	}

	glScalef(0.6f, 0.6f, 0.0f);
	I2();

// A Translate

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-Ax2, 0.0f, -3.0f);

    if (Ax2 <= -1.5f)
	{
		Ax2 = Ax2 + 0.0005f;
	}
     glScalef(0.6f, 0.6f, 0.0f);
	A();


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.99f, 0.0f, -3.0f);
	ColorLines();

	SwapBuffers(ghdc);
}

//Resize the window
void resize(int width, int height)
{
	//code
	if (height == 0)
		height = 1;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

}

//Uninitialize all the resources on exit
void uninitialize(void)
{
	//UNINITIALIZATION CODE

	if (gbFullscreen == true)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);

	}

	wglMakeCurrent(NULL, NULL);

	wglDeleteContext(ghrc);
	ghrc = NULL;

	ReleaseDC(ghwnd, ghdc);
	ghdc = NULL;

	DestroyWindow(ghwnd);
	ghwnd = NULL;
}

//Draw alphabet I
void I1(void)
{
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.9f, 0.0f);
	glVertex3f(0.5f, 0.8f, 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, 0.8f, 0.0f);
	glVertex3f(-0.5f, 0.9f, 0.0f);

	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.8f, 0.0f);
	glVertex3f(-0.5f, -0.9f, 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.9f, 0.0f);
	glVertex3f(0.5f, -0.8f, 0.0f);

	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-0.05f, 0.9f, 0.0f);
	glVertex3f(-0.05f, -0.9f, 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(0.05f, -0.8f, 0.0f);
	glVertex3f(0.05f, 0.8f, 0.0f);
	glEnd();
}

//Draw alphabet N
void N(void)
{
	glBegin(GL_QUADS);


	glVertex3f(-0.6f, 0.9f, 0.0f);
	glVertex3f(-0.6f, -0.9f, 0.0f);
	glVertex3f(-0.5f, -0.9f, 0.0f);
	glVertex3f(-0.5f, 0.9f, 0.0f);

	glVertex3f(-0.6f, 0.9f, 0.0f);
	glVertex3f(-0.5f, 0.9f, 0.0f);
	glVertex3f(0.6f, -0.9f, 0.0f);
	glVertex3f(0.5f, -0.9f, 0.0f);

	glVertex3f(0.6f, 0.9f, 0.0f);
	glVertex3f(0.6f, -0.9f, 0.0f);
	glVertex3f(0.5f, -0.9f, 0.0f);
	glVertex3f(0.5f, 0.9f, 0.0f);
	glEnd();
}

//Draw alphabet D
void D(void)
{
	glBegin(GL_QUADS);

	glVertex3f(-0.6f, 0.9f, 0.0f);       // Horizontal line
	glVertex3f(-0.6f, 0.8f, 0.0f);
	glVertex3f(0.5f, 0.8f, 0.0f);
	glVertex3f(0.5f, 0.9f, 0.0f);

	glVertex3f(-0.5f, 0.9f, 0.0f);        //line one 
	glVertex3f(-0.5f, -0.9f, 0.0f);
	glVertex3f(-0.4f, -0.9f, 0.0f);
	glVertex3f(-0.4f, 0.9f, 0.0f);

	glVertex3f(0.5f, 0.9f, 0.0f);         //line two
	glVertex3f(0.5f, -0.9f, 0.0f);
	glVertex3f(0.4f, -0.9f, 0.0f);
	glVertex3f(0.4f, 0.9f, 0.0f);

	glVertex3f(-0.6f, -0.9f, 0.0f);       // Horizontal line
	glVertex3f(-0.6f, -0.8f, 0.0f);
	glVertex3f(0.5f, -0.8f, 0.0f);
	glVertex3f(0.5f, -0.9f, 0.0f);
	glEnd();
}

//Draw alphabet I
void I2(void)
{
	glBegin(GL_QUADS);

	glVertex3f(0.5f, 0.9f, 0.0f);
	glVertex3f(0.5f, 0.8f, 0.0f);
	glVertex3f(-0.5f, 0.8f, 0.0f);
	glVertex3f(-0.5f, 0.9f, 0.0f);


	glVertex3f(-0.5f, -0.8f, 0.0f);
	glVertex3f(-0.5f, -0.9f, 0.0f);
	glVertex3f(0.5f, -0.9f, 0.0f);
	glVertex3f(0.5f, -0.8f, 0.0f);

	glVertex3f(-0.05f, 0.9f, 0.0f);
	glVertex3f(-0.05f, -0.9f, 0.0f);
	glVertex3f(0.05f, -0.8f, 0.0f);
	glVertex3f(0.05f, 0.8f, 0.0f);
	glEnd();
}

//Draw alphabet A
void A(void)
{
	glBegin(GL_QUADS);
	glVertex3f(0.4f, 0.9f, 0.0f);       // slanting  line
	glVertex3f(0.3f, 0.9f, 0.0f);
	glVertex3f(-0.4f, -0.9f, 0.0f);
	glVertex3f(-0.3f, -0.9f, 0.0f);

	glVertex3f(0.4f, 0.9f, 0.0f);       // slanting line
	glVertex3f(0.3f, 0.9f, 0.0f);
	glVertex3f(0.85f, -0.9f, 0.0f);
	glVertex3f(0.95, -0.9f, 0.0f);
	glEnd();


}

void ColorLines(void)
{

	glLineWidth(10.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.5f, 0.0f);	//Orange color
	glVertex3f(0.500f, 0.02f, 0.0f);
	glVertex3f(0.850f, 0.02f, 0.0f);


	glColor3f(1.0f, 1.0f, 1.0f);	//White
	glVertex3f(0.49f, 0.0f, 0.0f);
	glVertex3f(0.86f, 0.0f, 0.0f);


	glColor3f(0.0f, 1.0f, 0.0f);	//Green color
	glVertex3f(0.500f, -0.02f, 0.0f);
	glVertex3f(0.855f, -0.02f, 0.0f);


	glEnd();
}

void unintialize(void)
{
	//code
	if (gbFullscreen == true)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);
	}
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);

	}
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;

	}
	if (gpFile)
	{
		fprintf(gpFile, "LOG File Successfully Closed.Program Ended SuccessFully");
		fclose(gpFile);
		gpFile = NULL;
		//return(0);
	}
}



