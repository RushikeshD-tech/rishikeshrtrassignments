// Headers
#include<windows.h>
#include<stdio.h>
#include"GUIIcon.h"

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
FILE* gpFile = NULL;

// global Variable declarations
DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
bool gbFullscreen = false;
HWND ghwnd = NULL;




// WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");

	if (fopen_s(&gpFile, "RADLog.txt", "w") != 0)
	{
		MessageBox(NULL, TEXT("Can not Open Desired File"), TEXT("Error"), MB_OK);
		exit(0);
	}

	// code
	// intialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	// register above class
	RegisterClassEx(&wndclass);

	//create window
	hwnd = CreateWindow(szAppName,
		TEXT("Rishikesh Dumbre"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ghwnd = hwnd;
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	// message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	fclose(gpFile);
	gpFile = NULL;
	return((int)msg.wParam);

}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	// local function declaration
	void ToggleFullScreen(void);

	// local variable declarations
	HDC hdc, dc;
	PAINTSTRUCT ps;
	RECT rc, rctemp;
	TCHAR str[] = TEXT("Hello World!!!");
	HBITMAP hBitmap;
	BITMAP bmp;
	dc = CreateCompatibleDC(NULL);
	HBRUSH hBrush;
	static LONG lright = 0;
	static int iPaintflag = -1;
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CREATE:

		SetTimer(hwnd, 0, 1000, NULL);
		MessageBox(hwnd, TEXT("Starting to Draw Strips"), TEXT("Message"), MB_OK);
		break;
	case WM_TIMER:
	{
		KillTimer(hwnd, 0);
		iPaintflag = iPaintflag + 1;
		if (iPaintflag < 06)
		{
			InvalidateRect(hwnd, NULL, FALSE);

		}
		SetTimer(hwnd, 0, 1000, NULL);
	}
	break;
	case WM_SIZE:
		iPaintflag = 0;
		lright = 0;
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		SetBkColor(hdc, RGB(0, 0, 0));
		SetTextColor(hdc, RGB(0, 255, 0));
		DrawText(hdc, str, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(MYIMAGE));
		SelectObject(dc, (HGDIOBJ)hBitmap);
		GetObject(hBitmap, sizeof(bmp), &bmp);
		hBrush = CreateSolidBrush(RGB(255, 0, 0));
		SelectObject(hdc, hBrush);
		FillRect(hdc, &rc, hBrush);
		StretchBlt(hdc, 250, 50, 100, 100, dc, 0, 0, bmp.bmWidth / 2, bmp.bmHeight / 2, SRCCOPY);
		if (hBitmap == NULL)
		{
			MessageBox(NULL, TEXT("File Not Available"), TEXT("File Available"), MB_OK);
			exit(0);
		}
		//EndPaint(hwnd, &ps);

		switch (iPaintflag)
		{
		case 0:

			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);

			break;
		case 1:
			hBrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);
			break;
		case 2:
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);
			break;
		case 3:
			hBrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);
			break;
		case 4:
			hBrush = CreateSolidBrush(RGB(255, 0, 255));
			SelectObject(hdc, hBrush);
			FillRect(hdc, &rctemp, hBrush);
			break;

			EndPaint(hwnd, &ps);
			DeleteObject(hBrush);
		}
	}
}

	//DeleteObject(hBrush);




	 /*case WM_KEYDOWN:
		switch (wParam)
		{
		case 0x46:       // Capital 'F' hexadecimal value of 70
		case 0x66:       // Small 'f' hexadecimal value of 102
			ToggleFullScreen();
			break;
		default:
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	 }
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
 */

	void ToggleFullScreen(void)
	{
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
			SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);

			ShowCursor(TRUE);
			gbFullscreen = false;
		}
	}


 