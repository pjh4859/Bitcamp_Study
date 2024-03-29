#if 0 //001
#include<iostream>
#pragma warning(disable:4996)

void main()
{
	int num1 = 0;
	printf("정수 입력:");
	scanf("%d", &num1);

	int num2 = 0;
	printf("정수 입력:");
	scanf("%d", &num2);
	printf("%d + %d = %d\n", num1, num2, num1 + num2);
}
#endif

#if 0 //002
#include<iostream>
struct point
{
	int x;
	int y;
};
int main()
{
	point pt;
	pt.x = 10;
	pt.y = 20;
	printf("%d, %d \n", pt.x, pt.y);
	return 0;

}
#endif

#if 0 //003
//C에서는 스트럭쳐 안에 함수 선언 불가.
#include<iostream>
struct point
{
	int x;
	int y;
	void add(point a, point b)
	{
		x = a.x + b.x;
		y = a.y + b.y;
	}
	void sub(point a, point b)
	{
		x = a.x - b.x;
		y = a.y - b.y;
	}
};
void main()
{
	point pta, ptb, ptresult;
	pta.x = 100;
	pta.y = 200;
	ptb.x = 50;
	ptb.y = 100;
	ptresult.add(pta, ptb);
	printf("%d %d \n", ptresult.x, ptresult.y);
	ptresult.sub(pta, ptb);
	printf("%d %d \n", ptresult.x, ptresult.y);
}
#endif

#if 0 //004
#include<cstdio>
#include<cmath>

void main()
{
	int num;
	printf("음수입력:");
	scanf_s("%d", &num);
	printf("절대값:%d\n",abs(num));
}
#endif
#if 0 //005
#include<iostream>

void main()
{
	int num1, num2;
	std::cout << "정수 2개 입력: " << std::endl;
	//std::cout 은 변수 <<가 함수
	std::cin >> num1 >> num2;
	std::cout<<num1<<"+"<<num2<<" = \
		"<<num1+num2<<std::endl;
}
#endif
#if 0 //006
#include<iostream>
#pragma warning(disable:4996)

namespace A
{
	int Plus(int a, int b)
	{
		return a+b;
	}
}
namespace B
{
	char* Plus(char* a, char* b)
	{
		int len = strlen(a);
		int len2 = strlen(b);
		char* str = (char*)malloc(sizeof(char) * (len + len2 + 1));
		memset(str, 0, len + len2 + 1);
		
		strncpy(str, a, len);
		strncpy(str + len, b, len2);
		return str;
	}
}
void main()
{
	int a = 10, b = 20, result;
	const char* str = "아름다운", * str2 = "대한민국", * strResult;
	result = A::Plus(a, b);
	std::cout << result << std::endl;
	strResult = B::Plus((char*)str, (char*)str2);
	std::cout << strResult << std::endl;
	free((void*)strResult);
}
#endif //007
#if 0
//007 bool 자료형
#include<iostream>
using namespace std;
//std 안의 이름을 다 사용한다.
void main()
{
	int num;
	std::cout << "숫자를 입력하세요:";
	//위의 using namespace std;를 안쓰면 위처럼 써야함.
	cin >> num;

	bool b = num > 0;
	if (b == true)
		cout << num << "은양수입니다." << endl;
	else if (b == false)
		cout << num << "은양수가아닙니다" << endl;
}
#endif
#if 0 //008 Reference 비교.
#include<iostream>
using namespace std;

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void swapPoint(int* pa, int* pb)
{
	int temp = *pa;
	*pa=*pb;
	*pb = temp;
}
void swapRef(int& ra, int& rb)
{
	int temp = ra;
	ra = rb;
	rb = temp;
}

int main()
{
	int num1 = 10, num2 = 20;
	int num3 = 10, num4 = 20;
	int num5 = 10, num6 = 20;
	swap(num1, num2);
	cout << "swap[" << num1 << "," << num2 << "]" << endl;
	swapPoint(&num3, &num4);
	cout << "swapRef [" << num3 << "," << num4 << "]" << endl;
	swapRef(num5, num6);
	cout << "swapRef [" << num5 << "," << num6 << "]" << endl;
}
#endif
#if 0 //009
#include<iostream>
using namespace std;

int main()
{
	int* p;
	int num = 10;
	int aaa = 20;
	int& r=num;
	//ref는 한번 선언하면 바꿀 수 없다.
	p = &num;
	p = &aaa;
	cout << "r:" << r << endl;
	num = 50;
	cout << "r:" << r << endl;
}
#endif
#if 0 //010 함수 오버로딩
//함수이름 뒤에 받는매개변수 타입과 갯수를보고 이름을 붙여줘서 다르게 함.
//
#include<iostream>
using namespace std;
int Add(int a, int b)
{
	return a + b;
}
double Add(double a, double b)
{
	cout << "double Add" << endl;
	return a + b;
}
float Add(float a, float b)
{
	cout << "Float Add" << endl;
	return a + b;
}
void main()
{
	cout << Add(3, 5) << endl;
	cout << Add(3.14, 5.25) << endl;
	cout << Add(3.1f, 3.1f) << endl;
}
#endif
#if 0 //011 디폴트 파라미터.
#include<iostream>
using namespace std;
int Add(int a = 10, int b = 20)
{
	return a + b;
}
int AddTwo(int a, int b=100)
{
	return a + b;
}
int main()
{
	cout << Add(3, 5) << endl;
	cout << Add() << endl;
	cout << AddTwo(200) << endl;
	cout << AddTwo(200,300) << endl;
	return 0;
}
#endif
#if 0 //012 inline 함수
#include<iostream>
using namespace std;
inline int Add(int a, int b)
{
	return a + b;
}
void main()
{
	int result = 0, i = 0;
	for (i = 0; i < 5; i++)
		result = Add(result, i++);
	cout << result << endl;
}
#endif
#if 0 //013 new, delete 연산자 malloc free 와 같은 것.
#include<iostream>
using namespace std;

void main()
{
	int* num = new int();
	*num = 100;
	cout << *num << endl;
	delete num;
}
#endif

#if 0 //014 
#include<iostream>
#define ARR_LEN 100

using namespace std;
void main()
{
	int* num = new int[ARR_LEN]();
	for (int i = 0; i < ARR_LEN;i++)
		num[i] = i;
	for (int i = 0; i < ARR_LEN; i++)
		cout << num[i] << endl;
	delete[]num;
}

#endif
#if 0 //015 클래스 
#include<iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	void SetPoint(int _x, int _y);
	void AddPoint(Point& pt);
	void SubPoint(Point& pt);
	void MovePoint(int addX,int addY);
	void ShowPoint();
};

void Point::SetPoint(int _x, int _y)
//::의미,Point 안에있는 SetPoint 함수.
{
	x = _x;
	y = _y;
}
void Point::AddPoint(Point& pt)
{
	x += pt.x;
	y += pt.y;
}
void Point::SubPoint(Point& pt)
{
	x -= pt.x;
	y -= pt.y;
}
void Point::MovePoint(int addX, int addY)
{
	x += addX;
	y += addY;
}
void Point::ShowPoint()
{
	cout << "x,y : [" << x << "," << y << "]" << endl;
}
void main()
{
	Point pt, pt1;
	pt.SetPoint(100, 100);
	pt1.SetPoint(30, 30);
	pt.AddPoint(pt1);
	pt.ShowPoint();
	pt.SubPoint(pt1);
	pt.ShowPoint();
	pt.MovePoint(100, 100);
	pt.ShowPoint();
}
#endif 
#if 0 //016 생성자 소멸자
#include<iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point();
	~Point();
public:
	void SetPoint(int _x, int _y);
	void AddPoint(Point& pt);
	void SubPoint(Point& pt);
	void MovePoint(int addX, int addY);
	void ShowPoint();
};

Point::Point()
{
	x = 0;
	y = 0;
	cout << "생성자호출" << endl;
}
Point::~Point()
{
	cout << "소멸자호출" << endl;
}
void Point::SetPoint(int _x, int _y)
{
	x = _x;
	y = _y;
}
void Point::AddPoint(Point& pt)
{
	x += pt.x;
	y += pt.y;
}
void Point::SubPoint(Point& pt)
{
	x -= pt.x;
	y -= pt.y;
}
void Point::MovePoint(int addX, int addY)
{
	x += addX;
	y += addY;
}
void Point::ShowPoint()
{
	cout << "x,y :[" << x << "," << y << "]" << endl;

}
int main()
{
	Point pt, pt1;
	pt.SetPoint(100, 100);
	pt1.SetPoint(30, 30);
	pt.AddPoint(pt1);
	pt.ShowPoint();
	pt.SubPoint(pt1);
	pt.ShowPoint();
	pt.MovePoint(100, 100);
	pt.ShowPoint();

	return 0;
}
#endif

#if 0 //017 복사생성자
#include<iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point();
	Point(int _x, int _y);
	~Point();
public:
	void SetPoint(int _x, int _y);
	void AddPoint(Point& pt);
	void SubPoint(Point& pt);
	void MovePoint(int addX, int addY);
	void ShowPoint();
};

Point::Point()
{
	x = 0;
	y = 0;
	cout << "생성자호출" << endl;
}
Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
	cout << "매개변수있는 생성자호출" << endl;
}
Point::~Point()
{
	cout << "소멸자호출" << endl;
}
void Point::SetPoint(int _x, int _y)
{
	x = _x;
	y = _y;
}
void Point::AddPoint(Point& pt)
{
	x += pt.x;
	y += pt.y;
}
void Point::SubPoint(Point& pt)
{
	x -= pt.x;
	y -= pt.y;
}
void Point::MovePoint(int addX, int addY)
{
	x += addX;
	y += addY;
}
void Point::ShowPoint()
{
	cout << "x,y :[" << x << "," << y << "]" << endl;

}
int main()
{
	Point pt(100, 100);
	pt.ShowPoint();
	Point pt1 = pt;
	pt.ShowPoint();
	Point pt2(pt);
	pt2.ShowPoint();
	
	return 0;
}
#endif

