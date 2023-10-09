#include <iostream>
using namespace std;

class Thanhphan {
protected:
	string text = " ";
	int tcolor = 0;
	int bcolor = 0;
public:
	Thanhphan()
	{}
	~Thanhphan()
	{}
	virtual void Nhap()
	{
		cout << "Bang mau: " << endl;
		cout << "1.Red - 2.Orange - 3.Yellow - 4.SpringGreen \n";
		cout << "5.Green - 6.Turquoise - 7.Cyan - 8.Ocean \n";
		cout << "9.Blue - 10.Violet - 11.Magenta - 12.Raspberry \n";
		cout << "Chon mau nen: "; cin >> bcolor;
		cout << "\n";
		cout << "Chon mau chu: "; cin >> tcolor;
		cout << "\n";
	}
	virtual int getTextColor()
	{
		return tcolor;
	}
	virtual int getBaseColor()
	{
		return bcolor;
	}
};
class Label : public Thanhphan {
public:
	void Xuat() {
		cout << "Nhap label: " << endl;
		Thanhphan::Nhap();
	}
};
class Button : public Thanhphan {
public:
	void Nhap()
	{
		cout << "Nhap button: " << endl;
		cout << "1.Image - 2.Text \n";
		int tl; cin >> tl;
		if (tl == 1)
		{
			text = " ";
			bcolor = 0;
			tcolor = 0;
		}
		else
		{
			Thanhphan::Nhap();
		}
	}
};

bool maubotuc(int x, int y)
{
	return abs(x - y) == 6;
}
bool mautuongdong(int x, int y, int z)
{
	int data[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,1,2 };
	return (data[x + 1] == y && data[x + 2] == z);
}
int main()
{
	Thanhphan* ds[100];
	int n; cout << "Nhap so luong thanh phan: ";
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		cout << "Chon 1: Nhap Label\nChon 2: Nhap button\n";
		int tl;
		cin >> tl;
		if (tl == 1)
			ds[i] = new Label();
		else
			ds[i] = new Button();
		ds[i]->Nhap();
		cout << endl << endl;
	}
	//cau b
	if (maubotuc(ds[0]->getBaseColor(), ds[0]->getTextColor()))
		cout << "Thanh phan dau tien la mau bo tuc!\n";
	else
		cout << "Thanh phan dau tien Khong la mau bo tuc!\n";

	//cau c
	int dd[13];
	for (int i = 0; i <= 12; i++)
		dd[i] = 0;
	for (int i = 0; i < n; i++)
		dd[ds[i]->getBaseColor()]++;

	int spt = 0;
	int mau[13];
	for (int i = 1; i <= 12; i++)
		if (dd[i] != 0)
			mau[spt++] = i;
	cout << "Mau nen cac thanh phan: ";
	if (spt == 1)
		cout << "Theo nguyen tac: mau don sac\n";
	else
		if (spt == 2 && maubotuc(mau[0], mau[1]))
			cout << "Theo nguyen tac: Mau bo tuc\n";
		else
			if (spt == 3 && mautuongdong(mau[0], mau[1], mau[2]))
				cout << "Theo nguyen tac: Mau tuong dong\n";
			else
				cout << "Khong theo nguyen tac nao!\n";
	return 0;
}