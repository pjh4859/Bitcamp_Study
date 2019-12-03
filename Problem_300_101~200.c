#if 0 //101 �޸� ���ϱ�(memcmp)
#include<stdio.h>
#include<string.h>

void main()
{
	char s1[100] = "123";
	char s2[100] = "123";

	strcpy_s(&s1[4],sizeof(&s1[4]), "abc");
	strcpy_s(&s2[4], sizeof(&s2[4]), "efg");

	if (strcmp(s1, s2) == 0)
	{
		puts("strcmp: ������ ���� ��ġ�մϴ�.");
	}
	if (memcmp(s1, s2, 7) == 0)
	{
		puts("memcmp: ������ ���� ��ġ�մϴ�.");
	}
	else
	{
		puts("memcmp: ������ ���� ��ġ���� �ʽ��ϴ�.");
	}
}
#endif
#if 0 //102 �޸� �̵��ϱ�(memmove)
#include<stdio.h>
#include<string.h>

char s1[20] = "1234567890";
char s2[20] = "1234567890";

void main()
{
	puts(s1);
	memcpy(s1 + 4, s1 + 2, 5);
	puts(s1);

	puts(s2);
	memmove(s2 + 4, s2 + 2, 5);
	puts(s2);
}
#endif
#if 0 //103 �޸� ä���(memset)
#include<stdio.h>
#include<string.h>

void main(void)
{
	char string[50] = "�Ƹ��ٿ� �츮���� ���ѹα�";

	puts(string);
	memset(string, (int)NULL, sizeof(string));
	memset(string, '*', sizeof(string) - 1);

	puts(string);
}
#endif
#if 0 //104 �޸𸮸� �����ϴ� �Լ� �����
#include<stdio.h>
#include<string.h>

struct tagM1
{
	int x;
	int y;
	char buffer[30];
};

void* My_memcpy(void* dst, const void* src, unsigned int count);

