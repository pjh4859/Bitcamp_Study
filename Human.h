#if 1
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
	virtual void Eat();
	virtual void Sleep();
	void Work();
	void Info();
	void seta(int a);
	int geta();
	virtual void Play();
};
#endif