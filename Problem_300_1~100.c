#include <stdio.h>




#if 0 //001 C ���α׷� �����ϱ�.
int main()
{
	printf("�ȳ��ϼ�.");
}
#endif

#if 0 //002 ������ ���� ����.
int main()
{
	int �ӤӤ�ll��IIII;
	int x;
	int y;
	int z;

	�ӤӤ�ll��IIII = 20;
	x = 1;
	y = 2;

	z = x + y;

	printf("%d %d",z, �ӤӤ�ll��IIII);
}
#endif

#if 0 //003 ����� ���� ����.

#define X 1
#define PI 3.141592

int main()
{
	double z;

	z = X + PI;
	printf("%f", z);
}
#endif

#if 0 //004 ������ ���� ����.
main()
{
	int x;
	int y;
	x = 10;
	y = x - 5;
	if (x > y)
	{
		printf("x�� y���� Ů�ϴ�.");
	}
	else
	{
		printf("y�� x�� ���ų� �۽��ϴ�.");
	}
}

#endif

#if 0//005 ���ǹ� ���� ���� (if~else).
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

#if 0 //006 ��ȯ�� ���� ����(for).
main()
{
	int i;
	int hap = 0;

	for (i = 0; i <= 10; i = i + 1)
	{
		hap = hap + i;
	}
	printf("1���� 10������ ��: %d", hap);
}
#endif

#if 0 //007 ���ڿ� ���� ����.
main()
{
	printf("���ѹα�");	
}
#endif

#if 0 //009 �Լ� ���� ����.
int hapf(int value);

