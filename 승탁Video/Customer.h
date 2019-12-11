#pragma once
#include <iostream>
#include <string>
#include "Video.h"
using namespace std;
class Video;
class Customer 
{
private:
	string name;       //�̸�
	Customer* next; //��ũ (�̿��� customer�� �ּҸ� ������)
	string addr;       //�ּ�
private:
	int id;           //�Ϸù�ȣ 
	int lendlist[50]; //�뿩�� ��������Ʈ
	int ncount;       //�뿩�� ���� ����
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
//char* name;       //�̸�
//int id;           //�Ϸù�ȣ 
//char* addr;       //�ּ�
//int lendlist[50]; //�뿩�� ��������Ʈ
//int ncount;       //�뿩�� ���� ����
//struct customer* next; //��ũ (�̿��� customer�� �ּҸ� ������)