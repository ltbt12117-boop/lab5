#include <bits/stdc++.h>
using namespace std;
#include "nhan_vien.h"

NhanVien :: NhanVien(){
    MaNhanVien = "";
    HoTen = "";
    SoDienThoai = "";
    Email = "";
    Tuoi = 0;
    LuongCoBan = 0;
    Luong = 0;
}

void NhanVien :: Nhap(){
    cin.ignore();
    cout << "Nhap ma nhan vien: ";
    getline(cin, MaNhanVien);

    cout << "Nhap ho ten: ";
    getline(cin, HoTen);

    cout << "Nhap tuoi: ";
    cin >> Tuoi;
    cin.ignore();

    cout << "Nhap so dien thoai: ";
    getline(cin, SoDienThoai);

    cout << "Nhap email: ";
    getline(cin, Email);

    cout << "Nhap luong co ban: ";
    cin >> LuongCoBan;
}

void NhanVien :: Xuat(){
    cout << "Ma nhan vien: " << MaNhanVien << endl;
    cout << "Ho ten: " << HoTen << endl;
    cout << "Tuoi: " << Tuoi << endl;
    cout << "So dien thoai: " << SoDienThoai << endl;
    cout << "Email: " << Email << endl;
    cout << "Luong co ban: " << LuongCoBan << endl;
    cout << "Luong: " << Luong << endl;
}

void NhanVien :: TinhLuong(){
    Luong = 0;
}

long long NhanVien :: getLuong() const{
    return Luong;
}

NhanVien :: ~NhanVien(){
}

// lop lap trinh vien
LapTrinhVien :: LapTrinhVien(){
    SoGioOvertime = 0;
}

void LapTrinhVien :: Nhap(){
    NhanVien :: Nhap();

    cout << "Nhap so gio overtime: ";
    cin >> SoGioOvertime;

    TinhLuong();
}

void LapTrinhVien :: TinhLuong(){
    Luong = LuongCoBan + SoGioOvertime * 200000;
}

void LapTrinhVien :: Xuat(){
    cout << "\nLap trinh vien" << endl;
    NhanVien :: Xuat();
    cout << "So gio overtime: " << SoGioOvertime << endl;
}

// lop kiem chung vien
KiemChungVien :: KiemChungVien(){
    SoLoiPhatHien = 0;
}

void KiemChungVien :: Nhap(){
    NhanVien :: Nhap();

    cout << "Nhap so loi phat hien: ";
    cin >> SoLoiPhatHien;

    TinhLuong();
}

void KiemChungVien :: TinhLuong(){
    Luong = LuongCoBan + SoLoiPhatHien * 50000;
}

void KiemChungVien :: Xuat(){
    cout << "\nKiem chung vien" << endl;
    NhanVien :: Xuat();
    cout << "So loi phat hien: " << SoLoiPhatHien << endl;
}
