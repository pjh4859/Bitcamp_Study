#pragma once
#include <iostream>
#include <string>
#include "Customer.h"
class Customer;
using namespace std;
class Video {
	//char* name;  //����
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
//int id;      //�Ϸù�ȣ
//int lended;  //�뿩���� 1=�뿩��, 0=�뿩�ʵ�
//char* debtor_name;//�뿩�� ��
//struct video* next; //��ũ (�̿��� video�� �ּҸ� ������)
