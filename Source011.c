#if 1
#include <stdio.h>
#include <stdlib.h>

//step 1
//single linked list ����
typedef struct _node
{
	int data; //linked  data
	struct _node* next; //�ڱ� �ڽ��� ����Ű�� pointer
}NODE;
NODE* head = 0;
//step 2
//insert_data() ����
void insert_data(NODE**head,int data)
{
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));//�� ��Ʈ������ �ּҰ��� temp�� ������ ��.
	temp->data = data;
	temp->next = *head;
	//printf("%d\n", *head);
	*head = temp;
	//printf("%d\n", *head);

}
void display(NODE* head)
{
	NODE* temp;
	//system("cls");
	printf("[head]");
	for (temp = head; temp != 0; temp = temp->next)
		printf("->[%d]", temp->data);
	getchar();
}
int main()
{
	int i;
	NODE* MY_HEAD=0;
	display(MY_HEAD);
	for (i = 0; i < 7; i++)
	{
		insert_data(&MY_HEAD, i + 1);
		display(MY_HEAD);
	}
}

#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
//step 1
//single linked list ����
typedef struct _node
{
	int data; //linked  data
	struct _node* next; //�ڱ� �ڽ��� ����Ű�� pointer
}NODE;
NODE* head = 0;
//step 2
//insert_data() ����
void insert_data(NODE** head, int data)
{
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

void insert_next(NODE** s, int data)
{
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = (*s)->next;
	(*s)->next = temp;
}
void display(NODE* head)
{
	NODE* temp;
	system("cls");
	printf("[head]");
	for (temp = head; temp != 0; temp = temp->next)
		printf("->[%d]", temp->data);

	getchar();
}
int main()
{
	int i;
	NODE* MY_HEAD = 0;
	NODE* s;
	display(MY_HEAD);
	for (i = 0; i < 7; i++)
	{
		insert_data(&MY_HEAD, i + 1);
		display(MY_HEAD);
	}
	for (s = MY_HEAD; s->data != 6; s = s->next);
	insert_next(&s, 8);
	display(MY_HEAD);
	//6 ������ 8 ���ֱ�.
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
//step 1
//single linked list ����
typedef struct _node
{
	int data; //linked  data
	struct _node* next; //�ڱ� �ڽ��� ����Ű�� pointer
}NODE;
NODE head = { 0,&head };
//NODE tail = { 0 };
//step 2
//insert_data() ����
/*
void insert_data(NODE** head, int data)
{
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = *head;
	*head = temp;
}
*/
/*
void init(void)
{
	head.next = &tail;
	tail.next = &tail;
}
*/
void insert_next(NODE* s, int data)
{
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = s->next;
	s->next = temp;
}
void reverse(NODE* head)
{
	NODE* prev = head, * curr, * next;
	curr = prev->next;

	while (curr != head)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head->next = prev;
}
void display(NODE* head)
{
	NODE* temp;
	system("cls");
	printf("[head]");
	//for (temp = head->next; temp != &tail; temp = temp->next)
	for (temp = head->next; temp != head; temp = temp->next)
		printf("->[%d]", temp->data);
	getchar();
}

void del_date(NODE* s)
{
	NODE* temp;
	temp = s->next;
	s->next=temp->next;
	free(temp);

}
int main()
{
	int i;
	NODE* MY_HEAD = 0;
	NODE* s;
	//init();
	display(&head);
	for (i = 0; i < 7; i++)
	{
		insert_next(&head, i + 1);
		display(&head);
	}
	for (s = head.next; s->data != 6; s = s->next);
	insert_next(s, 8);
	//6 ������ 8 ���ֱ�.
	display(&head);
	del_date(s);
	display(&head);
	reverse(&head);
	display(&head);
	return 0;
}

#endif

#if 0
//double linked list
typedef struct _node
{
	struct _node* prev;
	int data;
	struct _node* next;
}NODE;

NODE head = { 0,&head,&head };
#endif

#if 0
//insert_data()����
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node* prev;
	struct _node* next;
}NODE;

NODE head = { 0,&head,&head };

void __insert_data(NODE* prev, NODE* temp,NODE*next)
{
	temp->next = next;
	prev->next = temp;
	next->prev = temp;
	temp->prev = prev;
}
void insert_back(NODE* head, NODE* temp)
{
	__insert_data(head->prev, temp, head);
}
void insert_front(NODE* head, NODE* temp)
{
	__insert_data(head, temp, head->next);
}

/*
void insert_data(NODE* head, NODE* temp)
{
	temp->next = head->next;
	head->next = temp;
	temp->prev = head;
	temp->next->prev = temp;
}


*/
void display(NODE* head)
{
	NODE* temp;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next)
		printf("<->[%d]", temp->data);
	printf("<->[head]");
	getchar();
}

