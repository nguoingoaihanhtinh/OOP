#include <iostream>
#include <string>
using namespace std;
class Character {
protected:
	static int dem_Nhan_loai;
	string name = "Unknown";
	float HP = 0.0;
	float ATK = 0.0;
	float DEF = 0.0;
public:
	float get_HP() { return HP; }
	bool is_dead() { return HP <= 0; }
	void attack(Character* enemy) {
		if (ATK > enemy->DEF) {
			enemy->HP = enemy->HP - (ATK - enemy->DEF);
		}
	}
	virtual void adjust() {
		return;
	}
	virtual void Nhap() {
		cout << "Nhap ten, chi so hp - atk - def: \n";
		cin >> name >> HP >> ATK >> DEF;
	}
	void Xuat() {
		cout << name << " " << HP << endl;
	}
};

int Character::dem_Nhan_loai = 0;
class Boss : public Character {};
class Nhan_loai : public Character {
protected:
	string job = "Unknown";
public:
	void Nhap() {
		Character::Nhap();
		cout << "Nhap toc nguoi: " << endl;
		cin >> job;
		++dem_Nhan_loai;
	}
};
class Human : public Nhan_loai
{
};
class Elf : public Nhan_loai
{
public:
	void adjust()
	{
		DEF = DEF * 1.5;
	}
};

class Ban_nhan : public Character {
protected:
	string race;
public:
	void Nhap()
	{
		Character::Nhap();
		cout << "Nhap chung toc: \n";
		cin >> race;
	}

};
class Orc : public Ban_nhan {
public:
	void adjust()
	{
		HP = HP * 1.5;
	}
};
class Goblin : public Ban_nhan {
public:
	void adjust()
	{
		ATK = ATK * 1.5;
	}
};

class Di_hinh : public Character {
};
class Vampire : public Di_hinh {
public:
	void adjust()
	{
		HP = 0.1 * HP * dem_Nhan_loai;
	}
};
class Devil : public Di_hinh {
protected:
	static int dem_Quy;
public:
	void Nhap()
	{
		Character::Nhap();
		dem_Quy++;
	}
	void adjust()
	{
		ATK = 0.1 * ATK * dem_Quy;
		DEF = 0.1 * DEF * dem_Quy;
	}
};
int Devil::dem_Quy = 0;
Character* init(int type)
{
	switch (type)
	{
	case 1: return new Human;
	case 2:return new Elf;
	case 3:return new Orc;
	case 4: return new Goblin;
	case 5: return new Vampire;
	case 6: return new Devil;
	}
}
	

class Guild {
private:
	int soluong;
	Character* arrGuild[50];
public:
	void Nhap()
	{
		cout << "Nhap so luong: ";
		cin >> soluong;
		for (int i = 0; i < soluong; i++)
		{
			cout << "Nhap chung loai nhan vat \n";
			cout << "1.toc nguoi\n";
			cout << "2.Toc tien\n";
			cout << "3.Toc orc\n";
			cout << "4.toc yeu tinh\n";
			cout << "5.toc ma ca rong\n";
			cout << "6.toc quy\n";
			int loai;
			cin >> loai;
			arrGuild[i] = init(loai);
			arrGuild[i]->Nhap();
		}
		for (int i = 0; i < soluong; i++)
		{
			arrGuild[i]->adjust();
		}
	}
	void Xuat()
	{
		for (int i = 0; i < soluong; i++)
		{
			if (!arrGuild[i]->is_dead())
			{
				arrGuild[i]->Xuat();
			}
		}
	}
	void attack(Character* enemy)
	{
		for (int i = 0; i < soluong; ++i)
		{
			if (!arrGuild[i]->is_dead())
			{
				arrGuild[i]->attack(enemy);
			}
		}
	}
	bool is_all_dead()
	{
		for (int i = 0; i < soluong; ++i)
		{
			if (!arrGuild[i]->is_dead())
			{
				return false;
			}
		}
	}
	Character* find_min_HP() {
		int min_index = 0;
		for (int i = 0; i < soluong; ++i) {
			if (!arrGuild[i]->is_dead()) {
				min_index = i;
				break;
			}
		}
		for (int i = 0; i < soluong; ++i) {
			if (!arrGuild[i]->is_dead() && arrGuild[i]->get_HP() < arrGuild[min_index]->get_HP()) {
				min_index = i;
			}
		}
		return arrGuild[min_index];
	}
	void sort_HP() {
		for (int i = 0; i <= soluong - 2; ++i)
			for (int j = i + 1; j <= soluong - 1; ++j)
				if (arrGuild[j]->get_HP() < arrGuild[i]->get_HP())
					swap(arrGuild[i], arrGuild[j]);
	}
};

int main()
{
	Guild team;
	team.Nhap();
	Boss boss;
	boss.Nhap();
	do {
		team.attack(&boss);
		if (boss.is_dead())
		{
			break;
		}
		boss.attack(team.find_min_HP());
	}
		while (!team.is_all_dead());
	if (!boss.is_dead())
	{
		boss.Xuat();
	}
	else
	{
		team.sort_HP();
		team.Xuat();
	}
	return 0;

}