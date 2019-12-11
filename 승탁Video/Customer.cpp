#include "Customer.h"
//#include "Video.h"

void Customer::OneSetncount(int n)
{
	ncount = n;
}
void Customer::SETNcount(int _nCount,int vid)
{
	int __nCount=++_nCount;
	ncount = __nCount;
	lendlist[_nCount] = vid;
}
int Customer::GETcustomerID()
{
	return id;
}
int *Customer::GETCustomerLendlist()
{
	//_lendlist = lendlist;
	return lendlist;
}
int Customer::GETCustomerncount()
{
	return ncount;
}

Customer *Customer::findCustomer(Customer** cHead,int id)
{

	Customer* tmp = NULL;
	tmp = *cHead;

	while (tmp != NULL) {
		if (tmp->id == id)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}
Customer *Customer::showCustomerInfo(Video **vHead,Customer** cHead)
{
	Video* tmp = NULL;
	Video* val = NULL;
	int i = 0;
	cout << "�̸� :" << (*cHead)->name << "," << "�ּ� : " << (*cHead)->addr<<"\n";
	cout << "================================\n";
	cout << "[��ȣ ]:" << (*cHead)->id<< "\n" << "[�̸�]:" << (*cHead)->name << "\n" << "[�ּ�]:" << (*cHead)->addr<< "\n" << "[��������]:" << (*cHead)->ncount<< "\n";
	cout << "================================\n";
	if (*vHead == NULL || (*cHead)->ncount < 1)
		return NULL;

	tmp = *vHead;
	printf("-- ������ ���� ��� --\n");
	for (i = 0; i < (*cHead)->ncount; i++) {
		tmp = *vHead;
		while (tmp != NULL) 
		{
			if (tmp->GETID() == (*cHead)->lendlist[i])
			{
				cout << tmp->GETNAME() << "\n";
				break;
			}
			tmp = tmp->GETNEXT();
		}
	}
	printf("------------------------\n");
}
void Customer::registerCustomer(Customer **cHead)
{
	int id = 1;
	Customer* tmp = NULL;
	Customer* val = NULL;

	//�Ǹ������� �Էµ� id ã��
	if (*cHead != NULL) {
		tmp = *cHead;
		id = tmp->id + 1;
		while (tmp->next != NULL) {
			tmp = tmp->next;
			id = tmp->id + 1;
		}
	}

	val = new Customer;
	val->id = id;
	val->ncount = 0;
	val->next = NULL;

	printf("�̸��� �Է����ּ��� \n>>");
	cin.ignore();
	getline(cin, val->name);
	//���๮�ڸ� �ι��ڷ� ��ü��

	printf("�ּҸ� �Է����ּ��� \n");
	//cin.ignore();
	getline(cin, val->addr);
	//���๮�ڸ� �ι��ڷ� ��ü��


	if (*cHead == NULL) {
		*cHead = val;
		return;
	}
	else {
		tmp = *cHead;
		//����Ʈ���� �Ǹ����� ��带 ã�´�
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = val;
	}
}
void Customer::listCustomer(Customer **cHead)
{
	Customer* tmp = NULL;
	Customer* val = NULL;
	tmp = *cHead;
	if (tmp == NULL)
		return;
	while (tmp != NULL)
	{
		cout << "================================\n";
		cout << "[��ȣ ]:"<<tmp->id<<"\n" << "[�̸�]:" << tmp->name << "\n" << "[�ּ�]:" << tmp->addr << "\n" << "[��������]:" << tmp->ncount << "\n";
		cout << "================================\n";
		tmp = tmp->next;
	}
}
void Customer::removeCustomer(Video **vHead,Customer**cHead,int id)
{
	Customer* tmp;
	Customer* prv;
	Video* vid=NULL;
	int i = 0;

	tmp = prv = *cHead;
	//�����Ͱ� ��ġ�ϴ� ��带 ã�ų�, ����� ���� �����ϸ� while���� ���
	while (tmp != NULL && (tmp->id != id)) {
		prv = tmp;
		tmp = tmp->next;
	}

	//���ϴ� ��带 ã�Ҵ��� üũ
	if (tmp != NULL) {
		//ã�� ��尡 head���, head�� head�� ������(tmp)�� ����Ű�� ��
		if (tmp == prv)
			*cHead = tmp->next;
		//prv�� �����׸��� tmp�� �����׸��� �ǵ�����
		else
			prv->next = tmp->next;
		//������ �ִ� ������ �뿩������ �ʱ�ȭ
		//Video* Video::findVideo(Video** vHead,int *id)
		
		for (i = 0; i < tmp->ncount; i++) {
			vid = vid->findVideo(vHead,lendlist[i]);
			if (vid != NULL) {
				vid->SETlended(0);
				vid->SETdebtorName();
			}
		}

		//ã������� �޸𸮸� ����
		free(tmp);
		printf("�����Ͽ����ϴ�.\n");
		return;
	}
	printf("�Է��� ȸ����ȣ �������� �ʽ��ϴ�.\n");
}

//���ڿ��� int Ÿ������ ��ȯ�մϴ�.
int number(char* buf) {
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