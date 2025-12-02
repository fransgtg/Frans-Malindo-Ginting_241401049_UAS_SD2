#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Pelanggan {
    string nama;
    int berat;
    string layanan;
    int waktu_proses; 
    int urutan_datang;
};

int hitungWaktu(int berat, const string& layanan) {
    if (layanan == "express") {
        return berat * 5; 
    } else {
        return berat * 10; 
    }
}

void urutan() {
    int n;
    if (!(cin >> n)) return; 

    vector<Pelanggan> express_list;
    vector<Pelanggan> reguler_list;
    int total_waktu = 0;

    for (int i = 0; i < n; ++i) {
        string nama, layanan;
        int berat;

        cin >> nama >> berat >> layanan; 

        Pelanggan p;
        p.nama = nama;
        p.berat = berat;
        p.layanan = layanan;
        p.waktu_proses = hitungWaktu(berat, layanan);
        p.urutan_datang = i;

        if (layanan == "express") {
            express_list.push_back(p);
        } else {
            reguler_list.push_back(p);
        }
    }

    vector<Pelanggan> urutan_akhir;
    urutan_akhir.insert(urutan_akhir.end(), express_list.begin(), express_list.end());
    urutan_akhir.insert(urutan_akhir.end(), reguler_list.begin(), reguler_list.end());


    cout << "Urutan: ";
    for (size_t i = 0; i < urutan_akhir.size(); ++i) {
        cout << urutan_akhir[i].nama;
        total_waktu += urutan_akhir[i].waktu_proses;
        
        if (i < urutan_akhir.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    cout << "Total waktu: " << total_waktu << " menit" << endl;
}

int main() {
    system("cls");
    urutan();
    
    return 0;
}