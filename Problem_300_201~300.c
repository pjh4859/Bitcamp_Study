#if 0 //201 scanf()�Լ� 100% Ȱ���ϱ�(scanf)
#include<stdio.h>
#pragma warning(disable:4996)

#define scan(d,x,y) printf(#d "��(%"#x")�� �Է��ϼ���\n");\
					scanf(#x,&y);\
					printf("scanf%"#x":"#x"\n\n",y)

void main()
{
	char ch = 0;
	short int si = 0;
	int i = 0;
	int o8 = 0;
	int x16 = 0;
	unsigned ui = 0;
	long l = 0;
	float f = 0;
	char s[100] = { 0, };

	scan(char, %c, ch);
	scan(short, %hd, si);
	scan(int, %d, i);
	scan(unsigned, % u, ui);
	scan(long, %d, l);
	scan(8����, %o, o8);
	scan(16����, %x, x16);
	scan(�����Ҽ���, %f, f);
	scan(���ڿ�, %s, s);

	scanf("%4d%3d", &i, &o8);
	printf("%d,%d\n", i, o8);
}
#endif
#if 0 //202 printf() �Լ� 100% Ȱ���ϱ�(printf)
#include<stdio.h>
void main()
{
	int i;
	char* pi;
	char* string = "books";

	//���� ������
	printf("[%c]\n",'A');
	printf("[%d]\n",7);
	printf("[%i]\n",7);
	printf("[%5d]\n",7);
	printf("[%05d]\n",7);
	printf("[%+d]\n",-12345);
	printf("[%+d]\n",12345);
	printf("[%d]\n",-12345);
	printf("[%u]\n",12345);
	printf("[%u]\n",-12345);
	printf("\n");
	//8����, 16����
	printf("[%x]\n", 0xFF);
	printf("[%X]\n", 0xFF);
	printf("[%#x]\n", 0xFF);
	printf("[%#x]\n", 12345);
	printf("[%o]\n", 0123);
	printf("[%#o]\n", 0123);
	printf("\n");

	//���� �Ҽ���
	printf("[%f]\n",3.141592);
	printf("[%5f]\n",3.141592);
	printf("[%.f]\n",3.141592);
	printf("[%.2f]\n",3.141592);
	printf("[%2.2f]\n",3.141592);
	printf("[%5.5f]\n",3.141592);
	printf("[%20.5f]\n",3.141592);
	printf("[%-20.5f]\n",3.141592);
	printf("\n");

	printf("[%e]\n",3.141592);
	printf("[%E]\n",3.141592);
	printf("[%5e]\n",3.141592);
	printf("[%.e]\n",3.141592);
	printf("[%.2e]\n",3.141592);
	printf("[%2.2e]\n",3.141592);
	printf("[%5.5e]\n",3.141592);
	printf("[%20.5e]\n",3.141592);
	printf("[%20.2E]\n",3.141592);
	printf("[%-20.2E]\n",3.141592);
	printf("\n");

	printf("[%g]\n",3.141592);
	printf("\n");

	printf("[%s]\n",string);
	printf("[%10s]\n",string);
	printf("[%-10s]\n",string);
	printf("[%2s]\n",string);
	printf("[%2.2s]\n",string);
	printf("[%3.2s]\n",string);
	printf("[%010s]\n",string);
	printf("\n");

	printf("[%p]\n", &i);
	printf("[%p]\n", &pi);
}
#endif
#if 0 //203 �ﰢ�� ����ϱ�(for)
#include<stdio.h>
void main()
{
	int i, j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
#endif
#if 0 //204 ���� �Է¹޾� Ȧ��/¦�� �����ϱ�(%)
#include<stdio.h>
void main()
{
	int num;

	printf("���ڸ� �Է��ϼ���:");

	scanf_s("%d", &num);

	if (num % 2 == 1)printf("%d�� Ȧ���Դϴ�.\n", num);
	else printf("%d�� ¦���Դϴ�.\n", num);
}
#endif
#if 0 //205 1~100���� Ȧ���� �� ���ϱ�
#include<stdio.h>

void main()
{
	int i; int hap = 0;

	for (i = 0; i <= 100; i++)
	{
		if (i % 2)
		{
			hap += i;
		}
	}
	printf("1~100������ Ȧ���� ��: %d\n", hap);
}
#endif
#if 0 //206 21~50 ������ ���� �߻���Ű��
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	int i, rand_num;

	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		rand_num = rand() % 30 + 21;
		printf("[%d]", rand_num);
	}
}
#endif
#if 0 //207 ������ ���� ����ϱ�(& ������)
#include<stdio.h>

void main()
{
	int i = 127;
	int j = 127;

	printf("%d,%x\n", i, j);
	printf("%#x\n", &i);
	printf("%#x\n", &j);

}
#endif
#if 0 //208 �������� 16���� ���ڿ��� ��ȯ�ϱ�(itoa)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	char buff[100];
	int radix = 16;

	_itoa_s(10, buff,sizeof(buff), radix);
	puts(buff);

	_itoa_s(255, buff,sizeof(buff), radix);
	puts(buff);
}
#endif
#if 0 //209 2����/16���� ���ڿ��� ���������� ��ȯ�ϱ�(strtol)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	char string1[]="1010";
	char string2[]="ff";
	char* stop;
	long value;

	value = strtol(string1, &stop,2);
	printf("2�����ڿ�\"%s\"�� ������ �ٲٸ� %d�Դϴ�.\n", string1, value);

	value = strtol(string2, &stop,16);
	printf("16�����ڿ�\"%s\"�� ������ �ٲٸ� %d�Դϴ�.\n", string2, value);

}
#endif
#if 0 //210 2���� ���ڿ��� 16���� ���ڿ��� ��ȯ�ϱ�(strtol, itoa)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int radix = 16;
	int base = 2;
	char string[] = "10101011";
	char* stop;
	long value;
	char buff[100];

	value = strtol(string, &stop, base);
	_itoa_s(value, buff, sizeof(buff), radix);
	puts(buff);
}
#endif
#if 0 //211 �ҹ��ڸ� �빮�ڷ� ��ȯ�ϱ�
#include<stdio.h>
#include<string.h>

