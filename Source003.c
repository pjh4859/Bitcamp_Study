#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


	/*
	int main()
{
	char ch = 999;
	int i = 99999;
	double d = 99.9999;
	printf("ch's size: %d \n", sizeof(ch));
	printf("i's size: %d \n", sizeof(i));
	printf("d's size: %d \n", sizeof(d));
	printf("char's size: %d \n", sizeof(char));
	printf("int's size: %d \n", sizeof(int));
	printf("__int64's size: %d \n", sizeof(__int64));
	printf("long's size: %d \n", sizeof(long));
	printf("long long's size: %d \n", sizeof(long long));
	printf("float's size: %d \n", sizeof(float));
	printf("double's size: %d \n", sizeof(double));
	printf("long double's size: %d \n", sizeof(long double));

	/*
	int x, y, z;
	char ch,ch2;
	short s;
	x = 10;
	y = 20;
	s = 0x1234;
	ch = 254;
	ch2 = -2;
	z = x + y;

	printf("%d,%d\n", ch, ch2);
	printf("%d %d %d\n", x, y, z);
	printf("%#X %#X %#X\n", x, y, z);
	printf("%p %p %p\n", &x, &y, &z);
	*/
	/*
	int j;
	float num = -118.625;
//	for (j = 0; j < 100; j++)
	//	num += 0.1;
	printf("%f \n", num);

	   	 

	int a=13;
	int* p = &a;
	int* pp = &p;//&(&a)
	int** ppp = &p;
	int b[4] = { 1,2,3,4 };
	printf("\n\n\n%d,%d,%d\n", sizeof(a), sizeof(p), sizeof(pp));
	printf("%u,%u,%u,%u, %u\n", a,&a, &p, &pp,&ppp);
	printf("%u,%u,%u,%u,%u,%u\n", p, *p, &*p,pp,*pp,&*pp);
	printf("%u,%u,%u,%u,%u,%u\n\n", ppp, *ppp, **ppp, &**ppp, &*ppp, *(&ppp));

	printf("%d\n", sizeof(b));
	*/
	/*
	int res;
	char cc;
	
	while (1)
	{
		res = scanf("%c", &cc);
		if (res == -1) break;
		printf("%d\n", cc);
	}
	*/

/*
void my_gets(char* str, int size);

int main()
{

	char str[7];

	my_gets(str, sizeof(str));
	printf("�Է��� ���ڿ� : %s\n", str);

	

	return 0;
}

void my_gets(char* str, int size)
{
	int ch;
	int i = 0;

	ch = getchar();
	while ((ch != '\n') && (i < size - 1))
	{
		str[i] = ch;
		i++;
		ch = getchar();
	}
	str[i] = '\n';
}

*/

#if 0
int main()
{
	/*
	int num, grade;

	printf("�й� �Է� :");
	scanf("%d", &num);
	getchar();
	printf("���� �Է� :");
	grade = getchar();
	printf("�й� : %d, ���� : %c", num, grade);
	*/
	int a = 66;
	char ch = 'f';
	void* p = &a;
	p = &ch;
	ch = (char)a;
	a = (int)ch;



	printf("a: %d, *p: %c\n", a, *((char*)p));


	char str[80];

	printf("������ ���Ե� ���ڿ� �Է� :");
	gets(str);
	printf("�Է��� ���ڿ��� %s �Դϴ�.", str);


	return 0;
}
#endif

#define PR printf

