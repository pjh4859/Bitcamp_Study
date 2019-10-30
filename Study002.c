#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int main(void)
{
	int pnum=0;
	char* Name;
	char* Phone;
	char* Adress;
	int a;
	int i = 0;
	int j=0;


	while(1)
	{	
	//	system("cls");		

		printf("Choose your action.\n 1.Sign in 2.Print out 3.Delete 4.Exit \n");
		scanf_s("%d", &a);

		if (a == 1)
		{
			printf("Insert your name phone# and adress. (Name Phone# Adress)\n");			
				
			Name[pnum] = malloc(sizeof(char) * 30);
			Phone[pnum] = malloc(sizeof(char) * 30);
			Adress[pnum] = malloc(sizeof(char) * 30);

			printf("Type Name : ");
			scanf_s("%s", Name[pnum], 80);      // 표준 입력을 받아서 메모리가 할당된 문자열 포인터에 저장
			printf("Type Phone# : ");
			scanf_s("%s", Phone[pnum], 80);
			printf("Type Adress : ");
			scanf_s("%s", Adress[pnum], 80);

			++pnum ;
						
		}
		else if (a == 2)
		{
			for (j = 0;j<pnum;j++)
			{	
				printf("이름: %s\n", Name[j]);
				printf("전번: %s\n", Phone[j]);
				printf("주소: %s\n", Adress[j]);
			}
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
	}
	//free(Num);
	return 0;
}


