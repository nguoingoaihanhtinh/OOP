#include <iostream>
#include <string>
using namespace std;

class ChungCu {
private:
	string name;
	int tang;
	double dientich;
	string sohuu;
	string quanly;
public:
	void ThongTin();
	string guiThongbao();
	virtual double tienphong() = 0.0;
};

typedef ChungCu CC;
class Vinhome : public CC {
public:
	Vinhome();
	double tienphong();
};
class Bcon : public CC {
public: 
	Bcon();
	double tienphong();
};
void ChungCu_import(ChungCu**, int, int);
void ChungCu_listExport(ChungCu**, int);
void ChungCu_tienPhong(ChungCu**, int);

int main()
{
	int Vinhome_amount, Bcons_amount;
	cout << "So chung cu VinHomes la:\n";
	cin >> Vinhome_amount;
	cout << "So chung cu Bcons la:\n";
	cin >> Bcons_amount;

	int size = Vinhome_amount + Bcons_amount;
	CC** a = new CC + [size];
	ChungCu_import(a, Vinhome_amount, Bcons_amount);
	ChungCu_listExport(a, size);
	ChungCu_tienPhong(a, size);

}
int random(int min, int max) {
	static bool first = true;
	if (first) {
		srand(time(NULL));
		first = false;
	}
	return min + rand() % ((max + 1) - min);
}
void CC::ThongTin()
{
	cout << "Ten chung cu: \n";
	getline(cin, name);
	cout << "So tang: \n";
	cin >> tang;
	cout << "Dien tich chung: \n";
	cin >> dientich;
	cin.ignore();
	cout << "Ten quan ly: \n";
	getline(cin, quanly);
}
string CC::guiThongbao()
{
	return quanly + " - " + name + " - " + sohuu;
}

Vinhome::Vinhome()
{
	sohuu = "Vinhomes";
}
double Vinhome::tienphong()
{
	if (dientich > 600)
	{
		return random(10, 15) * 6 * tang;
	}
	else return random(6, 10) * 6 * tang;
}
Bcon::Bcon() {
	sohuu = "Bcons";
}
double Bcon::tienphong()
{
	if (dientich > 600)
	{
		return random(8, 12) * 6 * tang;
	}
	else return random(5, 8) * 6 * tang;
}
void ChungCu_import(CC ** x, int a, int b)
{
	CC* temp;
	cin.ignore();
	for (int i = 0; i < a; i++)
	{
		cout << "thong tin Vinhome thu " << i + 1 << " : " << endl;
		temp = new Vinhome;
		temp->ThongTin();
		x[i] = temp;
	}
	for (int i = a; i < a + b; i++)
	{
		cout << "thong tin Bcon thu " << i + 1 - a << " : " << endl;
		temp = new Bcon;
		temp->ThongTin();
		x[i] = temp;
	}
}

void ChungCu_listExport(ChungCu** x, int size) {
	for (int i = 0; i < size; i++)
		cout << x[i]->guiThongbao() << endl;
}
void ChungCu_tienPhong(ChungCu** x, int size) {
	double total = 0;
	for (int i = 0; i < size; i++)
		total += x[i]->tienphong();
	cout << "\nTong so tien thu ve moi thang cua ban quan ly chung cu lang dai hoc la " << total
		<< "000 (VND)" << endl;
}