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
	cout << m_strName << "는컴퓨터를" << m_nComputer << "대가지고있다" << endl;
}
void ComputerEngineer::test(int a)
{
	//a = 10;
	b = 20;
	m_nAge = 10;
	seta(20);

	cout << "Human::m_nAge : " << endl;
}
void ComputerEngineer::seta(int a)
{
	Human::seta(a);
}
int ComputerEngineer::gtest()
{
	return geta();
}
#endif