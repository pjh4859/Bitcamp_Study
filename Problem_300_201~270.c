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
#if 0 //233 �ؽ�Ʈ ������ �� �پ� ����(fopen,fputs,fclose)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp,"D:\\C_code\\hii.txt", "w+");

	if (fp != NULL)
	{
		fputs("���ѹα�\n", fp);
		fputs("���ѹα�\n", fp);
		fputs("���ѹα�\n", fp);
		fputs("���ѹα�\n", fp);
		fputs("���ѹα�\n", fp);
		fclose(fp);
	}
}
#endif
#if 0 //234 �ؽ�Ʈ ������ �� �پ� �б�(fgets)
#include<stdio.h>
void main()
{
	FILE* fp;
	char buff[100];

	fopen_s(&fp, "D:\\C_code\\hii.txt", "r");

	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fgets(buff, 100, fp);
			printf(buff);
		}
		fclose(fp);
	}
}
#endif
#if 0 //235 �ؽ�Ʈ ���� ����(fwrite)
#include<stdio.h>
void main()
{
	FILE* fp;
	char* string = "�츮����\n";

	fopen_s(&fp, "D:\\C_code\\hii2.txt", "w+");

	if (fp != NULL)
	{
		fwrite(string, 1, strlen(string), fp);
		fwrite(string, 1, strlen(string), fp);
		fwrite(string, 1, strlen(string), fp);
		fclose(fp);
	}
}
#endif
#if 0 //236 �ؽ�Ʈ ���� �б�(fread)
#include<stdio.h>
void main()
{
	FILE* fp;
	char buff[100] = { 0, };
	int len;

	fopen_s(&fp, "D:\\C_code\\hii2.txt", "r");

	if (fp != NULL)
	{
		while (!feof(fp))
		{
				len = fread(buff, 1, 9, fp);
			if (ferror(fp) || len < 9) break;
			printf("read: %d, %s", len, buff);
		}
		fclose(fp);
	}
}
#endif
#if 0 //237 ���� ���� ����(fwrite)
#include<stdio.h>
void main()
{
	FILE* fp;
	char buff[5];

	fopen_s(&fp, "D:\\C_code\\bin.txt", "w+b");
	
	buff[0] = '@';
	buff[1] = 0;
	buff[2] = 0x112;
	buff[3] = 0x03;
	buff[4] = 0x61;

	if (fp != NULL)
	{
		fwrite(buff, 1, 5, fp);
		fclose(fp);
	}
}
#endif
#if 0 //238 ���� ���� �б�(fread)
#include<stdio.h>
void main()
{
	FILE* fp;
	char buff;

	fopen_s(&fp, "D:\\C_code\\bin.txt", "rb");
	
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fread(&buff, 1, 1, fp);
			if (!feof(fp))printf("%d(%#x)", buff, buff);
		}
		fclose(fp);
	}
}
#endif
#if 0 //239 ������ �ٸ� ���͸��� �̵��ϱ�(rename)
#include<stdio.h>
void main()
{
	char* filename = "D:\\C_code\\file2.txt";
	char* movefile = "D:\\C_code\\aa\\file!!.txt";

	if (rename(filename, movefile) != 0)
	{
		perror("���� �̵� ����");
	}
	else
	{
		puts("������ �̵��Ǿ����ϴ�.");
	}
}
#endif	
#if 0 //240 ���� �����ϱ�(fread, fwrite)
#include<stdio.h>
void main()
{
	FILE* fpR, * fpW;
	char buff;
	int len;

	fopen_s(&fpR, "D:\\C_code\\aa\\bin2.txt","rb");

	if (fpR == NULL)
	{
		perror("���� �б� ���� ����");
		return;
	}
	fopen_s(&fpW, "D:\\C_code\\aa\\abc.txt","w+b");
	
	if (fpW == NULL)
	{
		perror("���� ���� ���� ����");
		fclose(fpR);
		return;
	}
	while (!feof(fpR))
	{
		len = fread(&buff, 1, 1, fpR);
		if (ferror(fpR))
		{
			perror("���� �б� ����");
			_fcloseall();
			return;
		}
		if (len>0)//if(!feof(fpR))
		{
			fwrite(&buff, 1, 1, fpW);
			if (ferror(fpW))
			{
				perror("���� ���� ����");
				_fcloseall();
				return;
			}
		}
	}
	_fcloseall();
	puts("������ ���������� �����Ͽ����ϴ�.");	
}
#endif	
#if 0 //241 �� ���� ���� ��ġ��
#include<stdio.h>

#define FILEREAD 4096

void main()
{
	FILE* fpR1, * fpR2, * fpW;
	char buff[FILEREAD];
	int len;

	fopen_s(&fpR1, "D:\\C_code\\aa\\bin3.txt", "rb");

	if (fpR1 == NULL)
	{
		perror("���� �б� ���� ����");
		return;
	}
	fopen_s(&fpR2, "D:\\C_code\\aa\\bin2.txt", "rb");
	
	if (fpR2 == NULL)
	{
		perror("���� �б� ���� ����");
		_fcloseall();
		return;
	}
	fopen_s(&fpW, "D:\\C_code\\aa\\Output01.txt", "w+b");

	if (fpW == NULL)
	{
		perror("���� ���� ���� ����");
		_fcloseall();
		return;
	}
	while (!feof(fpR1))
	{
		len = fread(buff, 1, FILEREAD, fpR1);
		if (ferror(fpR1))
		{
			perror("���� �б� ���� 1");
			_fcloseall();
			return;
		}
		if (len > 0)
		{
			fwrite(buff, 1, len, fpW);
			if (ferror(fpW))
			{
				perror("���� ���� ����1");
				_fcloseall();
				return;
			}
		}
	}
	while (!feof(fpR2))
	{
		len = fread(buff, 1, FILEREAD, fpR2);
		if (ferror(fpR2))
		{
			perror("���� �б� ����2");
			_fcloseall();
			return;
		}
		if (len > 0)
		{
			fwrite(buff, 1, len, fpW);
			if (ferror(fpW))
			{
				perror("���� ���� ���� 2");
				_fcloseall();
				return;
			}
		}
	}
	_fcloseall();
	puts("������ ���������� ���������ϴ�.");
}
#endif
#if 0 //242 ���Ͽ��� Ư�� ���ڿ� �˻��ϱ�(strstr)
#include<stdio.h>
#include<string.h>

