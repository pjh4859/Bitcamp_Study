#include <stdio.h>




#if 0 //001 C 프로그램 시작하기.
int main()
{
	printf("안녕하셈.");
}
#endif

#if 0 //002 변수형 개념 배우기.
int main()
{
	int ㅣㅣㅣllㅣIIII;
	int x;
	int y;
	int z;

	ㅣㅣㅣllㅣIIII = 20;
	x = 1;
	y = 2;

	z = x + y;

	printf("%d %d",z, ㅣㅣㅣllㅣIIII);
}
#endif

#if 0 //003 상수형 개념 배우기.

#define X 1
#define PI 3.141592

int main()
{
	double z;

	z = X + PI;
	printf("%f", z);
}
#endif

#if 0 //004 연산자 개념 배우기.
main()
{
	int x;
	int y;
	x = 10;
	y = x - 5;
	if (x > y)
	{
		printf("x가 y보다 큽니다.");
	}
	else
	{
		printf("y가 x와 같거나 작습니다.");
	}
}

#endif

#if 0//005 조건문 개념 배우기 (if~else).
main()
{
	int x;
	int y;

	x = 20;
	y = 10;

	if (x > y)
		printf("x value is bigger than y.");
	else
		printf("y value is bigger or same than x.");

}

#endif

#if 0 //006 순환문 개념 배우기(for).
main()
{
	int i;
	int hap = 0;

	for (i = 0; i <= 10; i = i + 1)
	{
		hap = hap + i;
	}
	printf("1부터 10까지의 합: %d", hap);
}
#endif

#if 0 //007 문자열 개념 배우기.
main()
{
	printf("대한민국");	
}
#endif

#if 0 //009 함수 개념 배우기.
int hapf(int value);

main()
{
	printf("1부터 10까지의 합은 %d \n", hapf(10));
	printf("1부터 100까지의 합은 %d \n", hapf(100));
	printf("1부터 1000까지의 합은 %d \n", hapf(1000));
}
int hapf(int value)
{
	int i;
	int hap = 0;

	for (i = 0; i <= value; i = i + 1)
	{
		hap = hap + i;
	}
	return hap;
}
#endif

#if 0 //010 주석 개념 배우기.
main()
{
	int i;	//정수형 변수 i를 정의합니다.
	int hap = 0;  //정수형 변수 hap 을 정의하고 0으로 초기화합니다.

	/*
	for 문은 다음처럼 실행됩니다.

	1.i=0으로 시작합니다.ㅣ
	2.i가 10보다 작거나 같을때까지 반복합니다.
	3.현재의 hap값에 i를 더하여 hap 에 대입.
	4.i는 1씩 증가합니다.
	*/

	for (i = 0; i <= 10; i = i + 1)
	{
		hap = hap + i;
	}
	printf("%d", hap);
}
#endif

#if 0 //011 문자형 변수 이해하기(char).
main()
{
	char ch;
	unsigned char j;
	char k;

	ch = 200;
	j = 200;
	k = 'a';

	printf("문자형 변수 ch의 값은 %d\n", ch);
	printf("문자형 변수 j의 값은 %d\n", j);
	printf("문자형 변수 k의 값은 %d\n", k);
}
#endif

#if 0 //012 정수형 변수 이해하기(int).
main()
{
	int i;
	unsigned int j;
	int k;

	i = 2000000000;
	j = 4000000000;
	k = 'b';

	printf("정수형 변수 i의 값은 %d\n", i);
	printf("정수형 변수 j의 값은 %u\n", j);
	printf("정수형 변수 k의 값은 %d\n", k);
}
#endif

#if 0 //013 실수형 변수 이해하기(double).
main()
{
	float d;
	double d1;
	double d2;

	d = 3.141592;
	d1 = 1234567890;
	d2 = 'c';

	printf("실수형 변수 d의 값은 %E\n", d);
	printf("실수형 변수 d1의 값은 %E\n", d1);
	printf("실수형 변수 d2의 값은 %E\n", d2);
}
#endif

#if 0 // 014 논리형 변수 이해하기(bool).
main()
{
	int b;
	int j;

	b = 10 > 5;
	j = 10 > 20;

	printf("논리형 변수 b의 값은 %d\n", b);
	printf("논리형 변수 j의 값은 %d\n", j);

	if (b) //참
	{
		printf("10>5의 식은 참입니다.\n");
	}
	else
	{
		printf("10>5의 식은 거짓입니다.\n");
	}
	if (j) //거짓
	{
		printf("10>20의 식은 참입니다.\n");
	}
	else
	{
		printf("10>20의 식은 거짓입니다.\n");
	}
	if (-1) //참
	{
		printf("-1은 참입니다.\n");
	}
	else
	{
		printf("-1은 거짓입니다.\n");
	}
}
#endif