int main()
{
	int i;
	NODE* temp;
	for (i = 0; i < 7; i++)
	{
		temp = malloc(sizeof(NODE));

		temp->data = i +1;

		insert_front(&head, temp);
		//insert_back(&head, temp);
		display(&head);
	}
}

#endif

#if 0
//insert_data()����
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	void *data;
	struct _node* prev;
	struct _node* next;
}NODE;

NODE head = { (int*)0, &head, &head };

void __insert_data(NODE* prev, NODE* temp, NODE* next)
{
	temp->next = next;
	prev->next = temp;
	next->prev = temp;
	temp->prev = prev;
}
void insert_back(NODE* head, NODE* temp)
{
	__insert_data(head->prev, temp, head);
}
void insert_front(NODE* head, NODE* temp)
{
	__insert_data(head, temp, head->next);
}
/*
void insert_data(NODE* head, NODE* temp)
{
	temp->next = head->next;
	head->next = temp;
	temp->prev = head;
	temp->next->prev = temp;
}
*/
void display(NODE* head)
{
	NODE* temp;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next)
		printf("<->[%s]", (char*)temp->data);
	printf("<->[head]");
	getchar();
}

//----------------------------�Ϲ�ȭ��---------------------------------------
typedef struct
{
	char namene[20];
}SAWON;
int main()
{
	int i;
	NODE* temp;
	int* dp;
	SAWON s[5] = { "���̶�","ȫ����","����","�뷮��","�ҳ���" };
	display(&head);
	for (i = 0; i < 5; i++)
	{
		temp = (NODE*)malloc(sizeof(NODE));
		//dp = (int*)malloc(sizeof(int));
		//*dp = i + 1;
		temp->data = s+i;

		insert_back(&head, temp);
		//insert_back(&head, temp);
		display(&head);
	}
}
#endif

#if 0
//insert_data()����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node
{
	void* data;
	struct _node* prev;
	struct _node* next;
}NODE;

NODE head = { (int*)0, &head, &head };

void __insert_data(NODE* prev, NODE* temp, NODE* next)
{
	temp->next = next;
	prev->next = temp;
	next->prev = temp;
	temp->prev = prev;
}
void insert_back(NODE* head, NODE* temp)
{
	__insert_data(head->prev, temp, head);
}
void insert_front(NODE* head, NODE* temp)
{
	__insert_data(head, temp, head->next);
}
/*
void insert_data(NODE* head, NODE* temp)
{
	temp->next = head->next;
	head->next = temp;
	temp->prev = head;
	temp->next->prev = temp;
}
*/
typedef struct
{
	//int a;
	char name[20];
}SAWON;
void display(NODE* head)
{
	//int a;
	NODE* temp;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next)
		//printf("<->[%s]", ((SAWON*)temp->data)->name);//���� �ٲ����.
		printf("<->[%s]", (char*)temp->data);//���� �ٲ����.

	printf("<->[head]");
	getchar();
}