void main()
{
	FILE* fp;
	char buff[200];
	int line = 1;

	fopen_s(&fp, "D:\\C_code\\aa\\uuu.txt", "r");

	if (fp == NULL)
	{
		perror("���� �б� ���� ����");
		return;
	}

	while (!feof(fp))
	{
		fgets(buff, 200, fp);

		if (strstr(buff, "coke"))
		{
			printf("Line(%2d):%s", line, buff);
		}
		line++;
	}
	_fcloseall();
}
#endif
#if 0 //243 ���Ͽ��� Ư�� ���ڿ� ��ü�ϱ�
//�� ���������� �Ⱦ�����.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#pragma warning(disable:4996)

void main()
{
	FILE* fpR, * fpW;
	char buff[200];
	char* pbuf, * dup;
	int len, pos1, pos2;

	fopen_s(&fpR, "D:\\C_code\\aa\\uuu.txt", "r");

	if (fpR == NULL)
	{
		perror("���� �б� ���� ����");
		return;
	}
	fopen_s(&fpW, "D:\\C_code\\aa\\uuu_change.txt", "w+");

	if (fpW == NULL)
	{
		perror("���� ���� ���� ����");
		_fcloseall();
		return;
	}

	while (!feof(fpR))
	{
		fgets(buff, 200, fpR);
		pbuf = strstr(buff, "coke");
		if (pbuf)
		{
			len = strlen(buff);
			pos1 = pbuf - buff;

			dup = strdup(buff);
			strnset(&buff[pos1], 0, len - pos1);
			strcat(buff, "pepsi");

			pos1 = pbuf - buff + strlen("coke");
			pos2 = pbuf - buff + strlen("pepsi");

			strcpy(&buff[pos2], &dup[pos1]);
			free(dup);
		}
		if (!feof(fpR))fputs(buff, fpW);
	}
	_fcloseall();
	puts("replace coke to pepsi all.");
}
#endif
#if 0 //244 ��/��/��/ ��:��:�� ����ϱ�(time, localtime)
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)

void main()
{
	FILE* fp;
	char buff[200];
	time_t now;
	struct tm t;

	fopen_s(&fp, "D:\\C_code\\aa\\date1.txt", "w+");

	if (fp == NULL)
	{
		perror("���� ���� ���� ����");
		_fcloseall();
		return;
	}
	now = time(NULL);
	t = *localtime(&now);
	sprintf(buff, "%d/%d/%d %d:%d:%d",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);

	fputs(buff, fp);
	_fcloseall();

	puts(buff);
	puts("�ð��� D:\\C_code\\aa\\date1.txt�� �����Ͽ����ϴ�.");
}
#endif
#if 0 //245 ����Ϸκ��� ���ñ����� ����� �� ���ϱ�(mktime)
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)

#define DAYSEC (24*60*60)

void main()
{
	time_t n1, n2;
	struct tm t1, t2;
	double elapsed;

	t1.tm_year = 91;
	t1.tm_mon = 11 - 1;
	t1.tm_mday = 1;
	t1.tm_hour = 0;
	t1.tm_min = 0;
	t1.tm_sec = 0;

	n1 = time(NULL);
	t2 = *localtime(&n1);
	
	n1 = mktime(&t1);
	n2 = mktime(&t2);

	n2 = n2 - n1;
	elapsed = (double)(n2/DAYSEC);
	printf("������ �¾ �� %.2lf��° �Դϴ�.\n", elapsed);
}
#endif
#if 0 //246 �� ���� ������ ��¥ ���ϱ�(mktime)
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)

#define DAYSEC 86400L

void main()
{
	int i;
	time_t now;
	struct tm t1, t2;
	int n1, n2, last;

	now = time(NULL);
	t1 = *localtime(&now);
	t1.tm_mday = 1;
	t2 = t1;

	for (i = 0; i <= 11; i++)
	{
		t1.tm_mon = i;
		t2.tm_mon = i + 1;
		n1 = mktime(&t1);
		n2 = mktime(&t2);
		last = (n2 - n1) / DAYSEC;
		printf("%d�� %2d���� ������ ��¥�� %d ���Դϴ�.\n",
			t1.tm_year + 1900, t1.tm_mon + 1, last);
	}
}
#endif
#if 0 //247 D-Day ���ϱ�(mktime)
#include<stdio.h>
#include<time.h>
#define DAYSEC 86400L
#pragma warning(disable:4996)


void main()
{
	time_t now;
	struct tm t, dday = { 0,0,0,8,8,2020 };
	int n1, n2, nDday;

	now = time(NULL);
	t = *localtime(&now);

	dday.tm_year -= 1900;
	dday.tm_mon -= 1;

	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;

	n1 = mktime(&t);
	n2 = mktime(&dday);

	nDday = (n2 - n1) / DAYSEC;

	printf("������ ��¥�� %s", ctime(&now));
	printf("�ּ����� ����:%d�� ���ҽ��ϴ�.(%d/%d/%d)\n",
		nDday, dday.tm_year + 1900, dday.tm_mon + 1, dday.tm_mday);
}
#endif
#if 0 //248 ���� ��¥�κ��� ũ�������������� ���� �ð� ���ϱ�
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)

