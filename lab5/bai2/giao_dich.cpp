#include <bits/stdc++.h>
using namespace std;
#include "giao_dich.h"

GiaoDich :: GiaoDich(){
    MaGiaoDich = "";
    Ngay = 1;
    Thang = 1;
    Nam = 1;
    DonGia = 0;
    DienTich = 0;
    ThanhTien = 0;
}

void GiaoDich :: Nhap(){
    cin.ignore();
    cout << "Nhap ma giao dich: ";
    getline(cin, MaGiaoDich);

    cout << "Nhap ngay giao dich: ";
    cin >> Ngay;

    cout << "Nhap thang giao dich: ";
    cin >> Thang;

    cout << "Nhap nam giao dich: ";
    cin >> Nam;

    cout << "Nhap don gia: ";
    cin >> DonGia;

    cout << "Nhap dien tich: ";
    cin >> DienTich;
}

void GiaoDich :: Xuat(){
    cout << "Ma giao dich: " << MaGiaoDich << endl;
    cout << "Ngay giao dich: " << Ngay << "/" << Thang << "/" << Nam << endl;
    cout << "Don gia: " << DonGia << endl;
    cout << "Dien tich: " << DienTich << endl;
    cout << "Thanh tien: " << ThanhTien << endl;
}

void GiaoDich :: TinhThanhTien(){
    ThanhTien = 0;
}

double GiaoDich :: getThanhTien() const{
    return ThanhTien;
}

int GiaoDich :: getThang() const{
    return Thang;
}

int GiaoDich :: getNam() const{
    return Nam;
}

GiaoDich :: ~GiaoDich(){
}

// lop giao dich dat
GiaoDichDat :: GiaoDichDat(){
    LoaiDat = "";
}

void GiaoDichDat :: Nhap(){
    GiaoDich :: Nhap();
    cin.ignore();
    cout << "Nhap loai dat (A/B/C): ";
    getline(cin, LoaiDat);

    TinhThanhTien();
}

void GiaoDichDat :: TinhThanhTien(){
    if (LoaiDat == "A" || LoaiDat == "a"){
        ThanhTien = DienTich * DonGia * 1.5;
    }
    else {
        ThanhTien = DienTich * DonGia;
    }
}

void GiaoDichDat :: Xuat(){
    cout << "\nGiao dich dat" << endl;
    GiaoDich :: Xuat();
    cout << "Loai dat: " << LoaiDat << endl;
}

// lop giao dich nha pho
GiaoDichNhaPho :: GiaoDichNhaPho(){
    LoaiNha = "";
    DiaChi = "";
}

void GiaoDichNhaPho :: Nhap(){
    GiaoDich :: Nhap();
    cin.ignore();
    cout << "Nhap loai nha (cao cap/thuong): ";
    getline(cin, LoaiNha);

    cout << "Nhap dia chi: ";
    getline(cin, DiaChi);

    TinhThanhTien();
}

void GiaoDichNhaPho :: TinhThanhTien(){
    if (LoaiNha == "cao cap" || LoaiNha == "Cao cap" || LoaiNha == "Cao Cap"){
        ThanhTien = DienTich * DonGia;
    }
    else {
        ThanhTien = DienTich * DonGia * 0.9;
    }
}

void GiaoDichNhaPho :: Xuat(){
    cout << "\nGiao dich nha pho" << endl;
    GiaoDich :: Xuat();
    cout << "Loai nha: " << LoaiNha << endl;
    cout << "Dia chi: " << DiaChi << endl;
}

// lop giao dich can ho chung cu
GiaoDichCanHo :: GiaoDichCanHo(){
    MaCan = "";
    ViTriTang = 0;
}

void GiaoDichCanHo :: Nhap(){
    GiaoDich :: Nhap();
    cin.ignore();
    cout << "Nhap ma can: ";
    getline(cin, MaCan);

    cout << "Nhap vi tri tang: ";
    cin >> ViTriTang;

    TinhThanhTien();
}

void GiaoDichCanHo :: TinhThanhTien(){
    if (ViTriTang == 1){
        ThanhTien = DienTich * DonGia * 2;
    }
    else if (ViTriTang >= 15){
        ThanhTien = DienTich * DonGia * 1.2;
    }
    else {
        ThanhTien = DienTich * DonGia;
    }
}

void GiaoDichCanHo :: Xuat(){
    cout << "\nGiao dich can ho chung cu" << endl;
    GiaoDich :: Xuat();
    cout << "Ma can: " << MaCan << endl;
    cout << "Vi tri tang: " << ViTriTang << endl;
}
