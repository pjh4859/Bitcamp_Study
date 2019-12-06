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
#if 0
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
//---------2019-12-06-----------------------------------------
//---------2019-12-06-----------------------------------------
//---------2019-12-06-----------------------------------------
#if 0 //virtual 상속 하면 문제 안생김 
//다이아몬드 상속
#include<iostream>
#include<string>
class File
{
public:
	std::string filename;
	void open() {}
};
class InputFile:virtual public File 
{
public:
	void read() {}
	//void open() {}
};
class OutputFile:virtual public File
{
public:
	void write() {}
	//void open() {}

};
class IOFile :public InputFile, public OutputFile
{

};
int main()
{
	IOFile file;
	file.open();
}
#endif
#if 0 
//추상 클래스
/*
1. 순수 가상 함수 (pure virtual dunction)
	=>함수의 구현부가 없고, 선언부가 =0 으로 끝나는 가상 함수
2. 추상 클래스(Abstract Class)
	=>순수 가상 함수가 한 개 이상 있는 클래스
3. 추상 클래스 특징
	=>객체를 생성할 수 없다.
*/
#include<iostream>
class Shape
{
public:
	virtual void Draw() = 0;//pure virtual function
	//이게 불려오면 문제가 생기므로 이걸 상속받는 애들은 이걸 꼭 재정의 해줘야 함
	//메모리도 안잡힘. 
};
class Rect :public Shape
{
public:
	virtual void Draw() {}
	//virtual 안써도 되는데 가독성때문에 쓰는게 좋다
	//한 번 더 상속하고 하면 모르게되니
};
int main()
{
//	Shape s;
	Shape* p;
	Rect r;
}
#endif
#if 0
#include<iostream>
#include<vector>
using namespace std;
class Shape
{
public:
	//virtual void Draw() { cout << "Shape::Draw" << endl; }
	virtual void Draw() = 0;
	//여기에 virtual 을 안쓰면 Shape::Draw 만 불려옴
	//=0; 해주면 메모리도 안잡힘?
};
class Circle :public Shape
{
public:
	virtual void Draw(){ cout << "Circle::Draw" << endl; }
};
class Rect :public Shape
{
public:
	void Draw() { cout << "Rect::Draw" << endl; }
};
class Tri :public Shape
{
public:
	void Draw() { cout << "Tri::Draw" << endl; }
};
int main()
{
	vector<Shape*>v;
	while (1)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)v.push_back(new Rect);
		else if (cmd == 2)v.push_back(new Circle);
		else if (cmd == 3)v.push_back(new Tri);
		else if (cmd == 9)
		{
			for (auto p : v)
				p->Draw();
		}
		if (cmd == -1)
			break;
	}
}
#endif
#if 0
//카메라가 많아지면 요케 짜면 안된다
#include<iostream>
class Camera
{
public:
	void take()
	{
		std::cout << "take pictue" << std::endl;
	}
};
class HDCamera
{
public:
	void take()
	{
		std::cout << "take pictue HD" << std::endl;
	}
};
class People
{
public:
	void useCamera(Camera* p) { p->take(); }
	void useCamera(HDCamera* p) { p->take(); }
};
int main()
{
	People p;
	Camera c1;
	p.useCamera(&c1);
	HDCamera hd;
	p.useCamera(&hd);
}
#endif
#if 0
#include<iostream>
//class ICamera
struct ICamera
{
//public:
	virtual void take() = 0;
};
class Camera:public ICamera
{
public:
	void take()
	{
		std::cout << "take pictue" << std::endl;
	}
};
class HDCamera :public ICamera
{
public:
	void take()
	{
		std::cout << "take pictue HD" << std::endl;
	}
};
class People
{
public:
	void useCamera(ICamera* p) { p->take(); }
};
int main()
{
	People p;
	Camera c1;
	p.useCamera(&c1);	
	HDCamera hd;
	p.useCamera(&hd);
}
#endif
#if 0
#include<iostream>
class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) :x(a), y(b) {}
	void Print()const
	{
		std::cout << x << ", " << y << std::endl;
	}
	friend Point operator+(const Point& p1, const Point& p2);
	friend Point operator+(const int i, const Point& p2);
};
Point operator+(const Point& p1, const Point& p2)
{
	Point temp;
	temp.x = p1.x + p2.x;
	temp.y = p1.y + p2.y;
	return temp;
}
Point operator+(const int i, const Point& p2)
{
	Point temp;
	temp.x = i + p2.x;
	temp.y = i + p2.y;
	return temp;
}
int main()
{
	int n = 1 + 2;
	Point p1(1, 1);
	Point p2(2, 2);
	Point p3 = p1 + p2;//1. p1.operator+(p2)
						//2. operator+(p1,p2)

	p3=p1 + 1;	//(p1.operator+(in)
	p3.Print();
	p3=1 + p2;	//operator+(int, Point)
	p3.Print();
}
#endif
#if 0
#include<iostream>
using namespace std;
class Point
{
	int x, y;
public:
	Point(int a=0,int b=0):x(a),y(b){}
	void print()const
	{
		cout << x << ", " << y << endl;
	}
	Point& operator++()
	{
		++x; ++y;
		return *this;
	}
	const Point operator++(int)
	{
		Point temp(*this);
		//++x;
		//++y;
		++(*this);
		return temp;
	}
};
int main()
{
	int n = 3;
	++n;
	cout << "n: " << n << endl;
	Point p(1, 1);
	++p;	//p.operae
	p.print();
	++++n;
	cout << "n: " << n << endl;
	++++p;	//(p.operator++()).operator++()
	p.print();
	int i = n++;
	Point p1 = p++; //p.operator++(int)
	p1.print();
	p.print();
	//n++++;//error
	p++++;
}
#endif // 0
#if 0
#include<iostream>
using namespace std;
class Point
{
	int x, y;
public:
	Point(int a, int b) :x(a), y(b) {}
	void print()const { cout << x << ", " << y << endl; }
	Point& operator =(const Point&p)
	{
		cout << "=" << endl;
		x = p.x;
		y = p.y;
		return *this;
	}
};
int main()
{
	Point p1(1, 1); //생성자
	Point p2(2, 2);
	Point p3 = p1;	//복사 생성자

	p3 = p2;
	p3.print();
	int n = 10;
	int b;
	b - 20;
}
#endif
#if 0
#include<iostream>
using namespace std;