void main()
{
	time_t now;
	struct tm t, christmas = { 0,0,0,25,12,2020 };
	int n1, n2;
	__int64	nChristmas;

	now = time(NULL);
	t = *localtime(&now);

	christmas.tm_year -= 1900;
	christmas.tm_mon -= 1;

	n1 = mktime(&t);
	n2 = mktime(&christmas);

	nChristmas = (n2 - n1);
	christmas = *localtime(&nChristmas);

	printf("������ ��¥�� %s", ctime(&now));
	printf("ũ������������ ���� �ð��� %d���� %d�� %d�ð� %d�� %d���Դϴ�.\n",
		christmas.tm_mon, christmas.tm_mday, christmas.tm_hour,
		christmas.tm_min, christmas.tm_sec);
}
#endif
#if 0 //249 ���� ��¥�� ������ ��¥ ���ϰ� ����
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)

void main()
{
	time_t now;
	struct tm t, tb;

	now = time(NULL);
	t = *localtime(&now);

	tb = t;

	t.tm_mon += 100;
	t.tm_mday += 90;
	t.tm_hour += 80;

	mktime(&t);

	printf("���� ��¥��%d/%d/%d %d:%d:%d �Դϴ�.\n",
		tb.tm_year + 1900, tb.tm_mon + 1, tb.tm_mday,
		tb.tm_hour, tb.tm_min, tb.tm_sec);

	printf("100���� 90�� 80�ð��� ���� ��¥�� %d/%d/%d %d:%d:%d�Դϴ�.\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);

	tb.tm_mon -= 100;
	tb.tm_mday -= 90;
	tb.tm_hour -= 80;

	mktime(&tb);
	printf("100���� 90�� 80�ð��� �� ��¥�� %d/%d/%d %d:%d:%d�Դϴ�.\n",
		tb.tm_year + 1900, tb.tm_mon + 1, tb.tm_mday,
		tb.tm_hour, tb.tm_min, tb.tm_sec);
}
#endif
#if 0 //250 ũ���������� ���� ���ϱ�
#include<stdio.h>
#include<time.h>

void main()
{
	struct tm christmas = { 0,0,0,25,12 - 1,2019 - 1900 };
	char* wday[] = { "��","��","ȭ","��","��","��","��" };
	char buff[100];

	mktime(&christmas);

	strftime(buff, sizeof(buff), "2020�� 12�� 25���� %A�Դϴ�.",&christmas);

	puts(buff);
	printf("2020�� 12�� 25���� %s�����Դϴ�.\n", wday[christmas.tm_wday]);
}
#endif
#if 0 //251 ���� ǥ�� �ÿ� ���� ǥ�� ���� �ð� �� ���ϱ�(localtime)
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)

void main()
{
	time_t now, n1, n2;
	struct tm t1, t2;

	time(&now);
	t1 = *localtime(&now);
	t2 = *gmtime(&now);

	n1 = mktime(&t1);
	n2 = mktime(&t2);

	printf("UT�� �ѱ� LT�ð�����:%g �ð� \n", difftime(n1, n2) / 3600.);
}
#endif
#if 0 //252 5�ʰ� �����ϴ� �Լ� �����ϱ�(clock)
#include<stdio.h>
#include<time.h>
void sleep(int sec);

void main()
{
	time_t n1, n2;

	time(&n1);
	sleep(5);
	time(&n2);

	printf("%g�ʰ� �����Ǿ����ϴ�.\n", difftime(n2, n1));

}
void sleep(int sec)
{
	clock_t ct;
	ct = clock();
	while (ct + CLK_TCK * sec > clock());
}
#endif
#if 0 //253 �� �ð� ���� ���� ���ϱ�(mktime)
#include<stdio.h>
#include<time.h>

void main()
{
	struct tm t1, t2;
	int n1, n2, n3;

	t1.tm_year = 2020 - 1900;
	t1.tm_mon = 6 - 1;
	t1.tm_mday = 15;
	t1.tm_hour = 1;
	t1.tm_min = 12;
	t1.tm_sec = 50;

	t2.tm_year = 2020 - 1900;
	t2.tm_mon = 6 - 1;
	t2.tm_mday = 15;
	t2.tm_hour = 3;
	t2.tm_min = 35;
	t2.tm_sec = 22;

	n1 = mktime(&t1);
	n2 = mktime(&t2);

	n3 = n2 - n1;

	printf("�ð� 1:%4d-%02d-%02d %02d:%02d:%02d\n",
		t1.tm_year + 1900, t1.tm_mon + 1, t1.tm_mday,
		t1.tm_hour, t1.tm_min, t1.tm_sec);

	printf("�ð� 2:%4d-%02d-%02d %02d:%02d:%02d\n",
		t2.tm_year + 1900, t2.tm_mon + 1, t2.tm_mday,
		t2.tm_hour, t2.tm_min, t2.tm_sec);

	printf("�ð�����: %d:%d:%d\n",
		n3 / 3600, (n3 - ((n3 / 3600) * 3600)) / 60, n3 % 60);
}
#endif
#if 0 //�� ��¥ ���� ���� ���ϱ�(mktime)
#include<stdio.h>
#include<time.h>
#pragma warning(disable:4996)

