#if 0 //001
#include<iostream>
#pragma warning(disable:4996)

void main()
{
	int num1 = 0;
	printf("���� �Է�:");
	scanf("%d", &num1);

	int num2 = 0;
	printf("���� �Է�:");
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
//C������ ��Ʈ���� �ȿ� �Լ� ���� �Ұ�.
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
	printf("�����Է�:");
	scanf_s("%d", &num);
	printf("���밪:%d\n",abs(num));
}
#endif
#if 0 //005
#include<iostream>

void main()
{
	int num1, num2;
	std::cout << "���� 2�� �Է�: " << std::endl;
	//std::cout �� ���� <<�� �Լ�
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
	const char* str = "�Ƹ��ٿ�", * str2 = "���ѹα�", * strResult;
	result = A::Plus(a, b);
	std::cout << result << std::endl;
	strResult = B::Plus((char*)str, (char*)str2);
	std::cout << strResult << std::endl;
	free((void*)strResult);
}
#endif //007
#if 0
//007 bool �ڷ���
#include<iostream>
using namespace std;
//std ���� �̸��� �� ����Ѵ�.
void main()
{
	int num;
	std::cout << "���ڸ� �Է��ϼ���:";
	//���� using namespace std;�� �Ⱦ��� ��ó�� �����.
	cin >> num;

	bool b = num > 0;
	if (b == true)
		cout << num << "������Դϴ�." << endl;
	else if (b == false)
		cout << num << "��������ƴմϴ�" << endl;
}
#endif
#if 0 //008 Reference ��.
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
	//ref�� �ѹ� �����ϸ� �ٲ� �� ����.
	p = &num;
	p = &aaa;
	cout << "r:" << r << endl;
	num = 50;
	cout << "r:" << r << endl;
}
#endif
#if 0 //010 �Լ� �����ε�
//�Լ��̸� �ڿ� �޴¸Ű����� Ÿ�԰� ���������� �̸��� �ٿ��༭ �ٸ��� ��.
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
#if 0 //011 ����Ʈ �Ķ����.
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
#if 0 //012 inline �Լ�
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
#if 0 //013 new, delete ������ malloc free �� ���� ��.
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
#if 0 //015 Ŭ���� 
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
//::�ǹ�,Point �ȿ��ִ� SetPoint �Լ�.
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
#if 0 //016 ������ �Ҹ���
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
	cout << "������ȣ��" << endl;
}
Point::~Point()
{
	cout << "�Ҹ���ȣ��" << endl;
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

#if 0 //017 ���������
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
	cout << "������ȣ��" << endl;
}
Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
	cout << "�Ű������ִ� ������ȣ��" << endl;
}
Point::~Point()
{
	cout << "�Ҹ���ȣ��" << endl;
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
	Point(const Point& pt);                     //���۷��� ������ ����� ���ÿ� �ʱ�ȭ�ؾ���

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
	cout << "���� ������ ȣ��" << endl;
	x = pt.x;
	y = pt.y;
}

Point::Point()
{
	x = 0;
	y = 0;
	cout << "������ȣ��" << endl;
}

Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
	cout << "�Ű������ִ� ������ ȣ��" << endl;
}

Point::~Point()
{
	cout << "�Ҹ���ȣ��" << endl;
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
	Point pt(100, 200);         //�Լ� �����ε�
	Point pt1 = pt;
	//   pt1.x = 300;            //�㰡�� ����, �ȵ�, Point::���� �����ϴ� �ֵ��� �㰡�� ����.
	//   cout<<"pt.x"<<



}
#endif

#if 0 //019 ���� ������.(����.) 
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
	cout << "�Ű����� �ִ� ������ȣ��" << endl;
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
	cout << "���� ������ ȣ��" << endl;
}

Point& Point::operator=(const Point& apt)
{
	if (strlen(Name) < strlen(apt.Name))
	{
		delete[] Name;
		Name = new char[strlen(apt.Name) + 1];
		memset(Name, 0, strlen(apt.Name) + 1);//0���� �ʱ�ȭ
		strncpy(Name, apt.Name, strlen(apt.Name));
	
		goto next;
	}
	memset(Name, 0, strlen(apt.Name) + 1);
	strncpy(Name, apt.Name, strlen(apt.Name));
next:
	x = apt.x;
	y = apt.y;
	//cout << "���� ������ ȣ��" << endl;
	cout << "������ ������" << endl;
	return *this;
}
Point::~Point()
{
	delete[] Name;
	cout << "�Ҹ��� ȣ��" << endl;
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
	Point pt((char*)"�������� ����", 100, 100);
	Point pt1 = pt;
	pt1 = pt;
	pt1.ShowPoint();
	Point t;
	t = pt + pt1;
	t.ShowPoint();

}
#endif
#if 0 // 020 static ���
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
#define NAME_LEN 30

