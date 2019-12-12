#pragma once
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<Windows.h>

#include<conio.h>
#pragma warning(disable:4996)
#define TRUE 1
#define FALSE 0

using namespace std;

class Customer
{
private:
public:
	char* addr;
	Customer* next;
	char* name;
	int id;
	Customer() :next(nullptr) {};
	~Customer() ;
	int lendlist[50];
	int ncount;	
public:
	void registerCustomer();
	void listCustomer();
	Customer* findCustomer(int id);
	void showCustomerInfo(Customer* person);
	void removeCustomer(int id);
	//void removeAllCustomer();
	friend int number(char* buf);
};

class Video
{
private:
public:
	char* name;
	char* debtor_name;
	int id;
	int lended;
	Video* next;
	Video() :next(nullptr) {};
	~Video() ;
	Video* registerVideo();
	void removeVideo(int id);
	void listVideo();
	int number(char* buf);

	Video* findVideo(int id);
	void lendVideo(int vid);
	void restoreVideo();
	//void removeAllVideo();
};


