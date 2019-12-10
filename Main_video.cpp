#if 1
#include"videoshop.h"
void showMenu()
{
	char ch;
	int id;
	char buf[20];
	Customer* person = NULL;
	Video* vide = NULL;
	int i = 0;

	do {
		cout <<"---------------------"<< endl;
		cout <<"1: ���� ���"<< endl;
		cout <<"2: ���� ����"<< endl;
		cout <<"3: ���� ���"<< endl;
		cout <<"4: ���� �뿩"<< endl;
		cout <<"5: ���� �ݳ�"<< endl;
		cout << endl;
		cout <<"6: �ű�ȸ�� ���"<< endl;
		cout <<"7: ȸ����� ���"<< endl;
		cout <<"8: ȸ������ ���"<< endl;
		cout <<"9: ȸ������"<< endl;
		cout << endl;
		cout <<"(Q/q): ���α׷� ����"<< endl;
		cout <<"---------------------"<< endl;
		
		ch = getchar();
		getchar();
		//fflush(stdin);

		switch (ch) {
		case '1':
			vide->registerVideo();
			break;

		case '2':
			printf("������ ���� �Ϸù�ȣ�� �Է��ϼ���.\n>>");

			fgets(buf, 20, stdin);
			//���๮�ڸ� �ι��ڷ� ��ü��
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//�Է¹��ۿ� �����ִ� �����͸� ���ϴ�.
			fflush(stdin);
			//�Էµȹ��ڿ��� ���ڷ� ��ȯ
			id = vide->number(buf);
			if (id != -1)
				vide->removeVideo(id);
			break;

		case '3':
			vide->listVideo();
			break;

		case '4':
			vide->listVideo();
			printf("�뿩�� ���� �Ϸù�ȣ�� �Է��ϼ���.\n>>");

			fgets(buf, 20, stdin);
			//���๮�ڸ� �ι��ڷ� ��ü��
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//�Է¹��ۿ� �����ִ� �����͸� ���ϴ�.
			fflush(stdin);
			//�Էµȹ��ڿ��� ���ڷ� ��ȯ
			id = vide->number(buf);
			if (id != -1)
				vide->lendVideo(id);
			break;

		case '5':
			vide->restoreVideo();
			break;

		case '6':
			person->registerCustomer();
			break;

		case '7':
			person->listCustomer();
			break;

		case '8':
			person->listCustomer();
			printf("�˻��� ȸ�� ��ȣ�� �Է����ּ���.\n>>");
			fgets(buf, 20, stdin);
			//���๮�ڸ� �ι��ڷ� ��ü��
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//�Է¹��ۿ� �����ִ� �����͸� ���ϴ�.
			fflush(stdin);
			//�Էµȹ��ڿ��� ���ڷ� ��ȯ
			id = vide->number(buf);
			if (id != -1) {
				person = person->findCustomer(id);
				if (person)
					person->showCustomerInfo(person);
				else
					printf("�������� �ʴ� ȸ���Դϴ�.\n");
			}
			else
				printf("�������� �ʴ� ȸ���Դϴ�.\n");

			break;
		case '9':
			printf("������ ȸ�� �Ϸù�ȣ�� �Է��ϼ���.\n>>");

			fgets(buf, 20, stdin);
			//���๮�ڸ� �ι��ڷ� ��ü��
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//�Է¹��ۿ� �����ִ� �����͸� ���ϴ�.
			fflush(stdin);
			//�Էµȹ��ڿ��� ���ڷ� ��ȯ
			id = vide->number(buf);
			if (id != -1)
				person->removeCustomer(id);
			break;

		default:
			continue;
		}
		printf("����Ű�� �����ּ���.\n");
		getch();

	} while (ch != 'q' && ch != 'Q');

	printf("Good Bye!!\n");
}

int main()
{	
	Video vd;
	Customer cs;
	showMenu();
	//vHead->removeAllVideo();
	//cHead->removeAllCustomer();

	return 0;
}
#endif