#if 0 //018 
#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point();
	Point(int _x, int _y);
	Point(const Point& pt);                     //래퍼런스 변수는 선언과 동시에 초기화해야함

	~Point();
public:
	void SetPoint(int _x, int _y);
	void AddPoint(Point& pt);
	void SubPoint(Point& pt);
	void MovePoint(int addX, int addY);
	void ShowPoint();
};

Point::Point(const Point& pt)
{
	cout << "복사 생성자 호출" << endl;
	x = pt.x;
	y = pt.y;
}

Point::Point()
{
	x = 0;
	y = 0;
	cout << "생성자호출" << endl;
}

Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
	cout << "매개변수있는 생성자 호출" << endl;
}

Point::~Point()
{
	cout << "소멸자호출" << endl;
}

void Point::SetPoint(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Point::AddPoint(Point& pt)
{
	x += pt.x;
	y += pt.y;
}

void Point::SubPoint(Point& pt)
{
	x -= pt.x;
	y -= pt.y;
}

void Point::MovePoint(int addX, int addY)
{
	x += addX;
	y += addY;
}

void Point::ShowPoint()
{
	cout << "x, y : [" << x << ", " << y << "]" << endl;
}

int main()
{
	//   Point pt(100, 100), pt1(30, 30);
	//   pt.AddPoint(pt1);
	//   pt.ShowPoint();
	//   pt.SubPoint(pt1);
	//   pt.ShowPoint();
	//   pt.MovePoint(100, 100);
	//   pt.ShowPoint();

	//   Point pt(100, 100);
	//   Point pt1 = pt;
	//   pt1.ShowPoint();
	//   Point pt2(pt);
	//   pt2.ShowPoint();

	int i = 10;
	int k = i;
	Point t;
	Point pt(100, 200);         //함수 오버로딩
	Point pt1 = pt;
	//   pt1.x = 300;            //허가권 없음, 안됨, Point::으로 시작하는 애들은 허가권 있음.
	//   cout<<"pt.x"<<



}
#endif

#if 0 //019 복사 생성자.(망함.) 
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
class Point
{
private:
	char* Name;
	int x;
	int y;
public:
	Point(char* _Name, int _x, int _y);
	Point(const Point& pt);
	Point& operator=(const Point& pt);
	~Point();
public:
	void SetPoint(int _x, int _y);
	void AddPoint(Point& pt);
	void SubPoint(Point& pt);
	void MovePoint(int addX, int addY);
	void ShowPoint();
};
//Point& operator=(Point&a,Point&)
Point::Point(char* _Name, int _x, int _y)
{
	Name = new char[strlen(_Name) + 1];
	memset(Name, 0, strlen(_Name) + 1);
	x = _x;
	y = _y;
	cout << "매개변수 있는 생성자호출" << endl;
}
Point::Point(const Point& apt)
{
	if (apt.Name)
	{
		Name = new char[strlen(apt.Name) + 1];
		memset(Name, 0, strlen(apt.Name) + 1);
		strncpy(Name, apt.Name, strlen(apt.Name));
	}
	x = apt.x;
	y = apt.y;
	cout << "복사 생성자 호출" << endl;
}

Point& Point::operator=(const Point& apt)
{
	if (strlen(Name) < strlen(apt.Name))
	{
		delete[] Name;
		Name = new char[strlen(apt.Name) + 1];
		memset(Name, 0, strlen(apt.Name) + 1);//0으로 초기화
		strncpy(Name, apt.Name, strlen(apt.Name));
	
		goto next;
	}
	memset(Name, 0, strlen(apt.Name) + 1);
	strncpy(Name, apt.Name, strlen(apt.Name));
next:
	x = apt.x;
	y = apt.y;
	//cout << "복사 생성자 호출" << endl;
	cout << "연산자 재정의" << endl;
	return *this;
}
Point::~Point()
{
	delete[] Name;
	cout << "소멸자 호출" << endl;
}
void Point::AddPoint(Point& pt)
{
	x += pt.x;
	y += pt.y;
}
void Point::SubPoint(Point& pt)
{
	x -= pt.x;
	y -= pt.y;
}
void Point::MovePoint(int addX,int addY)
{
	x += addX;
	y += addY;
}
void Point::ShowPoint()
{
	cout << "x, y : [" << x << ", " << y << "]" << endl;
}
void main()
{
	Point pt((char*)"고르바초프 동무", 100, 100);
	Point pt1 = pt;
	pt1 = pt;
	pt1.ShowPoint();
	Point t;
	t = pt + pt1;
	t.ShowPoint();

}
#endif
#if 0 // 020 static 멤버
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
#define NAME_LEN 30

class Theater
{
private:
	char* m_strName;
	static int m_nViewerCount;
	//static은 글로벌 영역에 잡히기 떄문에 두 변수가 있지만 sizeof로 이건 4바이트 나옴.
	int localView{ 0 };
public:
	Theater(char* _Name)
	{
		this->m_strName = new char[NAME_LEN];
		memset(m_strName, 0, NAME_LEN);
		strcpy(m_strName, _Name);
	}
	Theater(const Theater& theater)
	{
		m_strName = new char[NAME_LEN];
		memset(m_strName, 0, NAME_LEN);
		memcpy(m_strName, theater.m_strName, NAME_LEN);
	}
	~Theater()
	{
		delete[]m_strName;
	}
	static void AddViewerCount()
	{
		m_nViewerCount++;
	}
	int GetlocalCount()
	{
		m_nViewerCount++;
		localView++;
	}
	static int GetViewerCount()
	{
		return m_nViewerCount;
	}
};
int Theater::m_nViewerCount = 0;
//static 이기때문에 외부에서 오픈해줘야 쓸 수있다. 초기화도 이렇게 전역 영역에 해야함.
//static 이면 객체가 없어도 접근할 수 있다.
void main()
{
	//Theater::AddViewerCount();
	//Theater::GetlocalCount();
	//Theater::m_nViewerCount;
	Theater test((char*)"대지극장");
	test.GetlocalCount();
	test.AddViewerCount();
	cout << "관객수 : " << Theater::GetViewerCount() << "명" << endl;
	Theater theater1((char*)"단성사");
	Theater theater2((char*)"서울극장");
	Theater theater3((char*)"명동CGV");
	printf("%d\n", sizeof(Theater));
	for (int i = 0; i < 1000000; i++)
		theater1.AddViewerCount();
	for (int i = 0; i < 1500000; i++)
		theater2.AddViewerCount();
	for (int i = 0; i < 2000000; i++)
		theater3.AddViewerCount();
	cout << "관객수 : " << Theater::GetViewerCount() << "명" << endl;
}
#endif
#if 0 // 021 this pointer
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
#define NAME_LEN 30

class Theater
{
private:
	char* m_strName;
	static int m_nViewerCount;
	//static은 글로벌 영역에 잡히기 떄문에 두 변수가 있지만 sizeof로 이건 4바이트 나옴.
	int localView{ 0 };
public:
	Theater(char* _Name)
	{
		this->m_strName = new char[NAME_LEN];
		memset(m_strName, 0, NAME_LEN);
		strcpy(m_strName, _Name);
	}
	Theater(const Theater& theater)
	{
		m_strName = new char[NAME_LEN];
		memset(m_strName, 0, NAME_LEN);
		memcpy(m_strName, theater.m_strName, NAME_LEN);
	}
	~Theater()
	{
		delete[]m_strName;
	}
	static void AddViewerCount()
	{
		m_nViewerCount++;
	}
	int GetlocalCount()
	{
		//m_nViewerCount++;
		//localView++;
		return localView;
	}
	void LocalCount()
	{
		this->localView++;
	}
	void LocalCountSet(int LocalView)
	{
		LocalView = localView;
	}
	static int GetViewerCount()
	{
		return m_nViewerCount;
	}
};
int Theater::m_nViewerCount = 0;
//static 이기때문에 외부에서 오픈해줘야 쓸 수있다. 초기화도 이렇게 전역 영역에 해야함.
//static 이면 객체가 없어도 접근할 수 있다.
void main()
{
	//Theater::AddViewerCount();
	//Theater::GetlocalCount();
	//Theater::m_nViewerCount;
	//Theater test((char*)"대지극장");
	//test.GetlocalCount();
	//test.AddViewerCount();

	cout << "관객수 : " << Theater::GetViewerCount() << "명" << endl;
	Theater theater1((char*)"단성사");
	Theater theater2((char*)"서울극장");
	Theater theater3((char*)"명동CGV");
	printf("%d\n", sizeof(Theater));
	for (int i = 0; i < 100; i++)
		//theater1.AddViewerCount();
		theater1.LocalCount();
	for (int i = 0; i < 150; i++)
		//theater2.AddViewerCount();
		theater2.LocalCount();
	for (int i = 0; i < 200; i++)
		//theater3.AddViewerCount();
		theater3.LocalCount();
	cout << "theater1관객수 : " << theater1.GetlocalCount() << "명" << endl;
	cout << "theater2관객수 : " << theater2.GetlocalCount() << "명" << endl;
	cout << "theater3관객수 : " << theater3.GetlocalCount() << "명" << endl;
}

#endif
#if 0 //022 상속.

#include<iostream>
#include"ComputerEngineer.h"
#include"Human.h"

using namespace std;

int main()
{
	ComputerEngineer comEng(32, (char*)"Tom", 3);
	cout << "sizeof(ComputerEngineer) : " << sizeof(ComputerEngineer) << endl;
	//comEng.m_nAge;
	//comEng.m_nComputer;
	comEng.c;
	comEng.test(100);
	cout << "comEng.gtest() : " << comEng.gtest() << endl;
	comEng.seta(100);
	cout << "comEng.gtest() : " << comEng.gtest() << endl;
	Human aaa(20, (char*)"hello");
	aaa.c = 20;
	//aaa.seta;
	//aaa.geta;
	//aaa.b = 30;
}
#endif
#if 0 //023 연산자 오버로딩.
#include<iostream>
#include"Position.h"

using namespace std;
Position operator+(int i, Position& pos)
{
	Position temp=pos.GetValue();
	return temp+i;
}
void main()
{
	int i = 10;
	Position pos(100.0, 100.0);
	Position a(100, 100);
	Position c;
	++pos;
	pos++;
	++i;
	c = a + pos;
	//c = pos + i;//pos.operator+(i)
	c = i + pos;
	c.ShowPosition();

	//pos++.ShowPosition();
}
#endif

#if 0 //024 
#include<iostream>
using namespace std;

bool Divide(double dividend, double divider, double& result)
{
	if (divider == 0)
		return false;

	result = dividend/divider;
	return true;
}
int main()
{
	double num1, num2, result;

	cout << "A/B를 연산할 2개의 수 입력:";
	cin >> num1 >> num2;

	if (Divide(num1, num2, result))
		cout << num1 << " / " << num2 << " = " << result << endl;
	else
		cout << "Invalid Value!!!" << endl;
}
#endif

#if 0 //025 try~catch 
#include<iostream>
using namespace std;

bool Divide(double dividend, double divider, double& result)
{
	if (divider == 0)
		throw false;

	result = dividend / divider;
}
int main()
{
	double num1, num2, result;

	cout << "A/B 를 연산할 2개의 수 입력:";
	cin >> num1 >> num2;

	try
	{
		Divide(num1, num2, result);
		cout << num1 << "/" << num2 << "=" << result << endl;
	}
	catch (bool exception)
	{
		cout << "invalid Value!!!" << endl;
	}
	catch (int exception)
	{
		cout << "Invalid Value!!: " << exception << endl;
	}
}
#endif
#if 0 //026 tamplet
#include<iostream>

using namespace std;

template<typename T>
T Add(T a, T b)
{
	return a + b;
}
//double Add(double a, double b)
//{
//	return a + b;
//}
void main()
{
	cout << Add<int>(10, 20) << endl;
	cout << Add<double>(3.1, 5.3) << endl;
}
#endif
#if 0 //027 tamplet 2
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

template<typename T>
T Add(T a, T b)
{
	return a + b;
}
template<>
char* Add(char* a, char* b)
{
	char* p = new char[strlen(a) + strlen(b) + 1];
	int len = strlen(a);
	strncpy(p, a, len);
	int len2 = strlen(b);
	strncpy(p + len, b, len2);
	p[len + len2] = 0;
	return p;
}
void main()
{
	char* p;
	cout << Add<int>(10, 20) << endl;
	cout << Add <double>(3.1, 5.3) << endl;
	cout << (p = Add<char*>((char*)"아름다운", (char*)"대한민국")) << endl;
	delete[] p;
}

#endif
#if 0 //028
#include <stdio.h>
/*
namespace 의 필요성
1. 하나의 프로그램은 수십~ 수백개의 파이로 구성될 수 있고
수십명의 개발자가 같이 작업을 할 수 있다.
2. 함수 및 구조체의 이름 충돌이 발생 할 수 있다.
*/
void init()
{
	printf("Audio init\n");
}
void init()
{
	printf("Video init\n");
}
void init()
{
	printf("System init\n");
}
void main()
{
	init();
}
#endif

#if 0 //028(2)
#include <stdio.h>
/*
namespace 의 필요성
1. 프로그램의 다양한 요소 (함수, 구조체등)을 연관된 요소끼리 관리 할 수 있다.
2. 기능별로 다른 이름 공간을 사용함으로써 함수/구조체등의 이름 충돌을 막을 수 있다.
*/
namespace Audio
{
	void init()
	{
		printf("Audio init\n");
	}
}

namespace Video
{
	void init()
	{
		printf("Video init\n");
	}
}
void init()
{
	printf("System init\n");
}
void main()
{
	init();
	Audio::init();
	Video::init();
}
#endif
#if 0 //028(3)
#include<stdio.h>
/*
namespace 에 있는 요소 접근방법 3가지
1."한정된 이름(qualified name)"
	==>Audio::init();
2. "using 선언(declaration)"
	==>using Audio::init;
3. "using 지시어(directive)"
	==>using namespace Audio;
*/
namespace Audio
{
	void init() { printf("Audio init\n"); }
	void reset() { printf("Audio reset\n"); }
}
void init() { printf("Global init\n"); }
int main()
{
	Audio::init();
	//using Audio::init;
	//init();
	using namespace Audio;
	reset();
	::init();
}
#endif
#if 0 //028(4)
#include"Audio.h"
int main()
{
	Audio::init();
}
#endif
#if 0 //029
#include<algorithm>
#include<iostream>

using namespace std;
int main()
{
	int n = std::max(1, 2);
	std::cout << n;
}
#endif
#if 0 //030
#include<stdio.h>
#include<algorithm>
using namespace std;
int count = 0;
int main()
{
	printf("%d\n", std::max(1, 2));
	printf("%d\n", ::count);
	//algorithm lib에 count 가 있어서 using namespace std;를 하면 충돌이 난다. 
	//::count 로 int count 를 쓸 수 있다.
}
#endif
#if 0  //031
//C++ 헤더파일의 특징
//<stdio.h> vs <cstdio>
/*
1. 헤더 파일의 확장자를 사용하지 않는다.
2. 기존 c 헤더를 대신하는 "새로운 헤더파일" 을 제공한다.
	==><stdio.h> --> <cstdio>
	==><stdlib.h> --> <cstdlib>
	==><헤더파일이름.h> --> <c헤더파일이름>
*/
#include<algorithm>
#include<cstdio>
#include<stdio.h>
using namespace std;
int main()
{
	printf("%d\n", std::max(1, 2));
	std::printf("%d\n", std::max(1, 2));
}
#endif
#if 0 //031(2)
/*
전역 공간에 있는 함수를 namespace에 포함하는 방법
==> using 선언을 사용하면 된다.
*/
void foo() {}
namespace Audio
{
	// void foo() {}
	using ::foo;
	void init() {}
}
int main()
{
	Audio::init();
	using Audio::init;
	using namespace Audio;
	init();
	foo();
	Audio::foo();
}
#endif
#if 0 //032
#include<stdio.h>
int main()
{
	int age = 0;
	printf("How old are you >>");
	scanf_s("%d", &age);
	printf("age: %d\n", age);
}
#endif
#if 0 //032(2)
/*
1. 표준 출력
	==>std::cout
	==>변수 값 출력시 "서식 문자열을 지정할 필요가 없다."
	==> <<를 연속적으로 "여러번 사용" 할 수도 있다.
2. 개행
	==>std::endl;
	==>C 언어의 \n 을 사용해도 된다.
3. 표준 입력
	==> std::cin
	==> 서식 문자열이 필요없고, 주소 연산자를 사용하지 않는다.
4. 표준 입출력을 사용하기 위한 해더 파일
	==> <iostream>
	1. printf와  scanf ==> 함수
	2. std::cout, std::in ==>함수 ? 변수! 키워드?
	3. std::endl 과 '\n' 의 차이점.
*/
#include<iostream>
int main()
{
	int age = 0;
	std::cout << "How old are you !" << std::endl;
	std::cout << "How old are you !" << '\n';
	std::cin >> age;
	std::cout << "age :" << age << std::endl;
}
#endif
#if 0 //033
//iomanipulator
#include<iostream>
#include<iomanip>
int main()
{
	int n = 10;
	std::cout << n << std::endl;
	std::cout << std::hex<< n << std::endl;
	std::cout << n << std::endl;
	std::cout << n << std::dec;
	std::cout << n << std::endl;
	std::cout << "hello" << std::endl;
	std::cout << std::setw(10) << "hellow" << std::endl;
	std::cout << std::setw(10) << std::setfill('#') << "heo;lo" << std::endl;
	std::cout << std::setw(10) << std::setfill('#') << std::left <<"hekko"<< std::endl;

}
#endif
#if 0 //034
#include<iostream>
struct Point
{
	int x=0;
	int y=9;
};
int main()
{
	if (1){}
	int n = 0;
	Point pt;
	std::cout << pt.x << "," << pt.y << std::endl;
	int n1 = 0b010; //0x10,070(8진수), 0b010(2진수)
	int n2 = 1'000'000;
	bool b = true;
	long long n3 = 10; //64bit 정수 C++11
	char* s1 = (char*)"aaa";
	wchar_t* s2 = (wchar_t*)L"AAA"; //유니코드 지원

	char16_t a = 'a';
	char32_t c = 'c';

}
#endif
#if 0 //035
/*
일관된 초기화(uniform initalization)
1. 변수를 초기화 할 때, 중괄호 {} 를 사용해서 초기화 하는 것.
2. C++11 에서 도입 된 문
*/
int main()
{
	int n1 = 10;
	int n2 = { 10 };
}
#endif
#if 0 //035(2)
/*
일관된 초기화(uniform initialization)
기존 초기화 방법의 문제점
1. 변수의 타입/종류에 따라 "초기화 방법이 다르다"
	==> "=값", "(값)", "{값}"
2. 암시적 형변환에 따른 데이터 손실 이 발생 할 수 있다.

일괄된 초기화(uniform initialization) 의 장점
1. 모든 종류의 변수를 초기화 할 때 하나의 방식(ubiform) 으로 초기화 가능/
2.데이터 손실이 발생할 경우 컴파일 에러 발생
*/
struct Point
{
	int x;
	int y;
};
int main()
{
	/*
	int n1 = 10;
	int n2(10);

	int x[2] = { 1,2 };
	Point pt{ 1,2 };
	char c = 300;
	int n3 = 3.4;
	*/
	int n1 = { 10 };
	int n2{ 10 };

	int x[2] = { 1,2 };
	Point pt = { 1,2 };

	int n3 = { 3.4 };
	char c = { 300 };
}
#endif
#if 0 //035(3)
/*
초기화의 2가지 형태
1. 직접 초기화(direct initailization)
	==> int n(0);
	==> int n{0};

2. 복사 초기화(copy ")
	==> int n=0;
	==> int n{0};
*/

struct Point
{
	int x;
	int y;
};
void goo(Point p) {}
void foo(int n) {}
int main()
{
	int n = 10;
	int n1 = { 10 };
	foo(3.14);
	foo({ 3 });
	goo({ 1,2 });

	int n2 = { 0 };//copy 초기화
	int n3{ 0 };//direct 초기화
}
#endif
#if 0 //036
//auto /decltype
/*
1. 변수의 타입을 컴파일러가 결정 하는 문법
	==> 컴파일 시간에 결정, 되므로 실행시간 오버헤드는 없다.
2. auto
	==> 우변의 수식 (expression) 으로 좌변의 타입 을 결정
	==> 반드시 초기값(우변식)이 필요하다.
3. decltype
	==> ()안의 표현식을 가지고 타입을 결정
	==> 초기값이 ㅇ벗어도 된다.
*/
int main()
{
	int x[5] = { 1,2,3,4,5 };
	int n1 = x[0];
	double d = 3.14;
	auto n2 = x[0];
	auto d1 = d;//auto 는 대입\받는 값의 자료형에 맞춰줌.

	decltype(n1) n3;//n1타입으로n3타입을 선언
	decltype(n1) n3= n1;//n1타입으로n3타입을 선언하고 값도 복사
}
#endif
#if 0 //036(2)
/*
1.auto
	==>우변이 배열이면 요소를 가리키는 포인터 타입으로 타입이 결정된다.
2. decltype 
	==> ()안의 표현식이 배열이면 ()안의 표현식과 완전히 동일한 배열타입으로 결정
	==> 이 경우 동일 표현식으로 초기화 할 수 없다.
3. auto 와 decltype 는 표현식에 따라 타입이 다르게 결정 되는 경우가 이다.
	==> int y[2] ={1,2};
	==> decltypr(y[0]) d4 = y[0];  //int& 로 결정
*/
#include<iostream>
int main()
{
	int n1 = 10;
	auto a1 = n1;
	decltype(n1) d1;

	int x[3] = { 1,2,3, };
	auto a2 = x; //1.int a2[3] =x;라고 추론하면???

	decltype(x) d2; //int d2[3]으로 추론...

	std::cout << "a1: " << a1 << std::endl;
	std::cout << "x: " << x << std::endl;
	std::cout << "a2: " << a2 << std::endl;
	std::cout << "sizeof(d2):" << sizeof(d2) << std::endl;
	decltype(x)d3 = { 1,2,3 };
	//int d3[3] = { x, };
	int y[2] = { 1,2 };
	auto a4 = y[0];//int
	decltype(y[0]) d4=y[0];//int가 아니고 int&
	d4 = 20;
	std::cout << "y[0]:" << y[0] << str::endl;

}
#endif
#if 0 //037
#include<iostream>
int foo(int a, double d)
{
	std::cout << "foo" << std::endl;
	return 0;
}
int main()
{
	foo(1, 2);
	decltype(foo) d1;//함수 타입 int(int,double)
	decltype(&foo)d2;//함수 포인터 타입 int(*)(int, doubleg)
	decltype(foo(1, 3.1))d3; //함수 반환 타입 int 컴파일 타입에 결정
	d2 = foo;
	d2(1, 3.1);

	std::cout << typeid(d1).name() << std::endl;
	std::cout << typeid(d2).name() << std::endl;
	std::cout << typeid(d3).name() << std::endl;
}
#endif
#if 0 //038
/*
typedef int DWORD;
typedef int (*F)(int, int);*/

using DWORD = int;
using F = void(*)(int, int);
int main()
{
	DWORD n; //int n
	F f; //void(*f)(int,int)
}
#endif
#if 0 //038(2)
#include<cstdio>
//#define c1 10;
void doo(const int am)
{
	printf("a: %d\n");
}
int main()
{

	const int c1 = 10;
	int* p = (int*)&c1;
	//c1 = 20;
	printf("c1: %d,*p1: %d\n", c1, *p);
	*p = 30;
	printf("c1: %d,*p1: %d\n", c1, *p);
	const int c2 = c1;
	foo(c2);
	constexpr int c2 = 0;
}
#endif
#if 0 //039
#include<iostream>

void foo(const int s)
{
	//int arr[s];
}
int main()
{
	int arr1[10];
	const int s1 = 10;//컴파일 타임
	int arr2[s1];
	int s2;
	const int s3 = s2;//런타임.
}
#endif
#if 0 //040
/*
1.const
	==> 컴파일 시간 상수 와 실행시간 상수를 모두 만들 수 있다.
	==> 변수 값으로 초기화 할 수 있다.
2. constexpr 
	==> 컴파일 시간 상수만 만들 수 있다.
	==> 컴파일 시간에 계산 될 수 있는 값 으로만 초기화 가능
	==> 템플릿 인자로 사용 될 수 있다.
*/
#include<iostream>

int main()
{
	int n = 10;
	const int c1 = 10;	//compile time
	const int c2 = n;	//run time

	constexpr int c3 = c1;
	constexpr int c4 = c2;	//error
}
#endif
#if 0 //041
//structed binding 개념, 사용법
/*
1. 구조체 또는 배열에서 각 멤버의 값을 꺼낼 때 사용
2. 타입은 반드시 auto 사용
*/
#include<iostream>
struct Point
{
	int x{ 10 };
	int y{ 20 };
};
int main()
{
	Point pt;

	//int x = pt.x;
	//int y = pt.y;
	auto [x, y] = pt;//C++17부터 사용가능
	std::cout << "x:" << x << "," << "y:" << y << std::endl;
	//int x = 30;
	auto& [c, d] = pt;
	std::cout << "c:" << c << "," << "d:" << d << std::endl;
	pt.x = 1;
	pt.y = 2;
	std::cout << "c:" << c << "," << "d:" << d << std::endl;

}
#endif
#if 0 //042
//C++에서 문자열 처리하는 방법
//std::string 사용법
#include<iostream>
#include<cstring>

int main()
{
	char s1[32] = "hellow";
	const char* s2 = "world";

	//s1 = s2; //대입 사용 불가능 직관적이지 않다.
	strcpy_s(s1, s2);

	//if (s1==s2){} //비교 불가능
	if (strcmp(s1, s2) == 0) {}
	//이 소스를 cpp룔으로 바꾸어 보자.
}
#endif
#if 0 //042(2)
//C++에서 문자열 처리하는 방법
//std::string 사용법
#include<iostream>
#include<string>

int main()
{
	//char s1[32] = "hellow";
	//const char* s2 = "world";
	std::string s1 = "hello";
	std::string s2 = "world";

	//s1 = s2; //대입 사용 불가능 직관적이지 않다.
	//strcpy_s(s1, s2);
	s1 = s2;

	//if (s1==s2){} //비교 불가능
	//if (strcmp(s1, s2) == 0) {}
	if (s1 == s2)
	{
		std::cout << "same"<<std::endl;
	}
	std::string s3 = s1 + s2;
	std::cout << s3 << std::endl;
	//이 소스를 cpp룔으로 바꾸어 보자.	
}
#endif
#if 0 //043
#include<iostream>
#include<cstring>
void foo(const char* s)
{
	printf("foo: %s\n", s);
}
int main()
{
	std::string s = "hello";
	//foo(s); //error
	//foo((const char*)s);//error
	foo(s.c_str());
}
#endif
#if 0 //044
//함수 오버로딩(function overloading)
/*
1. C 언어에서는 "동일한 이름의 함수를 2개 이상 만들 수 없다."
2. C++ 언어에서는 "동일한 이름의 함수를 여러 개 만들 수 있다."
3. 함수 사용자 입장에서는 동일한 함수처럼 생각하게 되므로
일관된 형태의 라이브러리 를 구축할 수 없다.
4. C언어를 제외한 "대부분의 최신 언어들이 지원" 하는 특징
*/
int square(int a)
{
	return a * a;
}
int main()
{
	square(3);
	square(3.3);
}
#endif
#if 0 //044(2)
void f1(int a) {}
void f1(double a) {}
void f2(int a) {}
void f2(int a, int b) {}

void f3(int a) {}
void f3(int a, int b = 0) {}

int f4(int a) { return 0; }
double f4(int a) { return 0; }

int main()
{
	f1(3.4);
	f2(3,4);
	f3(3,4);
	f3(3);//error
	f4(10);
}
#endif
#if 0 // 045
//function template 의 개념
//template 의 원리 
/*
템플릿의 기본개념
1. 타입만 다르고 "구혀닝 동일하거나 유사한 함수"
가 여러개 있다면 개발자가 직접 만들지 말고, "컴파일러가 함수를 생성" 하게 하자.
2. 컴파일러가 함수를 생성할 때 사용할 "함수의 틀(template)"이 있어야 한다.
3. 개발자는 함수 템플릿을 만들고, 컴파일러가 템플릿을 사용해서 필요한 함수를 생성 하게 하자.
*/
int square(int a) { return a * a; }
double square(double a) { return a * a; }

template<typename T>		//template parameter //컴파일 시간에 전달
T square(T a)				//call parameter	//실행시간에 함수에 전달
{
	return a * a;
}
int main()
{
	square<int>(3);
	square<double>(3.3);
	square(7);
	square(4.4);
}
#endif
#if 0 // 045(2)
/*
클래스(구조체) 템플릿 
1. 함수 뿐 아니라 "클래스(구조체)도 템플릿" 으로 만들 수 있다.
2. "C++17" 부터는 생성자가 있으면 "템플릿 파라미터 전달을 생략" 할 수 있다.
*/
//struct Point
//{
//	int x;
//	int y;
//};
//struct Point
//{
//	double x;
//	double y;
//};
template<typename T>
struct Point
{
	T x;
	T y;
};
int main()
{
	Point<int> pt;
	Point<double> pt2;
}
#endif
#if 0 //046
//함수 삭제(delete function) C++11
/*
1. "함수를 삭제" 하는 방법
2. 삭제된 함수를 호출하면 "컴파일 시간에 오류" 발생
*/

void foo(int a) {}
void foo(int) = delete;
int main()
{
	foo(10);
}
#endif

#if 0 //046(2)
template<typename T>
T square(T a)
{
	return a * a;
}
int main()
{
	square(3);
	square(3.3);
	square('a');
}
#endif
#if 0 //046(3)
/*
후위 반환 타입 (trailing return type)
함수의 후위 반환 타입 표기법 C++11
1. 함수를 만들때 사용하는 "새로운 표기법"
	==> 함수의 "이름 앞에는 auto" 를 적고, 괄호 뒤에 
	"->반환 타입"을 적는 표기법
2. "trailing return type" 또는 "suffix return type" 
3. "C++11" 부터 지원
4. "람다 표현식" 이나 "함수 탬플릿" 을 만들때 주로 사용
*/
//int square(int a)
auto square(int a)->int
{
	return a * a;
}
//int main()
auto main()->int
{
	square(3);
}
#endif
#if 0 //047(3)
/*
후위 반환 타입 표기법이 필요한 경우
*/
//int add(int a, int b)
//{
//	return a + b;
//}
//double add(double a, double b)
//{
//	return a + b;
//}
//template<typename T>
//T add(T a, T b)
//{
//	return a + b;
//}
template<typename T1, typename T2>
//decltype(a+b) add(T a, T b)
//auto add(T1 a, T2 b)->decltype(a + b)//C++11
auto add(T1 a, T2 b)//C++14
{
	return a + b;
}
int main()
{
	int a = 10;
	double b = 20.0;
	//decltype(a+b) t;
	add(1, 5);
	add<double>(2.2, 5.6);
	add(2.2, 5.6);
	add(22, 5.6);
	add(2.2, 56);
}
#endif
#if 0 //048
//constexpr function
/*
"컴파일 시간의 의미" 가지는 키워드 --C++11 
1.constexpr 상수화
	컴파일 타임에 이어나냐 런타임에 일어나냐
	==> constexpr int c=10; 컴파일 시에 해라
	const int c=10;
	int n = 10; 
	const int k = n; //run time
2.constexpr function

3. if constxpr
*/
int add(int a, int b)
//constexpr int add(int a, int b)
{
	return a + b;
}
int main()
{
	int a = add(1, 2);
}
#endif
#if 0 //048(2)
/*
constexpr function
1. 함수의 인자 값을 컴파일 시간에 결정할 수 있으면 
"컴파일 시간에 함수를 실행"
2. 함수의 인자 값을 컴파일 시간에 결정할 수 없으면
"실행 시간에 함수를 실행"

template parameter
1. 템플릿 인자로 타입 뿐 아니라 :정수형 상수" 도 사용할 수 있다.
	==>템플릿은 컴파일 시간에 결정된다. 그러므로 컴파일 시간에
	정수값을 알아야 한다.
2. 모든 템플릿 인자는 "컴파일 시간에 결정" 되어야 한다.
*/
#define MAX 40
constexpr int add(int a, int b)
{
	return a + b;
}
template<typename T, int n>
struct Buffer
{
	T data[n];
};
int main()
{
	int x = 1;
	int y = 2;
	int n1 = add(1, 1);
	int n2 = add(x, y);
	Buffer<int, 1024>b1;//1024는 컴파일 타임때 이미 알기 때문에 됨.
	Buffer<int, x>b2;//x는 runtime 때 알기때문에 오류가 남. 
	Buffer<int, add(1,3)>b3;//add 함수가 constexpr 해놔서 됨.
	Buffer<int, add(1,MAX)>b3;//add 함수가 constexpr 해놔서 됨.
}
#endif
#if 0 //049
//constexpr function의 제약조건
/*
1. C++11에서는 constexpr 함수가 컴파일 시간에 수행되기 위해
"제약 조건을 많이 가지고 있었다."
	==>return 문장이 한번만 나와야 한다.
2. C++14 에서는 "대부분 제약이 사라지고 일부 조건" 만 남아있다.
	==>"파일을 오픈" 하거나 "동적으로 메모리를 할당" 을 할 수 없다.
	==>가상함수가 될 수 없다.
*/
#include<iostream>
constexpr int factorial(int n)
{
	char* s = new char;
	if (n == 1)
		return 1;
	return n * factorial(n - 1);
}
int main()
{
	int x;
	std::cin >> x;
	int n = factorial(x);
	std::cout << n << std::endl;
}
#endif
#if 0 //050 lambda 람다 
/*
람다 표현식의 개념
1. 일반적인 함수
	==>global space에 만들어 놓고 필요할때
	"함수의 이름을 사용해서 호출"한다.
2. 람다 표현식(lambda expression)
	==>코드 안에서 "이름이 없는 함수를 만들어서 사용" 하는것
	==>"익명의 함수(annonymous function)", "함수 리터럴(literal)"
	==>"함수 반환타입과 이름을 제거" 하고 "[]"를 표기한다.
*/
#include<iostream>
void foo(int a)
{
	std::cout << "foo:" << a << std::endl;
}
int main()
{
	foo(1); //함수이름(함수인자);함수호출

	[](int a)
	{
		std::cout << "foo:" << a << std::endl;
	}(5);
}
#endif
#if 0 //050(2)
/*
1. "[]"
	==>lambda introducer
	==>람다표현식이 시작됨을 나타낸다.
*/
#include<iostream>
int add(int a, int b) { return a + b; }
int main()
{
	int n1 = add(1, 2);
	//[](int a, int b) {return a + b; };//람다표현식 함수 생성
	int n2 = [](int a, int b) {return a + b; }(1, 2);//람다 함수 호출
	std::cout << n1 << "," << n2 << std::endl;
}
#endif
#if 0 //050(3)
#include<iostream>
#include<algorithm>
bool cmp(int a, int b) { return a > b; }
int main()
{
	int x[10] = { 1,9,6,3,7,4,5,2,3,10 };
	//std::sort(x, x + 10);
	//std::sort(x, x + 10, cmp);
	std::sort(x, x + 10, [](int a, int b) { return a > b; });
	for (int i = 0; i < 10; i++)
	{
		std::cout << x[i] << ",";
	}
}
#endif
#if 0 //051
#include<iostream>
int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	/*for (int i = 0; i < 10; i++)
	{
		std::cout << x[i]<<", ";
	}*/
	for (auto n : x)
	{
		std::cout << n << ", ";
	}
}
#endif
#if 0 //052
/*
if init,switch init
if constexpr
	==>C++17
*/
#include<iostream>
int foo() { return -1; }
int goo() { return 10; }
int main()
{
	int ret;

	/*ret = foo();
	if (ret == -1)
	{
		printf("Error occurred\n");
	}
	return 0;*/

	if (int ret = foo(); ret == -1)
	{
		printf("Error Occurred\n");
	}
	int n;
	n = goo();
	//switch (n)
	switch (int n = goo();n)
	{
	case 10:
		printf("value:10\n");
		break;
	case 20:
		printf("value:20\n");
		break;
	}
	return 0;
}
#endif
#if 0 //053
//if_constexpr
/*
1.if
==>"실행시간"에 조건식을 조사
2. if constexpr
==>컴파일 시간 에 조건식을 조사
==>조건식은 반드시 컴파일 시간에 값을 결정 할수 있어야 한다.
==>static if 라고도 불리는 문법
3.C++17 부터 지원하는 문법

4.템플릿을 만들때 주로 사용
*/
int main()
{
	int k = 30;
	const int n = 0;
	if (n == 0) {}

	if constexpr (n == 0) {}//error n이 const 면 해결!
	if constexpr (sizeof(n) == 0) {}//error
}
#endif
#if 0 //054
template<typename T>
void foo(T a)
{
	if constexpr(0)
	//if (0)
	{
		*a = 0;
	}
}
int main()
{
	int n = 0;
	foo(&n);//T : int*
	foo(n); //T : int
}
#endif
#if 0 //055
/*
1.변수
==>메모리의 특정 위치를 가리키는 이름
==>코드 안에서 해당 메모리에 접근하기 위해서 사용
2.레퍼런스
==>
*/
#include<iostream>
int main()
{
	int n = 10;
	int& r = n;

	std::cout << n << std::endl;
	std::cout << r << std::endl;
	std::cout << &n << std::endl;
	std::cout << &r << std::endl;
}
#endif
#if 0 //056
#include<iostream>

