#if 0 
#include<iostream>
#include<string>
#pragma warning(disable:4996)
/*
1. �������(reference counting)
	=>���� ��ü�� �ϳ��� �ڿ��� �����ϰ� �ȴ�.
	=>��, �� ���� ��ü�� �ڿ��� ��������� ������ ���� �Ѵ�.
*/
class Person
{
	char* name;
	int age;
	int* ref;
public:
	Person(const char* n, int a) :age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		ref = new int;
		*ref = 1;
	}
	~Person() 
	{
		if (--(*ref) == 0)
		{
			delete[] name;
			delete ref;
		}
	}
	Person(const Person& p):name(p.name),age(p.age),ref(p.ref)
	{
		(*ref)++;
	//	name = new char[strlen(p.name) + 1];
	//	strcpy(name, p.name);
	}
};
int main()
{
	Person p1("park", 20);
	Person p2 = p1;//���� �����ڸ� ���� �ȸ�����ָ� ��������.
}
#endif
#if 0
#include<iostream>
#include<string>
#pragma warning(disable:4996)
/*
2. ���ڿ��� �ʿ��ϸ� STL �� string Ŭ������ �������. 
	=>���� �޸� �Ҵ��� �� �ʿ� ����.
	=>string �� ���������� �ڿ��� �������ش�
	=>
*/
class Person
{
	//char* name;
	std::string name;
	int age;
public:
	//Person(const char* n, int a) :age(a)
	Person(std::string n, int a):name(n),age(a){}
	~Person(){}
	//Person(const Person& p) = delete;
};
int main()
{
	Person p1("park", 20);
	Person p2 = p1;//���� �����ڸ� ���� �ȸ�����ָ� ��������.
}
#endif
#if 0
#include<iostream>
#include<string>
#pragma warning(disable:4996)
int cnt = 0;
class Car
{
	int speed;
	int color;
public:
	static int cnt;//���� const �� ���⼭ �ʱ�ȭ�� �ȴ�.
	Car() { cnt++; }
	~Car() { cnt--; }
};
int Car::cnt = 0; //����
int main()
{
	Car c1;
	Car c2;
	Car c3;

	std::cout << Car::cnt << std::endl;
	cnt = 0;
	std::cout << Car::cnt << std::endl;
}
#endif
#if 0
/*
1. ��� �����͸� ����ؼ� ��ü�� ������ �����ϴ� ���
	=>��� �����ʹ� ��ü�� �ϳ��� ������ �޸� ������ ���
	=>��ü�� ������ �׻� 1 �̴�.

2. ���� ������ ����ؼ� ��ü�� ������ �����ϴ� ���
	=>���������� �޸𸮿� �ϳ��� �ְ�, ��� ��ü�� ����
	=>��� ��ü�� ���� �ϹǷ� ��ü�� ������ ���� �� �ִ�.
	=>���� ������ ��� �͵��� �����ؼ� ���� ���� �� �� �־ ������ �ִ�.

3. ��ü�� ������ �����ϴ� ����
	=>���� Ŭ������ ��� ��ü�� �����ؾ� �Ѵ�.
	=>�ܺο� �߸��� ������κ��� ��ȣ �� �� �־�� �Ѵ�.

4. ���� ��� ������(ststic member data)
	=> ststic �� ���� ������ ���
	=>��� ��ü�� ���� �Ѵ�.
	=>Ŭ���� ���ο� ����(declaration)�� �����
	=>Ŭ���� �ܺο� ����(definition)�� ������ �Ѵ�.

5. ���� ��� ������(ststic member data)�� Ư¡
	=>��� ��ü�� ����
	=>��� �̸��� ���� �����ڸ� ��� �� �� �ִ�.
*/
#include<iostream>
#include<string>
#pragma warning(disable:4996)
int cnt = 0;
class Car
{
	int speed;
	int color;
	
