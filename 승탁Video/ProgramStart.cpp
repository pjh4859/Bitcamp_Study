
#include "ProgramStart.h"
#define NULL 0
ProgramStart::ProgramStart(){}
void ProgramStart::ProgramStartFunction()
{
	SelectMenu();
}
void ProgramStart::ShowMenu()
{
	cout<<"---------------------\n";
	cout << "1: ���� ��� \n";
	cout << "2: ���� ���� \n";
	cout << "3: ���� ��� \n";
	cout << "4: ���� �뿩 \n";
	cout << "5: ���� �ݳ� \n";

	cout << "6: �ű�ȸ�� ��� \n";
	cout << "7: ȸ����� ��� \n";
	cout << "8: ȸ������ ��� \n";
	cout << "9: ȸ������ \n";

	cout << "(0/-1): ���α׷� ���� \n";
	cout << "---------------------\n>>";
}
void ProgramStart::SelectMenu()
{
	ProgramStart start;
	Customer* cHead = NULL;;
	Video* vHead = NULL;;
	Customer* person = NULL;

	do{
		system("cls");
		ShowMenu();
		cin >> ch;
		switch (ch) 
		{
		case 1:
			start.vHead->registerVideo(&vHead);
			id = getchar();
			break;

		case 2:
			cout<<"������ ���� �Ϸù�ȣ�� �Է��ϼ���.\n>>";
			int id;
			cin >> id;
			if (id != -1)
				start.vHead->removeVideo(&vHead,id);
			id = getchar();
			break;
			
		case 3:
			start.vHead->listVideo(&vHead);
			id = getchar();
			break;

		case 4:
			start.vHead->listVideo(&vHead);
			cout << "�뿩�� ���� ��ȣ�� �Է��ϼ���";
			cin >> id;
			if (id != -1)
				start.vHead->lendVideo(&cHead,&vHead,id);
			id = getchar();
			break;

		case 5:
			start.vHead->restoreVideo(&cHead,&vHead);
			id = getchar();
			break;

		case 6:
			start.cHead->registerCustomer(&cHead);
			break;

		case 7:
			start.cHead->listCustomer(&cHead);
			id = getchar();
			break;

		case 8:
			start.cHead->listCustomer(&cHead);
			cout<<"�˻��� ȸ�� ��ȣ�� �Է����ּ���.\n>>";
			cin >> id;
			if (id != -1) {
				person = start.cHead->findCustomer(&cHead,id);
				if (person)
					start.cHead->showCustomerInfo(&vHead,&person);
				else
					cout<<"�������� �ʴ� ȸ���Դϴ�.\n";
			}
			else
				printf("�������� �ʴ� ȸ���Դϴ�.\n");
			cout << "�޴��� ���ư����� ����Ű�� �Է����ּ���\n";
			id = getchar();
			break;
		case 9:
			printf("������ ȸ�� �Ϸù�ȣ�� �Է��ϼ���.\n>>");
			cin >> ch;
			if (ch != -1)
				start.cHead->removeCustomer(&vHead,&cHead,ch);
			id = getchar();
			break;
		default:
			continue;
		}
		cout<<"����Ű�� �����ּ���.\n";
		id = getchar();

	}while (ch != 0 && ch != -1);

printf("Good Bye!!\n");
}

int ProgramStart::number(char* buf) 
{
	int i = 0;
	int id = 0;
	while (buf[i]) {
		if (!(buf[i] >= '0' && buf[i] <= '9'))
			break;
		i++;
	}
	if (i > 0 && (i == strlen(buf))) {
		id = atoi(buf);
		return id;
	}
	else
		return -1;
}