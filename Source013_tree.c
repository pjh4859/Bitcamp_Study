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
	printf("%*d\n", indent * 4, temp->data);//���� �� ���� ���ٷ� �ٲ㺽.
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
	//insert_data(7,&root->right,RIGHT);//�����ϸ� main�ȿ� NODE* root=0;�� �ְ�
	//���� �Լ����� ���������ͷ� ������ �� ���δ�.

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
	printf("%*d\n", indent * 4, temp->data);//���� �� ���� ���ٷ� �ٲ㺽.
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
	insert_data(7,&root->right,RIGHT);//�����ϸ� main�ȿ� NODE* root=0;�� �ְ�
	in_order(root);
	//���� �Լ����� ���������ͷ� ������ �� ���δ�.

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
//����Ÿ�� ���絥 �������.�տ� ���� int[10]* �ε� [10] �ڷ� ������ ��ȣ�ļ� ���ɴ�.
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
	insert_data(7, root->right, RIGHT);//�����ϸ� main�ȿ� NODE* root=0;�� �ְ�
	display(root);
	//���� �Լ����� ���������ͷ� ������ �� ���δ�.
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
void __display(NODE* temp,int (*a)[10],int *row,int*col)//����Ÿ�� ���絥 �������.�տ� ���� int[10]* �ε� [10] �ڷ� ������ ��ȣ�ļ� ���ɴ�.
{
	int i;
	if (temp == 0)
		return;
	(*row)++;
	__display(temp->left,a,row,col);
	//printf("%*d\n", indent * 4, temp->data);
	a[*row][(*col)++] = temp->data;
	__display(temp->right,a,row,col);
	(*row)--;

	//return a;
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
	insert_data(7, root->right, RIGHT);//�����ϸ� main�ȿ� NODE* root=0;�� �ְ�
	display(root);
	//���� �Լ����� ���������ͷ� ������ �� ���δ�.
	return 0;
}

#endif

#if 0
//���� ������ ���� �ڵ����� ����.(�������� ���� ū ���� ������)
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

void insert_data(int data)
{
	NODE* temp, * p = root, * prev = NULL ;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = temp->right = 0;

	if (root == 0)
	{
		root = temp;
		return;
	}

	while (p)//p�� 0�̸� �Ʒ��� �޸� ��尡 ����. �׶����� ��� ������ ���Ѵ�.
	{
		prev = p;
		if (p->data > data)
			p = p->left;
		else if (p->data < data)
			p = p->right;
		else
			return;
	}
	if (prev->data > data)
		prev->left = temp;
	else
		prev->right = temp;
}

void __display(NODE* temp, int(*a)[10], int* row, int* col)
//����Ÿ�� ���絥 �������.�տ� ���� int[10]* �ε� [10] �ڷ� ������ ��ȣ�ļ� ���ɴ�.
{
	if (temp == 0)
		return;
	(*row)++;
	__display(temp->left, a, row, col);
	//printf("%*d\n", indent * 4, temp->data);
	a[*row][(*col)++] = temp->data;
	__display(temp->right, a, row, col);
	(*row)--;

	//return a;
}

void display(NODE* temp)
//���⼭ �������� �������ְ� �����ͷ� __display �� �ѱ�� �� �ȿ����� �ٲ����� ������ ���ΰ� Ǯ���鼭
//�ٽ� ���������� ���ƿ��°��� �̿��� �ڵ��� �ߴ�.
{
	int a[10][10] = { 0, };
	int row = -1;
	int col = 0;
	int i = 0, j = 0;
	char ch = '0';

	__display(temp, a, &row, &col);
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
	ch=getchar();
}

int main()
{	
	int a[] = { 4,2,1,3,6,5,7 };
	int i;
	display(root);
	for (i = 0; i < 7; i++)
	{
		insert_data(a[i]);
		display(root);
	}

	return 0;
}

#endif

#if 0
//1. ���� ������ ���� �ڵ����� ����.(�������� ���� ū ���� ������)
//2. insert_data ���� ���ǹ��� �ϳ��� ���ǹ����� �����غ���.
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

