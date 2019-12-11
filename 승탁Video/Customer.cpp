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
	cout << "이름 :" << (*cHead)->name << "," << "주소 : " << (*cHead)->addr<<"\n";
	cout << "================================\n";
	cout << "[번호 ]:" << (*cHead)->id<< "\n" << "[이름]:" << (*cHead)->name << "\n" << "[주소]:" << (*cHead)->addr<< "\n" << "[비디오개수]:" << (*cHead)->ncount<< "\n";
	cout << "================================\n";
	if (*vHead == NULL || (*cHead)->ncount < 1)
		return NULL;

	tmp = *vHead;
	printf("-- 대출한 비디오 목록 --\n");
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

	//맨마지막에 입력된 id 찾기
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

	printf("이름을 입력해주세요 \n>>");
	cin.ignore();
	getline(cin, val->name);
	//개행문자를 널문자로 대체함

	printf("주소를 입력해주세요 \n");
	//cin.ignore();
	getline(cin, val->addr);
	//개행문자를 널문자로 대체함


	if (*cHead == NULL) {
		*cHead = val;
		return;
	}
	else {
		tmp = *cHead;
		//리스트에서 맨마지막 노드를 찾는다
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
		cout << "[번호 ]:"<<tmp->id<<"\n" << "[이름]:" << tmp->name << "\n" << "[주소]:" << tmp->addr << "\n" << "[비디오개수]:" << tmp->ncount << "\n";
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
	//데이터가 일치하는 노드를 찾거나, 노드의 끝에 도달하면 while문을 벗어남
	while (tmp != NULL && (tmp->id != id)) {
		prv = tmp;
		tmp = tmp->next;
	}

	//원하는 노드를 찾았는지 체크
	if (tmp != NULL) {
		//찾은 노드가 head라면, head에 head의 다음값(tmp)을 가리키게 함
		if (tmp == prv)
			*cHead = tmp->next;
		//prv의 다음항목이 tmp의 다음항목이 되도록함
		else
			prv->next = tmp->next;
		//가지고 있는 비디오의 대여정보를 초기화
		//Video* Video::findVideo(Video** vHead,int *id)
		
		for (i = 0; i < tmp->ncount; i++) {
			vid = vid->findVideo(vHead,lendlist[i]);
			if (vid != NULL) {
				vid->SETlended(0);
				vid->SETdebtorName();
			}
		}

		//찾은노드의 메모리를 해제
		free(tmp);
		printf("삭제하였습니다.\n");
		return;
	}
	printf("입력한 회원번호 존재하지 않습니다.\n");
}

//문자열을 int 타입으로 변환합니다.
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