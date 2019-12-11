#if 0
//
//#include<stdio.h>
#include<Windows.h>

#define MB_OK				0x00000000L
#define MB_OKCANCEL			0x00000001L
#define MB_ABORTRETRYIGNOR	0x00000002L
#define MB_YESNOCANCLE		0x00000003L
#define MB_YESNO			0x00000004L
#define MB_RETRYCANCEL		0x00000005L

#define MB_ICONHAND			0x00000010L
#define MB_ICONQUESTION		0x00000020L
#define MB_ICONEXCLAMATION	0x00000030L
#define MB_ICONASTERISK		0x00000040L

//void MessageBox(const char* pszsMessage, unsigned int flag)
//{
//	int iButton = flag & 0x000f;
//	int iIcon = (flag & 0x00f0) >> 4;
//
//	const char* pszButtons[] = { "OK","OKCANCEL",
//	"ABORTRETRYIGNORE","YESNOCANCEL","YESNO","RETRYCANCEL" };
//
//	const char* pszIcons[] = { "","HAND","QUESTION","EXCLAMATION",
//	"ASTERISK" };
//
//	printf("msg = %s\n"
//		"button=%s\n"
//		"icon=%s\n", pszsMessage, pszButtons[iButton], pszIcons[iIcon]);
//}

void main()//링커 시스템을 콘솔로 해야함 winMain 은 창 으로 설정.
{
	MessageBox(NULL, "hello world","hello", MB_OK | MB_ICONQUESTION);
}
#endif

#if 0
//연산자 .*  
#include<stdio.h>

class CStateManager
{
private:
	int m_iState;

	void State_Idle();
	void State_Attack();
	void State_GameOver();
public:
	CStateManager();
	void SetState(int state);
	void DoIt();
};

void CStateManager::State_Idle()
{
	printf("idle\n");
}
void CStateManager::State_Attack()
{
	printf("attack\n");
}
void CStateManager::State_GameOver()
{
	printf("game over\n");
}
CStateManager::CStateManager()
{
	m_iState = 0;
}
void CStateManager::SetState(int state)
{
	m_iState = state;
}
void CStateManager::DoIt()
{
	switch (m_iState)
	{
	case 0:
		State_Idle();
		break;
	case 1:
		State_Attack();
		break;
	case 2:
		State_GameOver();
		break;
	}
}

int main()
{
	void(CStateManager:: * fp)(int);

	fp = &CStateManager::SetState;
	
	CStateManager sman;//일반 멤버함수이기때문에 객체를 생성해야함.
	(sman.*fp)(1);
	sman.DoIt();
	sman.SetState(2);
	sman.DoIt();




	return 0;
}
#endif
#if 0
//연산자 ->*  
#include<stdio.h>

class CStateManager
{
private:
	int m_iState;

	void State_Idle();
	void State_Attack();
	void State_GameOver();
public:
	CStateManager();
	void SetState(int state);
	void DoIt();
};

void CStateManager::State_Idle()
{
	printf("idle\n");
}
void CStateManager::State_Attack()
{
	printf("attack\n");
}
void CStateManager::State_GameOver()
{
	printf("game over\n");
}
CStateManager::CStateManager()
{
	m_iState = 0;
}
void CStateManager::SetState(int state)
{
	m_iState = state;
}
void CStateManager::DoIt()
{
	static void (CStateManager:: * fp[3])() =
	{
		CStateManager::State_Idle,
		CStateManager::State_Attack,
		CStateManager::State_GameOver
	};
	(this->*fp[m_iState])();
}

int main()
{
	void(CStateManager:: * fp)(int);

	fp = &CStateManager::SetState;

	CStateManager sman;//일반 멤버함수이기때문에 객체를 생성해야함.
	CStateManager* cp;
	cp = &sman;
	cp->SetState(2);
	(cp->*fp)(0);
	sman.DoIt();
	cp->DoIt();
	(sman.*fp)(1);
	sman.DoIt();
	sman.SetState(2);
	sman.DoIt();




	return 0;
}
#endif
#if 0
#include<iostream>

#define stringit(x)		 #x
#define tokencat(x,y)	 x##y

void main()
{
	int i = 1,j = 2,ij = 3;

	std::cout << stringit(hello) << '\n';
	std::cout << tokencat(i, j) << '\n';
}
#endif
#if 0 //변환 연산자 오버로딩
#include<stdio.h>

typedef unsigned int HANDLE;

class CHandle
{
private:
	HANDLE	m_handle;
	int		m_data;

public:
	CHandle()
	{
		m_handle = 0;
		m_data = 1;
	}
	HANDLE GetHandle() const
	{
		printf("GetHandle()\n");
		return m_handle;
	}

	operator HANDLE() const
	{
		printf("GetHandle()\n");
		return m_handle;
	}
	operator int()const
	{
		printf("operator int\n");
		return m_data;
	}
	void FromHandle(HANDLE handle)
	{
		m_handle = handle;
	}
};

void Test(HANDLE handle)
{
	printf("handle=%i\n", handle);
}
void AAA(int i){
	printf("i=%d\n", i);
}
void main()
{
	CHandle handleObject;
	HANDLE handle;

	handle = 2;
	handleObject.FromHandle(handle);
	Test(handleObject.GetHandle());
	Test(handleObject);
	AAA(handleObject);
}
#endif
#if 0 //#define
#include<stdio.h>

#define PI 3.141592
#define A B,C
#define begin {
#define end }
#define procedure void

int B = 1, C = 2;

procedure PrintPI()
begin
	printf("%f\n", PI);
end

void main()
begin
	PrintPI();
	printf("%d,%d\n", A);
end
#endif

#if 0
#include<stdio.h>

#define MUL(a,b) ((a)*(b))

int main() {
	printf("%d\n", MUL(2 + 3, 4));
}
#endif

#if 0
#include<stdio.h>
#define pri() printf("propro");
#define FF 1
#if!defined FF 2
#ifdef DEBUG
void f(int i) {
	printf("%d\n", i);
}
#endif // DEBUG
void main()	{
	printf("%d",FF);
	pri();
	int i = 2, j = 3, k = 4;
	k = i * j * k;
#define pri() printf("oioi");
	pri();
#ifdef DEBUG
	f(k);
#endif
	printf("%d,%d,%d\n", i, j, k);
}
#endif
#endif