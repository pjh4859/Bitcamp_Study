#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <window.h>

/*
void Eliminate(char* str, char ch);
int main(void)
{
	char str[] = "Hello World";
	Eliminate(str, 'l');
	printf("%s\n", str);
	return 0;
}

void Eliminate(char* str, char ch)
{
	for (; *str != '\0'; str++)//���� ���ڸ� ���� ������ �ݺ�
	{
		if (*str == ch)//ch�� ���� ������ ��
		{
			strcpy(str, str + 1);
			str--;
		}
	}
}
*/

void Eliminate(char* str, char ch)
{
	for (; *str != '\0'; str++)//���� ���ڸ� ���� ������ �ݺ�
	{
		if (*str == ch)//ch�� ���� ������ ��
		{
			strcpy(str, str + 1);
			str--;
		}
	}
}

int main(void)
{		
	int k = 0;
	int pplnum=0;
	char temp[80];
	char* str[100];

	for (;;)
	{		
		int a;
		printf("Choose your action.\n 1.Sign in 2.Print out 3.Delete 4.Exit \n");
		scanf_s("%d", &a);

		if (a == 1)
		{				
			int i=0;
			printf("Insert your name phone# and adress. (Name Phone# Adress)\n");				
			for (i = 0; i < 3; i++)
			{
				str[i+k] = malloc(sizeof(char) * 80);    // char 80�� ũ�⸸ŭ ���� �޸� �Ҵ�
				printf("Type: ");
				scanf_s("%s", str[i+k],80);      // ǥ�� �Է��� �޾Ƽ� �޸𸮰� �Ҵ�� ���ڿ� �����Ϳ� ����
				//printf("%s\n", str[i+k]);   // ���ڿ��� ������ ���

				//gets(temp);
				//str[i+k] = (char*)malloc(strlen(temp) + 1);
				//strcpy(str[i+k], temp);
			}
			
			/*
			for (i = 0; i < 3; i++)
			{
				free(str[i+k]);
			}
			*/
		}
		else if (a == 2)
		{
			int j;
			int jj = pplnum * 3;
			for (j = 0; j <= (jj); j+= 3)
			{
				printf("%d\n", j);
				printf("%d\n", jj);
				//printf("%d\n", pplnum);
				printf("�̸�: %s\n����: %s\n�ּ�: %s\n", str[j], str[j+1], str[j+2]);
				
			}
		}
		else if (a == 3)
		{
			/*
			str2[0] = malloc(sizeof(char) * 80);    // char 10�� ũ�⸸ŭ ���� �޸� �Ҵ�
			printf("Type2: ");
			scanf("%s", str2[0]);
			Eliminate(str, str2[0]);
			return 0;	
			*/
			char str2[20];
			printf("������ �̸��� �Է��ϼ���: ");
			scanf("%s", str2);
			printf("Deleted\n");
		}
		else if (a == 4)
		{
			
			printf("Ending system.\n");
			break;
		}
		else
		{
			printf("Correct your order.\n");
		}
		pplnum = pplnum+1;		
		system("cls");
		if (a == 1)
		{
			k = k+3;
		}
	}
	//free(str);
	return 0;
}


