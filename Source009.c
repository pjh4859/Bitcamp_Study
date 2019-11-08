#include <stdio.h>

#if 0
int* foo()
{
	static int a = 20;
	return &a;
}
int* goo()
{
	static int a = 30;
	return &a;
}

int main()
{
	int* p,*pp;
	p = foo();
	pp = goo();
	printf("%d %d\n", *p,*pp);
	printf("%p %p\n", p, pp);

//둘 다 30이 나와버림.
	return 0;

}
#endif


#if 0
int add(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

int main()
{
	int a, b, c;
	a = 10;
	b = 20;// c = add(a, b);

	__asm mov	eax, dword ptr[a]
	__asm add	eax, dword ptr[b]
	__asm mov	dword ptr[c], eax

	printf("c: %d\n", c);
	return 0;
}
#endif

#if 1
void wow()
{
	int i = 5;
	double j = 4.5;
	double k = j + i;
}
int main()
{
	int i = 10;
	wow();

	return 0;
}





#endif


#if 0
//숙제
//bitcamp11_이름
//skypwk@hanmail.net
void goo()
{
	int a[2] = { 1,2 };
	printf("goo called\n");
	//int a[2] = { 1,2 };
}

void foo()
{
	int a[2] = { 1,2 };
	printf("foo called\n");
	a[5] = a[4];
	//a[2] = 3;
	//a[3] = 4;
	//a[4] = 0;
	a[4] = goo;
	//a[5] = 0;
}
int main()
{
	//int a[2] = { 1,2 };
	//a[5] = a[4];
	//a[4] = 0;
	//a[4] = goo;
	int i, j;
	i = 10;
	foo();
	j = i;
	printf("main \n");
	//__asm mov	esp,0 
	__asm sub esp, 4
	return 0;
}
#endif
//====================================================================
#if 0

typedef int(* FP1)[2];
typedef FP1(*FP2)();
//int(* foo())[2]
FP1 foo()
{
	static int a[2][2] = { 1,2,3,4 };
	return a;
}

int(* zoo())[2]
//int foo()
{
	static int a[2][2] = { 5,6,7,8 };
	return a;
}

//int(*foo())[2]
//int[2] *()foo
//int (*(*goo())())[2] = foo;

//int (*(*goo (int(*(*fun)())[2]))())[2]
//FP1 (*goo (int(*(*fun)())[2]))()
//FP1 (*goo(FP1 (*fun)()))()
//FP1 (*goo(FP2 fun))()
FP2 goo(FP2 fun)
{
	return fun;
}
int main()
{
	int i, j;
	int(*p)[2];
	p = foo();
	for (i=0;i<2;i++)
		for (j = 0; j < 2; j++)
		{
			printf("p[%d][%d] = %d\n", i, j, p[i][j]);
		}
//	goo(zoo)()[1][1] = 10;//L = R, L value 에는 주소값과 크기를 가지는 것이 오면 된다.
	//p[1][0] = 10;

	printf("\n");
	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
		{
			printf("p[%d][%d] = %d\n", i, j, p[i][j]);
			printf("p[%d][%d] = %d\n", i, j, foo()[i][j]);
		}
	printf("\n");

	for (i = 0; i < 2; i++)
		for (j = 0; j < 2; j++)
		{
			printf("p[%d][%d] = %d\t", i, j, goo(foo)()[i][j]);
			printf("p[%d][%d] = %d\n", i, j, goo(zoo)()[i][j]);
		}
	return 0;
}
#endif

#if 0

typedef int u32;

int main()
{
	u32 i;
	i = 10;
	printf("i : %d\n", i);

	return 0;
}
#endif


