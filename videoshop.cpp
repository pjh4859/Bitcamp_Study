#if 1
#include"videoshop.h"
//비디오를 등록
Video* vHead;
Customer* cHead;
int Video::number(char* buf)
{
	int i = 0;
	int id = 0;
	while (buf[i]) //buf 가 0이 나올 때까지 돈다
	{
		if (!(buf[i] >= '0' && buf[i] <= '9'))//buf[i]가 0~9 가 아니면 break
			break;
		i++;
	}
	if (i > 0 && (i == strlen(buf)))
	{
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

	//맨마지막에 입력된 id 찾기
	if (vHead != NULL) {
		tmp = vHead;
		id = tmp->id + 1;
		while (tmp->next != NULL) {
			tmp = tmp->next;
			id = tmp->id + 1;
		}
	}
	val = new Video;
	val->id = id;
	val->lended = 0;
	val->debtor_name = new char[50];
	strcpy(val->debtor_name, "");
	val->next = NULL;

	printf("비디오 제목을 입력해주세요 \n>>");
	val->name = new char[50];
	do {
		fgets(val->name, 20, stdin);

		//개행문자를 널문자로 대체함
		if (*(val->name + (strlen(val->name) - 1)) == '\n')
			*(val->name + (strlen(val->name) - 1)) = '\0';
		if (strcmp(val->name, ""))
			break;
	} while (TRUE);

	if (vHead == NULL) {
		vHead = val;
		cout << "registerVideo2" << endl;
		return val;
	}
	else {
		tmp = vHead;
		//리스트에서 맨마지막 노드를 찾는다
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = val;
	}
	cout << "registerVideo3" << endl;
	return val;
}
//비디오 목록을 출력합니다
void Video::listVideo() 
{
	Video* tmp = NULL;
	Video* val = NULL;
	char str[100];
	tmp = vHead;
	//아무런 내용도 없으면 바로 리턴
	if (tmp == NULL)
		return;

	printf("번호, 비디오명, 대출자, 대출유무\n");
	while (tmp != NULL) {
		char buf[20];
		if (tmp->lended) {
			strcpy(buf, " 대출불가");
		}
		else {
			strcpy(buf, " 대출가능");
		}
		sprintf(str, "%d> %s, %s, %s", tmp->id, tmp->name, tmp->debtor_name, buf);

		printf("%s\n", str);
		tmp = tmp->next;
	}
	cout << "listVideo" << endl;
}
//비디오를 검색합니다.(일련번호로..)
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
	cout << "findVideo" << endl;
	return 0;
}
// 비디오를 삭제합니다
void Video::removeVideo(int id) 
{
	Video* tmp;
	Video* prv;
	tmp = prv = vHead;
	//데이터가 일치하는 노드를 찾거나, 노드의 끝에 도달하면 while문을 벗어남
	while (tmp != NULL && (tmp->id != id)) {
		prv = tmp;
		tmp = tmp->next;
	}

	//원하는 노드를 찾았는지 체크
	if (tmp != NULL) {
		//찾은 노드가 head라면, head에 head의 다음값(tmp)을 가리키게 함
		if (tmp == prv)
			vHead = tmp->next;
		//prv의 다음항목이 tmp의 다음항목이 되도록함
		else
			prv->next = tmp->next;

		//찾은노드의 메모리를 해제
		free(tmp->name);
		free(tmp->debtor_name);
		free(tmp);
		printf("삭제하였습니다.\n");
		return;
	}
	printf("입력한 비디오는 존재하지 않습니다.\n");
	cout << "removeVideo" << endl;
}
// 비디오를 모두 삭제합니다
Video::~Video() 
{
	cout << "~video" << endl;
	Video* tmp;
	Video* next;
	tmp = vHead;
	while (tmp != NULL)
	{
		next = tmp->next;
		delete(tmp->name);
		delete(tmp->debtor_name);
		delete(tmp);

		tmp = next;
	}
	cout << "removeAllVideo" << endl;
}
// 비디오를 대여합니다.
void Video::lendVideo(int vid) 
{
	char buf[100];
	Customer* person = NULL;
	
	int id = 0;
	//비디오 검색
	Video* tmp = findVideo(vid);
	if (tmp == NULL) {
		printf("입력한 비디오는 존재하지 않습니다.\n");
		return;
	}
	//대여가능여부 체크
	if (tmp->lended) {
		printf("현재 대여중이라 대여 불가능 합니다..\n");
		return;
	}
	printf("비디오를 대여하시는 회원번호를 입력해주세요 \n");

	fgets(buf, 100, stdin);
	//개행문자를 널문자로 대체함
	if (*(buf + (strlen(buf) - 1)) == '\n')
		*(buf + (strlen(buf) - 1)) = '\0';

	//입력된문자열을 숫자로 변환
	id = number(buf);
	if (id != -1) {
		//회원검색		
		person = cHead->findCustomer(id);
		if (person)
			cHead->showCustomerInfo(person);
		if (!person) {
			printf("존재하지 않는 회원입니다.\n");
			return;
		}
		else if (person->ncount >= 20) {
			printf("대여할수 있는 비디오의 개수를 초과했습니다.\n");
			return;
		}
	}
	else {
		printf("존재하지 않는 회원입니다.\n");
		return;
	}

	//대여정보등록
	person->lendlist[person->ncount++] = vid;
	tmp->lended = TRUE;
	strcpy(tmp->debtor_name, buf);
	printf("정상적으로 처리되었습니다..\n");
	cout << "lendVideo" << endl;
}
//비디오를 반납합니다.
void Video::restoreVideo()
{
	char buf[20];
	Customer* person = NULL;
	Video* vid = NULL;
	char ch;
	int i = 0;
	int id = 0;

	//회원목록 출력
	cHead->listCustomer();
	printf("비디오를 반납할 회원 번호를 입력해주세요.\n>>");
	fgets(buf, 20, stdin);
	//개행문자를 널문자로 대체함
	if (*(buf + (strlen(buf) - 1)) == '\n')
		*(buf + (strlen(buf) - 1)) = '\0';

	//입력된문자열을 숫자로 변환
	id = number(buf);
	if (id != -1) {
		//회원검색		
		person = cHead->findCustomer(id);
		if (person)
			cHead->showCustomerInfo(person);
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
	if (ch == 'y' || ch == 'Y') {
		for (i = 0; i < person->ncount; i++) {
			vid = findVideo(person->lendlist[i]);
			if (vid != NULL) {
				vid->lended = FALSE;
				strcpy(vid->debtor_name, "");
			}
		}
		person->ncount = 0;
		printf("정상적으로 처리되었습니다..\n");
	}
	//입력버퍼에 남아있는 데이터를 비웁니다.
	fflush(stdin);
	cout << "restoreVideo" << endl;
}
// 신규 회원을 등록합니다.
void Customer::registerCustomer()
{
	int id = 1;
	Customer* tmp = NULL;
	Customer* val = NULL;

	//맨마지막에 입력된 id 찾기
	if (cHead != NULL) {
		tmp = cHead;
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
	val->name = new char[20];
	fgets(val->name, 20, stdin);
	//개행문자를 널문자로 대체함
	if (*(val->name + (strlen(val->name) - 1)) == '\n')
		*(val->name + (strlen(val->name) - 1)) = '\0';

	printf("주소를 입력해주세요 \n");
	val->addr = new char[20];
	fgets(val->addr, 20, stdin);
	//개행문자를 널문자로 대체함
	if (*(val->addr + (strlen(val->addr) - 1)) == '\n')
		*(val->addr + (strlen(val->addr) - 1)) = '\0';

	if (cHead == NULL) {
		cHead = val;
		return;
	}
	else {
		tmp = cHead;
		//리스트에서 맨마지막 노드를 찾는다
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = val;
	}
	cout << "registerCustomer" << endl;
}
//회원 목록을 출력합니다
void Customer::listCustomer() 
{
	Customer* tmp = NULL;
	Customer* val = NULL;
	char str[100];
	tmp = cHead;
	if (tmp == NULL)
		return;
	//아무런 내용도 없으면 바로 리턴
	printf("번호,이름,주소,대출비디오개수\n");
	while (tmp != NULL) {
		sprintf(str, "%d> %s, %s, %d", tmp->id, tmp->name, tmp->addr, tmp->ncount);
		printf("%s\n", str);
		tmp = tmp->next;
	}
	cout << "listCustomer" << endl;
}
//회원을 검색합니다.(이름으로 검색..)
Customer* Customer::findCustomer(int id)
{
	Customer* tmp = NULL;
	tmp = cHead;

	while (tmp != NULL) {
		if (tmp->id == id)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
	cout << "fineCustomer" << endl;
	return 0;
}
//해당 회원의 정보를 화면에 출력합니다.
void Customer::showCustomerInfo(Customer* person) 
{
	Video* tmp = NULL;
	Video* val = NULL;
	int i = 0;

	printf("이름:%s, 주소:%s\n", person->name, person->addr);
	if (vHead == NULL || person->ncount < 1)
		return;

	tmp = vHead;
	printf("-- 대출한 비디오 목록 --\n");
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
	cout << "showCustomerInfo" << endl;
}
//회원을 삭제합니다.
void Customer::removeCustomer(int id)
{
	Customer* tmp;
	Customer* prv;
	Video* vid;
	int i = 0;

	tmp = prv = cHead;
	//데이터가 일치하는 노드를 찾거나, 노드의 끝에 도달하면 while문을 벗어남
	while (tmp != NULL && (tmp->id != id)) {
		prv = tmp;
		tmp = tmp->next;
	}

	//원하는 노드를 찾았는지 체크
	if (tmp != NULL) {
		//찾은 노드가 head라면, head에 head의 다음값(tmp)을 가리키게 함
		if (tmp == prv)
			cHead = tmp->next;
		//prv의 다음항목이 tmp의 다음항목이 되도록함
		else
			prv->next = tmp->next;

		//가지고 있는 비디오의 대여정보를 초기화
		for (i = 0; i < tmp->ncount; i++) {
			vid = vHead->findVideo(tmp->lendlist[i]);
			if (vid != NULL) {
				vid->lended = FALSE;
				strcpy(vid->debtor_name, "");
			}
		}

		//찾은노드의 메모리를 해제
		free(tmp->name);
		free(tmp->addr);
		free(tmp);
		printf("삭제하였습니다.\n");
		return;
	}
	printf("입력한 회원번호 존재하지 않습니다.\n");
	cout << "removeCustomer" << endl;
}
// 회원를 모두 삭제합니다
Customer::~Customer() 
{
	cout << "~Customer" << endl;
	Customer* tmp;
	Customer* next;
	tmp = cHead;
	//데이터가 일치하는 노드를 찾거나, 노드의 끝에 도달하면 while문을 벗어남
	while (tmp != NULL) {
		next = tmp->next;
		//찾은노드의 메모리를 해제
		delete(tmp->name);
		delete(tmp->addr);
		delete(tmp);

		tmp = next;
	}
	cout << "removeAllCustomer" << endl;
}
#endif