//----------------------------�Ϲ�ȭ��---------------------------------------
int main()
{
	//int i;
	NODE* temp;
	//int* dp;
	SAWON* dp;
	char name[20];
	//SAWON s[5] = { "���̶�","ȫ����","����","�뷮��","�ҳ���" };
	display(&head);
	while (1)
	{		
		printf("Enter a Name:(exit : exit):");
		scanf_s("%s", name, sizeof(name));
		temp = (NODE*)malloc(sizeof(NODE));
		dp = (SAWON*)malloc(sizeof(SAWON));
		if (!strcmp(name, "exit"))
		{
			free(temp);
			free(dp);
			goto END;
		}
		//for (i = 0; i < 5; i++)
		//{
		
		strcpy_s(dp-> name,sizeof(name), name);
		//dp->a = 0;
		//dp = (int*)malloc(sizeof(int));
		//*dp = i + 1;
		temp->data = dp;

		insert_back(&head, temp);
		//insert_back(&head, temp);
		display(&head);
		//	}
		
	}
END:
	
	return 0;
}
#endif


#if 0
//insert_data()����
//���� �߰�.(�����:https://github.com/torvalds/linux/blob/6f0d349d922ba44e4348a17a78ea51b7135965b1/scripts/kconfig/list.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node
{
	void* data;
	struct _node* prev;
	struct _node* next;
}NODE;

NODE head = { (int*)0, &head, &head };

void __insert_data(NODE* prev, NODE* temp, NODE* next)
{
	temp->next = next;
	prev->next = temp;
	next->prev = temp;
	temp->prev = prev;
}
void insert_back(NODE* head, NODE* temp)
{
	__insert_data(head->prev, temp, head);
}
void insert_front(NODE* head, NODE* temp)
{
	__insert_data(head, temp, head->next);
}
void erase(NODE* s)
{	
	NODE* temp;
	temp = s->next;

	s->next = temp->next;
	free(temp);
}
/*
void insert_data(NODE* head, NODE* temp)
{
	temp->next = head->next;
	head->next = temp;
	temp->prev = head;
	temp->next->prev = temp;
}
*/
typedef struct
{
	//int a;
	char name[20];
}SAWON;
void display(NODE* head)
{
	//int a;
	NODE* temp;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next)
		//printf("<->[%s]", ((SAWON*)temp->data)->name);//���� �ٲ����.
		printf("<->[%s]", (char*)temp->data);//���� �ٲ����.

	printf("<->[head]");
	getchar();
}

//----------------------------�Ϲ�ȭ��---------------------------------------
int main()
{
	//int i;
	NODE* temp;
	//int* dp;
	SAWON* dp;
	char name[20];
	//SAWON s[5] = { "���̶�","ȫ����","����","�뷮��","�ҳ���" };
	display(&head);
	while (1)
	{
	back:
		printf("Enter a Name:(erase: erase):(exit : exit):");
		scanf_s("%s", name, sizeof(name));
		temp = (NODE*)malloc(sizeof(NODE));
		dp = (SAWON*)malloc(sizeof(SAWON));
		if (!strcmp(name, "exit"))
		{
			free(temp);
			free(dp);
			goto END;
		}
		else if (!strcmp(name, "erase"))
		{
			NODE* s;
			char name2[20];
			printf("Enter the Name will be erased:");
			scanf_s("%s", name2, sizeof(name2));
			//printf("%s", name2);
			for (s = head.next; s->data != name2; s = s->next);
			erase(s);
			display(&head);
			goto back;
		}
		//for (i = 0; i < 5; i++)
		//{

		strcpy_s(dp->name, sizeof(name), name);
		//dp->a = 0;
		//dp = (int*)malloc(sizeof(int));
		//*dp = i + 1;
		temp->data = dp;

		insert_back(&head, temp);
		//insert_back(&head, temp);
		display(&head);
		//	}

	}

END:

	return 0;
}
#endif

#if 0
//insert_data()����
//���� ������ �� �� ���Ը���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define list_entry(ptr,type,menber) (type*)((char*)ptr-(unsigned long)&(((SAWON*)0)->list))

typedef struct _node
{
	//void* data;
	struct _node* prev;
	struct _node* next;
}NODE;

