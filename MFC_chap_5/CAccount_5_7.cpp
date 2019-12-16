#if 0
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
#pragma warning(disable:4996)
#define KEY_ESC    27
class CAccount
{
public:
    enum
    {
        STATE_IDLE,
        STATE_INPUT,
        STATE_WAIT_ACK,

        STATE_MAX
    };
public:
    int m_iState;

    CAccount();
    void OnIdle();
    void OnInput();
    void OnWaitAck();

    void SetState(int iState);
    void Render();
};

CAccount::CAccount()
{
    m_iState = STATE_IDLE;
}
void CAccount::OnIdle()
{
    cout << "Onidle()" << endl;
}

void CAccount::OnInput()
{
    cout << "OnInput()" << endl;
}
void CAccount::OnWaitAck()
{
    cout << "OnWaitAck()" << endl;
}
void CAccount::SetState(int iState)
{
    m_iState = iState;
}

void CAccount::Render()
{
    static void(CAccount:: * mfp[])() =
    {
       &CAccount::OnIdle,
       &CAccount::OnInput,
       &CAccount::OnWaitAck
    };

    if (m_iState >= 0 && m_iState < STATE_MAX)
        (this->*mfp[m_iState])();
    //this-> 를 안해주면 실행시켜주는 객체가 없는 꼴이 된다.
}

int main(void)
{
    CAccount account;
    int ch = 0;

    while (ch != KEY_ESC)
    {
        if (_kbhit())
        {
            ch = getch();
            if (ch == '1')
                account.SetState(CAccount::STATE_IDLE);
            else if (ch == '2')
                account.SetState(CAccount::STATE_INPUT);
            else if (ch == '3')
                account.SetState(CAccount::STATE_WAIT_ACK);

        }
        Sleep(500);
        account.Render();
    }
}
#endif

#if 0 //5-8 이벤트 패턴의 구현 
#include<iostream>
#include<conio.h>
#define KEY_ESC     27
#pragma warning(disable:4996)

using std::cout;
using std::endl;

class CAccount
{
public:
    struct StartMap
    {
        int input;
        void(CAccount::* mfp)();
    };
    static StartMap map[];

    enum {
        STATE_IDLE,
        STATE_INPUT,
        STATE_WAIT_ACK
    };

public:
    int m_iState;
    CAccount();
    void Ondle();
    void OnInput();
    void OnWaitAck();
};
CAccount::CAccount()
{
    m_iState = STATE_IDLE;
}

void CAccount::Ondle() { cout << "OnIdle()" << endl; }
void CAccount::OnInput() { cout << "OnInput()" << endl; }
void CAccount::OnWaitAck() { cout << "OnWaitAck()" << endl; }

CAccount::StartMap CAccount::map[] =
{
    '1',&CAccount::Ondle,
    '2',&CAccount::OnInput,
    '3',&CAccount::OnWaitAck,
    '0',NULL
};

int main()
{
    int ch = 0;
    int i;
    CAccount account;
    while ((ch != KEY_ESC))
    {
        ch = getch();
        i = 0;
        while (CAccount::map[i].input != 0)
        {
            if (ch == CAccount::map[i].input)
            {
                (account.*(CAccount::map[i].mfp))();
            }
            i++;
        }
    }
}
#endif

#if 1 //5-11 AfxGetApp()의 원리
#include<stdio.h>
#include<assert.h>
#include<vector>

#define AfxGetApp()     KSingleton<CWinApp>::GetSingleton()

template<typename T>
class KSingleton
{
private:
    static T* ms_pSingleton;

public:
    KSingleton()
    {
        assert(NULL == KSingleton<T>::ms_pSingleton);
        KSingleton<T>::ms_pSingleton = (T*)this;
    }

    ~KSingleton()
    {
        KSingleton<T>::ms_pSingleton = NULL;
    }

    static T* GetSingleton()
    {
        return ms_pSingleton;
    }
};

/*static*/template<typename T>T* KSingleton<T>::ms_pSingleton = NULL;
class CWinApp :public KSingleton<CWinApp>//<> 안은 뭐?
{
public:
    void Print()
    {
        printf("hi\n");
    }
};

CWinApp theApp;
int main()
{
    //KSingleton<CWinApp>::GetSingleton()->Print();
    AfxGetApp()->Print();
    //CWinApp aaa;
}
#endif