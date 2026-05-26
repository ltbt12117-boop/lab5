#include <bits/stdc++.h>
#include "sinh_vien.h"
#include "sinh_vien.cpp"
using namespace std;

int main(){
    int nCaoDang, nDaiHoc;
    vector<SinhVien*> ds;
    vector<SinhVienCaoDang*> dsCaoDang;
    vector<SinhVienDaiHoc*> dsDaiHoc;

    cout << "Nhap so luong sinh vien cao dang: ";
    cin >> nCaoDang;
    for (int i = 0; i < nCaoDang; i++){
        cout << "\nNhap thong tin sinh vien cao dang thu " << i + 1 << ":" << endl;
        SinhVienCaoDang *sv = new SinhVienCaoDang();
        sv->Nhap();
        ds.push_back(sv);
        dsCaoDang.push_back(sv);
    }

    cout << "\nNhap so luong sinh vien dai hoc: ";
    cin >> nDaiHoc;
    for (int i = 0; i < nDaiHoc; i++){
        cout << "\nNhap thong tin sinh vien dai hoc thu " << i + 1 << ":" << endl;
        SinhVienDaiHoc *sv = new SinhVienDaiHoc();
        sv->Nhap();
        ds.push_back(sv);
        dsDaiHoc.push_back(sv);
    }

    cout << "\n===== Danh sach sinh vien =====" << endl;
    for (int i = 0; i < (int)ds.size(); i++){
        ds[i]->Xuat();
    }

    cout << "\n===== Danh sach sinh vien du dieu kien tot nghiep =====" << endl;
    bool coTotNghiep = false;
    for (int i = 0; i < (int)ds.size(); i++){
        if (ds[i]->XetTotNghiep()){
            ds[i]->Xuat();
            coTotNghiep = true;
        }
    }
    if (!coTotNghiep){
        cout << "Khong co sinh vien nao du dieu kien tot nghiep." << endl;
    }

    cout << "\n===== Danh sach sinh vien khong du dieu kien tot nghiep =====" << endl;
    bool coKhongTotNghiep = false;
    for (int i = 0; i < (int)ds.size(); i++){
        if (!ds[i]->XetTotNghiep()){
            ds[i]->Xuat();
            coKhongTotNghiep = true;
        }
    }
    if (!coKhongTotNghiep){
        cout << "Tat ca sinh vien deu du dieu kien tot nghiep." << endl;
    }

    if (nDaiHoc > 0){
        int vtMax = 0;
        for (int i = 1; i < nDaiHoc; i++){
            if (dsDaiHoc[i]->getDiemTrungBinh() > dsDaiHoc[vtMax]->getDiemTrungBinh()){
                vtMax = i;
            }
        }
        cout << "\nSinh vien dai hoc co diem trung binh cao nhat la:" << endl;
        dsDaiHoc[vtMax]->Xuat();
    }
    else {
        cout << "\nKhong co sinh vien dai hoc." << endl;
    }

    if (nCaoDang > 0){
        int vtMax = 0;
        for (int i = 1; i < nCaoDang; i++){
            if (dsCaoDang[i]->getDiemTrungBinh() > dsCaoDang[vtMax]->getDiemTrungBinh()){
                vtMax = i;
            }
        }
        cout << "\nSinh vien cao dang co diem trung binh cao nhat la:" << endl;
        dsCaoDang[vtMax]->Xuat();
    }
    else {
        cout << "\nKhong co sinh vien cao dang." << endl;
    }

    int soCaoDangKhongTotNghiep = 0;
    int soDaiHocKhongTotNghiep = 0;

    for (int i = 0; i < nCaoDang; i++){
        if (!dsCaoDang[i]->XetTotNghiep()){
            soCaoDangKhongTotNghiep++;
        }
    }

    for (int i = 0; i < nDaiHoc; i++){
        if (!dsDaiHoc[i]->XetTotNghiep()){
            soDaiHocKhongTotNghiep++;
        }
    }

    cout << "\n===== So sinh vien khong du dieu kien tot nghiep tung loai =====" << endl;
    cout << "Sinh vien cao dang: " << soCaoDangKhongTotNghiep << endl;
    cout << "Sinh vien dai hoc: " << soDaiHocKhongTotNghiep << endl;

    for (int i = 0; i < (int)ds.size(); i++){
        delete ds[i];
    }

    return 0;
}
