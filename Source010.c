#include <stdio.h>
#include <stdlib.h>


#if 0
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}
int main()
{
	int choice;
	int a, b,ret=0;
	char ch = 0;

	printf("연산 종류 선택(1. + 2. - 3. * 4. /) 두 값 입력: ");
	scanf_s("%d %d %d", &choice, &a, &b);
	switch (choice)
	{
	case 1:
		ret = add(a, b);
		ch = '+';
		break;
	case 2:
		ret = sub(a, b);
		ch = '-';
		break;
	case 3:
		ret = mul(a, b);
		ch = '*';
		break;
	case 4:
		ret = div(a, b);
		ch = '/';
		break;
	default:
		printf("오류");
	}
	printf("%d %c %d = %d\n", a, ch, b, ret);
}

#endif

#if 0

int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}
int foo(int a, double b)
{
	return a;
}

int main()
{
	int choice;
	int a, b, ret = 0;
	char ch[] = { '+','-','*','/' };
	/*
	funcp[]=add			//funcp[] 배열이 add 를 받는데 add 는 주소값이라
	*funcp[]=add		// *붙음
	add=int (int,int)	//add 는 int (int,int) 형임.
	int (int,int) *funcp[]	//따라서 *funcp[] 도 int (int,int) 형임.
	int *func[](int,int)	//넘기고 말이 맞게 넘기고 괄호 치면
	int (*func[])()			//이케 됨.
	*/
	int (*funcp[4])(int,int) = { add,sub,mul,div };
	//int funcp[] = { add,sub,mul,div };
	//int * ap[] = funcp;

	printf("%d %d %d %d\n", funcp[0], funcp[1], funcp[2], funcp[3]);
	//printf("%d %d %d %d\n", ap[0], ap[1], ap[2], ap[3]);


	printf("연산 종류 선택(1. + 2. - 3. * 4. /) 두 값 입력: ");
	scanf_s("%d %d %d", &choice, &a, &b);

	ret = funcp[choice - 1](a, b);
	//ret = (ap)[choice - 1](a, b);
	printf("%d %c %d = %d\n", a, ch[choice-1], b, ret);
}

#endif

#if 0
struct op_callbacks
{
	int a;
	int b;
	int ch;
	int (*add)(int, int);
	int (*sub)(int, int);
	int (*mul)(int, int);
	int (*div)(int, int);
	int (*foo)(int, double);
};

int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div(int a, int b)
{
	return a / b;
}
int foo(int a, double b)
{
	return a;
}

int main()
{
	int choice;
	int a, b, ret = 0;
	char ch[] = { '+','-','*','/' };
	struct op_callbacks op = { 0,0,0,add,sub,mul,div,foo };

	printf("연산 종류 선택(1. + 2. - 3. * 4. /) 두 값 입력: ");
	scanf_s("%d %d %d", &choice, &op.a, &op.b);
	switch (choice)
	{
	case 1:
		ret = op.add(op.a, op.b);
		op.ch = '+';
		break;
	case 2:
		ret = op.sub(op.a, op.b);
		op.ch = '-';
		break;
	case 3:
		ret = op.mul(op.a, op.b);
		op.ch = '*';
		break;
	case 4:
		ret = op.div(op.a, op.b);
		op.ch = '/';
		break;
	}
	printf("%d %c %d = %d\n",op.a, op.ch, op.b, ret);
}

#endif

#if 0

int main()
{
	int i;
	int flag[4] = { 0 };

	flag[0] = 1;
	flag[3] = 1;

	for (i = 0; i < 4; i++)
		if (flag[i] != 0)
			printf("%d\n", i);
	printf("------------------------\n");
	flag[3] = 0;
	for (i = 0; i < 4; i++)
		if (flag[i] != 0)
			printf("%d\n", i);
	return 0;
}
#endif

#if 0

int main()
{
	int i;
	int flag = 0;
	flag = flag | 1;//0001
	flag = flag | 8;//1001

	//0001
	//0010
	//0100
	//1000 을 & 연산하면 1일 경우 1이 나옴.

	for (i = 0; i < 4; i++)
		if (flag &  (1<<i))
			printf("%d\n", i);
	printf("----------------------------\n");
	flag = flag & ~8;
	for (i = 0; i < 4; i++)
		if (flag & (1 << i))
			printf("%d\n", 1);

	return 0;
}
#endif

#if 0
//#define BIT_SET(x,index) 	(x[index / 32] |= (1 << (index % 32)))
//#define BIT_ISSET(x,index)  (x[index/32] & (1 << (index%32)))
//#define BIT_CLR(x,index)	(x[index / 32] &= ~(1 << (index % 32)))
//typedef int bit_set[32];
//#define BIT_ZERO(x)			{int i;for (i=0;i<32;i++) x[i] = 0;}//한줄로 쓰기.
//#define BIT_ZERO(x)			{int i;\
							 for (i=0;i<32;i++)\
							 x[i] = 0;}//여러줄로 쓰기.
