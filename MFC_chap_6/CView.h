#pragma once
#include<Windows.h>
#include"stdafx.h"
#include"CObject.h"

#ifndef _CView_
#define _CView_

class CView;

typedef LRESULT(CView::* CViewFunPointer)(WPARAM, LPARAM);

typedef struct tagMessageMap {
	UINT iMsg;
	CViewFunPointer fp;
}MessageMap;

static CViewFunPointer fpCViewGlobal;

class CView :public CObject
{
public:
	LRESULT OnCreate(WPARAM,LPARAM);
	LRESULT OnDraw(WPARAM, LPARAM);
	LRESULT OnDestroy(WPARAM, LPARAM);
	LRESULT OnLButtonDown(WPARAM, LPARAM);
	LRESULT OnRButtonDown(WPARAM, LPARAM);

	DECLARE_MESSAGE_MAP()//함수들 선언
};//class CView

#endif