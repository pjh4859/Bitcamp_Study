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

#if 1
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