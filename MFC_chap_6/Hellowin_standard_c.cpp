#if 0 //6-1�ܰ� 0: ������ C
#include<windows.h>
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
		DrawText(hdc, "Hello, Windows!", -1, & rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);

		return 0;

	case WM_LBUTTONDOWN:
		hdc = GetDC(hwnd);
		MoveToEx(hdc, 50, 50, NULL);
		LineTo(hdc, 100, 100);
		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_CLOSE:
		hdc = GetDC(hwnd);
		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, 100, 100);
		ReleaseDC(hwnd, hdc);
		Sleep(2000);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}//switch
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	static char szAppName[] = "hellowin";
	HWND		hwnd;
	MSG			msg;
	WNDCLASSEX	wndclass;

	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);//����ϸ� ������ ��.

	hwnd = CreateWindow(szAppName,
		"The Hello Program",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);


	while (GetMessage(&msg, NULL, 0, 0))
	{
		static int i = 0;
		char buffer[80];
		wsprintf(buffer, "i\n", ++i);
		OutputDebugString(buffer);
		DispatchMessage(&msg);
	}//while

	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)break;
			DispatchMessage(&msg);
		}
		static int i = 0;
		char buffer[8];
		wsprintf(buffer, "i\n", ++i);
		OutputDebugString(buffer);
	}
	return msg.wParam;
}
#endif

#if 0 //6-2 �ܰ� 1: Ŭ������ ���
//#define _CRT_OBSOLETE_NO_WARNINGS
#include<Windows.h>
//#include<stdlib.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam,
	LPARAM lParam);

class CApp {
	static char szAppName[];//static ������ �ܺο� ����
	HWND		hwnd;
	MSG			msg;
	WNDCLASSEX	wndclass;

public:
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine,
		int iCmdShow);
	void Run();
	WPARAM ExitInstance();

	void OnCreate();
	void OnDraw();
	void OnDestroy();
};

void CApp::InitInstance(HINSTANCE hInstance, PSTR szCmdLine,
	int iCmdShow) {
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);//����ϸ� ������ ��.

	hwnd = CreateWindow(szAppName,
		"The Hellow Program",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
}//CApp::InitInstance

void CApp::Run() {
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

WPARAM CApp::ExitInstance() {
	return msg.wParam;
}

char CApp::szAppName[] = "helwin";


void CApp::OnCreate() {
}

void CApp::OnDraw() {
	HDC			hdc;
	PAINTSTRUCT	ps;
	RECT		rect;

	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	DrawText(hdc, "Hello,Windows!", -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);
}

void CApp::OnDestroy() {
	PostQuitMessage(0);
}

CApp app;

LRESULT CALLBACK WndProc( HWND hwnd, UINT iMsg, WPARAM wParam,
	LPARAM lPram) {
	switch (iMsg) {
	case WM_CREATE:
		app.OnCreate();
		return 0;
	case WM_PAINT:
		app.OnDraw();
		return 0;
	case WM_DESTROY:
		app.OnDestroy();
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lPram);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow) {
	app.InitInstance(hInstance, szCmdLine, iCmdShow);
	app.Run();
	return app.ExitInstance();
}
#endif

#if 0 //6-3 �ܰ� 2: ���� �Լ��� �̿�
#include<Windows.h>
#include<iostream>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam,
	LPARAM lParam);

class CObject {
protected:
	static char szAppName[];//static ������ �ܺο� ����
	HWND		hwnd;
	MSG			msg;
	WNDCLASSEX	wndclass;

public:
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine,
		int iCmdShow);
	void Run();
	WPARAM ExitInstance();

	virtual void OnCreate() = 0;
	virtual void OnDraw() = 0;
	virtual void OnDestroy() = 0;
};

void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine,
	int iCmdShow) {
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);//����ϸ� ������ ��.

	hwnd = CreateWindow(szAppName,
		"The Hellow Program",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
}

void CObject::Run() {
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

WPARAM CObject::ExitInstance() {
	return msg.wParam;
}

char CObject::szAppName[] = "helwin";

/**************************************************/

/**************************************************/

/**************************************************/

class CView :public CObject
{
	virtual void OnCreate();
	virtual void OnDraw();
	virtual void OnDestroy();
};

void CView::OnCreate() {}
void CView::OnDraw()
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	DrawText(hdc, "Hello, Windows!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);
}

void CView::OnDestroy()
{
	PostQuitMessage(0);
}
CObject* pCObject; //� ��ü�� ���� �ϰ� �; �̷��� ������
CView app;
/**************************************************/

/**************************************************/

/**************************************************/


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_CREATE:
		pCObject->OnCreate();
		return 0;
	case WM_PAINT:
		pCObject->OnDraw();
		return 0;
	case WM_DESTROY:
		pCObject->OnDestroy();
		return 0;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{	
	pCObject = &app;
	pCObject->InitInstance(hInstance, szCmdLine, iCmdShow);
	pCObject->Run();
	pCObject->ExitInstance();
}
#endif

#if 0 //6-4 �ܰ� 3: ��� �Լ� ������ ���̺��� �̿�
#include<Windows.h>
#include<iostream>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam,
	LPARAM lParam);