#if 0 //015 문자열형 변수 이해하기(char*).
main()
{	char str[] = "대한민국";
	char* j = "I love Korea";

	printf("문자열형 변수 str의 값은 %s\n", str);
	printf("문자열형 변수 j의 값은 %s\n", j);
}

#endif

#if 0 //016 문자형 상수 이해하기(char)

#define HUNDRED 100
const char j = 10;
main()
{
	HUNDRED = 200;	//에러 발생
	j = 200;		//에러 발생

	printf("문자형 상수 HUNDRED의 값은 %d\n", HUNDRED);
	printf("문자형 상수 j의 값은 %d\n", j);

}
#endif

#if 0 //017 정수형 상수 이해하기(int)

main()
{
	int i, j;
	int a[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	int* p = a;
	int* p2 = a[0];
	int(* p3)[5] = a;
	int* p4 = &a;
	int(* p5)[3][5] = &a;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("%d %d %d %d %d\n", p, p2,p3, p4,p5);
	printf("%d %d %d %d %d\n", sizeof(p), sizeof(p2), sizeof(p3), sizeof(p4), sizeof(p5));
	printf("%d %d %d %d %d\n", (p), (p2), p3,(p4),p5);
	printf("%d %d %d %d %d\n", (p+1), (p2+1),(p3+1), (p4+1),(p5+1));
}
#endif

#if 0 //017 정수형 상수 이해하기(int)
#include<stdio.h>
#define HUNDRED_THOUSAND 100000

const int j = 200000;
main()
{
	//HUNDRED_THOUSAND = 100000;	//에러 발생
	//j = 200000;	//에러 발생

	printf("정수형 상수 HUNDRED_THOUSAND의 값은 %d\n", HUNDRED_THOUSAND);
	printf("정수형 상수j의 값은 %d\n", j);
}
#endif
#if 0 //018 실수형 상수 이해하기(double)
#include<stdio.h>
#define PI 3.141592

const double j = 1.23456789;

main()
{
	//PI = 3.141592; //에러 발생
	//j = 1.23456789; //Error occured

	printf("실수형 상수 PI의 값은%f\n", PI);
	printf("실수형 상수 j의 값은%f\n", j);
}
#endif
#if 0 //019 논리형 상수 이해하기(bool)
#include<stdio.h>

#define TRUE 1
#define FALSE 0

main()
{
	if (TRUE)
	{
		printf("TRUE의 값은 참입니다.\n");
	}
	else
	{
		printf("TRUE의 값은 거짓입니다.\n");
	}
	if (FALSE)
	{
		printf("FALSE의 값은 참입니다.\n");
	}
	else
	{
		printf("FALSE의 값은 거짓입니다.\n");
	}
}
#endif

#if 0 //020 문자열형 상수 이해하기(char)
#include<stdio.h>

#define KOREA "대한민국"
#define BOOK "This is a book."

const char* SOCCER = "나는 축구를 좋아합니다.";

main()
{
	printf("문자열의 상수	KOREA의 값:%s \n", KOREA);
	printf("문자열의 상수	 BOOK의 값:%s \n", BOOK);
	printf("문자열의 상수  SOCCER의 값:%s \n", SOCCER);
}

#endif

#if 0 //021 대입 연상자 이해하기(=)
#include<stdio.h>

main()
{
	int x = 1;
	int y = 2;
	int  z;
	int zz;

	z = x + y;

	zz = printf("z의 값:%d\n", z);
	printf("zz의 값:%d\n", zz);
}
#endif

#if 0 //022 부호 연산자 이해하기(+,-)
#include<stdio.h>

main()
{
	int x = +4;
	int y = -2;

	printf("x + (-y) = %d \n", x + (-y));
	printf("-x + (+y) = %d\n", -x + (+y));
}
#endif

#if 0 //023 사칙 연산자 이해하기(+,-,*,/)
#include<stdio.h>

main()
{
	int x = 4;
	int y = 2;
	int z;

	z = x + y;
	z = x - y;
	z = x * y;
	z = x / y;
	z = (x + y) * (x - y);
	z = (x * y) + (x / y);
	z = x + y + 2004;
	z = 2004 - x - y;
}
#endif

#if 0 //024 증감 연산자 이해하기(++,--)
#include<stdint.h>

main()
{
	int x = 1;

	printf("x = %d\n", x++);
	printf("x = %d\n", x++);
	printf("x = %d\n", ++x);
	printf("x = %d\n", x--);
	printf("x = %d\n", x--);
	printf("x = %d\n", --x);
}
#endif

#if 0 //025 관계 연산자 이해하기(<,>,=,>=,<=,!=)
#include<stdio.h>

main()
{
	int x = 1;
	int y = 2;
	int z = 3;

	 if(x==y)printf("x는 y와 같습니다.\n");
	 if(x!=y)printf("x는 y와 같지 않습니다.\n");
	 if(x>y)printf("x는 y보다 큽니다.\n");
	 if(x<y)printf("x는 y보다 작습니다.\n");
	 if(x>=z)printf("y는 z보다 크거나 같습니다.\n");
	 if(x<=z)printf("y는 z보다 작거나 같습니다.\n");
}

#endif

#if 0 //026 논리 연산자 이해하기(||,&&,!)
#include<stdio.h>

main()
{
	int x = 5;
	int y = 2;

	if (x > 0 && x < 10)
	{
		printf("0<x<10\n");
	}

	if(x<0||y==2)
	{
		printf("x가 0보다 작거나,y는 2 입니다.\n");
	}
	if (!(x > y))
	{
		printf("x가y보다 크지 않습니다.\n");
	}
}
#endif

#if 0 //027 조건 연산자 이해하기(?:)
#include<stdio.h>

main()
{
	int x = 1;
	int y = 2;
	int max;

	max = x > y ? x : y;
	printf("%d\n", max);
}

#endif

#if 0 //028 쉼표 연산자 이해하기(,)
#include<stdio.h>

main()
{
	int x = 1, y = 2, max;

	max = x > y ? x : y;

	printf("max=%d,x=%d,y=%d", max, x, y);
}
#endif

#if 0 //029 비트 연산자 이해하기 (|, &, ~, ^, <<, >>)
#include<stdio.h>

main()
{
	unsigned char ch = 255, mask = 0x7F;

	printf("%d\n",ch);
	printf("%d\n",ch&mask);
	printf("%d\n",(char)~ch);
	printf("%d\n",ch^ch);
	printf("%d\n",ch>>1);
	printf("%d\n",mask<<1);
}
#endif

#if 0 //030 캐스트 연산자 이해하기
#include<stdio.h>

main()
{
	int x = 5, y = 2;

	printf("%d\n", x / y);
	printf("%f\n", (double)x / y);
}

#endif
#if 0 //031 sizeof 연산자 이해하기
#include<stdio.h>

main()
{
	char i;
	int j;
	double k;
	long t;
	long long tt;
	short ttt;

	printf("%d\n", sizeof(i));
	printf("%d\n", sizeof(j));
	printf("%d\n", sizeof(k));
	printf("%d\n", sizeof(t));
	printf("%d\n", sizeof(tt));
	printf("%d\n", sizeof(ttt));
}
#endif

#if 0 //032 중첩 조건문 이해하기(if~else)
#include<stdio.h>

main()
{
	int i = 1;
	int j = 2;
	int k = 7;

	if (i == 1)
	{
		if (j == 2)
		{
			if (k == 3)
				printf("i=1,j=2,k=3입니다.");
			else if(k==4)
				printf("i=1,j=2,k=4입니다.");
			else if (k==5)
				printf("i=1,j=2,k=5입니다.");
			else
				printf("i=1,j=2,k=%d입니다.",k);

				
		}
	}
}

#endif

#if 0 //033 중첩 순환문 이해하기(fir~continue~break)
#include<stdio.h>
main()
{
	int i;
	int j;

	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			printf("%d*%d=%2d\n", i, j, i*j);
		}
	}
}

