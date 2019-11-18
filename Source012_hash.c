#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

struct task_struct
{
	int pid;
	struct task_struct* pidhash_next;
	struct task_struct** pidhash_pprev;
};
#define PIDHASH_SZ (16)
struct task_struct* pidhash[PIDHASH_SZ];

typedef unsigned int u32;
static unsigned int pidhash_shift = 3;
#define GOLDEN_RATIO_PRIME_32	0x9e370001UL //UL: unsigned long

u32 hash_32(u32 val, unsigned int bits)
{
	u32 hash = val * GOLDEN_RATIO_PRIME_32;
	return hash >> (32 - bits);
}

#define hash_long(val, bits) hash_32(val,bits)

#define hashfn(sid) \
		hash_long((unsigned long)sid, pidhash_shift)
#define pid_hashfn(x) ((((x) >> 8)^(x)) &(PIDHASH_SZ -1))

void hash_pid(struct task_struct* p)
{
	struct task_struct** htable = &pidhash[pid_hashfn(p->pid)];
	if ((p->pidhash_next = *htable) != NULL)
		(*htable)->pidhash_pprev = &p->pidhash_next;
	*htable = p;
	p->pidhash_pprev = htable;
}
void display(void)
{
	int i;
	struct task_struct* p;
	system("cls");
	for (i = 0; i < PIDHASH_SZ; i++)
	{
		printf("[%2d]", i);
		for (p = pidhash[i]; p; p = p->pidhash_next)
			printf("<->[%2d]", p->pid);
		printf("\n");
	}
}

struct task_struct* find_task_by_pid(int pid)

{
	struct task_struct* p, ** htable = &pidhash[pid_hashfn(pid)];
	for (p = *htable; p && p->pid != pid; p = p->pidhash_next);
	return p;
}

