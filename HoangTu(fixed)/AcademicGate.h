#pragma once
#include "Gate.h"
class AcademicGate :
    public Gate
{
private:
	int baseintel;
public:
	void Nhap()
	{

		cout << "Nhap tri tue cau hoi "; cin >> baseintel;
	}
	int Xuat()
	{
		return baseintel;
	}

	bool Check(int& mny, int intel, int& str)
	{
		if (intel > baseintel)
		{
			return 1;
		}
		return 0;

	}
};

