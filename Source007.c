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
		printf("������ ������ �ʾҽ��ϴ�.\n");
		return 1;
	}
	printf("������ ���Ƚ��ϴ�.\n");
	fclose(fp);

	return 0;
}