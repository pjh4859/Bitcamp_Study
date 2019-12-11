#pragma once
#include <iostream>
#include <string>
#include "Customer.h"
class Customer;
using namespace std;
class Video {
	//char* name;  //제목
private:
	string name;
	string debtor_name;
	Video* next;
private:
	int id;
	int lended;
public:
	Video* registerVideo(Video** vHead);
	Video* findVideo(Video** vHead, int id);
	Video* _findVideo(Video** vHead, int **id);
	Video* lendVideo(Customer** cHead, Video** vHead, int vid);
	Video* GETNEXT();
public:
	void listVideo(Video** vHead);
	void removeVideo(Video** vHead, int id);
	void restoreVideo(Customer** cHead, Video** vHead);
	void removeAllVideo(Video** vHead);
	int GETID();
	int SETlended(int TorF);
public:               
	void SETdebtorName();
	string GETNAME();


};


//
//int id;      //일련번호
//int lended;  //대여유무 1=대여됨, 0=대여않됨
//char* debtor_name;//대여한 고객
//struct video* next; //링크 (이웃한 video의 주소를 저장함)
