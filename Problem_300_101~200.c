#if 0 //101 메모리 비교하기(memcmp)
#include<stdio.h>
#include<string.h>

void main()
{
	char s1[100] = "123";
	char s2[100] = "123";

	strcpy_s(&s1[4],sizeof(&s1[4]), "abc");
	strcpy_s(&s2[4], sizeof(&s2[4]), "efg");

	if (strcmp(s1, s2) == 0)
	{
		puts("strcmp: 버퍼의 값이 일치합니다.");
	}
	if (memcmp(s1, s2, 7) == 0)
	{
		puts("memcmp: 버퍼의 값이 일치합니다.");
	}
	else
	{
		puts("memcmp: 버퍼의 값이 일치하지 않습니다.");
	}
}
#endif
#if 0 //102 메모리 이동하기(memmove)
#include<stdio.h>
#include<string.h>

char s1[20] = "1234567890";
char s2[20] = "1234567890";

void main()
{
	puts(s1);
	memcpy(s1 + 4, s1 + 2, 5);
	puts(s1);

	puts(s2);
	memmove(s2 + 4, s2 + 2, 5);
	puts(s2);
}
#endif
#if 0 //103 메모리 채우기(memset)
#include<stdio.h>
#include<string.h>

void main(void)
{
	char string[50] = "아름다운 우리나라 대한민국";

	puts(string);
	memset(string, (int)NULL, sizeof(string));
	memset(string, '*', sizeof(string) - 1);

	puts(string);
}
#endif
#if 0 //104 메모리를 복사하는 함수 만들기
#include<stdio.h>
#include<string.h>

struct tagM1
{
	int x;
	int y;
	char buffer[30];
};

void* My_memcpy(void* dst, const void* src, unsigned int count);

