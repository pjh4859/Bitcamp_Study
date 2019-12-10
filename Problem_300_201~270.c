#if 0 //201 scanf()함수 100% 활용하기(scanf)
#include<stdio.h>
#pragma warning(disable:4996)

#define scan(d,x,y) printf(#d "형(%"#x")을 입력하세요\n");\
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
	scan(8진수, %o, o8);
	scan(16진수, %x, x16);
	scan(고정소수점, %f, f);
	scan(문자열, %s, s);

	scanf("%4d%3d", &i, &o8);
	printf("%d,%d\n", i, o8);
}
#endif
#if 0 //202 printf() 함수 100% 활용하기(printf)
#include<stdio.h>
void main()
{
	int i;
	char* pi;
	char* string = "books";

	//문자 정수값
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
	//8진수, 16진수
	printf("[%x]\n", 0xFF);
	printf("[%X]\n", 0xFF);
	printf("[%#x]\n", 0xFF);
	printf("[%#x]\n", 12345);
	printf("[%o]\n", 0123);
	printf("[%#o]\n", 0123);
	printf("\n");

	//고정 소수점
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
#if 0 //203 삼각형 출력하기(for)
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
#if 0 //204 값을 입력받아 홀수/짝수 구분하기(%)
#include<stdio.h>
void main()
{
	int num;

	printf("숫자를 입력하세요:");

	scanf_s("%d", &num);

	if (num % 2 == 1)printf("%d은 홀수입니다.\n", num);
	else printf("%d는 짝수입니다.\n", num);
}
#endif
#if 0 //205 1~100까지 홀수의 합 구하기
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
	printf("1~100까지의 홀수의 합: %d\n", hap);
}
#endif
#if 0 //206 21~50 범위의 난수 발생시키기
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
#if 0 //207 변수의 번지 출력하기(& 연산자)
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
#if 0 //208 정수값을 16진수 문자열로 변환하기(itoa)
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
#if 0 //209 2진수/16진수 문자열을 정수값으로 변환하기(strtol)
#include<stdio.h>
#include<stdlib.h>

void main()
{
	char string1[]="1010";
	char string2[]="ff";
	char* stop;
	long value;

	value = strtol(string1, &stop,2);
	printf("2진문자열\"%s\"을 정수로 바꾸면 %d입니다.\n", string1, value);

	value = strtol(string2, &stop,16);
	printf("16진문자열\"%s\"을 정수로 바꾸면 %d입니다.\n", string2, value);

}
#endif
#if 0 //210 2진수 문자열을 16진수 문자열로 변환하기(strtol, itoa)
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
#if 0 //211 소문자를 대문자로 변환하기
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
#if 0 //212 비트 연산을 사용하여 변수값을 0으로 만들기
#include<stdio.h>

void main()
{
	int i = -5;
	printf("i=%d\n", i);

	i = i ^ i;

	printf("i=%d\n", i);
}
#endif
#if 0 //213 비트 쉬프트 연산을 사용하여 곱셈 구현하기(<<)
#include<stdio.h>
void main()
{
	char value = 2;
	value = value << 2;
	printf("value:%d\n", value);
}
#endif
#if 0 //214 비트 쉬프트 연산을 사용하여 나눗셈 구현하기(>>)
#include<stdio.h>
void main()
{
	char value = 8;
	value = value >> 2;
	printf("value:%d\n", value);
}
#endif
#if 0 //215 문자열에서 특정 문자열의 인덱스 구하기(strstr)
#include<stdio.h>
#include<string.h>

