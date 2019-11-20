#if 0
//1. <AVL Tree> 를 만들 것.
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
		//& 가 제일 마지막에 연산됨. 즉 p가 가리키는 주소의 값이 가리키는 것의 right 의 주소.
		else return;
	}
	*p = temp;
}

void __display(NODE* temp, int(*a)[10], int* row, int* col)
//리턴타입 만든데 힘들었음.앞에 원래 int[10]* 인데 [10] 뒤로 돌리고 괄호쳐서 이케댐.
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
//여기서 변수들을 선언해주고 포인터로 __display 로 넘기면 그 안에서는 바뀌지만 스택이 쌓인게 풀리면서
//다시 원래값으로 돌아오는것을 이용해 코딩을 했다.
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

NODE* search(NODE* temp,int key)
{
	if (temp == NULL)return NULL;
	if (key == temp->data)
		return temp;
	else if (key < temp->data)
		search(temp->left, key);
	else
		search(temp->right, key);	
}

NODE* rotate_RR(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

int main()
{
	int a[] = {6,3,1,5,7,11};
	int i;
	char ch;
	NODE* node = 0;
	display(root);
	for (i = 0; i < 6; i++)
	{
		insert_data(a[i]);
		display(root);
	}
	//ch=getchar();
	insert_data(12);
	display(root);
	printf("RR(left rotation) test\n");
	ch=getchar();
	node = search(root, 6);
	//printf("node_data: %d\n", node->data);
	//ch=getchar();
	node->right = rotate_RR(node->right);
	display(root);
	
	return 0;	
}

#endif

#if 0
//1. <AVL Tree> 를 만들 것.
//2. RR rotate 를 만들고, LL ratate 도 만들어보자.
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
		//& 가 제일 마지막에 연산됨. 즉 p가 가리키는 주소의 값이 가리키는 것의 right 의 주소.
		else return;
	}
	*p = temp;
}

void __display(NODE* temp, int(*a)[10], int* row, int* col)
//리턴타입 만든데 힘들었음.앞에 원래 int[10]* 인데 [10] 뒤로 돌리고 괄호쳐서 이케댐.
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
//여기서 변수들을 선언해주고 포인터로 __display 로 넘기면 그 안에서는 바뀌지만 스택이 쌓인게 풀리면서
//다시 원래값으로 돌아오는것을 이용해 코딩을 했다.
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

NODE* search(NODE* temp, int key)
{
	if (temp == NULL)return NULL;
	if (key == temp->data)
		return temp;
	else if (key < temp->data)
		search(temp->left, key);
	else
		search(temp->right, key);
}

NODE* rotate_RR(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

NODE* rotate_LL(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
NODE* rotate_LR(NODE* parent)
{

}


int main()
{
	int a[] = { 7,6,3,12 };
	int i;
	char ch;
	NODE* node = 0;
	display(root);
	for (i = 0; i < 4; i++)
	{
		insert_data(a[i]);
		display(root);
	}
	insert_data(1);
	display(root);
	printf("LL rotation test\n");
	ch=getchar();
	node = search(root, 7);
	node->left = rotate_LL(node->left);
	display(root);

	return 0;
}

#endif

#if 0
//1. <AVL Tree> 를 만들 것.
//2. RR rotate 를 만들고, LL ratate 도 만들어보자.
//3. LR rotate, RL rotate 를 추가.
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
		//& 가 제일 마지막에 연산됨. 즉 p가 가리키는 주소의 값이 가리키는 것의 right 의 주소.
		else return;
	}
	*p = temp;
}

void __display(NODE* temp, int(*a)[10], int* row, int* col)
//리턴타입 만든데 힘들었음.앞에 원래 int[10]* 인데 [10] 뒤로 돌리고 괄호쳐서 이케댐.
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
//여기서 변수들을 선언해주고 포인터로 __display 로 넘기면 그 안에서는 바뀌지만 스택이 쌓인게 풀리면서
//다시 원래값으로 돌아오는것을 이용해 코딩을 했다.
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

NODE* search(NODE* temp, int key)
{
	if (temp == NULL)return NULL;
	if (key == temp->data)
		return temp;
	else if (key < temp->data)
		search(temp->left, key);
	else
		search(temp->right, key);
}

