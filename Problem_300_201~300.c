#if 1 //201 scanf()�Լ� 100% Ȱ���ϱ�(scanf)
#include<stdio.h>
#pragma warning(disable:4996)

#define scan(d,x,y) printf(#d "��(%"#x")�� �Է��ϼ���\n");\
					scanf(#x,&y);\
					printf("scanf%"#x":"#x"\n\n",y)

void main()
{
	char ch = 0;
	short int si = 0;
	int i = 0;
	int o8 = 0;
	int x16 = 0;
	unsigned ui = 0;
	long l = 0;
	float f = 0;
	char s[100] = { 0, };

	scan(char, %c, ch);
	scan(short, %hd, si);
	scan(int, %d, i);
	scan(unsigned, % u, ui);
	scan(long, %d, l);
	scan(8����, %o, o8);
	scan(16����, %x, x16);
	scan(�����Ҽ���, %f, f);
	scan(���ڿ�, %s, s);

	scanf("%4d%3d", &i, &o8);
	printf("%d,%d\n", i, o8);
}
#endif