	static int cnt;//���� const �� ���⼭ �ʱ�ȭ�� �ȴ�.
	
public:
	Car() { cnt++; }
	~Car() { cnt--; }
	static int GetCount()
	{
		return cnt;
	}
};
int Car::cnt = 0; //����
int main()
{
	std::cout << Car::GetCount() << std::endl;
	Car c1;
	Car c2;
	Car c3;

	std::cout << c1.GetCount() << std::endl;
	cnt = 0;
	std::cout << c1.GetCount() << std::endl;
}
#endif
#if 0
/*
cnt
(��������)
					speed		speed		speed
Car::cnt			color		color		color
(���� ��� ����)		c1			c2			c3
-------------------------------------------------------------
			�Ϲ� ��� ����		���� ��� ����		��������
-------------------------------------------------------------
��������		��ü ������			���α׷� ���� ��		"
-------------------------------------------------------------
����			��ü�� �Ѱ�			�Ѱ�(��� ��ü�� ����)	"
-------------------------------------------------------------
								c1.cnt
���� ���		c1.speed			Car::cnt			cnt
���� ������	��밡��				"					���Ұ�
-------------------------------------------------------------
�Ϲ� ��� ����: �ڵ��� ������ ������ Ư¡
���� ��� ����: ��� �ڵ����� ������ Ư¡
��������: ���α׷��� �ִ� ��� ��Ұ� ���� ����

*/
int cnt = 0;
class Car
{
public:
	int speed;
	int color;
	static int cnt;
	Car(){}
};
int Car::cnt = 0;
int main()
{
	
	Car::cnt = 10;
	Car c1, c2, c3;
	
}
#endif
#if 0
class Test
{
public:
	int data = 0; //C++11
	static int sdata1;
	static const int sdata2 = 0;	//ok
	//static const double sdata3 = 0; //error
	static constexpr int sdata4 = 0;
	static constexpr double sdata5 = 0;

	inline static int sdata6 = 0; //C++17
	inline static double sdata7 = 0; //C++17
};
int Test::sdata1 = 0;
int main()
{
	int n1 = Test::sdata1;
	int n2 = Test::sdata2;
	//double n3 = Test::sdata3;
	int n4 = Test::sdata4;
	double n5 = Test::sdata5;
	int n6 = Test::sdata6;
	double n7 = Test::sdata7;
}
#endif
#if 0
/*
				�Ϲݸ��			�������
�Ϲݸ�� �Լ�		o				o
������� �Լ�		x				o

*/
class Test
{
	int data1;
	static int data2;
public:
	static void foo()
	{
		data1 = 0;
		data2 = 0;
		goo();
		koo();
	}
	void goo()
	{
		data1 = 0;
		data2 = 0;
		foo();
	}
	static void koo()
	{

	}
};
int Test::data2 = 0;
int main()
{
	Test::foo();
	Test t;
	t.goo();
	t.foo();
}
#endif
#if 0
/*
��� ��� �Լ�(const member function)
1. ��� ��� �Լ�(const member function)
	=>�Լ� ���� �� ������ "�Լ� ��ȣ()�ڿ� const �� �ٴ� �Լ�
	=>void print()const
2. ��� ��� �Լ��� Ư¡
	=>��� ��� �Լ� �ȿ����� "��� ����� ��� ��� �Ѵ�.
	=>��� �������� ���� ���� ���� ������ ������ �� ����.
3. ��� ��� �Լ��� "����ϴ� ����"
	=>�ڵ� �ۼ��� ������
	=>��� ��ü�� ��� ��� �Լ��� ȣ�� �� �� �ִ�.

4. const Point pt(1,1)
	=>��� ��ü�̹Ƿ� ��ü�� ���¸� ���� �� �� ����� �Ѵ�.
	=>������ ���¸� ��ų� ��� �� �� �־�� �Ѵ�.
	=>print��� �Լ��� �ݵ�� ��� ��� �Լ��� �ؾ� �Ѵ�.
*/
#include<iostream>
class Point
{
public:
	int x, y;
	Point(int a=0,int b=0):x(a),y(b){}
	void set(int a, int b) { x = a; y = b; }
	void print()const
	{
		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
	//const Point pt(1, 1);
	const Point pt(1, 1);
	pt.x = 10;
	pt.set(10, 10);
	pt.print();
}
#endif
#if 0
class Rect
{
	int xpos, ypos, width, height;
public:
	Rect(int x = 0, int y = 0, int w = 0, int h = 0)
		:xpos(x), ypos(y), width(w), height(h) {}
	int getArea()const
	{
		return width * height;
	}
};
void foo(const Rect& r)
{
	int n = r.getArea();
}
int main()
{
	Rect r(1, 1, 10, 10);
	int n = r.getArea();
	foo(r);
}
#endif
#if 1
#include<iostream>
class Point
{
	int x, y;
	mutable int cnt = 0;
public:
	Point(int a = 0, int b = 0) :x(a), y(b) {}
	void print()const
	{
		++cnt;
		std::cout << x << ", " << y << std::endl;
		std::cout << "cnt:"<<cnt<< std::endl;
	}

};
int main()
{
	const Point pt(1,1);
	Point p1{};
	pt.print();
	pt.print();
	p1.print();
	p1.print();
	p1.print();
	p1.print();
}
#endif