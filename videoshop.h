#pragma once
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cctype>

#include<conio.h>
#pragma warning(disable:4996)
#define TRUE 1
#define FALSE 0

using namespace std;

class Customer
{
private:
	char* name;
	char* addr;
	int id;
	Customer* next;
public:
	Customer() :next(nullptr) {};
	~Customer() {};
	int lendlist[50];
	int ncount;	
public:
	void registerCustomer();
	void listCustomer();
	Customer* findCustomer(int id);
	void showCustomerInfo(Customer* person);
	void removeCustomer(int id);
	void removeAllCustomer();
};

class Video
{
private:
	char* name;
	int id;
	Video* next;
	char* debtor_name;
	int lended;
public:
	Video() :next(nullptr) {};
	~Video() {};
	Video* registerVideo();
	void removeVideo(int id);
	void listVideo();

	Video* findVideo(int id);
	void lendVideo(int vid);
	void restoreVideo();
	void removeAllVideo();
};
//Customer* cHead;
//Video* vHead;

