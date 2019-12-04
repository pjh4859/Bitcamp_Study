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
#if 0 //143 파일의 버퍼 비우기(fflush)
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
		fputs("대한민국rr", fp);
		fflush(fp);
		fclose(fp);
	}
}
#endif
#if 0 //144 파일 포인터의 현재 위치 구하기 1(ftell)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다");
	}
	else
	{
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fputs("abcdaksjhdfjkdsjf", fp);
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //145 파일 포인터를 처음으로 이동하기 1(fseek)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");
	
	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다");
	}
	else
	{
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fputs("abcdaksjhdfjkdsjf", fp);
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fseek(fp, 0L, SEEK_SET);
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //146 파일 포인터를 처음으로 이동하기 2(rewind)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다");
	}
	else
	{
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fputs("abcdaksjhdfjkdsjf", fp);
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		rewind(fp);
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //147 파일 포인터를 끝으로 이동하기(fseek)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다");
	}
	else
	{
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fputs("abcdaksjhdfjkdsjf", fp);
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		rewind(fp);
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fseek(fp, 0L, SEEK_END);
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //148 파일 포인터를 임의의 위치로 이동하기(fseek)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다");
	}
	else
	{
		fputs("abcdaksjhdfjkdsjf", fp);
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fseek(fp, -2L, SEEK_CUR);
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //148(2) 파일 포인터를 임의의 위치로 이동하기(fseek)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "a+");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다");
	}
	else
	{
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fseek(fp, 0L, SEEK_END);
		fputs("재재보고싶다", fp);
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //149 파일의 길이 구하기(fseek)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "r");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다");
	}
	else
	{
		fseek(fp, 0L, SEEK_END);
		printf("파일의 길이:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //150 파일 포인터의 현재 위치 구하기2(fgetpos)
#include<stdio.h>
void main()
{
	FILE* fp;
	fpos_t pos;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다");
	}
	else
	{
		fputs("재재야 보고싶다.", fp);
		fgetpos(fp, &pos);
		printf("파일 포인터의 위치:%d\n", pos);
		fclose(fp);
	}
}
#endif
#if 0 //151 파일 포인터의 현재 위치 설정하기(fsetpos)
#include<stdio.h>
void main()
{
	FILE* fp;
	fpos_t pos;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다");
	}
	else
	{
		fgetpos(fp, &pos);
		fputs("재재융.", fp);
		fsetpos(fp, &pos);
		printf("파일 포인터의 위치:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //152 파일 닫기(fclose)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	fputs("fclose() 함수", fp);
	fclose(fp);
	_fcloseall();
}
#endif
#if 0 //153 파일의 끝에 도달했는지 검사하기(feof)
#include<stdio.h>

void main()
{
	FILE* fp;
	int ch;

	fopen_s(&fp, "D:\\C_code\\file.txt", "r");
	
	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다");
	}
	else
	{
		while(!feof(fp))
		{
			ch = fgetc(fp);
			printf("읽은 문자: %c\n", ch);
		}
		fclose(fp);
	}
}
#endif
#if 0 //154 파일 읽기/쓰기 시 에러 검사하기(ferror)
#include<stdio.h>

void main()
{
	FILE* fp;
	int ch;

	fopen_s(&fp, "D:\\C_code\\file.txt", "r");

	if (fp == NULL)
	{
		puts("파일을 생성할 수 없습니다");
	}
	else
	{
		while (!feof(fp))
		{
			ch = fgetc(fp);
			if (ferror(fp))
			{
				puts("파일읽는데 에러임.");
			}
			printf("읽은 문자: %c\n", ch);
		}
		fclose(fp);
	}
}
#endif
#if 0 //155 파일 처리 시 발생된 에러 표시하기(perror)
#include<stdio.h>

void main()
{
	FILE* fp;
	int ch;

	fopen_s(&fp, "D:\\C_code\\file2.txt", "r");

	if (fp == NULL)
	{
		perror("파일 개방 에러");
	}
	else
	{
		while (!feof(fp))
		{
			ch = fgetc(fp);
			if (ferror(fp))
			{
				perror("파일 읽기 에러");
			}
			printf("읽은 문자: %c\n", ch);
		}
		fclose(fp);
	}
}
#endif
#if 0 //156 임시 파일 이름 만들기(tmpnam)
#include<stdio.h>
void main()
{
	int i;
	char buffer[500];
	char* path;

	for (i = 0; i < 10; i++)
	{
		tmpnam_s(buffer,sizeof(buffer));
	//	tmpnam(buffer);
		puts(buffer);
	}
	for (i = 0; i < 10; i++)
	{
		path = _tempnam("", "test");
		puts(path);
	}
}
#endif
#if 0 //157 파일이 존재하는지 확인하기(_access)
#include<stdio.h>
#include<io.h>

void main()
{
	char* path = "D:\\C_code\\file.txt";

	if (_access(path, 0) == 0)
		puts("해당 경로에 파일이 존재합니다.");
}
#endif
#if 0 //158 파일 이름 변경하기(rename)
#include<stdio.h>
void main()
{
	char*oldname= "D:\\C_code\\file.txt";
	char*newname= "D:\\C_code\\file2.txt";

	if (rename(oldname, newname) != 0)
	{
		perror("파일명 변경 에러");
	}
	else
	{
		puts("파일명 변경함.");
	}
}
#endif
#if 0 //159 파일 이름 변경하기(_chmod)
#include<stdio.h>
#include<io.h>
#include<sys/stat.h>
void main()
{
	char* filename = "D:\\C_code\\file2.txt";

	if (_chmod(filename,_S_IREAD) != 0)//읽기전용
	{
		perror("파일 속성 설정 에러");
	}
	else
	{
		puts("파일속성을 변경함.");
	}
}
#endif
#if 0 //160 파일 삭제하기(remove)
#include<stdio.h>

void main()
{
	char* filename = "D:\\C_code\\file2.txt";

	if (remove(filename))//읽기전용
	{
		perror("파일 삭제 에러");
	}
	else
	{
		puts("파일을 성공적으로 삭제함.");
	}
}
#endif
#if 0 //161 디렉터리 생성하기(_mkdir)
#include<stdio.h>
#include<direct.h>
void main()
{
	char* pathname = "D:\\C_code\\files";

	if (_mkdir(pathname)==-1)//읽기전용
	{
		perror("디렉터리 생성 에러");
	}
	else
	{
		puts("디렉터리를 성공적으로 생성함.");
	}
}
#endif
#if 0 //162 디렉터리 삭제하기(_rmdir)
#include<stdio.h>
#include<direct.h>
void main()
{
	char* pathname = "D:\\C_code\\files";

	if (_rmdir(pathname) == -1)//읽기전용
	{
		perror("디렉터리 삭제 에러");
	}
	else
	{
		puts("디렉터리를 성공적으로 삭제함.");
	}
}
#endif
#if 0 //163 현재 작업중인 디렉터리 구하기(_getcwd)
#include<stdio.h>
#include<stdlib.h>
#include<direct.h>
void main()
{
	char pathname[_MAX_PATH];

	_getcwd(pathname, _MAX_PATH);

	puts(pathname);
}
#endif
#if 0 //164 현재 작업중인 디렉터리 변경하기(_chdir)
#include<stdio.h>
#include<stdlib.h>
#include<direct.h>
void main()
{
	char pathname[_MAX_PATH]="D:\\C_code";;

	if (_chdir(pathname) == 0)
	{
		_getcwd(pathname, _MAX_PATH);
		puts(pathname);
	}
}
#endif
#if 0 //165 현재 작업중인 드라이브 구하기(_getdrive)
#include<stdio.h>
#include<direct.h>
void main()
{
	int drive;

	drive = _getdrive();
	printf("현재 드라이브 : %c\n", 'A' + drive - 1);
}
#endif
#if 0 //166 현재 작업중인 드라이브 변경하기(_chdrive)
#include<stdio.h>
#include<direct.h>
void main()
{
	int drive=2;

	if (_chdrive(drive) == 0)
	{
		drive = _getdrive();
		printf("변경된 드라이브 : %c\n", 'A' + drive - 1);
	}
}
#endif
#if 0 //167 표준 입,출력 스트림 사용하기(stdin, stdout)
#include<stdio.h>
void main()
{
	printf("산은 산이요~물은물이로다...");
}
#endif
#if 0 //168 현재까지 경과된 초의 수 구하기(time)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	time(&now);
	printf("1970년 1월 1일부터 경과된 초:%d\n", now);
}
#endif
#if 0 //169 날짜 및 시간 구하기 1(localtime)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	struct tm t;

	time(&now);
	
	//t = *localtime(&now);
	localtime_s(&t,&now);

	printf("현재 날짜 및 시간:%4d.%d.%d.%d:%d:%d\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);
}
#endif
#if 0 //170 날짜 및 시간 구하기 2(_ftime)
#include<stdio.h>
#include<time.h>
#include<sys/timeb.h>

