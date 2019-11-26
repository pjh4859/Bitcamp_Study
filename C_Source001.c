#if 0 //001
#include<stdio.h>
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
#include<stdio.h>
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
#include<stdio.h>
typedef struct point
{
	int x;
	int y;
}point;
	point add(point a, point b)
	{
		point point;
		point.x = a.x + b.x;
		point.y = a.y + b.y;
		return point;
	}
	point sub(point a, point b)
	{
		point point;
		point.x = a.x - b.x;
		point.y = a.y - b.y;
		return point;
	}
void main()
{
	struct point pta, ptb, ptresult;
	pta.x = 100;
	pta.y = 200;
	ptb.x = 50;
	ptb.y = 100;
	ptresult = add(pta, ptb);
	printf("%d %d \n", ptresult.x, ptresult.y);
	ptresult = sub(pta, ptb);
	printf("%d %d \n", ptresult.x, ptresult.y);
}

#endif
#if 0 //004
//#include<cstdio>
#include<stdio.h>
//#include<cmath>
#include<math.h>

void main()
{
	int num;
	printf("음수입력:");
	scanf_s("%d", &num);
	printf("절대값:%d\n", abs(num));
}
#endif

#if 0//006
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)


int Plus(int a, int b)
{
	return a + b;
}


char* Plus_st(char* a, char* b)
{
	int len = strlen(a);
	int len2 = strlen(b);
	char* str = (char*)malloc(sizeof(char) * (len + len2 + 1));
	memset(str, 0, len + len2 + 1);

	strncpy(str, a, len);
	strncpy(str + len, b, len2);
	return str;
}

void main()
{
	int a = 10, b = 20, result;
	const char* str = "아름다운", * str2 = "대한민국", * strResult;
	result = Plus(a, b);
	//std::cout << result << std::endl;
	strResult = Plus_st((char*)str, (char*)str2);
	//std::cout << strResult << std::endl;
	free((void*)strResult);
}
#endif
#if 0 //007 bool형
#include<stdio.h>
enum bool{true, false};
int main()
{
	enum bool a;
	a = true;
	printf("a: %d\n", a);
}
#endif