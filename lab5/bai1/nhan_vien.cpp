#include <bits/stdc++.h>
using namespace std;
#include "nhan_vien.h"

NhanVien :: NhanVien (){
    HoTen ="";
    NgaySinh = 1;
    ThangSinh = 1;
    NamSinh = 1;
    Luong = 0;
}

void NhanVien :: Nhap (){
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline (cin, HoTen);

    cout << "Nhap ngay sinh: ";
    cin >> NgaySinh;

    cout << "Nhap thang sinh: ";
    cin >> ThangSinh;

    cout << "Nhap nam sinh: ";
    cin >> NamSinh;
}

void NhanVien :: Xuat(){
    cout << "Ho Ten: " << HoTen << endl;
    cout << "Ngay sinh: " << NgaySinh << "/" << ThangSinh << "/" << NamSinh << endl;
    cout << "Luong: " << Luong << endl;
}

long long NhanVien :: getLuong() const{
    return Luong;
}

int NhanVien :: getNamSinh () const{
    return NamSinh;
}

void NhanVien :: TinhLuong(){
    Luong = 0;
}

NhanVien :: ~NhanVien(){
}

// lop nhan vien san xuat
NhanVienSX :: NhanVienSX(){
    LuongCanBan = 0;
    SoSanPham = 0;
}

void NhanVienSX :: Nhap (){
    NhanVien :: Nhap();
    cout << "Nhap luong can ban: ";
    cin >> LuongCanBan;

    cout << "Nhap so San Pham: ";
    cin >> SoSanPham;

    TinhLuong(); // tính lương luôn để gán giá trị vô Luong
} 

void NhanVienSX :: TinhLuong(){
    Luong = LuongCanBan + SoSanPham * 5000;
}

void NhanVienSX :: Xuat (){
    NhanVien :: Xuat ();
    cout << "Luong can ban la: " << LuongCanBan;
    cout << "\nSo san pham la: " << SoSanPham;
    cout << "\nLuong la: " << Luong;
}

// lop nhan vien van phong
NhanVienVP :: NhanVienVP(){
    SoNgayLamViec = 0;
}

void NhanVienVP :: Nhap(){
    NhanVien :: Nhap ();
    cout << "Nhap so ngay lam viec: ";
    cin >> SoNgayLamViec;

    TinhLuong();
}

void NhanVienVP :: TinhLuong(){
    Luong = SoNgayLamViec * 100000;
}

void NhanVienVP :: Xuat(){
    NhanVien :: Xuat ();
    cout << "So ngay lam viec la: " << SoNgayLamViec;
    cout << "\nLuong la: " << Luong;
}
