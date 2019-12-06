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
#if 0 //virtual ��� �ϸ� ���� �Ȼ��� 
//���̾Ƹ�� ���
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
//�߻� Ŭ����
/*
1. ���� ���� �Լ� (pure virtual dunction)
	=>�Լ��� �����ΰ� ����, ����ΰ� =0 ���� ������ ���� �Լ�
2. �߻� Ŭ����(Abstract Class)
	=>���� ���� �Լ��� �� �� �̻� �ִ� Ŭ����
3. �߻� Ŭ���� Ư¡
	=>��ü�� ������ �� ����.
*/
#include<iostream>
class Shape
{
public:
	virtual void Draw() = 0;//pure virtual function
	//�̰� �ҷ����� ������ ����Ƿ� �̰� ��ӹ޴� �ֵ��� �̰� �� ������ ����� ��
	//�޸𸮵� ������. 
};
class Rect :public Shape
{
public:
	virtual void Draw() {}
	//virtual �Ƚᵵ �Ǵµ� ������������ ���°� ����
	//�� �� �� ����ϰ� �ϸ� �𸣰ԵǴ�
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
	//���⿡ virtual �� �Ⱦ��� Shape::Draw �� �ҷ���
	//=0; ���ָ� �޸𸮵� ������?
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
//ī�޶� �������� ���� ¥�� �ȵȴ�
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
	Point p1(1, 1); //������
	Point p2(2, 2);
	Point p3 = p1;	//���� ������

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
	os << "1.Į����" << endl;
	os << "2.���" << endl;
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

	String s2 = s1;            //���� �ʱ�ȭ
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
//0~9 ������ ���� �߻� ��Ű�� 
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