void f1(int n) { ++n; }
void f2(int *p) { ++(*p); }
void f3(int &r) { ++r; }
int foo(int a) { std::cout << "foo()" << std::endl;
				return a; }
int* hoo()
{
	static int a;
	std::cout << "hoo a:" << a<<std::endl;
	return &a;
}
int& bar()
{
	static int a;
	std::cout << "bar a:" << a <<std::endl;
	return a;
}
int main()
{
	int a = 0, b = 0, c = 0;
	f1(a);	//call by vlaue
	f2(&b);	//call by address
	f3(c);	//call by reference
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	int array[3][3];
	int (&a_r)[3][3] = array;
	int cnt = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			array[i][j] = ++cnt;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			std::cout << "a_r[" << i << "]" << "[" << j << "]= " << a_r[i][j] \
			<< std::endl;
	//int foo(int a);
	//int(&f_r)(int) = foo;
	int(&f_r)(int) = foo;
	f_r(3);

	//int(&f_r)(int) = [](int a)
	//{
	//	std::cout << "foo()" << std::endl;
	//	return a;
	//};//람다함수는 레퍼런스가 안된다?

	*hoo() = 20;
	bar() = 30;
	hoo();
	bar();

}
#endif
#if 0 //057
//const_reference
/*
1. call by value의 특징
==>인자로 전달된 객체의 "복사본이 생성"된다
==>원본 객체를 변경할 수 없다. "안전" 하다
==>하지만 "복사본에 대한 오버헤드"가 있다.
2. const reference의 장점
==>인자에 대한 복사본을 만들지 않는다.
==>원본 객체를 변경할 수 없다.
==>복사 생성자와 소멸자가 호출되지 않는다.
*/
#include<iostream>
struct Date
{
	int year;
	int month;
	int day;
};
void foo(const Date& d)
{
	//d.year = 1000;
}
int main()
{
	Date date = { 2020,3,28 };
	foo(date);
	std::cout << date.year << std::endl;
}
#endif
#if 0 //057(2)
/*
1. 함수 안에서 인자의 값을 변경하고 싶다면
==>포인터 또는 레퍼런스를 사용해서 전달.
2. 함수 안에서 인자의 값을 변경하지 못하게 하려면
	primitive type(built-in)	:call by value
	user define type			:const reference
*/
#include<iostream>
void foo(int x)//call by value
//void foo(const int& x)
{

}
int main()
{
	int n = 10;
	foo(n);
	std::cout << n << std::endl;
}
#endif
#if 0 //058(-1)
#include<stdio.h>
int foo()
{
	static int a = 10;
	return a;
}
int main()
{
	int k = foo();
	//foo() = 20;//r-value는 공간이 없기때문에 넣을수 없음.(10에다 20을 어케넣나!)
	printf("k: %d\n", k);
}
#endif
#if 0//058
/*
1. 함수 인자 
call by value	:복사본 생성.
call by reference : 복사본 생성안함.

2. 함수 반환 값
리턴용 임시 객체 생성
return by value	:복사본 생성
return by reference :복사본을 생성하지 않음.
*/
#include<iostream>
struct Point
{
	int x;
	int y;
};
Point pt = { 0,0 };
Point foo() { return pt; }//복사본 생성
Point& goo() { return pt; }//복사본 생성 안함.
int& f()
{
	int n = 10;
	return n;
}
int& g()
{
	int n = 20;
	return n;
}
int main()
{
	//foo().x = 10;//값으로 와서 10을 못넣음.
	goo().x = 20;
	int& r = f();

	//std::cout << foo().x << std::endl;
	std::cout << r << std::endl;
	g();
	std::cout << r << std::endl;
}
#endif
#if 0 //059
/*
1.l-value 와 r-vlaue 
r-value : 등호(=)의 오른쪽에만 올 수 있다.
l-value : 등호(=)의 오른쪽과 왼쪽 모두 올 수 있다.

2. reference 규칙
l-value reference : l-value 만 가리킬 수 있다.
const l-value reference : l-value 와 r-value 모두 가리킬 수 있따.
r-value reference : r-value 만 가리킬 수 있다. -- C++11에서 추가

*/
#include<iostream>
int main()
{
	int v1 = 0, v2 = 0;
	v1 = 10; //ok 10: r-value
	10 = v1; //error v1: l-value
	v2 = v1;

	int& r1 = v1;//ok
	int& r2 = 10;//error  10 is r-value

	const int& r3 = v1;//ok
	const int& r4 = 10;//ok

	int&& r5 = v1; //error r-value 레퍼런스는 l-value를 헤퍼런스 할 수 없다.
	int&& r6 = 10; //ok		r-value 레퍼런스는 r-value 만을 레퍼런스 할 수 있다.

}
#endif
#if 0 //060
//C방식 캐스팅의 단점
//C++ Explicit Casting(명시적 캐스팅)
/*
1. C언어와 C++언어의 문법의 차이점
	C언어 :void* ==> 다른 타입*의 암시적 형변환 허용
	C++	 :void* ==> 다른 타입*의 암시적 형변환 허용 안됨.
2. C언어와 C++언어의 캐스팅 방법
	C언어 int* p1 = (int*)malloc(sizeof(int) * 10);
	C++	 int* p1 = static_cast<int*>(malloc(sizeof(int) * 10));
3. 왜 새로운 캐스팅이 필요한가?\
==> C의 캐스팅은 논리적이지 않고, 위험하고, 버그의 가능성이 높다.
*/
#include<iostream>
#include<cstdio>
int main()
{
	//int* p1 = (int*)malloc(sizeof(int) * 10);
	int* p1 = static_cast<int*>(malloc(sizeof(int) * 10));
	free(p1);
}
#endif
#if 0 //061
#include<iostream>
int main()
{
	int n = 0;
	double* p1 = (double*)&n; //error
	*p1 = 3.4; //runtime error

	const int c = 10;
	//int* p2 = &c; //error
	int* p2 = (int*)&c; //ok
	*p2 = 25;
	std::cout << "c:" << c << "*p2:" << *p2 << std::endl;
}
#endif
#if 0 //062
//C에서는 (type *)
//static_cast
//reinterpret_cast
//comst_cast
//dynamic_cast
/*
-----------------가장 기본적인 캐스팅 연산자----------------- 
static_cast		정수와 실수 사이의 변환, 열거형과 정수 사이 변환 
				void*==>다른 타입*변환					  
				배열=>포인터, 함수=>함수 포인터 등.			 
				----------------------------------------- 
				상수성을 제거하거나 서로 다른 타입의 포인터끼리	
				변환은 허용하지 않음							
--------------------------------------------------------- 
reinterpret_cast	서로 다른 포인터 타입 끼리의 변환			
					정수와 포인터 사이의 변환				  
--------------------------------------------------------- 
const_cast		포인터와 참조형의 상수성(const)과					  
				volatile속성을 제거하는데 사용			     
--------------------------------------------------------- 
dynamic_cast	안전한 다운 캐스팅(클래스 포인터를 안전하게 파생
				클래스 타입의 포인터로 캐스팅할 때 사용)		  
				실행시간 캐스팅							 
--------------------------------------------------------- 
*/
#include<iostream>
void foo(int){}
int main()
{
	const int c = 10;
	int i = 10;
	double d = 3.4;
	int n = static_cast<int>(d);
	auto p2 = static_cast<void(*)(int)>(foo);

	int* p3 = static_cast<int*>(&d);
	int* p4 = static_cast<int*>(&i);
	int* p5 = static_cast<int*>(&c);//const는 이걸로 캐스팅이 안된다.
}
#endif
#if 0 //061(2)
//reinterpret
/*
1. reinterpreter_cast
	==>서로 다른 타입의 포인터 사이의 변환
	==>정수와 포인터 사이의 변환
*/

