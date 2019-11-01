#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
int main()
{
	/*
	int age;
	char name[20];

	printf("나이 입력:");
	scanf_s("%d", &age);

	fgetc(stdin);
	printf("이름 입력 :");
	fgets(name,sizeof(name),stdin);
	printf("나이 : %d, 이름 : %s\n", age, name);
	*/
	/*
	char str[80] = "apple ju\0ice";
	char* ps = "banana";
	char tt[3] = { 92,79,48 };

	printf("%c%c\n",tt[0],tt[1]);
	printf("%d\n\n", tt[0]);
	gets(str);//

	puts(str);
	fputs(ps, stdout);
	puts("milk");
	*/
	/*
	char str1[80] = "strawberry";

	char str2[80] = "apples";

	strcpy(str2, "apple");
	char* ps1 = "banana";
	char* ps2 = str2;

	printf("%s\n", str1);
	strcpy(str1, str2);
	printf("next %s\n", str1);

	strcpy(str1, ps1);
	printf("%s\n", str1);

	strcpy(str1, "banana");
	printf("%s\n", str1);
	*/
	/*
	int score = 0;
	printf("학점입력 : ");
	scanf_s("%d", &score);
	if (score >= 90)
		printf("A학점\n");
	else if (score >= 80)
		printf("B학점\n");
	else if (score >= 70)
		printf("C학점\n");
	else if (score >= 60)
		printf("D학점\n");
	else
		printf("F학점\n");

	switch (score/10)
	{
	case 10:
	case 9:
		printf("A\n");
		break;
	case 8:
		printf("B\n");
		break;
	case 7:
		printf("C\n");
		break;
	case 6:
		printf("D\n");
		break;
	default:
		printf("F\n");
		break;
	}
	*/
	/*
	unsigned char i = 1;

	while (i < 256)
	{
	//	printf("%d, %f\n", i,(double)i),i += 2;

	//	printf("%d, %f\n", i, (double)i++);
		printf("%d, %d\n", i, i++);

		i += 2;

		
	}

	//printf("%d, %f\n", i, (double)i);
	*/
	/*
	int loop = 1;
	do
	{
		printf("%d\n", loop);
		loop++;
	} while (loop <= 10);
	*/
/*
	char ch;
	while (1)
	{
	ch = getchar();
	if (ch == '.')

		break;
	if (ch >= '0' && ch <= '9')
		continue;
	if (ch >= 'a' && ch <= 'z')
		ch += 'A' - 'a';
	putchar(ch);
	}
	*/
/*
	char ch;
		   	  
	while (1) {
		ch = getchar();
		if (ch >= '0' && ch <= '9') {
			putchar(ch);
			//fflush(stdin);
		}
		else if (ch >= 'a' && ch <= 'z') {
			putchar(ch + 'A' - 'a');
			goto END;
		}
		else
			goto END;
	}
END:
	printf("끝\n");
	*/


	
/*
char ch;
int i;
for (i = 0; i < 128; i++)
{
	if (i % 5 == 0)
		printf("\n");
	printf("%c: %d	",i,i);
}
*/
/*
int num;
printf("정수 입력(-1이면 종료): ");
scanf("%d", &num);
if (num == -1) {
	printf("끝\n");
	return;
}

*/



	return 0;
}

#endif
//-------------------------------------------------------------------------
#if 0
double AveInputCalc(double a, double b);
void swap(int* a, int* b);



int main()
{
	/*
	double result, val1, val2;
	printf("두 수 입력: ");
	scanf_s("%lf %lf", &val1, &val2);
	result=AveInputCalc(val1,val2);
	printf("결과값은 %lf\n", result);
	*/

	int a = 22, b = 33;
	int* p = &a, * pp = &b;
	printf("%d, %d\n", &a, &b);
	swap(p, pp);
	printf("%d, %d, %d, %d\n", &a, &b, a, b);

	return 0;
}

double AveInputCalc(double a, double b)
{
//	double result, val1, val2;
//	printf("두 수 입력: ");
//	scanf_s("%lf %lf", &val1, &val2);
//	result = (val1 + val2) / 2;
//	printf("결과값은 %lf\n", result);

	return (a + b) / 2;
}

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

	printf("%d, %d, %d, %d\n",&*a,&*b,*a,*b);
}
#endif
//----------------------------------------------------------------------------
#if 0
int countFunc = 0;
int tt = 2;
void CountFunc()
{
	int a = 0;
	static int countFunc=0;
	int b = 0;
	int c = 0;
	int d = 0;
	printf("호출된 수는: %d\n", ++countFunc);
}
void CallNumFunc()
{
	printf("호출된 수는 : %d\n", countFunc);
}
void main()
{
	int tt = 3;
	int i = 0, num = 0;
	printf("숫자입력 : ");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		countFunc++;
		CountFunc();
	}
	//countFunc += 10;
	CallNumFunc();
}

