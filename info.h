#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define MAX_NAME 10
#define MAX_PHONE 20
#define MAX_ADDR 30

/* Variable */

typedef struct
{
	char* name;
	char* phone;
	char* addr;
}info;

info* in[3];
int number;

/* Variable */



/* Function*/
void show_menu(); //�޴� ���
void get_mem();
void free_mem();
void input_info(); //���� �Է�
void show_info();
void del_info(); // ���� ����
void start_function(); //���α׷� ����
int set_number();
int get_number();
/* Function*/