void main()
{
	char string[] = "This is a book";
	char* pos;

	pos = strstr(string, "book");

	if (pos)
	{
		printf("book을 %d 번째에서 찾았습니다.\n", pos - string);
		printf("%s\n", &string[pos - string]);
	}
}
#endif
#if 0 //216 문자열을 콤마와 공백으로 분리하기(strtok)
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
#if 0 //217 문자열을 공백으로 분리하여 여러 개의 문자열로 만들기(strtok)
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
#if 0 //218 문자열에서 숫자만 추출해내기(isdigit)
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
#if 0 //219 문자열에서 알파벳만 추출해내기(isalpha)
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
#if 0 //220 문자열에서 한글만 추출해내기
#include<stdio.h>
#include<ctype.h>
void main()
{
	unsigned char* string = "I am 한국사람 man";
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
#if 0 //221 알파벳이 아닌 첫 문자의 위치 검출하기(strspn)
#include<stdio.h>
#include<string.h>
void main()
{
	char* string = "it's good man";
	char* find = "abcdefghijklmnopqrstuvwxyz";
	int nIndex;

	nIndex = strspn(string, find);
	printf("%d 위치에서 알파벳이 아닌 첫 문자를 찾았습니다.\n", nIndex);
}
#endif
#if 0 //222 문자열에서 숫자가 시작되는 위치 추출하기(strcspn)
#include<stdio.h>
#include<string.h>
void main()
{
	char string[] = "it's good22 man";
	char* find = "0123456789";
	int nIndex;

	nIndex = strcspn(string, find);
	printf("%d 위치에서 문자를 찾았습니다.\n", nIndex);
}
#endif
#if 0 //223 문자열을 특정 문자 위치에서 잘라내기(strchr)
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
#if 0 //224 문자열의 좌우 공백 제거하기(isspace)
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void main()
{
	char* string = "123";
	char buff[30] = { 0, };
	int i = 0;

	printf("string의 길이:%d\n", strlen(string));

	while (*string)
	{
		if (!isspace(*string))
		{
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);
	printf("string의 길이:%d\n", strlen(buff));
}
#endif
#if 0 //225 문자열의 좌우 특정 문자들 제거하기(strspn,strcspn)
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
#if 0 //226 문자열을 NULL로 채우기(strset)
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
void main()
{
	char buff[] = "암호는 Korea입니다.";

	puts(buff);
	strset(buff, 0);
	printf("[%s]\n", buff);
}
#endif
#if 0 //227 문자열의 첫 글자를 대문자로 변환하기
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
#if 0 //228 문자열에서 특정 위치의 문자 교체하기(strnset)
#include<stdio.h>
#include<string.h>
#pragma	warning(disable:4996)
void main()
{
	char string[] = "암호는 Korea입니다.";
	char* pstr;

	pstr = strstr(string, "Korea");
	if (pstr)
	{
		strnset(pstr, '*', 5);
		
	}
	puts(string);
}
#endif
#if 0 //229 문자열에 대한 임시 저장소 만들기(strdup)
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#pragma	warning(disable:4996)
void main()
{
	char buff[] = "문자열 복제하기";
	char* dup;

	dup = strdup(buff);
	if (dup)
	{
		strcpy(buff, "다른 문자열");
		puts(buff);
		puts(dup);
		free(dup);
	}
}
#endif
#if 0 //230 메모리를 1MB 할당하고 해제하기(malloc, free)
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
		strcpy(&pbuf[0], "서울시 양천구 목동");
		puts(&pbuf[0]);
		free(pbuf);
	}
}
#endif
#if 0 //231 메모리를 100MB 할당하고 해제하기
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
		strcpy(&pbuf[0], "서울시 양천구 목동");
		puts(&pbuf[0]);
		strcpy(&pbuf[104857500], "부산시 강서구 미음동1");
		puts(&pbuf[104857500]);
		free(pbuf);
	}
}
#endif
#if 0 //232 void형 포인터를 사용한 다양한 배열 복사하기
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
#if 0 //233 텍스트 파일을 한 줄씩 쓰기(fopen,fputs,fclose)
#include<stdio.h>
void main()
{
	FILE* fp;

	fopen_s(&fp,"D:\\C_code\\hii.txt", "w+");

	if (fp != NULL)
	{
		fputs("대한민국\n", fp);
		fputs("대한민국\n", fp);
		fputs("대한민국\n", fp);
		fputs("대한민국\n", fp);
		fputs("대한민국\n", fp);
		fclose(fp);
	}
}
#endif
#if 0 //234 텍스트 파일을 한 줄씩 읽기(fgets)
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
#if 0 //235 텍스트 파일 쓰기(fwrite)
#include<stdio.h>
void main()
{
	FILE* fp;
	char* string = "우리강산\n";

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
#if 0 //236 텍스트 파일 읽기(fread)
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
#if 0 //237 이진 파일 쓰기(fwrite)
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
#if 0 //238 이진 파일 읽기(fread)
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
#if 0 //239 파일을 다른 디렉터리로 이동하기(rename)
#include<stdio.h>
void main()
{
	char* filename = "D:\\C_code\\file2.txt";
	char* movefile = "D:\\C_code\\aa\\file!!.txt";

	if (rename(filename, movefile) != 0)
	{
		perror("파일 이동 에러");
	}
	else
	{
		puts("파일이 이동되었습니다.");
	}
}
#endif	
#if 0 //240 파일 복사하기(fread, fwrite)
#include<stdio.h>
void main()
{
	FILE* fpR, * fpW;
	char buff;
	int len;

	fopen_s(&fpR, "D:\\C_code\\aa\\bin2.txt","rb");

	if (fpR == NULL)
	{
		perror("파일 읽기 개방 에러");
		return;
	}
	fopen_s(&fpW, "D:\\C_code\\aa\\abc.txt","w+b");
	
	if (fpW == NULL)
	{
		perror("파일 쓰기 개방 에러");
		fclose(fpR);
		return;
	}
	while (!feof(fpR))
	{
		len = fread(&buff, 1, 1, fpR);
		if (ferror(fpR))
		{
			perror("파일 읽기 에러");
			_fcloseall();
			return;
		}
		if (len>0)//if(!feof(fpR))
		{
			fwrite(&buff, 1, 1, fpW);
			if (ferror(fpW))
			{
				perror("파일 쓰기 에러");
				_fcloseall();
				return;
			}
		}
	}
	_fcloseall();
	puts("파일을 성공적으로 복사하였습니다.");	
}
#endif	
#if 0 //241 두 개의 파일 합치기
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
		perror("파일 읽기 개방 에러");
		return;
	}
	fopen_s(&fpR2, "D:\\C_code\\aa\\bin2.txt", "rb");
	
	if (fpR2 == NULL)
	{
		perror("파일 읽기 개방 에러");
		_fcloseall();
		return;
	}
	fopen_s(&fpW, "D:\\C_code\\aa\\Output01.txt", "w+b");

	if (fpW == NULL)
	{
		perror("파일 쓰기 개방 에러");
		_fcloseall();
		return;
	}
	while (!feof(fpR1))
	{
		len = fread(buff, 1, FILEREAD, fpR1);
		if (ferror(fpR1))
		{
			perror("파일 읽기 에러 1");
			_fcloseall();
			return;
		}
		if (len > 0)
		{
			fwrite(buff, 1, len, fpW);
			if (ferror(fpW))
			{
				perror("파일 쓰기 에러1");
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
			perror("파일 읽기 에러2");
			_fcloseall();
			return;
		}
		if (len > 0)
		{
			fwrite(buff, 1, len, fpW);
			if (ferror(fpW))
			{
				perror("파일 쓰기 에러 2");
				_fcloseall();
				return;
			}
		}
	}
	_fcloseall();
	puts("파일이 성공적으로 합쳐졌습니다.");
}
#endif
#if 0 //242 파일에서 특정 문자열 검색하기(strstr)
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
		perror("파일 읽기 개방 에러");
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
#if 0 //243 파일에서 특정 문자열 교체하기
//맨 마지막줄이 안쓰여짐.
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
		perror("파일 읽기 개방 에러");
		return;
	}
	fopen_s(&fpW, "D:\\C_code\\aa\\uuu_change.txt", "w+");

	if (fpW == NULL)
	{
		perror("파일 쓰기 개방 에러");
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
#if 0 //244 연/월/일/ 시:분:초 출력하기(time, localtime)
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
		perror("파일 쓰기 개방 에러");
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
	puts("시간을 D:\\C_code\\aa\\date1.txt에 저장하였습니다.");
}
#endif
#if 0 //245 출생일로부터 오늘까지의 경과일 수 구하기(mktime)
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
	printf("박재희가 태어난 지 %.2lf일째 입니다.\n", elapsed);
}
#endif
#if 0 //246 각 달의 마지막 날짜 구하기(mktime)
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
		printf("%d년 %2d월의 마지막 날짜는 %d 일입니다.\n",
			t1.tm_year + 1900, t1.tm_mon + 1, last);
	}
}
#endif
#if 0 //247 D-Day 구하기(mktime)
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

	printf("오늘의 날짜는 %s", ctime(&now));
	printf("최수린의 생일:%d일 남았습니다.(%d/%d/%d)\n",
		nDday, dday.tm_year + 1900, dday.tm_mon + 1, dday.tm_mday);
}
#endif
#if 0 //248 오늘 날짜로부터 크리스마스까지의 남은 시간 구하기
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

	printf("오늘은 날짜는 %s", ctime(&now));
	printf("크리스마스까지 남은 시간은 %d개월 %d일 %d시간 %d분 %d초입니다.\n",
		christmas.tm_mon, christmas.tm_mday, christmas.tm_hour,
		christmas.tm_min, christmas.tm_sec);
}
#endif
#if 0 //249 오늘 날짜에 임의의 날짜 더하고 빼기
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

	printf("오늘 날짜는%d/%d/%d %d:%d:%d 입니다.\n",
		tb.tm_year + 1900, tb.tm_mon + 1, tb.tm_mday,
		tb.tm_hour, tb.tm_min, tb.tm_sec);

	printf("100개월 90일 80시간을 더한 날짜는 %d/%d/%d %d:%d:%d입니다.\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);

	tb.tm_mon -= 100;
	tb.tm_mday -= 90;
	tb.tm_hour -= 80;

	mktime(&tb);
	printf("100개월 90일 80시간을 뺀 날짜는 %d/%d/%d %d:%d:%d입니다.\n",
		tb.tm_year + 1900, tb.tm_mon + 1, tb.tm_mday,
		tb.tm_hour, tb.tm_min, tb.tm_sec);
}
#endif
#if 0 //250 크리스마스의 요일 구하기
#include<stdio.h>
#include<time.h>

