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

#if 1 //015 문자열형 변수 이해하기(char*).
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

#if 1 //017 정수형 상수 이해하기(int)

main()
{

}
#endif
