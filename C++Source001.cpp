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