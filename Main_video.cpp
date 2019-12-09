#if 0
#include"videoshop.h"
void showMenu()
{
	char ch;
	int id;
	char buf[20];
	Customer* person = NULL;
	int i = 0;

	do {
		printf("---------------------\n");
		printf("1: ���� ��� \n");
		printf("2: ���� ���� \n");
		printf("3: ���� ��� \n");
		printf("4: ���� �뿩 \n");
		printf("5: ���� �ݳ� \n");

		printf("6: �ű�ȸ�� ��� \n");
		printf("7: ȸ����� ��� \n");
		printf("8: ȸ������ ��� \n");
		printf("9: ȸ������ \n");

		printf("(Q/q): ���α׷� ���� \n");
		printf("---------------------\n>>");

		ch = getchar();
		getchar();
		//fflush(stdin);

		switch (ch) {
		case '1':
			vHead->registerVideo();
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
			id = vHead->number(buf);
			if (id != -1)
				vHead->removeVideo(id);
			break;

		case '3':
			vHead->listVideo();
			break;

		case '4':
			vHead->listVideo();
			printf("�뿩�� ���� �Ϸù�ȣ�� �Է��ϼ���.\n>>");

			fgets(buf, 20, stdin);
			//���๮�ڸ� �ι��ڷ� ��ü��
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//�Է¹��ۿ� �����ִ� �����͸� ���ϴ�.
			fflush(stdin);
			//�Էµȹ��ڿ��� ���ڷ� ��ȯ
			id = vHead->number(buf);
			if (id != -1)
				vHead->lendVideo(id);
			break;

		case '5':
			vHead->restoreVideo();
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
			id = vHead->number(buf);
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
			id = vHead->number(buf);
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
	cHead = NULL;
	vHead = NULL;
	
	showMenu();
	//vHead->removeAllVideo();
	//cHead->removeAllCustomer();

	return 0;
}
#endif
#if 1
#include"videoshop.h"

int number(char* buf) 
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
void showMenu()
{
	char ch;
	int id;
	char buf[20];
	Customer* person = NULL;
	Video* vide = NULL;
	int i = 0;

	do {
		printf("---------------------\n");
		printf("1: ���� ��� \n");
		printf("2: ���� ���� \n");
		printf("3: ���� ��� \n");
		printf("4: ���� �뿩 \n");
		printf("5: ���� �ݳ� \n");

		printf("6: �ű�ȸ�� ��� \n");
		printf("7: ȸ����� ��� \n");
		printf("8: ȸ������ ��� \n");
		printf("9: ȸ������ \n");

		printf("(Q/q): ���α׷� ���� \n");
		printf("---------------------\n>>");

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
			id = number(buf);
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
			id = number(buf);
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
			id = number(buf);
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
			id = number(buf);
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
	//cHead = NULL;
	//vHead = NULL;

	showMenu();
	//vHead->removeAllVideo();
	//cHead->removeAllCustomer();

	return 0;
}
#endif