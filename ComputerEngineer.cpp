#if 0
#include<iostream>
#include"ComputerEngineer.h"

using namespace std;

ComputerEngineer::ComputerEngineer(int age, char* Name, int nComputer):Human(age,Name)
{
	m_nComputer = nComputer;
	cout << "Call the ComputerEngineer constructor" << endl;
}
ComputerEngineer::~ComputerEngineer()
{
	cout << "Call the ComputerEngineer ~constructor" << endl;
}
void ComputerEngineer::Overtime()
{
	cout << m_strName << "is works overtime" << endl;
}
void ComputerEngineer::Info()
{
	Human::Info();
	cout << m_strName << "����ǻ�͸�" << m_nComputer << "�밡�����ִ�" << endl;
}
//void ComputerEngineer::test(int a)
//{
//	//a = 10;
//	b = 20;
//	m_nAge = 10;
//	seta(20);
//
//	cout << "Human::m_nAge : " << endl;
//}
//void ComputerEngineer::seta(int a)
//{
//	Human::seta(a);
//}
//int ComputerEngineer::gtest()
//{
//	return geta();
//}
#endif

#if 0
#include<iostream>
#include"ComputerEngineer.h"

using namespace std;

ComputerEngineer::ComputerEngineer(int age, char* Name, int nComputer) :Human(age, Name)   //�ٽ� �θ�(������ ȣ��� ����)
{
	m_nComputer = nComputer;
	cout << "ComputerEngineer ������ ȣ��" << endl;
}

ComputerEngineer::~ComputerEngineer()
{
	cout << "ComputerEngineer �Ҹ��� ȣ��" << endl;
}

void ComputerEngineer::Overtime()
{
	cout << m_strName << "�� �߱��� �Ѵ�." << endl;
}

void ComputerEngineer::Info()
{
	Human::Info();
	cout << m_strName << "�� ��ǻ�͸�" << m_nComputer << "�� ������ �ִ�." << endl;
}
void ComputerEngineer::seta(int a)
{
	Human::seta(a);
}
int ComputerEngineer::geta()
{
	return Human::geta();
}
void ComputerEngineer::Play()
{
	cout << "COMEN: Play()" << endl;
}
#endif