void main(void)
{
	struct tagM1 x1, x2;
	x1.x = 5;
	x1.y = 10;
	strcpy_s(x1.buffer,sizeof(x1.buffer), "memory copy");
	
	My_memcpy(&x2, &x1, sizeof(x1));

	puts(x2.buffer);
}
void* My_memcpy(void* dst, const void* src, unsigned int count)
{
	void* ret = dst;
	while (count--)
	{
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
	return ret;
}
#endif
#if 0 //105 메모리를 이동하는 함수 만들기
#include<stdio.h>
#include<string.h>

char s[20] = "1234567890";

void* My_memmove(void* dst, const void* src, unsigned int count);

void main(void)
{
	puts(s);
	My_memmove(s + 4, s + 2, 6);
	puts(s);
}

void* My_memmove(void* dst, const void* src, unsigned int count)
{
	void* ret = dst;

	if (dst <= src || (char*)dst >= ((char*)src + count))
	{
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		dst = (char*)dst + count - 1;
		src = (char*)src + count - 1;

		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}
	return ret;
}
#endif
#if 0 //106 포인터 사용하기
#include<stdio.h>

void main(void)
{
	char* p_char;
	short* p_short;
	int* p_int;
	long* p_long;
	float* p_float;
	double* p_double;

	printf("문자형의 크기: %d 바이트\n", sizeof(char));
	printf("정수형의 크기: %d 바이트\n", sizeof(short));
	printf("정수형의 크기: %d 바이트\n", sizeof(int));
	printf("정수형의 크기: %d 바이트\n", sizeof(long));
	printf("실수형의 크기: %d 바이트\n", sizeof(float));
	printf("실수형의 크기: %d 바이트\n", sizeof(double));

	printf("문자형 포인터의 크기: %d 바이트\n", sizeof(p_char));
	printf("정수형 포인터의 크기: %d 바이트\n", sizeof(p_short));
	printf("정수형 포인터의 크기: %d 바이트\n", sizeof(p_int));
	printf("정수형 포인터의 크기: %d 바이트\n", sizeof(p_long));
	printf("실수형 포인터의 크기: %d 바이트\n", sizeof(p_float));
	printf("실수형 포인터의 크기: %d 바이트\n", sizeof(p_double));
}
#endif
#if 0 //107 포인터를 함수에서 사용하기
#include<stdio.h>

void change_x1(int x1);
void change_x2(int *x2);

void main(void)
{
	int x;

	x = 5;
	printf("함수를 호출하기 전 x값: %d\n", x);

	change_x1(x);
	printf("change_x1() 함수를 호출한 후의 x값:%d\n", x);

	change_x2(&x);
	printf("change_x2() 함수를 호출한 후의 x값:%d\n", x);

}

void change_x1(int x1)
{
	x1 = 50;
	printf("%d\n", x1);
}

void change_x2(int* x2)
{
	*x2 = 100;
	printf("%d\n", x2);
}
#endif
#if 0 //108 
#include<stdio.h>

void main()
{
	int x = 0, y = 0;
	int* pxy[2];

	pxy[0] = &x;
	pxy[1] = &y;

	*pxy[0] = 5;
	*pxy[1] = 10;

	printf("x=%d,pxy[0]=%d\n", x, *pxy[0]);
	printf("y=%d,pxy[1]=%d\n", y, *pxy[1]);

	printf("x+y=%d\n", x + y);
	printf("x+y=%d\n", *pxy[0] + *pxy[1]);
}
#endif
#if 0 //109 포인터 배열을 함수에서 사용하기
#include<stdio.h>

void print_pxy(int* pxy[2]);

void main()
{
	int x = 0, y = 0;
	int* pxy[2];

	pxy[0] = &x, pxy[1] = &y;
	*pxy[0] = 5, *pxy[1] = 10;

	print_pxy(pxy);	
}
void print_pxy(int* pxy[2])
{
	printf("pxy[0]=%d\n", *pxy[0]);
	printf("pxy[1]=%d\n", *pxy[1]);
	printf("pxy[0]=%d\n", pxy[0]);
	printf("pxy[1]=%d\n", pxy[1]);
}
#endif
#if 0 //110 1차원 배열 사용하기
#include<stdio.h>

void main(void)
{
	char one[10] = "Kovea";

	puts(one);
	one[2] = 'r';
	puts(one);

	printf("one[0]=%3d,%c\n", one[0], one[0]);
	printf("one[1]=%3d,%c\n", one[1], one[1]);
	printf("one[2]=%3d,%c\n", one[2], one[2]);
	printf("one[3]=%3d,%c\n", one[3], one[3]);
	printf("one[4]=%3d,%c\n", one[4], one[4]);
	printf("one[5]=%3d,%c\n", one[5], one[5]);
}
#endif
#if 0 //111 1차원 배열의 포인터 사용하기
#include<stdio.h>
#include<string.h>

void main()
{
	char one[] = "Korea";
	char* pone;

	pone = one;

	puts(one);
	puts(pone);

	strcpy_s(pone, sizeof("japan"), "Japan");

	puts(one);
	puts(pone);
}
#endif
#if 0 //112 1차원 배열을 함수에서 사용하기
#include<stdio.h>

void print_one(char* pone);
void print_one2(char one[]);

void main()
{
	char one[] = "Korea";

	print_one(one);
	print_one2(one);
}

void print_one(char* pone)
{
	puts(pone);
}
void print_one2(char one[])
{
	puts(one);
}
#endif
#if 0 //113 2차원 배열 사용하기
#include<stdio.h>

void main()
{
	int i;
	int jumsu[100][3];
	int total[3] = { 0, };

	for (i = 0; i < 100; i++)
	{
		jumsu[i][0] = 92;
		jumsu[i][1] = 90;
		jumsu[i][2] = 95;
	}

	for (i = 0; i < 100; i++)
	{
		total[0] += jumsu[i][0];
		total[1] += jumsu[i][1];
		total[2] += jumsu[i][2];
	}

	printf("국어 점수의 총점:%d\n", total[0]);
	printf("영어 점수의 총점:%d\n", total[1]);
	printf("수학 점수의 총점:%d\n", total[2]);
}
#endif
#if 0 //114 2차원 배열의 포인터 사용하기
#include<stdio.h>

void main()
{
	int i;
	int jumsu[100][3];
	int total[3] = { 0, };
	int(*pjumsu)[3];

	pjumsu = jumsu;

	for (i = 0; i < 100; i++)
	{
		pjumsu[i][0] = 92;
		pjumsu[i][1] = 90;
		pjumsu[i][2] = 95;
	}
	for (i = 0; i < 100; i++)
	{
		total[0] = total[0] + pjumsu[i][0];
		total[1] = total[1] + pjumsu[i][1];
		total[2] = total[2] + pjumsu[i][2];
	}
	printf("국어 점수의 총점: %d\n",total[0]);
	printf("영어 점수의 총점: %d\n",total[1]);
	printf("수학 점수의 총점: %d\n",total[2]);
}
#endif
#if 0 //115 2차원 배열을 함수에서 사용하기
#include<stdio.h>
void calc(int(*pjumsu)[3], int* ptotal);

void main()
{
	int jumsu[100][3];
	int total[3] = { 0, };
	int(*pjumsu)[3];

	pjumsu = jumsu;

	calc(pjumsu, total);

	printf("국어 점수의 총점: %d\n", total[0]);
	printf("영어 점수의 총점: %d\n", total[1]);
	printf("수학 점수의 총점: %d\n", total[2]);
}
void calc(int(*pjumsu)[3], int* ptotal)
{
	int i;

	for (i = 0; i < 100; i++)
	{
		pjumsu[i][0] = 92;
		pjumsu[i][1] = 90;
		pjumsu[i][2] = 95;
	}

	for (i = 0; i < 100; i++)
	{
		ptotal[0] += pjumsu[i][0];
		ptotal[1] += pjumsu[i][1];
		ptotal[2] += pjumsu[i][2];
	}
}
#endif
#if 0 //116 3차원 배열 사용하기
#include<stdio.h>

void main()
{
	int i, j;
	int jumsu[10][100][3];
	int total[3] = { 0, };

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			jumsu[i][j][0] = 92;
			jumsu[i][j][1] = 90;
			jumsu[i][j][2] = 95;
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			total[0] += jumsu[i][j][0];
			total[1] += jumsu[i][j][1];
			total[2] += jumsu[i][j][2];
		}
	}
	printf("모든 반의 국어 점수의 총점:%d\n", total[0]);
	printf("모든 반의 영어 점수의 총점:%d\n", total[1]);
	printf("모든 반의 수학 점수의 총점:%d\n", total[2]);
}