//#define BIT_ZERO2(x)		do{int i;for (i=0;i<32;i++) x[i] = 0;}while(0)//한번만 돌꺼니 0, do while 을 써야 if 문 안에 들어감.
/*
#define BIT_SET(x,index) 	((*x).data[index / 32] |= (1 << (index % 32)))
#define BIT_ISSET(x,index)  ((*x).data[index/32] & (1 << (index%32)))
#define BIT_CLR(x,index)	((*x).data[index / 32] &= ~(1 << (index % 32)))
#define BIT_ZERO(x)			{int i;\
							 for (i=0;i<32;i++)\
							 (*x).data[i] = 0;}//여러줄로 쓰기.
#define BIT_ZERO2(x)		do{int i;for (i=0;i<32;i++) (*x).data[i] = 0;}while(0)
*/
#define BIT_SET(x,index) 	((x)->data[index >> 5] |= (1 << (index & 31)))
#define BIT_ISSET(x,index)  ((x)->data[index >> 5] & (1 << (index & 31)))
#define BIT_CLR(x,index)	((x)->data[index >> 5] &= ~(1 << (index & 31)))
#define BIT_ZERO(x)			{int i;\
							 for (i=0;i<32;i++)\
							 (x)->data[i] = 0;}//여러줄로 쓰기.
#define BIT_ZERO2(x)		do{int i;for (i=0;i<32;i++) (x)->data[i] = 0;}while(0)
typedef struct
{
	int data[32];
	int sdata[32];
}bit_set;
int main()
{
	int i;
	//int flag[32] = { 0, };
	//bit_set flag = { 0, };
	bit_set flag;
	i = 3;
	if (i == 3)
		BIT_ZERO2(&flag);		//저렇게 쓰는 이유는 ; 이if 문에 걸리는가 아닌가임 if 문에 걸리면 문장이 끝났기 때문에 else 가 나올 수 없어서 오류뜸.
		//BIT_ZERO(flag)  //; 지우면 되는데 사람들이 ; 무조건 붙일것이기때문에 이렇게는 안씀.
		//printf("test");	
	else
		printf("no initialization\n");


	BIT_ZERO(&flag);//배열 안의 것을 0으로 만들어줌.

	//flag 의 700번째 방 셋팅
	//flag[700 / 32] = flag[700 / 32] | (1 << (700 % 32));
	//flag[700 / 32] |= (1 << (700 % 32));
	BIT_SET(&flag, 700);

	//flag 의 800번째 방 셋팅
	//flag[800 / 32] |= (1 << (800 % 32));
	BIT_SET(&flag,800);

	for (i = 0; i < 1024; i++)
		//if (flag[i / 32] & (1 << (i % 32)))
		if (BIT_ISSET(&flag, i))
			printf("%d\n", i);
		
	
	printf("--------------------------------------------\n");
	//flag[800 / 32] = flag[800 / 32] & ~(1 << (800 % 32));
	//flag[800 / 32] &= ~(1 << (800 % 32));
	BIT_CLR(&flag, 800);

	for (i = 0; i < 1024; i++)
		//if (flag[i/32] & (1 << (i%32)))
		if (BIT_ISSET(&flag,i))
			printf("%d\n", i);

	return 0;
}
#endif


#if 0
int main()
{
	int i = 0, j = 0, num;
	printf("Enter a number.");
	scanf_s("%d", &num);

	while (i < num*num)//내가바꾼점 1.(원래는 num)
	{
		while (j < num)
		{
			//printf("%5d",i*num+j+1); //이거도 됨. 위에건 안바꾸고.
			printf("%5d",i);
			j++;
			i++;//2. 원래는 없음.
		}
		printf("\n");
		j = 0;
		//i++;//3. 주석처리함.
	}
	return 0;
}
#endif


#if 0
#define MAX 5
int main()
{
#define MAX2 10
	int i = 0, j = 0, num;
	int a[MAX][MAX] = { 0 };
	
	for(i=0;i<MAX;i++)
		for (j = 0; j < MAX; j++)
		{
			a[i][j] = i*MAX + j+1;
		}
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
		return 0;
}
#endif

#if 0
#define MAX 5
int main()
{
#define MAX2 10
	int i = 0, j = 0, num=0;
	int a[MAX2][MAX2] = { 0 };

	for (i = 0; i < MAX2; i++)
		for (j = 0; j < i+1; j++)
		{
			a[i][j] = num+++1;
		}
	for (i = 0; i < MAX2; i++)
	{
		for (j = 0; j < i+1; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
#endif

#if 0
#define MAX 5
int main()
{
#define MAX2 10
	int i = 0, j = 0, num = 0;
	int a[MAX][MAX] = { 0 };

	for (i = 0; i < MAX; i++)
		for (j = 0; j < i+1; j++)
		{
			a[i][MAX-1-i+j] = num++ + 1;
		}
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (a[i][j])
			{
				printf("%3d", a[i][j]);
			}
			else
			{
				printf("   ");
			}
		}
		printf("\n");
	}
	return 0;
}
#endif