void main(void)
{
	struct tagM1 x1, x2;
	x1.x = 5;
	x1.y = 10;
	strcpy_s(x1.buffer,sizeof(x1.buffer), "memory copy");
	
	My_memcpy(&x2, &x1, sizeof(x1));

	puts(x2.buffer);
}
void* My_memcpy(void* dst, const void* src, unsigned int count)
{
	void* ret = dst;
	while (count--)
	{
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
	return ret;
}
#endif
#if 0 //105 �޸𸮸� �̵��ϴ� �Լ� �����
#include<stdio.h>
#include<string.h>

char s[20] = "1234567890";

void* My_memmove(void* dst, const void* src, unsigned int count);

void main(void)
{
	puts(s);
	My_memmove(s + 4, s + 2, 6);
	puts(s);
}

void* My_memmove(void* dst, const void* src, unsigned int count)
{
	void* ret = dst;

	if (dst <= src || (char*)dst >= ((char*)src + count))
	{
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		dst = (char*)dst + count - 1;
		src = (char*)src + count - 1;

		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}
	return ret;
}
#endif
#if 0 //106 ������ ����ϱ�
#include<stdio.h>

void main(void)
{
	char* p_char;
	short* p_short;
	int* p_int;
	long* p_long;
	float* p_float;
	double* p_double;

	printf("�������� ũ��: %d ����Ʈ\n", sizeof(char));
	printf("�������� ũ��: %d ����Ʈ\n", sizeof(short));
	printf("�������� ũ��: %d ����Ʈ\n", sizeof(int));
	printf("�������� ũ��: %d ����Ʈ\n", sizeof(long));
	printf("�Ǽ����� ũ��: %d ����Ʈ\n", sizeof(float));
	printf("�Ǽ����� ũ��: %d ����Ʈ\n", sizeof(double));

	printf("������ �������� ũ��: %d ����Ʈ\n", sizeof(p_char));
	printf("������ �������� ũ��: %d ����Ʈ\n", sizeof(p_short));
	printf("������ �������� ũ��: %d ����Ʈ\n", sizeof(p_int));
	printf("������ �������� ũ��: %d ����Ʈ\n", sizeof(p_long));
	printf("�Ǽ��� �������� ũ��: %d ����Ʈ\n", sizeof(p_float));
	printf("�Ǽ��� �������� ũ��: %d ����Ʈ\n", sizeof(p_double));
}
#endif
#if 0 //107 �����͸� �Լ����� ����ϱ�
#include<stdio.h>

void change_x1(int x1);
void change_x2(int *x2);

void main(void)
{
	int x;

	x = 5;
	printf("�Լ��� ȣ���ϱ� �� x��: %d\n", x);

	change_x1(x);
	printf("change_x1() �Լ��� ȣ���� ���� x��:%d\n", x);

	change_x2(&x);
	printf("change_x2() �Լ��� ȣ���� ���� x��:%d\n", x);

}

void change_x1(int x1)
{
	x1 = 50;
	printf("%d\n", x1);
}

void change_x2(int* x2)
{
	*x2 = 100;
	printf("%d\n", x2);
}
#endif
#if 0 //108 
#include<stdio.h>

void main()
{
	int x = 0, y = 0;
	int* pxy[2];

	pxy[0] = &x;
	pxy[1] = &y;

	*pxy[0] = 5;
	*pxy[1] = 10;

	printf("x=%d,pxy[0]=%d\n", x, *pxy[0]);
	printf("y=%d,pxy[1]=%d\n", y, *pxy[1]);

	printf("x+y=%d\n", x + y);
	printf("x+y=%d\n", *pxy[0] + *pxy[1]);
}
#endif
#if 0 //109 ������ �迭�� �Լ����� ����ϱ�
#include<stdio.h>

void print_pxy(int* pxy[2]);

void main()
{
	int x = 0, y = 0;
	int* pxy[2];

	pxy[0] = &x, pxy[1] = &y;
	*pxy[0] = 5, *pxy[1] = 10;

	print_pxy(pxy);	
}
void print_pxy(int* pxy[2])
{
	printf("pxy[0]=%d\n", *pxy[0]);
	printf("pxy[1]=%d\n", *pxy[1]);
	printf("pxy[0]=%d\n", pxy[0]);
	printf("pxy[1]=%d\n", pxy[1]);
}
#endif
#if 0 //110 1���� �迭 ����ϱ�
#include<stdio.h>

void main(void)
{
	char one[10] = "Kovea";

	puts(one);
	one[2] = 'r';
	puts(one);

	printf("one[0]=%3d,%c\n", one[0], one[0]);
	printf("one[1]=%3d,%c\n", one[1], one[1]);
	printf("one[2]=%3d,%c\n", one[2], one[2]);
	printf("one[3]=%3d,%c\n", one[3], one[3]);
	printf("one[4]=%3d,%c\n", one[4], one[4]);
	printf("one[5]=%3d,%c\n", one[5], one[5]);
}
#endif
#if 0 //111 1���� �迭�� ������ ����ϱ�
#include<stdio.h>
#include<string.h>

void main()
{
	char one[] = "Korea";
	char* pone;

	pone = one;

	puts(one);
	puts(pone);

	strcpy_s(pone, sizeof("japan"), "Japan");

	puts(one);
	puts(pone);
}
#endif
#if 0 //112 1���� �迭�� �Լ����� ����ϱ�
#include<stdio.h>

void print_one(char* pone);
void print_one2(char one[]);

void main()
{
	char one[] = "Korea";

	print_one(one);
	print_one2(one);
}

void print_one(char* pone)
{
	puts(pone);
}
void print_one2(char one[])
{
	puts(one);
}
#endif
#if 0 //113 2���� �迭 ����ϱ�
#include<stdio.h>

void main()
{
	int i;
	int jumsu[100][3];
	int total[3] = { 0, };

	for (i = 0; i < 100; i++)
	{
		jumsu[i][0] = 92;
		jumsu[i][1] = 90;
		jumsu[i][2] = 95;
	}

	for (i = 0; i < 100; i++)
	{
		total[0] += jumsu[i][0];
		total[1] += jumsu[i][1];
		total[2] += jumsu[i][2];
	}

	printf("���� ������ ����:%d\n", total[0]);
	printf("���� ������ ����:%d\n", total[1]);
	printf("���� ������ ����:%d\n", total[2]);
}
#endif
#if 0 //114 2���� �迭�� ������ ����ϱ�
#include<stdio.h>

void main()
{
	int i;
	int jumsu[100][3];
	int total[3] = { 0, };
	int(*pjumsu)[3];

	pjumsu = jumsu;

	for (i = 0; i < 100; i++)
	{
		pjumsu[i][0] = 92;
		pjumsu[i][1] = 90;
		pjumsu[i][2] = 95;
	}
	for (i = 0; i < 100; i++)
	{
		total[0] = total[0] + pjumsu[i][0];
		total[1] = total[1] + pjumsu[i][1];
		total[2] = total[2] + pjumsu[i][2];
	}
	printf("���� ������ ����: %d\n",total[0]);
	printf("���� ������ ����: %d\n",total[1]);
	printf("���� ������ ����: %d\n",total[2]);
}
#endif
#if 0 //115 2���� �迭�� �Լ����� ����ϱ�
#include<stdio.h>
void calc(int(*pjumsu)[3], int* ptotal);

void main()
{
	int jumsu[100][3];
	int total[3] = { 0, };
	int(*pjumsu)[3];

	pjumsu = jumsu;

	calc(pjumsu, total);

	printf("���� ������ ����: %d\n", total[0]);
	printf("���� ������ ����: %d\n", total[1]);
	printf("���� ������ ����: %d\n", total[2]);
}
void calc(int(*pjumsu)[3], int* ptotal)
{
	int i;

	for (i = 0; i < 100; i++)
	{
		pjumsu[i][0] = 92;
		pjumsu[i][1] = 90;
		pjumsu[i][2] = 95;
	}

	for (i = 0; i < 100; i++)
	{
		ptotal[0] += pjumsu[i][0];
		ptotal[1] += pjumsu[i][1];
		ptotal[2] += pjumsu[i][2];
	}
}
#endif
#if 0 //116 3���� �迭 ����ϱ�
#include<stdio.h>

void main()
{
	int i, j;
	int jumsu[10][100][3];
	int total[3] = { 0, };

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			jumsu[i][j][0] = 92;
			jumsu[i][j][1] = 90;
			jumsu[i][j][2] = 95;
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			total[0] += jumsu[i][j][0];
			total[1] += jumsu[i][j][1];
			total[2] += jumsu[i][j][2];
		}
	}
	printf("��� ���� ���� ������ ����:%d\n", total[0]);
	printf("��� ���� ���� ������ ����:%d\n", total[1]);
	printf("��� ���� ���� ������ ����:%d\n", total[2]);
}