#endif
#if 0 //034 조건 선택문 이해하기(switch~case~default)
#include<stdio.h>

main()
{
	int i = 5;

	switch (i)
	{
	case 1:
		printf("i는1입니다.");
		break;
	case 2:
		printf("i는2입니다.");
		break;
	default:
		printf("i는 %d입니다.", i);
		break;

	}
}
#endif
#if 0 //035 조건 순환문 이해하기1(while~continue~break)
#include<stdio.h>

main()
{
	int i = 1;
	int hap = 0;

	while (i <= 10)
	{
		hap = hap + i;
		i++;
	}
	printf("hap=%d", hap);
}

#endif
#if 0 //036 조건 순환문 이해하기2(do~while~continue~break)
#include<stdio.h>

main()
{
	int i = 1;
	int hap = 0;

	do
	{
		hap = hap + i;
		i++;
	} while (i <= 10);
	printf("hap=%d", hap);
}
#endif

#if 0 //037 무조건 분기문 이해하기
#include<stdio.h>

main()
{
	int i;
	int j;

	for (i = 1; i <= 100; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			printf("%d*%d=%2d\n", i, j, i * j);
			if (i == 9 && j == 9)goto ku_ku_end;
		}
	}
ku_ku_end:;
}
#endif

#if 0 //038 문자열 이해하기
#include<stdio.h>

#define ASCII_BEGIN 0
#define ASCII_END 255

main()
{
	int i;

	for (i = ASCII_BEGIN; i <= ASCII_END; i++)
	{
		printf("ASCII코드(%3d),문자='%c'\n", i, i);
	}
}
#endif
#if 0 //039 배열 이해하기
#include<stdio.h>

