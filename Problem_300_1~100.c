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
#if 0 //057 ���ڿ� �����ϱ�(strcpy)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>

#define KOREA "���ѹα�"

void main(void)
{
	char* string1;
	char string2[100];
	
	//strcpy(string1, KOREA);
	strcpy(string2, KOREA);
	strcpy(string2,"��");
	printf("string2: %s", string2);
}
#endif
#if 0 //058 ���ڿ��� �����ϴ� �Լ� �����
#include <stdio.h>

#define KOREA "���ѹα�"

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
#if 0 //059 ���ڿ��� ��.�ҹ��ڷ� �����Ͽ� ���ϱ�(strcmp)
#include<stdio.h>
#include<string.h>

#define SKY "sky"

void main(void)
{
	char string[100];
	int ret;

	printf("���ܾ �Է��� �� Enter Ű�� ġ����!\n");
	printf("sky �� �Է��ϸ� ���α׷��� ����˴ϴ�.\n");

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

#if 0 //060 ���ڿ��� ���ϴ� �Լ� �����
#include<stdio.h>

#define SKY "sky"

int My_strcmp(const char* string1, const char* string2);

void main(void)
{
	char string[100];
	int ret;

	printf("���ܾ �Է��� �� Enter Ű�� ġ����!\n");
	printf("sky�� �Է��ϸ� ���α׷��� ����˴ϴ�.\n");

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
#if 0 //061 ���ڿ��� ���� ũ�⸸ŭ ���ϱ�(strncmp)
#include<stdio.h>
#include<string.h>

#define SKY "sky"
void main()
{
	char string[100];
	int ret;

	printf("���ܾ �Է��� �� Enter Ű�� ġ����!\n");
	printf("sky�� ���۵Ǵ� �ܾ �Է��ϸ� ���α׷��� ����˴ϴ�.\n");

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
#if 0 //062 ���ڿ� �����ϱ�(strcat)
#include<stdio.h>
#include<string.h>

void main()
{
	char string1[100];
	char string2[100];

	printf("ù ��° �ܾ �Է��ϼ���!\n");
	gets_s(string1, sizeof(string1));

	printf("�� ��° �ܾ �Է��ϼ���!\n");
	gets_s(string2, sizeof(string2));

	strcat_s(string1,sizeof (string1) ,string2);

	puts(string1);
}
#endif
#if 0 //063 ���ڿ��� ���� ���ϱ�(strlen)
#include<stdio.h>
#include<string.h>

void main(void)
{
	char string[200];

	printf("������ �Է��� ��, EnterŰ�� ġ����!\n");
	printf("�ƹ��͵� �Է����� ������ ���α׷��� ����˴ϴ�!\n");

	do
	{
		gets_s(string, sizeof(string));

		if (strlen(string) == 0)
		{
			break;
		}
		printf("���ڿ��� ���̴� %d�Դϴ�.\n", strlen(string));
	} while (1);
}

#endif
#if 0 //064 ���ڿ� �˻��ϱ�(strstr)
#include<stdio.h>
#include<string.h>

#define SKY "sky"

void main()
{
	char string[100];
	char* ret;

	puts("���ڿ��� �Է��� �� Enter Ű�� ġ����!");
	puts("���ڿ� �߿� sky�� ���ԵǾ� ������,���α׷��� ����˴ϴ�.");

	do
	{
		gets_s(string, sizeof(string));
		ret = strstr(string, SKY);
		if (ret == NULL)
		{
			puts("���ڿ� �߿� sky�� �����ϴ�.");
		}
		else
		{
			printf("%d�ּ� %d ��ġ���� sky ���ڿ��� ã�ҽ��ϴ�.",ret,ret - string);
			break;
		}
	} while (1);
}
#endif
#if 0 //065 ���ڿ� �߿��� ���� �˻��ϱ�(strchr)
#include<stdio.h>
#include<string.h>

#define FIND_CHAR  'h'

void main(void)
{
	char string[100];
	char* ret;

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("���ڿ� �߿� 'h'�� ���ԵǾ� ������, ���α׷��� ����˴ϴ�.");

	do
	{
		//scanf_s("%c", string);
		gets_s(string, sizeof(string));
		ret = strchr(string, FIND_CHAR);
		printf("%s\n", string);

		if (ret == NULL)
		{
			puts("���ڿ� �߿� 'h'�� �����ϴ�.");
		}
		else
		{
			printf("%d ��ġ���� 'h'���ڸ� ã�ҽ��ϴ�.", ret - string);
			break;
		}
	} while (1);
}
#endif
#if 0 // 066 ���ڿ� �߿��� ��ġ�Ǵ� ù ������ ��ġ ���ϱ�(strcspn)
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

	printf("%d ��ġ���� ��ġ�Ǵ� ù ���ڸ� �߰��Ͽ����ϴ�.\n", pos);
}

#endif
#if 0 // 067 ���ڿ� �߿��� ��ġ���� �ʴ� ù ������ ��ġ ���ϱ�(strspn)
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

	printf("%d ��ġ���� ��ġ���� �ʴ� ���ڸ� �߰��Ͽ����ϴ�.\n", pos);
}
#endif
#if 0 // 068 ���ڿ��� �����ڷ� �и��ϱ� 1(strtok)
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
#define TOKEN " "

void main(void)
{
	char string[100];
	char* token;

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");

	gets_s(string, sizeof(string));

	token = strtok(string, TOKEN);
	while (token != NULL)
	{
		puts(token);
		token = strtok(NULL, TOKEN);
	}
}
#endif
#if 0 // 069 ���ڿ��� �����ڷ� �и��ϱ� 2(strpbrk)
#include<stdio.h>
#include<string.h>

#define TOKEN " "

void main()
{
	char string[100];
	char* pos;

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	gets(string);
	pos = strpbrk(string, TOKEN);
	while (pos != NULL)
	{
		puts(pos++);
		pos = strpbrk(pos, TOKEN);
	}
}
#endif
#if 0 // 070 ���ڿ��� Ư�� ���ڷ� ä���(strset)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[100];

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do
	{
		gets_s(string,sizeof(string));
		if (strlen(string) == 0)break;
		_strset_s(string,sizeof(string), string[0]);		
		puts(string);
	} while (1);
}
#endif
#if 0 // 071 �κ� ���ڿ��� Ư�� ���ڷ� ä���(strnset)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[100];

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do
	{
		gets_s(string, sizeof(string));
		if (strlen(string) == 0)break;
		_strnset_s(string, sizeof(string), '*', 5);
		puts(string);
	} while (1);
}
#endif
#if 0 // 072 ���ڿ��� �빮�ڷ� ��ȯ�ϱ�(strupr)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[100];

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do
	{
		gets_s(string, sizeof(string));
		if (strlen(string) == 0)break;
		_strupr_s(string,sizeof(string));
		puts(string);
	} while (1);
}
#endif