int main()
{


	/*
	int radius;
	double pi;
	printf("�Է�\n");
//	scanf("%d %lf", &radius, &pi);
	scanf_s("%d %lf", &radius, &pi, sizeof(radius),sizeof(pi));
	scanf_s("%d %lf", &radius, &pi);


	printf("%d, %lf \n",radius, pi);
	*/
	/*
	char ch;
	int i;
	float f;
	double d;
	int j;
	ch = 10;
	i = 1000;
	f = 1.5;
	d = ch * i  + 10000;
	j = ch * i + 10000;

	printf("Result: %lf", d);
	*/
	/*
	int i;
	char ch;
	i = 128;
	ch = i;
	printf("i=%d\n", i);
	printf("ch=%d\n", ch);

	int j;
	double d;
	d = 3.14159;
	j = d;
	printf("d = %lf \n", d);
	printf("j = %d \n", j);

	*/

	/*
	double r1, r2;
	int res1, res2;
	r1 = 3.4;
	r2 = 2.1;
	res1 = r1 * r2;
	res2 = (int)r1 * (int)r2;
	printf("res1 = %d \n", res1);
	printf("res2 = %d \n", res2);
	*/
	/*
	int val = 10;
	printf("%d\n", val += 10);
	printf("%d\n", val -= 11);
	printf("%d\n", val *= 10);
	printf("%d\n", val /= 10);
	printf("%d\n", val %= 10);
	printf("%d\n", val | 10);

	int val2 = 1;
	printf("��������: %d\n", ++val2);
	printf("%d\n", val2);
	printf("��������: %d\n", val2++);
	printf("%d\n", val2);
	*/
	/*
	int val1 = 10, val2 = 20;
	int result = 0;
	result = val1 > val2;
	printf("%d\n", result);
	result = val1 == val2;
	printf("%d\n", result);
	result = val1 <= val2;
	printf("%d\n", result);
	result = val1 == 10;
	printf("%d\n", result);
	*/


	/*
	int val1 = 10, val2 = 20;
	printf("%d\n", 1 && 1);
	printf("%d\n", 1 || 1);
	printf("%d\n", !1);
	printf("%d\n", !0);
	printf("%d\n", !- 10);
	printf("%d\n", val1 > 10 || val2 == 20);
	*/
	/*
	int val1 = 17, val2 = 33;
	printf("%d\n", val1 & val2);
	printf("%d\n", val1 | val2);
	printf("%d\n", val1 ^ val2);
	printf("%d\n", ~val1);
	*/
	/*
	unsigned char cNum = 128;
	printf("%d\n", cNum << 1);
	printf("%d\n", cNum << 2);
	printf("%d\n", cNum << 3);
	printf("%d\n", cNum >> 1);
	printf("%d\n", cNum >> 2);
	printf("%d\n", cNum >> 3);
	*/
	/*
	int val1 = 10, val2 = 20;
	int result;
	result = val1 >= 10 ? val1 : val2;
	printf("%d\n", result);

	int val = 10;
	if (val == 10)
	{
		printf("val�� 10�̴�\n");
	}
	else if (val != 10)
	{
		printf("val�� 10dlek\n");
	}
	else
	{
		printf("-----");
	}
	*/
/*
	int val = 0;
	PR("������ �Է��ϼ���: ");
	scanf("%d", &val);
	(val == 10) ? printf("val�� 10�� �����ϴ�\n") : ((val > 10) ? printf("val�� 10���� Ů�ϴ�\n") : printf("val�� 10���� �۽��ϴ�\n"));
	*/
/*
	int num;
	printf("�ڿ����� �Է��ϼ���: ");
	scanf("%d", &num);
	switch (num % 3)
	{
	case 0:
		printf("3�� ����Դϴ�\n");
		break;
	case 1:
		printf("������ 1\n");
		break;
	case 2:
		printf("������ 2\n");
		break;
	default:
		PR("Typing another number.");
		break;
	}
	*/
	char ch;
	int a = 0, b = 0;
	printf("�����ȣ �Է��ϼ���:(+,-,*,/) ");
	scanf("%c%d%d", &ch,&a,&b);
	switch (ch)
	{
	case '+':
		printf("%d%c%d �� %d�Դϴ�\n",a,ch,b,a+b);
		break;
	case '-':
		printf("%d%c%d �� %d�Դϴ�\n", a, ch, b, a - b);
		break;
	case '*':
		printf("%d%c%d �� %d�Դϴ�\n", a, ch, b, a * b);
		break;
	case '/':
		printf("%d%c%d �� %d�Դϴ�\n", a, ch, b, a / b);
		break;
	}


	return 0;
}