#endif
#if 0 //117 3차원 배열의 포인터 사용하기
#include<stdio.h>
void main()
{
	int i, j;
	int jumsu[10][100][3];
	int total[3] = { 0, };
	int(*pjumsu)[100][3];

	pjumsu = jumsu;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			pjumsu[i][j][0] = 92;
			pjumsu[i][j][1] = 90;
			pjumsu[i][j][2] = 95;
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			total[0] += pjumsu[i][j][0];
			total[1] += pjumsu[i][j][1];
			total[2] += pjumsu[i][j][2];
		}
	}
	printf("모든 반의 국어 점수의 총점:%d\n", total[0]);
	printf("모든 반의 영어 점수의 총점:%d\n", total[1]);
	printf("모든 반의 수학 점수의 총점:%d\n", total[2]);
}
#endif
#if 0 //118 3차원 배열을 함수에서 사용하기
#include<stdio.h>

void calc(int(*pjumsu)[100][3], int* ptotal);

void main()
{
	int jumsu[10][100][3];
	int total[3] = { 0, };

	calc(jumsu, total);

	printf("모든 반의 국어 점수의 총점:%d\n", total[0]);
	printf("모든 반의 영어 점수의 총점:%d\n", total[1]);
	printf("모든 반의 수학 점수의 총점:%d\n", total[2]);
}
void calc(int(*pjumsu)[100][3], int* ptotal)
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			pjumsu[i][j][0] = 92;
			pjumsu[i][j][1] = 90;
			pjumsu[i][j][2] = 95;
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			ptotal[0] += pjumsu[i][j][0];
			ptotal[1] += pjumsu[i][j][1];
			ptotal[2] += pjumsu[i][j][2];
		}
	}	
}
#endif
#if 0 //119 구조체 사용하기
#include<stdio.h>
#include<string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};
void main()
{
	struct tagAddress ad;

	strcpy_s(ad.name, sizeof(ad.name), "홓길동");
	strcpy_s(ad.phone, sizeof(ad.phone), "02-1234-5678");
	strcpy_s(ad.address, sizeof(ad.address), "서울시 영천구 목동아파트 13단지");

	printf("이름:%s\n", ad.name);
	printf("전화:%s\n", ad.phone);
	printf("전화:%s\n",ad.address);
}
#endif
#if 0 //120 구조체 포인터 사용하기
#include<stdio.h>
#include<string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};
void main()
{
	struct tagAddress ad;
	struct tagAddress* pad;

	pad = &ad;

	strcpy_s((*pad).name, sizeof((*pad).name), "홓길동");
	strcpy_s((*pad).phone, sizeof((*pad).phone), "02-1234-5678");
	strcpy_s((*pad).address, sizeof((*pad).address), "서울시 영천구 목동아파트 13단지");

	printf("이름:%s\n", pad->name);
	printf("전화:%s\n", pad->phone);
	printf("전화:%s\n", pad->address);
}
#endif
#if 0 //121 구조체를 함수에서 사용하기
#include<stdio.h>
#include<string.h>