void main()
{
	struct _timeb tb;
	struct tm t;
	//_ftime_s;
	_ftime_s(&tb);

	localtime_s(&t,&tb.time);

	printf("현재 날짜 및 시간:%4d.%d.%d.%d:%d:%d.%d\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec,tb.millitm);
}
#endif
#if 0 //171 세계 표준 시 구하기(gmtime)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	struct tm t;

	time(&now);

	gmtime_s(&t, &now);

	printf("세계 표준 시: %4d.%d.%d %d:%d:%d \n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);
}
#endif
#if 0 //172 날짜 및 시간을 문자열로 변환하기(ctime)
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)

void main()
{
	time_t now;

	time(&now);

	printf("현재 날짜 및 시간: %s", ctime( &now));
}
#endif
#if 0 //173 날짜 및 시간을 더하거나 빼기(mktime)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	struct tm t;

	time(&now);
	localtime_s(&t, &now);
	t.tm_mday += 100;
	mktime(&t);

	printf("현재 날짜에 100일을 더한 날짜: %4d.%d.%d %d:%d:%d \n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);
}
#endif
#if 0 //174 날짜 및 시간의 차이 구하기(difftime)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t s1, s2;
	double gap=0;
	int i;

	time(&s1);

	for (i = 0; i < 1000000000; i++)
	{
		gap = gap * 100;
	}

	time(&s2);
	printf("경과시간: %g초\n", difftime(s2, s1));
}
#endif
#if 0 //175 날짜 및 시간을 미국식으로 변환하기(asctime)
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)
void main()
{
	time_t now;
	struct tm t;

	now = time(NULL);
	localtime_s(&t, &now);

	printf("현재 날짜 및 시간: %s\n", asctime(&t));
}
#endif
#if 0 //176 날짜 및 시간을 형식화하기(strftime)
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)
void main()
{
	time_t now;
	struct tm t;
	char buff[100];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "%Y-%m-%d %I:%M:%S %p", &t);
	puts(buff);
}
#endif
#if 0 //177 삼각 함수 싸인 값 구하기(sin)
#include<stdio.h>
#include<math.h>

