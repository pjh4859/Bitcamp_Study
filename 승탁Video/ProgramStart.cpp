
#include "ProgramStart.h"
#define NULL 0
ProgramStart::ProgramStart(){}
void ProgramStart::ProgramStartFunction()
{
	SelectMenu();
}
void ProgramStart::ShowMenu()
{
	cout<<"---------------------\n";
	cout << "1: 비디오 등록 \n";
	cout << "2: 비디오 삭제 \n";
	cout << "3: 비디오 목록 \n";
	cout << "4: 비디오 대여 \n";
	cout << "5: 비디오 반납 \n";

	cout << "6: 신규회원 등록 \n";
	cout << "7: 회원목록 출력 \n";
	cout << "8: 회원정보 출력 \n";
	cout << "9: 회원삭제 \n";

	cout << "(0/-1): 프로그램 종료 \n";
	cout << "---------------------\n>>";
}
void ProgramStart::SelectMenu()
{
	ProgramStart start;
	Customer* cHead = NULL;;
	Video* vHead = NULL;;
	Customer* person = NULL;

	do{
		system("cls");
		ShowMenu();
		cin >> ch;
		switch (ch) 
		{
		case 1:
			start.vHead->registerVideo(&vHead);
			id = getchar();
			break;

		case 2:
			cout<<"삭제할 비디오 일련번호를 입력하세요.\n>>";
			int id;
			cin >> id;
			if (id != -1)
				start.vHead->removeVideo(&vHead,id);
			id = getchar();
			break;
			
		case 3:
			start.vHead->listVideo(&vHead);
			id = getchar();
			break;

		case 4:
			start.vHead->listVideo(&vHead);
			cout << "대여할 비디오 번호를 입력하세요";
			cin >> id;
			if (id != -1)
				start.vHead->lendVideo(&cHead,&vHead,id);
			id = getchar();
			break;

		case 5:
			start.vHead->restoreVideo(&cHead,&vHead);
			id = getchar();
			break;

		case 6:
			start.cHead->registerCustomer(&cHead);
			break;

		case 7:
			start.cHead->listCustomer(&cHead);
			id = getchar();
			break;

		case 8:
			start.cHead->listCustomer(&cHead);
			cout<<"검색할 회원 번호를 입력해주세요.\n>>";
			cin >> id;
			if (id != -1) {
				person = start.cHead->findCustomer(&cHead,id);
				if (person)
					start.cHead->showCustomerInfo(&vHead,&person);
				else
					cout<<"존재하지 않는 회원입니다.\n";
			}
			else
				printf("존재하지 않는 회원입니다.\n");
			cout << "메뉴로 돌아가려면 엔터키를 입력해주세요\n";
			id = getchar();
			break;
		case 9:
			printf("삭제할 회원 일련번호를 입력하세요.\n>>");
			cin >> ch;
			if (ch != -1)
				start.cHead->removeCustomer(&vHead,&cHead,ch);
			id = getchar();
			break;
		default:
			continue;
		}
		cout<<"엔터키를 눌러주세요.\n";
		id = getchar();

	}while (ch != 0 && ch != -1);

printf("Good Bye!!\n");
}

int ProgramStart::number(char* buf) 
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