main()
{
	int kor[10] = { 100,90,35,60,75,55,95,80,90,70 };
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("%d ", kor[i]);
	}
}
#endif

#if 0 //040 메모리 이해하기
#include<stdio.h>

main()
{
	int i = 0;
	int j = 1;

	printf("값=%d,메모리주소=%p\n", i, &i);
	printf("값=%d,메모리주소=%p\n", j, &j);
}
#endif
#if 0 //041 포인터 이해하기
#include<stdio.h>

main()
{
	int saram_A = 0;
	int saram_B = 0;
	int* pointer;
	int* psaram;

	pointer = &saram_A;
	* pointer = 1;
	printf("%d,%d\n", saram_A, *pointer);

	psaram = &saram_A;
	* psaram = 2;
	printf("%d,%d %d\n", saram_A, *pointer,*psaram);

	pointer = &saram_B;
	*pointer = 3;
	printf("%d,%d %d\n", saram_A,saram_B, *pointer);

	psaram = &saram_B;
	*psaram = 4;
	printf("%d,%d %d %d\n", saram_A,saram_B, *pointer, *psaram);

}
#endif
#if 0 //042 널(NULL) 문자 이해하기
#include<stdio.h>

int length(char* pstr);

main()
{
	int len = length("abcde");

	printf("길이 = %d", len);
}

int length(char* pstr)
{
	int len = 0;

	while (*pstr != NULL)
	{
		pstr++;
		len++;
	}
return len;
}
#endif
#if 0 //043 구조체 이해하기
#include<stdio.h>

struct tagSungJuk
{
	int kor;
	int eng;
	int math;
};
main()
{
	struct tagSungJuk SJ;

	SJ.kor = 100;
	SJ.eng = 95;
	SJ.math = 99;

	printf("총합 = %d", SJ.kor + SJ.eng + SJ.math);
}
#endif
#if 0 //044 공용체 이해하기
#include<stdint.h>

union tagVariant
{
	int i;
	float d;
};

main()
{
	union tagVariant V;

	V.i = 0;
	V.d = 5.5;

	printf("V.i=%d\n", V.i);
	printf("V.d=%f\n", V.d);
}
#endif

#if 0 //045 열거형 이해하기
#include<stdint.h>

enum { Sun = 0, Mon, Tue, Wed, Thr, Fri, Sat };

main()
{
	printf("%d", Sun);
	printf("%d", Mon);
	printf("%d", Tue);
	printf("%d", Wed);
	printf("%d", Thr);
	printf("%d", Fri);
	printf("%d", Sat);
}
#endif
#if 0 //046 데이터형 정의하기
#include<stdint.h>
#define true 1
#define false 0

typedef int bool;

main()
{
	bool bCondition;

	bCondition = true;

	if (bCondition == true)
	{
		printf("조건식은 true입니다.");
	}
}
#endif
#if 0 //047 함수와 인수 이해하기
#include<stdint.h>

int print(char* string);

main()
{
	print("This is a function!");
}
int print(char* string)
{
	int len = 0;

	while (*string != (char)NULL)
	{
		printf("%c", *string);
		string++;
		len++;
	}
	return len;
}
#endif
#if 0 //048 변수의 범위 이해하기
#include<stdio.h>

void print_x(int x);
void print_gx(void);
int x = 20;

main()
{
	int x = 5;
	printf("x=%d\n", x);

	print_x(10);
	print_gx();
}

void print_x(int x)
{
	printf("x=%d\n", x);
}

void print_gx(void)
{
	printf("x=%d\n", x);
}
#endif
#if 0 //049 include 문 이해하기
#include<stdio.h>
#include<conio.h>

main()
{
	int ch;
	printf("아무키나 누르세요...\n");

	ch = _getch();

	printf("%c 키가 눌러졌습니다.",ch);
}
#endif
#if 0 //050 매크로 이해하기
#include<stdio.h>

#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

main()
{
	int i, j;

	i = 5;
	j = 7;

	printf("최대값은 %d입니다.\n", MAX(i, j));
	printf("최소값은 %d입니다.\n", MIN(i, j));
}
#endif
#if 0 //051 문자 입력받기(getch)
#include<stdio.h>
#include<conio.h>

#define ENTER 13

void main(void)
{
	int ch;

	printf("아스키 코드로 변환할 키를 누르세요...\n");
	printf("ENTER 키를 누르면 프로그램은 종료됩니다.\n");

	do
	{
		ch = _getch();

		printf("문자: (%c),아스키 코드=(%d)\n", ch, ch);

	} while (ch != ENTER);
}
#endif
#if 0 //052 문자 출력하기(putch)
#include<stdio.h>
#include<conio.h>

int print(char* string);

void main(void)
{
	print("This is a putch function!");
}
int print(char* string)
{
	int len = 0;

	while (*string != (char)NULL)
	{
		_putch(*string);
		string++;
		len++;
	}

	_putch('\r');
	_putch('\n');

	return len;
}
#endif
#if 0 //053 정수값 입력받기(scanf)
#include<stdio.h>

