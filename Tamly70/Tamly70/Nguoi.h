#pragma once

#include "yeuto.h"
#include "A.h"
#include "O.h"
#include "C.h"
#include "E.h"
#include "N.h"
class Nguoi
{
	yeuto* arrOcean[5];
public:
	void Nhap()
	{
		arrOcean[0] = new O;
		arrOcean[1] = new C;
		arrOcean[2] = new E;
		arrOcean[3] = new A;
		arrOcean[4] = new N;
		for (int i = 0; i < 5; i++)
		{
			arrOcean[i]->Nhap();
		}
	}
	void Xuat()
	{
		for (int i = 0; i < 5; i++)
		{
			arrOcean[i]->Xuat();
		}
	}
	int Nguyco()
	{
		int iC = arrOcean[1]->Nguyco();
		int iE = arrOcean[2]->Nguyco();
		int iN = arrOcean[4]->Nguyco();
		if (iC == 1 || iN == 1 || (iE == 1 && iN == 1))
			return 1;
		return 0;
	}
};

