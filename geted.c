#include"info.h"
int set_number()
{
	number = 0;
	return number;
}
void get_mem()
{
	in[number] = malloc(sizeof(char) * 4);

	in[number]->name = malloc(sizeof(char) * MAX_NAME);
	in[number]->phone = malloc(sizeof(char) * MAX_PHONE);
	in[number]->addr = malloc(sizeof(char) * MAX_ADDR);
}

void free_mem()
{
	free(in);
}

int get_number()
{
	return ++number;
}
void show_menu()
{
	printf("=============================================\n");
	printf(" ====1. 정보 입력 2. 출력 3. 삭제 4.삭제====\n");
	printf("=============================================\n");
}

void input_info()
{
	get_mem();
	printf("이름 입력 : ");
	scanf_s("%s", in[number]->name, MAX_NAME);

	printf("주소 입력 : ");
	scanf_s("%s", in[number]->addr, MAX_PHONE);

	printf("전화번호 입력 : ");
	scanf_s("%s", in[number]->phone, MAX_ADDR);

	get_number();
}
void show_info()
{
	int num;

	for (int i = 0; i < number; i++)
	{
		printf("===============================\n");
		printf("이름 :%s\n", in[i]->name);
		printf("주소 : %s\n", in[i]->addr);
		printf("전화번호 : %s\n", in[i]->phone);
		printf("===============================\n\n");
	}
	printf("메뉴로 돌아갈려면 0...");
	scanf_s("%d", &num);
	Sleep(num);
}

void del_info()
{
	printf("삭제를 위한 이름 입력 : ");
}


void start_function()
{
	int num;
	set_number();
	while (1)
	{
		system("cls");
		show_menu();
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:
			input_info();
			break;

		case 2:
			show_info();
			break;

		case 3:
			del_info();
			break;

		case 4:
			free_mem();
			return;
			break;
		}

	}
}