int main()
{
	int n = 10;
	double* p1 = reinterpret_cast<double*>(&n);

	int* p2 = reinterpret_cast<int*>(10);
}
#endif
#if 0 //062(3)
//const_cast
/*
1. const_cast
	=>포인터 변수와 참조 변수 사이의 상수성(const)와 volatile
	속성을 제거하기 위해 캐스팅
*/
int main()
{
	const int c = 10;
	volatile int v = 20;//항상 메모리를 접근해서 값 가져오는거.
	int* p = &c; //error
	int* p1 = const_cast<int*>(&c);//상수성 제거
	int* p2 = &v; //error
	int* p2 = const_cast<int*>(&v); //volatile 제거

	double* p3 = const_cast<double*>(&c);//error type이 달라서
}
#endif
#if 0 //062(4)
//const int 형 변수의 주소를 char* 변수에 담아보자
int main()
{
	const int c = 10;

	char* p = static_cast<char*>(&c);//error
	char* p = const_cast<char*>(&c);//error
	int* p = const_cast<int*>(&c);
	char* p = reinterpret_cast<char*>(const_cast<int*>(&c));
	char* p2 = (char*)&c;
}
#endif
#if 0 //062(5)
#include<cstdlib>
int main()
{
	int* p1 = (int*)malloc(sizeof(int) * 10);
	int* p1 = static_cast<int*>(malloc(sizeof(int) * 10));
	free(p1);

	int* p2 = new int;
	delete p2;

	int* p3 = new int[10];
	delete[]p3;

	int* p4 = new int[10][2];
	int(*p4)[2] = new int[10][2];
	int* p4 = reinterpret_cast<int*>(new int[10][2]);
	delete[]p4;
}
#endif
#if 0 //063
/*
nullptr
1.C++11 부터 도입된 새로운 키워드(keyword)
2.널 포인터값(null pointer value)을 나타내는 "포인터 리터럴(pointer literal)"
3.포인터 변수를 초기화 하기 위해 기존의 방식대로 "0을 사용해도 되지만
nullptr를 사용하는것" 이 안전하고 코드의 가독성을 높일 수 있다.
*/
int main()
{
	int* p1 = 0;
	int* p2 = nullptr;
}
#endif
#if 0 //063(2)
/*
1.0은 정수,실수,bool,포인터 등의 변수를 초기화 할 때 사용가능.
2.0은 정수형 literal 이고 int 타입
	=>0은 int 타입이지만, 실수,bool,포인터 타입으로
	암시적 형 변환될 수 있다.
*/
#include<iostream>
using namespace std;
void foo(int n) { cout << "int" << endl; }
void foo(double b) { cout << "double" << endl; }
void foo(bool d) { cout << "bool" << endl; }
void foo(char* s) { cout << "char" << endl; }
void foo2(double* t) { cout << "double*" << endl; }
int main()
{
	int n = 0;
	double b = 0;
	bool d = 0;
	char* s = 0;
	double* t = 0;
	foo(0);
	foo(0.0);
	foo(false);
	foo((char*)0);
	foo(nullptr);//포인터 값에 들어가서 char* 에 들어가는듯
}
#endif
#if 0 //063(3)
#include<iostream>
int* foo() { return 0; }
int main()
{
	auto ret = foo();

	//if (ret == 0)//ret가 포인터 값인지 정수 값인지 알 수가 없다.
	if(ret==nullptr)// 포인터 값이라면 처음부터 nullptr 로 하면 좋을듯.
	{

	}
}
#endif
#if 0 //063(4)
//nullptr과 데이터 타입
/*
1.nullptr 은 "std::nullptr_t"타입
2.std::nullptr_t 타입은 모든 타입의 포인터로 암시적 변환 된다.
3.std::nullptr_t 타입은 int 타입으로 변환 될 수 없다.
4.srd::nullptr_t 타입은 bool 타입으로 직접 초기화(direc initialization)시
초기화 값으로 사용이 가능하다.
*/
#include<iostream>
int main()
{
	0;//int
	0.0;//double
	nullptr; //std::nullptr_t 포인터 타입이 아닌데 포인터의 초기화 값으로 사용되고 있다.
	int* p1 = nullptr;
	void(*f)() = nullptr;
	int n1 = nullptr;
	int n2 = 0;

	bool b1 = nullptr;//직접초기화가 아님
	bool b2(nullptr);
	bool b3{ nullptr };
	bool b4={nullptr};//직접초기화가 아님
}
#endif
#if 0 //063(5)
#include<iostream>
using namespace std;
void foo(int n) { cout << "int" << endl; }
void foo(void* n) { cout << "void*" << endl; }
void goo(char* n) { cout << "goo" << endl; }
#ifdef __cplusplus
	#define NULL 0 //c++에서는 0이 여러 타입으로 자동으로 변환댐