void main()
{
	struct tm christmas = { 0,0,0,25,12 - 1,2019 - 1900 };
	char* wday[] = { "일","월","화","수","목","금","토" };
	char buff[100];

	mktime(&christmas);

	strftime(buff, sizeof(buff), "2020년 12월 25일은 %A입니다.",&christmas);

	puts(buff);
	printf("2020년 12월 25일은 %s요일입니다.\n", wday[christmas.tm_wday]);
}
#endif
#if 0 //251 세계 표준 시와 국내 표준 시의 시간 차 구하기(localtime)
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

	printf("UT와 한국 LT시간차이:%g 시간 \n", difftime(n1, n2) / 3600.);
}
#endif
#if 0 //252 5초간 지연하는 함수 구현하기(clock)
#include<stdio.h>
#include<time.h>
void sleep(int sec);

void main()
{
	time_t n1, n2;

	time(&n1);
	sleep(5);
	time(&n2);

	printf("%g초가 지연되었습니다.\n", difftime(n2, n1));

}
void sleep(int sec)
{
	clock_t ct;
	ct = clock();
	while (ct + CLK_TCK * sec > clock());
}
#endif
#if 0 //253 두 시간 간의 차이 구하기(mktime)
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

	printf("시간 1:%4d-%02d-%02d %02d:%02d:%02d\n",
		t1.tm_year + 1900, t1.tm_mon + 1, t1.tm_mday,
		t1.tm_hour, t1.tm_min, t1.tm_sec);

	printf("시간 2:%4d-%02d-%02d %02d:%02d:%02d\n",
		t2.tm_year + 1900, t2.tm_mon + 1, t2.tm_mday,
		t2.tm_hour, t2.tm_min, t2.tm_sec);

	printf("시간차이: %d:%d:%d\n",
		n3 / 3600, (n3 - ((n3 / 3600) * 3600)) / 60, n3 % 60);
}
#endif
#if 0 //두 날짜 간의 차이 구하기(mktime)
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

	printf("시간 1:%4d-%02d-%02d %02d:%02d:%02d\n",
		t1.tm_year + 1900, t1.tm_mon + 1, t1.tm_mday,
		t1.tm_hour, t1.tm_min, t1.tm_sec);

	printf("시간 2:%4d-%02d-%02d %02d:%02d:%02d\n",
		t2.tm_year + 1900, t2.tm_mon + 1, t2.tm_mday,
		t2.tm_hour, t2.tm_min, t2.tm_sec);

	printf("날짜차이 :%4d-%02d-%02d %02d:%02d:%02d\n",
		t3.tm_year + 1900, t3.tm_mon + 1, t3.tm_mday,
		t3.tm_hour, t3.tm_min, t3.tm_sec);
}
#endif
#if 0 //255 올해의 경과된 날짜 수 구하기(localtime)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	struct tm t;

	now = time(NULL);
	localtime_s(&t, &now);

	printf("올해의 경과일수 : %d\n", t.tm_yday);
}
#endif
#if 0 //256 올해의 경과된 주의 수 구하기(strftime)
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	struct tm t;
	char buff[100];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "올해의 경과된 주:%U주", &t);
	puts(buff);
}
#endif
#if 0 //257 오늘의 요일 구하기
#include<stdio.h>
#include<time.h>

