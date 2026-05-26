#include <bits/stdc++.h>
#include "CongTyXYZ.h"
#include "CongTyXYZ.cpp"
using namespace std;

int main(){
    CongTyXYZ ct;
    string inputFile = "XYZ.INP";
    string outputFile = "XYZ.OUT";
    ifstream fin(inputFile);

    if (!fin){
        inputFile = "bai6/XYZ.INP";
        outputFile = "bai6/XYZ.OUT";
    }
    else {
        fin.close();
    }

    ct.NhapDSKHTuFile(inputFile);
    ct.XuatKQRaFile(outputFile);

    return 0;
}
