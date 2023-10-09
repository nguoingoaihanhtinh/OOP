#pragma once
#include "yeuto.h"
class C :
    public yeuto
{
public:
	void Xuat()
	{
		yeuto::Xuat();
		cout << " - Tu chu tan tam (C) : ";
		if (ichiso >= 70)
		{
			cout << " nguoi cham chi, chiu ap luc tot ";
		}
		else if (ichiso <= 30)
		{
			cout << " nguoi de bo cuoc, kem ky luat ";
		}
		else cout << "khong xac dinh ";
	}
	int Nguyco()
	{
		if (ichiso <= 30)
			return 1;
		return 0;
	}
};

