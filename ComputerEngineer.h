#if 1 //022 ���.
//���� human.h, Human.cpp, ComputerEngineer.h, ComputerEngineer.cpp
#pragma once
#include <iostream>
#include"Human.h"
using namespace std;

//class ComputerEngineer : protected Human
class ComputerEngineer:public Human
{
protected:
	int m_nComputer;
public:
	ComputerEngineer(int age, char* Name, int nComputer);
	~ComputerEngineer();
public:
	void Overtime();	//�߰��� �Լ�
	void Info();		//Ȯ��� �Լ�
	void seta(int a);
	int geta();
	void Play();
	//void test(int a);
	//void seta(int a);
	//int gtest();
};
#endif