void main(void)
{
	int count;
	int tmp;
	int total = 0;

	for (count = 1; count <= 3; count++)
	{
		printf("%d 번째 정수값을 입력한 후 Enter 키를 누르세요.\n", count);
		scanf_s("%d", &tmp);
		total += tmp;

		printf("입력 값=%d,총 합= %d\n", tmp, total);

	}
	printf("읽은 정수의 총 합은 %d입니다.\n", total);
}
#endif
#if 0 //054 정수값 출력하기(printf)
#include<stdio.h>

void main(void)
{
	int i = 100;
	int j = 1000;
	int k = 12345;

	printf("[%d]\n", i);
	printf("[%d]\n", j);
	printf("[%d]\n", k);

	printf("[%5d]\n", i);
	printf("[%5d]\n", j);
	printf("[%5d]\n", k);

	printf("[%10d]\n", i);
	printf("[%10d]\n", j);
	printf("[%10d]\n", k);

	printf("[%-10d]\n", i);
	printf("[%-10d]\n", j);
	printf("[%-10d]\n", k);
}
#endif
#if 0 //055 문자열 입력받기(gets)
#include<stdio.h>

int count(char* str);

void main(void)
{
	char string[100];
	char* ret;

	ret = gets(string);

	if (ret != NULL)
	{
		printf("문자'a'의 갯수는%d개입니다.", count(string));
	}
}
int count(char* str)
{
	int cnt = 0;

	while (*str != (int)NULL)
	{
		if (*str++ == 'a')cnt++;
	}
	return cnt;
}
#endif
#if 0 //056 문자열 출력하기(puts)
#include<stdio.h>

#define KOREA "대한민국"
#define SUMMER "여름"

void main()
{
	const char* winter = "겨울";

	puts(KOREA);
	puts(SUMMER);
	puts(winter);
}
#endif
#if 0 //057 문자열 복사하기(strcpy)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

#define KOREA "대한민국"

void main(void)
{
	char* string1;
	char string2[100];
	
	//strcpy(string1, KOREA);
	strcpy(string2, KOREA);
	strcpy(string2,"봄");
	printf("string2: %s", string2);
}
#endif
#if 0 //058 문자열을 복사하는 함수 만들기
#include <stdio.h>

#define KOREA "대한민국"

char* My_strcpy(char* dest, const char* src);

void main(void)
{
	char string[100];
	My_strcpy(string, KOREA);
	puts(string);
}

char* My_strcpy(char* dest, const char* src)
{
	if (dest == (int)NULL || src == (int)NULL)
	{
		if ( *dest != (int)NULL) * dest = (int)NULL;
		return NULL;
	}
	do
	{
		*dest++ = *src;
	} while (*src++ != (int)NULL);
	return dest;
}

#endif
#if 0 //059 문자열을 대.소문자로 구분하여 비교하기(strcmp)
#include<stdio.h>
#include<string.h>

#define SKY "sky"

void main(void)
{
	char string[100];
	int ret;

	printf("영단어를 입력한 후 Enter 키를 치세요!\n");
	printf("sky 를 입력하면 프로그램이 종료됩니다.\n");

	do
	{
		gets(string);

		ret = strcmp(string, SKY);

		if (ret == 0)
		{
			printf("%s ==%s, ret=%d\n", string, SKY, ret);
			break;
		}
		else if (ret < 0)printf("%s<%s,ret=%d\n", string, SKY, ret);
		else printf("%s>%s,ret=%d\n", string, SKY, ret);
	} while (1);
}

#endif

#if 0 //060 문자열을 비교하는 함수 만들기
#include<stdio.h>

#define SKY "sky"

int My_strcmp(const char* string1, const char* string2);

void main(void)
{
	char string[100];
	int ret;

	printf("영단어를 입력한 후 Enter 키를 치세요!\n");
	printf("sky를 입력하면 프로그램이 종료됩니다.\n");

	do
	{
		gets_s(string,sizeof(string));
		ret = My_strcmp(string, SKY);

		if (ret == 0)
		{
			printf("%s == %s,ret = %d\n", string, SKY, ret);
			break;
		}
		else if (ret < 0)printf("%s < %s,ret=%d \n", string, SKY, ret);
		else printf("%s>%s,ret=%d\n", string, SKY, ret);
	} while (1);
}

int My_strcmp(const char* string1, const char* string2)
{
	if (*string1 == (int)NULL && *string2 == (int)NULL)return 0;

	while (*string1 != (int)NULL)
	{
		if (*string2 == (int)NULL) return 1;

		if (*string1 == *string2)
		{
			string1++;
			string2++;
			continue;
		}
		if (*string1 < *string2)return -1;
		else return 1;
	}
	if (*string2 != (int)NULL)return -1;

	return 0;
}
#endif
#if 0 //061 문자열을 일정 크기만큼 비교하기(strncmp)
#include<stdio.h>
#include<string.h>

