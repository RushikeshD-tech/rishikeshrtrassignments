//Header File 
#include<windows.h>
#include<stdio.h>
#include"DoubleBuffer1.h"
#include <gl/GL.h>
#include<gl/GLU.h>
#include <iostream>
#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"glu32.lib")
#define Win_Width 1200
#define Win_Height 800

//Global Function Declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
FILE* gpFile = NULL;
RECT rcWnd_RAD;

//Global Variable Declarations
DWORD dwStyle_RAD;
WINDOWPLACEMENT wpPrev_RAD = { sizeof(WINDOWPLACEMENT) };
bool gbFullscreen_RAD = false;
bool gbActiveWindow_RAD = false;
bool Bdone_RAD = false;
HWND ghwnd_RAD = NULL;
HDC ghdc_RAD = NULL;
HGLRC ghrc_RAD = NULL; 

bool bLight = false;

GLfloat lightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };  // Grey Light
GLfloat lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };   // White Light
GLfloat lightPosition[] = { 100.0f, 100.0f, 100.0f, 1.0f };
GLfloat lightSpeculiar[] = { 1.0f, 1.0f, 1.0f, 1.0f};

GLfloat materialAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat materialDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat materialSpeculiar[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat materialShinyness (50.0f);
/*
GLfloat lightAmbient[] = { 0.1f, 0.1f, 0.1f, 1.0f };  // Grey Light
GLfloat lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };   // White Light
GLfloat lightPosition[] = { 100.0f, 100.0f, 100.0f, 1.0f };
GLfloat lightSpeculiar[] = { 1.0f, 1.0f, 1.0f, 1.0f };

GLfloat materialAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat materialDiffuse[] = { 0.5f, 0.2f, 0.7f, 1.0f };
GLfloat materialSpeculiar[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat materialShinyness(128.0f);
*/
GLUquadric* quadric = NULL;
 
//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Function Declarations
	void Initialize(void);
	void Display(void);
	
	//Variable Declarations
	WNDCLASSEX wndclass_RAD;
	HWND hwnd_RAD;
	MSG msg_RAD;
	TCHAR szAppName_RAD[] = TEXT("MyApp");
	bool BDone_RAD = false;
	

	if (fopen_s(&gpFile, "RADLog.txt", "w") != 0)
	{
		MessageBox(NULL, TEXT("Can Not Open Desired File"), TEXT("Error"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "LOG File Successfully Created.Program Started SuccessFully");
	}
	// code
	// Intialization of WNDCLASSEX
	wndclass_RAD.cbSize = sizeof(WNDCLASSEX);
	wndclass_RAD.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass_RAD.cbClsExtra = 0;
	wndclass_RAD.cbWndExtra = 0;
	wndclass_RAD.lpfnWndProc = WndProc;
	wndclass_RAD.hInstance = hInstance;
	wndclass_RAD.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass_RAD.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass_RAD.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass_RAD.lpszClassName = szAppName_RAD;
	wndclass_RAD.lpszMenuName = NULL;
	wndclass_RAD.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));


	// Register above class
	RegisterClassEx(&wndclass_RAD);

	//Create Window
	hwnd_RAD = CreateWindowEx(WS_EX_APPWINDOW,
		szAppName_RAD,
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

	GetWindowRect(hwnd_RAD, &rcWnd_RAD);

	rcWnd_RAD.left = ((GetSystemMetrics(SM_CXSCREEN) - (rcWnd_RAD.right - rcWnd_RAD.left)) / 2);
	rcWnd_RAD.top = ((GetSystemMetrics(SM_CYSCREEN) - (rcWnd_RAD.bottom - rcWnd_RAD.top)) / 2);

	SetWindowPos(hwnd_RAD, NULL, rcWnd_RAD.left, rcWnd_RAD.top, 800, 600, SWP_NOSIZE | SWP_NOZORDER);

	ghwnd_RAD = hwnd_RAD;
	Initialize();
	ShowWindow(hwnd_RAD, iCmdShow);
	SetForegroundWindow(hwnd_RAD);
	SetFocus(hwnd_RAD);

	// Message loop or Game loop
	while (BDone_RAD == false)
	{
		if (PeekMessage(&msg_RAD, NULL, 0, 0, PM_REMOVE))
		{
			if (msg_RAD.message == WM_QUIT)
			{
				BDone_RAD = true;
			}
			else
			{
				TranslateMessage(&msg_RAD);
				DispatchMessage(&msg_RAD);
			}

		}
		else
		{
			if (gbActiveWindow_RAD == true)
			{
				//HERE YOU SHOULD CALL UPDATE FUNCTION FOR OPENGL RENDERING.........
				//HERE YOU SHOULD CALL DISPLAY FUNCTION FOR OPENGL RENDERING...........
				Display();
			}
		}

	}
	return((int)msg_RAD.wParam);

}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	// local function declaration
	void ToggleFullScreen(void);
	void Resize(int, int);
	void unintialize(void);
	

	TCHAR str[] = TEXT("Hello World!!!");

	switch (iMsg)
	{
	case WM_SETFOCUS:
		gbActiveWindow_RAD = true;
		break;
	case WM_KILLFOCUS:
		gbActiveWindow_RAD = false;
		break;
	case WM_ERASEBKGND:
		return(0);
	case WM_SIZE:
		Resize(LOWORD(lParam), HIWORD(lParam));
		break;
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
		case 0x4C:	//For 'l' or 'L'
			if (bLight == false)
			{
				bLight = true;
				glEnable(GL_LIGHTING);
			}
			else
			{
				bLight = false;
				glDisable(GL_LIGHTING);
			}
			break;
		case 48:
		//case NUMPAD 0:
			glViewport(0, 0,(GLsizei)Win_Width,(GLsizei)Win_Height);
			break;
		case 49:
		//case NUMPAD 1:
			glViewport(0, Win_Height/2, (GLsizei)Win_Width/2, (GLsizei)Win_Height/2);
			break;
		case 50:
		//case NUMPAD 2:
			glViewport(Win_Width/2, Win_Height/2, (GLsizei)Win_Width/2, (GLsizei)Win_Height/2);
			break;

		case 51:
		//case NUMPAD 3:
			glViewport(Win_Width/2, 0,(GLsizei)Win_Width/2, (GLsizei)Win_Height/2);
			break;
		case 52:
		//case NUMPAD 4:
			glViewport(0, 0, (GLsizei)Win_Width/2, (GLsizei)Win_Height/2);
			break;
		case 53:
		//case NUMPAD 5:
			glViewport(0, 0, (GLsizei)Win_Width/2, (GLsizei)Win_Height);
			break;
		case 54:
		//case NUMPAD 6:
			glViewport(Win_Width/2, 0, (GLsizei)Win_Width/2, (GLsizei)Win_Height);
			break;
		case 55:
		//case NUMPAD 7:
			glViewport(0, Win_Height/2, (GLsizei)Win_Width, (GLsizei)Win_Height/2);
			break;
		case 56:
		//case NUMPAD 8:
			glViewport(0, 0, (GLsizei)Win_Width, (GLsizei)Win_Height / 2);
			break;
		case 57:
		//case NUMPAD 9:
			glViewport(Win_Width/4, Win_Height/4, (GLsizei)Win_Width/2, (GLsizei)Win_Height/2);
			break;


		default:
			break;
		}
		break;
	case WM_DESTROY:
		unintialize();
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void ToggleFullScreen(void)
{
	//Function Declaration
	void Resize(int, int);

	// Local Variable Declaration
	MONITORINFO mi{ sizeof(MONITORINFO) };

	// Code
	if (gbFullscreen_RAD == false)
	{
		dwStyle_RAD = GetWindowLong(ghwnd_RAD, GWL_STYLE);
		if (dwStyle_RAD & WS_OVERLAPPEDWINDOW)
		{
			if (GetWindowPlacement(ghwnd_RAD, &wpPrev_RAD) && GetMonitorInfo(MonitorFromWindow(ghwnd_RAD, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd_RAD, GWL_STYLE, dwStyle_RAD & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(ghwnd_RAD, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);

			}
		}
		ShowCursor(FALSE);
		gbFullscreen_RAD = true;
	}
	else
	{
		SetWindowLong(ghwnd_RAD, GWL_STYLE, dwStyle_RAD | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd_RAD, &wpPrev_RAD);
		SetWindowPos(ghwnd_RAD, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);
		gbFullscreen_RAD = false;
	}

}
void Initialize(void)
{
	//Function Declaration
	void Resize(int, int);

	//Variable Declaration
	PIXELFORMATDESCRIPTOR pfd_RAD;
	int iPixelFormatIndex_RAD;

	//Code
	ghdc_RAD = GetDC(ghwnd_RAD);
	ZeroMemory(&pfd_RAD, sizeof(PIXELFORMATDESCRIPTOR));
	pfd_RAD.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd_RAD.nVersion = 1;
	pfd_RAD.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd_RAD.iPixelType = PFD_TYPE_RGBA;
	pfd_RAD.cColorBits = 32;
	pfd_RAD.cRedBits = 8;
	pfd_RAD.cGreenBits = 8;
	pfd_RAD.cBlueBits = 8;
	pfd_RAD.cAlphaBits = 8;
	iPixelFormatIndex_RAD = ChoosePixelFormat(ghdc_RAD, &pfd_RAD);
	if (iPixelFormatIndex_RAD == 0)
	{
		fprintf(gpFile, "ChoosePixelFormate Function Failed");
		DestroyWindow(ghwnd_RAD);

	}
	if (SetPixelFormat(ghdc_RAD, iPixelFormatIndex_RAD, &pfd_RAD) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat Function Failed");
		DestroyWindow(ghwnd_RAD);
	}
	ghrc_RAD = wglCreateContext(ghdc_RAD);
	if (ghrc_RAD == NULL)
	{
		fprintf(gpFile, "wglCreateContext Function Failed");
		DestroyWindow(ghwnd_RAD);

	}
	if (wglMakeCurrent(ghdc_RAD, ghrc_RAD) == FALSE)
	{
		fprintf(gpFile, ("wglMakeCurrent Function Failed"));
		DestroyWindow(ghwnd_RAD);
	}
	//Set ClearColor
      glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	  glClearDepth(1.0f);
	  glEnable(GL_DEPTH_TEST);
	  glDepthFunc(GL_LEQUAL);
	  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	  glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
	  glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
	  glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpeculiar);
	 
	  glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
	  glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
	  glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpeculiar);
	  glMaterialf(GL_FRONT, GL_SHININESS, materialShinyness);
	  
	  glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
	  glEnable(GL_LIGHT1);

	Resize(Win_Width, Win_Height);  // Warmup Call To Resize
}
void Resize(int width, int height)
{
	//Code
	if (height == 0)
	{
		height = 1;

	}
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}
void Display(void)
{
	//Code
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -0.55f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	quadric = gluNewQuadric();
	gluSphere(quadric, 0.2f, 30, 30); // Normals are calculated by gluSphere itself
	SwapBuffers(ghdc_RAD);

}

void unintialize(void)
{
	//Code
	if (gbFullscreen_RAD == true)
	{
		dwStyle_RAD = GetWindowLong(ghwnd_RAD, GWL_STYLE);
		SetWindowLong(ghwnd_RAD, GWL_STYLE, dwStyle_RAD & ~WS_OVERLAPPEDWINDOW);
		SetWindowLong(ghwnd_RAD, GWL_STYLE, dwStyle_RAD | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd_RAD, &wpPrev_RAD);
		SetWindowPos(ghwnd_RAD, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);
	}
	if (wglGetCurrentContext() == ghrc_RAD)
	{
		wglMakeCurrent(NULL, NULL);
		gluDeleteQuadric(quadric);
	}
	if (ghrc_RAD)
	{
		wglDeleteContext(ghrc_RAD);
		ghrc_RAD = NULL;
	}
	if (ghdc_RAD)
	{
		ReleaseDC(ghwnd_RAD, ghdc_RAD);
		ghdc_RAD = NULL;

	}
	if (gpFile)
	{
		fprintf(gpFile, "LOG File Successfully Closed.Program Ended SuccessFully");
		fclose(gpFile);
		gpFile = NULL;

	}
}
















