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