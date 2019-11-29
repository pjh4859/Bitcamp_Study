#if 0
#include<iostream>
#include"PosList.h"
using namespace std;

#define DEFAULT_POSLEN   24

void main()
{
	double pos = 0;
	PosList <double>pl(DEFAULT_POSLEN);
	PosList <char>pl2(DEFAULT_POSLEN);
	PosList <double>pl3(DEFAULT_POSLEN);
	for (int i = 0; i < DEFAULT_POSLEN; i++)
	{
		if (!pl.SetPos(i,(pos=pos+i)*2.25))
		{
			cout << "SetPos Error: [" << i << ", " << pos*2.5 << "]" << endl;
		}
	}
	for (int i = 0; i < DEFAULT_POSLEN; i++)
	{
		if (pl.GetPos(i, pos))
		{
			cout << "Pos : [" << i << ", " << pos << "]" << endl;
		}
		else
		{
			cout << "GetPos Error: [" << i << "]" << endl;
		}
	}
}
#endif