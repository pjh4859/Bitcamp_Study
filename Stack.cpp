#include"Stack.h"
//Stack::stack(int size=10) 이런식으로 초기값을 넣어주면 안되는데,
//분할컴파일을 하면 안되는것인지 확실치는 않음.
Stack::Stack(int size ) {
	idx = 0;
	buf = new int[size];
}
Stack::~Stack() { delete[] buf; }
void Stack:: push(int value) { buf[idx++] = value; }
int Stack::pop() { return buf[--(idx)]; }