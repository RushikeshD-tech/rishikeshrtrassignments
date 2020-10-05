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



// WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function declarations 
	void Initialize(void);
	void Display(float size);
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
				Display(0.00001f);
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

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}



void Display(float size)
{

	//void ConcentricCircle(void);
	void CircleColor(float);
	// Variable Declaration
	//code
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //for Perspective
	glLoadIdentity(); //for Perspective
	glTranslatef(0.0f, 0.0f, -3.0f);
    GLint circle_points = 1000;
	GLfloat angle;
	GLfloat radius ;
	
	//CircleColor(size);
	 glColor3f(1.0f, 1.0f, 0.0f);                                           //Red
	for (radius = 0.05f; radius <= 1.0f; radius = radius + 0.1f)
	{
		glBegin(GL_POINTS);
	  CircleColor(size);
		for (angle = 0.0f; angle <= 2 * GL_PI; angle = angle + 0.01f)
		{
			glVertex2f((radius * cos(angle)), (radius * sin(angle)));
		}
		glEnd();	
	}
	SwapBuffers(ghdc);
}


void CircleColor(float value)
{
	if (0.05f - value < 0.00001f)	//red
	{
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	if (0.06f - value < 0.00001f)	//green
	{
		glColor3f(0.647059f, 0.164706f, 0.164706f);
	}
	if (0.07f - value < 0.00001f)	//blue
	{
		glColor3f(0.5f, 0.5f, 0.5f);
	}
	if (0.08f - value < 0.00001f)	//cyan
	{
		glColor3f(1.0f, 0.5f, 0.0f);
	}
	if (0.09f - value < 0.00001f)	//magenta
	{
		glColor3f(1.0f, 1.0f, 0.0f);
	}
	if (0.10f - value < 0.00001f)	//yellow
	{
		glColor3f(1.0f, 0.0f, 1.0f);
	}
	if (0.11f - value < 0.00001f)	//orange
	{
		glColor3f(0.0f, 1.0f, 1.0f);
	}
	if (0.12f - value < 0.00001f)	//gray
	{
		glColor3f(0.0f, 0.0f, 1.0f);
	}
	if (0.13f - value < 0.00001f)	//brown 
	{
		glColor3f(0.0f, 1.0f, 0.0f);
	}
	if (0.14f - value < 0.00001f)	//white
	{
		glColor3f(1.0f, 0.0f, 0.0f);
	}

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
















