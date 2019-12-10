#include <stdio.h>
#if 0
int main(void)
{
	FILE* fp;
	int ch;

	fopen_s(&fp, "D:\\Test.txt", "r");
	if (fp == NULL)
	{
		printf("No file.\n");
		return 1;
	}
	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)
		{
			break;
		}
		putchar(ch);
	}
	fclose(fp);

	return 0;
}
#endif

#if 0

int main()
{
	FILE* fp;
	char str[] = "banana";
	int i;

	fopen_s(&fp, "D:\\b.txt", "w");
	if (fp == NULL)
	{
		printf("No file.\n");
		return 1;
	}
	i = 0;
	while (str[i] != '\0')
	{
		fputc(str[i], fp);
		i++;
	}
	fputc('\n', fp);
	fclose(fp);

	return 0;
}
#endif

#if 0
int main()
{
	char ch = 'a';
	int* p = (int*)&ch;
		*(char*) p = 68;
	printf("ch: %c\n", ch);
	//윗 줄의 *p=68; 로 하면 크기가 안맞아 런타임 오류가 난다.
}

#endif

#if 0

int main()
{
	int i;
	int a[4] = { 1,2,3,4 };
	int* p1 = a;
	int (*p2)[4] = &a;

	for (i = 0; i < 4; i++)
	{
		printf("p1[%d] = %d	", i, p1[i]);
		printf("p2[%d] = %d	", i, p2[0][i]);
		printf("p2[%d] = %d	", i, (*p2)[i]);
		printf("p2[%d] = %d	", i, (&p2)[0][0][i]);
		printf("\n");

	}
	return 0;
}//저번에 했던 포인터 배열로 받아버리고 장난치기.
#endif

#if 0
int main(void)
{
	int i = 0;
	int j;
	int a[2][2] = { 1,2,3,4 };
	int** p1 = a;
	int(*p2)[2] = a;
	/*
	for (i = 0; i < 4; i++)
	{
		printf("p1[%d]=%d	\n", i, p1[i]);
	}
	*/
	
	for (i=0;i<2;i++)
		for(j=0;j<2;j++)
			//printf("p1[%d][%d]=%d	\n", i, j,p1[i]);
			printf("p2[%d][%d]=%d	\n", i, j,p2[i][j]);
		
	return 0;
}

#endif

#if 0
int main(void)
{
	int i;
	int a[] = { 0,1,2,3,4 };
	int* p[] = { a,a + 1,a + 2,a + 3,a + 4 };
	int** pp = p;

	pp++; printf("**pp = %d\n", **pp);
	*pp++; printf("**pp = %d\n", **pp);
	*++pp; printf("**pp = %d\n", **pp);
	++*pp; printf("**pp = %d\n", **pp);
	printf("%d %d %d %d %d\n", p, p + 1, p + 2, p + 3, p + 4);

	++( pp);
	printf("\n");
	printf("%d %d %d %d %d\n", a[0], a[1],a[2], a[3], a[4]);
	printf("\n");
	printf("%d %d %d %d %d\n", p, p + 1, p + 2, p + 3, p + 4);
	printf("%d %d %d %d %d\n", pp, pp + 1, pp + 2, pp + 3, pp + 4);
	pp = p;
	printf("%d %d %d %d %d\n", p, p+1,p+2,p+3,p+4);
	printf("%d %d %d %d %d\n", pp, pp + 1, pp + 2, pp + 3, pp + 4);
	printf("\n");

	printf("**pp++ = %d\n", **pp++);
	printf("**pp = %d\n", **pp);
	printf("\n");

	*++* pp; printf("**pp=%d\n", **pp);
	++** pp; printf("**pp=%d\n", **pp);
	printf("\n");

	for (i = 0; i < 5; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
	return 0;
}
#endif

#if 0
int main(void)
{
	int i,j;
	int a[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int* pa[3] = { a,a + 1,a + 2 };
	int** pp = pa;
	printf("%d %d %d", pa[0][0], pa[1][0], pa[2][0]);
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		printf("a[%d][2-%d] = %d\t", i, i, a[i][2 - i]);
		printf("(*a)[%d] = %d\t", i, (*a)[i]);
		printf("*a[%d] = %d\t", i, *a[i]);
		printf("*(*(a+%d)+%d) = %d\t", i, i, *(*(a + i) + i));
		printf("*(a[%d])+%d = %d\t", i, i, *(a[i])+i);
		printf("*(a[%d])+%d = %d\n", i, i, a[i][i]);

	}
	for (i=0;i<3;i++)
		for (j = 0; j < 3; j++)
		{
			printf("%d\t", pp[i][j]);
		}
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		printf("%d\t", pp[i][2-i]);	
		printf("%d\t", *(*(pp + i) + 2 - i));
		printf("%d\t", pp[i][0]);	
		printf("%d\n", pp[i][i]);
	}

	return 0;
}
#endif

