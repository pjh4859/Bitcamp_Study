#if 0
#include"videoshop.h"
//������ ���
//���ڿ��� int Ÿ������ ��ȯ�մϴ�.
int Video::number(char* buf) {
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
//���ڿ��� int Ÿ������ ��ȯ�մϴ�.
int Customer::number(char* buf) {
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

Video* Video::registerVideo()
{
	int id = 1;
	Video* tmp = NULL;
	Video* val = NULL;

	//�Ǹ������� �Էµ� id ã��
	if (vHead != NULL) {
		tmp = vHead;
		id = tmp->id + 1;
		while (tmp->next != NULL) {
			tmp = tmp->next;
			id = tmp->id + 1;
		}
	}

	val = new Video;
	//val = (Video*)malloc(sizeof(Video));
	val->id = id;

	val->lended = 0;
	val->debtor_name = new (char[50]);
	//val->debtor_name = (char*)malloc(sizeof(char) * 50);
	strcpy(val->debtor_name, "");
	val->next = NULL;

	printf("���� ������ �Է����ּ��� \n>>");
	val->name = new (char[50]);
	//val->name = (char*)malloc(sizeof(char) * 50);
	do {
		fgets(val->name, 20, stdin);

		//���๮�ڸ� �ι��ڷ� ��ü��
		if (*(val->name + (strlen(val->name) - 1)) == '\n')
			*(val->name + (strlen(val->name) - 1)) = '\0';
		if (strcmp(val->name, ""))
			break;
	} while (TRUE);

	if (vHead == NULL) {
		vHead = val;
		return val;
	}
	else {
		tmp = vHead;
		//����Ʈ���� �Ǹ����� ��带 ã�´�
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = val;
	}
	return val;
}

//���� ����� ����մϴ�
void Video::listVideo() 
{
	Video* tmp = NULL;
	Video* val = NULL;
	char str[100];
	tmp = vHead;
	//�ƹ��� ���뵵 ������ �ٷ� ����
	if (tmp == NULL)
		return;

	printf("��ȣ, ������, ������, ��������\n");
	while (tmp != NULL) {
		char buf[20];
		if (tmp->lended) {
			strcpy(buf, " ����Ұ�");
		}
		else {
			strcpy(buf, " ���Ⱑ��");
		}
		sprintf(str, "%d> %s, %s, %s", tmp->id, tmp->name, tmp->debtor_name, buf);

		printf("%s\n", str);
		tmp = tmp->next;
	}
}
//������ �˻��մϴ�.(�Ϸù�ȣ��..)
Video* Video::findVideo(int id) 
{
	Video* tmp = NULL;
	tmp = vHead;

	while (tmp != NULL) {
		if (tmp->id == id)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}
// ������ �����մϴ�
void Video::removeVideo(int id) 
{
	Video* tmp;
	Video* prv;
	tmp = prv = vHead;
	//�����Ͱ� ��ġ�ϴ� ��带 ã�ų�, ����� ���� �����ϸ� while���� ���
	while (tmp != NULL && (tmp->id != id)) {
		prv = tmp;
		tmp = tmp->next;
	}

	//���ϴ� ��带 ã�Ҵ��� üũ
	if (tmp != NULL) {
		//ã�� ��尡 head���, head�� head�� ������(tmp)�� ����Ű�� ��
		if (tmp == prv)
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
void Video::removeAllVideo() 
{
	Video* tmp;
	Video* next;
	tmp = vHead;
	//�����Ͱ� ��ġ�ϴ� ��带 ã�ų�, ����� ���� �����ϸ� while���� ���
	while (tmp != NULL) {
		next = tmp->next;
		//ã������� �޸𸮸� ����
		free(tmp->name);
		free(tmp->debtor_name);
		free(tmp);

		tmp = next;
	}
}

// ������ �뿩�մϴ�.
void Video::lendVideo(int vid) 
{
	char buf[100];
	Customer* person = NULL;
	int id = 0;
	//���� �˻�
	Video* tmp = findVideo(vid);
	if (tmp == NULL) {
		printf("�Է��� ������ �������� �ʽ��ϴ�.\n");
		return;
	}
	//�뿩���ɿ��� üũ
	if (tmp->lended) {
		printf("���� �뿩���̶� �뿩 �Ұ��� �մϴ�..\n");
		return;
	}
	printf("������ �뿩�Ͻô� ȸ����ȣ�� �Է����ּ��� \n");

	fgets(buf, 100, stdin);
	//���๮�ڸ� �ι��ڷ� ��ü��
	if (*(buf + (strlen(buf) - 1)) == '\n')
		*(buf + (strlen(buf) - 1)) = '\0';

	//�Էµȹ��ڿ��� ���ڷ� ��ȯ
	id = vHead->number(buf);
	if (id != -1) {
		//ȸ���˻�		
		person = person->findCustomer(id);
		if (person)
			person->showCustomerInfo(person);
		if (!person) {
			printf("�������� �ʴ� ȸ���Դϴ�.\n");
			return;
		}
		else if (person->ncount >= 20) {
			printf("�뿩�Ҽ� �ִ� ������ ������ �ʰ��߽��ϴ�.\n");
			return;
		}
	}
	else {
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
void Video::restoreVideo()
{
	char buf[20];
	Customer* person = NULL;
	Video* vid = NULL;
	char ch;
	int i = 0;
	int id = 0;

	//ȸ����� ���
	person->listCustomer();
	printf("������ �ݳ��� ȸ�� ��ȣ�� �Է����ּ���.\n>>");
	fgets(buf, 20, stdin);
	//���๮�ڸ� �ι��ڷ� ��ü��
	if (*(buf + (strlen(buf) - 1)) == '\n')
		*(buf + (strlen(buf) - 1)) = '\0';

	//�Էµȹ��ڿ��� ���ڷ� ��ȯ
	id = vHead->number(buf);
	if (id != -1) {
		//ȸ���˻�		
		person = person->findCustomer(id);
		if (person)
			person->showCustomerInfo(person);
		if (!person) {
			printf("�������� �ʴ� ȸ���Դϴ�.\n");
			return;
		}

	}
	else {
		printf("�������� �ʴ� ȸ���Դϴ�.\n");
		return;
	}

	printf("������ ��� �ݳ��Ͻʴϱ�? (y/n) \n>>");
	ch = getchar();
	if (ch == 'y' || ch == 'Y') {
		for (i = 0; i < person->ncount; i++) {
			vid = findVideo(person->lendlist[i]);
			if (vid != NULL) {
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
void Customer::registerCustomer()
{
	int id = 1;
	Customer* tmp = NULL;
	Customer* val = NULL;

	//�Ǹ������� �Էµ� id ã��
	if (cHead != NULL) {
		tmp = cHead;
		id = tmp->id + 1;
		while (tmp->next != NULL) {
			tmp = tmp->next;
			id = tmp->id + 1;
		}
	}
	val = new Customer;
	//val = (CUSTOMER*)malloc(sizeof(CUSTOMER));
	val->id = id;
	val->ncount = 0;
	val->next = NULL;

	printf("�̸��� �Է����ּ��� \n>>");
	val->name = (char*)malloc(sizeof(char) * 20);
	fgets(val->name, 20, stdin);
	//���๮�ڸ� �ι��ڷ� ��ü��
	if (*(val->name + (strlen(val->name) - 1)) == '\n')
		*(val->name + (strlen(val->name) - 1)) = '\0';

	printf("�ּҸ� �Է����ּ��� \n");
	val->addr = (char*)malloc(sizeof(char) * 20);
	fgets(val->addr, 20, stdin);
	//���๮�ڸ� �ι��ڷ� ��ü��
	if (*(val->addr + (strlen(val->addr) - 1)) == '\n')
		*(val->addr + (strlen(val->addr) - 1)) = '\0';

	if (cHead == NULL) {
		cHead = val;
		return;
	}
	else {
		tmp = cHead;
		//����Ʈ���� �Ǹ����� ��带 ã�´�
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = val;
	}
}

//ȸ�� ����� ����մϴ�
void Customer::listCustomer() {
	Customer* tmp = NULL;
	Customer* val = NULL;
	char str[100];
	tmp = cHead;
	if (tmp == NULL)
		return;
	//�ƹ��� ���뵵 ������ �ٷ� ����
	printf("��ȣ,�̸�,�ּ�,�����������\n");
	while (tmp != NULL) {
		sprintf(str, "%d> %s, %s, %d", tmp->id, tmp->name, tmp->addr, tmp->ncount);
		printf("%s\n", str);
		tmp = tmp->next;
	}
}

//ȸ���� �˻��մϴ�.(�̸����� �˻�..)
Customer* Customer::findCustomer(int id) {
	Customer* tmp = NULL;
	tmp = cHead;

	while (tmp != NULL) {
		if (tmp->id == id)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

//�ش� ȸ���� ������ ȭ�鿡 ����մϴ�.
void Customer::showCustomerInfo(Customer* person) {
	Video* tmp = NULL;
	Video* val = NULL;
	int i = 0;

	printf("�̸�:%s, �ּ�:%s\n", person->name, person->addr);
	if (vHead == NULL || person->ncount < 1)
		return;

	tmp = vHead;
	printf("-- ������ ���� ��� --\n");
	for (i = 0; i < person->ncount; i++) {
		tmp = vHead;
		while (tmp != NULL) {
			if (tmp->id == person->lendlist[i]) {
				printf("%s\n", tmp->name);
				break;
			}
			tmp = tmp->next;
		}
	}
	printf("------------------------\n");
}
//ȸ���� �����մϴ�.
void Customer::removeCustomer(int id)
{
	Customer* tmp;
	Customer* prv;
	Video* vid;
	int i = 0;

	tmp = prv = cHead;
	//�����Ͱ� ��ġ�ϴ� ��带 ã�ų�, ����� ���� �����ϸ� while���� ���
	while (tmp != NULL && (tmp->id != id)) {
		prv = tmp;
		tmp = tmp->next;
	}

	//���ϴ� ��带 ã�Ҵ��� üũ
	if (tmp != NULL) {
		//ã�� ��尡 head���, head�� head�� ������(tmp)�� ����Ű�� ��
		if (tmp == prv)
			cHead = tmp->next;
		//prv�� �����׸��� tmp�� �����׸��� �ǵ�����
		else
			prv->next = tmp->next;

		//������ �ִ� ������ �뿩������ �ʱ�ȭ
		for (i = 0; i < tmp->ncount; i++) {
			vid = vid->findVideo(tmp->lendlist[i]);
			if (vid != NULL) {
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

// ȸ���� ��� �����մϴ�
void Customer::removeAllCustomer() {
	Customer* tmp = NULL;
	Customer* next;
	tmp = cHead;
	//�����Ͱ� ��ġ�ϴ� ��带 ã�ų�, ����� ���� �����ϸ� while���� ���
	while (tmp != NULL) {
		next = tmp->next;
		//ã������� �޸𸮸� ����
		free(tmp->name);
		free(tmp->addr);
		free(tmp);

		tmp = next;
	}
}
#endif