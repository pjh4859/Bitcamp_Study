#if 0
#pragma once
//���� human.h, Human.cpp, ComputerEngineer.h, ComputerEngineer.cpp

class Human
{
private:
	int a;
protected:
	//�����ִ� �Լ��� �� �������� �� �� �ִ�.
	int b;
	int m_nAge;
	char* m_strName;
public:
	Human(int age, char* Name);
	~Human();
public:
	int c;
	void Eat();
	void Sleep();
	void Work();
	void Info();
	void seta(int a);
	int geta();
};
#endif