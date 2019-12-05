#if 0 
#include<iostream>
#include<string>
#pragma warning(disable:4996)
/*
1. 참조계수(reference counting)
	=>여러 객체가 하나의 자원을 공유하게 된다.
	=>단, 몇 명의 객체가 자원을 사용해지는 개수를 관리 한다.
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
	Person p2 = p1;//복사 생성자를 따로 안만들어주면 오류생김.
}
#endif
#if 0
#include<iostream>
#include<string>
#pragma warning(disable:4996)
/*
2. 문자열이 필요하면 STL 의 string 클래스를 사용하자. 
	=>동적 메모리 할당을 할 필요 없다.
	=>string 이 내부적으로 자원을 관리해준다
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
	Person p2 = p1;//복사 생성자를 따로 안만들어주면 오류생김.
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
	static int cnt;//선언 const 는 여기서 초기화가 안댐.
	Car() { cnt++; }
	~Car() { cnt--; }
};
int Car::cnt = 0; //정의
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
1. 멤버 데이터를 사용해서 객체의 개수를 관리하는 경우
	=>멤버 데이터는 객체당 하나씩 별도의 메모리 공간을 사용
	=>개체의 개수는 항상 1 이다.

2. 전역 변수를 사용해서 객체의 개수를 관리하는 경우
	=>전역변수는 메모리에 하나만 있고, 모든 객체가 공유
	=>모든 객체가 공유 하므로 객체의 개수를 구할 수 있다.
	=>전역 변수는 모든 것들이 접근해서 값을 변경 할 수 있어서 문제가 있다.

3. 객체의 개수를 관리하는 변수
	=>같은 클래스의 모든 객체가 공유해야 한다.
	=>외부에 잘못된 사용으로부터 보호 할 수 있어야 한다.

4. 정적 멤버 데이터(ststic member data)
	=> ststic 이 붙은 데이터 멤버
	=>모든 객체가 공유 한다.
	=>클래스 내부에 선언(declaration)를 만들고
	=>클래스 외부에 정의(definition)를 만들어야 한다.

5. 정적 멤버 데이터(ststic member data)의 특징
	=>모든 객체가 공유
	=>멤버 이르모 접근 지정자를 사용 할 수 있다.
*/
#include<iostream>
#include<string>
#pragma warning(disable:4996)
int cnt = 0;
class Car
{
	int speed;
	int color;
	
	static int cnt;//선언 const 는 여기서 초기화가 안댐.
	
public:
	Car() { cnt++; }
	~Car() { cnt--; }
	static int GetCount()
	{
		return cnt;
	}
};
int Car::cnt = 0; //정의
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
(전역변수)
					speed		speed		speed
Car::cnt			color		color		color
(정적 멤버 변수)		c1			c2			c3
-------------------------------------------------------------
			일반 멤버 변수		정적 멤버 변수		전역변수
-------------------------------------------------------------
생성시점		객체 생성시			프로그램 시작 시		"
-------------------------------------------------------------
갯수			객체당 한개			한개(모든 객체가 공유)	"
-------------------------------------------------------------
								c1.cnt
접근 방법		c1.speed			Car::cnt			cnt
접근 지정자	사용가능				"					사용불가
-------------------------------------------------------------
일반 멤버 변수: 자동차 각각의 고유한 특징
정적 멤버 변수: 모든 자동차의 공통의 특징
전역변수: 프로그램에 있는 모든 요소가 접근 가능

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
				일반멤버			정적멤버
일반멤버 함수		o				o
정적멤버 함수		x				o

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
상수 멤버 함수(const member function)
1. 상수 멤버 함수(const member function)
	=>함수 선언 및 구현시 "함수 괄호()뒤에 const 가 붙는 함수
	=>void print()const
2. 상수 멤버 함수의 특징
	=>상수 멤버 함수 안에서는 "모든 멤버를 상수 취급 한다.
	=>멤버 데이터의 값을 읽은 수는 있지만 변경할 수 없다.
3. 상수 멤버 함수를 "사용하는 이유"
	=>코드 작성시 안전성
	=>상수 객체는 상수 멤버 함수만 호출 할 수 있다.

4. const Point pt(1,1)
	=>상수 객체이므로 객체의 상태를 변경 할 수 없어야 한다.
	=>하지만 상태를 얻거나 출력 할 수 있어야 한다.
	=>print멤버 함수는 반드시 상수 멤버 함수로 해야 한다.
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