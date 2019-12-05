#include"Point002.h"

Point::Point(int a, int b) :x(a), y(b) //2. member initializer list
{
	x = a; y = b;//3. 생성자 블록 안에서 초기화
}
