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
#if 1 //057 문자열 복사하기(strcpy)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

#define KOREA "대한민국"

void main(void)
{
	char* string1;
	char string2[100];
	
	strcpy(string1, KOREA);
	strcpy(string2, KOREA);
	strcpy(string2,"봄");
}
#endif