void main()
{
	char string[] = "abcdefghizklmnopqrstuvwxyz";
	unsigned i, len;

	puts(string);
	len = strlen(string);

	for (i = 0; i < len;i++)
	{
		string[i] = string[i] & 0xDF;
	}
	puts(string);
}
#endif
#if 0 //212 ��Ʈ ������ ����Ͽ� �������� 0���� �����
#include<stdio.h>

void main()
{
	int i = -5;
	printf("i=%d\n", i);

	i = i ^ i;

	printf("i=%d\n", i);
}
#endif
#if 0 //213 ��Ʈ ����Ʈ ������ ����Ͽ� ���� �����ϱ�(<<)
#include<stdio.h>
void main()
{
	char value = 2;
	value = value << 2;
	printf("value:%d\n", value);
}
#endif
#if 0 //214 ��Ʈ ����Ʈ ������ ����Ͽ� ������ �����ϱ�(>>)
#include<stdio.h>
void main()
{
	char value = 8;
	value = value >> 2;
	printf("value:%d\n", value);
}
#endif
#if 0 //215 ���ڿ����� Ư�� ���ڿ��� �ε��� ���ϱ�(strstr)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[] = "This is a book";
	char* pos;

	pos = strstr(string, "book");

	if (pos)
	{
		printf("book�� %d ��°���� ã�ҽ��ϴ�.\n", pos - string);
		printf("%s\n", &string[pos - string]);
	}
}
#endif
#if 0 //216 ���ڿ��� �޸��� �������� �и��ϱ�(strtok)
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

