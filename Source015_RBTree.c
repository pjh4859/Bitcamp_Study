#if 0

#include <stdio.h>
#include <stdlib.h>

typedef struct rb_node
{
	struct rb_node* parent;
	struct rb_node* rb_right;
	struct rb_node* rb_left;
	int color;
	int data;
}RB_NODE;

RB_NODE* root = 0;

#define   SIZE(a)   ( sizeof(a) / sizeof(a[0]) )

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

//ARG arg;

void __display(RB_NODE* temp, int(*a)[10], int* row, int* col)
{
	if (temp == 0)
		return;
	++* row;
	__display(temp->rb_left, a, row, col);
	a[*row][(*col)++] = temp->data;
	__display(temp->rb_right, a, row, col);
	--* row;
}

//void __display(RB_NODE* temp, int(*a)[10], int* row, int* col)
//void __display(ARG arg)
//{
//   ARG ar;
//   if (arg.temp == 0)
//      return;
//   ++*(arg.row);
//   ar.temp = arg.temp->rb_left;
//   __display(ar);
//   arg.a[*(arg.row)][(*(arg.col))++] = arg.temp->data;
//   arg.temp = arg.temp->rb_right;
//   __display(ar);
//   --*(arg.row);
//}

void display(RB_NODE* temp)
{
	int i, j;
	int row = -1;
	int col = 0;
	int a[10][10] = { 0, };

	system("cls");
	__display(temp, a, &row, &col);

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
}

//void display()
//void display(RB_NODE* temp)
//{
//   int i, j;
//   int row = -1;
//   int col = 0;
//   int a[10][10] = { 0, };
//   ARG arg;
//   arg.temp = temp;
//   arg.row = &row;
//   arg.col = &col;
//   arg.a = a;
//
//   system("cls");
////   __display(temp, a, &row, &col);
//   __display(arg);
//
//   for (i = 0; i < 10; i++)
//   {
//      for (j = 0; j < 10; j++)
//      {
//         if (arg.a[i][j] != 0)
//            printf("%4d", arg.a[i][j]);
//         else
//            printf("%4c", ' ');
//      }
//      printf("\n");
//   }
//}

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

#if 0
//1.R-B Tree 를 만들기 시작합니다.
#include<stdio.h>
#include<stdlib.h>

typedef struct rb_node
{
	struct rb_node* parent;
	struct rb_node* rb_right;
	struct rb_node* rb_left;
	int color;
	int data;
}RB_NODE;
RB_NODE* root = 0;
#define RB_RED		1
#define RB_BLACK	0

void rotate_left(RB_NODE* node, RB_NODE** root);
void rotate_right(RB_NODE* node, RB_NODE** root);
void insert_color(RB_NODE* node, RB_NODE** root);

void rotate_left(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* right = node->rb_right;
	RB_NODE* parent = node->parent;

	if (node->rb_right = right->rb_left)
	{
		right->rb_left->parent = node;
		//right의 왼쪽 자식을 node 에 붙임. (왼쪽 자식이 node 의 자식이 됨.)
	}
	right->rb_left = node;
	right->parent = parent;

	if (parent)
	{
		if (parent->rb_left == node)
			parent->rb_left = right;
		else
			parent->rb_right = right;
	}
	else
		*root = right;
	node->parent = right;
	//parent->rb_right = right;
}
void rotate_right(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* left = node->rb_left;
	RB_NODE* parent = node->parent;

	if (node->rb_left = left->rb_right)
	{
		left->rb_right->parent = node;
		//right의 왼쪽 자식을 node 에 붙임. (왼쪽 자식이 node 의 자식이 됨.)
	}
	left->rb_right = node;
	left->parent = parent;

	if (parent)
	{
		if (parent->rb_right == node)
			parent->rb_right = left;
		else
			parent->rb_left = left;
	}
	else
		*root = left;
	node->parent = left;
	//parent->rb_right = right;
}