void main()
{
	time_t now;
	struct tm t;
	char buff[100];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "요일:%A", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "요일:%a", &t);
	puts(buff);
	printf("%d\n", t.tm_wday);
}
#endif
#if 0 //258 오전/오후 표시하기
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
	
	if (strcmp(buff, "AM"))strcpy_s(AMPM,sizeof(AMPM), "오전");
	else if (strcmp(buff, "PM"))strcpy_s(AMPM, sizeof(AMPM), "오후");
	strcat_s(buff,sizeof(buff), AMPM);

	puts(buff);
}
#endif
#if 0 //259 AM/PM 표시하기
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

	if (strcmp(buff, "오전"))strcpy_s(AMPM, sizeof(AMPM), "AM");
	else if (strcmp(buff, "오후"))strcpy_s(AMPM, sizeof(AMPM), "PM");
	strcat_s(buff, sizeof(buff), AMPM);

	puts(buff);
}
#endif
#if 0 //260 문자열로 된 날짜를 time_t 형식으로 변환하기(atio, mktime)
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
	printf("2020-06-23을 time_t로 변환하면 %lld\n",now);
}
#endif
#if 0 //261 문자열로 된 날짜를 struct tm 형식으로 변환하기
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
	printf("struct tm 변환 후 날짜: %4d-%02d-%02d %02d:%02d:%02d\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);
}
#endif
#if 0 //262 날짜 및 시간을 다양한 방법으로 출력하기(_ftime)
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
#if 0 //263 야구 게임 만들기
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

	puts("야구 게임을 시작합니다.");

	while (1)
	{
		com[0] = rand() % 10;
		com[1] = rand() % 10;
		com[2] = rand() % 10;
		count = 1;

		if (com[0] == com[1] || com[0] == com[2] || com[1] == com[2])continue;

		puts("숫자0~9를 공백으로 분리하여 3개 입력하고 엔터키를 치세요!!");

		memset(guess, 0, sizeof(guess));

		while (1)
		{
			strike = 0; ball = 0;

			for (i = 0; i < 10; i++)
			{
				printf("%d", guess[i]);
			}
			printf("\n개의 숫자[0~9]를 입력하세요:");

			scanf("%d %d %d", &gamer[0], &gamer[1], &gamer[2]);

			if (com[0] == gamer[0])strike++;
			else if (com[0] == gamer[1] || com[0] == gamer[2])ball++;
			
			if (com[1] == gamer[1])strike++;
			else if (com[1] == gamer[0] || com[1] == gamer[2])ball++;

			if (com[2] == gamer[2])strike++;
			else if (com[2] == gamer[0] || com[2] == gamer[1])ball++;

			if (gamer[0] > 9 || gamer[1] > 9 || gamer[2] > 9)
			{
				puts("입력한 숫자가 너무 큽니다. 0~9를 입력하세요.");
				continue;
			}

			guess[gamer[0]] = 1;
			guess[gamer[1]] = 1;
			guess[gamer[2]] = 1;

			printf("\n[%2d회] %d 스트라이크 %d 볼 \n\n", count, strike, ball);
			if (strike == 3)break;
			count++;
		}
		fflush(stdin);

		printf("게임을 계속하시겠습니까(y/n)?");
		scanf("%c", &yesno);
		if (yesno == 'N' || yesno == 'n')break;
	}
}
#endif
#if 0 //264 스택 구현하기
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

	puts("계산식을 1 * 2처럼 입력하고 엔터키를 치세요.");
	puts("아무것도 입력하지 않으면 계산이 종료됩니다.");

	for (;;)
	{
		printf("계산식:");
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
			puts("잘못된 연산자를 사용하였습니다.");
			continue;
		}

		if(push(value1) == -1)
		{
			puts("더 이상 저장할 수 없습니다.");
		}
		printf("%s=%d,s.top=%d\n\n", buff, value1, s.top);

	}
	value1 = 0;

	for (;;)
	{
		if (pop(&value2) == -1)break;
		value1 += value2;
	}
	printf("계산의 총합은 %d입니다.\n", value1);
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
#if 0 //265 큐 구현하기
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

	puts("계산식을 1 * 2처럼 입력하고 엔터키를 치세요.");
	puts("아무것도 입력하지 않으면 계산이 종료됩니다.");

	for (;;)
	{
		printf("계산식:");
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
			puts("잘못된 연산자를 사용하였습니다.");
			continue;
		}
		if (add(value1) == -1)
		{
			puts("더 이상 추가할 수 없습니다.");
		}
		printf("%s=%d,q.rear = %d\n\n", buff, value1, q.rear);
	}
	value1 = 0;

	for (;;)
	{
		if (delete(&value2) == -1)break;

		value1 += value2;
	}
	printf("계산의 총합은 %d 입니다.\n", value1);

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
#if 0 //266 단일 링크드 리스트 구현하기
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
	add_list("홍길동", "1111", "서울 종로구");
	add_list("모모", "2222", "서울 강서구");
	add_list("사나", "3333", "서울 구로구");
	add_list("쯔위", "4444", "서울 강동");
	add_list("나연", "5555", "대전 동구");

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
#if 0 //267 이중 링크드 리스트 구현하기
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
	add_list("사나", "1111", "서울특별시 종로구");
	add_list("미나", "2222", "서울특별시 강서구");
	add_list("모모", "3333", "서울특별시 구로구");
	add_list("쯔위", "4444", "서울특별시 강동구");
	add_list("지효", "5555", "대전광역시 동구");

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
#if 1 //268 주소록 구현하기
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

	puts("주소록 프로그램 Version 1.0");

	while (1)
	{
		printf("\n[1]등록 [2]검색 [3]수정 [4]삭제 [5]출력 [S]저장 [Q]종료");

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
				printf("\n\n변경된 주소 데이터를 저장하시겠습니까(y/n)?");
				ch = getchar();
				if (ch == 'Y' || ch == 'y')Save_addr();
			}
			
			Remove_addr(); return;
		default:printf("\n\n1~5 또는 S/Q를 누르십시오.\n\n"); break;
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
		perror("파일 개방 에러");
		return;
	}

	while (!feof(fp))
	{
		fread(&addr, sizeof(ADDR), 1, fp);

		if (ferror(fp))
		{
			fclose(fp);
			perror("파일 읽기 에러");
			return;
		}
		
		if (feof(fp))break;

		if (add_list(&addr) == 0)
		{
			printf("주소 데이처를 링크드 리스트에 추가할 수 없습니다.\n");
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

	printf("\n\n 등록할 이름:"); gets(addr.name);

	if (strlen(addr.name) == 0)return;

	printf("등록할 전화:"); gets(addr.tel);
	printf("등록할 주소:"); gets(addr.addr);

	if (find_list(addr.name) == 1)
	{
		printf("\n이미 등록되어 있는 이름입니다.\n\n");
		puts(g_pFind->name);
		puts(g_pFind->tel);
		puts(g_pFind->addr);
		return;
	}

	if (add_list(&addr))
	{
		g_bSaved = 0;
		printf("\n등록되었습니다.\n\n");

	}
	else
	{
		printf("\n등록이 실패되었습니다.\n\n");
	}
}


void Find_addr()
{
	char buff[100] = { 0, };
	ADDR* plocal;
	printf("\n\n검색할 이름/전화/주소의 일부를 입력하세요.\n");
	printf("이름/전화/주소:"); gets(buff);

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
		printf("\n\n%s을 주소록에서 찾을 수 없습니다.\n\n", buff);
	}
}