main()
{
	printf("1���� 10������ ���� %d \n", hapf(10));
	printf("1���� 100������ ���� %d \n", hapf(100));
	printf("1���� 1000������ ���� %d \n", hapf(1000));
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

#if 0 //010 �ּ� ���� ����.
main()
{
	int i;	//������ ���� i�� �����մϴ�.
	int hap = 0;  //������ ���� hap �� �����ϰ� 0���� �ʱ�ȭ�մϴ�.

	/*
	for ���� ����ó�� ����˴ϴ�.

	1.i=0���� �����մϴ�.��
	2.i�� 10���� �۰ų� ���������� �ݺ��մϴ�.
	3.������ hap���� i�� ���Ͽ� hap �� ����.
	4.i�� 1�� �����մϴ�.
	*/

	for (i = 0; i <= 10; i = i + 1)
	{
		hap = hap + i;
	}
	printf("%d", hap);
}
#endif

#if 0 //011 ������ ���� �����ϱ�(char).
main()
{
	char ch;
	unsigned char j;
	char k;

	ch = 200;
	j = 200;
	k = 'a';

	printf("������ ���� ch�� ���� %d\n", ch);
	printf("������ ���� j�� ���� %d\n", j);
	printf("������ ���� k�� ���� %d\n", k);
}
#endif

#if 0 //012 ������ ���� �����ϱ�(int).
main()
{
	int i;
	unsigned int j;
	int k;

	i = 2000000000;
	j = 4000000000;
	k = 'b';

	printf("������ ���� i�� ���� %d\n", i);
	printf("������ ���� j�� ���� %u\n", j);
	printf("������ ���� k�� ���� %d\n", k);
}
#endif

#if 0 //013 �Ǽ��� ���� �����ϱ�(double).
main()
{
	float d;
	double d1;
	double d2;

	d = 3.141592;
	d1 = 1234567890;
	d2 = 'c';

	printf("�Ǽ��� ���� d�� ���� %E\n", d);
	printf("�Ǽ��� ���� d1�� ���� %E\n", d1);
	printf("�Ǽ��� ���� d2�� ���� %E\n", d2);
}
#endif

#if 0 // 014 ���� ���� �����ϱ�(bool).
main()
{
	int b;
	int j;

	b = 10 > 5;
	j = 10 > 20;

	printf("���� ���� b�� ���� %d\n", b);
	printf("���� ���� j�� ���� %d\n", j);

	if (b) //��
	{
		printf("10>5�� ���� ���Դϴ�.\n");
	}
	else
	{
		printf("10>5�� ���� �����Դϴ�.\n");
	}
	if (j) //����
	{
		printf("10>20�� ���� ���Դϴ�.\n");
	}
	else
	{
		printf("10>20�� ���� �����Դϴ�.\n");
	}
	if (-1) //��
	{
		printf("-1�� ���Դϴ�.\n");
	}
	else
	{
		printf("-1�� �����Դϴ�.\n");
	}
}
#endif

#if 0 //015 ���ڿ��� ���� �����ϱ�(char*).
main()
{	char str[] = "���ѹα�";
	char* j = "I love Korea";

	printf("���ڿ��� ���� str�� ���� %s\n", str);
	printf("���ڿ��� ���� j�� ���� %s\n", j);
}

#endif

#if 0 //016 ������ ��� �����ϱ�(char)

#define HUNDRED 100
const char j = 10;
main()
{
	HUNDRED = 200;	//���� �߻�
	j = 200;		//���� �߻�

	printf("������ ��� HUNDRED�� ���� %d\n", HUNDRED);
	printf("������ ��� j�� ���� %d\n", j);

}
#endif

#if 0 //017 ������ ��� �����ϱ�(int)

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

#if 0 //017 ������ ��� �����ϱ�(int)
#include<stdio.h>
#define HUNDRED_THOUSAND 100000

const int j = 200000;
main()
{
	//HUNDRED_THOUSAND = 100000;	//���� �߻�
	//j = 200000;	//���� �߻�

	printf("������ ��� HUNDRED_THOUSAND�� ���� %d\n", HUNDRED_THOUSAND);
	printf("������ ���j�� ���� %d\n", j);
}
#endif
#if 0 //018 �Ǽ��� ��� �����ϱ�(double)
#include<stdio.h>
#define PI 3.141592

const double j = 1.23456789;

main()
{
	//PI = 3.141592; //���� �߻�
	//j = 1.23456789; //Error occured

	printf("�Ǽ��� ��� PI�� ����%f\n", PI);
	printf("�Ǽ��� ��� j�� ����%f\n", j);
}
#endif
#if 0 //019 ���� ��� �����ϱ�(bool)
#include<stdio.h>

#define TRUE 1
#define FALSE 0

main()
{
	if (TRUE)
	{
		printf("TRUE�� ���� ���Դϴ�.\n");
	}
	else
	{
		printf("TRUE�� ���� �����Դϴ�.\n");
	}
	if (FALSE)
	{
		printf("FALSE�� ���� ���Դϴ�.\n");
	}
	else
	{
		printf("FALSE�� ���� �����Դϴ�.\n");
	}
}
#endif

#if 0 //020 ���ڿ��� ��� �����ϱ�(char)
#include<stdio.h>

#define KOREA "���ѹα�"
#define BOOK "This is a book."

const char* SOCCER = "���� �౸�� �����մϴ�.";

main()
{
	printf("���ڿ��� ���	KOREA�� ��:%s \n", KOREA);
	printf("���ڿ��� ���	 BOOK�� ��:%s \n", BOOK);
	printf("���ڿ��� ���  SOCCER�� ��:%s \n", SOCCER);
}

#endif

#if 0 //021 ���� ������ �����ϱ�(=)
#include<stdio.h>

main()
{
	int x = 1;
	int y = 2;
	int  z;
	int zz;

	z = x + y;

	zz = printf("z�� ��:%d\n", z);
	printf("zz�� ��:%d\n", zz);
}
#endif

#if 0 //022 ��ȣ ������ �����ϱ�(+,-)
#include<stdio.h>

main()
{
	int x = +4;
	int y = -2;

	printf("x + (-y) = %d \n", x + (-y));
	printf("-x + (+y) = %d\n", -x + (+y));
}
#endif

#if 0 //023 ��Ģ ������ �����ϱ�(+,-,*,/)
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

#if 0 //024 ���� ������ �����ϱ�(++,--)
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

#if 0 //025 ���� ������ �����ϱ�(<,>,=,>=,<=,!=)
#include<stdio.h>

main()
{
	int x = 1;
	int y = 2;
	int z = 3;

	 if(x==y)printf("x�� y�� �����ϴ�.\n");
	 if(x!=y)printf("x�� y�� ���� �ʽ��ϴ�.\n");
	 if(x>y)printf("x�� y���� Ů�ϴ�.\n");
	 if(x<y)printf("x�� y���� �۽��ϴ�.\n");
	 if(x>=z)printf("y�� z���� ũ�ų� �����ϴ�.\n");
	 if(x<=z)printf("y�� z���� �۰ų� �����ϴ�.\n");
}

#endif

#if 0 //026 �� ������ �����ϱ�(||,&&,!)
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
		printf("x�� 0���� �۰ų�,y�� 2 �Դϴ�.\n");
	}
	if (!(x > y))
	{
		printf("x��y���� ũ�� �ʽ��ϴ�.\n");
	}
}
#endif

#if 0 //027 ���� ������ �����ϱ�(?:)
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

#if 0 //028 ��ǥ ������ �����ϱ�(,)
#include<stdio.h>

main()
{
	int x = 1, y = 2, max;

	max = x > y ? x : y;

	printf("max=%d,x=%d,y=%d", max, x, y);
}
#endif

#if 0 //029 ��Ʈ ������ �����ϱ� (|, &, ~, ^, <<, >>)
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

#if 0 //030 ĳ��Ʈ ������ �����ϱ�
#include<stdio.h>

main()
{
	int x = 5, y = 2;

	printf("%d\n", x / y);
	printf("%f\n", (double)x / y);
}

#endif
#if 0 //031 sizeof ������ �����ϱ�
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

#if 0 //032 ��ø ���ǹ� �����ϱ�(if~else)
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
				printf("i=1,j=2,k=3�Դϴ�.");
			else if(k==4)
				printf("i=1,j=2,k=4�Դϴ�.");
			else if (k==5)
				printf("i=1,j=2,k=5�Դϴ�.");
			else
				printf("i=1,j=2,k=%d�Դϴ�.",k);

				
		}
	}
}