void main()
{
	struct tm t1, t2, t3;
	int n1, n2;
	__int64	n3;

	t1.tm_year = 2020 - 1900;
	t1.tm_mon = 6 - 1;
	t1.tm_mday = 23;
	t1.tm_hour = 1;
	t1.tm_min = 12;
	t1.tm_sec = 50;

	t2.tm_year = 2020 - 1900;
	t2.tm_mon = 8 - 1;
	t2.tm_mday = 19;
	t2.tm_hour = 3;
	t2.tm_min = 35;
	t2.tm_sec = 22;

	n1 = mktime(&t1);
	n2 = mktime(&t2);

	n3 = n2 - n1;
	t3 = *gmtime(&n3);
	t3.tm_year -= 70;

	printf("�ð� 1:%4d-%02d-%02d %02d:%02d:%02d\n",
		t1.tm_year + 1900, t1.tm_mon + 1, t1.tm_mday,
		t1.tm_hour, t1.tm_min, t1.tm_sec);

	printf("�ð� 2:%4d-%02d-%02d %02d:%02d:%02d\n",
		t2.tm_year + 1900, t2.tm_mon + 1, t2.tm_mday,
		t2.tm_hour, t2.tm_min, t2.tm_sec);

	printf("��¥���� :%4d-%02d-%02d %02d:%02d:%02d\n",
		t3.tm_year + 1900, t3.tm_mon + 1, t3.tm_mday,
		t3.tm_hour, t3.tm_min, t3.tm_sec);
}
#endif
#if 0 //255 ������ ����� ��¥ �� ���ϱ�(localtime)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	struct tm t;

	now = time(NULL);
	localtime_s(&t, &now);

	printf("������ ����ϼ� : %d\n", t.tm_yday);
}
#endif
#if 0 //256 ������ ����� ���� �� ���ϱ�(strftime)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	struct tm t;
	char buff[100];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "������ ����� ��:%U��", &t);
	puts(buff);
}
#endif
#if 0 //257 ������ ���� ���ϱ�
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	struct tm t;
	char buff[100];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "����:%A", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "����:%a", &t);
	puts(buff);
	printf("%d\n", t.tm_wday);
}
#endif
#if 0 //258 ����/���� ǥ���ϱ�
#include<stdio.h>
#include<time.h>
#include<string.h>

void main()
{
	time_t now;
	struct tm t;
	char buff[100],AMPM[10];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", &t);
	strftime(AMPM, sizeof(AMPM), "%p", &t);
	
	if (strcmp(buff, "AM"))strcpy_s(AMPM,sizeof(AMPM), "����");
	else if (strcmp(buff, "PM"))strcpy_s(AMPM, sizeof(AMPM), "����");
	strcat_s(buff,sizeof(buff), AMPM);

	puts(buff);
}
#endif
#if 0 //259 AM/PM ǥ���ϱ�
#include<stdio.h>
#include<time.h>
#include<string.h>