#define SZ(a)		(sizeof(a)/sizeof(a[0]))
void insert_color(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* parent, * gparent, * uncle, * temp;
	while ((parent = node->parent) && (parent->color == RB_RED))
	{
		gparent = parent->parent;
		if (parent == gparent->rb_right)
		{
			uncle=gparent->rb_right;
			if (uncle && (uncle->color) == RB_RED);
			{
				uncle->color = RB_BLACK;
				parent->color = RB_BLACK;
				gparent->color = RB_RED;
				node = gparent;
				continue;
			}
			if (parent->rb_left == node)
			{
				rotate_right(parent, root);
				temp = parent;
				parent = node;
				node = temp;
			}
			parent->color = RB_BLACK;
			gparent->color = RB_RED;
			rotate_right(gparent, root);
		}
		else
		{

		}
	}
	(*root)->color = RB_BLACK;

}

typedef struct
{
	int data;
	RB_NODE tree;
}DATA;
typedef struct
{
	int data;
	int color;
}INFO;
typedef struct _arg
{
	RB_NODE* temp;
	INFO(*a)[10];
	int* row;
	int* col;
}ARG;

void insert_data(int data)
{
	RB_NODE* temp;
	RB_NODE** p=&root;
	RB_NODE* parent = NULL;
	temp = (RB_NODE*)malloc(sizeof(RB_NODE));
	temp->data = data;
	temp->color = RB_RED;
	temp->rb_left = temp->rb_right = 0;

	while (*p)
	{
		parent = *p;//안해주면 NULL값이 계속 들어감.
		if ((*p)->data > data)
			p = &(*p)->rb_left;
		else if ((*p)->data < data)
			p = &(*p)->rb_right;
		else return;
	}
	temp->parent = parent;
	*p = temp;
	insert_color(temp, &root);
}
/*
typedef struct _arg
{
	RB_NODE* temp;
	int(*a)[10];
	int* row;
	int* col;
}ARG;
*/
void __display(ARG arg)
{
	ARG ar;
	ar = arg;
	if (arg.temp == 0)
		return;
	++* (arg.row);
	ar.temp = arg.temp->rb_left;
	__display(ar);
	arg.a[*(arg.row)][(*(arg.col))++] = arg.temp->data;
	ar.temp = arg.temp->rb_right;
	__display(ar);
	--* (arg.row);
}

void display(RB_NODE* temp)
{
	int i, j;
	int row = -1;
	int col = 0;
	int a[10][10] = { 0, };

	ARG arg;
	arg.temp = temp;
	arg.row = &row;
	arg.col = &col;
	arg.a = a;

	system("cls");
	__display(arg);

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
	/*
	int a[] = {6,4,2,1,3,5};
	int i;
	RB_NODE* s;

	for (i = 0; i < SZ(a); i++)
	{
		insert_data(a[i]);
		display(root);
	}
	printf("rotate_left test\n");
	getchar();
	//s = root->rb_right;
	//rotate_left(s, &root);
	s = root->rb_left;
	rotate_right(s, &root);
	display(root);
	*/

	int i;
	RB_NODE* root = 0;
	display(root);
	for (i = 0; i < 10; i++)
	{
		insert_data(&root, i + 1);
		display(root);
	}
	return 0;
}

#endif

#if 0
//1.R-B Tree 를 만들기 시작합니다.
//2.전체적인 함수 수정. (typedef 를 만들어서)
#include<stdio.h>
#include<stdlib.h>

typedef struct rb_node{
	struct rb_node* parent;
	struct rb_node* rb_right;
	struct rb_node* rb_left;
	int color;
	//int data;
}RB_NODE;
typedef struct{
	int data;
	RB_NODE tree;
}DATA;
typedef struct{
	int data;
	int color;
}INFO;
typedef struct _arg{
	RB_NODE* temp;
	INFO(*a)[10];
	int* row;
	int* col;
}ARG;
RB_NODE* root = 0;
#define offset(type,member)\
		( (unsigned long) & ( ((type*)0)->member ) )
