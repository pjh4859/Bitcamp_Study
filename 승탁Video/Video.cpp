#include "Video.h"
#include "header.h"
using namespace std;
int Video::SETlended(int TorF)
{
	lended = TorF;
	return lended;
}
void Video::SETdebtorName()
{
	debtor_name = "";
}
string Video::GETNAME()
{
	return name;
}
int Video::GETID()
{
	return id;
}

Video *Video::GETNEXT()
{
	return next;
}
Video *Video::registerVideo(Video** vHead)
{
	int id = 1;
	static int i = 0;
	Video* tmp = NULL;
	Video* val = NULL;

	//�Ǹ������� �Էµ� id ã��
	if (*vHead != NULL) {
		tmp = *vHead;
		id = tmp->id + 1;
		while (tmp->next != NULL) {
			tmp = tmp->next;
			id = tmp->id + 1;
		}
	}
	val = new Video;
	val->id = id;
	val->lended = 0;
	val->debtor_name = " ";
	val->next = NULL;

	printf("���� ������ �Է����ּ��� \n>>");

	cin.ignore();
	getline(cin,val->name);
	if (*vHead == NULL) {
		*vHead = val;
		return val;
	}
	else {
		tmp = *vHead;
		//����Ʈ���� �Ǹ����� ��带 ã�´�
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = val;
	}
	return val;
}
Video* Video::findVideo(Video** vHead,int id)
{
	Video* tmp = NULL;
	tmp = *vHead;
	while (tmp != NULL) {
		if (tmp->id == id)
			return tmp;
		tmp = tmp->next;
	}
	//return NULL;
}
Video* Video::_findVideo(Video** vHead, int **id)
{
	Video* tmp = NULL;
	tmp = *vHead;
	int i = 0;
	while (tmp != NULL) {
		if (tmp->id == (*id)[i])
			return tmp;
		tmp = tmp->next;
		++i;
	}
	return NULL;
}


/***************************************/
void Video::listVideo(Video** vHead)
{
	Video* tmp = NULL;
	Video* val = NULL;
	tmp = *vHead;
	//�ƹ��� ���뵵 ������ �ٷ� ����
	if (tmp == NULL)
	{
		cout << "���� �����ϴ�\n";
		return;
	}
	while (tmp != NULL) {
		string temp;
		if (tmp->lended) {
			temp="����Ұ�";
		}
		else {
			temp = "���Ⱑ��";
		}
		cout << "======================\n";
		cout << "[��ȣ] :"<<tmp->id <<"\n"<<"[������]:"<< tmp->name << "\n" <<"[��������]:"<< temp<<"\n";
		cout << "======================\n";
		tmp = tmp->next;
	}
}
void Video::removeVideo(Video **vHead,int id)
{
	Video* tmp;
	Video* prv;
	tmp = prv = *vHead;
	//�����Ͱ� ��ġ�ϴ� ��带 ã�ų�, ����� ���� �����ϸ� while���� ���
	while (tmp != NULL && (tmp->id != id)) {
		prv = tmp;
		tmp = tmp->next;
	}

	//���ϴ� ��带 ã�Ҵ��� üũ
	if (tmp != NULL) {
		//ã�� ��尡 head���, head�� head�� ������(tmp)�� ����Ű�� ��
		if (tmp == prv)
			*vHead = tmp->next;
		//prv�� �����׸��� tmp�� �����׸��� �ǵ�����
		else
			prv->next = tmp->next;

		//ã������� �޸𸮸� ����
		free(tmp);
		printf("�����Ͽ����ϴ�.\n");
		return;
	}
	printf("�Է��� ������ �������� �ʽ��ϴ�.\n");
}

Video *Video::lendVideo(Customer** cHead, Video** vHead, int vid)
{
	Customer* person = NULL;
	//���� �˻�
	Video* tmp = findVideo(vHead,vid);
	int _id = 0;
	//Video* tmp = *vHead;
	if (tmp == NULL) {
		printf("�Է��� ������ �������� �ʽ��ϴ�.\n");
		return NULL;
	}
	//�뿩���ɿ��� üũ
	if (tmp->lended) {
		printf("���� �뿩���̶� �뿩 �Ұ��� �մϴ�..\n");
		return NULL;
	}
	
	cout << "ȸ�� ��ȣ�� �Է����ּ���\n";
	cin >> _id;
	if (_id != -1)
	{
		person = person->findCustomer(cHead,_id);
		if (!person) {
			printf("�������� �ʴ� ȸ���Դϴ�.\n");
			return NULL;
		}	
		else if ((person->GETCustomerncount()) >= 20) 
		{
			printf("�뿩�Ҽ� �ִ� ������ ������ �ʰ��߽��ϴ�.\n");
		}
	}
	else {
		printf("�������� �ʴ� ȸ���Դϴ�.\n");
	}

	//�뿩�������
	int ncount = person->GETCustomerncount();
	person->SETNcount(ncount, vid);
	tmp->lended = 1;
	tmp->debtor_name = vid;
	printf("���������� ó���Ǿ����ϴ�..\n");
	person->showCustomerInfo(vHead, cHead);
}
void Video::restoreVideo(Customer **cHead,Video** vHead)
{
	Customer* person = NULL;
	Video* vid = NULL;
	char ch;
	int i = 0;
	int id = 0;

	//ȸ����� ���
	person->listCustomer(cHead);
	printf("������ �ݳ��� ȸ�� ��ȣ�� �Է����ּ���.\n>>");
	cin >> id;
	
	if (id != -1) 
	{
		person = person->findCustomer(cHead, id);
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
	cin >> ch;
	int* _id = person->GETCustomerLendlist();
	if (ch == 'y' || ch == 'Y') {
		for (i = 0; i < person->GETCustomerncount(); i++)
		{
			vid = findVideo(vHead,id+i);
			if (vid != NULL) {
				vid->lended = 0;
				vid->debtor_name = " ";
			}
		}
		person->OneSetncount(0);
		printf("���������� ó���Ǿ����ϴ�..\n");
	}
}
void Video::removeAllVideo(Video **vHead)
{
	Video* tmp;
	Video* next;
	tmp = *vHead;
	while (tmp != NULL) {
		next = tmp->next;
		//ã������� �޸𸮸� ����
		free(tmp);
		tmp = next;
	}
}
/***************************************/