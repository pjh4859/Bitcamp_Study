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
#if 0 //143 ������ ���� ����(fflush)
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
		fputs("���ѹα�rr", fp);
		fflush(fp);
		fclose(fp);
	}
}
#endif
#if 0 //144 ���� �������� ���� ��ġ ���ϱ� 1(ftell)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�");
	}
	else
	{
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fputs("abcdaksjhdfjkdsjf", fp);
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //145 ���� �����͸� ó������ �̵��ϱ� 1(fseek)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");
	
	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�");
	}
	else
	{
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fputs("abcdaksjhdfjkdsjf", fp);
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fseek(fp, 0L, SEEK_SET);
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //146 ���� �����͸� ó������ �̵��ϱ� 2(rewind)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�");
	}
	else
	{
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fputs("abcdaksjhdfjkdsjf", fp);
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		rewind(fp);
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //147 ���� �����͸� ������ �̵��ϱ�(fseek)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�");
	}
	else
	{
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fputs("abcdaksjhdfjkdsjf", fp);
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		rewind(fp);
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fseek(fp, 0L, SEEK_END);
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //148 ���� �����͸� ������ ��ġ�� �̵��ϱ�(fseek)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�");
	}
	else
	{
		fputs("abcdaksjhdfjkdsjf", fp);
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fseek(fp, -2L, SEEK_CUR);
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //148(2) ���� �����͸� ������ ��ġ�� �̵��ϱ�(fseek)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "a+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�");
	}
	else
	{
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fseek(fp, 0L, SEEK_END);
		fputs("���纸��ʹ�", fp);
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //149 ������ ���� ���ϱ�(fseek)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "r");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�");
	}
	else
	{
		fseek(fp, 0L, SEEK_END);
		printf("������ ����:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //150 ���� �������� ���� ��ġ ���ϱ�2(fgetpos)
#include<stdio.h>
void main()
{
	FILE* fp;
	fpos_t pos;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�");
	}
	else
	{
		fputs("����� ����ʹ�.", fp);
		fgetpos(fp, &pos);
		printf("���� �������� ��ġ:%d\n", pos);
		fclose(fp);
	}
}
#endif
#if 0 //151 ���� �������� ���� ��ġ �����ϱ�(fsetpos)
#include<stdio.h>
void main()
{
	FILE* fp;
	fpos_t pos;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�");
	}
	else
	{
		fgetpos(fp, &pos);
		fputs("������.", fp);
		fsetpos(fp, &pos);
		printf("���� �������� ��ġ:%d\n", ftell(fp));
		fclose(fp);
	}
}
#endif
#if 0 //152 ���� �ݱ�(fclose)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp, "D:\\C_code\\file.txt", "w+");

	fputs("fclose() �Լ�", fp);
	fclose(fp);
	_fcloseall();
}
#endif
#if 0 //153 ������ ���� �����ߴ��� �˻��ϱ�(feof)
#include<stdio.h>

void main()
{
	FILE* fp;
	int ch;

	fopen_s(&fp, "D:\\C_code\\file.txt", "r");
	
	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�");
	}
	else
	{
		while(!feof(fp))
		{
			ch = fgetc(fp);
			printf("���� ����: %c\n", ch);
		}
		fclose(fp);
	}
}
#endif
#if 0 //154 ���� �б�/���� �� ���� �˻��ϱ�(ferror)
#include<stdio.h>

void main()
{
	FILE* fp;
	int ch;

	fopen_s(&fp, "D:\\C_code\\file.txt", "r");

	if (fp == NULL)
	{
		puts("������ ������ �� �����ϴ�");
	}
	else
	{
		while (!feof(fp))
		{
			ch = fgetc(fp);
			if (ferror(fp))
			{
				puts("�����дµ� ������.");
			}
			printf("���� ����: %c\n", ch);
		}
		fclose(fp);
	}
}
#endif
#if 0 //155 ���� ó�� �� �߻��� ���� ǥ���ϱ�(perror)
#include<stdio.h>

