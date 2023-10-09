#include <iostream>
using namespace std;

class NV {
private:
	string ten, gt, ns, hdong;
	int id;
public:
	static int cnt;
	friend ostream& operator(ostream& Out, NV a)
	{
		Out << setfill('0') << setw(5) << a.id << " " << a.ten << " " << a.gt << " " << a.ns << " " << a.hdong << endl;
		return Out;
	}
	friend istream& operator(istream& In, NV& a)
	{
		cnt++;
		a.id = cnt;
		In.ignore();
		getline(In, a.ten);
		In >> a.gt >> a.ns;
		In.ignore();
		In >> a.hdong;
		return In;
	}
};

int main()
{
	NV a();
	cin >> a;
	cout << a;
	return 0;
}