#if 0 //022 ���.
//���� human.h, Human.cpp, ComputerEngineer.h, ComputerEngineer.cpp
#include <iostream>
#include"Human.h"

using namespace std;

class ComputerEngineer : public Human
//class ComputerEngineer : protected Human
{
protected:
	int m_nComputer;
public:
	ComputerEngineer(int age, char* Name, int nComputer);
	~ComputerEngineer();
public:
	void Overtime();	//�߰��� �Լ�
	void Info();		//Ȯ��� �Լ�
	void test(int a);
	void seta(int a);
	int gtest();
};
#endif