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

		switch (ch) {
		case '1':
			vHead->registerVideo();
			break;

		case '2':
			printf("삭제할 비디오 일련번호를 입력하세요.\n>>");

			fgets(buf, 20, stdin);
			//개행문자를 널문자로 대체함
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//입력버퍼에 남아있는 데이터를 비웁니다.
			fflush(stdin);
			//입력된문자열을 숫자로 변환
			id = vHead->number(buf);
			if (id != -1)
				vHead->removeVideo(id);
			break;

		case '3':
			vHead->listVideo();
			break;

		case '4':
			vHead->listVideo();
			printf("대여할 비디오 일련번호를 입력하세요.\n>>");

			fgets(buf, 20, stdin);
			//개행문자를 널문자로 대체함
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//입력버퍼에 남아있는 데이터를 비웁니다.
			fflush(stdin);
			//입력된문자열을 숫자로 변환
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
			printf("검색할 회원 번호를 입력해주세요.\n>>");
			fgets(buf, 20, stdin);
			//개행문자를 널문자로 대체함
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//입력버퍼에 남아있는 데이터를 비웁니다.
			fflush(stdin);
			//입력된문자열을 숫자로 변환
			id = vHead->number(buf);
			if (id != -1) {
				person = person->findCustomer(id);
				if (person)
					person->showCustomerInfo(person);
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
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//입력버퍼에 남아있는 데이터를 비웁니다.
			fflush(stdin);
			//입력된문자열을 숫자로 변환
			id = vHead->number(buf);
			if (id != -1)
				person->removeCustomer(id);
			break;

		default:
			continue;
		}
		printf("엔터키를 눌러주세요.\n");
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

		switch (ch) {
		case '1':
			vide->registerVideo();
			break;

		case '2':
			printf("삭제할 비디오 일련번호를 입력하세요.\n>>");

			fgets(buf, 20, stdin);
			//개행문자를 널문자로 대체함
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//입력버퍼에 남아있는 데이터를 비웁니다.
			fflush(stdin);
			//입력된문자열을 숫자로 변환
			id = number(buf);
			if (id != -1)
				vide->removeVideo(id);
			break;

		case '3':
			vide->listVideo();
			break;

		case '4':
			vide->listVideo();
			printf("대여할 비디오 일련번호를 입력하세요.\n>>");

			fgets(buf, 20, stdin);
			//개행문자를 널문자로 대체함
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//입력버퍼에 남아있는 데이터를 비웁니다.
			fflush(stdin);
			//입력된문자열을 숫자로 변환
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
			printf("검색할 회원 번호를 입력해주세요.\n>>");
			fgets(buf, 20, stdin);
			//개행문자를 널문자로 대체함
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//입력버퍼에 남아있는 데이터를 비웁니다.
			fflush(stdin);
			//입력된문자열을 숫자로 변환
			id = number(buf);
			if (id != -1) {
				person = person->findCustomer(id);
				if (person)
					person->showCustomerInfo(person);
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
			if (*(buf + (strlen(buf) - 1)) == '\n')
				*(buf + (strlen(buf) - 1)) = '\0';
			//입력버퍼에 남아있는 데이터를 비웁니다.
			fflush(stdin);
			//입력된문자열을 숫자로 변환
			id = number(buf);
			if (id != -1)
				person->removeCustomer(id);
			break;

		default:
			continue;
		}
		printf("엔터키를 눌러주세요.\n");
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