#else
	#define NULL (void*)0
#endif
#define DDD 10
#ifdef DDD
	#define DD 20
#else
	#define DD 30
#endif

int main()
{
	foo(0); //int
	foo((void*)0); //void*
	foo(NULL);
	goo(NULL);
	printf("%d", DD);
}
#endif
#if 0 //064
/*
1.현실세계에 존재하는 것들
	복소수 --> double 형 변수 2개
	날짜	  --> int형 변수 3개
	사람   --> char* name; int age;

2. Complex, Date, Person 이라는 타입이 있다면 편리하지않을까?
=>C언어의 구조체를 사용하면 새로운 타입을 만들 수 있다.
*/
#include<stdio.h>
void add(double ar, double ai, double br, double bi, //in parameter
	double*sr,double *si)  //out parameter
{
	//double sr = ar + br;
	//double si = ai + bi;
	*sr = ar + br;
	*si = ai + bi;
}
int main()
{
	double xr = 1, xi = 1; //1+1i;
	double yr = 2, yi = 2; //2+2i;
	double sr, si;
	add(xr, xi, yr, yi,&sr, &si);
}
#endif
#if 0 //064(2)
/*
1. 프로그램에서 필요한 타입을 먼저 설계한다.
2. 현실세계에 존재하는 사물은 상태와 동작이 있다.
			상태			동작
자동차		색상,속도		달린다,멈춘다
사람			나이,몸무게	웃는다,운다
복소수		실수,허수		더하기,절대값 구하기

3. 타입을 설계할 때.
=>상태와 동작을 표현할 수 있어야한다.
=>상태는 변수로 동작은 함수로 표현된다.

4. C의 구조체와 C++의 구조체
=> C: 데이터만 포함 할 수 있다.
=> C++: 데이터 뿐 아니라 함수도 포함할 수 있다. 
*/
struct Complex
{
	double real;
	double image;
};
Complex add(Complex c1, Complex c2)
{
	Complex temp;
	temp.real = c1.real + c2.real;
	temp.image = c1.image + c2.image;
	return temp;
}
int main()
{
	Complex c1 = { 1,1 }; //1+1i
	Complex c2 = { 2,2 }; //2+2i

	Complex ret = add(c1, c2);
}
#endif
#if 0 //064(3)
#include<iostream>
int buf[10];
int idx = 0;
//void push(int* buf, int* idx, int value)
//{
//	buf[(*idx)++] = value;
//}
//int pop(int* buf, int* idx)
//{
//	return buf[--(*idx)];
//}
//struct Stack
//{
//	int buf[10];
//	int idx;
//};
//void push(Stack* s, int value)
//{
//	s->buf[s->idx++] = value;
//}
//int pop(Stack* s)
//{
//	return s->buf[--(s->idx)];
//}
struct Stack
{
private:
	//int buf[10];
	int* buf;
	int idx;
public:
	//void init() { idx = 0; }
	Stack(int size = 10) {
		idx = 0;
		buf = new int[size];
	}
	~Stack() { delete[] buf; }
	void push(int value){buf[idx++] = value;}
	int pop(){return buf[--(idx)];}
};
int main()
{
	Stack s1(30);
	Stack s2;
	//s1.idx = 0;
	//s2.idx = 0;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	//int buf1[10];
	//int idx1 = 0;
	/*push(10);
	push(20);
	push(30);*/
	/*push(buf1, &idx1, 10);
	push(buf1, &idx1, 20);
	push(buf1, &idx1, 30);*/
	

	std::cout << s1.pop() << std::endl;
	std::cout << s1.pop() << std::endl;

	//int n1 = pop(&s1);
	
}
#endif
#if 0 //064(4)
#include"Stack.h"
#include<iostream>