void print(struct tagAddress* pad);

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};

void main()
{
	struct tagAddress ad;

	strcpy_s(ad.name, sizeof(ad.name), "홓길동");
	strcpy_s(ad.phone, sizeof(ad.phone), "02-1234-5678");
	strcpy_s(ad.address, sizeof(ad.address), "서울시 영천구 목동아파트 13단지");
	print(&ad);
}
void print(struct tagAddress *pad)
{
	printf("이름:%s\n", pad->name);
	printf("전화:%s\n", pad->phone);
	printf("전화:%s\n", pad->address);
}
#endif
#if 0 //122 구조체 배열 사용하기
#include<stdio.h>
#include<string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};
void main()
{
	struct tagAddress ad[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		sprintf_s(ad[i].name,sizeof(ad[i].name), "홍길동%d", i);
		strcpy_s(ad[i].phone,sizeof(ad[i].phone), "02-1234-5678");
		strcpy_s(ad[i].address,sizeof(ad[i].address), "서울시 양천구 목동아파트 13단지");
	}
	for (i = 0; i < 3; i++)
	{
		printf("이름:%s\n", ad[i].name);
		printf("전번:%s\n", ad[i].phone);
		printf("주소:%s\n", ad[i].address);
	}
}
#endif
#if 0 //123 구조체 배열 포인터 사용하기
#include<stdio.h>
#include<string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};

void main()
{
	struct tagAddress ad[3];
	struct tagAddress* pad;
	int i;

	pad = ad;

	for (i = 0; i < 3; i++)
	{
		sprintf_s(pad[i].name, sizeof(pad[i].name), "홍길동%d", i);
		strcpy_s(pad[i].phone, sizeof(pad[i].phone),"02-9112-4545");
		strcpy_s(pad[i].address, sizeof(pad[i].address), "서울 노원구 석계로15길");
			
	}
	for (i = 0; i < 3; i++)
	{
		printf("이름: %s\n", pad[i].name);
		printf("전번: %s\n", pad[i].phone);
		printf("주소: %s\n", pad[i].address);
	}
}
#endif
#if 0 //124 구조체 배열을 함수에서 사용하기
#include<stdio.h>
#include<string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];

};

void print(struct tagAddress* pad);

