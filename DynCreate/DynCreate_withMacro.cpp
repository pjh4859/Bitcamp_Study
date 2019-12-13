#if 1
//RTTI(runt time type information)
#include<stdio.h>
#include<iostream>

#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)
#define DECLARE_DYNAMIC(class_name) static CRuntimeClass class##class_name;
#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass class_name::class##class_name={(#class_name),sizeof(class_name),class_name::CreateObject};
#define DECLARE_DYNCREATE(class_name) static CObject* CreateObject();
#define IMPLEMENT_DYNCREATE(class_name) CObject* class_name::CreateObject(){return new class_name;}
class CObject;
//{{struct CRuntimeClass---------------------------------------------------
struct CRuntimeClass
{
    char m_lpszClassName[21];
    int m_nObjectSize;
    CObject* (*pfnCreateObject)();

    CObject* CreateObject();
};

CObject* CRuntimeClass::CreateObject() {
    return (*pfnCreateObject)();/*�Լ������͸� �̟G�Ͽ� ���������� �Լ��� ȣ���Ѵ�.*/
}
//}struct CRuntimeClass-------------------------------------------------------

//{{class CObject-------------------------------------------------------------
class CObject {
    /*CObject�� ���� ���� �Լ��� �������� ��������
    �߻�Ŭ������ �ƴϴ� ������ �����ڰ� protected�� �����Ǿ����Ƿ�,
    CObject��ü�� ������ �� ����.
    */
public:
    virtual CRuntimeClass* GetRuntimeClass() const { return NULL; }
    /*�Ļ� Ŭ�������� �ݵ�� ������ �ʿ䰡 �����Ƿ�
    �������� �Լ��� �ƴϴ�*/
    //   static CRuntimeClass classCObject;
    DECLARE_DYNAMIC(CObject)
    //DECLARE_DYNAMIC(CObject)
    virtual ~CObject() {}
protected:
    CObject() { printf("CObject constructor\n"); }
};

CRuntimeClass CObject::classCObject = {//IMPLEMENT_DYNAMIC(CObject)
   "CObject",sizeof(CObject),NULL
};

//}}class CObject------------------------------------------------------

//{class CAlpha---------------------------------------------------------
class CAlpha : public CObject {
public:
    virtual CRuntimeClass* GetRuntimeClass() const {
        return &classCAlpha;
    }
    //static CRuntimeClass classCAlpha;
    DECLARE_DYNAMIC(CAlpha)
    //static CObject* CreateObject();
    DECLARE_DYNCREATE(CAlpha)
protected:
    CAlpha() {
        printf("CAlpha constructor\n");
    }
};

IMPLEMENT_DYNAMIC(CAlpha)
IMPLEMENT_DYNCREATE(CAlpha)
//}}classCAlpha-----------------------------------------------------------

//{{classCBeta-----------------------------------------------------------
class CBeta :public CObject {
public:
    virtual CRuntimeClass* GetRuntimeClass() const {
        return &classCBeta;
    }
    //static CRuntimeClass classCBeta;
    DECLARE_DYNAMIC(CBeta)
    //static CObject* CreateObject();
    DECLARE_DYNCREATE(CBeta)
protected:
    CBeta() { printf("CBeta consturctor\n"); }
};

IMPLEMENT_DYNAMIC(CBeta)
IMPLEMENT_DYNCREATE(CBeta)
//}}class CBeta-------------------------------------------------------------

void main() {
    //Create CAlpha
    CRuntimeClass* pRTCAlpha = RUNTIME_CLASS(CAlpha);
    CObject* pObj1;

    pObj1 = pRTCAlpha->CreateObject();
    /*struct RuntimeClass�� createObject()�� ȣ�������
    IMPLEMENT_DYNCREATE��ũ�ο� ���� CAlpha�� &OnCreate()��
    ���ԵǾ� �����Ƿ�, �ᱹ�� CAlpha�� OnCreate()�� ȣ��Ǿ�
    �������� ��ü�� �����ϰ� �ȴ�
    ������ Ǫ�� ����� �ٷ� '�Լ� ������'��.
    */
    printf("CAlpha class=%s\n",
        pObj1->GetRuntimeClass()->m_lpszClassName);

    //Create CBeta
    CRuntimeClass* pRTCBeta = RUNTIME_CLASS(CBeta);
    CObject* pObj2;

    pObj2 = pRTCBeta->CreateObject();
    printf("CBeta class=%s\n",
        pObj2->GetRuntimeClass()->m_lpszClassName);
    //�ϰ��� ������� Ŭ������ ����� �����ϴ� �Ϳ� �ָ��϶�
    delete pObj1;
    delete pObj2;

}
#endif