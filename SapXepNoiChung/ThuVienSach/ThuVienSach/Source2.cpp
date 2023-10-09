#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

class Sach {
protected:
	int id = 0;
	string name = " ";
	string nxb = " ";
	long soluong = 0;
	long dongia = 0;
public:
	Sach() {};
	~Sach() {};
	virtual void Nhap()
	{
		cout << "Nhap vao id, ten sach, nha xuat ban, so luong, don gia: " << endl;
		cin >> id >> name >> nxb >> soluong >> dongia;
	}
	virtual void Xuat()
	{
		cout << id << ". " << name << " - " << nxb << endl;
		cout << dongia << " soluong " << soluong << endl;
	}
	string NXB()
	{
		return nxb;
	}
	virtual long ThanhTien()
	{
		return 0;
	}
};

class SGK : public Sach {
private:
	int tinhtrang;
	long thanhtien;
public:
	void Nhap()
	{
		Sach::Nhap();
		cout << "nhap tinh trang (1: Moi | 0: Cu)";
		cin >> tinhtrang;
	}
	string NXB()
	{
		return nxb;
	}
	long ThanhTien()
	{
		if (tinhtrang == 1)
		{
			thanhtien = soluong * dongia;
		}
		else thanhtien = soluong * dongia * 0.5;
		return thanhtien;
	}
	void Xuat()
	{
		Sach::Xuat();
		int x = ThanhTien();
		cout << "Thanh tien: " << x << endl;
	}
};

class STK : public Sach {
private:
	int thue;
	long thanhtien;
public:
	void Nhap()
	{
		Sach::Nhap();
		cout << "Nhap vao thue: " << endl;
		cin >> thue;
	}
	string NXB()
	{
		return nxb;
	}
	long ThanhTien()
	{
		thanhtien = soluong * dongia + thue;
		return thanhtien;
	}
	void Xuat()
	{
		Sach::Xuat();
		int x = ThanhTien();
		cout << "Thanh tien: " << x << endl;
	}
};

class ThuVien {
private:
	int n;
	Sach* arrSach[100];
	long sachre;
	long min;
public:
	Sach* init(int type)
	{
		switch (type)
		{
		case 1: return new SGK;
		case 2: return new STK;
		}
	}
	void Nhap()
	{
		
		cout << "Nhap so luong sach: "; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Nhap loai sach thu " << i + 1 << "\n";
			cout << "1.SGK\n";
			cout << "2.STK\n";
			int loai; cin >> loai;
			arrSach[i] = init(loai);
			arrSach[i]->Nhap();
		}
		
		
	}
	/*
	void thanhtien_min()
	{
		int min = 0;
		for (int i = 0; i < n; i++)
		{
			if (arrSach[i]->ThanhTien() < arrSach[min]->ThanhTien())
			{
				min = i;
			}
		}
		arrSach[min]->Xuat();
	}
	*/
		
	
	void Xuat()
	{
		for (int i = 0; i < n; i++)
		{
			arrSach[i]->Xuat();
		}
		
		sachre = arrSach[0]->ThanhTien();
		min = 0;
		for (int i = 0; i < n; i++)
		{
			if (arrSach[i]->ThanhTien() < sachre)
			{
				sachre = arrSach[i]->ThanhTien();
				min = i;
			}
		}
		cout << "Sach co gia thanh re nhat la: "; arrSach[min]->Xuat(); cout << "\n";
		cout << "Nhap vao ten cua nha xuat ban: ";
		string nxbmoi;
		cin >> nxbmoi;
		bool conxb = false;
		for (int i = 0; i < n; i++)
		{
			if (nxbmoi == arrSach[i]->NXB())
			{
				arrSach[i]->Xuat();
				conxb = true;
			}
		}
		if (conxb == false)
		{
			cout << "Khong co nha xuat ban! ";
		}
	}
};
int main()
{
	ThuVien thuvien;
	thuvien.Nhap();
	thuvien.Xuat();
	
	
	

}