void main()
{
	double x;
	x = sin((3.14/6));//rad

	printf("sin(1):%g\n", x);
}
#endif
#if 0 //178 삼각 함수 아크 싸인 값 구하기(asin)
#include<stdio.h>
#include<math.h>

void main()
{
	double x,y;
	x = asin(1);//rad
	y = sin(1.57);//rad

	printf("asin():%g//%g\n", x,y);
}
#endif
#if 0 //179 삼각 함수 x/y에 대한 아크 탄젠트 값 구하기(atan2)
#include<stdio.h>
#include<math.h>

void main()
{
	double x,y;
	x = atan2(1.0,1.0);
	y = tan(1.0,1.0);

	printf("atan2:%g, %g\n", x,y);
}
#endif
#if 0 //180 지수 함수 지수값 구하기(exp)
#include<stdio.h>
#include<math.h>

void main()
{
	double x, y;
	x = exp(1.0);
	y = exp(2.0);

	printf("exp:%g, %g\n", x, y);
}
#endif
#if 0 //181 로그 함수 자연 로그값 구하기(log)
#include<stdio.h>
#include<math.h>

void main()
{
	double x, y;
	x = log(1.0);
	y = log(2.0);

	printf("log:%g, %g\n", x, y);
}
#endif
#if 0 //182 로그 함수 밑수를 10으로 하는 로그값 구하기(log10)
#include<stdio.h>
#include<math.h>

void main()
{
	double x, y;
	x = log10(1.0);
	y = log10(2.0);

	printf("log10:%g, %g\n", x, y);
}
#endif
#if 0 //183 제곱근 구하기(sqrt)
#include<stdio.h>
#include<math.h>

void main()
{
	double x, y;
	x = sqrt(16.0);
	y = sqrt(4.0);

	printf("sqrt:%g, %g\n", x, y);
}
#endif
#if 0 //184 절대값 구하기(abs)
#include<stdio.h>
#include<math.h>

void main()
{
	double x, y;
	x = abs(1.0);
	y = abs(-2.0);

	printf("abs:%g, %g\n", x, y);
}
#endif
#if 0 //185 주어진 값보다 작지 않은 최소 정수값 구하기(ceil)
#include<stdio.h>
#include<math.h>

void main()
{
	printf("ceil(1.0) : %g\n", ceil(1.0));
	printf("ceil(1.1) : %g\n", ceil(1.1));
	printf("ceil(1.9) : %g\n", ceil(1.9));
	printf("ceil(2.5) : %g\n", ceil(2.5));
	printf("ceil(-2.5) : %g\n", ceil(-2.5));
	printf("ceil(-3.0) : %g\n", ceil(-3.0));
}
#endif
#if 0 //186 주어진 값보다 크지 않은 최소 정수값 구하기(floor)
#include<stdio.h>
#include<math.h>