int main()
{
	Stack s1(30);
	Stack s2(10);	
	s1.push(10);
	s1.push(20);
	s1.push(30);

	std::cout << s1.pop() << std::endl;
	std::cout << s1.pop() << std::endl;
}
#endif
#if 0 //064(5)
#include<iostream>
int buf[10];
int idx = 0;
template<typename T>
struct Stack
{
private:
	T* buf;
	int idx;
public:
	Stack(int size = 10) {
		idx = 0;
		buf = new T[size];
	}
	~Stack() { delete[] buf; }
	void push(T value) { buf[idx++] = value; }
	T pop() { return buf[--(idx)]; }
};
int main()
{
	Stack<int> s1(30);
	Stack<double> s2;

	s1.push(10);
	s1.push(20);
	s1.push(30);

	std::cout << s1.pop() << std::endl;
	std::cout << s1.pop() << std::endl;
}
#endif	
#if 0 //065
//변수와 객체(variable vs object)
/*
1. 변수(variable)
	=>변하는 수
	=>메모리의 특정 위치를 가리키는 이름
	=>변수를 사용하면 메모리의 값을 읽거나 쓸 수 있다.
	=>언어가 제공하는 기본 타입(primitive type)의 인스턴스
2. 객체(object)
	=>메모리를 할당하고 자신을 스스로 초기화 한다.
	=>상태와 동작을 가지고 있는 존재
	=>객체를 사용하면 해당 객체가 제공하는 다양한 서비스를 사용 할 수 있다.
	=>사용자 정의 타입(user define type)으로 만든 변수

프로그래밍 패러다임(paradigm)
프로그램이란 무엇인가?
1.명령형(절차적) 프로그래밍 패러다임(C언어)
	=>프로그램은 컴퓨터가 수행할 명령어들의 나열이다.
	=>모든 프로그램은 main 함수부터 순차적으로 실행된다
	=>제어문, 반복문, 함수 등을 사용해서 실행흐름을 변경할수 있다.

2. 객체지향 프로그래밍 패러다임(C++, JAVA, Python...)
	=>프로그램은 객체들과 객체들 사이의 메시지 이다.
	=>문제를 해결하기 위해 필요한 타입을 찾아내고 설계 한 후
	객체를 생성하고, 객체끼리 메시지를 주고 받으면서 문제를 해결 하는 것.

C++과 프로그래밍 패러다임
1. C++은 다중 패러다임(Multi Paradigm) 언어다.
	=>명령형(절차적) 프로그래밍 패러다임 지원
	=>객체 지향 프로그래밍 패러다임 지원
	=>일반화 프로그래밍 패러다임 지원
	=>함수형 프로그래밍 패러다임 지원
*/
#endif
#if 0 //065(2)
#include<iostream>
#include<stack>

