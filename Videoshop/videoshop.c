#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#pragma warning (disable:4996)

#define TRUE 1
#define FALSE 0
struct customer {
	char* name;       //�̸�
	int id;           //�Ϸù�ȣ 
	char* addr;       //�ּ�
	int lendlist[50]; //�뿩�� ��������Ʈ
	int ncount;       //�뿩�� ���� ����
	struct customer* next; //��ũ (�̿��� customer�� �ּҸ� ������)
};


struct video {
	char* name;  //����
	int id;      //�Ϸù�ȣ
	int lended;  //�뿩���� 1=�뿩��, 0=�뿩�ʵ�
	char* debtor_name;//�뿩�� ��
	struct video* next; //��ũ (�̿��� video�� �ּҸ� ������)
};


typedef struct customer CUSTOMER;
typedef struct video VIDEO;

CUSTOMER* cHead;
VIDEO* vHead;

VIDEO* registerVideo();
void listVideo();
VIDEO* findVideo(int id);
void removeVideo(int id);
void lendVideo(int vid);
void restoreVideo();
void removeAllVideo() ;

void registerCustomer();
void listCustomer();
CUSTOMER* findCustomer(int id);
void showCustomerInfo(CUSTOMER* person);
void removeCustomer(int id);

void removeAllCustomer();
void showMenu();
int number(char* buf);

void main() {

	cHead = NULL;
	vHead = NULL;

	showMenu();
	removeAllVideo();
	removeAllCustomer();
}

//����޴��� ����մϴ�.
void showMenu() {
	char ch;
	int id;
	char buf[20];
	CUSTOMER* person = NULL;
	int i=0;

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

		switch(ch) {
			case '1':
				registerVideo();
				break;

			case '2':
				printf("������ ���� �Ϸù�ȣ�� �Է��ϼ���.\n>>");

				fgets(buf, 20, stdin);
				//���๮�ڸ� �ι��ڷ� ��ü��
				if(*(buf + (strlen(buf) - 1)) == '\n')
					*(buf + (strlen(buf) - 1)) = '\0';
				//�Է¹��ۿ� �����ִ� �����͸� ���ϴ�.
				fflush(stdin);
				//�Էµȹ��ڿ��� ���ڷ� ��ȯ
				id = number(buf);
				if(id != -1)
					removeVideo(id);
				break;

			case '3':
				listVideo();
				break;

			case '4':
				listVideo();
				printf("�뿩�� ���� �Ϸù�ȣ�� �Է��ϼ���.\n>>");

				fgets(buf, 20, stdin);
				//���๮�ڸ� �ι��ڷ� ��ü��
				if(*(buf + (strlen(buf) - 1)) == '\n')
					*(buf + (strlen(buf) - 1)) = '\0';
				//�Է¹��ۿ� �����ִ� �����͸� ���ϴ�.
				fflush(stdin);
				//�Էµȹ��ڿ��� ���ڷ� ��ȯ
				id = number(buf);
				if(id != -1)
					lendVideo(id);
				break;

			case '5':
				restoreVideo();
				break;

			case '6':
				registerCustomer();
				break;

			case '7':
				listCustomer();
				break;

			case '8':
				listCustomer();
				printf("�˻��� ȸ�� ��ȣ�� �Է����ּ���.\n>>");
				fgets(buf, 20, stdin);
				//���๮�ڸ� �ι��ڷ� ��ü��
				if(*(buf + (strlen(buf) - 1)) == '\n')
					*(buf + (strlen(buf) - 1)) = '\0';
				//�Է¹��ۿ� �����ִ� �����͸� ���ϴ�.
				fflush(stdin);
				//�Էµȹ��ڿ��� ���ڷ� ��ȯ
				id = number(buf);
				if(id != -1) {
					person = findCustomer(id);
					if(person)
						showCustomerInfo(person);
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
				if(*(buf + (strlen(buf) - 1)) == '\n')
					*(buf + (strlen(buf) - 1)) = '\0';
				//�Է¹��ۿ� �����ִ� �����͸� ���ϴ�.
				fflush(stdin);
				//�Էµȹ��ڿ��� ���ڷ� ��ȯ
				id = number(buf);
				if(id != -1)
					removeCustomer(id);
				break;

			default:
				continue;
		}
		printf("����Ű�� �����ּ���.\n");
		getch();

	}while(ch != 'q' && ch != 'Q');

	printf("Good Bye!!\n");
}