//DATA 스트럭쳐 안에 tree 가 어느정도 떨어져있는지 구할 때 씀.
#define rb_entry(ptr,type,member)\
		(type*)((char*)ptr-offset(type,member))
#define RB_RED		1
#define RB_BLACK	0
#define SZ(a)		(sizeof(a)/sizeof(a[0]))

void rotate_left(RB_NODE* node, RB_NODE** root);
void rotate_right(RB_NODE* node, RB_NODE** root);
void insert_color(RB_NODE* node, RB_NODE** root);

void rotate_left(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* right = node->rb_right;
	RB_NODE* parent = node->parent;

	if (node->rb_right = right->rb_left)
	{
		right->rb_left->parent = node;
		//right의 왼쪽 자식을 node 에 붙임. (왼쪽 자식이 node 의 자식이 됨.)
	}
	right->rb_left = node;
	right->parent = parent;

	if (parent)
	{
		if (parent->rb_left == node)
			parent->rb_left = right;
		else
			parent->rb_right = right;
	}
	else
		*root = right;
	node->parent = right;
}
void rotate_right(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* left = node->rb_left;
	RB_NODE* parent = node->parent;

	if (node->rb_left = left->rb_right)
	{
		left->rb_right->parent = node;
		//right의 왼쪽 자식을 node 에 붙임. (왼쪽 자식이 node 의 자식이 됨.)
	}
	left->rb_right = node;
	left->parent = parent;

	if (parent)
	{
		if (parent->rb_right == node)
			parent->rb_right = left;
		else
			parent->rb_left = left;
	}
	else
		*root = left;
	node->parent = left;
}

void insert_color(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* parent, * gparent, * uncle, * temp;
	while ((parent = node->parent) && (parent->color == RB_RED))
	{
		gparent = parent->parent;
		if (parent == gparent->rb_right)
		{
			uncle = gparent->rb_left;//right 를 left 로 바꿈.
			if (uncle && (uncle->color == RB_RED))
			{
				uncle->color = RB_BLACK;
				parent->color = RB_BLACK;
				gparent->color = RB_RED;
				node = gparent;
				continue;
			}
			if (parent->rb_left == node)
			{
				rotate_right(parent, root);
				temp = parent;
				parent = node;
				node = temp;
			}
			parent->color = RB_BLACK;
			gparent->color = RB_RED;
			rotate_left(gparent, root);//right->left
		}
		else//반대로 바꿔야함.
		{
			uncle = gparent->rb_right;
			if (uncle && (uncle->color == RB_RED));
			{
				uncle->color = RB_BLACK;
				parent->color = RB_BLACK;
				gparent->color = RB_RED;
				node = gparent;
				continue;
			}
			if (parent->rb_right == node)
			{
				rotate_left(parent, root);
				temp = parent;
				parent = node;
				node = temp;
			}
			parent->color = RB_BLACK;
			gparent->color = RB_RED;
			rotate_right(gparent, root);
		}
	}
	(*root)->color = RB_BLACK;

}

void insert_data(RB_NODE**root,int data)
{
	DATA* temp;//
	RB_NODE** p = root;
	RB_NODE* parent = NULL;
	temp = (DATA*)malloc(sizeof(DATA));//
	temp->data = data;
	temp->tree.color = RB_RED;
	temp->tree.rb_left = temp->tree.rb_right = 0;
	DATA* s;

	while (*p)
	{
		parent = *p;//안해주면 NULL값이 계속 들어감.
		s = rb_entry(parent, DATA, tree);

		if (s->data > data)
			p = &(*p)->rb_left;
		else if (s->data < data)
			p = &(*p)->rb_right;
		else return;
	}
	temp->tree.parent = parent;
	*p = &(temp->tree);
	insert_color(&(temp->tree), root);

}
void __display(ARG arg)
{
	ARG ar;
	ar = arg;
	if (arg.temp == 0)
		return;
	++* (arg.row);
	ar.temp = arg.temp->rb_left;
	__display(ar);

	arg.a[*(arg.row)][(*(arg.col))].data = (rb_entry(arg.temp,DATA,tree))->data;
	arg.a[*(arg.row)][(*(arg.col))++].color = arg.temp->color;
	
	ar.temp = arg.temp->rb_right;
	__display(ar);
	--* (arg.row);
}

