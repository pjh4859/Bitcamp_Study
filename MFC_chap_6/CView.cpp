#include<Windows.h>
#include"stdafx.h"
#include"CView.h"

CView app;

BEGIN_MESSAGE_MAP(CView)//�Լ� �ʱ�ȭ���ְ�
	{ WM_CREATE, & CView::OnCreate},
	{ WM_PAINT,&CView::OnDraw },
	{ WM_DESTROY,&CView::OnDestroy },
	{WM_LBUTTONDOWN,&CView::OnLButtonDown},
	{WM_RBUTTONDOWN,&CView::OnRButtonDown},
END_MESSAGE_MAP()

LRESULT CView::OnCreate(WPARAM wParam, LPARAM lParam) {
	return 0L;
}//�Լ��� ���ǵ�
LRESULT CView::OnDraw(WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	hdc = BeginPaint(hwnd, &ps);

	GetClientRect(hwnd, &rect);
	DrawText(hdc, "Hello, Windows!", -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	EndPaint(hwnd, &ps);
	return 0L;
}

LRESULT CView::OnDestroy(WPARAM wParam, LPARAM lParam) {
	PostQuitMessage(0);
	return 0L;
}

LRESULT CView::OnLButtonDown(WPARAM wParam, LPARAM lParam) {
	MessageBox(hwnd, "LButtonDown", "WM_LBUTTONDOWN", MB_OK);
	return 0L;
}

LRESULT CView::OnRButtonDown(WPARAM wParam, LPARAM lParam) {
	MessageBox(hwnd, "RButtonDown", "WM_RBUTTONDOWN", MB_OK);
	return 0L;
}