#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	int i, j;
	int rand_num[6] = { 0,};

	srand((unsigned int) time(NULL));
	
	for (i = 0; i < 6; i++) {
		rand_num[i] = rand() % 45 + 1;
		for (j = 0; j < i; j++)	{
			if (rand_num[i]==rand_num[j]) {
				i--;
				break;
			}			
		}
		printf("[%d] ", rand_num[i]);
	}
}