void main()
{
	char string[] = "a12,b34,v56 This is a book";
	char* token;

	token=strtok(string, ", ");

	while (token != NULL)
	{
		puts(token);
		token = strtok(NULL, ", ");

	}
}
#endif
#if 0 //217 ���ڿ��� �������� �и��Ͽ� ���� ���� ���ڿ��� �����(strtok)
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

void main()
{
	char string[] = "(a12),(b34),(v56) book";
	char* token;

	token = strtok(string, "(123456), ");

	while (token != NULL)
	{
		puts(token);
		token = strtok(NULL, "(123456), ");

	}
}
#endif
#if 0 //218 ���ڿ����� ���ڸ� �����س���(isdigit)
#include<stdio.h>
#include<ctype.h>
void main()
{
	char* string = "(02) 1111-2233";
	char buff[20] = { 0, };
	int i = 0;

	while (*string)
	{
		if (isdigit(*string))
		{
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);
}
#endif
#if 0 //219 ���ڿ����� ���ĺ��� �����س���(isalpha)
#include<stdio.h>
#include<ctype.h>
void main()
{
	char* string = "(temperature is 333degress man";
	char buff[50] = { 0, };
	int i = 0;

	while (*string)
	{
		if (isalpha(*string))
		{
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);
}
#endif
#if 0 //220 ���ڿ����� �ѱ۸� �����س���
#include<stdio.h>
#include<ctype.h>
void main()
{
	unsigned char* string = "I am �ѱ���� man";
	unsigned char buff[50] = { 0, };
	int i = 0;

	while (*string)
	{
		if (*string>127)
		{
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);
}
#endif
#if 0 //221 ���ĺ��� �ƴ� ù ������ ��ġ �����ϱ�(strspn)
#include<stdio.h>
#include<string.h>
void main()
{
	char* string = "it's good man";
	char* find = "abcdefghijklmnopqrstuvwxyz";
	int nIndex;

	nIndex = strspn(string, find);
	printf("%d ��ġ���� ���ĺ��� �ƴ� ù ���ڸ� ã�ҽ��ϴ�.\n", nIndex);
}
#endif
#if 0 //222 ���ڿ����� ���ڰ� ���۵Ǵ� ��ġ �����ϱ�(strcspn)
#include<stdio.h>
#include<string.h>
void main()
{
	char string[] = "it's good22 man";
	char* find = "0123456789";
	int nIndex;

	nIndex = strcspn(string, find);
	printf("%d ��ġ���� ���ڸ� ã�ҽ��ϴ�.\n", nIndex);
}
#endif
#if 0 //223 ���ڿ��� Ư�� ���� ��ġ���� �߶󳻱�(strchr)
#include<stdio.h>
#include<string.h>
void main()
{
	char string[] = "a.book";
	char* pstr = string, * pfind = string;
	int i = 0;

	while (pfind)
	{
		pfind = strchr(pstr, 'a');

		if (pfind == NULL)
		{
			pfind = strchr(pstr, '.');
			if (pfind)pstr = &string[++i];
		}
		else pstr = &string[++i];
	}
	puts(pstr);
}
#endif
#if 0 //224 ���ڿ��� �¿� ���� �����ϱ�(isspace)
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
	char* string = "123";
	char buff[30] = { 0, };
	int i = 0;

	printf("string�� ����:%d\n", strlen(string));

	while (*string)
	{
		if (!isspace(*string))
		{
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);
	printf("string�� ����:%d\n", strlen(buff));
}
#endif
#if 0 //225 ���ڿ��� �¿� Ư�� ���ڵ� �����ϱ�(strspn,strcspn)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[] = " .;;abc;;. ";
	char* sep = " .;";
	int nIndex1, nIndex2;

	nIndex1 = strspn(string, sep);
	nIndex2 = strcspn(&string[nIndex1], sep);
	(&string[nIndex1])[nIndex2] = 0;
	printf("%s\n", &string[nIndex1]);
}
#endif
#if 0 //226 ���ڿ��� NULL�� ä���(strset)
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
void main()
{
	char buff[] = "��ȣ�� Korea�Դϴ�.";

	puts(buff);
	strset(buff, 0);
	printf("[%s]\n", buff);
}
#endif
#if 0 //227 ���ڿ��� ù ���ڸ� �빮�ڷ� ��ȯ�ϱ�
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main()
{
	char buff[] = "boy is man", * pos = buff;

	while (pos)
	{
		if (isalpha(buff[0]) && pos == buff)
		{
			buff[0] &= 0xDF;
			pos++;
		}
		else if (pos = strpbrk(pos, " "))*++pos &= 0xDF;
	}
	printf(buff);
}
#endif
#if 0 //228 ���ڿ����� Ư�� ��ġ�� ���� ��ü�ϱ�(strnset)
#include<stdio.h>
#include<string.h>
#pragma	warning(disable:4996)
void main()
{
	char string[] = "��ȣ�� Korea�Դϴ�.";
	char* pstr;

	pstr = strstr(string, "Korea");
	if (pstr)
	{
		strnset(pstr, '*', 5);
		
	}
	puts(string);
}
#endif
#if 0 //229 ���ڿ��� ���� �ӽ� ����� �����(strdup)
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#pragma	warning(disable:4996)
void main()
{
	char buff[] = "���ڿ� �����ϱ�";
	char* dup;

	dup = strdup(buff);
	if (dup)
	{
		strcpy(buff, "�ٸ� ���ڿ�");
		puts(buff);
		puts(dup);
		free(dup);
	}
}
#endif
#if 0 //230 �޸𸮸� 1MB �Ҵ��ϰ� �����ϱ�(malloc, free)
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#pragma	warning(disable:4996)

void main()
{
	char* pbuf;

	pbuf = malloc(100 * 10000);

	if (pbuf)
	{
		memset(pbuf, 0, 100 * 10000);
		strcpy(&pbuf[0], "����� ��õ�� ��");
		puts(&pbuf[0]);
		free(pbuf);
	}
}
#endif
#if 0 //231 �޸𸮸� 100MB �Ҵ��ϰ� �����ϱ�
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#pragma	warning(disable:4996)
#define MEGA_BYTE 1048576
void main()
{
	char* pbuf;

	pbuf = malloc(100 * MEGA_BYTE);

	if (pbuf)
	{
		memset(pbuf, 0, 100 * MEGA_BYTE);
		strcpy(&pbuf[0], "����� ��õ�� ��");
		puts(&pbuf[0]);
		strcpy(&pbuf[104857500], "�λ�� ������ ������1");
		puts(&pbuf[104857500]);
		free(pbuf);
	}
}
#endif
#if 0 //232 void�� �����͸� ����� �پ��� �迭 �����ϱ�
#include<stdio.h>

void array_copy(void* dest, const void* src, int size);

void main()
{
	char array1[100] = "array of char";
	char array2[100] = { 0, };
	int array3[5] = { 1,2,3,4,5 };
	int array4[5] = { 0, };

	printf("array1:[%s]\n", array1);
	printf("array2:[%s]\n", array2);
	printf("array3:[%d]\n", array3[0]);
	printf("array4:[%d]\n", array4[0]);

	array_copy(array2, array1, sizeof(array1));
	array_copy(array4, array3, sizeof(array3));

	printf("array1:[%s]\n", array1);
	printf("array2:[%s]\n", array2);
	printf("array3:[%d]\n", array3[0]);
	printf("array4:[%d]\n", array4[0]);
}
void array_copy(void* dest, const void* src, int size)
{
	while (size--)
	{
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)++;
	}
}
#endif
#if 1 //233 �ؽ�Ʈ ������ �� �پ� ����(fopen,fputs,fclose)
#include<stdio.h>
void main()
{

}
#endif