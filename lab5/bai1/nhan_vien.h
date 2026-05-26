#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <bits/stdc++.h>
using namespace std;

class NhanVien{
    protected:
        string HoTen;
        int NgaySinh, ThangSinh, NamSinh;
        long long Luong;
    public:
        NhanVien();
        
        virtual void Nhap();
        virtual void Xuat();
        virtual void TinhLuong();

        int getNamSinh() const;
        long long getLuong() const;

        virtual ~NhanVien();
};

class NhanVienSX : public NhanVien {
    private:
        long long LuongCanBan;
        int SoSanPham;
    public:
        NhanVienSX ();
        void Nhap();
        void Xuat();
        void TinhLuong();
};

class NhanVienVP : public NhanVien {
    private:
        long long SoNgayLamViec;
    public:
        NhanVienVP();
        void Nhap();
        void Xuat();
        void TinhLuong();
};

#endif