NODE* rotate_RR(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

NODE* rotate_LL(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
NODE* rotate_LR(NODE* parent)
{
	//NODE* child = parent->left->right;
	//child->right = parent;
	//parent->left->right = child->left;
	//child->left = parent->left;
	//parent->left = 0;
	//return child;
	NODE* child = parent->left;
	parent->left = rotate_RR(child);
	return rotate_LL(parent);
}
NODE* rotate_RL(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = rotate_LL(child);
	return rotate_RR(parent);
}
int main()
{
#define SIZE(a) ((sizeof(a))/(sizeof(a[0])))
	//int a[] = { 7,3,1,6,12};//LR용
	int a[] = { 6,3,1,5,7,12};//RL용
	int i;
	char ch;
	NODE* node = 0;
	display(root);
	for (i = 0; i < SIZE(a); i++)
	{
		insert_data(a[i]);
		display(root);
	}
	//insert_data(5);//LR용
	insert_data(9);//RL용
	display(root);
	//printf("LR rotation test\n");
	printf("RL rotation test\n");
	ch = getchar();
	//node = search(root, 7);//LR
	node = search(root, 6);//RL
	//root = rotate_LR(root);
	//root = rotate_LR(node);//LR
	node->right = rotate_RL(node->right);//RL
	display(root);

	return 0;
}

#endif

#if 0
//1. <AVL Tree> 를 만들 것.
//2. RR rotate 를 만들고, LL ratate 도 만들어보자.
//3. LR rotate, RL rotate 를 추가.
//4. height 를 구하는 함수 추가.
//5. balance 를 구하는 함수 추가.
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
		//& 가 제일 마지막에 연산됨. 즉 p가 가리키는 주소의 값이 가리키는 것의 right 의 주소.
		else return;
	}
	*p = temp;
}

void __display(NODE* temp, int(*a)[10], int* row, int* col)
//리턴타입 만든데 힘들었음.앞에 원래 int[10]* 인데 [10] 뒤로 돌리고 괄호쳐서 이케댐.
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
//여기서 변수들을 선언해주고 포인터로 __display 로 넘기면 그 안에서는 바뀌지만 스택이 쌓인게 풀리면서
//다시 원래값으로 돌아오는것을 이용해 코딩을 했다.
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

NODE* search(NODE* temp, int key)
{
	if (temp == NULL)return NULL;
	if (key == temp->data)
		return temp;
	else if (key < temp->data)
		search(temp->left, key);
	else
		search(temp->right, key);
}

NODE* rotate_RR(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

NODE* rotate_LL(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
NODE* rotate_LR(NODE* parent)
{	
	NODE* child = parent->left;
	parent->left = rotate_RR(child);
	return rotate_LL(parent);
}
NODE* rotate_RL(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = rotate_LL(child);
	return rotate_RR(parent);
}
#define SIZE(a) ((sizeof(a))/(sizeof(a[0])))
#define max(a,b) (((a)>(b))?(a):(b))
int get_height(NODE* node)
{
	int height = 0;
	if (node != NULL)
		height = 1+max(get_height(node->left),get_height(node->right));
	return height;
}

int get_balance(NODE* node)
{
	if (node == NULL)return 0;
	return get_height(node->left) - get_height(node->right);
}
int main()
{
	//int a[] = { 7,3,1,6,12};//LR용
	//int a[] = { 6,3,1,5,7,12 };//RL용
	int a[] = { 7,3,1,6,5,12,15,13,14 };
	NODE* node = 0;
	int i,height,in,bal;
	char ch;
	display(root);
	for (i = 0; i < SIZE(a); i++)
	{
		insert_data(a[i]);
		display(root);
	}
	/*
	//insert_data(5);//LR용
	insert_data(9);//RL용
	display(root);
	//printf("LR rotation test\n");
	printf("RL rotation test\n");
	ch = getchar();
	//node = search(root, 7);//LR
	node = search(root, 6);//RL
	//root = rotate_LR(root);
	//root = rotate_LR(node);//LR
	node->right = rotate_RL(node->right);//RL
	display(root);
	*/
	//insert_data(9);
	
	/*
	display(root);
	height = get_height(root);
	printf("root depth: %d\n", height);
	*/

	while (1)
	{
		printf("input the node data(exit: -1): ");
		scanf_s("%d", &in);
		if (in == -1)break;
		node = search(root, in);
		bal = get_balance(node);
		printf("%d의 밸런스 값: %d\n", in, bal);
		ch = getchar();
	}
	return 0;
}

#endif

#if 0
//1. <AVL Tree> 를 만들 것.
//2. RR rotate 를 만들고, LL ratate 도 만들어보자.
//3. LR rotate, RL rotate 를 추가.
//4. height 를 구하는 함수 추가.
//5. balance 를 구하는 함수 추가.
//6. balance_tree 함수 구현.
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
		//& 가 제일 마지막에 연산됨. 즉 p가 가리키는 주소의 값이 가리키는 것의 right 의 주소.
		else return;
	}
	*p = temp;
}

