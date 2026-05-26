#ifndef GIAODICH_H
#define GIAODICH_H
#include <bits/stdc++.h>
using namespace std;

class GiaoDich {
    protected:
        string MaGiaoDich;
        int Ngay, Thang, Nam;
        double DonGia, DienTich, ThanhTien;
    public:
        GiaoDich();

        virtual void Nhap();
        virtual void Xuat();
        virtual void TinhThanhTien();

        double getThanhTien() const;
        int getThang() const;
        int getNam() const;

        virtual ~GiaoDich();
};

class GiaoDichDat : public GiaoDich {
    private:
        string LoaiDat;
    public:
        GiaoDichDat();
        void Nhap();
        void Xuat();
        void TinhThanhTien();
};

class GiaoDichNhaPho : public GiaoDich {
    private:
        string LoaiNha, DiaChi;
    public:
        GiaoDichNhaPho();
        void Nhap();
        void Xuat();
        void TinhThanhTien();
};

class GiaoDichCanHo : public GiaoDich {
    private:
        string MaCan;
        int ViTriTang;
    public:
        GiaoDichCanHo();
        void Nhap();
        void Xuat();
        void TinhThanhTien();
};

#endif
