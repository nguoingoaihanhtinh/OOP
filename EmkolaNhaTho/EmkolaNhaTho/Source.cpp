#include <iostream>
#include <string>
using namespace std;
string getVan(string a) {
	int l = a.length();
	int i = 0;
	if (a[0] == 'q') i = 2;
	for (i; i < l; i++) {
		if (a[i] == 'a' || a[i] == 'u' || a[i] == 'i' || a[i] == 'e' || a[i] == 'o' || a[i] ==
			'y') break;
	}
	string van = "";
	for (int j = i; j < l; j++) van.push_back(a[j]);
	return van;
}
bool amTrac(string a) {
	int l = a.length() - 1;
	return (a[l] == 'p' || a[l] == 'c' || a[l] == 't');
}
bool hiepVan(string a, string b) {
	string vanA = getVan(a);
	string vanB = getVan(b);
	int la = vanA.length() - 1;
	int lb = vanB.length() - 1;
	if (vanA[la] == 'g') vanA.pop_back();
	if (vanB[lb] == 'g') vanB.pop_back();
	if (vanA[la] == 't') vanA[la] = 'c';
	if (vanB[lb] == 't') vanB[lb] = 'c';
	if (vanA == "y") vanA = "i";
	if (vanB == "y") vanB = "i";
	if (vanA == vanB) return 1;
	return 0;
}
class BucTranh {
protected: int type;
		 string colorName[7] = {
		 "",
		 "Cam",
		 "Lam",
		 "Vang",
		 "Luc",
		 "Tim",
		 "Do"
		 };
		 int idC = -1;
public: virtual void Nhap() {
	cin >> idC;
}
	  virtual void Xuat() {}
	  int getidC() {
		  return idC;
	  }
	  void setidC(int idC) {
		  this->idC = idC;
	  }
	  virtual void dividedByEight() {}
};
class Chau : public BucTranh {
protected: static int priColor[7];
public: void Nhap() {
	type = 1;
	cout << "Mau chu dao cua Chau (1 - Cam, 2 - Lam, 3 - Vang, 4 - Luc, 5 - Tim, 6 - Do): ";
	BucTranh::Nhap();
	priColor[idC]++;
	if (idC == 2) priColor[2]++;
}
	  void Xuat() {
		  cout << "Cac tranh cua Chau:\n";
		  bool coTranh = 0;
		  for (int i = 1; i < 7; i++) {
			  if (priColor[i] > 0) {
				  cout << colorName[i] << ": " << priColor[i] << " tranh\n";
				  coTranh = 1;
			  }
		  }
		  if (coTranh == 0) cout << "Khong ve tranh nao\n";
	  }
};
class Dong : public BucTranh {
protected: static int priColor[7];
public: void Nhap() {
	type = 2;
	if (idC != -1) {
		mauDoiLap(idC);
	}
	else priColor[5]++;
}
	  void mauDoiLap(int ChaucrnColor) {
		  switch (ChaucrnColor) {
		  case 1:
			  priColor[2]++;
			  break;
		  case 2:
			  priColor[1]++;
			  break;
		  case 3:
			  priColor[5]++;
			  break;
		  case 4:
			  priColor[6]++;
			  break;
		  case 5:
			  priColor[3]++;
			  break;
		  case 6:
			  priColor[4]++;
			  break;
		  }
	  }
	  void Xuat() {
		  cout << "Cac tranh cua Dong:\n";
		  bool coTranh = 0;
		  for (int i = 1; i < 7; i++) {
			  if (priColor[i] > 0) {
				  cout << colorName[i] << ": " << priColor[i] << " tranh\n";
				  coTranh = 1;
			  }
		  }
		  if (coTranh == 0) cout << "Khong ve tranh nao\n";
	  }
};
class Vu : public BucTranh {
protected: static int priColor[7]; bool dividedbyEight = 0;
public: static int tongSoTho;
	  void Nhap() {
		  type = 3;
		  tongSoTho++;
		  if (tongSoTho <= 2) {
			  cout << "Mau chu dao cua Vu (1 - Cam, 2 - Lam, 3 - Vang, 4 - Luc, 5 - Tim, 6 - Do): ";
			  BucTranh::Nhap();
			  priColor[idC]++;
			  if (dividedbyEight) priColor[idC]++;
		  }
		  else {
			  cout << "Anh Vu da ve cho 2 bai tho\n";
		  }
	  }
	  void dividedByEight() {
		  dividedbyEight = 1;
	  }
	  int tongSoTien() {
		  int tongSoTien = 0;
		  for (int i = 1; i < 7; i++) {
			  tongSoTien += 800 * priColor[i];
			  if (i == 3) tongSoTien += 200 * priColor[i];
		  }
		  return tongSoTien;
	  }
	  void Xuat() {
		  cout << "Cac tranh cua Vu:\n";
		  bool coTranh = 0;
		  for (int i = 1; i < 7; i++) {
			  if (priColor[i] > 0) {
				  cout << colorName[i] << ": " << priColor[i] << " tranh\n";
				  coTranh = 1;
			  }
		  }
		  if (coTranh == 0) cout << "Khong ve tranh nao\n";
		  cout << "Tong chi phi: " << tongSoTien();
	  }
};
int Vu::tongSoTho = 0;
int Chau::priColor[7] = {};
int Dong::priColor[7] = {};
int Vu::priColor[7] = {};
class dsTranh {
private: bool hoaSi[4]; BucTranh** bucTranh = new BucTranh * [3];
	   bool haveChau; bool dividedbyEight;
public: dsTranh() {
	bucTranh[0] = new Chau;
	bucTranh[1] = new Dong;
	bucTranh[2] = new Vu;
}
	  ~dsTranh() {
		  delete[] bucTranh;
	  }
	  void Nhap(int type = 0) {
		  int temp;
		  do {
			  cin >> temp;
			  hoaSi[temp] = 1;
		  } while (cin.get() != '\n');
		  if (type == 2) {
			  hoaSi[2] = 0;
		  }
		  if (type == 3) {
			  hoaSi[1] = 0;
		  }
		  taoHoaSi();
	  }
	  void setDividedByEight(bool dividedbyEight) {
		  this->dividedbyEight = dividedbyEight;
	  }
	  void taoHoaSi() {
		  for (int i = 1; i < 4; i++) {
			  if (hoaSi[i] == 1) {
				  switch (i) {
				  case 1:
					  haveChau = 1;
					  break;
				  case 2:
					  if (haveChau == 1) bucTranh[1]->setidC(bucTranh[0]->getidC());
					  break;
				  case 3:
					  if (dividedbyEight) bucTranh[2]->dividedByEight();
				  }
				  bucTranh[i - 1]->Nhap();
			  }
		  }
	  }
	  void Xuat() {
		  for (int i = 0; i < 3; i++) bucTranh[i]->Xuat();
	  }
};
class BaiTho {
protected: string tenbaitho;
		 string cauTho[100][100];
		 int soCau = 0;
		 dsTranh TranhList;
public:
	virtual void Nhap() {
		cout << "- Ten bai tho: ";
		getline(cin, tenbaitho);
		cout << "- Nhap bai tho: \n";
		string temp;
		int chu = 1;
		do {
			cin >> temp;
			if (temp == "/") break;
			if (temp != " ") cauTho[soCau + 1][chu++] = temp;
			if (cin.get() == '\n') {
				soCau++;
				chu = 1;
			}
		} while (true);
		TranhList.setDividedByEight(soCau % 8 == 0);
	}
	virtual bool KiemTra() = 0;
	void Xuat() {
		if (KiemTra()) {
			cout << "==\n";
			cout << "-Tieu de: " << tenbaitho << "\n";
			for (int i = 1; i <= soCau; i++) {
				int chu = 1;
				while (cauTho[i][chu] != "") {
					cout << cauTho[i][chu++] << " ";
				}
				cout << "\n";
			}
		}
	}
};
class LB : public BaiTho {
public: void Nhap() {
	BaiTho::Nhap();
	if (!KiemTra()) return;
	cout << "- Cac hoa si muon nho (1 - Chau, 2 - Dong, 3 - Vu): ";
	TranhList.Nhap(1);
}
	  bool KiemTra() {
		  if (soCau % 2 != 0) return 0;
		  for (int i = 1; i <= soCau; i++) {
			  if (i % 2 == 1 && (cauTho[i][7] != "")) return 0;
			  if (i % 2 == 0 && (cauTho[i][9] != "")) return 0;
			  if (i % 2 == 1 && !hiepVan(cauTho[i][6], cauTho[i + 1][6])) return 0;
			  if (i % 2 == 0 && i != soCau && !hiepVan(cauTho[i][8], cauTho[i + 1][6])) return 0;
		  }
		  return 1;
	  }
};
class ST : public BaiTho {
public: void Nhap() {
	BaiTho::Nhap();
	if (!KiemTra()) return;
	cout << "- Cac hoa si muon nho (1 - Chau, 3 - Vu): ";
	TranhList.Nhap(2);
}
	  bool KiemTra() {
		  if (soCau % 4 != 0) return 0;
		  int i = 1;
		  if (!amTrac(cauTho[1][7])) return 0;
		  if (amTrac(cauTho[2][7])) return 0;
		  if (amTrac(cauTho[4][8])) return 0;
		  while (i <= soCau - 3) {
			  if ((i % 4 == 1 || i % 4 == 2) && (cauTho[i][8] != "")) return 0;
			  if (i % 4 == 3 && (cauTho[i][7] != "")) return 0;
			  if (i % 4 == 0 && (cauTho[i][9] != "")) return 0;
			  if (!hiepVan(cauTho[i][7], cauTho[i + 1][5])) return 0;
			  if (!hiepVan(cauTho[i + 1][7], cauTho[i + 2][6])) return 0;
			  if (!hiepVan(cauTho[i + 2][6], cauTho[i + 3][6])) return 0;
			  if ((i + 4 < soCau) && (!hiepVan(cauTho[i + 3][8], cauTho[i + 4][5]))) return 0;
			  i += 4;
		  }
		  return 1;
	  }
};
class TN : public BaiTho {
public: void Nhap() {
	BaiTho::Nhap();
	if (!KiemTra()) return;
	cout << "- Cac hoa si muon nho (2 - Dong, 3 - Vu): ";
	TranhList.Nhap(3);
}
	  bool KiemTra() {
		  if (soCau != 8) return 0;
		  for (int i = 1; i <= 8; i++) {
			  if (cauTho[i][8] != "") return 0;
		  }
		  if (amTrac(cauTho[1][7])) return 0;
		  if (!hiepVan(cauTho[1][7], cauTho[2][7])) return 0;
		  if (!hiepVan(cauTho[2][7], cauTho[4][7])) return 0;
		  if (!hiepVan(cauTho[4][7], cauTho[6][7])) return 0;
		  if (!hiepVan(cauTho[6][7], cauTho[8][7])) return 0;
		  return 1;
	  }
};
int main() {
	cout << "- Nhap so luong bai tho: ";
	int n;
	cin >> n;
	BaiTho** tho = new BaiTho * [n];
	for (int i = 0; i < n; i++) {
		cout << "== The loai bai tho thu " << i + 1 << "(LB - Luc bat, ST - Song that luc bat, TN- That ngon bat cu Duong luat): ";
			string type;
		cin >> type;
		cin.ignore();
		if (type == "LB") tho[i] = new LB;
		if (type == "ST") tho[i] = new ST;
		if (type == "TN") tho[i] = new TN;
		tho[i]->Nhap();
	}
	for (int i = 0; i < n; i++) {
		tho[i]->Xuat();
	}
	cout << "--\n";
	dsTranh ds;
	ds.Xuat();
	return 0;
}