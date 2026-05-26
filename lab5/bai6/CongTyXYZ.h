#ifndef CONGTYXYZ_H
#define CONGTYXYZ_H
#include <bits/stdc++.h>
#include "khach_hang.h"
using namespace std;

class CongTyXYZ {
    private:
        KhachHang **dsKhachHang;
        int TongSoKhachHang;
    public:
        CongTyXYZ();
        ~CongTyXYZ();

        void NhapDSKHTuFile(string tenFile);
        void XuatKQRaFile(string tenFile) const;

        double TinhTongSoTienCongTyThuDuoc() const;
};

#endif
