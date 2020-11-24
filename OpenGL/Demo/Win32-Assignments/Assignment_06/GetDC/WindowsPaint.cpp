//Headers
#include<windows.h>

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd_RAD;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");

	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//register above class
	RegisterClassEx(&wndclass);

	//create window
	hwnd_RAD = CreateWindow(szAppName, TEXT("Rishikesh Dumbre"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd_RAD, iCmdShow);
	UpdateWindow(hwnd_RAD);

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);

}
LRESULT CALLBACK WndProc(HWND hwnd_RAD, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//code
	HDC hdc_RAD;
	//PAINTSTRUCT ps;
	RECT rc;
	TCHAR str[] = TEXT("Hello World!!!");


	switch (iMsg)
	{
	//case WM_PAINT:
	case WM_LBUTTONDOWN:
		GetClientRect(hwnd_RAD, &rc);
		hdc_RAD = GetDC(hwnd_RAD); //BeginPaint(hwnd, &ps);
		SetBkColor(hdc_RAD, RGB(0, 0, 0));
		SetTextColor(hdc_RAD, RGB(0, 255, 0));
		DrawText(hdc_RAD, str, -1, &rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd_RAD, hdc_RAD);  // EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd_RAD, iMsg, wParam, lParam));
}