#define SKY "sky"
void main()
{
	char string[100];
	int ret;

	printf("영단어를 입력한 후 Enter 키를 치세요!\n");
	printf("sky로 시작되는 단어를 입력하면 프로그램이 종료됩니다.\n");

	do
	{
		gets_s(string, sizeof(string));

		ret = strncmp(string, SKY, 3);

		if (ret == 0)
		{
			printf("%3.3s == %s,ret = %d\n", string, SKY, ret);
			break;
		}
		else if (ret < 0)printf("%s<%s,ret=%d\n", string, SKY, ret);
		else printf("%s>%s,ret=%d\n", string, SKY, ret);
	} while (1);
}
#endif
#if 0 //062 문자열 연결하기(strcat)
#include<stdio.h>
#include<string.h>

void main()
{
	char string1[100];
	char string2[100];

	printf("첫 번째 단어를 입력하세요!\n");
	gets_s(string1, sizeof(string1));

	printf("두 번째 단어를 입력하세요!\n");
	gets_s(string2, sizeof(string2));

	strcat_s(string1,sizeof (string1) ,string2);

	puts(string1);
}
#endif
#if 0 //063 문자열의 길이 구하기(strlen)
#include<stdio.h>
#include<string.h>

void main(void)
{
	char string[200];

	printf("문장을 입력한 후, Enter키를 치세요!\n");
	printf("아무것도 입력하지 않으면 프로그램은 종료됩니다!\n");

	do
	{
		gets_s(string, sizeof(string));

		if (strlen(string) == 0)
		{
			break;
		}
		printf("문자열의 길이는 %d입니다.\n", strlen(string));
	} while (1);
}

#endif
#if 0 //064 문자열 검색하기(strstr)
#include<stdio.h>
#include<string.h>

#define SKY "sky"

void main()
{
	char string[100];
	char* ret;

	puts("문자열을 입력한 후 Enter 키를 치세요!");
	puts("문자열 중에 sky가 포함되어 있으면,프로그램은 종료됩니다.");

	do
	{
		gets_s(string, sizeof(string));
		ret = strstr(string, SKY);
		if (ret == NULL)
		{
			puts("문자열 중에 sky가 없습니다.");
		}
		else
		{
			printf("%d주소 %d 위치에서 sky 문자열을 찾았습니다.",ret,ret - string);
			break;
		}
	} while (1);
}
#endif
#if 0 //065 문자열 중에서 문자 검색하기(strchr)
#include<stdio.h>
#include<string.h>

#define FIND_CHAR  'h'

void main(void)
{
	char string[100];
	char* ret;

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("문자열 중에 'h'가 포함되어 있으면, 프로그램은 종료됩니다.");

	do
	{
		//scanf_s("%c", string);
		gets_s(string, sizeof(string));
		ret = strchr(string, FIND_CHAR);
		printf("%s\n", string);

		if (ret == NULL)
		{
			puts("문자열 중에 'h'가 없습니다.");
		}
		else
		{
			printf("%d 위치에서 'h'문자를 찾았습니다.", ret - string);
			break;
		}
	} while (1);
}
#endif
#if 0 // 066 문자열 중에서 일치되는 첫 문자의 위치 구하기(strcspn)
#include<stdio.h>
#include<string.h>

void main(void)
{
	char* string = "This is a string $$$";
	char* strCharSet = "~!@#$%^&*()_+-={}[]:;'<>./?";
	unsigned int pos;

	pos = strcspn(string, strCharSet);

	puts("0			1	    2		3");
	puts("0123456789012345678901234567890");
	puts(string);
	puts(strCharSet);

	printf("%d 위치에서 일치되는 첫 문자를 발견하였습니다.\n", pos);
}

#endif
#if 0 // 067 문자열 중에서 일치되지 않는 첫 문자의 위치 구하기(strspn)
#include<stdio.h>
#include<string.h>

void main(void)
{
	char* string = "this is a very good!";
	char* strCharSet = "abcdefghijklmnopqrstuvwxyz";
	unsigned int pos;

	pos = strspn(string, strCharSet);

	puts("0		1	2	3");
	puts("0123456789012345678901234567890");
	puts(string);
	puts(strCharSet);

	printf("%d 위치에서 일치되지 않는 문자를 발견하였습니다.\n", pos);
}
#endif
#if 0 // 068 문자열을 구분자로 분리하기 1(strtok)
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
#define TOKEN " "

void main(void)
{
	char string[100];
	char* token;

	puts("문자열을 입력한 후 Enter키를 치세요!");

	gets_s(string, sizeof(string));

	token = strtok(string, TOKEN);
	while (token != NULL)
	{
		puts(token);
		token = strtok(NULL, TOKEN);
	}
}
#endif
#if 0 // 069 문자열을 구분자로 분리하기 2(strpbrk)
#include<stdio.h>
#include<string.h>

