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