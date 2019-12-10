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
	char* name;       //이름
	int id;           //일련번호 
	char* addr;       //주소
	int lendlist[50]; //대여한 비디오리스트
	int ncount;       //대여한 비디오 개수
	struct customer* next; //링크 (이웃한 customer의 주소를 저장함)
};


struct video {
	char* name;  //제목
	int id;      //일련번호
	int lended;  //대여유무 1=대여됨, 0=대여않됨
	char* debtor_name;//대여한 고객
	struct video* next; //링크 (이웃한 video의 주소를 저장함)
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

//실행메뉴를 출력합니다.
void showMenu() {
	char ch;
	int id;
	char buf[20];
	CUSTOMER* person = NULL;
	int i=0;

	do {
		printf("---------------------\n");
		printf("1: 비디오 등록 \n");
		printf("2: 비디오 삭제 \n");
		printf("3: 비디오 목록 \n");
		printf("4: 비디오 대여 \n");
		printf("5: 비디오 반납 \n");

		printf("6: 신규회원 등록 \n");
		printf("7: 회원목록 출력 \n");
		printf("8: 회원정보 출력 \n");
		printf("9: 회원삭제 \n");

		printf("(Q/q): 프로그램 종료 \n");
		printf("---------------------\n>>");

		ch = getchar();
		getchar();
		//fflush(stdin);

		switch(ch) {
			case '1':
				registerVideo();
				break;

			case '2':
				printf("삭제할 비디오 일련번호를 입력하세요.\n>>");

				fgets(buf, 20, stdin);
				//개행문자를 널문자로 대체함
				if(*(buf + (strlen(buf) - 1)) == '\n')
					*(buf + (strlen(buf) - 1)) = '\0';
				//입력버퍼에 남아있는 데이터를 비웁니다.
				fflush(stdin);
				//입력된문자열을 숫자로 변환
				id = number(buf);
				if(id != -1)
					removeVideo(id);
				break;

			case '3':
				listVideo();
				break;

			case '4':
				listVideo();
				printf("대여할 비디오 일련번호를 입력하세요.\n>>");

				fgets(buf, 20, stdin);
				//개행문자를 널문자로 대체함
				if(*(buf + (strlen(buf) - 1)) == '\n')
					*(buf + (strlen(buf) - 1)) = '\0';
				//입력버퍼에 남아있는 데이터를 비웁니다.
				fflush(stdin);
				//입력된문자열을 숫자로 변환
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
				printf("검색할 회원 번호를 입력해주세요.\n>>");
				fgets(buf, 20, stdin);
				//개행문자를 널문자로 대체함
				if(*(buf + (strlen(buf) - 1)) == '\n')
					*(buf + (strlen(buf) - 1)) = '\0';
				//입력버퍼에 남아있는 데이터를 비웁니다.
				fflush(stdin);
				//입력된문자열을 숫자로 변환
				id = number(buf);
				if(id != -1) {
					person = findCustomer(id);
					if(person)
						showCustomerInfo(person);
					else
						printf("존재하지 않는 회원입니다.\n");
				}
				else
					printf("존재하지 않는 회원입니다.\n");

				break;
			case '9':
				printf("삭제할 회원 일련번호를 입력하세요.\n>>");

				fgets(buf, 20, stdin);
				//개행문자를 널문자로 대체함
				if(*(buf + (strlen(buf) - 1)) == '\n')
					*(buf + (strlen(buf) - 1)) = '\0';
				//입력버퍼에 남아있는 데이터를 비웁니다.
				fflush(stdin);
				//입력된문자열을 숫자로 변환
				id = number(buf);
				if(id != -1)
					removeCustomer(id);
				break;

			default:
				continue;
		}
		printf("엔터키를 눌러주세요.\n");
		getch();

	}while(ch != 'q' && ch != 'Q');

	printf("Good Bye!!\n");
}


//비디오를 등록
VIDEO* registerVideo()
{
	int id = 1;
	VIDEO* tmp = NULL;
	VIDEO* val = NULL;

	//맨마지막에 입력된 id 찾기
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

	printf("비디오 제목을 입력해주세요 \n>>");
	val->name = (char*) malloc(sizeof(char)*50);
	do {
		fgets(val->name, 20, stdin);

		//개행문자를 널문자로 대체함
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
		//리스트에서 맨마지막 노드를 찾는다
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = val;
	}
	return val;
}

//비디오 목록을 출력합니다
void listVideo() {
	VIDEO* tmp = NULL;
	VIDEO* val = NULL;
	char str[100];
	tmp = vHead;
	//아무런 내용도 없으면 바로 리턴
	if(tmp == NULL)
		return;

	printf("번호, 비디오명, 대출자, 대출유무\n");
	while(tmp != NULL) {
		char buf[20];
		if(tmp->lended) {
			strcpy(buf, " 대출불가");
		}
		else  {
			strcpy(buf, " 대출가능");
		}
		sprintf(str, "%d> %s, %s, %s", tmp->id, tmp->name, tmp->debtor_name, buf);

		printf("%s\n", str);
		tmp = tmp->next;
	}
}

//비디오를 검색합니다.(일련번호로..)
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

// 비디오를 삭제합니다
void removeVideo(int id) {
	VIDEO* tmp;
	VIDEO* prv; 
	tmp = prv = vHead;
	//데이터가 일치하는 노드를 찾거나, 노드의 끝에 도달하면 while문을 벗어남
	while(tmp != NULL && (tmp->id != id)){
		prv = tmp;
		tmp = tmp->next;
	}

	//원하는 노드를 찾았는지 체크
	if(tmp != NULL) {
		//찾은 노드가 head라면, head에 head의 다음값(tmp)을 가리키게 함
		if(tmp == prv)
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
}

// 비디오를 모두 삭제합니다
void removeAllVideo() {
	VIDEO* tmp;
	VIDEO* next;
	tmp = vHead;
	//데이터가 일치하는 노드를 찾거나, 노드의 끝에 도달하면 while문을 벗어남
	while(tmp != NULL){
		next = tmp->next;
		//찾은노드의 메모리를 해제
		free(tmp->name);
		free(tmp->debtor_name);
		free(tmp);

		tmp = next;
	}
}

// 비디오를 대여합니다.
void lendVideo(int vid) {
	char buf[100];
	CUSTOMER* person = NULL;
	int id = 0;
	//비디오 검색
	VIDEO* tmp = findVideo(vid);
	if(tmp == NULL) {
		printf("입력한 비디오는 존재하지 않습니다.\n");
		return;
	}
	//대여가능여부 체크
	if(tmp->lended) {
		printf("현재 대여중이라 대여 불가능 합니다..\n");
		return;
	}
	printf("비디오를 대여하시는 회원번호를 입력해주세요 \n");

	fgets(buf, 100, stdin);
	//개행문자를 널문자로 대체함
	if(*(buf + (strlen(buf) - 1)) == '\n')
		*(buf + (strlen(buf) - 1)) = '\0';
	
	//입력된문자열을 숫자로 변환
	id = number(buf);
	if(id != -1) {
		//회원검색		
		person = findCustomer(id);
		if(person)
			showCustomerInfo(person);
		if(!person) {
			printf("존재하지 않는 회원입니다.\n");
			return;
		}
		else if(person->ncount >= 20) {
			printf("대여할수 있는 비디오의 개수를 초과했습니다.\n");
			return;
		}
	}
	else  {
		printf("존재하지 않는 회원입니다.\n");
		return;
	}

	//대여정보등록
	person->lendlist[person->ncount++] = vid;
	tmp->lended = TRUE;
	strcpy(tmp->debtor_name, buf);
	printf("정상적으로 처리되었습니다..\n");
}

//비디오를 반납합니다.
void restoreVideo()
{
	char buf[20];
	CUSTOMER* person = NULL;
	VIDEO* vid = NULL;
	char ch;
	int i = 0;
	int id = 0;

	//회원목록 출력
	listCustomer();
	printf("비디오를 반납할 회원 번호를 입력해주세요.\n>>");
	fgets(buf, 20, stdin);
	//개행문자를 널문자로 대체함
	if(*(buf + (strlen(buf) - 1)) == '\n')
		*(buf + (strlen(buf) - 1)) = '\0'; 

	//입력된문자열을 숫자로 변환
	id = number(buf);
	if(id != -1) {
		//회원검색		
		person = findCustomer(id);
		if(person)
			showCustomerInfo(person);
		if(!person) {
			printf("존재하지 않는 회원입니다.\n");
			return;
		}
	
	}
	else  {
		printf("존재하지 않는 회원입니다.\n");
		return;
	}

	printf("비디오를 모두 반납하십니까? (y/n) \n>>");
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
		printf("정상적으로 처리되었습니다..\n");
	}
	//입력버퍼에 남아있는 데이터를 비웁니다.
	fflush(stdin);
}

// 신규 회원을 등록합니다.
void registerCustomer()
{
	int id = 1;
	CUSTOMER* tmp = NULL;
	CUSTOMER* val = NULL;

	//맨마지막에 입력된 id 찾기
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

	printf("이름을 입력해주세요 \n>>");
	val->name = (char*) malloc(sizeof(char)*20);
	fgets(val->name, 20, stdin);
	//개행문자를 널문자로 대체함
	if(*(val->name + (strlen(val->name) - 1)) == '\n')
		*(val->name + (strlen(val->name) - 1)) = '\0';  

	printf("주소를 입력해주세요 \n");
	val->addr = (char*) malloc(sizeof(char)*20);
	fgets(val->addr, 20, stdin);
	//개행문자를 널문자로 대체함
	if(*(val->addr + (strlen(val->addr) - 1)) == '\n')
		*(val->addr + (strlen(val->addr) - 1)) = '\0';  

	if(cHead == NULL) {
		cHead = val;
		return;
	}
	else {
		tmp = cHead;
		//리스트에서 맨마지막 노드를 찾는다
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = val;
	}
}

//회원 목록을 출력합니다
void listCustomer() {
	CUSTOMER* tmp = NULL;
	CUSTOMER* val = NULL;
	char str[100];
	tmp = cHead;
	if(tmp == NULL)
		return;
	//아무런 내용도 없으면 바로 리턴
	printf("번호,이름,주소,대출비디오개수\n");
	while(tmp != NULL) {
		sprintf(str, "%d> %s, %s, %d", tmp->id, tmp->name, tmp->addr, tmp->ncount);
		printf("%s\n", str);
		tmp = tmp->next;
	}
}

//회원을 검색합니다.(이름으로 검색..)
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

//해당 회원의 정보를 화면에 출력합니다.
void showCustomerInfo(CUSTOMER* person) {
	VIDEO* tmp = NULL;
	VIDEO* val = NULL;
	int i=0;

	printf("이름:%s, 주소:%s\n", person->name, person->addr);
	if(vHead == NULL || person->ncount < 1)
		return;

	tmp = vHead;
	printf("-- 대출한 비디오 목록 --\n");
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

// 회원를 모두 삭제합니다
void removeAllCustomer() {
	CUSTOMER* tmp;
	CUSTOMER* next;
	tmp = cHead;
	//데이터가 일치하는 노드를 찾거나, 노드의 끝에 도달하면 while문을 벗어남
	while(tmp != NULL){
		next = tmp->next;
		//찾은노드의 메모리를 해제
		free(tmp->name);
		free(tmp->addr);
		free(tmp);

		tmp = next;
	}
}

//문자열을 int 타입으로 변환합니다.
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

//회원을 삭제합니다.
void removeCustomer(int id)
{
	CUSTOMER* tmp;
	CUSTOMER* prv; 
	VIDEO* vid;
	int i = 0;

	tmp = prv = cHead;
	//데이터가 일치하는 노드를 찾거나, 노드의 끝에 도달하면 while문을 벗어남
	while(tmp != NULL && (tmp->id != id)){
		prv = tmp;
		tmp = tmp->next;
	}

	//원하는 노드를 찾았는지 체크
	if(tmp != NULL) {
		//찾은 노드가 head라면, head에 head의 다음값(tmp)을 가리키게 함
		if(tmp == prv)
			cHead = tmp->next;
		//prv의 다음항목이 tmp의 다음항목이 되도록함
		else
			prv->next = tmp->next;

		//가지고 있는 비디오의 대여정보를 초기화
		for(i=0; i<tmp->ncount; i++) {
			vid =findVideo(tmp->lendlist[i]);
			if(vid != NULL) {
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
}
#endif