void display(RB_NODE* temp)
{
	int i, j;
	int row = -1;
	int col = 0;
	INFO a[10][10] = { 0, };

	ARG arg;
	arg.temp = temp; arg.row = &row; arg.col = &col; arg.a = a;

	system("cls");
	__display(arg);
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (a[i][j].data != 0)
			{
				if (a[i][j].color == RB_RED)
					printf("<%2d>", a[i][j].data);
				else 
					printf("[%2d]", a[i][j].data);
			}
			else
				printf("%3c", ' ');
		}
		printf("\n");
	}
	getchar();
}

int main()
{	
	int i;
	RB_NODE* root = 0;
	display(root);
	for (i = 0; i < 10; i++)
	{
		insert_data(&root, i + 1);
		display(root);
	}
	return 0;
}

#endif
#if 0
//1.R-B Tree 를 만들기 시작합니다.
//2.전체적인 함수 수정. (typedef 를 만들어서)
//3.패딩때문에 주소값에서 뒤의 두 숫자는 00이 나오는 것을 이용
//color 를 표시해보자!
#include<stdio.h>
#include<stdlib.h>

typedef struct rb_node {
	unsigned long rb_parent_color;
	struct rb_node* rb_right;
	struct rb_node* rb_left;
	//int color;
	//int data;
}RB_NODE;
typedef struct {
	int data;
	RB_NODE tree;
}DATA;
typedef struct {
	int data;
	int color;
}INFO;
typedef struct _arg {
	RB_NODE* temp;
	INFO(*a)[10];
	int* row;
	int* col;
}ARG;
RB_NODE* root = 0;
#define offset(type,member)\
		( (unsigned long) & ( ((type*)0)->member ) )
//DATA 스트럭쳐 안에 tree 가 어느정도 떨어져있는지 구할 때 씀.
#define rb_entry(ptr,type,member)\
		(type*)((char*)ptr-offset(type,member))
#define RB_RED		1
#define RB_BLACK	0
#define SZ(a)		(sizeof(a)/sizeof(a[0]))
//#define rb_parent(r)	((RB_NODE*)((((r)->rb_parent_color)>>2)<<2))
#define rb_parent(r)	((RB_NODE*)((r)->rb_parent_color & ~3))
//#define rb_set_parent(r, ptr) ((r)->rb_parent_color = ((r)->rb_parent_color & 3) | (unsigned long)(ptr))
//#define rb_set_parent2(r, ptr) ((r)->tree.rb_parent_color = ((r)->tree.rb_parent_color & 3) | (unsigned long)(ptr))
#define rb_color(r)		((r)->rb_parent_color & 1)
#define rb_is_red(r)	(rb_color(r))
#define rb_set_black(r)		do{((r)->rb_parent_color &= ~1);}while(0)
#define rb_set_red(r)	do{((r)->rb_parent_color |= 1);}while(0)
//#define rb_set_black2(r)	do{((r)->tree.rb_parent_color &= ~1);}while(0)
//#define rb_set_red2(r)	do{((r)->tree.rb_parent_color |= 1);}while(0)

void rotate_left(RB_NODE* node, RB_NODE** root);
void rotate_right(RB_NODE* node, RB_NODE** root);
void insert_color(RB_NODE* node, RB_NODE** root);
void __display(ARG arg);
void display(RB_NODE* temp);

void rb_set_parent(RB_NODE* child, RB_NODE* parent)
{
	child->rb_parent_color = child->rb_parent_color & 3 | (unsigned long)parent;
}