#endif
#if 0 //117 3���� �迭�� ������ ����ϱ�
#include<stdio.h>
void main()
{
	int i, j;
	int jumsu[10][100][3];
	int total[3] = { 0, };
	int(*pjumsu)[100][3];

	pjumsu = jumsu;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			pjumsu[i][j][0] = 92;
			pjumsu[i][j][1] = 90;
			pjumsu[i][j][2] = 95;
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			total[0] += pjumsu[i][j][0];
			total[1] += pjumsu[i][j][1];
			total[2] += pjumsu[i][j][2];
		}
	}
	printf("��� ���� ���� ������ ����:%d\n", total[0]);
	printf("��� ���� ���� ������ ����:%d\n", total[1]);
	printf("��� ���� ���� ������ ����:%d\n", total[2]);
}
#endif
#if 0 //118 3���� �迭�� �Լ����� ����ϱ�
#include<stdio.h>

void calc(int(*pjumsu)[100][3], int* ptotal);

void main()
{
	int jumsu[10][100][3];
	int total[3] = { 0, };

	calc(jumsu, total);

	printf("��� ���� ���� ������ ����:%d\n", total[0]);
	printf("��� ���� ���� ������ ����:%d\n", total[1]);
	printf("��� ���� ���� ������ ����:%d\n", total[2]);
}
void calc(int(*pjumsu)[100][3], int* ptotal)
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			pjumsu[i][j][0] = 92;
			pjumsu[i][j][1] = 90;
			pjumsu[i][j][2] = 95;
		}
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 100; j++)
		{
			ptotal[0] += pjumsu[i][j][0];
			ptotal[1] += pjumsu[i][j][1];
			ptotal[2] += pjumsu[i][j][2];
		}
	}	
}
#endif
#if 0 //119 ����ü ����ϱ�
#include<stdio.h>
#include<string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};
void main()
{
	struct tagAddress ad;

	strcpy_s(ad.name, sizeof(ad.name), "�P�浿");
	strcpy_s(ad.phone, sizeof(ad.phone), "02-1234-5678");
	strcpy_s(ad.address, sizeof(ad.address), "����� ��õ�� �񵿾���Ʈ 13����");

	printf("�̸�:%s\n", ad.name);
	printf("��ȭ:%s\n", ad.phone);
	printf("��ȭ:%s\n",ad.address);
}
#endif
#if 0 //120 ����ü ������ ����ϱ�
#include<stdio.h>
#include<string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};
void main()
{
	struct tagAddress ad;
	struct tagAddress* pad;

	pad = &ad;

	strcpy_s((*pad).name, sizeof((*pad).name), "�P�浿");
	strcpy_s((*pad).phone, sizeof((*pad).phone), "02-1234-5678");
	strcpy_s((*pad).address, sizeof((*pad).address), "����� ��õ�� �񵿾���Ʈ 13����");

	printf("�̸�:%s\n", pad->name);
	printf("��ȭ:%s\n", pad->phone);
	printf("��ȭ:%s\n", pad->address);
}
#endif
#if 0 //121 ����ü�� �Լ����� ����ϱ�
#include<stdio.h>
#include<string.h>

