#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class ThuVien {
public:
	virtual void Nhap() = 0;
	virtual void Xuat() = 0;
	int min;
	int ThanhTien()
	{
		return 0;
	}
	string NSX()
	{
		return 0;
	}
};

class SGK : public ThuVien {
protected:
	int masgk;
	string tensgk;
	string nsxsgk;
	float dongia;
	float soluong;
	int tinhtrang;
	float thanhtien;
public:
	SGK()
	{
		this->masgk = 0;
		this->tensgk = this->nsxsgk = "";
		this->dongia = this->thanhtien = this->soluong = 0.0;
		this->tinhtrang = 0;
	}
	~SGK()
	{
		this->masgk = 0;
		this->tensgk = this->nsxsgk = "";
		this->dongia = this->thanhtien = this->soluong = 0.0;
		this->tinhtrang = 0;
	}
	void Nhap()
	{

		cout << "Nhap ma "; cin >> this->masgk;
		cin.ignore();
		cout << "Nhap ten sach: "; getline(cin, this->tensgk);
		cout << "Nhap ten nsx: "; getline(cin, this->nsxsgk);
		cout << "Nhap don gia: "; cin >> this->dongia;
		cout << "Nhap so luong: "; cin >> this->soluong;
		cout << "Nhap tinh trang (1 = tot | 0 = te) : "; cin >> this->tinhtrang;
		if (this->tinhtrang == 1)
		{
			this->thanhtien = this->dongia * this->soluong;
		}
		else this->thanhtien = this->dongia * this->soluong * 0.5 ;
		if (this->thanhtien < min)
			min = this->thanhtien;
	}
	int ThanhTien()
	{
		return this->thanhtien;
	}

	void Xuat()
	{

		cout << this->masgk << " " << this->tensgk << " " << this->nsxsgk << " Chat luong: ";
		if (this->tinhtrang == 1)
		{
			cout << " Tot " << endl;
		}
		else cout << " Te " << endl;
		cout << "Don gia: " << this->dongia << " - So luong: " << this->soluong << endl;
		cout << "Thanh tien : " << this->thanhtien << endl;
	}

	string NSX()
	{
		return nsxsgk;
	}
	
	
};

class STK : public ThuVien {
protected:
	int mastk;
	string tenstk;
	string nsxstk;
	float dongia;
	float soluong;
	float thanhtien;
public:
	STK()
	{
		this->mastk = 0;
		this->tenstk = this->nsxstk = "";
		this->dongia = this->thanhtien = this->soluong = 0.0;
	}
	~STK()
	{
		this->mastk = 0;
		this->tenstk = this->nsxstk = "";
		this->dongia = this->thanhtien = this->soluong = 0.0;
	}
	void Nhap()
	{
		cout << "Nhap ma "; cin >> this->mastk;
		cin.ignore();
		cout << "Nhap ten sach: "; getline(cin, this->tenstk);
		cout << "Nhap ten nsx: "; getline(cin, this->nsxstk);
		cout << "Nhap don gia: "; cin >> this->dongia;
		cout << "Nhap so luong: "; cin >> this->soluong;
		this->thanhtien = this->dongia * this->soluong;
		if (this->thanhtien < min)
			min = this->thanhtien;
	}
	string NSX()
	{
		return nsxstk;
	}

	void Xuat()
	{
		cout << this->mastk << " " << this->tenstk << " " << this->nsxstk << endl;
	cout << "Thanh tien: " << this->thanhtien << endl;
	}
};
ThuVien* init(int type)
{
	switch (type)
	{
	case 1: return new SGK;
	case 2: return new STK;
	}
}
class ThongKeSach {
private:
	int n;
	ThuVien* arrSach[50];
public:
	void Nhap() {
		cout << "Nhap so luong sach: " << endl;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Nhap loai sach thu " << i + 1 << "( 1 = SGK, 2 = STK) " << endl;
			int loai;
			cin >> loai;
			arrSach[i] = init(loai);
			arrSach[i]->Nhap();
		}
	}
	ThuVien* thanhtien_min()
	{
		int min = 0;
		for (int i = 0; i < n; i++)
		{
			if (arrSach[i]->ThanhTien() < arrSach[min]->ThanhTien())
			{
				min = i;
			}
		}
		return arrSach[min];
	}

	void Xuat()
	{
		for (int i = 0; i < n; i++)
		{
			arrSach[i]->Xuat();
		}
		cout << "Loai sach co gia thanh re nhat la: ";
		thanhtien_min()->Xuat();
		cout << endl;
		bool consx = false;
		cin.ignore();
		cout << "nhap vao ten nsx: ";
		string nsx;
		getline(cin, nsx);
		for (int i = 0; i < n; i++)
		{
			if (nsx == arrSach[i]->NSX())
			{
				arrSach[i]->Xuat();
				consx = true;
			}
		}
		if (consx == false)
		{
			cout << "Khong co nha san xuat! \n";
		}
	}
};

int main()
{
	ThongKeSach thuvien;
	thuvien.Nhap();
	thuvien.Xuat();

	return 0;
}


	


