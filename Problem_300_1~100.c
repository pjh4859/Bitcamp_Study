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
#include<stdio.h>
#define HUNDRED_THOUSAND 100000

const int j = 200000;
main()
{
	//HUNDRED_THOUSAND = 100000;	//拭君 降持
	//j = 200000;	//拭君 降持

	printf("舛呪莫 雌呪 HUNDRED_THOUSAND税 葵精 %d\n", HUNDRED_THOUSAND);
	printf("舛呪莫 雌呪j税 葵精 %d\n", j);
}
#endif
#if 0 //018 叔呪莫 雌呪 戚背馬奄(double)
#include<stdio.h>
#define PI 3.141592

const double j = 1.23456789;

main()
{
	//PI = 3.141592; //拭君 降持
	//j = 1.23456789; //Error occured

	printf("叔呪莫 雌呪 PI税 葵精%f\n", PI);
	printf("叔呪莫 雌呪 j税 葵精%f\n", j);
}
#endif
#if 0 //019 轄軒莫 雌呪 戚背馬奄(bool)
#include<stdio.h>

#define TRUE 1
#define FALSE 0

main()
{
	if (TRUE)
	{
		printf("TRUE税 葵精 凧脊艦陥.\n");
	}
	else
	{
		printf("TRUE税 葵精 暗憎脊艦陥.\n");
	}
	if (FALSE)
	{
		printf("FALSE税 葵精 凧脊艦陥.\n");
	}
	else
	{
		printf("FALSE税 葵精 暗憎脊艦陥.\n");
	}
}
#endif

#if 0 //020 庚切伸莫 雌呪 戚背馬奄(char)
#include<stdio.h>

#define KOREA "企廃肯厩"
#define BOOK "This is a book."

const char* SOCCER = "蟹澗 逐姥研 疏焼杯艦陥.";

main()
{
	printf("庚切伸税 雌呪	KOREA税 葵:%s \n", KOREA);
	printf("庚切伸税 雌呪	 BOOK税 葵:%s \n", BOOK);
	printf("庚切伸税 雌呪  SOCCER税 葵:%s \n", SOCCER);
}

#endif

#if 0 //021 企脊 尻雌切 戚背馬奄(=)
#include<stdio.h>

main()
{
	int x = 1;
	int y = 2;
	int  z;
	int zz;

	z = x + y;

	zz = printf("z税 葵:%d\n", z);
	printf("zz税 葵:%d\n", zz);
}
#endif

#if 0 //022 採硲 尻至切 戚背馬奄(+,-)
#include<stdio.h>

main()
{
	int x = +4;
	int y = -2;

	printf("x + (-y) = %d \n", x + (-y));
	printf("-x + (+y) = %d\n", -x + (+y));
}
#endif

#if 0 //023 紫帳 尻至切 戚背馬奄(+,-,*,/)
#include<stdio.h>

main()
{
	int x = 4;
	int y = 2;
	int z;

	z = x + y;
	z = x - y;
	z = x * y;
	z = x / y;
	z = (x + y) * (x - y);
	z = (x * y) + (x / y);
	z = x + y + 2004;
	z = 2004 - x - y;
}
#endif

#if 0 //024 装姶 尻至切 戚背馬奄(++,--)
#include<stdint.h>

main()
{
	int x = 1;

	printf("x = %d\n", x++);
	printf("x = %d\n", x++);
	printf("x = %d\n", ++x);
	printf("x = %d\n", x--);
	printf("x = %d\n", x--);
	printf("x = %d\n", --x);
}
#endif

#if 0 //025 淫域 尻至切 戚背馬奄(<,>,=,>=,<=,!=)
#include<stdio.h>

main()
{
	int x = 1;
	int y = 2;
	int z = 3;

	 if(x==y)printf("x澗 y人 旭柔艦陥.\n");
	 if(x!=y)printf("x澗 y人 旭走 省柔艦陥.\n");
	 if(x>y)printf("x澗 y左陥 溺艦陥.\n");
	 if(x<y)printf("x澗 y左陥 拙柔艦陥.\n");
	 if(x>=z)printf("y澗 z左陥 滴暗蟹 旭柔艦陥.\n");
	 if(x<=z)printf("y澗 z左陥 拙暗蟹 旭柔艦陥.\n");
}

#endif

#if 0 //026 轄軒 尻至切 戚背馬奄(||,&&,!)
#include<stdio.h>

main()
{
	int x = 5;
	int y = 2;

	if (x > 0 && x < 10)
	{
		printf("0<x<10\n");
	}

	if(x<0||y==2)
	{
		printf("x亜 0左陥 拙暗蟹,y澗 2 脊艦陥.\n");
	}
	if (!(x > y))
	{
		printf("x亜y左陥 滴走 省柔艦陥.\n");
	}
}
#endif