class CObject {
protected:
	static char szAppName[];//static ������ �ܺο� ����
	HWND		hwnd;
	MSG			msg;
	WNDCLASSEX	wndclass;

public:
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine,
		int iCmdShow);
	void Run();
	WPARAM ExitInstance();

	virtual void OnCreate() = 0;
	virtual void OnDraw() = 0;
virtual void OnDestroy() = 0;
};

void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine,
	int iCmdShow) {
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);//����ϸ� ������ ��.

	hwnd = CreateWindow(szAppName,
		"The Hellow Program",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
}

void CObject::Run() {
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

WPARAM CObject::ExitInstance() {
	return msg.wParam;
}

char CObject::szAppName[] = "helwin";

/**************************************************/
class CView;

typedef void(CView::* CViewFunPointer)();
typedef struct tagMessageMap {
	UINT iMsg;
	CViewFunPointer fp;
}MessageMap;

static CViewFunPointer fpCViewGlobal;

class CView :public CObject
{
public:
	static MessageMap messageMap[];
public:
	virtual void OnCreate();
	virtual void OnDraw();
	virtual void OnDestroy();

};//class CView

MessageMap CView::messageMap[] = {
	{WM_CREATE,&CView::OnCreate},
	{WM_PAINT,&CView::OnDraw},
	{WM_DESTROY,&CView::OnDestroy},
	{0,NULL}
};

void CView::OnCreate() {}
void CView::OnDraw()
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	DrawText(hdc, "Hello, Windows!", -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);
}

void CView::OnDestroy(){
	PostQuitMessage(0);
}
//CObject* pCObject; //� ��ü�� ���� �ϰ� �; �̷��� ������
CView app;
/**************************************************/
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	int i = 0;

	while (CView::messageMap[i].iMsg != 0) {
		if (iMsg == CView::messageMap[i].iMsg) {
			fpCViewGlobal = CView::messageMap[i].fp;
			(app.*fpCViewGlobal)();
			return 0;
		}
		++i;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	app.InitInstance(hInstance, szCmdLine, iCmdShow);
	app.Run();
	return app.ExitInstance();
}

#endif

#if 0 //6-5 �ܰ� 4: ��ũ���� ���
#include<Windows.h>
#include<iostream>

#define DECLARE_MESSAGE_MAP()			static MessageMap messageMap[];
#define BEGIN_MESSAGE_MAP(class_name)	MessageMap class_name::messageMap[]={
#define END_MESSAGE_MAP()				{0,NULL}};


LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam,
	LPARAM lParam);

class CObject {
protected:
	static char szAppName[];//static ������ �ܺο� ����
	HWND		hwnd;
	MSG			msg;
	WNDCLASSEX	wndclass;

public:
	void InitInstance(HINSTANCE hInstance, PSTR szCmdLine,
		int iCmdShow);
	void Run();
	WPARAM ExitInstance();

	virtual void OnCreate() = 0;
	virtual void OnDraw() = 0;
	virtual void OnDestroy() = 0;
};

void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine,
	int iCmdShow) {
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&wndclass);//����ϸ� ������ ��.

	hwnd = CreateWindow(szAppName,
		"The Hellow Program",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
}

void CObject::Run() {
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

WPARAM CObject::ExitInstance() {
	return msg.wParam;
}

char CObject::szAppName[] = "helwin";

/**************************************************/
class CView;

typedef void(CView::* CViewFunPointer)();
typedef struct tagMessageMap {
	UINT iMsg;
	CViewFunPointer fp;
}MessageMap;

static CViewFunPointer fpCViewGlobal;

class CView :public CObject
{
public:
	//static MessageMap messageMap[];
	DECLARE_MESSAGE_MAP()//�Լ��� ����
public:
	virtual void OnCreate();
	virtual void OnDraw();
	virtual void OnDestroy();

};//class CView

//MessageMap CView::messageMap[] = {

BEGIN_MESSAGE_MAP(CView)//�Լ� �ʱ�ȭ���ְ�
	{WM_CREATE,&CView::OnCreate},
	{WM_PAINT,&CView::OnDraw},
	{WM_DESTROY,&CView::OnDestroy},
	//{0,NULL}//���� �ǹ�
END_MESSAGE_MAP()
//};

void CView::OnCreate() {}//�Լ��� ���ǵ�
void CView::OnDraw()
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	hdc = BeginPaint(hwnd, &ps);
	GetClientRect(hwnd, &rect);
	DrawText(hdc, "Hello, Windows!", -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	EndPaint(hwnd, &ps);
}

void CView::OnDestroy() {
	PostQuitMessage(0);
}
//CObject* pCObject; //� ��ü�� ���� �ϰ� �; �̷��� ������
CView app;
/**************************************************/
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	int i = 0;

	while (CView::messageMap[i].iMsg != 0) {
		if (iMsg == CView::messageMap[i].iMsg) {
			fpCViewGlobal = CView::messageMap[i].fp;
			(app.*fpCViewGlobal)();
			return 0;
		}
		++i;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	app.InitInstance(hInstance, szCmdLine, iCmdShow);
	app.Run();
	return app.ExitInstance();
}

#endif