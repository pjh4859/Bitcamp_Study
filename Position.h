#if 0
#pragma once
class Position
{
private:
	int m_nX;
	int m_nY;
public:
	Position();
	Position(int x, int y);
	~Position();
public:
	void ShowPosition();
	Position& operator++();//����
	Position operator++(int);//����
	Position operator+(const Position& pos);
	Position operator+(int a);
	void SetValue(double a, double b);
	Position GetValue();
};
#endif