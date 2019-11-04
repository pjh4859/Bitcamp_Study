#include <stdio.h>
#include <time.h>



#if 0
int main()
{
	int i = 5;
	printf("%d %d \n", i, i++);


	char ch = 'a';
	char charstr[] = "korea";
	char* str = "korea";
	char* str2 = "korea";
	str2 = charstr;
	*(charstr + 0) = 't';
	str = charstr;// 추가라인
	*(str + 0) = 'y';//얘는 안됨. 하지만 추가라인 을 추가하면 됨.
	charstr[1] = ch;
	str = &ch;
	*str2 = &ch;

	printf("charstr: %s\n",charstr);
	printf("str: %s\n", str);
	printf("str2: %s\n", str2);

	printf("%d\n", sizeof(str));

	return 0;
}

#endif

#if 0

#define ser 1000
#define ser (int*)1000

int CalcSum(int* score, int len)
{
	int i = 0, sum = 0;
	for (i = 0; i < len; i++)
		sum += score[i];
	return sum;
}


int main()
{
	/*
	int ch3;
	int ch2;
	ch3 = (int*)1000;
	ch2 = ser;

	int sum = 0;
	int a = 0x00aa00aa, b = 0x55005500;
	int* ptrSum = &sum;
	int* ptrA = &a, * ptrB = &b;
	printf("주소: %p, %p, %p\n", &sum, &a, &b);
	printf("주소: %p, %p, %p\n", ptrSum, ptrA, ptrB);
	*ptrSum = *(char*)ptrA + *(char*)ptrB;
	printf("%#x = %#x + %#x\n", sum, a, b);
	printf("%#x = %#x + %#x\n", (unsigned char)sum, a, b);
	printf("\n");


	int i = 0;
	int korean[5] = { 96,97,98,99,100 };
	long long* ptr = korean;
	printf("%d %d\n", sizeof(long long), sizeof(long));
	printf("ptr[1]: %ld\n", *(int *)ptr+1);
	printf("ptr[1]: %ld\n", *(char*)ptr + 1);
	printf("ptr[1]: %ld\n", *(long*)ptr + 1);
	printf("%p\n",korean);
	printf("%p\n", korean);
	for (i = 0; i < 5; i++)
		printf("%d, ", korean[i]);
	printf("\n");
	for (i = 0; i < 5; i++)
		printf("%p, ", korean + i);
	printf("\n");
	for (i = 0; i < 5; i++)
		printf("%d, ", *(korean + i));
	printf("\n");
	printf("%p,\n",(char*)korean+i);
	*/

	int korean[5] = { 96,97,98,99,100 };
	int sum = 0;
	sum = CalcSum(korean, 5);
	printf("총합은 %d\n", sum);


	return 0;
}
#endif

	

#if 0


void swap(int *a, int *b)
{
	/*
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	*/
	/*
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
	*/
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;

	printf("%d, %d\n", *a, *b);

}
int main()
{
	clock_t start, end;
	start = clock();
	int num1 = 10, num2 = 20;
	int* p = &num1, * p2 = &num2;
	printf("%d, %d\n", &num1, &num2);

	swap(p, p2);
	printf("%d, %d\n", &num1,&num2);
	printf("%d, %d\n", num1, num2);
	end = clock();
	printf("elapse time : %f", (double)(end - start) / CLOCKS_PER_SEC);


	return 0;
}

#endif

#if 1
int main()
{
	int i = 0, j = 0, cnt = 0;
	int korean[3][5];

	//int* ptr = (int*)korean;
	int* ptr = &korean[0][0];
	int(*ptr2)[5] = korean; 
	int** ptr3 = korean;
	

	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			korean[i][j] = 86 + cnt++;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			printf("%d, ", ptr3[i][j]);
	printf("\n");

	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			printf("%d, ", ptr2[i][j]);
	printf("\n");

	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			printf("%d, ", korean[i][j]);
	printf("\n");
	for (i = 0; i < 3 * 5; i++)
		printf("%d, ", ptr[i]);
	printf("\n");
	

	printf("%d %d %d\n", sizeof(korean[0][0]), sizeof(korean[0]), sizeof(korean));

	return 0;
}

#endif