#include <stdio.h>




#if 0 //001 C 覗稽益轡 獣拙馬奄.
int main()
{
	printf("照括馬疾.");
}
#endif

#if 0 //002 痕呪莫 鯵割 壕酔奄.
int main()
{
	int びびびllびIIII;
	int x;
	int y;
	int z;

	びびびllびIIII = 20;
	x = 1;
	y = 2;

	z = x + y;

	printf("%d %d",z, びびびllびIIII);
}
#endif

#if 0 //003 雌呪莫 鯵割 壕酔奄.

#define X 1
#define PI 3.141592

int main()
{
	double z;

	z = X + PI;
	printf("%f", z);
}
#endif

#if 0 //004 尻至切 鯵割 壕酔奄.
main()
{
	int x;
	int y;
	x = 10;
	y = x - 5;
	if (x > y)
	{
		printf("x亜 y左陥 溺艦陥.");
	}
	else
	{
		printf("y亜 x人 旭暗蟹 拙柔艦陥.");
	}
}

#endif

#if 0//005 繕闇庚 鯵割 壕酔奄 (if~else).
main()
{
	int x;
	int y;

	x = 20;
	y = 10;

	if (x > y)
		printf("x value is bigger than y.");
	else
		printf("y value is bigger or same than x.");

}

#endif

#if 0 //006 授発庚 鯵割 壕酔奄(for).
main()
{
	int i;
	int hap = 0;

	for (i = 0; i <= 10; i = i + 1)
	{
		hap = hap + i;
	}
	printf("1採斗 10猿走税 杯: %d", hap);
}
#endif

#if 0 //007 庚切伸 鯵割 壕酔奄.
main()
{
	printf("企廃肯厩");	
}
#endif

#if 0 //009 敗呪 鯵割 壕酔奄.
int hapf(int value);

main()
{
	printf("1採斗 10猿走税 杯精 %d \n", hapf(10));
	printf("1採斗 100猿走税 杯精 %d \n", hapf(100));
	printf("1採斗 1000猿走税 杯精 %d \n", hapf(1000));
}
int hapf(int value)
{
	int i;
	int hap = 0;

	for (i = 0; i <= value; i = i + 1)
	{
		hap = hap + i;
	}
	return hap;
}
#endif

#if 0 //010 爽汐 鯵割 壕酔奄.
main()
{
	int i;	//舛呪莫 痕呪 i研 舛税杯艦陥.
	int hap = 0;  //舛呪莫 痕呪 hap 聖 舛税馬壱 0生稽 段奄鉢杯艦陥.

	/*
	for 庚精 陥製坦軍 叔楳桔艦陥.

	1.i=0生稽 獣拙杯艦陥.び
	2.i亜 10左陥 拙暗蟹 旭聖凶猿走 鋼差杯艦陥.
	3.薄仙税 hap葵拭 i研 希馬食 hap 拭 企脊.
	4.i澗 1梢 装亜杯艦陥.
	*/

	for (i = 0; i <= 10; i = i + 1)
	{
		hap = hap + i;
	}
	printf("%d", hap);
}
#endif

#if 0 //011 庚切莫 痕呪 戚背馬奄(char).
main()
{
	char ch;
	unsigned char j;
	char k;

	ch = 200;
	j = 200;
	k = 'a';

	printf("庚切莫 痕呪 ch税 葵精 %d\n", ch);
	printf("庚切莫 痕呪 j税 葵精 %d\n", j);
	printf("庚切莫 痕呪 k税 葵精 %d\n", k);
}
#endif

#if 0 //012 舛呪莫 痕呪 戚背馬奄(int).
main()
{
	int i;
	unsigned int j;
	int k;

	i = 2000000000;
	j = 4000000000;
	k = 'b';

	printf("舛呪莫 痕呪 i税 葵精 %d\n", i);
	printf("舛呪莫 痕呪 j税 葵精 %u\n", j);
	printf("舛呪莫 痕呪 k税 葵精 %d\n", k);
}
#endif

#if 0 //013 叔呪莫 痕呪 戚背馬奄(double).
main()
{
	float d;
	double d1;
	double d2;

	d = 3.141592;
	d1 = 1234567890;
	d2 = 'c';

	printf("叔呪莫 痕呪 d税 葵精 %E\n", d);
	printf("叔呪莫 痕呪 d1税 葵精 %E\n", d1);
	printf("叔呪莫 痕呪 d2税 葵精 %E\n", d2);
}
#endif

#if 0 // 014 轄軒莫 痕呪 戚背馬奄(bool).
main()
{
	int b;
	int j;

	b = 10 > 5;
	j = 10 > 20;

	printf("轄軒莫 痕呪 b税 葵精 %d\n", b);
	printf("轄軒莫 痕呪 j税 葵精 %d\n", j);

	if (b) //凧
	{
		printf("10>5税 縦精 凧脊艦陥.\n");
	}
	else
	{
		printf("10>5税 縦精 暗憎脊艦陥.\n");
	}
	if (j) //暗憎
	{
		printf("10>20税 縦精 凧脊艦陥.\n");
	}
	else
	{
		printf("10>20税 縦精 暗憎脊艦陥.\n");
	}
	if (-1) //凧
	{
		printf("-1精 凧脊艦陥.\n");
	}
	else
	{
		printf("-1精 暗憎脊艦陥.\n");
	}
}
#endif

#if 0 //015 庚切伸莫 痕呪 戚背馬奄(char*).
main()
{	char str[] = "企廃肯厩";
	char* j = "I love Korea";

	printf("庚切伸莫 痕呪 str税 葵精 %s\n", str);
	printf("庚切伸莫 痕呪 j税 葵精 %s\n", j);
}

#endif

#if 0 //016 庚切莫 雌呪 戚背馬奄(char)

#define HUNDRED 100
const char j = 10;
main()
{
	HUNDRED = 200;	//拭君 降持
	j = 200;		//拭君 降持

	printf("庚切莫 雌呪 HUNDRED税 葵精 %d\n", HUNDRED);
	printf("庚切莫 雌呪 j税 葵精 %d\n", j);

}
#endif

#if 0 //017 舛呪莫 雌呪 戚背馬奄(int)

main()
{
	int i, j;
	int a[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
	int* p = a;
	int* p2 = a[0];
	int(* p3)[5] = a;
	int* p4 = &a;
	int(* p5)[3][5] = &a;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("%d %d %d %d %d\n", p, p2,p3, p4,p5);
	printf("%d %d %d %d %d\n", sizeof(p), sizeof(p2), sizeof(p3), sizeof(p4), sizeof(p5));
	printf("%d %d %d %d %d\n", (p), (p2), p3,(p4),p5);
	printf("%d %d %d %d %d\n", (p+1), (p2+1),(p3+1), (p4+1),(p5+1));
}
#endif

#if 0 //017 舛呪莫 雌呪 戚背馬奄(int)

main()
{
	
}
#endif
