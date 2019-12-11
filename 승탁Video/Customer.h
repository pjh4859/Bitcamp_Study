#pragma once
#include <iostream>
#include <string>
#include "Video.h"
using namespace std;
class Video;
class Customer 
{
private:
	string name;       //이름
	Customer* next; //링크 (이웃한 customer의 주소를 저장함)
	string addr;       //주소
private:
	int id;           //일련번호 
	int lendlist[50]; //대여한 비디오리스트
	int ncount;       //대여한 비디오 개수
	int* _lendlist;
	int debug;
public:
	Customer *findCustomer(Customer** cHead, int id);
	Customer *showCustomerInfo(Video** vHead, Customer** cHead);
public:
	void registerCustomer(Customer** cHead);
	void listCustomer(Customer** cHead);
	void removeCustomer(Video** vHead, Customer** cHead, int id);
public:
	int GETcustomerID();
	int *GETCustomerLendlist();
	int GETCustomerncount();
	void SETNcount(int _nCount,int vid);
	void OneSetncount(int n);

};
//char* name;       //이름
//int id;           //일련번호 
//char* addr;       //주소
//int lendlist[50]; //대여한 비디오리스트
//int ncount;       //대여한 비디오 개수
//struct customer* next; //링크 (이웃한 customer의 주소를 저장함)