#if 0 //027 繕闇 尻至切 戚背馬奄(?:)
#include<stdio.h>

main()
{
	int x = 1;
	int y = 2;
	int max;

	max = x > y ? x : y;
	printf("%d\n", max);
}

#endif

#if 0 //028 衆妊 尻至切 戚背馬奄(,)
#include<stdio.h>

main()
{
	int x = 1, y = 2, max;

	max = x > y ? x : y;

	printf("max=%d,x=%d,y=%d", max, x, y);
}
#endif

#if 0 //029 搾闘 尻至切 戚背馬奄 (|, &, ~, ^, <<, >>)
#include<stdio.h>

main()
{
	unsigned char ch = 255, mask = 0x7F;

	printf("%d\n",ch);
	printf("%d\n",ch&mask);
	printf("%d\n",(char)~ch);
	printf("%d\n",ch^ch);
	printf("%d\n",ch>>1);
	printf("%d\n",mask<<1);
}
#endif

#if 0 //030 蝶什闘 尻至切 戚背馬奄
#include<stdio.h>

main()
{
	int x = 5, y = 2;

	printf("%d\n", x / y);
	printf("%f\n", (double)x / y);
}

#endif
#if 0 //031 sizeof 尻至切 戚背馬奄
#include<stdio.h>

main()
{
	char i;
	int j;
	double k;
	long t;
	long long tt;
	short ttt;

	printf("%d\n", sizeof(i));
	printf("%d\n", sizeof(j));
	printf("%d\n", sizeof(k));
	printf("%d\n", sizeof(t));
	printf("%d\n", sizeof(tt));
	printf("%d\n", sizeof(ttt));
}
#endif

#if 0 //032 掻淡 繕闇庚 戚背馬奄(if~else)
#include<stdio.h>

main()
{
	int i = 1;
	int j = 2;
	int k = 7;

	if (i == 1)
	{
		if (j == 2)
		{
			if (k == 3)
				printf("i=1,j=2,k=3脊艦陥.");
			else if(k==4)
				printf("i=1,j=2,k=4脊艦陥.");
			else if (k==5)
				printf("i=1,j=2,k=5脊艦陥.");
			else
				printf("i=1,j=2,k=%d脊艦陥.",k);

				
		}
	}
}

#endif

#if 0 //033 掻淡 授発庚 戚背馬奄(fir~continue~break)
#include<stdio.h>
main()
{
	int i;
	int j;

	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			printf("%d*%d=%2d\n", i, j, i*j);
		}
	}
}

#endif
#if 0 //034 繕闇 識澱庚 戚背馬奄(switch~case~default)
#include<stdio.h>

main()
{
	int i = 5;

	switch (i)
	{
	case 1:
		printf("i澗1脊艦陥.");
		break;
	case 2:
		printf("i澗2脊艦陥.");
		break;
	default:
		printf("i澗 %d脊艦陥.", i);
		break;

	}
}
#endif
#if 0 //035 繕闇 授発庚 戚背馬奄1(while~continue~break)
#include<stdio.h>

main()
{
	int i = 1;
	int hap = 0;

	while (i <= 10)
	{
		hap = hap + i;
		i++;
	}
	printf("hap=%d", hap);
}

#endif
#if 0 //036 繕闇 授発庚 戚背馬奄2(do~while~continue~break)
#include<stdio.h>

main()
{
	int i = 1;
	int hap = 0;

	do
	{
		hap = hap + i;
		i++;
	} while (i <= 10);
	printf("hap=%d", hap);
}
#endif

#if 0 //037 巷繕闇 歳奄庚 戚背馬奄
#include<stdio.h>

main()
{
	int i;
	int j;

	for (i = 1; i <= 100; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			printf("%d*%d=%2d\n", i, j, i * j);
			if (i == 9 && j == 9)goto ku_ku_end;
		}
	}
ku_ku_end:;
}
#endif

#if 0 //038 庚切伸 戚背馬奄
#include<stdio.h>

#define ASCII_BEGIN 0
#define ASCII_END 255

main()
{
	int i;

	for (i = ASCII_BEGIN; i <= ASCII_END; i++)
	{
		printf("ASCII坪球(%3d),庚切='%c'\n", i, i);
	}
}
#endif
#if 0 //039 壕伸 戚背馬奄
#include<stdio.h>

main()
{
	int kor[10] = { 100,90,35,60,75,55,95,80,90,70 };
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("%d ", kor[i]);
	}
}
#endif

#if 0 //040 五乞軒 戚背馬奄
#include<stdio.h>

main()
{
	int i = 0;
	int j = 1;

	printf("葵=%d,五乞軒爽社=%p\n", i, &i);
	printf("葵=%d,五乞軒爽社=%p\n", j, &j);
}
#endif