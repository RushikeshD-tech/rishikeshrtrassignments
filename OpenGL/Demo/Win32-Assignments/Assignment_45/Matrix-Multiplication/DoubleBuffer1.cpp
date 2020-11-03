//Header File 
#include<windows.h>
#include<windowsx.h>
#include<stdio.h>
#include"DoubleBuffer1.h"
#include <gl/GL.h>
#include<gl/GLU.h>
#include<math.h>                                            // ?????
#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"glu32.lib")
#define Win_Width 1024
#define Win_Height 720
#define _USE_MATH_DEFINES 1 
#define M_PI  3.14159265359 
//const double M_PI; 

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

GLfloat angle_radian = 0.0f;
GLfloat angle_degree = 0.0f;



//static GLfloat angle_Cube;
GLfloat  Identity_Matrix[16];
GLfloat  Translation_Matrix[16];
GLfloat  Scale_Matrix[16];

GLfloat RotationMatrix_x[16];
GLfloat RotationMatrix_y[16];
GLfloat RotationMatrix_z[16];





//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//Function Declarations
	void Initialize(void);
	void Display(void);
	void update(void);

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
				update();
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
	pfd_RAD.cDepthBits = 32;  // depth bits
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
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	  
	  //Initialize the Identity Matrix
	  Identity_Matrix[0] = 1.0f;
	  Identity_Matrix[1] = 0.0f;
	  Identity_Matrix[2] = 0.0f;
	  Identity_Matrix[3] = 0.0f;
	  Identity_Matrix[4] = 0.0f;
	  Identity_Matrix[5] = 1.0f;
	  Identity_Matrix[6] = 0.0f;
	  Identity_Matrix[7] = 0.0f;
	  Identity_Matrix[8] = 0.0f;
	  Identity_Matrix[9] = 0.0f;
	  Identity_Matrix[10] = 1.0f;
	  Identity_Matrix[11] = 0.0f;
	  Identity_Matrix[12] = 0.0f;
	  Identity_Matrix[13] = 0.0f;
	  Identity_Matrix[14] = 0.0f;
	  Identity_Matrix[15] = 1.0f;

	  //Initialize the Translation Matrix
	  Translation_Matrix[0] = 1.0f;
	  Translation_Matrix[1] = 0.0f;
	  Translation_Matrix[2] = 0.0f;
	  Translation_Matrix[3] = 0.0f;
	  Translation_Matrix[4] = 0.0f;
	  Translation_Matrix[5] = 1.0f;
	  Translation_Matrix[6] = 0.0f;
	  Translation_Matrix[7] = 0.0f;
	  Translation_Matrix[8] = 0.0f;
	  Translation_Matrix[9] = 0.0f;
	  Translation_Matrix[10] = 1.0f;
	  Translation_Matrix[11] = 0.0f;
	  Translation_Matrix[12] = 0.0f;
	  Translation_Matrix[13] = 0.0f;
	  Translation_Matrix[14] = -6.0f;
	  Translation_Matrix[15] = 1.0f;

	  //Initialize Scale Matrix
	  Scale_Matrix[0] = 0.75f;
	  Scale_Matrix[1] = 0.0f;
	  Scale_Matrix[2] = 0.0f;
	  Scale_Matrix[3] = 0.0f;
	  Scale_Matrix[4] = 0.0f;
	  Scale_Matrix[5] = 0.75f;
	  Scale_Matrix[6] = 0.0f;
	  Scale_Matrix[7] = 0.0f;
	  Scale_Matrix[8] = 0.0f;
	  Scale_Matrix[9] = 0.0f;
	  Scale_Matrix[10] = 0.75f;
	  Scale_Matrix[11] = 0.0f;
	  Scale_Matrix[12] = 0.0f;
	  Scale_Matrix[13] = 0.0f;
	  Scale_Matrix[14] = 0.0f;
	  Scale_Matrix[15] = 1.0f;

	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

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
	//Variable Declaration
	GLfloat angle_radian = 0.2f;
	
	//Code
	
	angle_radian = angle_degree * (M_PI / 180.0f);

	//Initialize the X Rotation Matrix

	RotationMatrix_x[0] = 1.0f;
	RotationMatrix_x[1] = 0.0f;
	RotationMatrix_x[2] = 0.0f;
	RotationMatrix_x[3] = 0.0f;
	RotationMatrix_x[4] = 0.0f;
	RotationMatrix_x[5] = cos(angle_radian);
	RotationMatrix_x[6] = sin(angle_radian);
	RotationMatrix_x[7] = 0.0f;
	RotationMatrix_x[8] = 0.0f;
	RotationMatrix_x[9] = -sin(angle_radian);
	RotationMatrix_x[10] = cos(angle_radian);
	RotationMatrix_x[11] = 0.0f;
	RotationMatrix_x[12] = 0.0f;
	RotationMatrix_x[13] = 0.0f;
	RotationMatrix_x[14] = 0.0f;
	RotationMatrix_x[15] = 1.0f;
	