NODE head = {&head, &head};
void __insert_data(NODE* prev, NODE* temp, NODE* next)//temp�� ���� prev ��next ���̿� ����ũ.
{
	temp->next = next;
	prev->next = temp;
	next->prev = temp;
	temp->prev = prev;
}
void insert_back(NODE* head, NODE* temp)
{
	__insert_data(head->prev, temp, head);
}
void insert_front(NODE* head, NODE* temp)
{
	__insert_data(head, temp, head->next);
}
typedef struct
{
	int a;
	char name[20];
	NODE list;//�߰�
	NODE S;
	int b;
}SAWON;
void display(NODE* head)
{
	//int a;
	NODE* temp;
	SAWON* s;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next)
	{
		//s = (SAWON*)((char*)temp - (unsigned long)&(((SAWON*)0)->list));
		s = list_entry(temp, SAWON, list);
			   	
		printf("<->[%s]", s->name);
	}
	printf("<->[head]");
	getchar();
}

//----------------------------�Ϲ�ȭ��---------------------------------
int main()
{
	//int i;
	NODE* temp;
	//int* dp;
	SAWON* dp;
	NODE w = { &w,&w };
	char name[20];
	display(&head);
	while (1)
	{
		printf("Enter a Name:(erase: erase):(exit : exit):");
		scanf_s("%s", name, sizeof(name));
		temp = (NODE*)malloc(sizeof(NODE));
		dp = (SAWON*)malloc(sizeof(SAWON));
		if (!strcmp(name, "exit"))
		{
			free(temp);
			free(dp);
			goto END;
		}		
		strcpy_s(dp->name, sizeof(name), name);
		dp->a = 0;
		
		insert_back(&head, &(dp->list));
		//insert_back(&head, temp);
		display(&head);
	}
END:
	return 0;
}
#endif

#if 0
//insert_data()����
//���� ������ �� �� ���Ը���
//���� ���� �߰�.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define list_entry(ptr,type,menber) (type*)((char*)ptr-(unsigned long)&(((SAWON*)0)->list))

typedef struct _node
{
	struct _node* prev;
	struct _node* next;
}NODE;

NODE head = { &head, &head };
void __insert_data(NODE* prev, NODE* temp, NODE* next)
{
	temp->next = next;
	prev->next = temp;
	next->prev = temp;
	temp->prev = prev;
}
void insert_back(NODE* head, NODE* temp)
{
	__insert_data(head->prev, temp, head);
}
void insert_front(NODE* head, NODE* temp)
{
	__insert_data(head, temp, head->next);
}
typedef struct
{
	int sex;
	char name[20];
	NODE list;//�߰�
	NODE M;
	NODE F;
}SAWON;
void display(NODE* head)
{
	NODE* temp;
	SAWON* s;
	//system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next)
	{
		//s = (SAWON*)((char*)temp - (unsigned long)&(((SAWON*)0)->list));
		s = list_entry(temp, SAWON, list);
		printf("<->[%s]", s->name);
		printf("<->[%s]", s->sex);

	}
	printf("<->[head]");
	getchar();
}