class Theater
{
private:
	char* m_strName;
	static int m_nViewerCount;
	//static�� �۷ι� ������ ������ ������ �� ������ ������ sizeof�� �̰� 4����Ʈ ����.
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
//static �̱⶧���� �ܺο��� ��������� �� ���ִ�. �ʱ�ȭ�� �̷��� ���� ������ �ؾ���.
//static �̸� ��ü�� ��� ������ �� �ִ�.
void main()
{
	//Theater::AddViewerCount();
	//Theater::GetlocalCount();
	//Theater::m_nViewerCount;
	Theater test((char*)"��������");
	test.GetlocalCount();
	test.AddViewerCount();
	cout << "������ : " << Theater::GetViewerCount() << "��" << endl;
	Theater theater1((char*)"�ܼ���");
	Theater theater2((char*)"�������");
	Theater theater3((char*)"��CGV");
	printf("%d\n", sizeof(Theater));
	for (int i = 0; i < 1000000; i++)
		theater1.AddViewerCount();
	for (int i = 0; i < 1500000; i++)
		theater2.AddViewerCount();
	for (int i = 0; i < 2000000; i++)
		theater3.AddViewerCount();
	cout << "������ : " << Theater::GetViewerCount() << "��" << endl;
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
	//static�� �۷ι� ������ ������ ������ �� ������ ������ sizeof�� �̰� 4����Ʈ ����.
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
//static �̱⶧���� �ܺο��� ��������� �� ���ִ�. �ʱ�ȭ�� �̷��� ���� ������ �ؾ���.
//static �̸� ��ü�� ��� ������ �� �ִ�.
void main()
{
	//Theater::AddViewerCount();
	//Theater::GetlocalCount();
	//Theater::m_nViewerCount;
	//Theater test((char*)"��������");
	//test.GetlocalCount();
	//test.AddViewerCount();

	cout << "������ : " << Theater::GetViewerCount() << "��" << endl;
	Theater theater1((char*)"�ܼ���");
	Theater theater2((char*)"�������");
	Theater theater3((char*)"��CGV");
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
	cout << "theater1������ : " << theater1.GetlocalCount() << "��" << endl;
	cout << "theater2������ : " << theater2.GetlocalCount() << "��" << endl;
	cout << "theater3������ : " << theater3.GetlocalCount() << "��" << endl;
}

#endif
#if 0 //022 ���.

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
#if 0 //023 ������ �����ε�.
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

	cout << "A/B�� ������ 2���� �� �Է�:";
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

	cout << "A/B �� ������ 2���� �� �Է�:";
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
	cout << (p = Add<char*>((char*)"�Ƹ��ٿ�", (char*)"���ѹα�")) << endl;
	delete[] p;
}

#endif
#if 0 //028
#include <stdio.h>
/*
namespace �� �ʿ伺
1. �ϳ��� ���α׷��� ����~ ���鰳�� ���̷� ������ �� �ְ�
���ʸ��� �����ڰ� ���� �۾��� �� �� �ִ�.
2. �Լ� �� ����ü�� �̸� �浹�� �߻� �� �� �ִ�.
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
namespace �� �ʿ伺
1. ���α׷��� �پ��� ��� (�Լ�, ����ü��)�� ������ ��ҳ��� ���� �� �� �ִ�.
2. ��ɺ��� �ٸ� �̸� ������ ��������ν� �Լ�/����ü���� �̸� �浹�� ���� �� �ִ�.
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
namespace �� �ִ� ��� ���ٹ�� 3����
1."������ �̸�(qualified name)"
	==>Audio::init();
2. "using ����(declaration)"
	==>using Audio::init;
3. "using ���þ�(directive)"
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
	//algorithm lib�� count �� �־ using namespace std;�� �ϸ� �浹�� ����. 
	//::count �� int count �� �� �� �ִ�.
}
#endif
#if 0  //031
//C++ ��������� Ư¡
//<stdio.h> vs <cstdio>
/*
1. ��� ������ Ȯ���ڸ� ������� �ʴ´�.
2. ���� c ����� ����ϴ� "���ο� �������" �� �����Ѵ�.
	==><stdio.h> --> <cstdio>
	==><stdlib.h> --> <cstdlib>
	==><��������̸�.h> --> <c��������̸�>
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
���� ������ �ִ� �Լ��� namespace�� �����ϴ� ���
==> using ������ ����ϸ� �ȴ�.
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
1. ǥ�� ���
	==>std::cout
	==>���� �� ��½� "���� ���ڿ��� ������ �ʿ䰡 ����."
	==> <<�� ���������� "������ ���" �� ���� �ִ�.
2. ����
	==>std::endl;
	==>C ����� \n �� ����ص� �ȴ�.
3. ǥ�� �Է�
	==> std::cin
	==> ���� ���ڿ��� �ʿ����, �ּ� �����ڸ� ������� �ʴ´�.
4. ǥ�� ������� ����ϱ� ���� �ش� ����
	==> <iostream>
	1. printf��  scanf ==> �Լ�
	2. std::cout, std::in ==>�Լ� ? ����! Ű����?
	3. std::endl �� '\n' �� ������.
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
	int n1 = 0b010; //0x10,070(8����), 0b010(2����)
	int n2 = 1'000'000;
	bool b = true;
	long long n3 = 10; //64bit ���� C++11
	char* s1 = (char*)"aaa";
	wchar_t* s2 = (wchar_t*)L"AAA"; //�����ڵ� ����

	char16_t a = 'a';
	char32_t c = 'c';

}
#endif
#if 0 //035
/*
�ϰ��� �ʱ�ȭ(uniform initalization)
1. ������ �ʱ�ȭ �� ��, �߰�ȣ {} �� ����ؼ� �ʱ�ȭ �ϴ� ��.
2. C++11 ���� ���� �� ��
*/
int main()
{
	int n1 = 10;
	int n2 = { 10 };
}
#endif
#if 0 //035(2)
/*
�ϰ��� �ʱ�ȭ(uniform initialization)
���� �ʱ�ȭ ����� ������
1. ������ Ÿ��/������ ���� "�ʱ�ȭ ����� �ٸ���"
	==> "=��", "(��)", "{��}"
2. �Ͻ��� ����ȯ�� ���� ������ �ս� �� �߻� �� �� �ִ�.

�ϰ��� �ʱ�ȭ(uniform initialization) �� ����
1. ��� ������ ������ �ʱ�ȭ �� �� �ϳ��� ���(ubiform) ���� �ʱ�ȭ ����/
2.������ �ս��� �߻��� ��� ������ ���� �߻�
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
�ʱ�ȭ�� 2���� ����
1. ���� �ʱ�ȭ(direct initailization)
	==> int n(0);
	==> int n{0};

2. ���� �ʱ�ȭ(copy ")
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

	int n2 = { 0 };//copy �ʱ�ȭ
	int n3{ 0 };//direct �ʱ�ȭ
}
#endif
#if 0 //036
//auto /decltype
/*
1. ������ Ÿ���� �����Ϸ��� ���� �ϴ� ����
	==> ������ �ð��� ����, �ǹǷ� ����ð� �������� ����.
2. auto
	==> �캯�� ���� (expression) ���� �º��� Ÿ�� �� ����
	==> �ݵ�� �ʱⰪ(�캯��)�� �ʿ��ϴ�.
3. decltype
	==> ()���� ǥ������ ������ Ÿ���� ����
	==> �ʱⰪ�� ����� �ȴ�.
*/
int main()
{
	int x[5] = { 1,2,3,4,5 };
	int n1 = x[0];
	double d = 3.14;
	auto n2 = x[0];
	auto d1 = d;//auto �� ����\�޴� ���� �ڷ����� ������.

	decltype(n1) n3;//n1Ÿ������n3Ÿ���� ����
	decltype(n1) n3= n1;//n1Ÿ������n3Ÿ���� �����ϰ� ���� ����
}
#endif
#if 0 //036(2)
/*
1.auto
	==>�캯�� �迭�̸� ��Ҹ� ����Ű�� ������ Ÿ������ Ÿ���� �����ȴ�.
2. decltype 
	==> ()���� ǥ������ �迭�̸� ()���� ǥ���İ� ������ ������ �迭Ÿ������ ����
	==> �� ��� ���� ǥ�������� �ʱ�ȭ �� �� ����.
3. auto �� decltype �� ǥ���Ŀ� ���� Ÿ���� �ٸ��� ���� �Ǵ� ��찡 �̴�.
	==> int y[2] ={1,2};
	==> decltypr(y[0]) d4 = y[0];  //int& �� ����
*/
#include<iostream>
int main()
{
	int n1 = 10;
	auto a1 = n1;
	decltype(n1) d1;

	int x[3] = { 1,2,3, };
	auto a2 = x; //1.int a2[3] =x;��� �߷��ϸ�???

	decltype(x) d2; //int d2[3]���� �߷�...

	std::cout << "a1: " << a1 << std::endl;
	std::cout << "x: " << x << std::endl;
	std::cout << "a2: " << a2 << std::endl;
	std::cout << "sizeof(d2):" << sizeof(d2) << std::endl;
	decltype(x)d3 = { 1,2,3 };
	//int d3[3] = { x, };
	int y[2] = { 1,2 };
	auto a4 = y[0];//int
	decltype(y[0]) d4=y[0];//int�� �ƴϰ� int&
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
	decltype(foo) d1;//�Լ� Ÿ�� int(int,double)
	decltype(&foo)d2;//�Լ� ������ Ÿ�� int(*)(int, doubleg)
	decltype(foo(1, 3.1))d3; //�Լ� ��ȯ Ÿ�� int ������ Ÿ�Կ� ����
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
	const int s1 = 10;//������ Ÿ��
	int arr2[s1];
	int s2;
	const int s3 = s2;//��Ÿ��.
}
#endif
#if 0 //040
/*
1.const
	==> ������ �ð� ��� �� ����ð� ����� ��� ���� �� �ִ�.
	==> ���� ������ �ʱ�ȭ �� �� �ִ�.
2. constexpr 
	==> ������ �ð� ����� ���� �� �ִ�.
	==> ������ �ð��� ��� �� �� �ִ� �� ���θ� �ʱ�ȭ ����
	==> ���ø� ���ڷ� ��� �� �� �ִ�.
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
//structed binding ����, ����
/*
1. ����ü �Ǵ� �迭���� �� ����� ���� ���� �� ���
2. Ÿ���� �ݵ�� auto ���
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
	auto [x, y] = pt;//C++17���� ��밡��
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
//C++���� ���ڿ� ó���ϴ� ���
//std::string ����
#include<iostream>
#include<cstring>

int main()
{
	char s1[32] = "hellow";
	const char* s2 = "world";

	//s1 = s2; //���� ��� �Ұ��� ���������� �ʴ�.
	strcpy_s(s1, s2);

	//if (s1==s2){} //�� �Ұ���
	if (strcmp(s1, s2) == 0) {}
	//�� �ҽ��� cpp������ �ٲپ� ����.
}
#endif
#if 0 //042(2)
//C++���� ���ڿ� ó���ϴ� ���
//std::string ����
#include<iostream>
#include<string>

int main()
{
	//char s1[32] = "hellow";
	//const char* s2 = "world";
	std::string s1 = "hello";
	std::string s2 = "world";

	//s1 = s2; //���� ��� �Ұ��� ���������� �ʴ�.
	//strcpy_s(s1, s2);
	s1 = s2;

	//if (s1==s2){} //�� �Ұ���
	//if (strcmp(s1, s2) == 0) {}
	if (s1 == s2)
	{
		std::cout << "same"<<std::endl;
	}
	std::string s3 = s1 + s2;
	std::cout << s3 << std::endl;
	//�� �ҽ��� cpp������ �ٲپ� ����.	
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
//�Լ� �����ε�(function overloading)
/*
1. C ������ "������ �̸��� �Լ��� 2�� �̻� ���� �� ����."
2. C++ ������ "������ �̸��� �Լ��� ���� �� ���� �� �ִ�."
3. �Լ� ����� ���忡���� ������ �Լ�ó�� �����ϰ� �ǹǷ�
�ϰ��� ������ ���̺귯�� �� ������ �� ����.
4. C�� ������ "��κ��� �ֽ� ������ ����" �ϴ� Ư¡
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
//function template �� ����
//template �� ���� 
/*
���ø��� �⺻����
1. Ÿ�Ը� �ٸ��� "������ �����ϰų� ������ �Լ�"
�� ������ �ִٸ� �����ڰ� ���� ������ ����, "�����Ϸ��� �Լ��� ����" �ϰ� ����.
2. �����Ϸ��� �Լ��� ������ �� ����� "�Լ��� Ʋ(template)"�� �־�� �Ѵ�.
3. �����ڴ� �Լ� ���ø��� �����, �����Ϸ��� ���ø��� ����ؼ� �ʿ��� �Լ��� ���� �ϰ� ����.
*/
int square(int a) { return a * a; }
double square(double a) { return a * a; }

template<typename T>		//template parameter //������ �ð��� ����
T square(T a)				//call parameter	//����ð��� �Լ��� ����
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
Ŭ����(����ü) ���ø� 
1. �Լ� �� �ƴ϶� "Ŭ����(����ü)�� ���ø�" ���� ���� �� �ִ�.
2. "C++17" ���ʹ� �����ڰ� ������ "���ø� �Ķ���� ������ ����" �� �� �ִ�.
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
//�Լ� ����(delete function) C++11
/*
1. "�Լ��� ����" �ϴ� ���
2. ������ �Լ��� ȣ���ϸ� "������ �ð��� ����" �߻�
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
���� ��ȯ Ÿ�� (trailing return type)
�Լ��� ���� ��ȯ Ÿ�� ǥ��� C++11
1. �Լ��� ���鶧 ����ϴ� "���ο� ǥ���"
	==> �Լ��� "�̸� �տ��� auto" �� ����, ��ȣ �ڿ� 
	"->��ȯ Ÿ��"�� ���� ǥ���
2. "trailing return type" �Ǵ� "suffix return type" 
3. "C++11" ���� ����
4. "���� ǥ����" �̳� "�Լ� ���ø�" �� ���鶧 �ַ� ���
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