#if 0
#pragma once
//구성 human.h, Human.cpp, ComputerEngineer.h, ComputerEngineer.cpp

class Human
{
private:
	int a;
protected:
	//여기있는 함수가 이 변수들을 쓸 수 있다.
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