void main()
{
	struct tagAddress ad[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		sprintf_s(ad[i].name, sizeof(ad[i].name), "박재희%d", i);
		strcpy_s(ad[i].phone, sizeof(ad[i].phone), "010-3933-2828");
		strcpy_s(ad[i].address, sizeof(ad[i].address), "서울 노원구 석계로15길");

	}
	print(ad);
}
void print(struct tagAddress* pad)
{
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("이름:%s\n", pad[i].name);
		printf("전화:%s\n", pad[i].phone);
		printf("주소:%s\n", pad[i].address);
	}
}
#endif
#if 0 //125 구조체의 길이를 구하고 초기화하기
#include<stdio.h>
#include<string.h>
struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];

};
typedef struct tagAddress addr;

void main()
{
	addr ad;
	int len;

	len = sizeof(addr);

	printf("구조체 addr의 크기:%d\n", len);

	memset(&ad, 0, len);
}
#endif
#if 0 //126 공용체 사용하기
#include<stdio.h>

typedef union tagVariable
{
	int i;
	double d;
}VA;

void main()
{
	VA va;
	va.i = 5;
	printf("va.i 공용체의 값: %d\n", va.i);

	va.d = 3.14;

	printf("va.d 공용체의 값: %f\n", va.d);
	printf("va.i 공용체의 값: %d\n", va.i);
}
#endif
#if 0 //127 공용체 함수에서 사용하기
#include<stdio.h>
typedef union tagVariavle
{
	int i;
	double d;
}VA;

void print(VA* pva);

void main()
{
	VA va;

	print(&va);
}
void print(VA* pva)
{
	pva->i = 5;

	printf("pva->i 공용체의 값:%d\n", pva->i);

	pva->d = 3.14;

	printf("pva->d 공용체의 값: %f\n", pva->d);
	printf("pva->i 공용체의 값: %d\n", pva->i);
}
#endif
#if 0 //128 void형 포인터 사용하기
#include<stdio.h>

void main()
{
	int i;
	double d = 3.14;

	int* pi;
	double* pd;
	void* pv;

	pi = &i;
	pd = &d;
	pi = &d;
	pv = &i;
	pv = &d;

	printf("실수 값 d:%f\n", *(double*)pv);
}
#endif
#if 0 //129 void형 포인터를 함수에서 사용하기
#include<stdio.h>
#include<string.h>

typedef struct tagPoint
{
	int x;
	int y;
}point;

void My_memset(void* dest, int c, unsigned count);

void main(void)
{
	point pt = { 5,10 };
	char array[10];

	printf("x,y: %d, %d\n", pt.x, pt.y);

	My_memset(&pt, 0, sizeof(pt));

	printf("x,y : %d, %d\n", pt.x, pt.y);

	My_memset(array, 48, sizeof(array));

	printf("array[0] ~ array[9]:%c ~ %c\n", array[0], array[9]);
}

void My_memset(void* dest, int c, unsigned count)
{
	while (count--)
	{
		*(char*)dest = c;
		dest = (char*)dest + 1;
	}
}
#endif
#if 0 //130 포인터의 포인터 사용하기
#include<stdio.h>

void main()
{
	char* animal[3];
	char** ppanimal;

	animal[0] = "호랑이";
	animal[1] = "사자";
	animal[2] = "토끼";

	ppanimal = animal;

	puts(animal[0]);
	puts(ppanimal[1]);
	puts(ppanimal[2]);

}
#endif
#if 0 //131 포인터의 포인터를 함수에서 사용하기
#include<stdio.h>
void print(char** ppanimal);

void main()
{
	char* animal[3];

	animal[0] = "호랑이";
	animal[1] = "사자";
	animal[2] = "토끼";

	print(animal);
}

void print(char** ppanimal)
{
	puts(ppanimal[0]);
	puts(ppanimal[1]);
	puts(ppanimal[2]);
}
#endif
#if 0 //132 함수 포인터 사용하기
#include<stdio.h>
#include<string.h>