void print(struct tagAddress* pad);

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};

void main()
{
	struct tagAddress ad;

	strcpy_s(ad.name, sizeof(ad.name), "�P�浿");
	strcpy_s(ad.phone, sizeof(ad.phone), "02-1234-5678");
	strcpy_s(ad.address, sizeof(ad.address), "����� ��õ�� �񵿾���Ʈ 13����");
	print(&ad);
}
void print(struct tagAddress *pad)
{
	printf("�̸�:%s\n", pad->name);
	printf("��ȭ:%s\n", pad->phone);
	printf("��ȭ:%s\n", pad->address);
}
#endif
#if 0 //122 ����ü �迭 ����ϱ�
#include<stdio.h>
#include<string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};
void main()
{
	struct tagAddress ad[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		sprintf_s(ad[i].name,sizeof(ad[i].name), "ȫ�浿%d", i);
		strcpy_s(ad[i].phone,sizeof(ad[i].phone), "02-1234-5678");
		strcpy_s(ad[i].address,sizeof(ad[i].address), "����� ��õ�� �񵿾���Ʈ 13����");
	}
	for (i = 0; i < 3; i++)
	{
		printf("�̸�:%s\n", ad[i].name);
		printf("����:%s\n", ad[i].phone);
		printf("�ּ�:%s\n", ad[i].address);
	}
}
#endif
#if 0 //123 ����ü �迭 ������ ����ϱ�
#include<stdio.h>
#include<string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];
};

void main()
{
	struct tagAddress ad[3];
	struct tagAddress* pad;
	int i;

	pad = ad;

	for (i = 0; i < 3; i++)
	{
		sprintf_s(pad[i].name, sizeof(pad[i].name), "ȫ�浿%d", i);
		strcpy_s(pad[i].phone, sizeof(pad[i].phone),"02-9112-4545");
		strcpy_s(pad[i].address, sizeof(pad[i].address), "���� ����� �����15��");
			
	}
	for (i = 0; i < 3; i++)
	{
		printf("�̸�: %s\n", pad[i].name);
		printf("����: %s\n", pad[i].phone);
		printf("�ּ�: %s\n", pad[i].address);
	}
}
#endif
#if 0 //124 ����ü �迭�� �Լ����� ����ϱ�
#include<stdio.h>
#include<string.h>

struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];

};

void print(struct tagAddress* pad);

