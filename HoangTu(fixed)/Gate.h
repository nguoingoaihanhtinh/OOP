#pragma once
#include<iostream>
using namespace std;
class Gate
{
private:
	int mny, intel, str;
	int type;
public:
	virtual void Nhap() = 0;
	virtual int Xuat() = 0;
	int getType()
	{
		return type;
	}

	virtual bool Check(int& mny, int intel, int& str) = 0;

};

