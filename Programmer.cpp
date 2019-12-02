#if 0
#include<iostream>
#include"Programmer.h"

using namespace std;

Programmer::Programmer(int age, char* Name, int nComputer, int nLanguage) :ComputerEngineer(age, Name, nComputer)
{
	m_nLanguage = nLanguage;
	cout << "Programmer 생성자 호출" << endl;
}
Programmer::~Programmer()
{
	cout << "Programmer 소멸자호출" << endl;
}
void Programmer::NeverEndingStudy()
{
	cout << m_strName << "는 계속공부하기" << endl;
}
void Programmer::Sleep()
{
	cout << m_strName << "는 늦게잘때가 종종있음" << endl;
}
void Programmer::Overtime()
{
	ComputerEngineer::Overtime();
	cout << "에휴~" << endl;
}
void Programmer::Info()
{
	ComputerEngineer::Info();
	cout << m_strName << "는 알고있는 프로그래밍 언어가" << m_nLanguage << "개이다" << endl;
}
void Programmer::Play()
{
	cout << "Programmer Play()" << endl;
}

#endif