void main()
{
	printf("floor(1.0) : %g\n", floor(1.0));
	printf("floor(1.1) : %g\n", floor(1.1));
	printf("floor(1.9) : %g\n", floor(1.9));
	printf("floor(2.5) : %g\n", floor(2.5));
	printf("floor(-2.5) : %g\n",floor(-2.5));
	printf("floor(-3.0) : %g\n",floor(-3.0));
}
#endif
#if 0 //187 주어진 값을 정수와 소수로 분리하기(modf)
#include<stdio.h>
#include<math.h>
void main()
{
	double x = 2.3, n, y;

	y = modf(x, &n);

	printf("2.3을 정수와 소수로 분리하면, %g 와 %g 입니다.\n", n, y);
}
#endif
#if 0 //188 x의 y승 구하기(pow)
#include<stdio.h>
#include<math.h>
void main()
{
	double x = 10.0, y=3.0,r;

	r = pow(x, y);
	printf("10^3= %g \n", r);
}
#endif
#if 0 //189 난수 구하기(srand,rand)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < 5; i++)
	{
		printf("난수%d: %d\n",i, rand()%1500+1);
	}	
}
#endif
#if 0 //190 숫자 정렬하기(qsort)
#include<stdio.h>
#include<stdlib.h>

int intcmp(const void* v1, const void* v2);

void main()
{
	int i;
	int arr[5] = { 1,3,5,4,2 };

	qsort(arr, 5, sizeof(arr[0]), intcmp);

	for (i = 0; i < 5; i++)
	{
		printf("%d", arr[i]);
	}
}
int intcmp(const void* v1, const void* v2)
{
	int cmpvalue1, cmpvalue2;

	cmpvalue1 = *(int*)v1;
	cmpvalue2 = *(int*)v2;

	return cmpvalue1 - cmpvalue2;
}
#endif
#if 0 //191 이진 검색 사용하기(bsearch)
#include<stdio.h>
#include<stdlib.h>
#include<search.h>

int intcmp(const void* v1, const void* v2);

void main()
{
	int key = 5, * ptr;
	int array[10] = { 150,27,33,1,5,100,99,75,81,10 };
	qsort(array,10,sizeof(array[0]),intcmp);
	ptr = bsearch(&key, array, 10, sizeof(array[0]), intcmp);

	if (ptr)
	{
		puts("5를 찾았습니다.");
	}
}
int intcmp(const void* v1, const void* v2)
{
	return(*(int*)v1 - *(int*)v2);
}
#endif
#if 0 //192 매크로 상수 정의하기
#include<stdio.h>

#define program void main(void)
#define println printf

#define MAX 1000
#define MIN 0

program
{
	println("MAX:%d,MIN:%d\n",MAX,MIN);
}
#endif
#if 0 //193 매크로 함수 정의하기1
#include<stdio.h>

#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
void main()
{
	printf("최대값: %d\n", max(5, 3));
	printf("최소값: %d\n", min(5, 3));
	printf("최대값: %g\n", max(3.5, 4.4));
	printf("최소값: %g\n", min(3.5, 4.4));
}
#endif
#if 0 //194 매크로 함수 정의하기2
#include<stdio.h>

#define x_i(x,i) printf("x%s의 값은 %d입니다.\n",#i,x##i)

void main()
{
	int xa = 3, xb = 5;

	x_i(x, a);
	x_i(x, b);
}
#endif
#if 0 //195 매크로 상수가 선언되었는지 검사하기
#include<stdio.h>

//#define COUNT 100

#if !defined COUNT
#define COUNT 90
#endif
void main()
{
	printf("COUNT: %d\n", COUNT);
}
#endif
#if 0 //196 매크로 컴파일 에러 출력하기
#include<stdio.h>

//#define COUNT 100
#if !defined COUNT
#error"COUNT MACRO is not defined!"
#endif

void main()
{
	printf("COUNT:%d\n", COUNT);
}
#endif
#if 0 //197 매크로 상수의 값을 검사하기
#include<stdio.h>

#define COUNT 100

#if COUNT !=100
#error "COUNT !=100"
#endif
void main()
{
	printf("COUNT:%d\n", COUNT);
}
#endif
#if 0 //198 매크로 상수의 선언을 취소하기
#include<stdio.h>

#define COUNT 100

#if defined COUNT
#undef COUNT
#define COUNT 99
#else
#define COUNT 88
#endif

void main()
{
	printf("COUNT:%d\n", COUNT);
}
#endif
#if 0 //199 경고 에러를 발생시키지 않기
#include<stdio.h>
#pragma warning(disable:4101)
void main()
{
	int i;
}
#endif
#if 0 //200 내장된 매크로 사용하기
#include<stdio.h>
void main()
{
	printf("파일명:%s\n", __FILE__);
	printf("날 짜:%s\n", __DATE__);
	printf("시 간:%s\n", __TIME__);
	printf("줄 수:%d\n", __LINE__);
}
#endif