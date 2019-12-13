#include<stdio.h>
#include<iostream>
#include<afx.h>

class CAlpha :public CObject {
public:
	/*virtual CRuntimeClass* GetRuntimeClass() const {
		return &classCAlpha;
	}*/
	DECLARE_DYNAMIC(CAlpha)
	DECLARE_DYNCREATE(CAlpha)
protected:
	CAlpha() { printf("CAlpha constructor\n"); }
};

IMPLEMENT_DYNAMIC(CAlpha,CObject)
IMPLEMENT_DYNCREATE(CAlpha,CObject)


class CBeta :public CObject {
public:
	/*virtual CRuntimeClass* GetRuntimeClass() const {
		return &classCBeta;
	}
	DECLARE_DYNAMIC(CBeta)*/
	DECLARE_DYNCREATE(CBeta)
protected:
	CBeta() { printf("CBeta constructor\n"); }
};

IMPLEMENT_DYNAMIC(CBeta,CObject)
IMPLEMENT_DYNCREATE(CBeta,CObject)


int main() {
	CRuntimeClass* pRTCAlpha = RUNTIME_CLASS(CAlpha);
	CObject* pObj1;

	pObj1 = pRTCAlpha->CreateObject();
	printf("CAlpha class=%s\n",
		pObj1 ->GetRuntimeClass()->m_lpszClassName);
	
	CRuntimeClass* pRTCBeta = RUNTIME_CLASS(CBeta);
	CObject* pObj2;

	pObj2 = pRTCBeta->CreateObject();
	printf("CBeta class=%s\n",
		pObj2->GetRuntimeClass()->m_lpszClassName);

	delete pObj1;
	delete pObj2;
}