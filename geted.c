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
	printf(" ====1. ���� �Է� 2. ��� 3. ���� 4.����====\n");
	printf("=============================================\n");
}

void input_info()
{
	get_mem();
	printf("�̸� �Է� : ");
	scanf_s("%s", in[number]->name, MAX_NAME);

	printf("�ּ� �Է� : ");
	scanf_s("%s", in[number]->addr, MAX_PHONE);

	printf("��ȭ��ȣ �Է� : ");
	scanf_s("%s", in[number]->phone, MAX_ADDR);

	get_number();
}
void show_info()
{
	int num;

	for (int i = 0; i < number; i++)
	{
		printf("===============================\n");
		printf("�̸� :%s\n", in[i]->name);
		printf("�ּ� : %s\n", in[i]->addr);
		printf("��ȭ��ȣ : %s\n", in[i]->phone);
		printf("===============================\n\n");
	}
	printf("�޴��� ���ư����� 0...");
	scanf_s("%d", &num);
	Sleep(num);
}

void del_info()
{
	printf("������ ���� �̸� �Է� : ");
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