void insert_data(int data)
{
	NODE* temp, ** p = &root;//, * prev = NULL;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = temp->right = 0;

	/*if (root == 0)
	{
		root = temp;
		return;
	}*/

	while (*p)//p�� 0�̸� �Ʒ��� �޸� ��尡 ����. �׶����� ��� ������ ���Ѵ�.
	{
		//prev = p;
		if ((*p)->data > data)
		{
			p = &(*p)->left;
		}
		else if ((*p)->data < data)
		{
			p = &(*p)->right;
		}
		else		
			return;
	}
	*p = temp;

	/*if (prev->data > data)
		prev->left = temp;
	else
		prev->right = temp;*/
}

void __display(NODE* temp, int(*a)[10], int* row, int* col)
//����Ÿ�� ���絥 �������.�տ� ���� int[10]* �ε� [10] �ڷ� ������ ��ȣ�ļ� ���ɴ�.
{
	if (temp == 0)
		return;
	(*row)++;
	__display(temp->left, a, row, col);
	//printf("%*d\n", indent * 4, temp->data);
	a[*row][(*col)++] = temp->data;
	__display(temp->right, a, row, col);
	(*row)--;

	//return a;
}

void display(NODE* temp)
//���⼭ �������� �������ְ� �����ͷ� __display �� �ѱ�� �� �ȿ����� �ٲ����� ������ ���ΰ� Ǯ���鼭
//�ٽ� ���������� ���ƿ��°��� �̿��� �ڵ��� �ߴ�.
{
	int a[10][10] = { 0, };
	int row = -1;
	int col = 0;
	int i = 0, j = 0;
	char ch = '0';

	__display(temp, a, &row, &col);
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
	ch = getchar();
}

int main()
{
	//int a[] = { 4,2,1,3,6,5,7 };
	int a[] = {1,2,3,4,5,6,7 };
	int i;
	display(root);
	for (i = 0; i < 7; i++)
	{
		insert_data(a[i]);
		display(root);
	}

	return 0;
}
#endif

#if 0
//1. ���� ������ ���� �ڵ����� ����.(�������� ���� ū ���� ������)
//2. insert_data ���� ���ǹ��� �ϳ��� ���ǹ����� �����غ���.
//3. �������� ġ������ �� Ʈ���� �뷱���� �����ִ� �Լ� ����.
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

void insert_data(int data)
{
	NODE* temp, ** p = &root;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->left = temp->right = 0;	

	while (*p)
	{
		//prev = p;
		if ((*p)->data > data)
			p = &(*p)->left;
		else if ((*p)->data < data)
			p = &(*p)->right;
			//& �� ���� �������� �����. �� p�� ����Ű�� �ּ��� ���� ����Ű�� ���� right �� �ּ�.
		else return;
	}
	*p = temp;	
}

void __display(NODE* temp, int(*a)[10], int* row, int* col)
//����Ÿ�� ���絥 �������.�տ� ���� int[10]* �ε� [10] �ڷ� ������ ��ȣ�ļ� ���ɴ�.
{
	if (temp == 0)
		return;
	(*row)++;
	__display(temp->left, a, row, col);
	a[*row][(*col)++] = temp->data;
	__display(temp->right, a, row, col);
	(*row)--;
}

void display(NODE* temp)
//���⼭ �������� �������ְ� �����ͷ� __display �� �ѱ�� �� �ȿ����� �ٲ����� ������ ���ΰ� Ǯ���鼭
//�ٽ� ���������� ���ƿ��°��� �̿��� �ڵ��� �ߴ�.
{
	int a[10][10] = { 0, };
	int row = -1;
	int col = 0;
	int i = 0, j = 0;
	char ch = '0';

	__display(temp, a, &row, &col);
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
	ch = getchar();
}
void __fill(NODE* temp, int* a, int* n)
{
	if (temp == 0)
		return;
	__fill(temp->left, a, n);
	a[(*n)++] = temp->data;
	__fill(temp->right, a, n);
}
NODE* __bal(int* a, int n)
{
	int mid = n / 2;
	NODE* temp;
	if (n < 1)
		return 0;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = a[mid];
	temp->left = __bal(a, mid);
	temp->right = __bal(a + mid + 1, n - mid - 1);
	return temp;
}
void bal(NODE* temp)
{
	int a[100];
	int n = 0;
	__fill(temp,a,&n);
	root=__bal(a, n);
}

int main()
{
	int a[] = { 1,2,3,4,5,6,7 };
	int i;
	display(root);
	for (i = 0; i < 7; i++)
	{
		insert_data(a[i]);
		display(root);
	}
	bal(root);
	display(root);

		return 0;
}
#endif