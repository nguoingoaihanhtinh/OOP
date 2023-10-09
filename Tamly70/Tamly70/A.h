#pragma once
#include "yeuto.h"
class A :
    public yeuto
{
public:
	void Xuat()
	{
		yeuto::Xuat();
		cout << " - Hoa dong de chiu (A) : ";
		if (ichiso >= 70)
		{
			cout << " nguoi than thien, coi mo (doi khi thieu chinh kien) ";
		}
		else if (ichiso <= 30)
		{
			cout << " nguoi uu tien loi ich ca nhan, canh tranh ";
		}
		else cout << "khong xac dinh ";
	}
	int Nguyco()
	{
		return 0;
	}
};