void rotate_left(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* right = node->rb_right;
	//RB_NODE* parent = (RB_NODE*)(node->rb_parent_color & ~3);
	RB_NODE* parent = rb_parent(node);

	if (node->rb_right = right->rb_left)
	{
		//right->rb_left->parent = node;
		//right의 왼쪽 자식을 node 에 붙임. (왼쪽 자식이 node 의 자식이 됨.)
		rb_set_parent(right->rb_left, node);
	}
	right->rb_left = node;
	//right->parent = parent;
	rb_set_parent(right, parent);

	if (parent)
	{
		if (parent->rb_left == node)
			parent->rb_left = right;
		else
			parent->rb_right = right;
	}
	else
		*root = right;
	//node->parent = right;
	rb_set_parent(node, right);

}
void rotate_right(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* left = node->rb_left;
	RB_NODE* parent = rb_parent(node);

	if (node->rb_left = left->rb_right)
	{
		//left->rb_right->parent = node;
		rb_set_parent(left->rb_right, node);
		//right의 왼쪽 자식을 node 에 붙임. (왼쪽 자식이 node 의 자식이 됨.)
	}
	left->rb_right = node;
	//left->parent = parent;
	rb_set_parent(left, parent);

	if (parent)
	{
		if (parent->rb_right == node)
			parent->rb_right = left;
		else
			parent->rb_left = left;
	}
	else
		*root = left;
	//node->parent = left;
	rb_set_parent(node, left);
}

void insert_color(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* parent, * gparent, * uncle, * temp;
	//while ((parent = node->parent) && (parent->color == RB_RED))
	while((parent = rb_parent(node)) && (rb_is_red(parent)))
	{
		//gparent = parent->parent;
		gparent = rb_parent(parent);
		if (parent == gparent->rb_right)
		{
			uncle = gparent->rb_left;//right 를 left 로 바꿈.
			//if (uncle && (uncle->color == RB_RED))
			if (uncle && (rb_is_red(uncle)))
			{
				//uncle->color = RB_BLACK;
				rb_set_black(uncle);
				//parent->color = RB_BLACK;
				rb_set_black(parent);
				//gparent->color = RB_RED;
				rb_set_red(gparent);
				node = gparent;
				continue;
			}
			if (parent->rb_left == node)
			{
				rotate_right(parent, root);
				temp = parent;
				parent = node;
				node = temp;
			}
			//parent->color = RB_BLACK;
			rb_set_black(parent);
			//gparent->color = RB_RED;
			rb_set_red(gparent);
			rotate_left(gparent, root);//right->left
		}
		else//반대로 바꿔야함.
		{
			uncle = gparent->rb_right;
			//if (uncle && (uncle->color == RB_RED));
			if (uncle && (rb_is_red(uncle)));
			{
				//uncle->color = RB_BLACK;
				rb_set_black(uncle);
				//parent->color = RB_BLACK;
				rb_set_black(parent);
				//gparent->color = RB_RED;
				rb_set_red(gparent);
				node = gparent;
				continue;
			}
			if (parent->rb_right == node)
			{
				rotate_left(parent, root);
				temp = parent;
				parent = node;
				node = temp;
			}
			//parent->color = RB_BLACK;
			rb_set_black(parent);
			//gparent->color = RB_RED;
			rb_set_red(gparent);

			rotate_right(gparent, root);
		}
	}
	//(*root)->color = RB_BLACK;
	rb_set_black(*root);
}

void insert_data(RB_NODE** root, int data)
{
	DATA* temp;//
	RB_NODE** p = root;
	RB_NODE* parent = NULL;
	temp = (DATA*)malloc(sizeof(DATA));//
	temp->data = data;
	//temp->tree.color = RB_RED;
	//rb_set_red2(temp);
	rb_set_red(&temp->tree);
	temp->tree.rb_left = temp->tree.rb_right = 0;
	DATA* s;

	while (*p)
	{
		parent = *p;//안해주면 NULL값이 계속 들어감.
		s = rb_entry(parent, DATA, tree);

		if (s->data > data)
			p = &(*p)->rb_left;
		else if (s->data < data)
			p = &(*p)->rb_right;
		else return;
	}
	//temp->tree.parent = parent;
	rb_set_parent(&temp->tree, parent);
	*p = &(temp->tree);
	display(*root);
	insert_color(&temp->tree, root);

}
void __display(ARG arg)
{
	ARG ar;
	ar = arg;
	if (arg.temp == 0)
		return;
	++* (arg.row);
	ar.temp = arg.temp->rb_left;
	__display(ar);

	arg.a[*(arg.row)][(*(arg.col))].data = (rb_entry(arg.temp, DATA, tree))->data;
	//arg.a[*(arg.row)][(*(arg.col))++].color = arg.temp->color;
	arg.a[*(arg.row)][(*(arg.col))++].color = rb_color(arg.temp);

	ar.temp = arg.temp->rb_right;
	__display(ar);
	--* (arg.row);
}