void Modify_addr()
{
	char name[100] = { 0, };
	ADDR addr;

	while (1)
	{
		printf("\n\n수정할 이름:"); gets(name);

		if (strlen(name) == 0)return;

		if (find_list(name) == 0)
		{
			puts("수정할 이름을 찾을 수 없습니다.");
			continue;
		}
		break;
	}

	printf("\n%s에 대한 주소 데이터는 아래와 같습니다.\n\n", name);
	puts(g_pFind->name);
	puts(g_pFind->tel);
	puts(g_pFind->addr);

	printf("\n 수정하려는 이름/전화주소를 입력한 후 엔터키를 치세요.\n\n");

	printf("이름:"); gets(addr.name);
	printf("전화:"); gets(addr.tel);
	printf("주소:"); gets(addr.addr);
	if (strlen(addr.name) == 0) strcpy(addr.name, name);

	strcpy(g_pFind->name, addr.name);
	strcpy(g_pFind->tel, addr.tel);
	strcpy(g_pFind->addr, addr.addr);

	g_bSaved = 0;

	printf("%s에 대한 주소 데이터를 수정하였습니다.\n", name);
}

void Delete_addr()
{
	char name[100] = { 0, };
	ADDR* plocal;
	int ch;

	while (1)
	{
		printf("\n\n삭제할 이름:"); gets(name);

		if (strlen(name) == 0)return;

		if (find_list(name) == 0)
		{
			puts("삭제할 이름을 찾을 수 없습니다.");
			continue;
		}
		break;
	}

	puts(g_pFind->name);
	puts(g_pFind->tel);
	puts(g_pFind->addr);

	printf("%s을 삭제하시겠습니까(y/n)?", name);
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

		printf("\n\n검색된 줏고 데이터를 삭제하였습니다.\n\n");
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
		printf("번호.%d\n", count++);
		puts(plocal->name);
		puts(plocal->tel);
		printf("%s \n\n", plocal->addr);

		printf("아무키나 누르세요,(중기:q)\n\n");
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
		perror("파일 개방 에러");
		return;
	}
	SetHeadPosition();

	while (g_pAddrHead)
	{
		plocal = g_pAddrHead->next;

		fwrite(g_pAddrHead, sizeof(ADDR), 1, fp);

		g_pAddrHead = plocal;
	}
	printf("\n모든 데이터를 파일에 저장하였습니다.");
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
#if 0 //269 TCP/IP 이해하기
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
		printf("WSAStartup 실패, 에러코드=%d\n", WSAGetLastError());
		return;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET)
	{
		printf("소켓 생성 실패, 에러코드:%d\n", WSAGetLastError());
		WSACleanup();
		return;
	}
	
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin.sin_port = htons(21);

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0)
	{
		printf("접속실패,에러코드=%u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (closesocket(s) != 0)
	{
		printf("소켓 제거 실패,에러코드=%u\n", WSAGetLastError());
		return;
	}

	puts("127.0.0.1의 21번 포트에 접속을 성공하였습니다.");
}
#endif
#if 0 //270 TCP/IP 서버/클라이언트 프로그램 만들기
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
		printf("WSAStartup 실패,에러코드=%d\n", WSAGetLastError());
		return;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET)
	{
		printf("소켓 생성 실패, 에러코드:%d\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	sin.sin_family = AF_INET;
	sin.sin_port = htons(10000);
	sin.sin_addr.s_addr = htonl(ADDR_ANY);

	if (bind(s, (struct sockaddr*) & sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("바인드 실패,에러코드=%d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (listen(s, SOMAXCONN) != 0)
	{
		printf("리슨 모드 설정 실패,에러코드=%d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	printf("클라이언트로부터 접속을 기다리고 있습니다...\n");

	cs = accept(s, (struct sockaddr*) & cli_addr, &size);

	if (cs == INVALID_SOCKET)
	{
		printf("접속 승인 실패,에러코드=%d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("클라이언트와 연결되었습니다.");

	if (recv(cs, data, 3, 0) < 3)
	{
		printf("데이터 수신 실패,에러 코드=%u\n", WSAGetLastError());
		closesocket(cs); closesocket(s);
		WSACleanup();
		return;
	}
	printf("%s가 클라이언트로부터 수신되었습니다.\n", data);

	if (closesocket(cs) != 0 || closesocket(s) != 0)
	{
		printf("소켓 제거 실패, 에러코드=%u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0)
	{
		printf("WSACleanup 실패,에러코드=%u\n", WSAGetLastError());
		return;
	}
}
#endif