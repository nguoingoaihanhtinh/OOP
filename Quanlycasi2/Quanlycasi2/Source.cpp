#include <iostream>
#include <string>
using namespace std;

class Casi {
protected:
	string name = " ";
	int yearworking = 0;
	int CDs = 0;
	int Stages = 0;
public:
	Casi() {};
	~Casi() {};
	virtual void Nhap()
	{
		cout << "Nhap ten, nam lam viec, so dia ban, so buoi trinh dien: ";
		cin >> name >> yearworking >> CDs >> Stages;
	}
	virtual void Xuat()
	{
		cout << name << yearworking << CDs << Stages << endl;
	}

	virtual long Luong() {
		return 0; 
	};
};
class NoiTieng : public Casi {
private: 
	int gShows;
	long salary;
public:
	void Nhap()
	{
		Casi::Nhap();
		cout << "nhap so gameshow tham gia: ";
		cin >> gShows;
	}
	long Luong()
	{
		salary = 5000000 + 500000 * yearworking + 1200 * CDs + 500000 * Stages + 500000 * gShows;
		return salary;
	}
	void Xuat()
	{
		Casi::Xuat();
		cout << Luong();
	}
};
class ChuaNoi : public Casi {
private: 
	long salary;
public:
	void Nhap()
	{
		Casi::Nhap();
	}
	long Luong()
	{
		salary = 3000000 + 500000 * yearworking + 1000 * CDs + 200000 * Stages;
		return salary;
	}
	void MaxSalary(Casi* casixin)
	{
		Casi::Xuat();
	}
	void Xuat()
	{
		Casi::Xuat();
		cout << Luong() << endl;
	}

};
Casi* init(int type)
{
	switch (type)
	{
	case 1: return new NoiTieng;
	case 2: return new ChuaNoi;
	}
}
class MangCasi {
private: 
	int n;
	Casi* arrCasi[50];
public:
	void Nhap()
	{
		cout << "Nhap so ca si: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Nhap loai ca si:\n";
			cout << "1.Ca si noi tieng\n";
			cout << "2.Ca si chua noi tieng\n";
			int loai;
			cin >> loai;
			arrCasi[i] = init(loai);
			arrCasi[i]->Nhap();
		}
	}
	Casi* find_max_salary()
	{
		int max = 0;
		for (int i = 0; i < n; ++i)
		{
			if (arrCasi[i]->Luong() > arrCasi[max]->Luong())
			{
				max = i;
			}
		}
		return arrCasi[max];
	}
	void XuatCaSi(Casi* casi)
	{
		casi->Xuat();
	}
	

	void Xuat()
	{
		for (int i = 0; i < n; ++i)
		{
			arrCasi[i]->Xuat();
		}
	}
};

int main()
{
	MangCasi nhom;
	nhom.Nhap();
	nhom.Xuat();
	cout << "Ca si co luong cao nhat la: ";
	nhom.XuatCaSi(nhom.find_max_salary());

	return 0;
}