void __display(NODE* temp, int(*a)[10], int* row, int* col)
//리턴타입 만든데 힘들었음.앞에 원래 int[10]* 인데 [10] 뒤로 돌리고 괄호쳐서 이케댐.
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
//여기서 변수들을 선언해주고 포인터로 __display 로 넘기면 그 안에서는 바뀌지만 스택이 쌓인게 풀리면서
//다시 원래값으로 돌아오는것을 이용해 코딩을 했다.
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

NODE* search(NODE* temp, int key)
{
	if (temp == NULL)return NULL;
	if (key == temp->data)
		return temp;
	else if (key < temp->data)
		search(temp->left, key);
	else
		search(temp->right, key);
}

NODE* rotate_RR(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

NODE* rotate_LL(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
NODE* rotate_LR(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = rotate_RR(child);
	return rotate_LL(parent);
}
NODE* rotate_RL(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = rotate_LL(child);
	return rotate_RR(parent);
}
#define SIZE(a) ((sizeof(a))/(sizeof(a[0])))
#define max(a,b) (((a)>(b))?(a):(b))
int get_height(NODE* node)
{
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int get_balance(NODE* node)
{
	if (node == NULL)return 0;
	return get_height(node->left) - get_height(node->right);
}

NODE* search_parent(NODE* node, int key)
//함수 호출기법을 알아야 쓸 수 있는 함수. 리턴형이 있는데 뭔가 이상함.
//리턴되는 중간에 ax 레이터(리턴값은 여기 들어감) 값이 안바뀌기때문에 할 수 있음.
{
	if (node->left && node->left->data == key)
		return node;
	if (node->right && node->right->data == key)
		return node;
	if (!node-> left && key < node->data)
		search_parent(node->left, key);
	else
		search_parent(node->right, key);
}
NODE* balance_tree(NODE* node)
{
	int height_diff;
	height_diff = get_balance(node);
	if (height_diff > 1)
	{
		if (get_balance(node->left) > 0)
		{
			//printf("rotate_LL\n");
			node = rotate_LL(node);
		}
		else
		{
			//printf("rotate_LR\n");
			node = rotate_LR(node);
		}
	}
	else if (height_diff < -1)
	{
		if (get_balance(node->right)<0)
		{
			printf("rotate_RR\n");
			node = rotate_RR(node);
		}
		else
		{
			printf("rotate_RL\n");
			node = rotate_RL(node);
		}
	}
	return node;
}
int main()
{
	//int a[] = { 7,3,1,6,12};//LR용
	//int a[] = { 6,3,1,5,7,12 };//RL용
	int a[] = { 7,3,1,6,5,12,15,13,14 };
	NODE* node = 0;
	int i, height, in, bal;
	display(root);
	for (i = 0; i < SIZE(a); i++)
	{
		insert_data(a[i]);
		display(root);
	}
	/*
	//insert_data(5);//LR용
	insert_data(9);//RL용
	display(root);
	//printf("LR rotation test\n");
	printf("RL rotation test\n");
	ch = getchar();
	//node = search(root, 7);//LR
	node = search(root, 6);//RL
	//root = rotate_LR(root);
	//root = rotate_LR(node);//LR
	node->right = rotate_RL(node->right);//RL
	display(root);
	*/
	//insert_data(9);

	/*
	display(root);
	height = get_height(root);
	printf("root depth: %d\n", height);
	*/

	while (1)
	{
		printf("input the node data(exit: -1): ");
		scanf_s("%d", &in);
		if (in == -1)break;
		node = search(root, in);
		bal = get_balance(node);
		printf("%d의 밸런스 값: %d\n", in, bal);
		if (bal < -1 || bal>1)
		{
			node = search_parent(root, in);
			printf("in: %d parent: %d\n", in, node->data);
			if (node->data < in)
				node->right = balance_tree(node->right);
			else
				node->left = balance_tree(node->left);
			display(root);
		}
	}
	return 0;
}

#endif

#if 0
//1. <AVL Tree> 를 만들 것.
//2. RR rotate 를 만들고, LL ratate 도 만들어보자.
//3. LR rotate, RL rotate 를 추가.
//4. height 를 구하는 함수 추가.
//5. balance 를 구하는 함수 추가.
//6. balance_tree 함수 구현.
//7. 이제 하나 집어넣을때마다 밸런스 맞추게구현 (재귀함수 이용)
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
/*
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
		//& 가 제일 마지막에 연산됨. 즉 p가 가리키는 주소의 값이 가리키는 것의 right 의 주소.
		else return;
	}
	*p = temp;
}
*/

void __display(NODE* temp, int(*a)[10], int* row, int* col)
//리턴타입 만든데 힘들었음.앞에 원래 int[10]* 인데 [10] 뒤로 돌리고 괄호쳐서 이케댐.
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
//여기서 변수들을 선언해주고 포인터로 __display 로 넘기면 그 안에서는 바뀌지만 스택이 쌓인게 풀리면서
//다시 원래값으로 돌아오는것을 이용해 코딩을 했다.
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

NODE* search(NODE* temp, int key)
{
	if (temp == NULL)return NULL;
	if (key == temp->data)
		return temp;
	else if (key < temp->data)
		search(temp->left, key);
	else
		search(temp->right, key);
}

NODE* rotate_RR(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

NODE* rotate_LL(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
NODE* rotate_LR(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = rotate_RR(child);
	return rotate_LL(parent);
}
NODE* rotate_RL(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = rotate_LL(child);
	return rotate_RR(parent);
}
#define SIZE(a) ((sizeof(a))/(sizeof(a[0])))
#define max(a,b) (((a)>(b))?(a):(b))
int get_height(NODE* node)
{
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int get_balance(NODE* node)
{
	if (node == NULL)return 0;
	return get_height(node->left) - get_height(node->right);
}

NODE* search_parent(NODE* node, int key)
//함수 호출기법을 알아야 쓸 수 있는 함수. 리턴형이 있는데 뭔가 이상함.
//리턴되는 중간에 ax 레이터(리턴값은 여기 들어감) 값이 안바뀌기때문에 할 수 있음.
{
	if (node->left && node->left->data == key)
		return node;
	if (node->right && node->right->data == key)
		return node;
	if (!node->left && key < node->data)
		search_parent(node->left, key);
	else
		search_parent(node->right, key);
}
NODE* balance_tree(NODE* node)
{
	int height_diff;
	height_diff = get_balance(node);
	if (height_diff > 1)
	{
		if (get_balance(node->left) > 0)
		{
			//printf("rotate_LL\n");
			node = rotate_LL(node);
		}
		else
		{
			//printf("rotate_LR\n");
			node = rotate_LR(node);
		}
	}
	else if (height_diff < -1)
	{
		if (get_balance(node->right) < 0)
		{
			printf("rotate_RR\n");
			node = rotate_RR(node);
		}
		else
		{
			printf("rotate_RL\n");
			node = rotate_RL(node);
		}
	}
	return node;
}
void insert_data(NODE **root, int data)
{
	NODE ** p = root;

	if (*p == NULL)
	{
		*p = (NODE*)malloc(sizeof(NODE));
		if (*p == NULL)
		{
			printf("메모리 할당 실패\n");
			exit(-1);
		}
		(*p)->data = data;
		(*p)->left = (*p)->right = NULL;
	}
	else if (data < (*p)->data)
	{		 
		insert_data(&((*p)->left),data);
		*p = balance_tree(*p);
	}
	else if (data > (*p)->data)
	{
		insert_data(&((*p)->right),data);
		*p = balance_tree(*p);
	}
	else
	{
		printf("중복 데이터 입력\n");
		return;
	}
}
int main()
{
	//int a[] = { 7,3,1,6,12};//LR용
	//int a[] = { 6,3,1,5,7,12 };//RL용
	//int a[] = { 7,3,1,6,5,12,15,13,14 };
	int a[] = {1,2,4,3,5,6,7 };
	NODE* node = 0;
	int i, height, in, bal;
	display(root);
	for (i = 0; i < SIZE(a); i++)
	{
		insert_data(&root,a[i]);
		display(root);
	}
	/*
	//insert_data(5);//LR용
	insert_data(9);//RL용
	display(root);
	//printf("LR rotation test\n");
	printf("RL rotation test\n");
	ch = getchar();
	//node = search(root, 7);//LR
	node = search(root, 6);//RL
	//root = rotate_LR(root);
	//root = rotate_LR(node);//LR
	node->right = rotate_RL(node->right);//RL
	display(root);
	*/
	//insert_data(9);

	/*
	display(root);
	height = get_height(root);
	printf("root depth: %d\n", height);
	*/

	while (1)
	{
		printf("input the node data(exit: -1): ");
		scanf_s("%d", &in);
		if (in == -1)break;
		node = search(root, in);
		bal = get_balance(node);
		printf("%d의 밸런스 값: %d\n", in, bal);
		if (bal < -1 || bal>1)
		{
			node = search_parent(root, in);
			printf("in: %d parent: %d\n", in, node->data);
			if (node->data < in)
				node->right = balance_tree(node->right);
			else
				node->left = balance_tree(node->left);
			display(root);
		}
	}
	return 0;
}

#endif

#if 0
//1. <AVL Tree> 를 만들 것.
//2. RR rotate 를 만들고, LL ratate 도 만들어보자.
//3. LR rotate, RL rotate 를 추가.
//4. height 를 구하는 함수 추가.
//5. balance 를 구하는 함수 추가.
//6. balance_tree 함수 구현.
//7. 이제 하나 집어넣을때마다 밸런스 맞추게구현 (재귀함수 이용)
//8. 필요없는 주석부분 지우고 해봄.
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

void __display(NODE* temp, int(*a)[10], int* row, int* col)
//리턴타입 만든데 힘들었음.앞에 원래 int[10]* 인데 [10] 뒤로 돌리고 괄호쳐서 이케댐.
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
//여기서 변수들을 선언해주고 포인터로 __display 로 넘기면 그 안에서는 바뀌지만 스택이 쌓인게 풀리면서
//다시 원래값으로 돌아오는것을 이용해 코딩을 했다.
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

NODE* search(NODE* temp, int key)
{
	if (temp == NULL)return NULL;
	if (key == temp->data)
		return temp;
	else if (key < temp->data)
		search(temp->left, key);
	else
		search(temp->right, key);
}

NODE* rotate_RR(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

NODE* rotate_LL(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}
NODE* rotate_LR(NODE* parent)
{
	NODE* child = parent->left;
	parent->left = rotate_RR(child);
	return rotate_LL(parent);
}
NODE* rotate_RL(NODE* parent)
{
	NODE* child = parent->right;
	parent->right = rotate_LL(child);
	return rotate_RR(parent);
}
#define SIZE(a) ((sizeof(a))/(sizeof(a[0])))
#define max(a,b) (((a)>(b))?(a):(b))
int get_height(NODE* node)
{
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int get_balance(NODE* node)
{
	if (node == NULL)return 0;
	return get_height(node->left) - get_height(node->right);
}

NODE* search_parent(NODE* node, int key)
//함수 호출기법을 알아야 쓸 수 있는 함수. 리턴형이 있는데 뭔가 이상함.
//리턴되는 중간에 ax 레이터(리턴값은 여기 들어감) 값이 안바뀌기때문에 할 수 있음.
{
	if (node->left && node->left->data == key)
		return node;
	if (node->right && node->right->data == key)
		return node;
	if (!node->left && key < node->data)
		search_parent(node->left, key);
	else
		search_parent(node->right, key);
}
NODE* balance_tree(NODE* node)
{
	int height_diff;
	height_diff = get_balance(node);
	if (height_diff > 1)
	{
		if (get_balance(node->left) > 0)
		{
			node = rotate_LL(node);
		}
		else
		{
			node = rotate_LR(node);
		}
	}
	else if (height_diff < -1)
	{
		if (get_balance(node->right) < 0)
		{
			printf("rotate_RR\n");
			node = rotate_RR(node);
		}
		else
		{
			printf("rotate_RL\n");
			node = rotate_RL(node);
		}
	}
	return node;
}
void insert_data(NODE** root, int data)
{
	NODE** p = root;

	if (*p == NULL)
	{
		*p = (NODE*)malloc(sizeof(NODE));
		if (*p == NULL)
		{
			printf("메모리 할당 실패\n");
			exit(-1);
		}
		(*p)->data = data;
		(*p)->left = (*p)->right = NULL;
	}
	else if (data < (*p)->data)
	{
		insert_data(&((*p)->left), data);
		*p = balance_tree(*p);
	}
	else if (data > (*p)->data)
	{
		insert_data(&((*p)->right), data);
		*p = balance_tree(*p);
	}
	else
	{
		printf("중복 데이터 입력\n");
		return;
	}
}
int main()
{
	int a[] = { 1,2,4,3,5,6,7,10 };
	NODE* node = 0;
	int i, height, in, bal;
	display(root);
	for (i = 0; i < SIZE(a); i++)
	{
		insert_data(&root, a[i]);
		display(root);
	}

	while (1)
	{
		printf("input the node data(exit: -1): ");
		scanf_s("%d", &in,sizeof(in));
		//if (in != )break;
		if (in == -1)break;
		node = search(root, in);
		bal = get_balance(node);
		printf("%d의 밸런스 값: %d\n", in, bal);
		if (bal < -1 || bal>1)
		{
			node = search_parent(root, in);
			printf("in: %d parent: %d\n", in, node->data);
			if (node->data < in)
				node->right = balance_tree(node->right);
			else
				node->left = balance_tree(node->left);
			display(root);
		}
	}
	return 0;
}

#endif