#endif

#if 0
#define CNT 10
int global = 0;

void add()
{
	return;
}
int main(int argc, char** argv,char* env)
{
	int age = 0;
	int* p = 0;
	p = (int*)malloc(sizeof(int));

	printf("main: %#X\n", (unsigned int)main);
	printf("printf: %#X\n", (unsigned int)printf);
	printf("argc: %#X\n", (unsigned int)&argc);
	printf("argv: %#X\n", (unsigned int)&argv);
	printf("env: %#X\n", (unsigned int)&env);
	printf("age: %#X\n", (unsigned int)&age);
	printf("global: %#X\n", (unsigned int)&global);
	printf("add(): %#X\n", (unsigned int)&add);
	printf("p: %#X\n", (unsigned int)p);
	// 각 성분당 메모리의 어떤 영역에 들어있나 확인.

	printf("string: %#X\n", "Hellow");
	printf("string: %s\n", "Hellow");


	/*
	int num;
	char name[10];
	printf("Input Data");
	scanf("%s %d %d", name, &age, &num);
	printf("%s %d %d\n", name, age, num);
	*/
	return 0;
}
#endif

#if 0

/*
void main()
{
	int korean[10];
	int sum=0, ave, i;
	for (i = 0; i < 10; i++)
	{
		printf("%d번째학생국어점수입력: ",i+1);
		scanf_s("%d", &korean[i]);

		scanf_s("%d", korean+i);
		//getchar();
	}
	for (i = 0; i < 10; i++)
	{
		sum += korean[i];
	}
	ave = sum / 10;
	printf("학생의국어점수총합은 %d, 평균은 %d\n", sum, ave);
}
*/
/*
#define RA_NUM 5
void main()
{
	int i = 0;
	double radius[RA_NUM] = { 2.1, 3.3, 3.5, 3.6, 4.6 };
	int iii[30] = { 1,2,3 };
	printf("radius배열의사이즈: %d\n", sizeof(radius));
	printf("radius배열의길이: %d\n", sizeof(radius) / sizeof(radius[0]));
	for (i = 0; i < RA_NUM; i++)
		printf("%d번째원의둘레는 %lf\n", i, radius[i] * 2 * 3.14);
	for (i = 0; i < sizeof(radius) / sizeof(radius[0]); i++)
		printf("%d번째원의둘레는 %lf\n", i, radius[i] * 2 * 3.14);
}
*/

int main()
{
	/*
	char chstr[10] = { 'k','o','r','e','a' };
	char* p = chstr;
	printf("chstr: %s\n", chstr);
	printf("%d\n", sizeof(p));
	*/
	/*
	char a;
	while (1)
	{
		a = getchar();
		printf("%c\n", a);
		break;
	}
	*/


	int i = 0;
	int k = 5;
	printf("%d %d\n", i++, k=i);
	printf("%d %d\n", k=i, i++);
	printf("%d %d\n", k = i, ++i);


	int str[6] = {1,3,5,7,9};
	//printf("%s\n", str);

	int* p = &str[0];
	int* pp = str;
	int* s = &str;
	int** pp2 = &pp;
	int** s2 = &s;

	printf("%d %d %d %d\n", **pp2, **s2, *pp, *s);
	printf("%d %d %d %d\n", *&pp2, *&s2, &pp, &s);

//	return;


	int(*ppp)[4] = str;
	int(*pppp)[4] = &str;

	printf("%d  %d\n", sizeof(str), sizeof(&str));
	printf("%d %d %d %d %d %d\n", str, str+1,&str,&str+1,pp,&pp);
	printf("%d %d %d %d %d %d\n", p, pp,*p,*pp, *(p+1), *(pp+1));
	printf("%d %d\n", ppp, **(ppp+1));
	printf("%d %d\n", pppp, **(pppp + 1));


	return 0;
}


#endif

int main()
{
	char* pary[4];
	int i;
	pary[0] = "dog";
	pary[1] = "elephant";
	pary[2] = "horse";
	pary[3] = "giraffe";

	for (i = 0; i < 4; i++)
	{
		printf("%d: %s\n", &pary[i],pary[i]);
		printf("%p\n", "dog");
	}
	return 0;
}