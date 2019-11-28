#if 0 //022 상속.
//구성 human.h, Human.cpp, ComputerEngineer.h, ComputerEngineer.cpp
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
	void Overtime();	//추가된 함수
	void Info();		//확장된 함수
	void test(int a);
	void seta(int a);
	int gtest();
};
#endif