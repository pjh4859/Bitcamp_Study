#include <stdio.h>

int main()
{
	char ch = 999;
	int i = 99999;
	double d = 99.9999;
	printf("ch's size: %d \n", sizeof(ch));
	printf("i's size: %d \n", sizeof(i));
	printf("d's size: %d \n", sizeof(d));
	printf("char's size: %d \n", sizeof(char));
	printf("int's size: %d \n", sizeof(int));
	printf("__int64's size: %d \n", sizeof(__int64));
	printf("long's size: %d \n", sizeof(long));
	printf("long long's size: %d \n", sizeof(long long));
	printf("float's size: %d \n", sizeof(float));
	printf("double's size: %d \n", sizeof(double));
	printf("long double's size: %d \n", sizeof(long double));

	/*
	int x, y, z;
	char ch,ch2;
	short s;
	x = 10;
	y = 20;
	s = 0x1234;
	ch = 254;
	ch2 = -2;
	z = x + y;

	printf("%d,%d\n", ch, ch2);
	printf("%d %d %d\n", x, y, z);
	printf("%#X %#X %#X\n", x, y, z);
	printf("%p %p %p\n", &x, &y, &z);
	*/

	int j;
	float num = -118.625;
//	for (j = 0; j < 100; j++)
	//	num += 0.1;
	printf("%f \n", num);

	   	 

	int a=13;
	int* p = &a;
	int* pp = &p;//&(&a)
	int** ppp = &p;
	int b[4] = { 1,2,3,4 };
	printf("\n\n\n%d,%d,%d\n", sizeof(a), sizeof(p), sizeof(pp));
	printf("%u,%u,%u,%u, %u\n", a,&a, &p, &pp,&ppp);
	printf("%u,%u,%u,%u,%u,%u\n", p, *p, &*p,pp,*pp,&*pp);
	printf("%u,%u,%u,%u,%u,%u\n\n", ppp, *ppp, **ppp, &**ppp, &*ppp, *(&ppp));

	printf("%d\n", sizeof(b));
	return 0;
}