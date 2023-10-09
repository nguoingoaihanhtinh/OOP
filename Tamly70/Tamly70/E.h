#pragma once
#include "yeuto.h"
class E :
    public yeuto
{
public:
	void Xuat()
	{
		yeuto::Xuat();
		cout << " - Huong ngoai (E) : ";
		if (ichiso >= 70)
		{
			cout << " nguoi nhiet tinh, giao tiep tot ";
		}
		else if (ichiso <= 30)
		{
			cout << " nguoi ngai giao tiep, lam viec doc lap ";
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