void main()
{
	FILE* fp;
	int ch;

	fopen_s(&fp, "D:\\C_code\\file2.txt", "r");

	if (fp == NULL)
	{
		perror("���� ���� ����");
	}
	else
	{
		while (!feof(fp))
		{
			ch = fgetc(fp);
			if (ferror(fp))
			{
				perror("���� �б� ����");
			}
			printf("���� ����: %c\n", ch);
		}
		fclose(fp);
	}
}
#endif
#if 0 //156 �ӽ� ���� �̸� �����(tmpnam)
#include<stdio.h>
void main()
{
	int i;
	char buffer[500];
	char* path;

	for (i = 0; i < 10; i++)
	{
		tmpnam_s(buffer,sizeof(buffer));
	//	tmpnam(buffer);
		puts(buffer);
	}
	for (i = 0; i < 10; i++)
	{
		path = _tempnam("", "test");
		puts(path);
	}
}
#endif
#if 0 //157 ������ �����ϴ��� Ȯ���ϱ�(_access)
#include<stdio.h>
#include<io.h>

void main()
{
	char* path = "D:\\C_code\\file.txt";

	if (_access(path, 0) == 0)
		puts("�ش� ��ο� ������ �����մϴ�.");
}
#endif
#if 0 //158 ���� �̸� �����ϱ�(rename)
#include<stdio.h>
void main()
{
	char*oldname= "D:\\C_code\\file.txt";
	char*newname= "D:\\C_code\\file2.txt";

	if (rename(oldname, newname) != 0)
	{
		perror("���ϸ� ���� ����");
	}
	else
	{
		puts("���ϸ� ������.");
	}
}
#endif
#if 0 //159 ���� �̸� �����ϱ�(_chmod)
#include<stdio.h>
#include<io.h>
#include<sys/stat.h>
void main()
{
	char* filename = "D:\\C_code\\file2.txt";

	if (_chmod(filename,_S_IREAD) != 0)//�б�����
	{
		perror("���� �Ӽ� ���� ����");
	}
	else
	{
		puts("���ϼӼ��� ������.");
	}
}
#endif
#if 0 //160 ���� �����ϱ�(remove)
#include<stdio.h>

void main()
{
	char* filename = "D:\\C_code\\file2.txt";

	if (remove(filename))//�б�����
	{
		perror("���� ���� ����");
	}
	else
	{
		puts("������ ���������� ������.");
	}
}
#endif
#if 0 //161 ���͸� �����ϱ�(_mkdir)
#include<stdio.h>
#include<direct.h>
void main()
{
	char* pathname = "D:\\C_code\\files";

	if (_mkdir(pathname)==-1)//�б�����
	{
		perror("���͸� ���� ����");
	}
	else
	{
		puts("���͸��� ���������� ������.");
	}
}
#endif
#if 0 //162 ���͸� �����ϱ�(_rmdir)
#include<stdio.h>
#include<direct.h>
void main()
{
	char* pathname = "D:\\C_code\\files";

	if (_rmdir(pathname) == -1)//�б�����
	{
		perror("���͸� ���� ����");
	}
	else
	{
		puts("���͸��� ���������� ������.");
	}
}
#endif
#if 0 //163 ���� �۾����� ���͸� ���ϱ�(_getcwd)
#include<stdio.h>
#include<stdlib.h>
#include<direct.h>
void main()
{
	char pathname[_MAX_PATH];

	_getcwd(pathname, _MAX_PATH);

	puts(pathname);
}
#endif
#if 0 //164 ���� �۾����� ���͸� �����ϱ�(_chdir)
#include<stdio.h>
#include<stdlib.h>
#include<direct.h>
void main()
{
	char pathname[_MAX_PATH]="D:\\C_code";;

	if (_chdir(pathname) == 0)
	{
		_getcwd(pathname, _MAX_PATH);
		puts(pathname);
	}
}
#endif
#if 0 //165 ���� �۾����� ����̺� ���ϱ�(_getdrive)
#include<stdio.h>
#include<direct.h>
void main()
{
	int drive;

	drive = _getdrive();
	printf("���� ����̺� : %c\n", 'A' + drive - 1);
}
#endif
#if 0 //166 ���� �۾����� ����̺� �����ϱ�(_chdrive)
#include<stdio.h>
#include<direct.h>
void main()
{
	int drive=2;

	if (_chdrive(drive) == 0)
	{
		drive = _getdrive();
		printf("����� ����̺� : %c\n", 'A' + drive - 1);
	}
}
#endif
#if 0 //167 ǥ�� ��,��� ��Ʈ�� ����ϱ�(stdin, stdout)
#include<stdio.h>
void main()
{
	printf("���� ���̿�~�������̷δ�...");
}
#endif
#if 0 //168 ������� ����� ���� �� ���ϱ�(time)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	time(&now);
	printf("1970�� 1�� 1�Ϻ��� ����� ��:%d\n", now);
}
#endif
#if 0 //169 ��¥ �� �ð� ���ϱ� 1(localtime)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	struct tm t;

	time(&now);
	
	//t = *localtime(&now);
	localtime_s(&t,&now);

	printf("���� ��¥ �� �ð�:%4d.%d.%d.%d:%d:%d\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);
}
#endif
#if 0 //170 ��¥ �� �ð� ���ϱ� 2(_ftime)
#include<stdio.h>
#include<time.h>
#include<sys/timeb.h>