void display(RB_NODE* temp)
{
	int i, j;
	int row = -1;
	int col = 0;
	INFO a[10][10] = { 0, };

	ARG arg;
	arg.temp = temp; arg.row = &row; arg.col = &col; arg.a = a;

	system("cls");
	__display(arg);
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (a[i][j].data != 0)
			{
				if (a[i][j].color == RB_RED)
					printf("<%2d>", a[i][j].data);
				else
					printf("[%2d]", a[i][j].data);
			}
			else
				printf("%3c", ' ');
		}
		printf("\n");
	}
	getchar();
}

int main()
{
	int i;
	RB_NODE* root = 0;
	display(root);
	for (i = 0; i < 10; i++)
	{
		insert_data(&root, i + 1);
		display(root);
	}
	return 0;
}

#endif

#if 0
//1.R-B Tree 를 만들기 시작합니다.
//2.전체적인 함수 수정. (typedef 를 만들어서)
//3.패딩때문에 주소값에서 뒤의 두 숫자는 00이 나오는 것을 이용
//color 를 표시해보자!
//4.노드 삭제해보자!
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct rb_node {
	unsigned long rb_parent_color;
	struct rb_node* rb_right;
	struct rb_node* rb_left;
}RB_NODE;
typedef struct {
	int data;
	RB_NODE tree;
}DATA;
typedef struct {
	int data;
	int color;
}INFO;
typedef struct _arg {
	RB_NODE* temp;
	INFO(*a)[10];
	int* row;
	int* col;
}ARG;
RB_NODE* root = 0;
#define offset(type,member)\
		( (unsigned long) & ( ((type*)0)->member ) )
//DATA 스트럭쳐 안에 tree 가 어느정도 떨어져있는지 구할 때 씀.
#define rb_entry(ptr,type,member)\
		(type*)((char*)ptr-offset(type,member))
#define RB_RED				1
#define RB_BLACK			0
#define SZ(a)				(sizeof(a)/sizeof(a[0]))
//#define rb_parent(r)		((RB_NODE*)((((r)->rb_parent_color)>>2)<<2))
#define rb_parent(r)		((RB_NODE*)((r)->rb_parent_color & ~3))
#define rb_color(r)			((r)->rb_parent_color & 1)
#define rb_is_red(r)		(rb_color(r))
#define rb_set_black(r)		do{((r)->rb_parent_color &= ~1);}while(0)
#define rb_set_red(r)		do{((r)->rb_parent_color |= 1);}while(0)

void rotate_left(RB_NODE* node, RB_NODE** root);
void rotate_right(RB_NODE* node, RB_NODE** root);
void insert_color(RB_NODE* node, RB_NODE** root);
void __display(ARG arg);
void display(RB_NODE* temp);

