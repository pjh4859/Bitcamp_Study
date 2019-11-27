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