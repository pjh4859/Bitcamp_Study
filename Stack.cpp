#include"Stack.h"
//Stack::stack(int size=10) �̷������� �ʱⰪ�� �־��ָ� �ȵǴµ�,
//������������ �ϸ� �ȵǴ°����� Ȯ��ġ�� ����.
Stack::Stack(int size ) {
	idx = 0;
	buf = new int[size];
}
Stack::~Stack() { delete[] buf; }
void Stack:: push(int value) { buf[idx++] = value; }
int Stack::pop() { return buf[--(idx)]; }