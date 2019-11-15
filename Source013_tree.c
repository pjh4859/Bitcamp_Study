#if 0
#include <stdio.h>
#include <Windows.h>

typedef struct _node
{
	int data;
	struct _node* left;
	struct _node* right;
}NODE;

NODE* root;
typedef enum { LEFT, RIGHT }TYPE;
void insert_data(int data,NODE *s,TYPE type)
{
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = temp->right = 0;
	if (s == 0)
	{
		root = temp;
		return;
	}
	if (type == LEFT)
		s->left = temp;
	else if (type == RIGHT)
		s->right = temp;
}
void in_order(NODE*temp)
{
	int i;
	int ary[7][7];
	//static int indent = 3;
	static int indent = -1;
	if (temp == 0)
		return;
	//indent--;
	indent++;
	in_order(temp->right);
	//for (i = 0; i < indent;i++)
	//	printf("%4c", ' ');
	//printf("%d\n", temp->data);
	printf("%*d\n", indent * 4, temp->data);//위의 세 줄을 한줄로 바꿔봄.
	//printf("[%2d]\n", temp->data);
	in_order(temp->left);
	//indent++;
	indent--;
	//printf("[%2d]\n", temp->right);
	//system("cls");

}
int main()
{
//	NODE* root=0;
	insert_data(1,root,LEFT);
	insert_data(2,root,LEFT);
	insert_data(3,root,RIGHT);
	insert_data(4,root->left,LEFT);
	insert_data(5,root->left,RIGHT);
	insert_data(6,root->right,LEFT);
	insert_data(7,root->right,RIGHT);
	in_order(root);
	//insert_data(1,&root,LEFT);
	//insert_data(2,&root,LEFT);
	//insert_data(3,&root,RIGHT);
	//insert_data(4,&root->left,LEFT);
	//insert_data(5,&root->left,RIGHT);
	//insert_data(6,&root->right,LEFT);
	//insert_data(7,&root->right,RIGHT);//이케하면 main안에 NODE* root=0;를 넣고
	//위의 함수에서 이중포인터로 받으면 될 것인다.

	return 0;
}

#endif

#if 0
#include <stdio.h>
#include <Windows.h>

typedef struct _node
{
	int data;
	struct _node* left;
	struct _node* right;
}NODE;

//NODE* root;
typedef enum { LEFT, RIGHT }TYPE;
void insert_data(int data, NODE** s, TYPE type)
{
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = temp->right = 0;
	if (*s == 0)
	{
		*s = temp;
		return;
	}
	if (type == LEFT)
		(*s)->left = temp;
	else if (type == RIGHT)
		(*s)->right = temp;
}
void in_order(NODE* temp)
{
	int i;
	static int indent = -1;
	if (temp == 0)
		return;
	indent++;
	in_order(temp->right);
	printf("%*d\n", indent * 4, temp->data);//위의 세 줄을 한줄로 바꿔봄.
	in_order(temp->left);
	indent--;
}
int main()
{
	NODE* root=0;
	
	insert_data(1,&root,LEFT);
	insert_data(2,&root,LEFT);
	insert_data(3,&root,RIGHT);
	insert_data(4,&root->left,LEFT);
	insert_data(5,&root->left,RIGHT);
	insert_data(6,&root->right,LEFT);
	insert_data(7,&root->right,RIGHT);//이케하면 main안에 NODE* root=0;를 넣고
	in_order(root);
	//위의 함수에서 이중포인터로 받으면 될 것인다.

	return 0;
}

#endif

#if 0
#include <stdio.h>
#include <Windows.h>
#include <time.h>

typedef struct _node
{
	int data;
	struct _node* left;
	struct _node* right;
}NODE;

NODE* root;
typedef enum { LEFT, RIGHT }TYPE;
void insert_data(int data, NODE* s, TYPE type)
{
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = temp->right = 0;
	if (s == 0)
	{
		root = temp;
		return;
	}
	if (type == LEFT)
		s->left = temp;
	else if (type == RIGHT)
		s->right = temp;
}
int(* __display(NODE* temp))[10]
//리턴타입 만든데 힘들었음.앞에 원래 int[10]* 인데 [10] 뒤로 돌리고 괄호쳐서 이케댐.
{
	static int a[10][10] = { 0, };
	static int row = -1;
	static int col = 0;
	if (temp==0)
		return;
	row++;
	__display(temp->left);
	//printf("%*d\n", indent * 4, temp->data);
	a[row][col++] = temp->data;
	__display(temp->right);
	row--;

	return a;
}

void display(NODE* temp)
{
	int i = 0, j = 0;
	int(*a)[10]=__display(temp);
	system("cls");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (a[i][j] != 0)
				printf("%4d", a[i][j]);
			else
				printf("%4d", ' ');
		}
		printf("\n");
	}	 
	getchar();
}

int main()
{
	//NODE* root = 0;

	display(root);
	insert_data(1, root, LEFT);
	display(root);
	insert_data(2, root, LEFT);
	display(root);
	insert_data(3, root, RIGHT);
	display(root);
	insert_data(4, root->left, LEFT);
	display(root);
	insert_data(5, root->left, RIGHT);
	display(root);
	insert_data(6, root->right, LEFT);
	display(root);
	insert_data(7, root->right, RIGHT);//이케하면 main안에 NODE* root=0;를 넣고
	display(root);
	//위의 함수에서 이중포인터로 받으면 될 것인다.
	return 0;
}

#endif
#if 0
#include <stdio.h>
#include <Windows.h>
#include <time.h>

typedef struct _node
{
	int data;
	struct _node* left;
	struct _node* right;
}NODE;

NODE* root;
typedef enum { LEFT, RIGHT }TYPE;
void insert_data(int data, NODE* s, TYPE type)
{
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = temp->right = 0;
	if (s == 0)
	{
		root = temp;
		return;
	}
	if (type == LEFT)
		s->left = temp;
	else if (type == RIGHT)
		s->right = temp;
}
void __display(NODE* temp,int (*a)[10],int *row,int*col)//리턴타입 만든데 힘들었음.앞에 원래 int[10]* 인데 [10] 뒤로 돌리고 괄호쳐서 이케댐.
{
	if (temp == 0)
		return;
	
	
	;
	__display(temp->left,a,row,col);
	//printf("%*d\n", indent * 4, temp->data);
	a[*row][(*col)++] = temp->data;
	__display(temp->right,a,row,col);
	(*row)--;

	return a;
}

void display(NODE* temp)
{
	int a[10][10] = { 0, };
	int row = -1;
	int col = 0;
	int i = 0, j = 0;
	__display(temp,a,&row,&col);
	system("cls");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (a[i][j] != 0)
				printf("%4d", a[i][j]);
			else
				printf("%4c", ' ');
		}
		printf("\n");
	}
	getchar();
}

int main()
{
	//NODE* root = 0;
	display(root);
	insert_data(1, root, LEFT);
	display(root);
	insert_data(2, root, LEFT);
	display(root);
	insert_data(3, root, RIGHT);
	display(root);
	insert_data(4, root->left, LEFT);
	display(root);
	insert_data(5, root->left, RIGHT);
	display(root);
	insert_data(6, root->right, LEFT);
	display(root);
	insert_data(7, root->right, RIGHT);//이케하면 main안에 NODE* root=0;를 넣고
	display(root);
	//위의 함수에서 이중포인터로 받으면 될 것인다.
	return 0;
}

#endif