//----------------------------�Ϲ�ȭ��---------------------------------
int main()
{
	//NODE* temp;
	SAWON* dp;
	NODE w = { &w,&w };
	char name[20];
	int sex;
	display(&head);
	while (1)
	{
		printf("Enter a Name:(erase: erase):(exit : exit):");
		scanf_s("%s", name, sizeof(name));
		//temp = (NODE*)malloc(sizeof(NODE));
		dp = (SAWON*)malloc(sizeof(SAWON));
		if (!strcmp(name, "exit"))
		{
			//free(temp);
			free(dp);
			goto END;
		}
		printf("Enter the sex:(Male:0, Female:except 0)");
		scanf_s("%d", &sex, sizeof(sex));
		strcpy_s(dp->name, sizeof(name), name);
		dp->sex = sex;
		//printf("%d", dp->sex);
		insert_back(&head, &(dp->list));
		display(&head);
		if (sex == 0)
		{
			insert_back(&head, &(dp->M));
		}
		else
		{
			insert_back(&head, &(dp->F));
		}
		//display(&head);
	}
END:
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node NODE;
struct _node
{
	int data;
	NODE* next;
};

typedef struct _list
{
	NODE* head;
	NODE* tail;
	int size;
}LIST;

int creatList(LIST* lp);
int insertFirst(LIST* lp, int data);
int insertLast(LIST* lp, int data);
int removeNode(LIST* lp, int data);
NODE* searchNode(LIST* lp, int data);

void sortList(LIST* lp);
void showList(LIST* lp);
void removeList(LIST* lp);


int creatList(LIST* lp)
{
	if (lp == NULL)
	{
		return -1;
	}
	lp->head = (NODE*)malloc(sizeof(NODE));
	if (lp->head == NULL)
	{
		return -1;
	}
	lp->tail = (NODE*)malloc(sizeof(NODE));
	if (lp->tail == NULL)
	{
		free(lp->head);
		return -1;
	}
	lp->head->next = lp->tail;
	lp->tail->next = lp->tail;
	lp->size = 0;

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1
#define bool   _Bool

// Node
typedef struct Node {
	int data;
	Node* next;
}Node;

// Global list
Node* list;

// Init
void init() {

	if (list == NULL) {
		return;
	}
	else {
		Node* cur;
		cur = list;

		while (cur != NULL) {
			list = cur->next;
			free(cur);
			cur = list;
		}
	}
}

// Add - one by one
void add(int key) {

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = key;
	new_node->next = NULL;

	// Check first element
	if (list == NULL) {
		list = new_node;
	}
	else {
		// Add new node to head
		new_node->next = list;
		list = new_node;
	}
}

// Add - add ascending order
void ascending_order_add(int key) {

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = key;
	new_node->next = NULL;

	if (list == NULL) {
		list = new_node;
	}
	else {

		Node* cur = list;
		Node* prev = NULL;

		// If first element is larger than key
		if (cur->data > new_node->data) {
			new_node->next = cur;
			list = new_node;
		}
		// Other cases
		else {
			while (cur != NULL && cur->data < new_node->data) {
				prev = cur;
				cur = cur->next;
			}
			// Add in middle
			if (cur != NULL) {
				new_node->next = cur;
				prev->next = new_node;
			}
			// Add to end
			else {
				prev->next = new_node;
			}
		}
	}
}

// Add - add only unique value
void add_unique(int key) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = key;
	new_node->next = NULL;

	if (list == NULL) {
		list = new_node;
	}
	else {
		Node* cur = list;

		// Duplication check
		while (cur != NULL) {
			if (cur->data == key) {
				return;
			}
			cur = cur->next;
		}

		new_node->next = list;
		list = new_node;
	}
}

// Remove
bool remove(int key) {

	if (list == NULL) {
		return false;
	}

	if (list->data == key) {
		Node* cur = list;
		list = list->next;
		free(cur);
		return true;
	}
	else {
		Node* cur = list->next;
		Node* prev = list;
		while (cur != NULL && cur->data != key) {
			prev = cur;
			cur = cur->next;
		}

		if (cur == NULL) return false;

		prev->next = cur->next;
		free(cur);
		return true;
	}
}

// Traverse
void traverse() {

	Node* cur = list;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

}

int main() {

	int arr[9] = { 2, 4, 6, 8, 1, 3, 5, 7, 9 };
	int arr_duplicated[18] = { 8, 1, 3, 2, 4, 6, 8, 1, 3, 5, 7, 9, 2, 4, 6, 5, 7, 9 };
	int arr_rmv[4] = { 2, 9, 8, 100 };


	// Add to list 1
	init();
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		add(arr[i]);
	}
	printf("After add(normal) : ");
	traverse();


	// Add to list 2
	init();
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		ascending_order_add(arr[i]);
	}
	printf("After add(ascending) : ");
	traverse();


	// Add to list 3
	init();
	for (int i = 0; i < sizeof(arr_duplicated) / sizeof(arr_duplicated[0]); ++i) {
		add_unique(arr_duplicated[i]);
	}
	printf("After add(unique) : ");
	traverse();


	// Remove specific values in list
	for (int i = 0; i < sizeof(arr_rmv) / sizeof(arr_rmv[0]); ++i) {
		remove(arr_rmv[i]);
	}
	printf("After remove : ");
	traverse();

	return 0;

}
#endif