//Initialize the Y Rotation Matrix
	RotationMatrix_y[0] = cos(angle_radian);
	RotationMatrix_y[1] = 0.0f;
	RotationMatrix_y[2] = -sin(angle_radian);
	RotationMatrix_y[3] = 0.0f;
	RotationMatrix_y[4] = 0.0f;
	RotationMatrix_y[5] = 1.0f;
	RotationMatrix_y[6] = 0.0f;
	RotationMatrix_y[7] = 0.0f;
	RotationMatrix_y[8] = sin(angle_radian);
	RotationMatrix_y[9] = 0.0f;
	RotationMatrix_y[10] = cos(angle_radian);
	RotationMatrix_y[11] = 0.0f;
	RotationMatrix_y[12] = 0.0f;
	RotationMatrix_y[13] = 0.0f;
	RotationMatrix_y[14] = 0.0f;
	RotationMatrix_y[15] = 1.0f;
	
	//Initialize the Z Rotation Matrix

	RotationMatrix_z[0] = cos(angle_radian);
	RotationMatrix_z[1] = sin(angle_radian);
	RotationMatrix_z[2] = 0.0f;
	RotationMatrix_z[3] = 0.0f;
	RotationMatrix_z[4] = -sin(angle_radian);
	RotationMatrix_z[5] = cos(angle_radian);
	RotationMatrix_z[6] = 0.0f;
	RotationMatrix_z[7] = 0.0f;
	RotationMatrix_z[8] = 0.0f;
	RotationMatrix_z[9] = 0.0f;
	RotationMatrix_z[10] = 1.0f;
	RotationMatrix_z[11] = 0.0f;
	RotationMatrix_z[12] = 0.0f;
	RotationMatrix_z[13] = 0.0f;
	RotationMatrix_z[14] = 0.0f;
	RotationMatrix_z[15] = 1.0f;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/****************CUBE********************/

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(Identity_Matrix);
	glMultMatrixf(Translation_Matrix);
	glMultMatrixf(Scale_Matrix);


	
	glMultMatrixf(RotationMatrix_x);
	glMultMatrixf(RotationMatrix_y);
	glMultMatrixf(RotationMatrix_z);


	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	glColor3f(0.0f, 0.1f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);

//Right surface

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	glColor3f(0.0f, 0.1f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	
// Back Surface

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glColor3f(0.0f, 0.1f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	
// Left Surface

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	glColor3f(0.0f, 0.1f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	// Top Surface

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	glColor3f(0.0f, 0.1f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);

	// Bottom Surface

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	glColor3f(0.0f, 0.1f, 0.0f);
	glVertex3f(0.5f,-0.5f, 0.5f);

	
	//angle_radian = angle_radian + 0.2f;
	glEnd();
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

void update(void)
{

	//code

	angle_degree = angle_degree - 0.05f;
	if (angle_degree <= -360.0f)
		angle_degree = 0.0f;
}














