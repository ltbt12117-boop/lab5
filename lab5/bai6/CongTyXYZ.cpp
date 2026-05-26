#include <bits/stdc++.h>
using namespace std;
#include "CongTyXYZ.h"
#include "khach_hang.cpp"

CongTyXYZ :: CongTyXYZ(){
    dsKhachHang = NULL;
    TongSoKhachHang = 0;
}

CongTyXYZ :: ~CongTyXYZ(){
    for (int i = 0; i < TongSoKhachHang; i++){
        delete dsKhachHang[i];
    }

    delete[] dsKhachHang;
}

void CongTyXYZ :: NhapDSKHTuFile(string tenFile){
    ifstream fin(tenFile);

    if (!fin){
        cout << "Khong mo duoc file " << tenFile << endl;
        return;
    }

    int x, y, z;
    fin >> x >> y >> z;

    TongSoKhachHang = x + y + z;
    dsKhachHang = new KhachHang*[TongSoKhachHang];

    int k = 0;

    for (int i = 0; i < x; i++){
        dsKhachHang[k] = new KhachHangLoaiA();
        dsKhachHang[k]->Nhap(fin);
        k++;
    }

    for (int i = 0; i < y; i++){
        dsKhachHang[k] = new KhachHangLoaiB();
        dsKhachHang[k]->Nhap(fin);
        k++;
    }

    for (int i = 0; i < z; i++){
        dsKhachHang[k] = new KhachHangLoaiC();
        dsKhachHang[k]->Nhap(fin);
        k++;
    }

    fin.close();
}

double CongTyXYZ :: TinhTongSoTienCongTyThuDuoc() const{
    double tong = 0;

    for (int i = 0; i < TongSoKhachHang; i++){
        tong += dsKhachHang[i]->TinhTienPhaiTra();
    }

    return tong;
}

void CongTyXYZ :: XuatKQRaFile(string tenFile) const{
    ofstream fout(tenFile);

    for (int i = 0; i < TongSoKhachHang; i++){
        dsKhachHang[i]->Xuat(fout);
        fout << endl;
    }

    fout << "Tong so tien cong ty thu duoc la: ";
    fout << fixed << setprecision(0) << TinhTongSoTienCongTyThuDuoc();

    fout.close();
}
