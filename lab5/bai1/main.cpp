#include <bits/stdc++.h>
#include "nhan_vien.h"
#include "nhan_vien.cpp"
using namespace std;

int main(){

    int n, m;

    cout << "Nhap so luong nhan vien san xuat: ";
    cin >> n;
    vector <NhanVienSX> dsSX(n);
    for (int i = 0; i < n; i++){
        cout << "\nNhap thong tin nhan vien san xuat thu " << i+1 << " : " << endl;
        dsSX[i].Nhap();
    }

    cout << "\nNhap so luong nhan vien van phong: ";
    cin >> m;
    vector <NhanVienVP> dsVP(m);
    for (int i=0; i < m; i++){
        cout << "\nNhap thong tin cua nhan vien van phong thu " << i+1 <<" : " << endl;
        dsVP[i].Nhap();
    }

    
    long long TongLuong = 0;
    
    for (int i=0; i<n; i++){
        cout << "\nThong tin nhan vien san xuat thu " << i+1 << " : " << endl;
        dsSX[i].Xuat();
        TongLuong += dsSX[i].getLuong();
    }
 
    for (int i=0; i<m; i++){
        cout << "\nThong tin nhan vien van phong thu " << i+1 << " : " << endl;
        dsVP[i].Xuat();
        TongLuong += dsVP[i].getLuong();
    }

    cout << "\nTong luong cong ty phai tra la: " << TongLuong << endl;

    
    if (n>0){
        long long lmin = 0;
        for (int i=1; i < n; i++){
            if (dsSX[i].getLuong() < dsSX[lmin].getLuong()){
                lmin = i;
            }
        }

        cout << "\nNhan vien SX co luong thap nhat la: \n";
        dsSX[lmin].Xuat();

    }


    if (m>0){
        int tmax = 0;
        for (int i=1; i<m; i++){
            if (dsVP[i].getNamSinh() < dsVP[tmax].getNamSinh()){
                tmax = i;
            }
        }
        cout << "\nNhan vien VP co tuoi cao nhat la: \n";
        dsVP[tmax].Xuat();
    }
    
    return 0;
}