#if 0
#include<iostream>
#include"Exception.h"
#pragma warning(disable:4996)
using namespace std;

Exception::Exception(char* name, int line,char*filename)
{
	m_pStrName = new char[strlen(name) + 1];
	strcpy(m_pStrName, name);
	m_pFileName = new char[strlen(filename) + 1];
	strcpy(m_pFileName, filename);
	m_nLine = line;
	//cout << "filename: "<<filename<<endl;
}
Exception::~Exception()
{
	delete[] m_pStrName;
}
char* Exception::GetName()
{
	return m_pStrName;
}
char* Exception::GetFileName()
{
	return m_pFileName;
}
int Exception::GetLine()
{
	return m_nLine;
}
#endif 