#if 0
#include<stdio.h>
#include<Windows.h>
//1.R-B Tree 를 만들기 시작합니다.
typedef struct rb_node
{
	struct rb_node* parent;
	struct rb_node* rb_right;
	struct rb_node* rb_left;
	int color;
	int data;
}RB_NODE;
RB_NODE* root = 0;
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

void insert_data(int data)
{
	RB_NODE* temp;
	RB_NODE** p = &root;
	RB_NODE* parent = NULL;
	temp = (RB_NODE*)malloc(sizeof(RB_NODE));
	temp->data = data;
	temp->rb_left = temp->rb_right = 0;

	while (*p)
	{
		if ((*p)->data > data)
			p = &(*p)->rb_left;
		else if ((*p)->data < data)
			p = &(*p)->rb_right;
		else
			return;
	}
	temp->parent = parent;
	*p = temp;
}
typedef struct _arg {
	RB_NODE* temp;
	int(*a)[10];
	int* row;
	int* col;
}ARG;
/*
void __display(RB_NODE* temp, int (*a)[10], int* row, int* col)
{
	if (temp == 0)
		return;
	++* row;
	__display(temp->rb_left, a, row, col);
	a[*row][(*col)++] = temp->data;
	__display(temp->rb_right, a, row, col);
	(*row)--;
}
*/
void __display(ARG arg)
{
	if (arg.temp == 0)
		return;
	++(*(arg.row));
	__display(arg);
	arg.a[*(arg.row)][*(arg.col)++] = (arg.temp)->data;
	__display(arg);
	(*(arg.row))--;
}

void display(RB_NODE* temp)
{
	int i, j;
	ARG arg = { temp, };
	arg = (ARG
		)malloc(sizeof(ARG));
	*(arg.row) = -1;
	*(arg.col) = 0;

	printf("%d %d %d ", arg.a[0][0], *(arg.col), *(arg.row));
	Sleep(1000);
	system("cls");
	__display(arg);

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (arg.a[i][j] != 0)
				printf("%4d", arg.a[i][j]);
			else
				printf("%4c", ' ');
		}
	}
	getchar();
}
int main()
{
	int a[] = { 4,2,1,3,6,5,7 };
	int i;

	for (i = 0; i < SIZE(a); i++)
	{
		insert_data(a[i]);
		display(root);
	}
	return 0;
}
#endif