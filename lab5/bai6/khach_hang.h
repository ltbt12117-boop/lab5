#ifndef KHACHHANG_H
#define KHACHHANG_H
#include <bits/stdc++.h>
using namespace std;

class KhachHang {
    protected:
        string TenKhachHang;
        int SoLuongHang;
        double DonGiaHang, ThueVAT;
    public:
        KhachHang();

        virtual void Nhap(ifstream &fin);
        virtual void Xuat(ofstream &fout) const;
        virtual double TinhTienPhaiTra() const;

        virtual ~KhachHang();
};

class KhachHangLoaiA : public KhachHang {
    public:
        KhachHangLoaiA();
        void Nhap(ifstream &fin);
        void Xuat(ofstream &fout) const;
        double TinhTienPhaiTra() const;
};

class KhachHangLoaiB : public KhachHang {
    private:
        int SoNamThanThiet;
    public:
        KhachHangLoaiB();
        void Nhap(ifstream &fin);
        void Xuat(ofstream &fout) const;
        double TinhTienPhaiTra() const;
};

class KhachHangLoaiC : public KhachHang {
    public:
        KhachHangLoaiC();
        void Nhap(ifstream &fin);
        void Xuat(ofstream &fout) const;
        double TinhTienPhaiTra() const;
};

#endif