//������ ���
VIDEO* registerVideo()
{
	int id = 1;
	VIDEO* tmp = NULL;
	VIDEO* val = NULL;

	//�Ǹ������� �Էµ� id ã��
	if(vHead != NULL) {
		tmp = vHead;
		id = tmp->id + 1;
		while(tmp->next != NULL) {
			tmp = tmp->next;
			id = tmp->id + 1;
		}
	}

	val = (VIDEO*) malloc(sizeof(VIDEO));
	val->id = id;
	val->lended = 0;
	val->debtor_name = (char*)malloc(sizeof(char)*50);
	strcpy(val->debtor_name, "");
	val->next = NULL;

	printf("���� ������ �Է����ּ��� \n>>");
	val->name = (char*) malloc(sizeof(char)*50);
	do {
		fgets(val->name, 20, stdin);

		//���๮�ڸ� �ι��ڷ� ��ü��
		if(*(val->name + (strlen(val->name) - 1)) == '\n')
			*(val->name + (strlen(val->name) - 1)) = '\0';
		if(strcmp(val->name, ""))
			break;
	}while(TRUE);

	if(vHead == NULL) {
		vHead = val;
		return val;
	}
	else {
		tmp = vHead;
		//����Ʈ���� �Ǹ����� ��带 ã�´�
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = val;
	}
	return val;
}

//���� ����� ����մϴ�
void listVideo() {
	VIDEO* tmp = NULL;
	VIDEO* val = NULL;
	char str[100];
	tmp = vHead;
	//�ƹ��� ���뵵 ������ �ٷ� ����
	if(tmp == NULL)
		return;

	printf("��ȣ, ������, ������, ��������\n");
	while(tmp != NULL) {
		char buf[20];
		if(tmp->lended) {
			strcpy(buf, " ����Ұ�");
		}
		else  {
			strcpy(buf, " ���Ⱑ��");
		}
		sprintf(str, "%d> %s, %s, %s", tmp->id, tmp->name, tmp->debtor_name, buf);

		printf("%s\n", str);
		tmp = tmp->next;
	}
}