void main()
{
	struct _timeb tb;
	struct tm t;
	//_ftime_s;
	_ftime_s(&tb);

	localtime_s(&t,&tb.time);

	printf("���� ��¥ �� �ð�:%4d.%d.%d.%d:%d:%d.%d\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec,tb.millitm);
}
#endif
#if 0 //171 ���� ǥ�� �� ���ϱ�(gmtime)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	struct tm t;

	time(&now);

	gmtime_s(&t, &now);

	printf("���� ǥ�� ��: %4d.%d.%d %d:%d:%d \n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);
}
#endif
#if 0 //172 ��¥ �� �ð��� ���ڿ��� ��ȯ�ϱ�(ctime)
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)

void main()
{
	time_t now;

	time(&now);

	printf("���� ��¥ �� �ð�: %s", ctime( &now));
}
#endif
#if 0 //173 ��¥ �� �ð��� ���ϰų� ����(mktime)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	struct tm t;

	time(&now);
	localtime_s(&t, &now);
	t.tm_mday += 100;
	mktime(&t);

	printf("���� ��¥�� 100���� ���� ��¥: %4d.%d.%d %d:%d:%d \n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);
}
#endif
#if 0 //174 ��¥ �� �ð��� ���� ���ϱ�(difftime)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t s1, s2;
	double gap=0;
	int i;

	time(&s1);

	for (i = 0; i < 1000000000; i++)
	{
		gap = gap * 100;
	}

	time(&s2);
	printf("����ð�: %g��\n", difftime(s2, s1));
}
#endif
#if 0 //175 ��¥ �� �ð��� �̱������� ��ȯ�ϱ�(asctime)
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)
void main()
{
	time_t now;
	struct tm t;

	now = time(NULL);
	localtime_s(&t, &now);

	printf("���� ��¥ �� �ð�: %s\n", asctime(&t));
}
#endif
#if 0 //176 ��¥ �� �ð��� ����ȭ�ϱ�(strftime)
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)
void main()
{
	time_t now;
	struct tm t;
	char buff[100];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "%Y-%m-%d %I:%M:%S %p", &t);
	puts(buff);
}
#endif
#if 0 //177 �ﰢ �Լ� ���� �� ���ϱ�(sin)
#include<stdio.h>
#include<math.h>

void main()
{
	double x;
	x = sin((3.14/6));//rad

	printf("sin(1):%g\n", x);
}
#endif
#if 0 //178 �ﰢ �Լ� ��ũ ���� �� ���ϱ�(asin)
#include<stdio.h>
#include<math.h>

