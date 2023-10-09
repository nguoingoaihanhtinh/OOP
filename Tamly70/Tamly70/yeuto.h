#pragma once
#include <iostream>
using namespace std;
class yeuto
{
protected:
	int ichiso;
public:
	void Nhap()
	{
		cout << "nhap chi so: ";
		cin >> ichiso;
	}
	virtual void Xuat()
	{
		cout << endl;
		cout << ichiso << " ";
	}
	virtual int Nguyco()
	{
		return 0;
	}
};

