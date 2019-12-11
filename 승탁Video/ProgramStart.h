#pragma once
#include "Customer.h"
#include "Video.h"
#include "Link.h"
#include <windows.h>
class ProgramStart
{
private:
	Link *LinkStart;
	Video *vHead;
	Customer* cHead;
	string _id;
private:
	int id;
	char buf[20];
	int ch;
private:
	void SelectMenu();
	int number(char* buf);
	void ShowMenu();
public:
	void ProgramStartFunction();
	ProgramStart();

};