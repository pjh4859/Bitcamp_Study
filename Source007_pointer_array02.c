#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
int main()
{
	FILE* fp;
	
	fopen_s(&fp, "D:\\Test.txt", "r");
	//fp = fopen("D:\\Test.txt", "r");
	if (fp == NULL)
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}
	printf("파일이 열렸습니다.\n");
	fclose(fp);
	
	return 0;
}
#endif

#if 0
int main()
{
	int kor[3][4] = { {1,2,3,4,},{5,6,7,8,},{9,10,11,12} };
	int(*p)[3][4] = &kor;
	int(*pp)[4] = kor;
	//int(*ppp)[3][4] = kor;
	int i;
	i = p[0][1][2];

	printf("%d %d\n", p[0][0][0], (*p)[0][0]);
	printf("%d\n", pp[1][2]);
	//printf("%d\n", ppp[0][1][2]);


	return 0;
}

#endif

#if 0
struct student
{
	char name[30];
	int age;
	char address[40];
	char gender;
	char hobby[20];
};

void print(struct student* p)
{
	
}
int my_strcpy(char* dst, char* src)
{
	int cnt = 0;
	while (*src)
	{
		*dst++ = *src++;
		cnt++;
	}
	*dst = '\0';
	return cnt;
}


void func(int a)
{
	printf("a : %d\n", a);
}


int main()
{
	int a[3] = { 1,2,3 };
	int* p = a;
	
	struct student s = { "홍길동",24,"황해도구월산",1,"어려운사람돕기" };

	struct student *st = &s;
	printf("%s\n", (*st).name);
	printf("%d\n", (*st).age);
	printf("%s\n", st->address);
	printf("%s\n", (*st).gender ? "남자" : "여자");
	printf("%s\n", (*st).hobby);
	printf("sizeof(st): %d\n", sizeof(st));
	int b[3] = { 1,2,3 };
	int i = 10;
	char* sc;
	sc = "유관순";
	strcpy(s.name, "유관순");
	my_strcpy(st->name, "김시민");
	printf("sp: %s\n\n",sc);
	printf("%s\n", (*st).name);
	printf("%d\n", (*st).age);
	printf("%s\n", st->address);
	printf("%s\n", (*st).gender ? "남자" : "여자");
	printf("%s\n", (*st).hobby);
	printf("sizeof(st): %d\n", sizeof(st));
	return 0;
}

#endif


#if 0
/*
typedef struct student
{
	char name[30];
	int age;
	char address[40];
	char gender;
	char hobby[30];
}Student, * PtStudent;

int main()
{
	Student st;
	PtStudent pSt = &st;
	strcpy(pSt->name, "홍길동");
	pSt->age = 24;
	strcpy(pSt->address, "황해도구월산");
	pSt->gender = 1;
	strcpy(pSt->hobby, "어려운사람돕기");
	printf("%s\n", st.name);
	printf("%d\n", st.age);
	printf("%s\n", st.address);
	printf("%s\n", st.gender ? "남자" : "여자");
	printf("%s\n", st.hobby);

	return 0;
}
*/
#pragma pack(push,1)

typedef struct st1
{
	char ch;
	char ch2;
	short s;
	int i;
}St1;
#pragma pack(push,1)
typedef struct st2
{
	char ch;
	int i;
	short s;
	char ch2;
}St2;
#pragma pack(pop)
int main()
{
	St1 a = { 'a','b',0x1234,0x12345678 };
	St2 b = { 'c',0x87654321,0x4321,'d' };
	printf("St1: %d\n", sizeof(St1));
	printf("St2: %d\n", sizeof(St2));

	return 0;
}

#endif

#if 0
enum CNUM
{
	ONE=1,
	TWO,
	THREE=4,
	FOUR,
	FIVE
};

int main()
{
	enum CNUM cnum = ONE;
	for (cnum = 1; cnum <= FIVE; cnum++)
	{
		printf("%d,",cnum);
	}
	printf("\n");
	printf("%d\n", FOUR);
	printf("cnum: %d sizeof(cnum): %d\n", cnum, sizeof cnum);
	return 0;
}

#endif

#if 0
union packet
{
	unsigned char ch1;
	unsigned short s;
	unsigned int i;

};
int main()
{
	union packet a;
	a.i = 0x12345678;
	printf("sizeof a: %d\n", sizeof(a));
	printf("ch1: %#X\n", a.ch1);
	printf("s: %#X\n", a.s);
	printf("i: %#X\n", a.i);
	   
	return 0;
}
#endif