#if 0

int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char** cp2[] = { c ,c + 1,c + 2,c+3 };

	char*** cpp = cp;
	char*** cpp2 = cp2;

	printf("%s\n",**++cpp);
	//printf("%p\n", cpp);

	printf("%s\n", *--*++cpp+3);
	printf("%s\n", *cpp[-2]+3);
	printf("%s\n", cpp[-1][-1]+1);
	printf("%s\n", cpp[0][0] + 2);
	printf("%s\n", **(cpp) + 2);


	char* p[] = { "nnnn","ttt" };
	printf("%d\n", *p[0]);
	return 0;
}
#endif

#if 0
/*
int main()
{
	static struct S1
	{
		char c[4], * s;

	}s1 = {"abc","def"};

	static struct S2
	{
		char* cp;
		struct S1 ss1;

	}s2 = { "ghi",{"jkl","mno"} };

	

	printf("(s1.c)[0]: %c\n", (s1.c)[0]);
	printf("*(s1.c)[0]: %c\n", *(s1.c));
	printf("\n\n");
	printf("s1.c: %c\n", s1.c);
	printf("s1.s: %c\n", s1.s);
	printf("s1.cp: %c\n", s1.cp);
	printf("s1.c: %c\n", s1.c);
	*/
int main(void)
{
	static struct S1
	{
		char c[4], * s;
	}s1 = { "abc","def" };

	static struct S2
	{
		char* cp;
		struct S1 ss1;
	}s2 = { "ghi",{"jk1,","mno"} };

	printf("(s1.c)[0] : %c\n", (s1.c)[0]);
	printf("(s1.c)[1] : %c\n", (s1.c)[1]);

	printf("*(s1.s) : %c\n", *(s1.s));
	printf("*(s1.s+1) : %c\n", *(s1.s+1));

	printf("\n\n");
	printf("s1.c : %s\n", s1.c);
	printf("s1.s : %s\n", s1.s);
	printf("s2.cp : %s\n", s2.cp);
	printf("(s2.ss1).s: %s\n", (s2.ss1).s);
	printf("++(s2.cp) : %s\n", ++(s2.cp));
	printf("++((s2.ss1).s: %s\n", ++((s2.ss1).s));

	return 0;
}
#endif


#if 0
struct S1
{
	char* s;
	int i;
	struct S1* slp;
};

int main()
{
	static struct S1 a[] = { {"abcd",1,a + 1},{"efgi",2,a + 2},{"ijkl",3,a} };
	struct S1* p = a;
	int i;

	printf("a[0].s : %s\n", a[0].s);
	printf("a[0].s : %d\n", a[0].i);

	printf("p->s : %s\n", p->s);
	printf("a[2].slp->s: %s\n", a[2].slp->s);

	for (i = 0; i < 2; i++)
	{
		printf("--a[%d].%d: %d\n", i, i, --a[i].i);
	}
	printf("++(p->s) : %s\n", ++(p->s));
	//p = p + 1;
	//printf("(++p->i): %d\n",  (++p)->i);

	printf("a[(++p)->i].s: %s\n",  a[(++p)->i].s);
	printf("a[--(p->slp->i)].s: %s\n", a[--(p->slp->i)].s);

	return 0;
}
#endif


#if 0
int main()
{
	int i = 10;
	int* p = &i;
	int** pp = &p;

	printf("%p %p %d %p %d\n", &i, p, *p,pp,*pp);



	return 0;
}

#endif