//������ �˻��մϴ�.(�Ϸù�ȣ��..)
VIDEO* findVideo(int id) {
	VIDEO* tmp = NULL;
	tmp = vHead;

	while(tmp != NULL) {
		if(tmp->id == id)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

// ������ �����մϴ�
void removeVideo(int id) {
	VIDEO* tmp;
	VIDEO* prv; 
	tmp = prv = vHead;
	//�����Ͱ� ��ġ�ϴ� ��带 ã�ų�, ����� ���� �����ϸ� while���� ���
	while(tmp != NULL && (tmp->id != id)){
		prv = tmp;
		tmp = tmp->next;
	}

	//���ϴ� ��带 ã�Ҵ��� üũ
	if(tmp != NULL) {
		//ã�� ��尡 head���, head�� head�� ������(tmp)�� ����Ű�� ��
		if(tmp == prv)
			vHead = tmp->next;
		//prv�� �����׸��� tmp�� �����׸��� �ǵ�����
		else
			prv->next = tmp->next;

		//ã������� �޸𸮸� ����
		free(tmp->name);
		free(tmp->debtor_name);
		free(tmp);
		printf("�����Ͽ����ϴ�.\n");
		return;
	}
	printf("�Է��� ������ �������� �ʽ��ϴ�.\n");
}

// ������ ��� �����մϴ�
void removeAllVideo() {
	VIDEO* tmp;
	VIDEO* next;
	tmp = vHead;
	//�����Ͱ� ��ġ�ϴ� ��带 ã�ų�, ����� ���� �����ϸ� while���� ���
	while(tmp != NULL){
		next = tmp->next;
		//ã������� �޸𸮸� ����
		free(tmp->name);
		free(tmp->debtor_name);
		free(tmp);

		tmp = next;
	}
}

// ������ �뿩�մϴ�.
void lendVideo(int vid) {
	char buf[100];
	CUSTOMER* person = NULL;
	int id = 0;
	//���� �˻�
	VIDEO* tmp = findVideo(vid);
	if(tmp == NULL) {
		printf("�Է��� ������ �������� �ʽ��ϴ�.\n");
		return;
	}
	//�뿩���ɿ��� üũ
	if(tmp->lended) {
		printf("���� �뿩���̶� �뿩 �Ұ��� �մϴ�..\n");
		return;
	}
	printf("������ �뿩�Ͻô� ȸ����ȣ�� �Է����ּ��� \n");

	fgets(buf, 100, stdin);
	//���๮�ڸ� �ι��ڷ� ��ü��
	if(*(buf + (strlen(buf) - 1)) == '\n')
		*(buf + (strlen(buf) - 1)) = '\0';
	
	//�Էµȹ��ڿ��� ���ڷ� ��ȯ
	id = number(buf);
	if(id != -1) {
		//ȸ���˻�		
		person = findCustomer(id);
		if(person)
			showCustomerInfo(person);
		if(!person) {
			printf("�������� �ʴ� ȸ���Դϴ�.\n");
			return;
		}
		else if(person->ncount >= 20) {
			printf("�뿩�Ҽ� �ִ� ������ ������ �ʰ��߽��ϴ�.\n");
			return;
		}
	}
	else  {
		printf("�������� �ʴ� ȸ���Դϴ�.\n");
		return;
	}

	//�뿩�������
	person->lendlist[person->ncount++] = vid;
	tmp->lended = TRUE;
	strcpy(tmp->debtor_name, buf);
	printf("���������� ó���Ǿ����ϴ�..\n");
}

//������ �ݳ��մϴ�.
void restoreVideo()
{
	char buf[20];
	CUSTOMER* person = NULL;
	VIDEO* vid = NULL;
	char ch;
	int i = 0;
	int id = 0;

	//ȸ����� ���
	listCustomer();
	printf("������ �ݳ��� ȸ�� ��ȣ�� �Է����ּ���.\n>>");
	fgets(buf, 20, stdin);
	//���๮�ڸ� �ι��ڷ� ��ü��
	if(*(buf + (strlen(buf) - 1)) == '\n')
		*(buf + (strlen(buf) - 1)) = '\0'; 

	//�Էµȹ��ڿ��� ���ڷ� ��ȯ
	id = number(buf);
	if(id != -1) {
		//ȸ���˻�		
		person = findCustomer(id);
		if(person)
			showCustomerInfo(person);
		if(!person) {
			printf("�������� �ʴ� ȸ���Դϴ�.\n");
			return;
		}
	
	}
	else  {
		printf("�������� �ʴ� ȸ���Դϴ�.\n");
		return;
	}

	printf("������ ��� �ݳ��Ͻʴϱ�? (y/n) \n>>");
	ch = getchar();
	if(ch == 'y' || ch == 'Y') {
		for(i=0; i<person->ncount; i++) {
			vid =findVideo(person->lendlist[i]);
			if(vid != NULL) {
				vid->lended = FALSE;
				strcpy(vid->debtor_name, "");
			}
		}
		person->ncount = 0;	
		printf("���������� ó���Ǿ����ϴ�..\n");
	}
	//�Է¹��ۿ� �����ִ� �����͸� ���ϴ�.
	fflush(stdin);
}

// �ű� ȸ���� ����մϴ�.
void registerCustomer()
{
	int id = 1;
	CUSTOMER* tmp = NULL;
	CUSTOMER* val = NULL;

	//�Ǹ������� �Էµ� id ã��
	if(cHead != NULL) {
		tmp = cHead;
		id = tmp->id + 1;
		while(tmp->next != NULL) {
			tmp = tmp->next;
			id = tmp->id + 1;
		}
	}

	val = (CUSTOMER*) malloc(sizeof(CUSTOMER));
	val->id = id;
	val->ncount = 0;
	val->next = NULL;

	printf("�̸��� �Է����ּ��� \n>>");
	val->name = (char*) malloc(sizeof(char)*20);
	fgets(val->name, 20, stdin);
	//���๮�ڸ� �ι��ڷ� ��ü��
	if(*(val->name + (strlen(val->name) - 1)) == '\n')
		*(val->name + (strlen(val->name) - 1)) = '\0';  

	printf("�ּҸ� �Է����ּ��� \n");
	val->addr = (char*) malloc(sizeof(char)*20);
	fgets(val->addr, 20, stdin);
	//���๮�ڸ� �ι��ڷ� ��ü��
	if(*(val->addr + (strlen(val->addr) - 1)) == '\n')
		*(val->addr + (strlen(val->addr) - 1)) = '\0';  

	if(cHead == NULL) {
		cHead = val;
		return;
	}
	else {
		tmp = cHead;
		//����Ʈ���� �Ǹ����� ��带 ã�´�
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = val;
	}
}

//ȸ�� ����� ����մϴ�
void listCustomer() {
	CUSTOMER* tmp = NULL;
	CUSTOMER* val = NULL;
	char str[100];
	tmp = cHead;
	if(tmp == NULL)
		return;
	//�ƹ��� ���뵵 ������ �ٷ� ����
	printf("��ȣ,�̸�,�ּ�,�����������\n");
	while(tmp != NULL) {
		sprintf(str, "%d> %s, %s, %d", tmp->id, tmp->name, tmp->addr, tmp->ncount);
		printf("%s\n", str);
		tmp = tmp->next;
	}
}

//ȸ���� �˻��մϴ�.(�̸����� �˻�..)
CUSTOMER* findCustomer(int id) {
	CUSTOMER* tmp = NULL;
	tmp = cHead;

	while(tmp != NULL) {
		if(tmp->id == id)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

//�ش� ȸ���� ������ ȭ�鿡 ����մϴ�.
void showCustomerInfo(CUSTOMER* person) {
	VIDEO* tmp = NULL;
	VIDEO* val = NULL;
	int i=0;

	printf("�̸�:%s, �ּ�:%s\n", person->name, person->addr);
	if(vHead == NULL || person->ncount < 1)
		return;

	tmp = vHead;
	printf("-- ������ ���� ��� --\n");
	for(i=0; i<person->ncount; i++) {
		tmp = vHead;
		while(tmp != NULL) {
			if(tmp->id == person->lendlist[i]){
				printf("%s\n", tmp->name);
				break;
			}
			tmp = tmp->next;
		}
	}
	printf("------------------------\n");
}

// ȸ���� ��� �����մϴ�
void removeAllCustomer() {
	CUSTOMER* tmp;
	CUSTOMER* next;
	tmp = cHead;
	//�����Ͱ� ��ġ�ϴ� ��带 ã�ų�, ����� ���� �����ϸ� while���� ���
	while(tmp != NULL){
		next = tmp->next;
		//ã������� �޸𸮸� ����
		free(tmp->name);
		free(tmp->addr);
		free(tmp);

		tmp = next;
	}
}

//���ڿ��� int Ÿ������ ��ȯ�մϴ�.
int number(char* buf) {
	int i=0;
	int id = 0;
	while(buf[i]) {
		if(!(buf[i] >= '0' && buf[i] <= '9'))
			break;
		i++;
	}
	if(i>0 && (i == strlen(buf))) {
		id =atoi(buf);
		return id;
	}
	else
		return -1;
}

//ȸ���� �����մϴ�.
void removeCustomer(int id)
{
	CUSTOMER* tmp;
	CUSTOMER* prv; 
	VIDEO* vid;
	int i = 0;

	tmp = prv = cHead;
	//�����Ͱ� ��ġ�ϴ� ��带 ã�ų�, ����� ���� �����ϸ� while���� ���
	while(tmp != NULL && (tmp->id != id)){
		prv = tmp;
		tmp = tmp->next;
	}

	//���ϴ� ��带 ã�Ҵ��� üũ
	if(tmp != NULL) {
		//ã�� ��尡 head���, head�� head�� ������(tmp)�� ����Ű�� ��
		if(tmp == prv)
			cHead = tmp->next;
		//prv�� �����׸��� tmp�� �����׸��� �ǵ�����
		else
			prv->next = tmp->next;

		//������ �ִ� ������ �뿩������ �ʱ�ȭ
		for(i=0; i<tmp->ncount; i++) {
			vid =findVideo(tmp->lendlist[i]);
			if(vid != NULL) {
				vid->lended = FALSE;
				strcpy(vid->debtor_name, "");
			}
		}

		//ã������� �޸𸮸� ����
		free(tmp->name);
		free(tmp->addr);
		free(tmp);
		printf("�����Ͽ����ϴ�.\n");
		return;
	}
	printf("�Է��� ȸ����ȣ �������� �ʽ��ϴ�.\n");
}
#endif