int main()
{
	printf("%d\n", 3);
	cout << 3;//cout.operator<<(3) => operator<<"(int)
	cout << 3.4;//cout.operator(3.4)=>operator<<(double)

}
#endif
#if 0
#include<cstdio>
namespace std
{
	class ostream
	{
	public:
		ostream& operator<<(int n) { printf("%d", n); return *this; }
		ostream& operator<<(double n) { printf("%f", n); return *this; }
	};
	ostream cout;
}
int main()
{
	//cout << 3;		//cout.operator<<(int n)
	//cout << 3.4;	//cout.operator<<(double n)
	//cout << 3 << 3.4;
	//cout << 3.4 << 1;
	std::cout << 3 << 3.4;
}
#endif
#if 0
#include<iostream>
class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) :x(a), y(b) {}
	friend std::ostream& operator<<(std::ostream& os, const Point& pt);

};
 std::ostream& operator<<(std::ostream& os, const Point& pt)
{
	os << pt.x << ", " << pt.y;
	return os;
}

int main()
{
	int a = 10;
	double d = 3.4;
	Point pt(1, 2);
	std::cout << a << ", " << d<<'\n';
	std::cout << pt;	//std::cout.operator<<(pt)==>operator<<(Point)
}						//operator<<(cout,pt)==>operator(ostream,Point)
#endif
#if 0
#include<iostream>
#include<cstdio>
using namespace std;
ostream& myendl(ostream& os)
{
	os.put('\n');
	os.flush();
	return os;
}

int main()
{
	cout << "test";
	cout << endl;
	cout << "aaa";
	endl(cout);
	cout << "bbb";
	cout.put('\n');
	cout.flush();

	cout << "endl";
	endl(cout) << "test";
	endl(cout) << "end";

	myendl(cout);
	cout << "bitcamp";
	cout << endl;
	cout << myendl;
}
#endif
#if 0
#include<cstdio>
namespace std
{
	class ostream
	{
	public:
		ostream& flush() { return *this; }
		ostream& put(char c) { printf("%c", c); return *this; }
		ostream& operator<<(int n) { printf("%d", n); return*this; }
		ostream& operator<<(double n) { printf("%f", n); return*this; }
		ostream& operator<<(ostream& (*f)(ostream&))
		{
			f(*this);
			return *this;
		}
	};
	ostream cout;

