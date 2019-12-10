#pragma once
struct Stack
{
private:
	int* buf;
	int idx;
public:
	Stack(int size = 10);
	~Stack();
	void push(int value);
	int pop();
};