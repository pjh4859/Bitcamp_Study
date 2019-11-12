#if 0
#include <stdio.h>
#include <stdlib.h>

//step 1
//single linked list 설계
typedef struct _node
{
	int data; //linked  data
	struct _node* next; //자기 자신을 가리키는 pointer
}NODE;
NODE* head = 0;
//step 2
//insert_data() 구현
void insert_data(NODE**head,int data)
{
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
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

#if 1
//step 1
//single linked list 설계
typedef struct _node
{
	int data; //linked  data
	struct _node* next; //자기 자신을 가리키는 pointer
}NODE;
NODE* head = 0;
//step 2
//insert_data() 구현
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
	//6 다음에 8 껴넣기.
}
#endif

#if 0
//step 1
//single linked list 설계
typedef struct _node
{
	int data; //linked  data
	struct _node* next; //자기 자신을 가리키는 pointer
}NODE;
NODE head = { 0,&head };
//NODE tail = { 0 };
//step 2
//insert_data() 구현
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
	//6 다음에 8 껴넣기.
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
//insert_data()구현
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