void main()
{
	struct tagAddress ad[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		sprintf_s(ad[i].name, sizeof(ad[i].name), "������%d", i);
		strcpy_s(ad[i].phone, sizeof(ad[i].phone), "010-3933-2828");
		strcpy_s(ad[i].address, sizeof(ad[i].address), "���� ����� �����15��");

	}
	print(ad);
}
void print(struct tagAddress* pad)
{
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("�̸�:%s\n", pad[i].name);
		printf("��ȭ:%s\n", pad[i].phone);
		printf("�ּ�:%s\n", pad[i].address);
	}
}
#endif
#if 0 //125 ����ü�� ���̸� ���ϰ� �ʱ�ȭ�ϱ�
#include<stdio.h>
#include<string.h>
struct tagAddress
{
	char name[30];
	char phone[20];
	char address[100];

};
typedef struct tagAddress addr;

void main()
{
	addr ad;
	int len;

	len = sizeof(addr);

	printf("����ü addr�� ũ��:%d\n", len);

	memset(&ad, 0, len);
}
#endif
#if 0 //126 ����ü ����ϱ�
#include<stdio.h>

typedef union tagVariable
{
	int i;
	double d;
}VA;

void main()
{
	VA va;
	va.i = 5;
	printf("va.i ����ü�� ��: %d\n", va.i);

	va.d = 3.14;

	printf("va.d ����ü�� ��: %f\n", va.d);
	printf("va.i ����ü�� ��: %d\n", va.i);
}
#endif
#if 0 //127 ����ü �Լ����� ����ϱ�
#include<stdio.h>
typedef union tagVariavle
{
	int i;
	double d;
}VA;

void print(VA* pva);

void main()
{
	VA va;

	print(&va);
}
void print(VA* pva)
{
	pva->i = 5;

	printf("pva->i ����ü�� ��:%d\n", pva->i);

	pva->d = 3.14;

	printf("pva->d ����ü�� ��: %f\n", pva->d);
	printf("pva->i ����ü�� ��: %d\n", pva->i);
}
#endif
#if 0 //128 void�� ������ ����ϱ�
#include<stdio.h>

void main()
{
	int i;
	double d = 3.14;

	int* pi;
	double* pd;
	void* pv;

	pi = &i;
	pd = &d;
	pi = &d;
	pv = &i;
	pv = &d;

	printf("�Ǽ� �� d:%f\n", *(double*)pv);
}
#endif
#if 0 //129 void�� �����͸� �Լ����� ����ϱ�
#include<stdio.h>
#include<string.h>

typedef struct tagPoint
{
	int x;
	int y;
}point;

void My_memset(void* dest, int c, unsigned count);

void main(void)
{
	point pt = { 5,10 };
	char array[10];

	printf("x,y: %d, %d\n", pt.x, pt.y);

	My_memset(&pt, 0, sizeof(pt));

	printf("x,y : %d, %d\n", pt.x, pt.y);

	My_memset(array, 48, sizeof(array));

	printf("array[0] ~ array[9]:%c ~ %c\n", array[0], array[9]);
}

void My_memset(void* dest, int c, unsigned count)
{
	while (count--)
	{
		*(char*)dest = c;
		dest = (char*)dest + 1;
	}
}
#endif
#if 0 //130 �������� ������ ����ϱ�
#include<stdio.h>

void main()
{
	char* animal[3];
	char** ppanimal;

	animal[0] = "ȣ����";
	animal[1] = "����";
	animal[2] = "�䳢";

	ppanimal = animal;

	puts(animal[0]);
	puts(ppanimal[1]);
	puts(ppanimal[2]);

}
#endif
#if 0 //131 �������� �����͸� �Լ����� ����ϱ�
#include<stdio.h>
void print(char** ppanimal);

void main()
{
	char* animal[3];

	animal[0] = "ȣ����";
	animal[1] = "����";
	animal[2] = "�䳢";

	print(animal);
}

void print(char** ppanimal)
{
	puts(ppanimal[0]);
	puts(ppanimal[1]);
	puts(ppanimal[2]);
}
#endif
#if 0 //132 �Լ� ������ ����ϱ�
#include<stdio.h>
#include<string.h>

