#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int cnt;
class NV {
private:
	string ten, gt, lop, ns;
	int id;
	double gpa;
public:
	NV()
	{
		ten = gt = lop = ns = " ";
		id = 0;
		gpa = 0;
	}
	 
	
	friend ostream& operator << (ostream& Out, NV a)
	{
		Out << setfill('0') << setw(2) << a.id << " " << a.ten << " " << a.gt << " " << a.lop << " " << a.ns << " "  << fixed << setprecision(2) << a.gpa << " " << endl;
		return Out;
	}
	friend istream& operator >> (istream& In, NV& a)
	{
		cnt++;
		a.id = cnt;
		
		getline(In, a.ten);
		In >> a.gt >> a.lop >> a.ns;
		
		if (a.ns[2] != '/') a.ns = "0" + a.ns;
		if (a.ns[5] != '/') a.ns.insert(3, "0");
		cout << "Nhap diem ";
		cin >> a.gpa;
		return In;
	}
};



int main()
{
	NV a[50];
	int n, i;
	cout << "nhap so sinh vien ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i];
	}
	return 0;

}