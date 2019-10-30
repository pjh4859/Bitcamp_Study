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
void show_menu(); //메뉴 출력
void get_mem();
void free_mem();
void input_info(); //정보 입력
void show_info();
void del_info(); // 정보 삭제
void start_function(); //프로그램 시작
int set_number();
int get_number();
/* Function*/