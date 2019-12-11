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

	//맨마지막에 입력된 id 찾기
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

	printf("비디오 제목을 입력해주세요 \n>>");

	cin.ignore();
	getline(cin,val->name);
	if (*vHead == NULL) {
		*vHead = val;
		return val;
	}
	else {
		tmp = *vHead;
		//리스트에서 맨마지막 노드를 찾는다
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
	//아무런 내용도 없으면 바로 리턴
	if (tmp == NULL)
	{
		cout << "값이 없습니다\n";
		return;
	}
	while (tmp != NULL) {
		string temp;
		if (tmp->lended) {
			temp="대출불가";
		}
		else {
			temp = "대출가능";
		}
		cout << "======================\n";
		cout << "[번호] :"<<tmp->id <<"\n"<<"[비디오명]:"<< tmp->name << "\n" <<"[대출유무]:"<< temp<<"\n";
		cout << "======================\n";
		tmp = tmp->next;
	}
}
void Video::removeVideo(Video **vHead,int id)
{
	Video* tmp;
	Video* prv;
	tmp = prv = *vHead;
	//데이터가 일치하는 노드를 찾거나, 노드의 끝에 도달하면 while문을 벗어남
	while (tmp != NULL && (tmp->id != id)) {
		prv = tmp;
		tmp = tmp->next;
	}

	//원하는 노드를 찾았는지 체크
	if (tmp != NULL) {
		//찾은 노드가 head라면, head에 head의 다음값(tmp)을 가리키게 함
		if (tmp == prv)
			*vHead = tmp->next;
		//prv의 다음항목이 tmp의 다음항목이 되도록함
		else
			prv->next = tmp->next;

		//찾은노드의 메모리를 해제
		free(tmp);
		printf("삭제하였습니다.\n");
		return;
	}
	printf("입력한 비디오는 존재하지 않습니다.\n");
}

Video *Video::lendVideo(Customer** cHead, Video** vHead, int vid)
{
	Customer* person = NULL;
	//비디오 검색
	Video* tmp = findVideo(vHead,vid);
	int _id = 0;
	//Video* tmp = *vHead;
	if (tmp == NULL) {
		printf("입력한 비디오는 존재하지 않습니다.\n");
		return NULL;
	}
	//대여가능여부 체크
	if (tmp->lended) {
		printf("현재 대여중이라 대여 불가능 합니다..\n");
		return NULL;
	}
	
	cout << "회원 번호를 입력해주세요\n";
	cin >> _id;
	if (_id != -1)
	{
		person = person->findCustomer(cHead,_id);
		if (!person) {
			printf("존재하지 않는 회원입니다.\n");
			return NULL;
		}	
		else if ((person->GETCustomerncount()) >= 20) 
		{
			printf("대여할수 있는 비디오의 개수를 초과했습니다.\n");
		}
	}
	else {
		printf("존재하지 않는 회원입니다.\n");
	}

	//대여정보등록
	int ncount = person->GETCustomerncount();
	person->SETNcount(ncount, vid);
	tmp->lended = 1;
	tmp->debtor_name = vid;
	printf("정상적으로 처리되었습니다..\n");
	person->showCustomerInfo(vHead, cHead);
}
void Video::restoreVideo(Customer **cHead,Video** vHead)
{
	Customer* person = NULL;
	Video* vid = NULL;
	char ch;
	int i = 0;
	int id = 0;

	//회원목록 출력
	person->listCustomer(cHead);
	printf("비디오를 반납할 회원 번호를 입력해주세요.\n>>");
	cin >> id;
	
	if (id != -1) 
	{
		person = person->findCustomer(cHead, id);
		if (!person) {
			printf("존재하지 않는 회원입니다.\n");
			return;
		}

	}
	else {
		printf("존재하지 않는 회원입니다.\n");
		return;
	}

	printf("비디오를 모두 반납하십니까? (y/n) \n>>");
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
		printf("정상적으로 처리되었습니다..\n");
	}
}
void Video::removeAllVideo(Video **vHead)
{
	Video* tmp;
	Video* next;
	tmp = *vHead;
	while (tmp != NULL) {
		next = tmp->next;
		//찾은노드의 메모리를 해제
		free(tmp);
		tmp = next;
	}
}
/***************************************/