#include <iostream>
using namespace std;

class DichVu {
protected:
	string name;
	string CCCD;
public:
	virtual void Nhap()
	{
		cout << "Nhap vao ten va CCCD: ";
		cin >> name >> CCCD;
		cout << "\n";
	}
	virtual long Tien()
	{
		return 0;
	}
	virtual void Xuat()
	{
		cout << name << " " << CCCD;
	}
};
class NonMember : public DichVu {
protected:
	long price = 200;
	long pt = 200;
	long thanhtien = 0;
	int time = 0;
public:
	void Nhap()
	{
		DichVu::Nhap();
		cout << "\nThoi gian su dung: "; cin >> time;
	}
	long Tien()
	{
		thanhtien = (price + pt) * time;
		return thanhtien;
	}
	void Xuat()
	{
		DichVu::Xuat();
	}
};
class Basic : public DichVu {
protected:
	long price = 500;
	long ccost = 100;
	int solop = 0;
	long pt = 100;
	long thanhtien = 0;
	int time = 0;
public:
	void Nhap()
	{
		DichVu::Nhap();
		cout << "So lop hoc : "; cin >> solop;
		cout << "\nThoi gian su dung: "; cin >> time;
	}
	long Tien()
	{
		thanhtien = (price + ccost * solop + pt) * time;
		return thanhtien;
	}
	void Xuat()
	{
		DichVu::Xuat();
	}
};
class Premium : public DichVu
{
protected:
	long price = 1000;
	long ccost = 0;
	int solop = 0;
	long spa = 0;
	long pt = 0;
	long thanhtien = 0;
	int time = 0;
public:
	void Nhap()
	{
		DichVu::Nhap();
		cout << "Nhap so lop: "; cin >> solop;
		cout << "\nThoi gian su dung: "; cin >> time;
	}
	long Tien()
	{
		thanhtien = (price + ccost * solop + pt + spa) * time;
		return thanhtien;
	}
	void Xuat()
	{
		DichVu::Xuat();
	}
};

class Gym {
private:
	int n;
	DichVu* arrGym[100];
public:
	DichVu* init(int type)
	{
		switch (type)
		{
		case 1: return new NonMember;
		case 2: return new Basic;
		case 3: return new Premium;
		}
	}
	void Nhap()
	{
		cout << "Nhap so luong khach: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Nhap dich vu mong muon: \n";
			cout << "1.Non Membership \n";
			cout << "2.Basic Membership \n";
			cout << "3.Premium Membership \n";
			int loai; cin >> loai;
			arrGym[i] = init(loai);
			arrGym[i]->Nhap();
		}
	}
	DichVu* thanh_tien_max()
	{
		long max = 0;
		for (int i = 0; i < n; i++)
		{
			if (arrGym[i]->Tien() > arrGym[max]->Tien())
				max = i;
		}
		return arrGym[max];
	}
	void Xuat()
	{
		for (int i = 0; i < n; i++)
		{
			arrGym[i]->Xuat();
			cout << endl;
		}
	}
	void XuatPhuBa(DichVu* phuba)
	{
		phuba->Xuat();
	}
	
};

int main()
{
	Gym gym;
	gym.Nhap();
	gym.Xuat();
	cout << "Khach hang chi tieu nhieu nhat la: ";
	gym.XuatPhuBa(gym.thanh_tien_max());
}