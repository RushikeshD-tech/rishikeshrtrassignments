// Headers
#include<windows.h>

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


// WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");
	int  dx = 800;
	int  dy = 600;
	
	// code
	// intialization of WNDCLASSEX
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

	// register above class
	RegisterClassEx(&wndclass);

	//create window
	hwnd = CreateWindow(szAppName,
		TEXT("My Application"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,//GetSystemMetrics(SM_CXSCREEN),
	    CW_USEDEFAULT,//GetSystemMetrics(SM_CYSCREEN),
		/*CW_USEDEFAULT,*/dx,
		/*CW_USEDEFAULT,*/dy,
		NULL,
		NULL,
		hInstance,
		NULL);


	//ghwnd = hwnd;
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	// message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);

}
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// local function declarations
	void CenterWindow(HWND hwnd);
	
	
	switch (iMsg)
	{
	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
    }
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
void CenterWindow(HWND hwnd)
{
	
	RECT rcWnd;
	
	GetWindowRect(hwnd, &rcWnd);
	
	
	rcWnd.left = ((GetSystemMetrics(SM_CXSCREEN) - (rcWnd.right - rcWnd.left)) / 2);
	rcWnd.right = ((GetSystemMetrics(SM_CYSCREEN) - (rcWnd.bottom - rcWnd.top)) / 2);



	SetWindowPos(hwnd, NULL, rcWnd.left, rcWnd.top, 800, 600, SWP_NOSIZE | SWP_NOZORDER );
}