int main()
{
	std::stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);

	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
}
#endif
#if 0 //066
#include<iostream>
#include<vector>
#include<list>
int main()
{
	//int x[10]={1,2,3,4,5,6,7,8,9,10}
	//std::vector<int>x;
	//std::vector<int> x(10);
	std::list<int> x = { 1,2,3,4,5,6,7,8,9,10 };
	//x[0] = 10;
	//x.resize(20);
	//for (int i = 0; i < x.size(); i++)
	//	std::cout << x[i] << std::endl;
	for (auto n : x)
		std::cout << n << std::endl;
}
#endif
#if 0 //066(2)
//friend 함수
/*
1. friend 함수 
	=>멤버 함수는 아니지만 private 멤버에 접근 할 수 있게 하고 싶을 때.
2.왜 멤버 함수로 만들지 않았는가?
	=>멤버 함수로 만들 수 없는 경우가 있다.(연산자 재정의)
	Point a,b,c;
	int i=10;
	c=a+b; a.operator+(b)
	c=i+a; operator+(i,a);//friend 함수가 필요하다
*/
#include<iostream>
class Airplane
{
	int color;
	int speed;
	int engineTemp;

public:
	int getSpeed() { return speed; }
	friend void fixAirplane(Airplane& a);
//	int getengineTemp() { return engineTemp; }
};
void fixAirplane(Airplane& a)
{
	int n = a.engineTemp;
}
int main()
{
	Airplane a;
	//a.color = 1;
	fixAirplane(a);
}
#endif
#if 0 //066(3)
/*

*/
#include<iostream>
using namespace std;
class Point
{
	int x, y;
public:
	Point() { x = 0; y = 0; cout << "1" << endl; }
	Point(int a, int b) { x = a; y = b; cout << "2" << endl; }
};
int main()
{
	//Point p1(1, 2);		//2
	//Point p2{ 1, 2 };		//2,C++직접초기화
	//Point p3 = { 1, 2 };	//2,	복사초기화

	//Point p4;		//1
	//Point p5();		//객체생성 아님, 함수 선언문
	//Point p6{};		//1
	//Point p7 = {};	//1

	//Point p8[3];
	//Point p9[3] = { Point(1,1), };
	//Point p10[3] = { {1,1},{2,2} };
	
	Point* p11;

	p11 = static_cast<Point*>(malloc(sizeof(Point)));
	free(p11);
	p11 = new Point;
	delete p11;

	p11 = new Point(1, 2);
	delete p11;
}
#endif
#if 0 //066(4)
#include<iostream>
using namespace std;
class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};
class Rect
{
	Point p1;
	Point p2;
public:
	Rect(){ cout << "Rect()" << endl; }
	~Rect() { cout << "Point()" << endl; }
};
int main()
{
	Rect r;
}
#endif
#if 0 //067
/*
위임 생성자(delegate constructor)
*/
class Point
{
	int x, y;
public:
	Point() :Point(0, 0) {}
	//{x = 0; y = 0;}
	Point(int a, int b)
	{x = a; y = b;}
};
int main()
{
	Point p1;
	Point p2(1, 2);
}
#endif
#if 0 //067(2)
/*
default constructor
1. Point() =default;
	=>컴파일러에게 디폴트 생성자를 만들어 달라고 하는 문법
	=>클래스 선언부만 표기하면 되고 구현부는 만들지 않아도 된다.

constructor delete
2. Point()=delete;
	=>인자 없는 객체를 만들지 못하게 할 때 사용
*/
class Point
{
	int x, y;
public:
	Point() = default;
	//Point() =delete;
	Point(int a, int b)	{}
};
int main()
{
	Point p1;
	Point p2(1, 2);
}
#endif
#if 0 //068
/*
소멸자(destructor)
1. 소멸자 모양
	=> ~클래스이름()
	=>리턴 타입을 표기하지 않는다.
	=>인자를 가질 수 없다. -한개만 만들수 있다.

2. 특징
	=>객체를 생성하면 생성자가 호출되고
	=>객체가 파괴되면 소멸자가 호출된다.
3. 소멸자를 만들지 않으면
	=>컴파일러가 소멸자를 제공해준다.

4. 소멸자가 필요한 경우
	=>생성자 등에서 자원을 할당한 경우, 소멸자에서 자원을 해지 해야한다.
	=>자원해지등이 필요 없는 경우 소멸자를 만들 필요는 없다.
*/
#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	FILE* f = fopen("D:\\C_code\\a.txt", "wt");

	fputs("hi", f);
	fclose(f);
}
#endif
#if 0 //068(2)
#include<iostream>
#include<cstdio>
#include<string>
#pragma warning(disable:4996)
class File
{
	FILE* file = 0;
public:
	File(std::string filename, std::string mode)
	{
		file = fopen(filename.c_str(), mode.c_str());
	}
	//RW 함수들 정의
	void puts(std::string s)
	{
		fputs(s.c_str(), file);
	}
	~File()
	{
		fclose(file);
	}
};
int main()
{
	//std::string test = "skywalk";
	File f("D:\\C_code\\a.txt", "wt");
	f.puts("hello~~~skywalker");
}
#endif
#if 0 //069
/*
-member initializer list
*/
#include<iostream>
class Point
{
	int x; int y;
	const int cval;
	int& r;
public:
	Point(int a, int b,int val,int c):cval(val),r(c)
	{
		x = a; y = b;
		//cval = val;
	}
};
int main()
{
	int i = 10;
	Point p(1, 2, 3, i);
	int a = 0;
	int b;
	b = 0;
	int& r = a;
}
#endif
#if 0 //070
/*
반드시 멤버 초기화 리스트를 사용해야 하는 경우
1. 클래스 안에 멤버 데이터가 const 또는 reference 로 되어 있을 때.
2. 클래스 안에 디폴트 생성자가 없는 타입이 멤버 데이터로 있을 때.
*/
class Point
{
	int x;
	int y;
public:
	//Point() {}
	Point(int a, int b) :x(a), y(b) {}
};

