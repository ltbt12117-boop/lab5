#include <bits/stdc++.h>
#include "giao_dich.h"
#include "giao_dich.cpp"
using namespace std;

int main(){
    int nDat, nNhaPho, nCanHo;
    vector<GiaoDich*> ds;
    vector<GiaoDichNhaPho*> dsNhaPho;
    vector<GiaoDichCanHo*> dsCanHo;

    cout << "Nhap so luong giao dich dat: ";
    cin >> nDat;
    for (int i = 0; i < nDat; i++){
        cout << "\nNhap thong tin giao dich dat thu " << i + 1 << ":" << endl;
        GiaoDichDat *gd = new GiaoDichDat();
        gd->Nhap();
        ds.push_back(gd);
    }

    cout << "\nNhap so luong giao dich nha pho: ";
    cin >> nNhaPho;
    for (int i = 0; i < nNhaPho; i++){
        cout << "\nNhap thong tin giao dich nha pho thu " << i + 1 << ":" << endl;
        GiaoDichNhaPho *gd = new GiaoDichNhaPho();
        gd->Nhap();
        ds.push_back(gd);
        dsNhaPho.push_back(gd);
    }

    cout << "\nNhap so luong giao dich can ho chung cu: ";
    cin >> nCanHo;
    for (int i = 0; i < nCanHo; i++){
        cout << "\nNhap thong tin giao dich can ho chung cu thu " << i + 1 << ":" << endl;
        GiaoDichCanHo *gd = new GiaoDichCanHo();
        gd->Nhap();
        ds.push_back(gd);
        dsCanHo.push_back(gd);
    }

    cout << "\nTong so luong tung loai" << endl;
    cout << "Giao dich dat: " << nDat << endl;
    cout << "Giao dich nha pho: " << nNhaPho << endl;
    cout << "Giao dich can ho chung cu: " << nCanHo << endl;

    if (nCanHo > 0){
        double tongThanhTienCanHo = 0;
        for (int i = 0; i < nCanHo; i++){
            tongThanhTienCanHo += dsCanHo[i]->getThanhTien();
        }
        cout << "\nTrung binh thanh tien giao dich can ho chung cu: "
             << tongThanhTienCanHo / nCanHo << endl;
    }
    else {
        cout << "\nKhong co giao dich can ho chung cu de tinh trung binh." << endl;
    }

    if (nNhaPho > 0){
        int vtMax = 0;
        for (int i = 1; i < nNhaPho; i++){
            if (dsNhaPho[i]->getThanhTien() > dsNhaPho[vtMax]->getThanhTien()){
                vtMax = i;
            }
        }
        cout << "\nGiao dich nha pho co tri gia cao nhat la:" << endl;
        dsNhaPho[vtMax]->Xuat();
    }
    else {
        cout << "\nKhong co giao dich nha pho." << endl;
    }

    cout << "\nDanh sach giao dich thang 12 nam 2024" << endl;
    bool coGiaoDich = false;
    for (int i = 0; i < (int)ds.size(); i++){
        if (ds[i]->getThang() == 12 && ds[i]->getNam() == 2024){
            ds[i]->Xuat();
            coGiaoDich = true;
        }
    }

    if (!coGiaoDich){
        cout << "Khong co giao dich nao trong thang 12 nam 2024." << endl;
    }

    for (int i = 0; i < (int)ds.size(); i++){
        delete ds[i];
    }

    return 0;
}