void rb_set_parent(RB_NODE* child, RB_NODE* parent)
{
	child->rb_parent_color = child->rb_parent_color & 3 | (unsigned long)parent;
}
void rotate_left(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* right = node->rb_right;
	//RB_NODE* parent = (RB_NODE*)(node->rb_parent_color & ~3);
	RB_NODE* parent = rb_parent(node);

	if (node->rb_right = right->rb_left)
	{
		//right->rb_left->parent = node;
		//right의 왼쪽 자식을 node 에 붙임. (왼쪽 자식이 node 의 자식이 됨.)
		rb_set_parent(right->rb_left, node);
	}
	right->rb_left = node;
	//right->parent = parent;
	rb_set_parent(right, parent);

	if (parent)
	{
		if (parent->rb_left == node)
			parent->rb_left = right;
		else
			parent->rb_right = right;
	}
	else
		*root = right;
	//node->parent = right;
	rb_set_parent(node, right);
}
void rotate_right(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* left = node->rb_left;
	RB_NODE* parent = rb_parent(node);

	if (node->rb_left = left->rb_right)
	{
		//left->rb_right->parent = node;
		rb_set_parent(left->rb_right, node);
		//right의 왼쪽 자식을 node 에 붙임. (왼쪽 자식이 node 의 자식이 됨.)
	}
	left->rb_right = node;
	//left->parent = parent;
	rb_set_parent(left, parent);

	if (parent)
	{
		if (parent->rb_right == node)
			parent->rb_right = left;
		else
			parent->rb_left = left;
	}
	else
		*root = left;
	//node->parent = left;
	rb_set_parent(node, left);
}

void insert_color(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* parent, * gparent, * uncle, * temp;
	//while ((parent = node->parent) && (parent->color == RB_RED))
	while ((parent = rb_parent(node)) && (rb_is_red(parent)))
	{
		//gparent = parent->parent;
		gparent = rb_parent(parent);
		if (parent == gparent->rb_right)
		{
			uncle = gparent->rb_left;//right 를 left 로 바꿈.
			//if (uncle && (uncle->color == RB_RED))
			if (uncle && (rb_is_red(uncle)))
			{
				//uncle->color = RB_BLACK;
				rb_set_black(uncle);
				//parent->color = RB_BLACK;
				rb_set_black(parent);
				//gparent->color = RB_RED;
				rb_set_red(gparent);
				node = gparent;
				continue;
			}
			if (parent->rb_left == node)
			{
				rotate_right(parent, root);
				temp = parent;
				parent = node;
				node = temp;
			}
			//parent->color = RB_BLACK;
			rb_set_black(parent);
			//gparent->color = RB_RED;
			rb_set_red(gparent);
			rotate_left(gparent, root);//right->left
		}
		else//반대로 바꿔야함.
		{
			uncle = gparent->rb_right;
			//if (uncle && (uncle->color == RB_RED));
			if (uncle && (rb_is_red(uncle)));
			{
				//uncle->color = RB_BLACK;
				rb_set_black(uncle);
				//parent->color = RB_BLACK;
				rb_set_black(parent);
				//gparent->color = RB_RED;
				rb_set_red(gparent);
				node = gparent;
				continue;
			}
			if (parent->rb_right == node)
			{
				rotate_left(parent, root);
				temp = parent;
				parent = node;
				node = temp;
			}
			//parent->color = RB_BLACK;
			rb_set_black(parent);
			//gparent->color = RB_RED;
			rb_set_red(gparent);

			rotate_right(gparent, root);
		}
	}
	//(*root)->color = RB_BLACK;
	rb_set_black(*root);
}

void insert_data(RB_NODE** root, int data)
{
	DATA* temp;//
	RB_NODE** p = root;
	RB_NODE* parent = NULL;
	temp = (DATA*)malloc(sizeof(DATA));//
	temp->data = data;
	//temp->tree.color = RB_RED;
	//rb_set_red2(temp);
	rb_set_red(&temp->tree);
	temp->tree.rb_left = temp->tree.rb_right = 0;
	DATA* s;

	while (*p)
	{
		parent = *p;//안해주면 NULL값이 계속 들어감.
		s = rb_entry(parent, DATA, tree);

		if (s->data > data)
			p = &(*p)->rb_left;
		else if (s->data < data)
			p = &(*p)->rb_right;
		else return;
	}
	//temp->tree.parent = parent;
	rb_set_parent(&temp->tree, parent);
	*p = &(temp->tree);
	display(*root);
	insert_color(&temp->tree, root);

}
void __display(ARG arg)
{
	ARG ar;
	ar = arg;
	if (arg.temp == 0)
		return;
	++* (arg.row);
	ar.temp = arg.temp->rb_left;
	__display(ar);

	arg.a[*(arg.row)][(*(arg.col))].data = (rb_entry(arg.temp, DATA, tree))->data;
	//arg.a[*(arg.row)][(*(arg.col))++].color = arg.temp->color;
	arg.a[*(arg.row)][(*(arg.col))++].color = rb_color(arg.temp);

	ar.temp = arg.temp->rb_right;
	__display(ar);
	--* (arg.row);
}