class Rect
{
	Point p1;
	Point p2;
public:
	Rect(int a, int b, int c, int d):p1(a,b),p2(c,d) //여기서 초기화하면 객체생성
	{
		//p1(a, b); //여기선 함수호출
	}
};
int main()
{
	Rect r(1, 2, 3, 4);		//p1 Point 생성자 호출
	Point p1(1,2);			//p2 Point 생성자 호출
							//Rect 생성자 호출
}
#endif
#if 0 //071
/*

*/
#include<iostream>
class Point
{
public:
	int y;int x;// 선언된 순서대로 되기때문에 됨. 순서를 x y 순으로 하면 안됨.
public:
	Point() :y(0), x(y) {}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;
}
#endif
#if 0 //072
/*
멤버 데이터를 초기화하는 3가지 방법
1. member field initialization
	=>생성자로 전달된 값을 사용할 수 없다.
2. member initializer list
3. 생성자 블록 안에서 초기화
	=>초기화가 아닌 대입.

클래스를 선언과 구현으로 분리하는 경우
	=>초기화 리스트는 구현부에 작성한다.
*/
#include<iostream>
class Point
{
public:
	int x = 0;//C++11 //1. member field initialization
	int y = 0;
public:
	Point(int a,int b):x(a),y(b) //2. member initializer list
	{
		x = a; y = b;//3. 생성자 블록 안에서 초기화
	}
};
int main()
{	
}
#endif
#if 0 //073
/*
직접 초기화 vs 복사 초기화
1. 직접초기화(direct initailization): = 없이 초기화 하는 것
	OFile f1("a.txt")
2. 복사 초기화(copy initailization): = 를 사용해서 초기화 하는 것
	OGile f2="a.txt"

함수 인자 전달과 초기화 방법
1. 함수 인자 전달 시 복사초기화를 사용한다.
2. 특정 클래스 설계시 복사 초기화를 사용하지 못하게 하는것이 좋을 때가 있다.
*/
#pragma warning(disable:4996)
#include<iostream>
class OFile
{
	FILE* file;
public:
	OFile(const char* filename)
	{
		file = fopen(filename, "wt");
	}
	~OFile() { fclose(file); }
};
void foo(OFile f) {}
int main()
{
	OFile f1("D:\\C_code\\b.txt");  //직접 초기화
	OFile f2 = "D:\\C_code\\b2.txt";	//복사 초기화

	foo(f1);
	foo("D:\\C_code\\hellllo.txt");
}
#endif
#if 0 //073(2)
/*
explicit 생성자
1. 객체를 초기화 할 때 직접 초기화만 사용할 수 있고,
복사 초기화는 사용할 수 없게 함.
2. OFile 의 생성자가 explicit 이고, foo함수가 OFile을 인자로 가지는 경우
	OFile f1("a.txt");	//OK
	OFile f1="a.txt";	//ERROR
	foo(f1);			//OK
	foo("hello.txt");	//ERROR
*/
#include<iostream>
#pragma warning(disable:4996)
class OFile
{
	FILE* file;
public:
	explicit OFile(const char* filename)
	{
		file = fopen(filename, "wt");
	}
	~OFile() { fclose(file); }
};
void foo(OFile f) {}
int main()
{
	OFile f1("D:\\C_code\\b.txt");  //직접 초기화
	OFile f2 = "D:\\C_code\\b2.txt";	//복사 초기화

	foo(f1);
	foo("D:\\C_code\\hellllo.txt");
}
#endif
#if 0 //074
//C++ 표준 라이브러리와 explicit 생성자
#include<string>
#include<vector>
#include<iostream>
int main()
{
	std::string s1("hello");
	std::string s2 = "heellow";

	std::vector<int> v1(10);
	std::vector<int> v2=10;
	std::vector<int> v43 = { 10 }; //다른 생성자가 호출된다.

	//C++ 표준 스마트 포인더
	std::shared_ptr<int> p1(new int);
	std::shared_ptr<int> p2 = new int;
}
#endif
#if 0 //074
/*
1. 복사 생성자랑?
	=> 자신과 동일한 타입 한개를 인자로 가지는 생성자
2. 사용자 복사 생성자를 만든지 않으면 
	=>컴파일러가 제공(복사생성자 자체를 만들지 않으면 만들어준다.)
	=>디폴트 복사 생성자(default copy constructor)
	=>모든 멤버를 복사(bitwise copy)한다.
*/
#include<iostream>
class Point
{
public:
	int x;
	int y;
	Point() :x(0), y(0) {}
	Point(int a, int b) :x(a), y(b) {}
	Point(const Point& p) :x(p.y), y(p.x)
	{
		std::cout << "copy ctor" << std::endl;
	}
};
int main()
{
	Point p1;
	Point p2(1, 2);
	//Point p3(1);
	Point p4(p2);

	std::cout << p4.x << std::endl;
	std::cout << p4.y << std::endl;
}
#endif
#if 0 //075
/*
//복사 생성자가 호출 되는 3가지 경우

1. 자신과 동일한 타입의 객체로 초기화 될 때.
	=>Point p2(p1);
	=>Point p2{2};
	=>Point p2 = p1; =>explicit 이 아닌 경우만
2. 함수 인자를 call by value 로 받을 경우
	=>함수 인자를 const reference 로 사용 하면 복사본을 만들지
	않으므로 복사 생성자가 호출되지 않는다.

3. 함수가 객체 값으로 변환 할 때.
	=>참조로 변환 하면 리턴 용 임시객체가 생성되지 않는다.
	=>단, 지역변수는 참조로 반환 하면 안된다.
*/
#include<iostream>
class Point
{
public:
	int x; int y;
	Point() {}
	Point(int a, int b) :x(a), y(b) 
	{
		std::cout << "ctor" << std::endl;
	}
	explicit Point(const Point& p) :x(p.x), y(p.y)
	{
		std::cout << "copy ctor" << std::endl;
	}
};
void foo(const Point& pt) {}
Point p;
Point& goo()
{
	return p;
}

int main()
{
	Point p1(1, 2);	//생성자
	Point p2(p1);	//
	Point p3{ p1 };
	Point p4 = { p1 };
	Point p5 = p1;
	foo(p1);
	goo();

	std::cout << p4.x << std::endl;
	std::cout << p4.y << std::endl;
}
#endif
#if 0 //076
/*
1. 객체가 자신의 동일한 타입의 객체로 초기화 될 때
	=>복사 생성자가 사용된다
	=>사용자가 만들지 않은 경우 디폴트 복사 생성자가 사용 된다.
	=>디폴트 복사 생성자는 모든 멤버를 복사 해준다
2. 디폴트 복사 생성자가 모든 멤버를 복사 해주는 것은
	=>편리한 경우도 있다
	=>문제가 되는 경우도 있다. 언제 그럴까?

*/
#include<iostream>
class Point
{
public:
	int x; int y;
	Point() {}
	Point(int a, int b) :x(a), y(b){}	
};
int main(){}
#endif

#if 0 //077
#include<iostream>
#pragma warning(disable:4996)
class Person
{
	char* name;
	int age;
public:
	Person(const char* n, int a) :age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	~Person() { delete[] name; }
	Person(const Person& p) :age(p.age)
	{
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
};
int main()
{
	Person p1("park", 20);
	Person p2 = p1;//복사 생성자를 따로 안만들어주면 오류생김.
}
#endif