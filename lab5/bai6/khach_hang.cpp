#include <bits/stdc++.h>
using namespace std;
#include "khach_hang.h"

KhachHang :: KhachHang(){
    TenKhachHang = "";
    SoLuongHang = 0;
    DonGiaHang = 0;
    ThueVAT = 0.1;
}

void KhachHang :: Nhap(ifstream &fin){
    fin >> ws;
    getline(fin, TenKhachHang);
    fin >> SoLuongHang;
    fin >> DonGiaHang;
}

void KhachHang :: Xuat(ofstream &fout) const{
    fout << TenKhachHang << endl;
    fout << fixed << setprecision(0) << TinhTienPhaiTra() << endl;
}

double KhachHang :: TinhTienPhaiTra() const{
    return 0;
}

KhachHang :: ~KhachHang(){
}

// khach hang loai A
KhachHangLoaiA :: KhachHangLoaiA(){
}

void KhachHangLoaiA :: Nhap(ifstream &fin){
    KhachHang :: Nhap(fin);
}

double KhachHangLoaiA :: TinhTienPhaiTra() const{
    double tienHang = SoLuongHang * DonGiaHang;
    return tienHang + tienHang * ThueVAT;
}

void KhachHangLoaiA :: Xuat(ofstream &fout) const{
    KhachHang :: Xuat(fout);
}

// khach hang loai B
KhachHangLoaiB :: KhachHangLoaiB(){
    SoNamThanThiet = 0;
}

void KhachHangLoaiB :: Nhap(ifstream &fin){
    KhachHang :: Nhap(fin);
    fin >> SoNamThanThiet;
}

double KhachHangLoaiB :: TinhTienPhaiTra() const{
    double phanTramKhuyenMai = SoNamThanThiet * 0.05;
    if (phanTramKhuyenMai > 0.5){
        phanTramKhuyenMai = 0.5;
    }

    double tienHang = SoLuongHang * DonGiaHang;
    double tienSauKhuyenMai = tienHang * (1 - phanTramKhuyenMai);

    return tienSauKhuyenMai + tienSauKhuyenMai * ThueVAT;
}

void KhachHangLoaiB :: Xuat(ofstream &fout) const{
    KhachHang :: Xuat(fout);
}

// khach hang loai C
KhachHangLoaiC :: KhachHangLoaiC(){
}

void KhachHangLoaiC :: Nhap(ifstream &fin){
    KhachHang :: Nhap(fin);
}

double KhachHangLoaiC :: TinhTienPhaiTra() const{
    double tienHang = SoLuongHang * DonGiaHang * 0.5;
    return tienHang + tienHang * ThueVAT;
}

void KhachHangLoaiC :: Xuat(ofstream &fout) const{
    KhachHang :: Xuat(fout);
}