#if 0
#define SQRT(x) ((x)*(x))
double dsqrt(double a)
{
	return a * a;
}
int main()
{
	int num = 100;
	printf("%d\n", SQRT(100));
	printf("%d\n", SQRT(-20));
	printf("%.2lf\n", SQRT(2.5));
	printf("%d\n", SQRT(4 + 5)); //4+5*4+5
	printf("%.2lf\n", SQRT(4.2 + 5.3));
	printf("%.2lf\n", dsqrt(4 + 5));
	return 0;
}
#endif

#if 0

#pragma warning(disable:4996)
#define _DEBUG_
void DebugPrint(char* str)
{
#ifdef _DEBUG_
	printf("%s\n", str);
#endif
}
void main()
{
	int num;
	char str[20];
	printf("값을입력하세요 : ");
	scanf("%d", &num);
	sprintf(str, "%d", num);
	DebugPrint(str);
}
#endif

#if 0

#pragma warning(disable:4996)
#define _DEBUG_

int main()
{
	int stNum = 0, sum = 0;
	int i = 0;
	double ave = 0;
	int korean[] = { 85,86,87,88,89,90,91,92,93 };

	FILE* fp;
	stNum = sizeof(korean) / sizeof(korean[0]);

	for (i = 0; i < stNum; i++)
		sum += korean[i];
	ave = (double)sum / stNum;
	fp = fopen("..\\korean.txt", "wt");
	if (fp == NULL) {
		printf("파일열기에러\n");
		return;
	}
	printf("File is opend.\n");

	fputs("국어점수\n", fp);
	fprintf(fp, "총점: %d\n", sum);
	fprintf(fp, "평균: %.2f\n", ave);
	fclose(fp);
	
	return 0;
}
#endif



#if 0

#define BUF_LEN 256
void main()
{
	char buffer[BUF_LEN] = { 0 };
	int sum = 0;
	double ave = 0;
	FILE* fp;
	fp = fopen("..\\korean.txt", "rt");
	if (fp == NULL) {
		printf("파일열기에러\n");
		return;
	}
	fgets(buffer, BUF_LEN, fp);
	fputs(buffer, stdout);
	fscanf(fp, "%s %d", buffer, &sum);
	printf("%s %d\n", buffer, sum);
	fscanf(fp, "%s %lf", buffer, &ave);
	printf("%s %.2lf\n", buffer, ave);
	fclose(fp);
}

#endif


#if 0
#define BUF_LEN 256
int main()
{
	int stNum = 0, sum = 0;
	int i = 0;
	double ave = 0;
	int korean[] = { 85,86,87,88,89,90,91,92,93 };
	char str[BUF_LEN] = { 0 };
	FILE* fp;
	stNum = sizeof(korean) / sizeof(korean[0]);
	for (i = 0; i < stNum; i++)
		sum += korean[i];
	ave = (double)sum / stNum;
	fp = fopen("..\\korean.bin", "wb");
	if (fp == NULL) {
		printf("파일열기에러\n");
		return;
	}
	sprintf(str, "국어점수");
	fwrite(str, sizeof(char), strlen(str) + 1, fp);
	sprintf(str, "총점: ");
	fwrite(str, sizeof(char), strlen(str) + 1, fp);
	fwrite(&sum, sizeof(int), 1, fp);
	sprintf(str, "평균: ");
	fwrite(str, sizeof(char), strlen(str) + 1, fp);
	fwrite(&ave, sizeof(double), 1, fp);
	fclose(fp);

	return 0;
}

#endif

#if 0
#define BUF_LEN 256
int main()
{
	char buffer[BUF_LEN] = { 0 };
	int sum = 0;
	double ave = 0;
	FILE* fp;
	fp = fopen("..\\korean.bin", "rb");
	if (fp == NULL) {
		printf("파일열기에러\n");
		return;
	}
	fread(buffer, sizeof(char), 9, fp);
	printf("%s\n", buffer);
	fread(buffer, sizeof(char), 7, fp);
	fread(&sum, sizeof(int), 1, fp);
	printf("%s %d\n", buffer, sum);
	fread(buffer, sizeof(char), 7, fp);
	fread(&ave, sizeof(double), 1, fp);
	printf("%s %.2lf\n", buffer, ave);
	fclose(fp);

	return 0;
}

#endif