// Headers
#include<Windows.h>
#include<stdio.h>
#include "DibFile.h"




// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);



// global Variable declarations
HBITMAP imageBmp;
HBITMAP imageBmp1;
//HBITMAP imageBmp2;
HDC imageDC; 
HDC hdc;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
//bool DrawBitmap;


// WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");
	
//loadImage("windowxp.bmp");
	
	
	//MYTIMER;
	//int dx_width;
	//int dy_height;

	// code
	// initialization of WNDCLASSEX
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
	//wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	// register above class
	RegisterClassEx(&wndclass);

	
	// create window
	hwnd = CreateWindow (szAppName,
		TEXT("MyBitmap"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
	UpdateWindow(hwnd);

	// message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}
   /*void loadImage(const char* pathname)
   {
	imageDC = CreateCompatibleDC(NULL);

	imageBmp = (HBITMAP)LoadBitmap(GetModuleHandle(NULL), TEXT("E:/RTR/WindowsColorAnimation/windowxp.bmp"));
	  if (imageBmp == NULL)
	  {
		MessageBox(NULL, TEXT("File Not Available"), TEXT("File Available"), MB_OK);
		exit(0);
      }
   }*/


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//code
	static int iPaintflag = -1;
	//static int cxClientMax, cyClientMax, cxClient, cyClient, cxChar, cyChar;
	HDC hdc,dc;
	HDC imageDC, imageDC1;
	RECT rc, rctemp;
    HBRUSH hBrush;
	PAINTSTRUCT ps;
	static LONG lright = 0;
	HBITMAP hBitmap;
	HBITMAP hBitmap1;
	//HBITMAP hBitmap2;
	BITMAP imageBmp;
	BITMAP imageBmp1;
	//BITMAP imageBmp2;
	//BITMAP imageBmp3;
	//HBRUSH hBrush;
	
	HINSTANCE hInstance = NULL;
	dc = CreateCompatibleDC(NULL);
	imageDC = CreateCompatibleDC(NULL);
	imageDC1 = CreateCompatibleDC(NULL);
	//const int   screenSize_X = 640;
	//const int   screenSize_Y = 480;

	
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CREATE:
		//cxClientMax = GetSystemMetrics(SM_CXMAXIMIZED);
		//cyClientMax = GetSystemMetrics(SM_CYMAXIMIZED);

		SetTimer(hwnd, 0, 1000, NULL);
		MessageBox(hwnd, TEXT("Starting to Draw Strips"), TEXT("Message"), MB_OK);
			break;
	case WM_TIMER:
	{
		KillTimer(hwnd, 0);
		iPaintflag = iPaintflag ;
		if (iPaintflag < 7)
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
	{
		GetClientRect(hwnd, &rc);
		/*if (iPaintflag < 7)
		{
			rctemp.left = lright;
			lright = (rc.right / 7) + lright;
			rctemp.right = lright;
			rctemp.top = rc.bottom / 4 ;
			rctemp.bottom = rc.top ;
		}
		/*else if(iPaintflag < 10)
		{
			rctemp.left = lright;
			lright = (rc.right / 5) + lright;
			rctemp.right = lright;
			rctemp.top = rc.bottom ;
			rctemp.bottom = rc.bottom;

		}*/
	    
		hdc = BeginPaint(hwnd, &ps);
		
		// Windows 10 Image 
		hBitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(MYIMAGE));
        SelectObject(dc, (HGDIOBJ)hBitmap);
		GetObject(hBitmap, sizeof(imageBmp), &imageBmp);
		hBrush = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hdc, hBrush);
		FillRect(hdc, &rc, hBrush);
		

		
		// System Requirement Image 
		hBitmap1 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(MYIMAGE1));
		SelectObject(imageDC, (HGDIOBJ)hBitmap1);
		GetObject(hBitmap1, sizeof(imageBmp1), &imageBmp1);
		//hBrush = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hdc, hBrush);
		FillRect(hdc, &rc, hBrush);
		
		//hBrush = CreateSolidBrush(RGB(0, 0, 0));
		//hBrush = CreateSolidBrush(RGB(0, 0, 0));
		//hBitmap2 = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(MYIMAGE));
		
		
		
		//SelectObject(hdc, hBrush);
		//FillRect(hdc, &rc, hBrush);

		if (hBitmap == NULL)
		{
			MessageBox(NULL, TEXT("File Not Found"), TEXT("Message"), MB_OK);
			exit(0);

		}
		else if (hBitmap1 == NULL)
		{
			MessageBox(NULL, TEXT("File Not Found"), TEXT("Message"), MB_OK);
			exit(0);
		}
		
		
		switch (iPaintflag)
		{
		case 0:
			
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			FillRect(hdc, &rctemp, hBrush);
			//StretchBlt(hdc, 0, 205, 800, 600, dc, 0, 0, imageBmp.bmWidth, imageBmp.bmHeight, SRCCOPY);
			StretchBlt(hdc, 0, 205, 1540, 600, dc, 0, 0, imageBmp.bmWidth, imageBmp.bmHeight, SRCCOPY);  // Full Screen Windows 10
			SelectObject(hdc, hBrush);
			DeleteDC(dc);
			break;

			
			
		case 1:
			hBrush = CreateSolidBrush(RGB(0, 255, 0));
			FillRect(hdc, &rctemp, hBrush);
			StretchBlt(hdc, 100, 205, 800, 600, imageDC, 0, 0, imageBmp1.bmWidth, imageBmp1.bmHeight, SRCCOPY);
			SelectObject(imageDC, (HGDIOBJ)hBitmap1);
			GetObject(hBitmap1, sizeof(imageBmp1), &imageBmp1);
			SelectObject(hdc, hBrush);
			DeleteDC(imageDC);
			break;
			
			
	/*	case 2:
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			FillRect(hdc, &rctemp, hBrush);
			SelectObject(imageDC1, (HGDIOBJ)hBitmap2);
			GetObject(hBitmap1, sizeof(imageBmp2), &imageBmp2);
			StretchBlt(hdc, 470, 50, 100 * 2, 100 * 2, dc, 0, 0, imageBmp2.bmWidth, imageBmp2.bmHeight, SRCCOPY);
			SelectObject(hdc, hBrush);
			DeleteDC(dc);
			break;
			
		case 3:
			hBrush = CreateSolidBrush(RGB(255, 255, 0));
			FillRect(hdc, &rctemp, hBrush);
			StretchBlt(hdc, 695, 50, 100 * 2, 100 * 2, dc, 0, 0, imageBmp.bmWidth, imageBmp.bmHeight, SRCCOPY);
			SelectObject(hdc, hBrush);
			DeleteDC(dc);
			break;
			
		case 4:
			hBrush = CreateSolidBrush(RGB(255, 0, 255));
			FillRect(hdc, &rctemp, hBrush);
			StretchBlt(hdc, 925, 50, 100 * 2, 100 * 2, dc, 0, 0, imageBmp.bmWidth, imageBmp.bmHeight, SRCCOPY);
			SelectObject(hdc, hBrush);
			DeleteDC(dc);
			break;
			

		case 5:
			hBrush = CreateSolidBrush(RGB(0, 255, 255));
			FillRect(hdc, &rctemp, hBrush);
			StretchBlt(hdc, 925, 50, 100 * 2, 100 * 2, dc, 0, 0, imageBmp.bmWidth, imageBmp.bmHeight, SRCCOPY);
			SelectObject(hdc, hBrush);
			DeleteDC(dc);
			break;
			

		case 6:
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
			FillRect(hdc, &rctemp, hBrush);
			StretchBlt(hdc, 925, 50, 100 * 2, 100 * 2, dc, 0, 0, imageBmp.bmWidth, imageBmp.bmHeight, SRCCOPY);
			SelectObject(hdc, hBrush);
			DeleteDC(dc);
			break;
			

        case 7:
			hBrush = CreateSolidBrush(RGB(0, 0, 0));
			FillRect(hdc, &rctemp, hBrush);
			StretchBlt(hdc, 925, 50, 100 * 2, 100 * 2, dc, 0, 0, imageBmp.bmWidth, imageBmp.bmHeight, SRCCOPY);
			SelectObject(hdc, hBrush);
			DeleteDC(dc);
			break; */

			
		}
	}
	EndPaint(hwnd, &ps);
	DeleteObject(hBrush);
	break;

	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
