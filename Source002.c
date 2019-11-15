
#if 0
//#include <stdio.h>//#은 전처리기
//#define SQUARE(x) x*x
/*
int printf(char * str)
{
	return 0;
}
*/
//main(__argc, __argv, _get_initial_narrow_environment())
int main(int argc,char ** argv, char ** env)// 세 번째 것은 환경변수로 cmd 에서 set 치면 나오는 것
//이걸 이용해서 OS 안의 환경변수를 받아와서 쓸 수 있다.**argv는 *argv[] 와 같다.
{

	/*
	int a;
	char c = 255;
//	scanf_s("%d", &a, 4);
//	printf("%d", a);
	printf("%d\n", c);

	char ch;
	char arr[10] = { 'a','b','c' };
	printf("%d\n", arr[3]);
	printf("%d\n", *(arr+3));
	
	printf("%d\n", SQUARE(1 + 2));
	printf("%d\n", SQUARE((1 + 2)));
	*/
	/*
	printf("hellow\n");
	printf("argc:%d\n", argc);
	printf("arcv[0]: %s\n", argv[0]);
	printf("arcv[1]: %s\n", argv[1]);
	printf("arcv[2]: %s\n", argv[2]);
	printf("arcv[3]: %s\n", argv[3]);
	printf("env[0]: %s\n", env[0]);

	int a=55;
	int* p = &a;
	int** pp = &p;
	printf("%d\n%d\n%d\n", a, p, pp);
	printf("%d\n%d\n%d\n%d\n", a, *p, *pp,**pp);
	*/
	char ch = 255;
	printf("%u\n", ch);
	printf("%d\n", ch);
	
	return 0;
}

#endif

#if 0// 0 False 일 때 그 사이에는 실행 안 함. 1 True 일 때는 실행함.

//#include <stdio.h>
#define SQUARE(x) x*x
int main()
{
	int a;
	a = SQUARE((1 + 2));
	return0;
}
#endif

#if 0
#include <stdio.h>


int main()
{
	int a = 1234;
	float f = 3.14f;
	char c = 'a';
	char buf[] = "hellom";
	char* p = "hellow";
	int* k = &a;
	*k = 10;
	buf[0] = 'k';
	//*p = 't'; 얘는 *p 가 read only 메모리 주소에 있어서 값을 바꿀 수 없음.

	printf("[%d]\n", a);
	printf("[%10d]\n", a);
	printf("[%-10d]\n", a);
	printf("[%010d]\n", a);
	printf("[%+010d]\n", a);
	printf("[%x]\n", a);//16진수
	printf("[%X]\n", a);//16진수 대문자
	printf("[0x%X]\n", a);
	printf("[%#X]\n", a);
	printf("[%#o]\n", a);
	printf("[%o]\n", a);//8진법

	printf("[%f]\n", f);
	printf("[%e]\n", f);//지수형태
	printf("[%c]\n", c);
	printf("[%s]\n", buf);
	printf("[%s]\n", p);

	printf("%d,%d\n", sizeof(buf), sizeof(*p));



	   
	return 0;
}


#endif

/*
double add(3, 4)
{

	return 3 + 4;
}
*/