void unhash_pid(struct task_struct* p)
{
	if (p->pidhash_next)
		p->pidhash_next->pidhash_pprev = p->pidhash_pprev;
	*p->pidhash_pprev = p->pidhash_next;
}
int main()
{
	int i, pid;
	struct task_struct* p;

	srand(time(NULL));
	display();

	for (i = 0; i < 32;)
	{
		if (find_task_by_pid(pid = rand() % 100 + 1000))
			continue;
		p = (struct task_struct*)malloc(sizeof(*p));
		p->pid = pid;
		hash_pid(p);
		Sleep(500);
		display();
		i++;
	}
	getchar();
	for (i = 0; i < PIDHASH_SZ; i++)
	{
		while (p = pidhash[i]) {
			unhash_pid(p);
			free(p);
			Sleep(500);
			display();
		}
	}
return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//위의 코드를 더 바꿔본 것.
struct task_struct
{
	int pid;
	struct task_struct* pidhash_next;
	struct task_struct** pidhash_pprev;
};
#define PIDHASH_SZ (16)
struct task_struct* pidhash[PIDHASH_SZ];
//struct task_struct* pidhash[PIDHASH_SZ][2];

typedef struct _table //수정추가된 곳.
{
	struct task_struct* end;
	struct task_struct* first;
}TABLE;
TABLE pidhash2[PIDHASH_SZ];

typedef unsigned int u32;
static unsigned int pidhash_shift = 3;
#define GOLDEN_RATIO_PRIME_32	0x9e370001UL //UL: unsigned long

u32 hash_32(u32 val, unsigned int bits)
{
	u32 hash = val * GOLDEN_RATIO_PRIME_32;
	return hash >> (32 - bits);
}

#define hash_long(val, bits) hash_32(val,bits)

#define hashfn(sid) \
		hash_long((unsigned long)sid, pidhash_shift)
#define pid_hashfn(x) ((((x) >> 8)^(x)) &(PIDHASH_SZ -1))

void hash_pid(struct task_struct* p)
{
	//struct task_struct** htable = &pidhash[pid_hashfn(p->pid)];
	//struct task_struct** htable = &(pidhash2[pid_hashfn(p->pid)].first);
	TABLE* table = &pidhash2[pid_hashfn(p->pid)];	
	//printf("%d %d", &pidhash[pid_hashfn(p->pid)], &pidhash[pid_hashfn(p->pid)]);
	//printf("%d %d\n", &(pidhash2[pid_hashfn(p->pid)].first), (pidhash2[pid_hashfn(p->pid)].first));
	//printf("%d %d", &pidhash2[pid_hashfn(p->pid)], pidhash2[pid_hashfn(p->pid)]);
	//Sleep(2500);
	if ((p->pidhash_next = table->first) != NULL)
		table->first->pidhash_pprev = &p->pidhash_next;
		//table->first->pidhash_pprev = p->pidhash_next;
	table->first = p;
	//table->end = p;//NULL일 때만 넣어야함
	p->pidhash_pprev = &(table->first);
	if ((table->end) == 0)
		table->end = p;
	/*
	if ((p->pidhash_next = *htable) != NULL)
		(*htable)->pidhash_pprev = &p->pidhash_next;
	*htable = p;
	p->pidhash_pprev = htable;
	*/
}
void display(void)
{
	int i;
	struct task_struct* p;
	system("cls");
	for (i = 0; i < PIDHASH_SZ; i++)
	{
		printf("[%2d]", i);
		//for (p = pidhash[i]; p; p = p->pidhash_next)
		for (p = pidhash2->first; p; p = p->pidhash_next)
			printf("<->[%2d]", p->pid);
		printf("\n");
	}
}

struct task_struct* find_task_by_pid(int pid)

{
	struct task_struct* p, ** htable = &pidhash[pid_hashfn(pid)];
	for (p = *htable; p && p->pid != pid; p = p->pidhash_next);
	return p;
}

void unhash_pid(struct task_struct* p)
{
	if (p->pidhash_next)
		p->pidhash_next->pidhash_pprev = p->pidhash_pprev;
	*p->pidhash_pprev = p->pidhash_next;
}
int main()
{
	int i, pid;
	struct task_struct* p;

	//printf("%d %d", sizeof(pidhash), sizeof(pidhash2));
	Sleep(2500);

	srand(time(NULL));
	display();

	for (i = 0; i < 32;)
	{
		if (find_task_by_pid(pid = rand() % 100 + 1000))
			continue;
		p = (struct task_struct*)malloc(sizeof(*p));
		p->pid = pid;
		hash_pid(p);
		Sleep(500);
		display();
		i++;
	}
	getchar();
	for (i = 0; i < PIDHASH_SZ; i++)
	{
		while (p = pidhash[i]) {
			unhash_pid(p);
			free(p);
			Sleep(500);
			display();
		}
	}
return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//위의 코드를 스트럭쳐 배열로도 되나 실험.
struct task_struct
{
	int pid;
	struct task_struct* pidhash_next;
	struct task_struct** pidhash_pprev;
};
#define PIDHASH_SZ (16)
struct task_struct* pidhash[PIDHASH_SZ][2];

typedef unsigned int u32;
static unsigned int pidhash_shift = 3;
#define GOLDEN_RATIO_PRIME_32	0x9e370001UL //UL: unsigned long

u32 hash_32(u32 val, unsigned int bits)
{
	u32 hash = val * GOLDEN_RATIO_PRIME_32;
	return hash >> (32 - bits);
}

#define hash_long(val, bits) hash_32(val,bits)

#define hashfn(sid) \
		hash_long((unsigned long)sid, pidhash_shift)
#define pid_hashfn(x) ((((x) >> 8)^(x)) &(PIDHASH_SZ -1))

void hash_pid(struct task_struct* p)
{
	struct task_struct** htable = &pidhash[pid_hashfn(p->pid)];
	if ((p->pidhash_next = *htable) != NULL)
		(*htable)->pidhash_pprev = &p->pidhash_next;
	*htable = p;
	p->pidhash_pprev = htable;
}
void display(void)
{
	int i;
	struct task_struct* p;
	system("cls");
	for (i = 0; i < PIDHASH_SZ; i++)
	{
		printf("[%2d]", i);
		for (p = pidhash[i]; p; p = p->pidhash_next)
			printf("<->[%2d]", p->pid);
		printf("\n");
	}
}

struct task_struct* find_task_by_pid(int pid)

{
	struct task_struct* p, ** htable = &pidhash[pid_hashfn(pid)];
	for (p = *htable; p && p->pid != pid; p = p->pidhash_next);
	return p;
}

void unhash_pid(struct task_struct* p)
{
	if (p->pidhash_next)
		p->pidhash_next->pidhash_pprev = p->pidhash_pprev;
	*p->pidhash_pprev = p->pidhash_next;
}
int main()
{
	int i, pid;
	struct task_struct* p;

	srand(time(NULL));
	display();

	for (i = 0; i < 32;)
	{
		if (find_task_by_pid(pid = rand() % 100 + 1000))
			continue;
		p = (struct task_struct*)malloc(sizeof(*p));
		p->pid = pid;
		hash_pid(p);
		Sleep(500);
		display();
		i++;
	}
	getchar();
	for (i = 0; i < PIDHASH_SZ; i++)
	{
		while (p = pidhash[i]) {
			unhash_pid(p);
			free(p);
			Sleep(500);
			display();
		}
	}
return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//과제 2 미완성.
struct task_struct
{
	int pid;
	struct task_struct* pidhash_next;
	struct task_struct** pidhash_pprev;
};
#define PIDHASH_SZ (16)
struct task_struct* pidhash[PIDHASH_SZ];

typedef struct _table
{
	struct task_struct* end;
	struct task_struct* first;
}TABLE;
TABLE pidhash2[PIDHASH_SZ];

typedef unsigned int u32;
static unsigned int pidhash_shift = 3;
#define GOLDEN_RATIO_PRIME_32	0x9e370001UL //UL: unsigned long

u32 hash_32(u32 val, unsigned int bits)
{
	u32 hash = val * GOLDEN_RATIO_PRIME_32;
	return hash >> (32 - bits);
}

#define hash_long(val, bits) hash_32(val,bits)

#define hashfn(sid) \
		hash_long((unsigned long)sid, pidhash_shift)
#define pid_hashfn(x) ((((x) >> 8)^(x)) &(PIDHASH_SZ -1))

void hash_pid(struct task_struct* p)
{
	TABLE* table = &pidhash2[pid_hashfn(p->pid)];
	if ((p->pidhash_next = table->first) != NULL)
		(table->first)->pidhash_pprev = &p->pidhash_next;
	table->first = p;
	p->pidhash_pprev = &(table->first);
	if (p->pidhash_next == 0)
		table->end = p;
}
void display(void)
{
	int i;
	struct task_struct* p;
	system("cls");
	for (i = 0; i < PIDHASH_SZ; i++)
	{
		printf("[%2d]", i);
		for (p = (&pidhash2[i])->first; p; p = p->pidhash_next)
			printf("<->[%2d]", p->pid);
		printf("\n");
	}
}

struct task_struct* find_task_by_pid(int pid)
{
	struct task_struct* p;
	TABLE* htable = &pidhash2[pid_hashfn(pid)];
	for (p = htable; p && p->pid != pid; p = p->pidhash_next);
	return p;
}

void unhash_pid(struct task_struct* p)
{
	if (p->pidhash_next)
		p->pidhash_next->pidhash_pprev = p->pidhash_pprev;
	*p->pidhash_pprev = p->pidhash_next;
}

void Add_end(struct task_struct* p, int num)
//끝단에 NODE 추가 함수
{
	TABLE* htable = &pidhash2[num];

	if (htable->end == NULL)
		//랜덤으로 32개의 NODE가 붙여지는데, 특정구역에는 하나도 붙지 않는 곳이 있을수 있으므로 if문을 추가
	{
		p->pidhash_next = NULL;
		p->pidhash_pprev = &htable->first;
		htable->first = p;
		htable->end = p;
		return;
	}

	p->pidhash_next = NULL;
	p->pidhash_pprev = &htable->end->pidhash_next;
	htable->end->pidhash_next = p;
	htable->end = p;
}
void Add_first(struct task_struct* p, int num)
//첫단에 NODE 추가 함수
{
	TABLE* htable = &pidhash2[num];
	if ((p->pidhash_next = htable->first) != NULL)
		(htable->first)->pidhash_pprev = &p->pidhash_next;
	htable->first = p;
	p->pidhash_pprev = &(htable->first);

	if (p->pidhash_next == NULL)
		htable->end = p;
	if (htable->first == NULL)
		//랜덤으로 32개의 NODE가 붙여지는데, 특정구역에는 하나도 붙지 않는 곳이 있을수 있으므로 if문을 추가
	{
		p->pidhash_next = NULL;
		p->pidhash_pprev = &htable->first;
		htable->first = p;
		htable->end = p;
		return;
	}

	p->pidhash_next = NULL;
	p->pidhash_pprev = &htable->end->pidhash_next;
	htable->end->pidhash_next = p;
	htable->end = p;
}
void Del_first(int num)									//끝단의 NODE 삭제 함수
{
	struct task_struct* p;
	TABLE* htable = &pidhash2[num];

	if (pidhash2[num].first == NULL && pidhash2[num].end == NULL)
	{
		printf("\n삭제 할 (NODE)가 없습니다. 다시 입력하세요.\n");
		Sleep(1000);
		return;
	}

	p = (struct task_struct*)malloc(sizeof(*p));
	//끝단의 NODE를 복사 할 p를 생성
	p->pidhash_pprev = htable->first->pidhash_pprev;
	free(htable->first);
	//끝단의 NODE 삭제
	htable->first = p;

	if (*htable->first->pidhash_pprev == pidhash2[num].first)
		//NODE가 하나밖에 남지 않은 구역의 NODE가 삭제될때를 대비해서 if문으로 처리
	{
		pidhash2[num].first = pidhash2[num].end = NULL;
		free(p);
		return;
	}

	*htable->first->pidhash_pprev = NULL;
	htable->first = htable->first->pidhash_pprev - 1;
	free(p);											//사용하고 남은 p NODE 삭제

}
void Del_end(int num)									//끝단의 NODE 삭제 함수
{
	struct task_struct* p;
	TABLE* htable = &pidhash2[num];

	if (pidhash2[num].end == NULL && pidhash2[num].first == NULL)
	{
		printf("\n삭제 할 (NODE)가 없습니다. 다시 입력하세요.\n");
		Sleep(1000);
		return;
	}

	p = (struct task_struct*)malloc(sizeof(*p));
	//끝단의 NODE를 복사 할 p를 생성
	p->pidhash_pprev = htable->end->pidhash_pprev;
	free(htable->end);
	//끝단의 NODE 삭제
	htable->first = p;

	if (*htable->end->pidhash_pprev == pidhash2[num].end)
		//NODE가 하나밖에 남지 않은 구역의 NODE가 삭제될때를 대비해서 if문으로 처리
	{
		pidhash2[num].end = pidhash2[num].first = NULL;
		free(p);
		return;
	}

	*htable->end->pidhash_pprev = NULL;
	htable->end = htable->end->pidhash_pprev - 1;
	free(p);											//사용하고 남은 p NODE 삭제

}
int main()
{
	int i, pid;
	struct task_struct* p;

	srand(time(NULL));
	display();

	for (i = 0; i < 32;)
	{
		if (find_task_by_pid(pid = rand() % 100 + 1000))
			continue;
		p = (struct task_struct*)malloc(sizeof(*p));
		p->pid = pid;
		hash_pid(p);
		Sleep(100);
		display();
		i++;
	}
	printf("makehashend\n");
	getchar();
agin:
	while (1)
	{
		printf("Add a NODE at the (1.First 2.End), 3. Delete menu.\n");
		int num = 0, arrnum = 0;
		scanf_s("%d", &num);
		if (num == 1 || num == 2)
		{
			printf("Enter the NODE arr num.\n");
			scanf_s("%d", &arrnum);
		}

		if (find_task_by_pid(pid = rand() % 100 + 1000))
			continue;
		if (num == 1)
		{
			p = (struct task_struct*)malloc(sizeof(*p));
			p->pid = pid;
			Add_first(p, arrnum);

		}
		else if (num == 2)
		{
			p = (struct task_struct*)malloc(sizeof(*p));
			p->pid = pid;
			Add_end(p, arrnum);
		}
		else if (num == 3)
		{
			break;
		}
		else
		{
			printf("Typing again.");
			goto agin;
		}
		display();
	}

	//-------------------------Delete-----------------------
agin2:
	while (1)
	{
		printf("Delete (1.First 2.End 3.ALL).\nChoose NODE arr num.\n");
		int num2 = 0, arrnum2;
		scanf_s("%d", &num2);
		if (num2 == 1 || num2 == 2)
		{
			printf("Select NODE arr num\n");
			scanf_s("%d", &arrnum2);
		}
		if (num2 == 1)
		{
			Del_first(arrnum2);
		}
		else if (num2 == 2)
		{
			Del_end(arrnum2);
		}
		else if (num2 == 3)
		{
			break;
		}
		else
		{
			printf("Typing again.");
			goto agin2;
		}
		display();
	}
	for (i = 0; i < PIDHASH_SZ; i++)
	{
		while (p = (&pidhash2[i])->first)
		{
			unhash_pid(p);
			free(p);
			Sleep(100);
			display();
		}
	}
	return 0;
}
#endif