#pragma once
#include<Windows.h>
#ifndef _CObject_
#define _CObject_

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
};

#endif