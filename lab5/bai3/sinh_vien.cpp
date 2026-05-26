#include <bits/stdc++.h>
using namespace std;
#include "sinh_vien.h"

SinhVien :: SinhVien(){
    MaSo = "";
    HoTen = "";
    DiaChi = "";
    TongTinChi = 0;
    DiemTrungBinh = 0;
}

void SinhVien :: Nhap(){
    cin.ignore();
    cout << "Nhap ma so sinh vien: ";
    getline(cin, MaSo);

    cout << "Nhap ho ten: ";
    getline(cin, HoTen);

    cout << "Nhap dia chi: ";
    getline(cin, DiaChi);

    cout << "Nhap tong so tin chi: ";
    cin >> TongTinChi;

    cout << "Nhap diem trung binh: ";
    cin >> DiemTrungBinh;
}

void SinhVien :: Xuat(){
    cout << "Ma so sinh vien: " << MaSo << endl;
    cout << "Ho ten: " << HoTen << endl;
    cout << "Dia chi: " << DiaChi << endl;
    cout << "Tong so tin chi: " << TongTinChi << endl;
    cout << "Diem trung binh: " << DiemTrungBinh << endl;
}

bool SinhVien :: XetTotNghiep(){
    return false;
}

double SinhVien :: getDiemTrungBinh() const{
    return DiemTrungBinh;
}

SinhVien :: ~SinhVien(){
}

// lop sinh vien cao dang
SinhVienCaoDang :: SinhVienCaoDang(){
    DiemThiTotNghiep = 0;
}

void SinhVienCaoDang :: Nhap(){
    SinhVien :: Nhap();

    cout << "Nhap diem thi tot nghiep: ";
    cin >> DiemThiTotNghiep;
}

bool SinhVienCaoDang :: XetTotNghiep(){
    return TongTinChi >= 120 && DiemTrungBinh >= 5 && DiemThiTotNghiep >= 5;
}

void SinhVienCaoDang :: Xuat(){
    cout << "\nSinh vien cao dang" << endl;
    SinhVien :: Xuat();
    cout << "Diem thi tot nghiep: " << DiemThiTotNghiep << endl;
}

// lop sinh vien dai hoc
SinhVienDaiHoc :: SinhVienDaiHoc(){
    TenLuanVan = "";
    DiemLuanVan = 0;
}

void SinhVienDaiHoc :: Nhap(){
    SinhVien :: Nhap();
    cin.ignore();

    cout << "Nhap ten luan van: ";
    getline(cin, TenLuanVan);

    cout << "Nhap diem luan van: ";
    cin >> DiemLuanVan;
}

bool SinhVienDaiHoc :: XetTotNghiep(){
    return TongTinChi >= 170 && DiemTrungBinh >= 5 && DiemLuanVan >= 5;
}

void SinhVienDaiHoc :: Xuat(){
    cout << "\nSinh vien dai hoc" << endl;
    SinhVien :: Xuat();
    cout << "Ten luan van: " << TenLuanVan << endl;
    cout << "Diem luan van: " << DiemLuanVan << endl;
}
