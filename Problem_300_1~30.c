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

#if 1 //015 ���ڿ��� ���� �����ϱ�(char*).
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

#if 1 //017 ������ ��� �����ϱ�(int)

main()
{

}
#endif
