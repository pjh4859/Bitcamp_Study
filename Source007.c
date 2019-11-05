#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE* fp;
	
	fopen_s(&fp, "D:\\Test.txt", "r");
	//fp = fopen("D:\\Test.txt", "r");
	if (fp == NULL)
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}
	printf("파일이 열렸습니다.\n");
	fclose(fp);

	return 0;
}