#if 0 // 073 ���ڿ��� �ҹ��ڷ� ��ȯ�ϱ�(strlwr)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[100];

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do
	{
		gets_s(string, sizeof(string));
		if (strlen(string) == 0)break;
		_strlwr_s(string, sizeof(string));
		puts(string);
	} while (1);
}
#endif
#if 0 // 074 ���ڿ��� �Ųٷ� ������(strrev)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[100];

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do
	{
		gets_s(string, sizeof(string));
		if (strlen(string) == 0)break;
		_strrev(string);
		puts(string);
	} while (1);
}
#endif
#if 0 // 075 ���ڿ��� �ߺ� �����ϱ�(strdup)
#include<stdio.h>
#include<string.h>
#include<malloc.h>

void main()
{
	char string[100];
	char* pstr;

	puts("���ڿ��� �Է��� �� Enter Ű�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do
	{
		gets_s(string, sizeof(string));
		if (strlen(string) == 0) break;
		pstr = _strdup(string);
		strcpy_s(string,sizeof(string), "temporary string");
		
		printf("���ڿ�string: %s\n", string);
		printf("���ڿ�pstr: %s\n", pstr);

		free(pstr);
	} while (1);
}
#endif
#if 0 // 076 ���ڿ��� ����ȭ�ϱ�(sprintf)
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

	sprintf_s(buffer, sizeof(buffer), "char����%c", cValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "int ����%d", iValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "long ����%ld", lValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "float ����%f", fValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "double ����%e", dValue);
	puts(buffer);

	sprintf_s(buffer,sizeof(buffer), "char* ����%s", string);
	puts(buffer);
	
}


#endif
#if 0 // 077 ���ڿ��� ������ ��ȯ�ϱ� 1(atoi)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int count;
	int total = 0;
	char string[100];

	for (count = 1; count <= 3; count++)
	{
		printf("%d ��° ���ڿ��� �Է��� �� EnterŰ�� ��������.\n", count);
		gets_s(string, sizeof(string));
		total += atoi(string);

		printf("�Է� �� = %d, �� ��= %d\n", atoi(string), total);

	}
	printf("���� ���ڿ��� �� ���� %d�Դϴ�.\n", total);
}
#endif
# if 0 // 078 ���ڿ��� ������ ��ȯ�ϱ� 2(atol)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	char* string1 = "2�� 1���� Ů�ϴ�.";
	char* string2 = "1004�� õ���Դϴ�.";
	char* string3 = "2016�⵵ �Դϴ�.";
	char* string4 = "������ 6�� 9���Դϴ�.";
	long t1, t2, t3, t4;

	puts(string1);
	puts(string2);
	puts(string3);
	puts(string4);

	t1 = atol(string1);
	t2 = atol(string2);
	t3 = atol(string3);
	t4 = atol(string4);

	printf("���ڿ��� ���ڷ� ��ȯ�� ��:%ld, %ld, % ld, %ld \n", t1, t2, t3, t4);
	printf("�� ���� %d�Դϴ�.\n", t1 + t2 + t3 + t4);
}
#endif
#if 0 // 079 ���ڿ��� ������ ��ȯ�ϱ� 3(strtol)
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

	printf("%d ���� ���ڰ� ��ȯ�Ǿ����ϴ�. \n", stop - string);
	printf("16���� %s�� ���ڷ� ��ȯ�ϸ� %ld �Դϴ�.\n", string, value);
}
#endif
#if 0 // 080 ���ڿ��� ������ ��ȯ�ϱ� 4(strtoul)
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

	printf("%d ���� ���ڰ� ��ȯ�Ǿ����ϴ�.\n", stop - string);
	printf("2���� %s�� ���ڷ� ��ȯ�ϸ� %u�Դϴ�.\n", string, value);
}

