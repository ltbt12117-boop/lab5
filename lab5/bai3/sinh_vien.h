#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <bits/stdc++.h>
using namespace std;

class SinhVien {
    protected:
        string MaSo, HoTen, DiaChi;
        int TongTinChi;
        double DiemTrungBinh;
    public:
        SinhVien();

        virtual void Nhap();
        virtual void Xuat();
        virtual bool XetTotNghiep();

        double getDiemTrungBinh() const;

        virtual ~SinhVien();
};

class SinhVienCaoDang : public SinhVien {
    private:
        double DiemThiTotNghiep;
    public:
        SinhVienCaoDang();
        void Nhap();
        void Xuat();
        bool XetTotNghiep();
};

class SinhVienDaiHoc : public SinhVien {
    private:
        string TenLuanVan;
        double DiemLuanVan;
    public:
        SinhVienDaiHoc();
        void Nhap();
        void Xuat();
        bool XetTotNghiep();
};

#endif