void display(RB_NODE* temp)
{
	int i, j;
	int row = -1;
	int col = 0;
	INFO a[10][10] = { 0, };

	ARG arg;
	arg.temp = temp; arg.row = &row; arg.col = &col; arg.a = a;

	system("cls");
	__display(arg);
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (a[i][j].data != 0)
			{
				if (a[i][j].color == RB_RED)
					printf("<%2d>", a[i][j].data);
				else
					printf("[%2d]", a[i][j].data);
			}
			else
				printf("%3c", ' ');
		}
		printf("\n");
	}
	getchar();
}
#define rb_data(ptr,type,tree)		((rb_entry(ptr,type,tree))->data)

void rb_erase_color(RB_NODE* node, RB_NODE* parent, RB_NODE** root)
{

}

void rb_erase(RB_NODE* node, RB_NODE** root)
{
	RB_NODE* child, * parent;
	int color;

	if (!node->rb_left)	child = node->rb_right;
	else if (!node->rb_right) child = node->rb_left;
	else{
		RB_NODE* old = node, * left;
		node = node->rb_right;
		while ((left = node->rb_left) != NULL)
			node = left;
		if (rb_parent(old))
		{
			if (rb_parent(old)->rb_left == old)
				rb_parent(old)->rb_left = node;
			else
				rb_parent(old)->rb_right = node;
		}
		else
			*root = node;
		child = node->rb_right;
		parent = rb_parent(node);


		color = rb_color(node);
		if (parent == old)		
			parent = node;
		else{
			if (child)
				rb_set_parent(child, parent);
			parent->rb_left = child;
			node->rb_right = old->rb_right;
			rb_set_parent(old->rb_right, node);
		}
		node->rb_parent_color = old->rb_parent_color;
		node->rb_left = old->rb_left;
		rb_set_parent(old->rb_left, node);
		goto color;
	}
	parent = rb_parent(node);
	color = rb_color(node);
	if (child)
		rb_set_parent(child, parent);
	if (parent)
	{
		if (parent->rb_left == node)
			parent->rb_left = child;
		else
			parent->rb_right = child;
	}
	else
		*root = child;
color:
	if (color == RB_BLACK)
		rb_erase_color(child,parent,root);
		printf("start rb_erase_color\n");
}
void erase_data(RB_NODE** root, int data)
{
	//   DATA* s=NULL;
	RB_NODE** p = root;
	while (*p)
	{
		//   s = rb_entry(*p, DATA, tree);
		//   if (s->data > data)
		if (rb_data(*p, DATA, tree) > data)
			p = &(*p)->rb_left;
		else if (rb_data(*p, DATA, tree) < data)
			p = &(*p)->rb_right;
		else if (rb_data(*p, DATA, tree) == data)
			break;
		else
			return;
	}
	//printf("data : %d, node.data : %d\n", data, rb_data(*p, DATA, tree));
	//getchar();
	rb_erase(*p, root);
}
int main()
{
	int i,in;
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	RB_NODE* root = 0;
	display(root);
	for (i = 0; i < SZ(a); i++)
	{
		//insert_data(&root, i + 1);
		insert_data(&root, a[i]);
		display(root);
	}
	while (1)
	{
		printf("Erase a Node: ");
		scanf("%d", &in);
		if (in == -1)
			break;

		getchar();
		erase_data(&root,in);
		display(root);
	}
	return 0;
}
#endif