void main()
{
	double x,y;
	x = asin(1);//rad
	y = sin(1.57);//rad

	printf("asin():%g//%g\n", x,y);
}
#endif
#if 0 //179 �ﰢ �Լ� x/y�� ���� ��ũ ź��Ʈ �� ���ϱ�(atan2)
#include<stdio.h>
#include<math.h>

void main()
{
	double x,y;
	x = atan2(1.0,1.0);
	y = tan(1.0,1.0);

	printf("atan2:%g, %g\n", x,y);
}
#endif
#if 0 //180 ���� �Լ� ������ ���ϱ�(exp)
#include<stdio.h>
#include<math.h>

void main()
{
	double x, y;
	x = exp(1.0);
	y = exp(2.0);

	printf("exp:%g, %g\n", x, y);
}
#endif
#if 0 //181 �α� �Լ� �ڿ� �αװ� ���ϱ�(log)
#include<stdio.h>
#include<math.h>

void main()
{
	double x, y;
	x = log(1.0);
	y = log(2.0);

	printf("log:%g, %g\n", x, y);
}
#endif
#if 0 //182 �α� �Լ� �ؼ��� 10���� �ϴ� �αװ� ���ϱ�(log10)
#include<stdio.h>
#include<math.h>

void main()
{
	double x, y;
	x = log10(1.0);
	y = log10(2.0);

	printf("log10:%g, %g\n", x, y);
}
#endif
#if 0 //183 ������ ���ϱ�(sqrt)
#include<stdio.h>
#include<math.h>

void main()
{
	double x, y;
	x = sqrt(16.0);
	y = sqrt(4.0);

	printf("sqrt:%g, %g\n", x, y);
}
#endif
#if 0 //184 ���밪 ���ϱ�(abs)
#include<stdio.h>
#include<math.h>

void main()
{
	double x, y;
	x = abs(1.0);
	y = abs(-2.0);

	printf("abs:%g, %g\n", x, y);
}
#endif
#if 0 //185 �־��� ������ ���� ���� �ּ� ������ ���ϱ�(ceil)
#include<stdio.h>
#include<math.h>

void main()
{
	printf("ceil(1.0) : %g\n", ceil(1.0));
	printf("ceil(1.1) : %g\n", ceil(1.1));
	printf("ceil(1.9) : %g\n", ceil(1.9));
	printf("ceil(2.5) : %g\n", ceil(2.5));
	printf("ceil(-2.5) : %g\n", ceil(-2.5));
	printf("ceil(-3.0) : %g\n", ceil(-3.0));
}
#endif
#if 0 //186 �־��� ������ ũ�� ���� �ּ� ������ ���ϱ�(floor)
#include<stdio.h>
#include<math.h>

void main()
{
	printf("floor(1.0) : %g\n", floor(1.0));
	printf("floor(1.1) : %g\n", floor(1.1));
	printf("floor(1.9) : %g\n", floor(1.9));
	printf("floor(2.5) : %g\n", floor(2.5));
	printf("floor(-2.5) : %g\n",floor(-2.5));
	printf("floor(-3.0) : %g\n",floor(-3.0));
}
#endif
#if 0 //187 �־��� ���� ������ �Ҽ��� �и��ϱ�(modf)
#include<stdio.h>
#include<math.h>
void main()
{
	double x = 2.3, n, y;

	y = modf(x, &n);

	printf("2.3�� ������ �Ҽ��� �и��ϸ�, %g �� %g �Դϴ�.\n", n, y);
}
#endif
#if 0 //188 x�� y�� ���ϱ�(pow)
#include<stdio.h>
#include<math.h>
void main()
{
	double x = 10.0, y=3.0,r;

	r = pow(x, y);
	printf("10^3= %g \n", r);
}
#endif
#if 0 //189 ���� ���ϱ�(srand,rand)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < 5; i++)
	{
		printf("����%d: %d\n",i, rand()%1500+1);
	}	
}
#endif
#if 0 //190 ���� �����ϱ�(qsort)
#include<stdio.h>
#include<stdlib.h>

