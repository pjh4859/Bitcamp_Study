#if 0
#include<iostream>
#include"Position.h"

using namespace std;

Position::Position()
{
	m_nX = 0;
	m_nY = 0;
}
Position::Position(int x, int y)
{
	m_nX = x;
	m_nY = y;
}
Position::~Position()
{

}
void Position::ShowPosition()
{
	cout << "[" << m_nX << ", " << m_nY << "]" << endl;
}
Position& Position::operator++()
{
	++m_nX;
	++m_nY;
	return *this;
}
Position Position::operator++(int)
{
	cout << "후취연산" << endl;
	return *this;
}
Position Position::operator+(const Position& pos)
{
	Position temp;
	temp.m_nX = m_nX + pos.m_nX;
	temp.m_nY = m_nY + pos.m_nY;
	return temp;
}
Position Position::operator+(int a)
{
	Position temp;
	temp.m_nX = m_nX + a;
	temp.m_nY = m_nY + a;
	return temp;
}
void Position::SetValue(double a, double b)
{
	m_nX = a;
	m_nY = b;
}
Position Position::GetValue()
{
	Position temp;
	temp.m_nX = m_nX;
	temp.m_nY = m_nY;
	return temp;
}
#endif