void main()
{
	int(*myfunc)(const char*);

	myfunc = puts;

	puts("��ì�̰� ��~.~");
	myfunc("�޴ٸ��� ��~.~");

	myfunc = strlen;

	printf("���ڿ��� ����:%d\n", strlen("aa"));
	printf("���ڿ��� ����:%d\n", myfunc("aa"));
}
#endif
#if 0 //133 �Լ� �����͸� �迭���� ����ϱ�
#include<stdio.h>
#include<string.h>
void main()
{
	int(*myfunc[3])(const char*);

	myfunc[0] = puts;
	myfunc[1] = strlen;
	myfunc[2] = myfunc[1];

	puts("��ì�̰� ��~.~");
	myfunc[0]("�޴ٸ��� ��~.~");


	printf("���ڿ��� ����:%d\n", strlen("aa"));
	printf("���ڿ��� ����:%d\n", myfunc[1]("aa"));
	printf("���ڿ��� ����:%d\n", myfunc[2]("aa"));
}
#endif
#if 0 //134 �Լ� �����͸� �Լ����� ����ϱ�
#include<stdio.h>
#include<string.h>

void print1(int(*X)(const char*));
void print2(int(*X[2])(const char*));

void main()
{
	int (*myfunc[2])(const char*);

	myfunc[0] = puts;
	myfunc[1] = strlen;

	print1(myfunc[0]);
	print2(myfunc);
}
void print1(int(*X)(const char*))
{
	X("��ì�̰� ��!");
}
void print2(int(*X[2])(const char*))
{
	X[0]("�޴ٸ��� ��!");
	printf("���ڿ��� ����: %d\n", X[1]("aa"));
}
#endif
#if 0 //135 main() �Լ� ���� ����ϱ�
#include<stdio.h>

int main(int argc, int* argv[])
{
	int i;

	printf("�μ��� ��:%d\n", argc);

	for (i = 0; i < argc;i++)
	{
		printf("argc[%d]: %s\n", i, argv[i]);
	}
}
#endif
#if 0 //136 ���� �����ϱ�(fopen)
#include<stdio.h>
void main()
{
	FILE* file;
	fopen_s(&file,"D:\\C_code\\file.txt", "w+");
	if (file == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		puts("������ ���������� �����Ǿ����ϴ�.");
		fclose(file);
	}
}
#endif
#if 0 //137 ���Ͽ� �� ���� ����(fputc)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void main()
{
	FILE* fp;
	fp= fopen("D:\\C_code\\file.txt", "w+");
	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fputs("A", fp);
		puts("���� 'A'�� ���Ͽ� �����ߴ�.");
		fclose(fp);
	}
}
#endif
#if 0 //138 ���Ͽ��� �� ���� �б�(fgetc)
#include<stdio.h>
void main()
{
	FILE* fp;
	int ch;

	fopen_s(&fp,"D:\\C_code\\file.txt", "r");
	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		ch = fgetc(fp);
		printf("���� ����:%c \n", ch);
		fclose(fp);
	}
}
#endif
#if 0 //139 ���Ͽ� ���ڿ� ����(fputs)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fputs("���ѹα�\n¦��\n", fp);
		fclose(fp);
	}
}
#endif
#if 0 //140 ���Ͽ��� ���ڿ� �б�(fgets)
#include<stdio.h>
void main()
{
	FILE* fp;
	char buffer[100];

	fopen_s(&fp, "D:\\C_code\\file.txt", "r");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fgets(buffer, 100, fp);//���๮�ڸ� ������ �׸�����.
		puts(buffer);
		fclose(fp);
	}
}
#endif
#if 0 //141 ���Ͽ� ����ȭ�� ���ڿ� ����(fprintf)
#include<stdio.h>
void main()
{
	FILE* fp;
	int i = 12345;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fprintf(fp, "%d", i);
		fclose(fp);
	}

}
#endif
#if 0 //142 ���Ͽ��� ����ȭ�� ���ڿ� �б�(fscanf)
#include<stdio.h>
void main()
{
	FILE* fp;
	int i;

	fopen_s(&fp, "D:\\C_code\\file.txt", "r");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fscanf_s(fp, "%d", &i);
		//fscanf(fp, "%d", &i);
		printf("i=%d\n", i);
		fclose(fp);
	}
}
#endif
#if 1 //143 