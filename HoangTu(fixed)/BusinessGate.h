#pragma once
#include "Gate.h"


class BusinessGate :
    public Gate
{
private:
	int value, number;
public:
	void Nhap()
	{

		cout << "Nhap don gia , so hang";
		cin >> value >> number;
	}
	int Xuat()
	{
		return value * number;
	}

	bool Check(int& mny, int intel, int& str)
	{
		if (mny > value * number)
		{

			mny -= value * number;
			return 1;
		}
		return 0;
	}
};