int intcmp(const void* v1, const void* v2);

void main()
{
	int i;
	int arr[5] = { 1,3,5,4,2 };

	qsort(arr, 5, sizeof(arr[0]), intcmp);

	for (i = 0; i < 5; i++)
	{
		printf("%d", arr[i]);
	}
}
int intcmp(const void* v1, const void* v2)
{
	int cmpvalue1, cmpvalue2;

	cmpvalue1 = *(int*)v1;
	cmpvalue2 = *(int*)v2;

	return cmpvalue1 - cmpvalue2;
}
#endif
#if 0 //191 ���� �˻� ����ϱ�(bsearch)
#include<stdio.h>
#include<stdlib.h>
#include<search.h>

int intcmp(const void* v1, const void* v2);

void main()
{
	int key = 5, * ptr;
	int array[10] = { 150,27,33,1,5,100,99,75,81,10 };
	qsort(array,10,sizeof(array[0]),intcmp);
	ptr = bsearch(&key, array, 10, sizeof(array[0]), intcmp);

	if (ptr)
	{
		puts("5�� ã�ҽ��ϴ�.");
	}
}
int intcmp(const void* v1, const void* v2)
{
	return(*(int*)v1 - *(int*)v2);
}
#endif
#if 0 //192 ��ũ�� ��� �����ϱ�
#include<stdio.h>

#define program void main(void)
#define println printf

#define MAX 1000
#define MIN 0

program
{
	println("MAX:%d,MIN:%d\n",MAX,MIN);
}
#endif
#if 0 //193 ��ũ�� �Լ� �����ϱ�1
#include<stdio.h>

#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
void main()
{
	printf("�ִ밪: %d\n", max(5, 3));
	printf("�ּҰ�: %d\n", min(5, 3));
	printf("�ִ밪: %g\n", max(3.5, 4.4));
	printf("�ּҰ�: %g\n", min(3.5, 4.4));
}
#endif
#if 0 //194 ��ũ�� �Լ� �����ϱ�2
#include<stdio.h>

#define x_i(x,i) printf("x%s�� ���� %d�Դϴ�.\n",#i,x##i)

void main()
{
	int xa = 3, xb = 5;

	x_i(x, a);
	x_i(x, b);
}
#endif
#if 0 //195 ��ũ�� ����� ����Ǿ����� �˻��ϱ�
#include<stdio.h>

//#define COUNT 100

#if !defined COUNT
#define COUNT 90
#endif
void main()
{
	printf("COUNT: %d\n", COUNT);
}
#endif
#if 0 //196 ��ũ�� ������ ���� ����ϱ�
#include<stdio.h>

//#define COUNT 100
#if !defined COUNT
#error"COUNT MACRO is not defined!"
#endif

void main()
{
	printf("COUNT:%d\n", COUNT);
}
#endif
#if 0 //197 ��ũ�� ����� ���� �˻��ϱ�
#include<stdio.h>

#define COUNT 100

#if COUNT !=100
#error "COUNT !=100"
#endif
void main()
{
	printf("COUNT:%d\n", COUNT);
}
#endif
#if 0 //198 ��ũ�� ����� ������ ����ϱ�
#include<stdio.h>

#define COUNT 100

#if defined COUNT
#undef COUNT
#define COUNT 99
#else
#define COUNT 88
#endif

void main()
{
	printf("COUNT:%d\n", COUNT);
}
#endif
#if 0 //199 ��� ������ �߻���Ű�� �ʱ�
#include<stdio.h>
#pragma warning(disable:4101)
void main()
{
	int i;
}
#endif
#if 0 //200 ����� ��ũ�� ����ϱ�
#include<stdio.h>
void main()
{
	printf("���ϸ�:%s\n", __FILE__);
	printf("�� ¥:%s\n", __DATE__);
	printf("�� ��:%s\n", __TIME__);
	printf("�� ��:%d\n", __LINE__);
}
#endif