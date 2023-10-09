#include "BusinessGate.h"
#include "AcademicGate.h"
#include "PowerGate.h"

int main()
{
	cout << "Nhap so cong: ";
	int n; cin >> n;
	cout << "\n1.Cong giao thuong";
	cout << "\n2.Cong ma thuat";
	cout << "\n3.Cong suc manh";
	Gate* a[1000];
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap vao loai cong";
		int l; cin >> l;
		if (l == 1) a[i] = new BusinessGate();
		if (l == 2) a[i] = new AcademicGate();
		if (l == 3) a[i] = new PowerGate();
		a[i]->Nhap();
		a[i]->Xuat();
	}

	cout << "\nNhap thong tin hoang tu ";
	cout << "\nNhap so tien ";
	int mny; cin >> mny;
	cout << "\nNhap tri tue";
	int intel; cin >> intel;
	cout << "\nNhap suc manh";
	int str; cin >> str;
	for (int i = 0; i < n; i++)
	{
		if (a[i]->Check(mny, intel, str))
		{
		}
		else {
			cout << "Khong cuu duoc";
			return 0;
		}
	}
	cout << "Cuu duoc cong chua";
}