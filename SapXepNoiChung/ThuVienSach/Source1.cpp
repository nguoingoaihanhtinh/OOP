#include <iostream>
using namespace std;

class Sach
{
protected:
	string ten, nsx, ma, tinh trang;
	double dongia, soluong;
public:
	void Nhap();
	void Xuat();
	string getTen()
	{
		return ten;
	}
	string getNsx()
	{
		return nsx;
	}
	string getMa()
	{
		return ma;
	}
};