#endif

#if 0 //033 ��ø ��ȯ�� �����ϱ�(fir~continue~break)
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
#if 0 //034 ���� ���ù� �����ϱ�(switch~case~default)
#include<stdio.h>

main()
{
	int i = 5;

	switch (i)
	{
	case 1:
		printf("i��1�Դϴ�.");
		break;
	case 2:
		printf("i��2�Դϴ�.");
		break;
	default:
		printf("i�� %d�Դϴ�.", i);
		break;

	}
}
#endif
#if 0 //035 ���� ��ȯ�� �����ϱ�1(while~continue~break)
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
#if 0 //036 ���� ��ȯ�� �����ϱ�2(do~while~continue~break)
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

#if 0 //037 ������ �б⹮ �����ϱ�
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

#if 0 //038 ���ڿ� �����ϱ�
#include<stdio.h>

#define ASCII_BEGIN 0
#define ASCII_END 255

main()
{
	int i;

	for (i = ASCII_BEGIN; i <= ASCII_END; i++)
	{
		printf("ASCII�ڵ�(%3d),����='%c'\n", i, i);
	}
}
#endif
#if 0 //039 �迭 �����ϱ�
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

#if 0 //040 �޸� �����ϱ�
#include<stdio.h>

main()
{
	int i = 0;
	int j = 1;

	printf("��=%d,�޸��ּ�=%p\n", i, &i);
	printf("��=%d,�޸��ּ�=%p\n", j, &j);
}
#endif
#if 0 //041 ������ �����ϱ�
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
#if 0 //042 ��(NULL) ���� �����ϱ�
#include<stdio.h>

int length(char* pstr);

main()
{
	int len = length("abcde");

	printf("���� = %d", len);
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
#if 0 //043 ����ü �����ϱ�
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

	printf("���� = %d", SJ.kor + SJ.eng + SJ.math);
}
#endif
#if 0 //044 ����ü �����ϱ�
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

#if 0 //045 ������ �����ϱ�
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
#if 0 //046 �������� �����ϱ�
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
		printf("���ǽ��� true�Դϴ�.");
	}
}
#endif
#if 0 //047 �Լ��� �μ� �����ϱ�
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
#if 0 //048 ������ ���� �����ϱ�
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
#if 0 //049 include �� �����ϱ�
#include<stdio.h>
#include<conio.h>

main()
{
	int ch;
	printf("�ƹ�Ű�� ��������...\n");

	ch = _getch();

	printf("%c Ű�� ���������ϴ�.",ch);
}
#endif
#if 0 //050 ��ũ�� �����ϱ�
#include<stdio.h>

#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

main()
{
	int i, j;

	i = 5;
	j = 7;

	printf("�ִ밪�� %d�Դϴ�.\n", MAX(i, j));
	printf("�ּҰ��� %d�Դϴ�.\n", MIN(i, j));
}
#endif
#if 0 //051 ���� �Է¹ޱ�(getch)
#include<stdio.h>
#include<conio.h>

#define ENTER 13

void main(void)
{
	int ch;

	printf("�ƽ�Ű �ڵ�� ��ȯ�� Ű�� ��������...\n");
	printf("ENTER Ű�� ������ ���α׷��� ����˴ϴ�.\n");

	do
	{
		ch = _getch();

		printf("����: (%c),�ƽ�Ű �ڵ�=(%d)\n", ch, ch);

	} while (ch != ENTER);
}
#endif
#if 0 //052 ���� ����ϱ�(putch)
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
#if 0 //053 ������ �Է¹ޱ�(scanf)
#include<stdio.h>

void main(void)
{
	int count;
	int tmp;
	int total = 0;

	for (count = 1; count <= 3; count++)
	{
		printf("%d ��° �������� �Է��� �� Enter Ű�� ��������.\n", count);
		scanf_s("%d", &tmp);
		total += tmp;

		printf("�Է� ��=%d,�� ��= %d\n", tmp, total);

	}
	printf("���� ������ �� ���� %d�Դϴ�.\n", total);
}
#endif
#if 0 //054 ������ ����ϱ�(printf)
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
#if 0 //055 ���ڿ� �Է¹ޱ�(gets)
#include<stdio.h>

int count(char* str);

void main(void)
{
	char string[100];
	char* ret;

	ret = gets(string);

	if (ret != NULL)
	{
		printf("����'a'�� ������%d���Դϴ�.", count(string));
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
#if 0 //056 ���ڿ� ����ϱ�(puts)
#include<stdio.h>

#define KOREA "���ѹα�"
#define SUMMER "����"

void main()
{
	const char* winter = "�ܿ�";

	puts(KOREA);
	puts(SUMMER);
	puts(winter);
}
#endif
#if 1 //057 ���ڿ� �����ϱ�(strcpy)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

#define KOREA "���ѹα�"

void main(void)
{
	char* string1;
	char string2[100];
	
	strcpy(string1, KOREA);
	strcpy(string2, KOREA);
	strcpy(string2,"��");
}
#endif