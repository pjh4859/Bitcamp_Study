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