#define TOKEN " "

void main()
{
	char string[100];
	char* pos;

	puts("문자열을 입력한 후 Enter키를 치세요!");
	gets(string);
	pos = strpbrk(string, TOKEN);
	while (pos != NULL)
	{
		puts(pos++);
		pos = strpbrk(pos, TOKEN);
	}
}
#endif
#if 0 // 070 문자열을 특정 문자로 채우기(strset)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[100];

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

	do
	{
		gets_s(string,sizeof(string));
		if (strlen(string) == 0)break;
		_strset_s(string,sizeof(string), string[0]);		
		puts(string);
	} while (1);
}
#endif
#if 0 // 071 부분 문자열을 특정 문자로 채우기(strnset)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[100];

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

	do
	{
		gets_s(string, sizeof(string));
		if (strlen(string) == 0)break;
		_strnset_s(string, sizeof(string), '*', 5);
		puts(string);
	} while (1);
}
#endif
#if 0 // 072 문자열을 대문자로 변환하기(strupr)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[100];

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

	do
	{
		gets_s(string, sizeof(string));
		if (strlen(string) == 0)break;
		_strupr_s(string,sizeof(string));
		puts(string);
	} while (1);
}
#endif

#if 0 // 073 문자열을 소문자로 변환하기(strlwr)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[100];

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

	do
	{
		gets_s(string, sizeof(string));
		if (strlen(string) == 0)break;
		_strlwr_s(string, sizeof(string));
		puts(string);
	} while (1);
}
#endif
#if 0 // 074 문자열을 거꾸로 뒤집기(strrev)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[100];

	puts("문자열을 입력한 후 Enter키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

	do
	{
		gets_s(string, sizeof(string));
		if (strlen(string) == 0)break;
		_strrev(string);
		puts(string);
	} while (1);
}
#endif
#if 0 // 075 문자열을 중복 생성하기(strdup)
#include<stdio.h>
#include<string.h>
#include<malloc.h>

void main()
{
	char string[100];
	char* pstr;

	puts("문자열을 입력한 후 Enter 키를 치세요!");
	puts("아무 문자도 입력하지 않으면 프로그램은 종료됩니다!");

	do
	{
		gets_s(string, sizeof(string));
		if (strlen(string) == 0) break;
		pstr = _strdup(string);
		strcpy_s(string,sizeof(string), "temporary string");
		
		printf("문자열string: %s\n", string);
		printf("문자열pstr: %s\n", pstr);

		free(pstr);
	} while (1);
}
#endif
#if 0 // 076 문자열을 형식화하기(sprintf)
#include<stdio.h>

void main(void)
{
	char cValue = 'a';
	int iValue = 1234567;
	long lValue = 7890123;
	float fValue = 3.141592;
	double dValue = 3.141592;
	char* string = "korea";
	char buffer[100];

	sprintf_s(buffer, sizeof(buffer), "char형은%c", cValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "int 형은%d", iValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "long 형은%ld", lValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "float 형은%f", fValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "double 형은%e", dValue);
	puts(buffer);

	sprintf_s(buffer,sizeof(buffer), "char* 형은%s", string);
	puts(buffer);
	
}


#endif
#if 0 // 077 문자열을 정수로 변환하기 1(atoi)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int count;
	int total = 0;
	char string[100];

	for (count = 1; count <= 3; count++)
	{
		printf("%d 번째 문자열을 입력한 후 Enter키를 누르세요.\n", count);
		gets_s(string, sizeof(string));
		total += atoi(string);

		printf("입력 값 = %d, 총 합= %d\n", atoi(string), total);

	}
	printf("읽은 문자열의 총 합은 %d입니다.\n", total);
}
#endif
# if 0 // 078 문자열을 정수로 변환하기 2(atol)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	char* string1 = "2는 1보다 큽니다.";
	char* string2 = "1004는 천사입니다.";
	char* string3 = "2016년도 입니다.";
	char* string4 = "오늘은 6월 9일입니다.";
	long t1, t2, t3, t4;

	puts(string1);
	puts(string2);
	puts(string3);
	puts(string4);

	t1 = atol(string1);
	t2 = atol(string2);
	t3 = atol(string3);
	t4 = atol(string4);

	printf("문자열을 숫자로 변환한 값:%ld, %ld, % ld, %ld \n", t1, t2, t3, t4);
	printf("총 합은 %d입니다.\n", t1 + t2 + t3 + t4);
}
#endif
#if 0 // 079 문자열을 정수로 변환하기 3(strtol)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	char* string = "0xFF";
	char* stop;
	int radix;
	long value;

	radix = 16;

	value = strtol(string, &stop, radix);

	printf("%d 개의 문자가 변환되었습니다. \n", stop - string);
	printf("16진수 %s를 숫자로 변환하면 %ld 입니다.\n", string, value);
}
#endif
#if 0 // 080 문자열을 정수로 변환하기 4(strtoul)
#include<stdio.h>
#include<stdlib.h>

