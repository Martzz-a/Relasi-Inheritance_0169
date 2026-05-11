#ifndef IBU_H
#define IBU_H

#include <iostream>
#include <vector>
#include "anak.h"
using namespace std;

class ibu {
public:
    string nama;
    vector<anak*> daftar_anak;
    ibu(string pNama) : nama(pNama) {
        cout << "Ibu \"" << nama << "\" ada\n";
    }
    void tambahAnak(anak*);
    void cetakAnak();
    
};

void ibu::tambahAnak(anak* pAnak) {
    daftar_anak.push_back(pAnak);
}

void ibu::cetakAnak() {
    cout << "Daftar Anak dari Ibu \"" << this->nama << "\":\n";
    for (auto &a : daftar_anak) {
        cout << a->nama << "\n";
    }
}
#endif