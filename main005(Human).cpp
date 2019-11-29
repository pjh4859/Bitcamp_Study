#include"Human.h"
#include"ComputerEngineer.h"
#include"Programmer.h"
#include"ServerManager.h"
#include<iostream>

using namespace std;

void main()
{
	Human human(30, (char*)"장길상");
	ComputerEngineer comEng(32,(char*)"임걱정", 3);
	Programmer prog(24, (char*)"홍길동", 2, 10);
	ServerManager serv(36, (char*)"일지매", 3, 28);
	Human* p = &human;
	p->Play();
	p = &comEng;
	//((ComputerEngineer*)p)->Play();
	p->Play();
	p = &prog;
	//((Programmer*)p)->Play();
	p->Play();
	p = &serv;
	//((ServerManager*)p)->Play();
	p->Play();

	//comEng.Info();
	//prog.Overtime();
	//prog.Info();
	//serv.Info();
}