// Headers   // NEW CODE 
#include<windows.h>
#include<stdio.h>
#include"SingleBuffer.h"
#include<gl/GL.h>
#pragma comment(lib, "Opengl32.lib") //lib-import library
#define Win_Width 800
#define Win_Height 600

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
FILE* gpFile = NULL;
RECT rcWnd;

// global Variable declarations
DWORD dwStyle_RAD;
WINDOWPLACEMENT wpPrev_RAD = { sizeof(WINDOWPLACEMENT) };
bool gbFullscreen_RAD = false;
bool gbActiveWindow_RAD = false;
bool Bdone_RAD = false;
HWND ghwnd_RAD = NULL;
HDC ghdc_RAD = NULL;
HGLRC ghrc_RAD = NULL;


// WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function declarations 
	void Initialize(void);
	void Display(void);
	

	// variable declarations
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
	// intialization of WNDCLASSEX
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
	

	// register above class
	RegisterClassEx(&wndclass_RAD);

	//create window
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

	GetWindowRect(hwnd_RAD, &rcWnd);

	rcWnd.left = ((GetSystemMetrics(SM_CXSCREEN) - (rcWnd.right - rcWnd.left)) / 2);
	rcWnd.top = ((GetSystemMetrics(SM_CYSCREEN) - (rcWnd.bottom - rcWnd.top)) / 2);

	SetWindowPos(hwnd_RAD, NULL, rcWnd.left, rcWnd.top, 800, 600, SWP_NOSIZE | SWP_NOZORDER);


	ghwnd_RAD = hwnd_RAD;
	Initialize();
	ShowWindow(hwnd_RAD, iCmdShow);
	SetForegroundWindow(hwnd_RAD);
	SetFocus(hwnd_RAD);

	// Message loop // Game loop
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
	//void Display(void);
	// local variable declarations

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
		SetWindowPos(ghwnd_RAD, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

		ShowCursor(TRUE);
		gbFullscreen_RAD = false;
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
	ghdc_RAD = GetDC(ghwnd_RAD);
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;// | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	iPixelFormatIndex = ChoosePixelFormat(ghdc_RAD, &pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixelFormate Function Failed");
		DestroyWindow(ghwnd_RAD);

	}
	if (SetPixelFormat(ghdc_RAD, iPixelFormatIndex, &pfd) == FALSE)
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

}
void Display(void)
{
	//code

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);

	glEnd();
	glFlush();
	//SwapBuffers(ghdc);

}
void unintialize(void)
{
	//code
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
		//return(0);
	}
}

















