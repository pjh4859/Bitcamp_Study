#include <stdio.h>
#include <stdlib.h>


#if 0
int main()
{
	int *pi;
	double* pd;

	pi = (int*)malloc(sizeof(int));
	if (pi == NULL)
	{
		printf("# Out of Memories.\n");
		exit(1);
	}
	pd = (double*)malloc(sizeof(double));
	if (pd == NULL)
	{
		printf("# Out of Memories.\n");
		exit(1);
	}
	*pi = 10;
	*pd = 3.4;

	printf("Using by integer : %d\n", *pi);
	printf("Using by double : %.1lf\n", *pd);

	free(pi);
	free(pd);

	return 0;
}

#endif





#if 0

void KorPresentation()
{
	printf("정수를입력하세요: ");
}
void EngPresentation()
{
	printf("Input Integer: ");
}
int InputValue(void (*presentation)())
{
	int a;
	presentation();
	scanf_s("%d", &a);
	return a;
}

int main(void)
{
	
	int 하;
	int k;
	int* p = &k;
	int korea[3][4];
	int(*pp)[3][4] = &korea;

	int(*ppp)[4] = korea;
	int(*pppp)[4] = &korea[0];
	int(*ppppp) = korea[0];
	int(*pppppp) = &korea[0][0];
	//써놨음.
	//()()
	//(..)
	//(><)*
	int korean = 96, math = 99, eng = 90;
	int* ptr[3] = { &korean, &math, &eng };
	int i = 0;
	for (i = 0; i < 3; i++)
		printf("%d, ", *ptr[i]);
	printf("\n");
	char* subject[3] = { "korean","math","eng" };
	for (i = 0; i < 3; i++)
		printf("%s, ", subject[i]);
	printf("\n");
	


	int value = 0;
	int flag = 0;
	while (1)
	{
		printf("language select(1.kor 2.eng 3.Exit): ");
		scanf_s("%d,", &flag);
		switch (flag)
		{
		case 1:
			value = InputValue(KorPresentation);
			break;
		case 2:
			value = InputValue(EngPresentation);
			break;
		case 3:
			goto END;
		}
		printf("input value: %d\n", value);
	}
END:
	return 0;
}


#endif



#if 0

//int data[3];
//#typedef int(*Fp)[2];
int(* input())[2]
{
	static int data[2][2];
	int* p =(int*) data;
	printf("값 네개 입력: ");
	//scanf_s("%d %d %d %d", data, data + 1, data + 2, data+3);
	//scanf_s("%d %d %d %d", p, p + 1, p + 2, p + 3);
	scanf_s("%d %d %d %d", data[0], data[0] + 1, data[1], data[1] + 1);


	return data;
}
int print(int* data)
{	
	printf("%d %d %d %d\n", data[0], data[1], data[2], data[3]);
}

int main(void)
{
	int* data;
	data = input();
	print(data);
	return 0;
}

#endif

#if 0
#define PTR_NUM 5

int main()
{
	char ans = 0;
	int i = 0, j = 0, alocCnt = PTR_NUM;
	int* k;
	int* ptr = (int*)malloc(sizeof(int) * PTR_NUM);
//	int* ptr2 = (int*)malloc(sizeof(int) * PTR_NUM);
	k = (int*)realloc(NULL, sizeof(int) *  PTR_NUM);

	while (i < alocCnt)
	{
		printf("Input Num: ");
		//scanf_s("%d", &ptr[i]);
		scanf_s("%d", ptr+i);
		i++;
		if (i == alocCnt)
		{
			//fflush(stdin);
			getchar();
			printf("Memory Full \n");
			printf("Are you sure you want to reallocation?\nEnter 'Y'(Yes) or 'N'(No).\n");
			//getchar();
			ans = getchar();
			if (ans == 'Y' || ans == 'y')
				//ptr2 = (int*)malloc(ptr2, sizeof(int) * (alocCnt += PTR_NUM));
				ptr = (int*)realloc(ptr, sizeof(int) * (alocCnt += PTR_NUM));
			else if(ans == 'N' || ans == 'n')
				for (j = 0; j < alocCnt; j++)
					printf("%d, ", ptr[j]);
			else
				printf("Invalid Input\n");
		}
	}
	free(ptr);
	return 0;
}


#endif

#if 1

int main()
{
	//int 하;
	int k;
	int* p = &k;
	int korea[3][4] = { {1,2,3,3},{4,5,6,6},{7,8,9,9} };
	int korea2[2][3][4] = {0};

	int arr[4];
	int* t = &arr;
	int* t2 = arr;

	printf("%d %d %d %d\n\n", arr, arr + 1, &arr, &arr + 1);
	

	int(*p2)[3][4] = &korea;
	//int(*p22)[3][4] = korea;

	int(*p3)[4] = korea;
	int(*p4)[4] = &korea[0];
	int(*p5) = korea[2];
	int(*p6) = &korea[1][0];

	printf("ko: %d  %d  %d  %d\n",korea, korea +1, korea[0]+1,korea[0][0]);
	printf("ko2: %d  %d  %d  %d  %d\n", korea2, korea2 + 1, korea2[0] + 1, korea2[0][0]+1,korea2[0][0][0]);

	printf("p2: %d  %d  %d  %d  %d\n", p2, p2 + 1, p2[0] + 1, p2[0][0]+1, p2[0][1][3]);
	//printf("p22: %d  %d  %d  %d  %d\n", p22, p22 + 1, p22[0] + 1, p22[0][0], p22[0][1][2]);
	printf("p3: %d  %d  %d  %d  %d\n", p3, p3 + 1, p3[0] + 1, p3[1][0], p3[1][1]);
	printf("p4: %d  %d  %d  %d  %d\n", p4, p4 + 1, p4[0] + 1, p4[0][0], p4[0][1]);
	printf("p5: %d  %d  %d  %d  %d\n", p5, p5 + 1, p5[0] + 1, p5[0], p5[0]+1);
	printf("p6: %d  %d  %d  %d  %d\n", p6, p6 + 1, p6[0] + 1, p6[0], p6[0]+1);



	//써놨음.
	//()()
	//(..)
	//(><)*
	int korean = 96, math = 99, eng = 90;
	int* ptr[3] = { &korean, &math, &eng };
	int i = 0;
	for (i = 0; i < 3; i++)
		printf("%d, ", *ptr[i]);
	printf("\n");
	char* subject[3] = { "korean","math","eng" };
	for (i = 0; i < 3; i++)
		printf("%s, ", subject[i]);
	printf("\n");

	return 0;
}

#endif