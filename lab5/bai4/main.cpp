#include <bits/stdc++.h>
#include "nhan_vien.h"
#include "nhan_vien.cpp"
using namespace std;

int main(){
    int nLapTrinhVien, nKiemChungVien;
    vector<NhanVien*> ds;
    vector<LapTrinhVien*> dsLapTrinhVien;
    vector<KiemChungVien*> dsKiemChungVien;

    cout << "Nhap so luong lap trinh vien: ";
    cin >> nLapTrinhVien;
    for (int i = 0; i < nLapTrinhVien; i++){
        cout << "\nNhap thong tin lap trinh vien thu " << i + 1 << ":" << endl;
        LapTrinhVien *nv = new LapTrinhVien();
        nv->Nhap();
        ds.push_back(nv);
        dsLapTrinhVien.push_back(nv);
    }

    cout << "\nNhap so luong kiem chung vien: ";
    cin >> nKiemChungVien;
    for (int i = 0; i < nKiemChungVien; i++){
        cout << "\nNhap thong tin kiem chung vien thu " << i + 1 << ":" << endl;
        KiemChungVien *nv = new KiemChungVien();
        nv->Nhap();
        ds.push_back(nv);
        dsKiemChungVien.push_back(nv);
    }

    cout << "\nDanh sach nhan vien" << endl;
    for (int i = 0; i < (int)ds.size(); i++){
        ds[i]->Xuat();
    }

    if (ds.empty()){
        cout << "\nDanh sach nhan vien rong." << endl;
        return 0;
    }

    long long tongLuong = 0;
    for (int i = 0; i < (int)ds.size(); i++){
        tongLuong += ds[i]->getLuong();
    }
    double luongTrungBinh = (double)tongLuong / ds.size();

    cout << fixed << setprecision(0);
    cout << "\nLuong trung binh cua cong ty: " << luongTrungBinh << endl;
    cout << "\nDanh sach nhan vien co luong thap hon luong trung binh" << endl;
    bool coLuongThapHonTrungBinh = false;
    for (int i = 0; i < (int)ds.size(); i++){
        if (ds[i]->getLuong() < luongTrungBinh){
            ds[i]->Xuat();
            coLuongThapHonTrungBinh = true;
        }
    }
    if (!coLuongThapHonTrungBinh){
        cout << "Khong co nhan vien nao co luong thap hon luong trung binh." << endl;
    }

    int vtLuongCaoNhat = 0;
    int vtLuongThapNhat = 0;
    for (int i = 1; i < (int)ds.size(); i++){
        if (ds[i]->getLuong() > ds[vtLuongCaoNhat]->getLuong()){
            vtLuongCaoNhat = i;
        }
        if (ds[i]->getLuong() < ds[vtLuongThapNhat]->getLuong()){
            vtLuongThapNhat = i;
        }
    }

    cout << "\nNhan vien co luong cao nhat la:" << endl;
    ds[vtLuongCaoNhat]->Xuat();

    cout << "\nNhan vien co luong thap nhat la:" << endl;
    ds[vtLuongThapNhat]->Xuat();

    if (nLapTrinhVien > 0){
        int vtMax = 0;
        for (int i = 1; i < nLapTrinhVien; i++){
            if (dsLapTrinhVien[i]->getLuong() > dsLapTrinhVien[vtMax]->getLuong()){
                vtMax = i;
            }
        }
        cout << "\nLap trinh vien co luong cao nhat la:" << endl;
        dsLapTrinhVien[vtMax]->Xuat();
    }
    else {
        cout << "\nKhong co lap trinh vien." << endl;
    }

    if (nKiemChungVien > 0){
        int vtMin = 0;
        for (int i = 1; i < nKiemChungVien; i++){
            if (dsKiemChungVien[i]->getLuong() < dsKiemChungVien[vtMin]->getLuong()){
                vtMin = i;
            }
        }
        cout << "\nKiem chung vien co luong thap nhat la:" << endl;
        dsKiemChungVien[vtMin]->Xuat();
    }
    else {
        cout << "\nKhong co kiem chung vien." << endl;
    }

    for (int i = 0; i < (int)ds.size(); i++){
        delete ds[i];
    }

    return 0;
}