void main()
{
	int(*myfunc)(const char*);

	myfunc = puts;

	puts("올챙이가 쑥~.~");
	myfunc("뒷다리가 쭉~.~");

	myfunc = strlen;

	printf("문자열의 길이:%d\n", strlen("aa"));
	printf("문자열의 길이:%d\n", myfunc("aa"));
}
#endif
#if 0 //133 함수 포인터를 배열에서 사용하기
#include<stdio.h>
#include<string.h>
void main()
{
	int(*myfunc[3])(const char*);

	myfunc[0] = puts;
	myfunc[1] = strlen;
	myfunc[2] = myfunc[1];

	puts("올챙이가 쑥~.~");
	myfunc[0]("뒷다리가 쭉~.~");


	printf("문자열의 길이:%d\n", strlen("aa"));
	printf("문자열의 길이:%d\n", myfunc[1]("aa"));
	printf("문자열의 길이:%d\n", myfunc[2]("aa"));
}
#endif
#if 0 //134 함수 포인터를 함수에서 사용하기
#include<stdio.h>
#include<string.h>

void print1(int(*X)(const char*));
void print2(int(*X[2])(const char*));

void main()
{
	int (*myfunc[2])(const char*);

	myfunc[0] = puts;
	myfunc[1] = strlen;

	print1(myfunc[0]);
	print2(myfunc);
}
void print1(int(*X)(const char*))
{
	X("올챙이가 쑥!");
}
void print2(int(*X[2])(const char*))
{
	X[0]("뒷다리가 쭉!");
	printf("문자열의 길이: %d\n", X[1]("aa"));
}
#endif
#if 0 //135 main() 함수 원형 사용하기
#include<stdio.h>

int main(int argc, int* argv[])
{
	int i;

	printf("인수의 수:%d\n", argc);

	for (i = 0; i < argc;i++)
	{
		printf("argc[%d]: %s\n", i, argv[i]);
	}
}
#endif
#if 0 //136 파일 생성하기(fopen)
#include<stdio.h>
void main()
{
	FILE* file;
	fopen_s(&file,"D:\\C_code\\file.txt", "w+");
	if (file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		puts("파일이 정상적으로 생성되었습니다.");
		fclose(file);
	}
}
#endif
#if 0 //137 파일에 한 문자 쓰기(fputc)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void main()
{
	FILE* fp;
	fp= fopen("D:\\C_code\\file.txt", "w+");
	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fputs("A", fp);
		puts("문자 'A'를 파일에 저장했다.");
		fclose(fp);
	}
}
#endif
#if 0 //138 파일에서 한 문자 읽기(fgetc)
#include<stdio.h>
void main()
{
	FILE* fp;
	int ch;

	fopen_s(&fp,"D:\\C_code\\file.txt", "r");
	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		ch = fgetc(fp);
		printf("읽은 문자:%c \n", ch);
		fclose(fp);
	}
}
#endif
#if 0 //139 파일에 문자열 쓰기(fputs)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fputs("대한민국\n짝작\n", fp);
		fclose(fp);
	}
}
#endif
#if 0 //140 파일에서 문자열 읽기(fgets)
#include<stdio.h>
void main()
{
	FILE* fp;
	char buffer[100];

	fopen_s(&fp, "D:\\C_code\\file.txt", "r");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fgets(buffer, 100, fp);//개행문자를 만나면 그만읽음.
		puts(buffer);
		fclose(fp);
	}
}
#endif
#if 0 //141 파일에 형식화된 문자열 쓰기(fprintf)
#include<stdio.h>
void main()
{
	FILE* fp;
	int i = 12345;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fprintf(fp, "%d", i);
		fclose(fp);
	}

}
#endif
#if 0 //142 파일에서 형식화된 문자열 읽기(fscanf)
#include<stdio.h>
void main()
{
	FILE* fp;
	int i;

	fopen_s(&fp, "D:\\C_code\\file.txt", "r");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fscanf_s(fp, "%d", &i);
		//fscanf(fp, "%d", &i);
		printf("i=%d\n", i);
		fclose(fp);
	}
}
#endif
#if 1 //143 