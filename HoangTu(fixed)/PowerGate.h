#pragma once
#include "Gate.h"
class PowerGate :
    public Gate
{
private:
	int dstr;
public:
	void Nhap()
	{

		cout << "Nhap suc manh dung si "; cin >> dstr;
	}
	int Xuat()
	{
		return dstr;
	}
	bool Check(int& mny, int intel, int& str)
	{
		if (str > dstr)
		{
			str -= dstr;
			return 1;
		}
		return 0;
	}

};