void main(void)
{
	char* string = "11000";
	char* stop;
	int radix;
	unsigned long value;

	radix = 2;

	value = strtoul(string, &stop, radix);

	printf("%d 개의 문자가 변환되었습니다.\n", stop - string);
	printf("2진수 %s를 숫자로 변환하면 %u입니다.\n", string, value);
}

#endif
#if 0 // 081 문자열을 실수로 변환하기 1(atof)
#include<stdio.h>
#include<stdlib.h>

void main(void)
{
	char* string1 = "2.1은 1.0보다 큽니다.";
	char* string2 = "1004.5는 천사.오 입니다.";
	char* string3 = "2005년도 입니다.";
	char* string4 = "오늘은 6월 9일입니다.";
	double t1, t2, t3, t4;

	puts(string1);
	puts(string2);
	puts(string3);
	puts(string4);

	t1 = atof(string1);
	t2 = atof(string2);
	t3 = atof(string3);
	t4 = atof(string4);

	printf("문자열을 숫자로 변환한 값:%.1f,%.1f,%.1f,%.1f\n",
		t1,t2,t3,t4);
	printf("총 합은 %.2f입니다.\n", t1 + t2 + t3 + t4);
}
#endif
#if 0 // 082 문자열을 실수로 변환하기 2(strtod)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	char* string = "1.234E-10";
	char* stop;
	double value;

	value = strtod(string, &stop);

	printf("%d 개의 문자가 변환되었습니다.\n", stop - string);
	printf("문자열 [%s]를 숫자로 변환하면 %E입니다.\n", string, value);
}
#endif
#if 0 // 083 정수를 문자열로 변환하기 1(itoa)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int value;
	char string[100];
	int radix;

	radix = 10;

	value = 5;
	_itoa_s(value, string,sizeof(string), radix);
	printf("변환된 문자열을 %s입니다.\n",string);

	value = -12345;
	_itoa_s(value, string, sizeof(string), radix);
	printf("변환된 문자열은 %s 입니다.\n", string);
}
#endif
#if 0 // 084 정수를 문자열로 변환하기 2(itoa)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	long value;
	char string[100];
	int radix;

	radix = 2;

	value = 12345;
	_itoa_s(value, string, sizeof(string), radix);
	printf("변환된 문자열은 %s 입니다.\n", string);

	value = -12345;
	_itoa_s(value, string, sizeof(string), radix);
	printf("변환된 문자열은 %s 입니다.\n", string);
}
#endif

#if 0 // 085 정수를 문자열로 변환하기 3(_ultoa)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	long value;
	char string[100];
	int radix;

	radix = 16;

	value = 34567;
	
	_ultoa_s(value, string, sizeof(string), radix);
	printf("변환된 문자열은 %s 입니다.\n", string);

	value = 1234567890;
	_ultoa_s(value, string, sizeof(string), radix);
	printf("변환된 문자열은 %s 입니다.\n", string);
}
#endif

#if 0 // 086 실수를 문자열로 변환하기 1(fcvt)
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void main()
{
	double value;
	char *pstr;
	int dec, sign;

	value = 3.1415926535;
	//_fcvt_s(pstr, sizeof(pstr),value, 6, &dec, &sign);
	pstr = _fcvt(value, 6, &dec, &sign);
	printf("변환된 문자열은 %s 입니다.\n", pstr);
	printf("소수점이 위치는%d, 부호는 %d입니다.\n", dec, sign);

	value = -3.1415926535;
	//_fcvt_s(pstr, sizeof(pstr),value, 6, &dec, &sign);
	pstr = _fcvt(value, 6, &dec, &sign);
	printf("변환된 문자열은 %s 입니다.\n", pstr);
	printf("소수점이 위치는%d, 부호는 %d입니다.\n", dec, sign);
}
#endif

#if 0 // 087 실수를 문자열로 변환하기 2(ecvt)
#include<stdio.h>	
#include<stdlib.h>
#pragma warning(disable:4996)


void main()
{
	double value;
	char* pstr;
	int dec, sign;

	value = 3.14e10;
	pstr = ecvt(value, 3, &dec, &sign);

	printf("변환된 문자열은 %s입니다.\n", pstr);
	printf("소수점의 위치는 %d, 부호는%d입니다.\n", dec, sign);

	value = -3.14e10;
	pstr = ecvt(value, 3, &dec, &sign);

	printf("변환된 문자열은 %s입니다.\n", pstr);
	printf("소수점의 위치는 %d, 부호는%d입니다.\n", dec, sign);
}
#endif