#endif
#if 0 // 081 ���ڿ��� �Ǽ��� ��ȯ�ϱ� 1(atof)
#include<stdio.h>
#include<stdlib.h>

void main(void)
{
	char* string1 = "2.1�� 1.0���� Ů�ϴ�.";
	char* string2 = "1004.5�� õ��.�� �Դϴ�.";
	char* string3 = "2005�⵵ �Դϴ�.";
	char* string4 = "������ 6�� 9���Դϴ�.";
	double t1, t2, t3, t4;

	puts(string1);
	puts(string2);
	puts(string3);
	puts(string4);

	t1 = atof(string1);
	t2 = atof(string2);
	t3 = atof(string3);
	t4 = atof(string4);

	printf("���ڿ��� ���ڷ� ��ȯ�� ��:%.1f,%.1f,%.1f,%.1f\n",
		t1,t2,t3,t4);
	printf("�� ���� %.2f�Դϴ�.\n", t1 + t2 + t3 + t4);
}
#endif
#if 0 // 082 ���ڿ��� �Ǽ��� ��ȯ�ϱ� 2(strtod)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	char* string = "1.234E-10";
	char* stop;
	double value;

	value = strtod(string, &stop);

	printf("%d ���� ���ڰ� ��ȯ�Ǿ����ϴ�.\n", stop - string);
	printf("���ڿ� [%s]�� ���ڷ� ��ȯ�ϸ� %E�Դϴ�.\n", string, value);
}
#endif
#if 0 // 083 ������ ���ڿ��� ��ȯ�ϱ� 1(itoa)
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
	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n",string);

	value = -12345;
	_itoa_s(value, string, sizeof(string), radix);
	printf("��ȯ�� ���ڿ��� %s �Դϴ�.\n", string);
}
#endif
#if 0 // 084 ������ ���ڿ��� ��ȯ�ϱ� 2(itoa)
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
	printf("��ȯ�� ���ڿ��� %s �Դϴ�.\n", string);

	value = -12345;
	_itoa_s(value, string, sizeof(string), radix);
	printf("��ȯ�� ���ڿ��� %s �Դϴ�.\n", string);
}
#endif

#if 0 // 085 ������ ���ڿ��� ��ȯ�ϱ� 3(_ultoa)
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
	printf("��ȯ�� ���ڿ��� %s �Դϴ�.\n", string);

	value = 1234567890;
	_ultoa_s(value, string, sizeof(string), radix);
	printf("��ȯ�� ���ڿ��� %s �Դϴ�.\n", string);
}
#endif

#if 0 // 086 �Ǽ��� ���ڿ��� ��ȯ�ϱ� 1(fcvt)
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
	printf("��ȯ�� ���ڿ��� %s �Դϴ�.\n", pstr);
	printf("�Ҽ����� ��ġ��%d, ��ȣ�� %d�Դϴ�.\n", dec, sign);

	value = -3.1415926535;
	//_fcvt_s(pstr, sizeof(pstr),value, 6, &dec, &sign);
	pstr = _fcvt(value, 6, &dec, &sign);
	printf("��ȯ�� ���ڿ��� %s �Դϴ�.\n", pstr);
	printf("�Ҽ����� ��ġ��%d, ��ȣ�� %d�Դϴ�.\n", dec, sign);
}
#endif

#if 0 // 087 �Ǽ��� ���ڿ��� ��ȯ�ϱ� 2(ecvt)
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

	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n", pstr);
	printf("�Ҽ����� ��ġ�� %d, ��ȣ��%d�Դϴ�.\n", dec, sign);

	value = -3.14e10;
	pstr = ecvt(value, 3, &dec, &sign);

	printf("��ȯ�� ���ڿ��� %s�Դϴ�.\n", pstr);
	printf("�Ҽ����� ��ġ�� %d, ��ȣ��%d�Դϴ�.\n", dec, sign);
}
#endif
