#if 0
#include<iostream>
#include"Exception.h"

using namespace std;

void Divide(double dividend, double divider, double& result)
{
	if (divider == 0)
		throw Exception((char*)"Divide()", __LINE__,(char*)__FILE__);
	result = dividend / divider;
}
void main()
{
	double num1=0.0, num2=0.0, result=0.0
		;
	char Name[100];

	cout << "A/B 를 연산할 2개의 수 입력 : ";
	cin >> num1 >> num2;

	try
	{
		Divide(num1, num2, result);
		cout << num1 << "/" << num2 << "=" << result << endl;
	}
	catch (Exception & e)
	{
		cout << "Exception : " << e.GetName() <<"Filename :"<<e.GetFileName()<< ", Line :" << e.GetLine() << endl;
	}
}
#endif