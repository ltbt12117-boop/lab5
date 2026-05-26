#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <bits/stdc++.h>
using namespace std;

class NhanVien {
    protected:
        string MaNhanVien, HoTen, SoDienThoai, Email;
        int Tuoi;
        long long LuongCoBan, Luong;
    public:
        NhanVien();

        virtual void Nhap();
        virtual void Xuat();
        virtual void TinhLuong();

        long long getLuong() const;

        virtual ~NhanVien();
};

class LapTrinhVien : public NhanVien {
    private:
        int SoGioOvertime;
    public:
        LapTrinhVien();
        void Nhap();
        void Xuat();
        void TinhLuong();
};

class KiemChungVien : public NhanVien {
    private:
        int SoLoiPhatHien;
    public:
        KiemChungVien();
        void Nhap();
        void Xuat();
        void TinhLuong();
};

#endif
