#pragma once
#include "Nguoi.h"
class MangNguoi
{
	Nguoi arrNguoi[100];
	int in;
public:
	void Nhap()
	{
		cout << "Nhap so nguoi: ";
		cin >> in;
		for (int i = 0; i < in; i++)
		{
			cout << "Nhap thong tin nguoi thu " << i + 1 << ": \n";
			arrNguoi[i].Nhap();
		}
	}
	void Xuat()
	{
		int iIndex;
		cout << "Xuat chi so cua nguoi : ";
		cin >> iIndex;
		arrNguoi[iIndex - 1].Xuat();
	}
	void Nguyco()
	{
		cout << "Nguoi co nguy co rot cao: " << endl;
		for (int i = 0; i < in; i++)
		{
			if (arrNguoi[i].Nguyco() == 1)
				cout << "Nguoi " << i + 1 << endl;
		}
	}
};

