#include<iostream>
#include<string>
using namespace std;

class NhaThue
{
protected:
    char DiaChi[1000];
    long TienThueThang;
    long TienDatCoc;
    bool TinhTrangCanHo;
public:
    NhaThue()
    {
        TienDatCoc = 0;
        TienThueThang = 0;
        TinhTrangCanHo = 0;
    }
    ~NhaThue(){}
    virtual void Nhap()
    {
        cout << "Nhap vao dia chi can ho: ";
        cin >> DiaChi;
        cout << "Nhap vao so tien dat coc: ";
        cin >> TienDatCoc;
        cout << "Nhap vao so tien thue hang thang: ";
        cin >> TienThueThang;
        do
        {
            cout << "Nhap so 0 neu dang cho thue" << endl;
            cout << "Nhap so 1 neu dang con trong" << endl;
            cout << "Nhap lua chon: ";
            cin >> TinhTrangCanHo;
            if (TinhTrangCanHo != 0 && TinhTrangCanHo != 1)
            {
                cout << "Nhap sai. Vui long nhap lai!" << endl;
            }
        } while (TinhTrangCanHo != 0 && TinhTrangCanHo != 1);
    }
    virtual void Xuat()
    {
        cout << "Dia chi can ho: " << DiaChi << endl;
        cout << "Tien dat coc la: " << TienDatCoc << endl;
        cout << "Tien thue hang thang la: " << TienThueThang << endl;
        cout << "Tinh trang can ho: ";
        if (TinhTrangCanHo == 0)
        {
            cout << "Cho thue" << endl;
        }
        else if (TinhTrangCanHo == 1)
        {
            cout << "Con trong" << endl;
        }
    }
    virtual long ThueThang()
    {
        return TienThueThang;
    }
    virtual long DatCoc()
    {
        return TienDatCoc;
    }
    virtual bool TinhTrang()
    {
        return TinhTrangCanHo;
    }
};
class BinhThuong : virtual public NhaThue
{
protected:
    int SoTang;
public:
    BinhThuong()
    {
        SoTang = 1;
    }
    ~BinhThuong() {}
    virtual void Nhap()
    {
        cout << "Nhap thong tin cua can ho thuong" << endl;
        NhaThue::Nhap();
        cout << "Nhap so tang cua can ho: ";
        cin >> SoTang;
    }
    virtual void Xuat()
    {
        cout << "Thong tin cua can ho thuong" << endl;
        NhaThue::Xuat();
        cout << "So tang cua can ho: " << SoTang << endl;
    }
};
class ChungCu : virtual public NhaThue
{
protected:
    int TangMay;
public:
    ChungCu()
    {
        TangMay = 1;
    }
    ~ChungCu() {}
    virtual void Nhap()
    {
        cout << "Nhap thong tin cua can ho chung cu" << endl;
        NhaThue::Nhap();
        cout << "Nhap vao can ho o tang: ";
        cin >> TangMay;
    }
    virtual void Xuat()
    {
        cout << "Thong tin cua chung cu" << endl;
        NhaThue::Xuat();
        cout << "Can ho o tang: " << TangMay << endl;
    }
};

class CongTyABC
{
protected:
    NhaThue** DuLieu;
    int SoCanHo;
    int SoCanHoTrong;
    int SoCanHoThuong, SoChungCu;
    long TongTienChoThue;
    long TongTienDatCoc;
public:
    CongTyABC()
    {
        SoCanHo = 0;
        DuLieu = new NhaThue * [SoCanHo];
        SoCanHoTrong = 0;
        SoCanHoThuong = 0;
        SoChungCu = 0;
        TongTienChoThue = 0;
        TongTienDatCoc = 0;
    }
    ~CongTyABC()
    {
        delete[]DuLieu;
    }
    void Nhap()
    {
        cout << "Nhap so can ho cong ty ABC quan ly: ";
        cin >> SoCanHo;
        int LuaChon = 0;
        for (int i = 0; i < SoCanHo; i++)
        {
            do
            {
                cout << "======================================" << endl;
                cout << "Nhap thong tin can ho thu: " << i + 1 << endl;
                cout << "Nhap so 1 neu can ho la chung cu" << endl;
                cout << "Nhap so 2 neu can ho la can ho thuong" << endl;
                cout << "Nhap su lua chon: ";
                cin >> LuaChon;
                if (LuaChon != 1 && LuaChon != 2)
                {
                    cout << "Nhap sai. Vui long nhap lai!" << endl;
                }
            } while (LuaChon != 1 && LuaChon != 2);
            if (LuaChon == 1)
            {
                DuLieu[i] = new ChungCu;
                DuLieu[i]->Nhap();
                if (DuLieu[i]->TinhTrang() == 0)
                {
                    SoChungCu++;
                    TongTienChoThue += DuLieu[i]->ThueThang();
                    TongTienDatCoc += DuLieu[i]->DatCoc();
                }
                else if (DuLieu[i]->TinhTrang() == 1)
                {
                    SoCanHoTrong++;
                }
            }
            else if (LuaChon == 2)
            {
                DuLieu[i] = new BinhThuong;
                DuLieu[i]->Nhap();
                if (DuLieu[i]->TinhTrang() == 0)
                {
                    SoCanHoThuong++;
                    TongTienChoThue += DuLieu[i]->ThueThang();
                    TongTienDatCoc += DuLieu[i]->DatCoc();
                }
                else if (DuLieu[i]->TinhTrang() == 1)
                {
                    SoCanHoTrong++;
                }
            }
        }
    }
    void Xuat()
    {
        cout << "========================================" << endl;
        cout << "THONG TIN QUAN LY CUA CONG TY ABC" << endl;
        cout << "So luong can ho cong ty quan ly: " << SoCanHo << endl;
        cout << "So luong can ho con trong: " << SoCanHoTrong << endl;
        cout << "So luong can ho cho thue: " << SoChungCu + SoCanHoThuong << endl;
        cout << "So chung cu da cho thue: " << SoChungCu << endl;
        cout << "So can ho thuong da cho thue: " << SoCanHoThuong << endl;
        cout << "Thong tin chi tiet cac can ho: " << endl;
        for (int i = 0; i < SoCanHo; i++)
        {
            cout << "=================================" << endl;
            cout << "Thong tin can ho thu: " << i + 1 << endl;
            DuLieu[i]->Xuat();
        }
        cout << "Tong so tien thue phong trong thang: " << TongTienChoThue << endl;
        cout << "Tong so tien dat coc trong thang: " << TongTienDatCoc << endl;
    }
};

int main()
{
    CongTyABC DuLieu;
    DuLieu.Nhap();
    DuLieu.Xuat();
    return 0;
}