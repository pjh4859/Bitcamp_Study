#if 0

#include <stdio.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)
struct task_struct
{
	int pid;
	struct task_struct* pidhash_next;
	struct task_struct** pidhash_pprev;
};

typedef struct TABLE
{
	struct task_struct* end;
	struct task_struct* next;
}TABLE;

#define PIDHASH_SZ	(16)

TABLE jump[PIDHASH_SZ];

//struct task_struct* pidhash[PIDHASH_SZ];    // TASK* pidhash[16]

typedef unsigned int u32;
static unsigned int pidhash_shift = 3;

#define GOLDEN_RATIO_PRIME_32	0x9e370001UL

u32 hash_32(u32 val, unsigned int bits)
{
	u32 hash = val * GOLDEN_RATIO_PRIME_32;
	return hash >> (32 - bits);
}

#define hash_long(val, bits)	hash_32(val,bits)

#define hashfn(sid)	\
			hash_long((unsigned long)sid, pidhash_shift)

#define pid_hashfn(x)	((((x) >> 8) ^ (x)) &(PIDHASH_SZ - 1))
//		&(16-1)

void hash_pid(struct task_struct* p)
{
	//struct task_struct** htable = &pidhash[pid_hashfn(p->pid)];
	TABLE* htable = &jump[pid_hashfn(p->pid)];
	if ((p->pidhash_next = htable->next) != NULL)
		(htable->next)->pidhash_pprev = &p->pidhash_next;
	htable->next = p;
	p->pidhash_pprev = &(htable->next);
	if (p->pidhash_next == NULL)
		htable->end = p;
}

void display(void)
{
	int i;
	struct task_struct* p;
	system("cls");
	for (i = 0; i < PIDHASH_SZ; i++)  // ( ; i < 16; i++ )
	{
		printf("[%2d]", i);
		for (p = &jump[i]; p; p = p->pidhash_next)
			printf("<->[%2d]", p->pid);
		printf("\n");
	}
}

void jump_add(struct task_struct* p, int num)			//���ܿ� NODE �߰� �Լ�
{
	TABLE* htable = &jump[num];

	if (htable->end == NULL)							//�������� 32���� NODE�� �ٿ����µ�, Ư���������� �ϳ��� ���� �ʴ� ���� ������ �����Ƿ� if���� �߰�
	{
		p->pidhash_next = NULL;
		p->pidhash_pprev = &htable->next;
		htable->next = p;
		htable->end = p;
		return;
	}

	p->pidhash_next = NULL;
	p->pidhash_pprev = &htable->end->pidhash_next;
	htable->end->pidhash_next = p;
	htable->end = p;
}

void jump_del(int num)									//������ NODE ���� �Լ�
{
	struct task_struct* p;
	TABLE* htable = &jump[num];

	if (jump[num].end == NULL && jump[num].next == NULL)
	{
		printf("\n���� �� (NODE)�� �����ϴ�. �ٽ� �Է��ϼ���.\n");
		Sleep(2000);
		return;
	}

	p = (struct task_struct*)malloc(sizeof(*p));		//������ NODE�� ���� �� p�� ����
	p->pidhash_pprev = htable->end->pidhash_pprev;
	free(htable->end);									//������ NODE ����
	htable->end = p;

	if (*htable->end->pidhash_pprev == jump[num].next)	//NODE�� �ϳ��ۿ� ���� ���� ������ NODE�� �����ɶ��� ����ؼ� if������ ó��
	{
		jump[num].end = jump[num].next = NULL;
		free(p);
		return;
	}

	*htable->end->pidhash_pprev = NULL;
	htable->end = htable->end->pidhash_pprev - 1;
	free(p);											//����ϰ� ���� p NODE ����

}

struct task_struct* find_task_by_pid(int pid)
{
	struct task_struct* p;
	TABLE* htable = &jump[pid_hashfn(pid)];				//���� �ߺ� ����				// &jump[PIDHASH_SZ];		// &pidhash[pid_hashfn(pid)];
	for (p = htable; p && p->pid != pid; p = p->pidhash_next);
	return p;
}

//void unhash_pid(struct task_struct* p)
//{
//	if (p->pidhash_next)
//		p->pidhash_next->pidhash_pprev = p->pidhash_pprev;
//	*p->pidhash_pprev = p->pidhash_next;
//}

int main()
{
	int i, pid;
	struct task_struct* p;
	int num;

	srand(time(NULL));
	display();

	for (i = 0; i < 32; )
	{
		if (find_task_by_pid(pid = rand() % 100 + 1000))		// pid = 1000~1099
			continue;
		p = (struct task_struct*)malloc(sizeof(*p));
		p->pid = pid;
		hash_pid(p);
	//	Sleep(500);
		display();
		i++;
	}

	getchar();

	while (1)
	{
	re:
		printf("\n(NODE) �߰� -> 1\n(NODE) ���� -> 2\n��ȣ �Է� : ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			printf("\n(NODE)�� �߰��ϰ� ���� ���� ��ȣ �Է� (NODE �߰� ���� : 99) : ");
			scanf("%d", &num);
			if (num == 99)
				goto re;

		go:
			if (find_task_by_pid(pid = rand() % 100 + 1000))		// pid = 1000~1099
				goto go;
			p = (struct task_struct*)malloc(sizeof(*p));
			p->pid = pid;

			jump_add(p, num);
			display();
			break;

		case 2:
			printf("\n(NODE)�� �����ϰ� ���� ���� ��ȣ �Է� (NODE ���� ���� : 99) : ");
			scanf("%d", &num);
			if (num == 99)
				goto re;

			jump_del(num);		//(struct task_struct* p, int num)
			display();
			break;
		}
		printf("\n");
		//	printf("\n���α׷��� �����Ͻðڽ��ϱ�? (YES : 1, NO : 2) : ");
		//	scanf("%d", &num);
		//	if (num == 1)
		//		break;
	}


	//	for (i = 0; i < PIDHASH_SZ; i++)		// ( ; i < 16; )
	//	{
	//		while (p = pidhash[i])
	//		{
	//		//	unhash_pid(p);
	//			free(p);
	//			Sleep(500);
	//			display();
	//		}
	//	}

	return 0;
}
#endif