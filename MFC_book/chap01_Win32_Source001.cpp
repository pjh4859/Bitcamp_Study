#if 0
#include<stdio.h>
int main()
{
	printf("Hello World\n");
	return 0;
}
#endif

#if 0
#include<Windows.h>
int main()
{
	MessageBox(NULL,"Hello World","Hello",MB_OK);
	return 0;
}
#endif

#if 0
#include<Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine,int iCmdShow)
{
	MessageBox(NULL, "Hello World", "Hello", MB_OK);
	return 0;
}
#endif

#if 0
//step 2
#include<Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	static char szAppName[] = "Hellowin";
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW;
	wndclass.lpfnWndProc = DefWindowProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//ū ������
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//Ŀ��
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//��׶��� ��
	wndclass.lpszMenuName = NULL;//�޴����� 
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);//���� ������

	RegisterClassEx(&wndclass);

	return 0;
}
#endif
#if 0
//step 3
#include<Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	static char szAppName[] = "Hellowin";
	HWND	hwnd;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW;
	wndclass.lpfnWndProc = DefWindowProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//ū ������
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//Ŀ��
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//��׶��� ��
	wndclass.lpszMenuName = NULL;//�޴����� 
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);//���� ������

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,"Hi Program",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	return 0;
}
#endif
#if 0
//step 4 �����츦 ȭ�鿡 ��Ÿ����
#include<Windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam,
	LPARAM lParam)
{
	HDC			hdc;
	PAINTSTRUCT	ps;
	RECT		rect;

	switch (iMsg)
	{
	case WM_CREATE:
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, "Hello, Windows", -1, &rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		MoveToEx(hdc, 50, 50, NULL);
		LineTo(hdc, 300, 200);
		ReleaseDC(hwnd, hdc);
		return 0;
	
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	static char szAppName[] = "Hellowin";
	HWND	hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//ū ������
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//Ŀ��
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//��׶��� ��
	wndclass.lpszMenuName = NULL;//�޴����� 
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);//���� ������

	RegisterClassEx(&wndclass);//Ŀ�ο� �˷��ַ��� ���

	hwnd = CreateWindow(szAppName, "Hi Program",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);//������ ���
	
	ShowWindow(hwnd, iCmdShow);//������(�ڵ�)

	while (GetMessage(&msg,NULL,0,0))
	{
		DispatchMessage(&msg);
	}
	return 0;
}
#endif
#if 0
//Win32
//step 4 �����츦 ȭ�鿡 ��Ÿ����(2)
#include<Windows.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam,
	LPARAM lParam)
{
	HDC			hdc;
	PAINTSTRUCT	ps;
	RECT		rect;

	switch (iMsg)
	{
	case WM_CREATE:
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, "Hello, Windows", -1, &rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		MoveToEx(hdc, 50, 50, NULL);
		LineTo(hdc, 300, 200);
		ReleaseDC(hwnd, hdc);
		return 0;

	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	static char szAppName[] = "Hellowin";
	HWND	hwnd;
	MSG msg;
	WNDCLASSEX wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//ū ������
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//Ŀ��
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//��׶��� ��
	wndclass.lpszMenuName = NULL;//�޴����� 
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);//���� ������

	RegisterClassEx(&wndclass);//Ŀ�ο� �˷��ַ��� ���

	hwnd = CreateWindow(szAppName, "Hi Program",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);//������ ���

	ShowWindow(hwnd, iCmdShow);//������(�ڵ�)

	/*while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}*/
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)break;
			DispatchMessage(&msg);
		}
		static int i = 0;
		char buff[8];
		wsprintf(buff, "%d\n", ++i);
		OutputDebugString(buff);
	}
	return 0;
}
#endif