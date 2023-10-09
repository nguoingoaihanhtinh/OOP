#pragma once
#include "yeuto.h"
class N :
    public yeuto
{
public:
	void Xuat()
	{
		yeuto::Xuat();
		cout << " - Bat on cam xuc (N) : ";
		if (ichiso >= 70)
		{
			cout << " nguoi co nhung cam xuc tieu cuc ";
		}
		else if (ichiso <= 30)
		{
			cout << " nguoi biet kiem soat cam xuc ";
		}
		else cout << "khong xac dinh ";
	}
	int Nguyco()
	{
		if (ichiso >= 70)
			return 1;
		return 0;
	}
};

