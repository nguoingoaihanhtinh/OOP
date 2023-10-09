#pragma once
#include<iostream>
#include<string>
using namespace std;
class NhanVien
{
protected:
    char HoTen[100];
    int Ngay, Thang, Nam;
public:
    NhanVien();
    ~NhanVien();
    virtual void Nhap();
    virtual void Xuat();
    virtual long Luong();

};
NhanVien::NhanVien()
{

}

NhanVien::~NhanVien()
{

}

void NhanVien::Nhap()
{
    cout << "Nhap ho va ten: ";
    cin >> HoTen;
    cout << "Nhap ngay sinh: ";
    cin >> Ngay;
    cout << "Nhap thang sinh: ";
    cin >> Thang;
    cout << "Nhap nam sinh: ";
    cin >> Nam;
}

void NhanVien::Xuat()
{
    cout << "Ho va ten nhan vien: " << HoTen << endl;
    cout << "Ngay thang nam sinh: " << Ngay << "/" << Thang << "/" << Nam << endl;
}

long NhanVien::Luong()
{
    return 0;
}


class NhanVienSanXuat :
    public NhanVien
{
protected:
    long LuongCoBan, SoSanPham;
public:
    NhanVienSanXuat();
    ~NhanVienSanXuat();
    virtual void Nhap();
    virtual void Xuat();
    virtual long Luong();
};
NhanVienSanXuat::NhanVienSanXuat()
{

}

NhanVienSanXuat::~NhanVienSanXuat()
{

}

void NhanVienSanXuat::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap muc luong co ban: ";
    cin >> LuongCoBan;
    cout << "Nhap so san pham: ";
    cin >> SoSanPham;
}

void NhanVienSanXuat::Xuat()
{
    NhanVien::Xuat();
    cout << "Muc luong co ban: " << LuongCoBan << endl;
    cout << "So san pham lam duoc: " << SoSanPham << endl;
}

long NhanVienSanXuat::Luong()
{
    return LuongCoBan + (SoSanPham * 5000);
}

class NhanVienVanPhong :
    public NhanVien
{
protected:
    long SoNgayLamViec;
public:
    NhanVienVanPhong();
    ~NhanVienVanPhong();
    virtual void Nhap();
    virtual void Xuat();
    virtual long Luong();
};
NhanVienVanPhong::NhanVienVanPhong()
{

}

NhanVienVanPhong::~NhanVienVanPhong()
{

}

void NhanVienVanPhong::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> SoNgayLamViec;
}

void NhanVienVanPhong::Xuat()
{
    NhanVien::Xuat();
    cout << "So ngay lam viec: " << SoNgayLamViec << endl;
}

long NhanVienVanPhong::Luong()
{
    return SoNgayLamViec * 100000;
}
class QuanLyNhanVien
{
protected:
    NhanVien** DuLieu;
    long SoLuongNhanVien;
    long TongSoLuongPhaiTra;
    long LuongCaoNhat, Max;
    long LuongThapNhat, Min;
public:
    QuanLyNhanVien();
    ~QuanLyNhanVien();
    void Nhap();
    void Xuat();
};
QuanLyNhanVien::QuanLyNhanVien()
{
    SoLuongNhanVien = 0;
    DuLieu = new NhanVien * [SoLuongNhanVien];
    TongSoLuongPhaiTra = 0;
    LuongCaoNhat = 0; Max = 0;
    LuongThapNhat = 0; Min = 0;
}

QuanLyNhanVien::~QuanLyNhanVien()
{
    delete[]DuLieu;
}

void QuanLyNhanVien::Nhap()
{
    cout << "Nhap so luong nhan vien: ";
    cin >> SoLuongNhanVien;
    int LuaChon = 0;
    for (int i = 0; i < SoLuongNhanVien; i++)
    {
        do
        {
            cout << "==============================" << endl;
            cout << "Nhap thong tin nhan vien thu: " << i + 1 << endl;
            cout << "Menu nhap du lieu:" << endl;
            cout << "Nhap so 1 neu la nhan vien san xuat" << endl;
            cout << "Nhap so 2 neu la nhan vien van phong" << endl;
            cout << "Nhap su lua chon: ";
            cin >> LuaChon;
            if (LuaChon != 1 && LuaChon != 2)
            {
                cout << "Nhap sai lua chon, vui long nhap lai!" << endl;
            }
        } while (LuaChon != 1 && LuaChon != 2);
        if (LuaChon == 1)
        {
            DuLieu[i] = new NhanVienSanXuat;
        }
        else if (LuaChon == 2)
        {
            DuLieu[i] = new NhanVienVanPhong;
        }
        DuLieu[i]->Nhap();
        TongSoLuongPhaiTra += DuLieu[i]->Luong();
    }
}

void QuanLyNhanVien::Xuat()
{
    cout << "So luong nhan vien cua cong ty: " << SoLuongNhanVien << endl;
    for (int i = 0; i < SoLuongNhanVien; i++)
    {
        cout << "=================================================" << endl;
        cout << "Thong tin nhan vien thu: " << i + 1 << endl;
        DuLieu[i]->Xuat();
        cout << "Tien luong nhan duoc: " << DuLieu[i]->Luong() << endl;
    }
    cout << "======================================================" << endl;
    cout << "Tong so tien luong ma cong ty phai tra cho nhan vien: " << TongSoLuongPhaiTra << endl;
    LuongCaoNhat = DuLieu[0]->Luong();
    LuongThapNhat = DuLieu[0]->Luong();
    for (int i = 0; i < SoLuongNhanVien; i++)
    {
        if (DuLieu[i]->Luong() > LuongCaoNhat)
        {
            LuongCaoNhat = DuLieu[i]->Luong();
            Max = i;
        }
        if (DuLieu[i]->Luong() < LuongThapNhat)
        {
            LuongThapNhat = DuLieu[i]->Luong();
            Min = i;
        }
    }
    cout << "Nhan vien co muc luong cao nhat la: " << endl;
    DuLieu[Max]->Xuat();
    cout << endl;
    cout << "Nhan vien co muc luong thap nhat la: " << endl;
    DuLieu[Min]->Xuat();
    cout << endl;
}
int main()
{
    QuanLyNhanVien DuLieu;
    DuLieu.Nhap();
    DuLieu.Xuat();
    return 0;
}