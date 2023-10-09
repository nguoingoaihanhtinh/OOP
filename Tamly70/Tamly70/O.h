#pragma once
#include "yeuto.h"
class O : public yeuto
{
public:
	void Xuat()
	{
		yeuto::Xuat();
		cout << " - San sang trai nghiem (O) : ";
		if (ichiso >= 70)
		{
			cout << " nguoi thich nhung dieu moi ";
		}
		else if (ichiso <= 30)
		{
			cout << " nguoi thich su on dinh, quen thuoc ";
		}
		else cout << "khong xac dinh ";
	}
	int Nguyco()
	{
		return 0;
	}
};

