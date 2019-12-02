#if 0 //022 상속.
//구성 human.h, Human.cpp, ComputerEngineer.h, ComputerEngineer.cpp

#include <iostream>
#include"Human.h"
#pragma warning(disable:4996)
using namespace std;

Human::Human(int age, char* Name)
{
	m_nAge = age;
	m_strName = new char[strlen(Name) + 1];
	strcpy(m_strName, Name);
	cout << "Generate Human constructor" << endl;
}
Human::~Human()
{
	delete[] m_strName;
	cout << "call Human ~constructor" << endl;
}
void Human::Eat()
{
	cout << m_strName << "is eating meal" << endl;
}
void Human::Sleep()
{
	cout << m_strName << "is sleeping" << endl;
}
void Human::Work()
{
	cout << m_strName << "is working" << endl;
}
void Human::Info()
{
	cout << "name:" << m_strName << endl;
	cout << "age:" << m_nAge << endl;
}
void Human::seta(int _a)
{
	a = _a;
}
int Human::geta()
{
	return a;
}
void Human::Play()
{
	cout << "Human Play()" << endl;
}
//void Human::seta(int _a)
////값 바뀌게하려고 _ 넣음.
//{
//	a = _a;
//}
//int Human::geta()
//{
//	return a;
//}
#endif