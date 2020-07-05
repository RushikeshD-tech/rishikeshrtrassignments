// Headers
#include<Windows.h>

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// variable declarations
	WNDCLASSEX wndclass_RAD;
	HWND hwnd_RAD;
	MSG msg_RAD;
	TCHAR szAppName_RAD[] = TEXT("MyApp");

	//code
	//initialization of WNDCLASSEX
	wndclass_RAD.cbSize = sizeof(WNDCLASSEX);
	wndclass_RAD.style = CS_HREDRAW | CS_VREDRAW;
	wndclass_RAD.cbClsExtra = 0;
	wndclass_RAD.cbWndExtra = 0;
	wndclass_RAD.lpfnWndProc = WndProc;
	wndclass_RAD.hInstance = hInstance;
	wndclass_RAD.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass_RAD.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass_RAD.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass_RAD.lpszClassName = szAppName_RAD;
	wndclass_RAD.lpszMenuName = NULL;
	wndclass_RAD.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//register above class
	RegisterClassEx(&wndclass_RAD);

	// create window
	hwnd_RAD = CreateWindow(szAppName_RAD,
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

	ShowWindow(hwnd_RAD, iCmdShow);
	UpdateWindow(hwnd_RAD);

	//message loop
	while (GetMessage(&msg_RAD, NULL, 0, 0))
	{
		TranslateMessage(&msg_RAD);
		DispatchMessage(&msg_RAD);
	}
	return((int)msg_RAD.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd_RAD, UINT iMsg_RAD, WPARAM wParam_RAD, LPARAM lParam_RAD)
{
	//code
	switch (iMsg_RAD)
	{
	case WM_CREATE:
			MessageBox(hwnd_RAD, TEXT("WM_CREATE Is Received"), TEXT("My Message"), MB_OK);
			break;
	case WM_LBUTTONDOWN:
			MessageBox(hwnd_RAD, TEXT("WM_LBUTTONDOWN Is Received"), TEXT("My Message"), MB_OK);
			break;
	case WM_RBUTTONDOWN:
			MessageBox(hwnd_RAD, TEXT("WM_RBUTTONBOX Is Received"), TEXT("My Message"), MB_OK);
			break;
	case WM_KEYDOWN:
			MessageBox(hwnd_RAD, TEXT("WM_KEYDOWN Is Received"), TEXT("My Message"), MB_OK);
			break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd_RAD, iMsg_RAD, wParam_RAD, lParam_RAD));
}