void main()
{
	time_t now;
	struct tm t;
	char buff[100], AMPM[10];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", &t);
	strftime(AMPM, sizeof(AMPM), "%p", &t);
	puts(buff);

	if (strcmp(buff, "����"))strcpy_s(AMPM, sizeof(AMPM), "AM");
	else if (strcmp(buff, "����"))strcpy_s(AMPM, sizeof(AMPM), "PM");
	strcat_s(buff, sizeof(buff), AMPM);

	puts(buff);
}
#endif
#if 0 //260 ���ڿ��� �� ��¥�� time_t �������� ��ȯ�ϱ�(atio, mktime)
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void main()
{
	char date[] = "2020-06-23";
	time_t now;
	struct tm t = { 0, };

	t.tm_mday = atoi(&date[8]);
	t.tm_mon = atoi(&date[5]) - 1;
	t.tm_year = atoi(&date[0]) - 1900;

	now = mktime(&t);
	printf("2020-06-23�� time_t�� ��ȯ�ϸ� %lld\n",now);
}
#endif
#if 0 //261 ���ڿ��� �� ��¥�� struct tm �������� ��ȯ�ϱ�
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void main()
{
	char date[] = "2020-06-23 02:09:21";
	struct tm t = { 0, };

	t.tm_sec = atoi(&date[17]);
	t.tm_min = atoi(&date[14]);
	t.tm_hour = atoi(&date[11]);
	t.tm_mday = atoi(&date[8]);
	t.tm_mon = atoi(&date[5]) - 1;
	t.tm_year = atoi(&date[0]) - 1900;

	mktime(&t);
	printf("struct tm ��ȯ �� ��¥: %4d-%02d-%02d %02d:%02d:%02d\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);
}
#endif
#if 0 //262 ��¥ �� �ð��� �پ��� ������� ����ϱ�(_ftime)
#include<stdio.h>
#include<time.h>
#include<sys/timeb.h>
#pragma warning(disable:4996)

void main()
{
	struct _timeb tb;
	struct tm t;
	char buff[100];

	_ftime(&tb);

	localtime_s(&t, &tb.time);

	printf("%4d-%d-%d %d:%d:%d.%d\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec, tb.millitm);

	printf(ctime(&tb.time));
	printf(asctime(&t));
	puts(_strdate(buff));
	puts(_strtime(buff));
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S %p(%a)", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%#Y-%#m-%#d %#H:%#M:%#S %p(%a)", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%c", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%x %X", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%#c", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%#x", &t);
	puts(buff);
}
#endif
#if 0 //263 �߱� ���� �����
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<memory.h>
#pragma warning(disable:4996)

void main()
{
	int com[3] = { 0, };
	int gamer[3] = { 0, };
	int guess[10] = { 0, };
	int count, i;
	int strike, ball;
	char yesno;

	srand(time(NULL));

	puts("�߱� ������ �����մϴ�.");

	while (1)
	{
		com[0] = rand() % 10;
		com[1] = rand() % 10;
		com[2] = rand() % 10;
		count = 1;

		if (com[0] == com[1] || com[0] == com[2] || com[1] == com[2])continue;

		puts("����0~9�� �������� �и��Ͽ� 3�� �Է��ϰ� ����Ű�� ġ����!!");

		memset(guess, 0, sizeof(guess));

		while (1)
		{
			strike = 0; ball = 0;

			for (i = 0; i < 10; i++)
			{
				printf("%d", guess[i]);
			}
			printf("\n���� ����[0~9]�� �Է��ϼ���:");

			scanf("%d %d %d", &gamer[0], &gamer[1], &gamer[2]);

			if (com[0] == gamer[0])strike++;
			else if (com[0] == gamer[1] || com[0] == gamer[2])ball++;
			
			if (com[1] == gamer[1])strike++;
			else if (com[1] == gamer[0] || com[1] == gamer[2])ball++;

			if (com[2] == gamer[2])strike++;
			else if (com[2] == gamer[0] || com[2] == gamer[1])ball++;

			if (gamer[0] > 9 || gamer[1] > 9 || gamer[2] > 9)
			{
				puts("�Է��� ���ڰ� �ʹ� Ů�ϴ�. 0~9�� �Է��ϼ���.");
				continue;
			}

			guess[gamer[0]] = 1;
			guess[gamer[1]] = 1;
			guess[gamer[2]] = 1;

			printf("\n[%2dȸ] %d ��Ʈ����ũ %d �� \n\n", count, strike, ball);
			if (strike == 3)break;
			count++;
		}
		fflush(stdin);

		printf("������ ����Ͻðڽ��ϱ�(y/n)?");
		scanf("%c", &yesno);
		if (yesno == 'N' || yesno == 'n')break;
	}
}
#endif
#if 0 //264 ���� �����ϱ�
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int push(int value);
int pop(int* value);

#define STACK_MAX 100

typedef struct tagStack
{
	int array[STACK_MAX];
	int top;
	int bottom;
}STACK;

STACK s;

void main()
{
	char buff[100], tmp[100];
	char* op = "+-*/%";
	int index;
	int value1 = 0, value2 = 0;

	s.top = STACK_MAX;

	puts("������ 1 * 2ó�� �Է��ϰ� ����Ű�� ġ����.");
	puts("�ƹ��͵� �Է����� ������ ����� ����˴ϴ�.");

	for (;;)
	{
		printf("����:");
		gets(buff);

		if (strlen(buff) == 0)break;

		memset(tmp, 0, sizeof(tmp));

		index = strcspn(buff, op);

		memcpy(tmp, buff, index);

		value1 = atoi(tmp);
		value2 = atoi(&buff[index + 1]);

		switch (buff[index])
		{
		case'+':value1 += value2; break;
		case'-':value1 -= value2; break;
		case'*':value1 *= value2; break;
		case'/':value1 /= value2; break;
		case'%':value1 %= value2; break;
		default:
			puts("�߸��� �����ڸ� ����Ͽ����ϴ�.");
			continue;
		}

		if(push(value1) == -1)
		{
			puts("�� �̻� ������ �� �����ϴ�.");
		}
		printf("%s=%d,s.top=%d\n\n", buff, value1, s.top);

	}
	value1 = 0;

	for (;;)
	{
		if (pop(&value2) == -1)break;
		value1 += value2;
	}
	printf("����� ������ %d�Դϴ�.\n", value1);
}
int push(int value)
{
	if (s.top == 0)return -1;
	s.array[--s.top] = value;
	return 0;
}

int pop(int* value)
{
	if (s.top == STACK_MAX)return-1;
	*value = s.array[s.top++];
	return 0;
}
#endif
#if 0 //265 ť �����ϱ�
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int add(int value);
int delete(int* value);

#define QUEUE_MAX 100

typedef struct tagQueue
{
	int array[QUEUE_MAX];
	int front;
	int rear;
}QUEUE;

QUEUE q;

void main()
{
	char buff[100], tmp[100];
	char* op = "+-*/%";
	int index;
	int value1 = 0, value2 = 0;

	q.front = q.rear = 0;

	puts("������ 1 * 2ó�� �Է��ϰ� ����Ű�� ġ����.");
	puts("�ƹ��͵� �Է����� ������ ����� ����˴ϴ�.");

	for (;;)
	{
		printf("����:");
		gets(buff);

		if (strlen(buff) == 0)break;

		memset(tmp, 0, sizeof(tmp));

		index = strcspn(buff, op);

		memcpy(tmp, buff, index);

		value1 = atoi(tmp);
		value2 = atoi(&buff[index + 1]);

		switch (buff[index])
		{
		case'+':value1 += value2; break;
		case'-':value1 -= value2; break;
		case'*':value1 *= value2; break;
		case'/':value1 /= value2; break;
		case'%':value1 %= value2; break;
		default:
			puts("�߸��� �����ڸ� ����Ͽ����ϴ�.");
			continue;
		}
		if (add(value1) == -1)
		{
			puts("�� �̻� �߰��� �� �����ϴ�.");
		}
		printf("%s=%d,q.rear = %d\n\n", buff, value1, q.rear);
	}
	value1 = 0;

	for (;;)
	{
		if (delete(&value2) == -1)break;

		value1 += value2;
	}
	printf("����� ������ %d �Դϴ�.\n", value1);

}
int add(int value)
{
	if (q.rear == QUEUE_MAX)return -1;
	q.array[q.rear++] = value;
	return 0;
}
int delete(int* value)
{
	if (q.front == q.rear || q.front == QUEUE_MAX)return -1;
	*value = q.array[q.front++];
	return 0;
}
#endif
#if 0 //266 ���� ��ũ�� ����Ʈ �����ϱ�
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#pragma warning(disable:4996)

int add_list(char* name, char* tel, char* addr);
void print_list(void);
void remove_list(void);

typedef struct tagLinkedList
{
	char name[30];
	char tal[30];
	char addr[100];

	struct tagLinkedList* next;
}ADDR;

ADDR* g_pAddrHead = NULL;

void main()
{
	add_list("ȫ�浿", "1111", "���� ���α�");
	add_list("���", "2222", "���� ������");
	add_list("�糪", "3333", "���� ���α�");
	add_list("����", "4444", "���� ����");
	add_list("����", "5555", "���� ����");

	print_list();
	remove_list();
}

int add_list(char* name, char* tel, char* addr)
{
	ADDR* plocal, * pn = g_pAddrHead;

	if (g_pAddrHead == NULL)
	{
		g_pAddrHead = malloc(sizeof(ADDR));

		if (g_pAddrHead == NULL)
		{
			return 0;
		}
		g_pAddrHead->next = NULL;
		plocal = g_pAddrHead;
	}
	else
	{
		plocal = malloc(sizeof(ADDR));

		if (plocal == NULL)
		{
			return 0;
		}
		while (pn->next)
		{
			pn = pn->next;
		}
		pn->next = plocal;
		plocal->next = NULL;
	}
	strcpy(plocal->name, name);
	strcpy(plocal->tal, tel);
	strcpy(plocal->addr, addr);

	return 1;
}

void print_list()
{
	int count = 1;
	ADDR* plist;

	plist = g_pAddrHead;

	while (plist)
	{
		printf("No. %d\n", count++);
		puts(plist->name);
		puts(plist->tal);
		printf("%s\n\n", plist->addr);

		plist = plist->next;
	}
}

void remove_list()
{
	ADDR* plocal;

	while (g_pAddrHead)
	{
		plocal = g_pAddrHead->next;

		free(g_pAddrHead);
		g_pAddrHead = plocal;
	}
}
#endif
#if 0 //267 ���� ��ũ�� ����Ʈ �����ϱ�
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#pragma warning(disable:4996)

int add_list(char* name, char* tel, char* addr);
void print_list(void);
void remove_list(void);

typedef struct tagLinkedList
{
	char name[30];
	char tel[30];
	char addr[100];

	struct tagLinkedList* prev;
	struct tagLinkedList* next;
}ADDR;

ADDR* g_pAddrHead = NULL;

void main(void)
{
	add_list("�糪", "1111", "����Ư���� ���α�");
	add_list("�̳�", "2222", "����Ư���� ������");
	add_list("���", "3333", "����Ư���� ���α�");
	add_list("����", "4444", "����Ư���� ������");
	add_list("��ȿ", "5555", "���������� ����");

	print_list();
	remove_list();
}
int add_list(char* name, char* tel, char* addr)
{
	ADDR* plocal;

	if (g_pAddrHead == NULL)
	{
		g_pAddrHead = malloc(sizeof(ADDR));

		if (g_pAddrHead == NULL)
		{
			return 0;
		}
		g_pAddrHead->prev = NULL;
		g_pAddrHead->next = NULL;
	}
	else
	{
		plocal = malloc(sizeof(ADDR));

		if (plocal == NULL)
		{
			return 0;
		}
		g_pAddrHead->next = plocal;
		plocal->prev = g_pAddrHead;
		g_pAddrHead = plocal;
		g_pAddrHead->next = NULL;
	}

	strcpy(g_pAddrHead->name, name);
	strcpy(g_pAddrHead->tel, tel);
	strcpy(g_pAddrHead->addr, addr);

	return 1;
}

void print_list(void)
{
	int count = 1;
	ADDR* plocal;

	plocal = g_pAddrHead;
	while (plocal->prev	)
	{	
		plocal = plocal->prev;
	}
	while (plocal)
	{
		printf("No.%d\n", count++);
		puts(plocal->name);
		puts(plocal->tel);
		printf("%s \n\n", plocal->addr);
		
		plocal = plocal->next;
	}
}

void remove_list()
{
	ADDR* plocal;

	while (g_pAddrHead->prev)
	{
		g_pAddrHead = g_pAddrHead->prev;
	}

	while (g_pAddrHead)
	{
		plocal = g_pAddrHead->next;

		free(g_pAddrHead);
		g_pAddrHead = plocal;
	}
	g_pAddrHead = NULL;
}
#endif
#if 1 //268 �ּҷ� �����ϱ�
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<conio.h>
#pragma warning(disable:4996)

#define ADDRFILE "D:\\C_code\\addrlist.txt"

typedef struct tagLinkedList
{
	char name[30];
	char tel[30];
	char addr[100];

	struct tagLinkedList* prev;
	struct tagLinkedList* next;
}ADDR;

ADDR* g_pAddrHead = NULL;
ADDR* g_pFind;
int g_bSaved = 1;

void get_addrlist();
int add_list(const ADDR* addr);
int find_list(const char* name);
void SetHeadPosition();
void SetTailPosition();

void Add_addr();
void Find_addr();
void Modify_addr();
void Delete_addr();
void Print_addr();
void Save_addr();
void Remove_addr();

void main()
{
	int ch;

	get_addrlist();

	puts("�ּҷ� ���α׷� Version 1.0");

	while (1)
	{
		printf("\n[1]��� [2]�˻� [3]���� [4]���� [5]��� [S]���� [Q]����");

		ch = getch();

		switch (ch)
		{
		case '1':Add_addr(); break;
		case '2':Find_addr(); break;
		case '3':Modify_addr(); break;
		case '4':Delete_addr(); break;
		case '5':Print_addr(); break;
		case 's':
		case 'S':Save_addr(); break;
		case 'q':
		case 'Q':
			if (g_bSaved == 0)
			{
				printf("\n\n����� �ּ� �����͸� �����Ͻðڽ��ϱ�(y/n)?");
				ch = getchar();
				if (ch == 'Y' || ch == 'y')Save_addr();
			}
			
			Remove_addr(); return;
		default:printf("\n\n1~5 �Ǵ� S/Q�� �����ʽÿ�.\n\n"); break;
		}
	}
}
void get_addrlist()
{
	ADDR addr;
	FILE* fp;

	fopen_s(&fp, ADDRFILE, "rb");

	if (fp == NULL)
	{
		perror("���� ���� ����");
		return;
	}

	while (!feof(fp))
	{
		fread(&addr, sizeof(ADDR), 1, fp);

		if (ferror(fp))
		{
			fclose(fp);
			perror("���� �б� ����");
			return;
		}
		
		if (feof(fp))break;

		if (add_list(&addr) == 0)
		{
			printf("�ּ� ����ó�� ��ũ�� ����Ʈ�� �߰��� �� �����ϴ�.\n");
		}
	}
	fclose(fp);
}

int add_list(const ADDR* addr)
{
	ADDR* plocal=0, * pn = g_pAddrHead;
	SetHeadPosition();

	if (g_pAddrHead == NULL)
	{
		plocal = malloc(sizeof(ADDR));
		memset(plocal, 0, sizeof(ADDR));

		if (plocal == NULL)
		{
			return 0;
		}

		while (pn->next)
		{
			pn = pn->next;
		}
		pn->next = plocal;
		plocal->prev = pn;
		plocal->next = NULL;
	}

	strcpy(plocal->name, addr->name);
	strcpy(plocal->tel, addr->tel);
	strcpy(plocal->addr, addr->addr);

	return 1;
}

void SetHeadPosition()
{
	if (g_pAddrHead == NULL)return;

	while (g_pAddrHead->prev)
	{
		g_pAddrHead = g_pAddrHead->prev;
	}
}

void SetTailPosition()
{
	if (g_pAddrHead == NULL)return;

	while (g_pAddrHead->next)
	{
		g_pAddrHead = g_pAddrHead->next;
	}
}

int find_list(const char* name)
{
	ADDR* plocal;

	SetHeadPosition();

	plocal = g_pAddrHead;

	while (plocal)
	{
		if (strstr(plocal->name, name))
		{
			g_pFind = plocal;
			return 1;
		}
		plocal = plocal->next;
	}
	return 0;
}

void Add_addr()
{
	ADDR addr;

	memset(&addr, 0, sizeof(ADDR));

	printf("\n\n ����� �̸�:"); gets(addr.name);

	if (strlen(addr.name) == 0)return;

	printf("����� ��ȭ:"); gets(addr.tel);
	printf("����� �ּ�:"); gets(addr.addr);

	if (find_list(addr.name) == 1)
	{
		printf("\n�̹� ��ϵǾ� �ִ� �̸��Դϴ�.\n\n");
		puts(g_pFind->name);
		puts(g_pFind->tel);
		puts(g_pFind->addr);
		return;
	}

	if (add_list(&addr))
	{
		g_bSaved = 0;
		printf("\n��ϵǾ����ϴ�.\n\n");

	}
	else
	{
		printf("\n����� ���еǾ����ϴ�.\n\n");
	}
}


void Find_addr()
{
	char buff[100] = { 0, };
	ADDR* plocal;
	printf("\n\n�˻��� �̸�/��ȭ/�ּ��� �Ϻθ� �Է��ϼ���.\n");
	printf("�̸�/��ȭ/�ּ�:"); gets(buff);

	if (strlen(buff) == 0)return;

	SetHeadPosition();

	plocal = g_pAddrHead;
	g_pFind = NULL;

	while (plocal)
	{
		if (strstr(plocal->name, buff))
		{
			g_pFind = plocal;
			break;
		}

		if (strstr(plocal->tel, buff))
		{
			g_pFind = plocal;
			break;
		}

		if (strstr(plocal->addr, buff))
		{
			g_pFind = plocal;
			break;
		}
		plocal = plocal->next;
	}

	if (g_pFind)
	{
		puts(g_pFind->name);
		puts(g_pFind->tel);
		puts(g_pFind->addr);
	}
	else
	{
		printf("\n\n%s�� �ּҷϿ��� ã�� �� �����ϴ�.\n\n", buff);
	}
}

void Modify_addr()
{
	char name[100] = { 0, };
	ADDR addr;

	while (1)
	{
		printf("\n\n������ �̸�:"); gets(name);

		if (strlen(name) == 0)return;

		if (find_list(name) == 0)
		{
			puts("������ �̸��� ã�� �� �����ϴ�.");
			continue;
		}
		break;
	}

	printf("\n%s�� ���� �ּ� �����ʹ� �Ʒ��� �����ϴ�.\n\n", name);
	puts(g_pFind->name);
	puts(g_pFind->tel);
	puts(g_pFind->addr);

	printf("\n �����Ϸ��� �̸�/��ȭ�ּҸ� �Է��� �� ����Ű�� ġ����.\n\n");

	printf("�̸�:"); gets(addr.name);
	printf("��ȭ:"); gets(addr.tel);
	printf("�ּ�:"); gets(addr.addr);
	if (strlen(addr.name) == 0) strcpy(addr.name, name);

	strcpy(g_pFind->name, addr.name);
	strcpy(g_pFind->tel, addr.tel);
	strcpy(g_pFind->addr, addr.addr);

	g_bSaved = 0;

	printf("%s�� ���� �ּ� �����͸� �����Ͽ����ϴ�.\n", name);
}

void Delete_addr()
{
	char name[100] = { 0, };
	ADDR* plocal;
	int ch;

	while (1)
	{
		printf("\n\n������ �̸�:"); gets(name);

		if (strlen(name) == 0)return;

		if (find_list(name) == 0)
		{
			puts("������ �̸��� ã�� �� �����ϴ�.");
			continue;
		}
		break;
	}

	puts(g_pFind->name);
	puts(g_pFind->tel);
	puts(g_pFind->addr);

	printf("%s�� �����Ͻðڽ��ϱ�(y/n)?", name);
	ch = getch();
	fflush(stdin);

	if (ch == 'Y' || ch == 'y')
	{
		if (g_pFind->prev == NULL)
		{
			if (g_pFind->next == NULL)
			{
				free(g_pFind);
				g_pAddrHead = NULL;
			}
			else
			{
				plocal = g_pFind->next;
				free(g_pFind);
				plocal->prev = NULL;
				g_pAddrHead = plocal;
			}
		}
		else if (g_pFind->next == NULL)
		{
			plocal = g_pFind->prev;
			free(g_pFind);
			plocal->next = NULL;
			g_pAddrHead = plocal;
		}
		else
		{
			plocal = g_pFind->prev;
			plocal->next = g_pFind->next;

			plocal = g_pFind->next;
			plocal->prev = g_pFind->prev;

			free(g_pFind);
			g_pAddrHead = plocal;
		}

		g_bSaved = 0;

		printf("\n\n�˻��� �ް� �����͸� �����Ͽ����ϴ�.\n\n");
	}
}


void Print_addr()
{
	int count = 1;
	ADDR* plocal;

	SetHeadPosition();

	plocal = g_pAddrHead;

	while (plocal->prev)
	{
		plocal = plocal->prev;
	}
	printf("\n\n");

	while (plocal)
	{
		printf("��ȣ.%d\n", count++);
		puts(plocal->name);
		puts(plocal->tel);
		printf("%s \n\n", plocal->addr);

		printf("�ƹ�Ű�� ��������,(�߱�:q)\n\n");
		if (getch() == 'q')return;

		plocal = plocal->next;
	}
}

void Save_addr()
{
	ADDR* plocal;
	FILE* fp;

	if (g_pAddrHead == NULL)return;

	fopen_s(&fp, ADDRFILE, "w+b");

	if (fp == NULL)
	{
		perror("���� ���� ����");
		return;
	}
	SetHeadPosition();

	while (g_pAddrHead)
	{
		plocal = g_pAddrHead->next;

		fwrite(g_pAddrHead, sizeof(ADDR), 1, fp);

		g_pAddrHead = plocal;
	}
	printf("\n��� �����͸� ���Ͽ� �����Ͽ����ϴ�.");
	g_bSaved = 1;

	fclose(fp);
}

void Remove_addr()
{
	ADDR* plocal;

	if (g_pAddrHead == NULL)return;

	SetHeadPosition();

	while (g_pAddrHead)
	{
		plocal = g_pAddrHead->next;

		free(g_pAddrHead);

		g_pAddrHead = plocal;
	}
	g_pAddrHead = NULL;
}
#endif
#if 0 //269 TCP/IP �����ϱ�
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<WinSock2.h>
#pragma comment(lib,"wsock32.lib")

void main()
{
	SOCKET s;
	WSADATA wsaData;
	SOCKADDR_IN sin;

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0)
	{
		printf("WSAStartup ����, �����ڵ�=%d\n", WSAGetLastError());
		return;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET)
	{
		printf("���� ���� ����, �����ڵ�:%d\n", WSAGetLastError());
		WSACleanup();
		return;
	}
	
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin.sin_port = htons(21);

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0)
	{
		printf("���ӽ���,�����ڵ�=%u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (closesocket(s) != 0)
	{
		printf("���� ���� ����,�����ڵ�=%u\n", WSAGetLastError());
		return;
	}

	puts("127.0.0.1�� 21�� ��Ʈ�� ������ �����Ͽ����ϴ�.");
}
#endif
#if 0 //270 TCP/IP ����/Ŭ���̾�Ʈ ���α׷� �����
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<stdio.h>
#include<WinSock2.h>
#pragma comment(lib,"wsock32.lib")

void main()
{
	SOCKET s, cs;
	WSADATA wsaData;

	struct sockaddr_in sin, cli_addr;
	int size = sizeof(cli_addr);
	char data[10] = { 0, };

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0)
	{
		printf("WSAStartup ����,�����ڵ�=%d\n", WSAGetLastError());
		return;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET)
	{
		printf("���� ���� ����, �����ڵ�:%d\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	sin.sin_family = AF_INET;
	sin.sin_port = htons(10000);
	sin.sin_addr.s_addr = htonl(ADDR_ANY);

	if (bind(s, (struct sockaddr*) & sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("���ε� ����,�����ڵ�=%d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (listen(s, SOMAXCONN) != 0)
	{
		printf("���� ��� ���� ����,�����ڵ�=%d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	printf("Ŭ���̾�Ʈ�κ��� ������ ��ٸ��� �ֽ��ϴ�...\n");

	cs = accept(s, (struct sockaddr*) & cli_addr, &size);

	if (cs == INVALID_SOCKET)
	{
		printf("���� ���� ����,�����ڵ�=%d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("Ŭ���̾�Ʈ�� ����Ǿ����ϴ�.");

	if (recv(cs, data, 3, 0) < 3)
	{
		printf("������ ���� ����,���� �ڵ�=%u\n", WSAGetLastError());
		closesocket(cs); closesocket(s);
		WSACleanup();
		return;
	}
	printf("%s�� Ŭ���̾�Ʈ�κ��� ���ŵǾ����ϴ�.\n", data);

	if (closesocket(cs) != 0 || closesocket(s) != 0)
	{
		printf("���� ���� ����, �����ڵ�=%u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0)
	{
		printf("WSACleanup ����,�����ڵ�=%u\n", WSAGetLastError());
		return;
	}
}
#endif