	ostream& endl(ostream& os)
	{
		os.put('\n');
		os.flush();
		return os;
	}
}
int main()
{
	std::cout << 3;
	std::cout << std::endl << 3.4 << std::endl;
}
#endif
#if 0
#include<iostream>
using namespace std;
ostream& tab(ostream& os)
{
	os.put('\t');
	return os;
}
ostream& menu(ostream& os)
{
	os << "1.칼국수" << endl;
	os << "2.라면" << endl;
	return os;
}
int main()
{
	cout << "A" << '\t' << "B" << endl;
	cout << "A" << tab << "B" << endl;
	cout << menu << endl;
}
#endif
#if 0
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class String
{
	//char buff[10];
	char* buff;
	int size;
public:
	String(const char* s)
	{
		size = strlen(s);
		buff = new char[size + 1];
		strcpy(buff, s);
	}
	String(const String& s) : size(s.size)
	{
		buff = new char[size + 1];
		strcpy(buff, s.buff);
	}
	~String() { delete[] buff; }
	friend ostream& operator<<(ostream& os, const String& s);
	String operator=(const String& s)
	{
		if (&s == this)
			return *this;
		size = s.size;
		delete[] buff;
		buff = new char[size + 1];
		strcpy(buff, s.buff);
		return *this;
	}
};

ostream& operator<<(ostream& os, const String& s)
{
	return os << s.buff;
}

int main()
{
	String s1 = "hello";
	cout << s1 << endl;         //operator<<(count, s1)

	String s2 = s1;            //복사 초기화
	cout << s2 << endl;

	String s3 = "world";
	cout << s3 << endl;
	s3 = s1;               //s3.operator=(s1)   ==>   operator=(String)
	s3 = s2 = s1;
	cout << s3 << endl;

	s1 = s1;
	cout << s1 << endl;
	int n = 10;
	n = n;
}
#endif
#if 0
#include<iostream>
class Car
{
	int color;
public:
	~Car() { std::cout << "~Car()" << std::endl; }
	void Go(){ std::cout << "Car go" << std::endl; }
};
template<typename T>
class Ptr
{
	T* pObj;
public:
	Ptr(T* p = 0) :pObj() {}
	~Ptr() { delete pObj; }
	T* operator->() { return pObj; }
	T& operator*() { return *pObj; }
};
#include<memory>
int main()
{
	std::shared_ptr<Car>p1(new Car);
	p1->Go();
	//Car a;
	//Car* p1 = &a;
	//p1->Go();
	//(*p1).Go();
	//a.Go();
	//Ptr p = new Car;
	//p->Go();	//p.operator->()Go()
	//			//p.operator->()->Go();
	//(*p).Go();
}
#endif
#if 0
class Plus
{
	int a;
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};
int main()
{
	Plus p;
	int p = p(1, 2);//p.operator()(1,2)
}
#endif
#if 1
//0~9 사이의 난수 발생 시키자 
#include<iostream>
#include<ctime>
int frand()
{
	//static char history[10] = { 0, };
	return rand()%10;
}
class URandom
{
	char history[10];
public:
	URandom()
	{
		for (int i = 0; i < 10; i++)
		{
			history[i] = 0;
			srand(time(0));
		}
	}
	int operator()()
	{
		int n = -1;
		do {
			n = rand() % 10;
		} while (history[n] == 1);
		history[n] = 1;
		return n;
	}
};
int main()
{
	URandom orand;
	std::cout << orand() << std::endl;
	std::cout << orand() << std::endl;
	std::cout << orand() << std::endl;
	std::cout << orand() << std::endl;
	std::cout << orand() << std::endl;
	std::cout << orand() << std::endl;
	std::cout << orand() << std::endl;
	std::cout << orand() << std::endl;
	std::cout << orand() << std::endl;
	std::cout << orand() << std::endl;
	std::cout << frand() << std::endl;
}
#endif
#if 0
#include<iostream>
#include<functional>
int main()
{
	std::plus<double>p;
	std::cout << p(3.4, 5.6) << std::endl;
}
#endif
#if 0
#include<iostream>
#include<vector>
#include<list>

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p1 = x;
	++p1;
	*p1 = 20;
//	std::vector<int>v = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	auto p2 = v.begin();
	++p2;
	*p2 = 30;
	++p2;
	std::cout << *p2 << std::endl;
	for (auto n : v)
		std::cout << n << ", " ;
}
#endif
#if 0
#include<iostream>
#include<vector>
#include<list>

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	auto p1 = std::begin(x);
	auto p2 = std::end(x);
	
	while (p1 != p2)
	{
		std::cout << *p1 << std::endl;
		++p1;
	}
}
#endif