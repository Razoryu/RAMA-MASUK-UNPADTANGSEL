#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Motor{
    string merk;
    string plat;
    string status;
    string jenis;
};

Motor dataMotor[200];
int jumlahData = 0;

void simpanKeFile(){
    ofstream file("rental.txt");
    for (int i = 0; i < jumlahData; i++){
        file << dataMotor[i].merk << "|"
             << dataMotor[i].plat << "|"
             << dataMotor[i].status << "|"
             << dataMotor[i].jenis << "\n";
    }
    file.close();
    cout << "Data berhasil disimpan ke rental.txt\n";
}

void bacaFile(){
    ifstream file("rental.txt");
    jumlahData = 0;

    while(file.good()){
        getline(file, dataMotor[jumlahData].merk, '|');
        getline(file, dataMotor[jumlahData].plat, '|');
        getline(file, dataMotor[jumlahData].status, '|');
        getline(file, dataMotor[jumlahData].jenis, '\n');

        if(dataMotor[jumlahData].merk != "")
            jumlahData++;
    }
    file.close();
}

void tambahMotor(){
    cin.ignore();

    cout << "Masukkan Merk: ";
    getline(cin, dataMotor[jumlahData].merk);

    cout << "Masukkan Plat Nomor: ";
    getline(cin, dataMotor[jumlahData].plat);

    cout << "Masukkan Status (Tersedia/Disewa): ";
    getline(cin, dataMotor[jumlahData].status);
    
    cout << "Masukkan Jenis (Moge/Biasa): ";
    getline(cin, dataMotor[jumlahData].jenis);

    jumlahData++;
    cout << "Data motor berhasil ditambahkan!\n";
}

void tampilkanMotor(){
    cout << "\n===== Daftar Motor =====\n";
    cout << "No\tMerk\tPlat\tStatus\tJenis\n";
    cout << "-------------------------------------\n";
    for(int i = 0; i < jumlahData; i++){
        cout << i + 1 << "\t"
             << dataMotor[i].merk << "\t"
             << dataMotor[i].plat << "\t"
             << dataMotor[i].status << "\t"
             << dataMotor[i].jenis << endl;
    }
}

void sortingMenu(){
    int pilih, arah;
    cout << "\n=== Sorting ===\n";
    cout << "1. Sort Berdasarkan Merk\n";
    cout << "2. Sort Berdasarkan Plat\n";
    cout << "3. Sort Berdasarkan Status\n";
    cout << "Pilih: ";
    cin >> pilih;

    cout << "Urutan:\n1. A - Z\n2. Z - A\nPilih: ";
    cin >> arah;

    for(int i = 0; i < jumlahData - 1; i++){
        int idx = i;
        for (int j = i + 1; j < jumlahData; j++){
            
            string a, b;
            if (pilih == 1){ a = dataMotor[j].merk; b = dataMotor[idx].merk;}
            else if (pilih == 2){ a = dataMotor[j].plat; b = dataMotor[idx].plat;}
            else if (pilih == 3){ a = dataMotor[j].status; b = dataMotor[idx].status;}

            if(arah == 1 && a < b) idx = j;
            if(arah == 2 && a > b) idx = j;
        }
        swap(dataMotor[i], dataMotor[idx]);
    }

    cout << "Sorting selesai!\n";
}

void cariMotor(){
    cin.ignore();
    string cari;

    cout << "Masukkan kata kunci plat: ";
    getline(cin, cari);

    bool ada = false;
    cout << "\nHasil pencarian:\n";
    for(int i = 0; i < jumlahData; i++){
        if(dataMotor[i].plat.find(cari) != string::npos){
            cout << dataMotor[i].merk << " | "
                 << dataMotor[i].plat << " | "
                 << dataMotor[i].status << " | "
                 << dataMotor[i].jenis << endl;
            ada = true;
        }
    }
    if(!ada)
        cout << "Tidak ada data yang cocok.\n";
}

void ubahStatus(){
    tampilkanMotor();
    
    if (jumlahData == 0) return;
    cin.ignore();
    string plat;
    cout << "\nMasukkan plat yang ingin diubah statusnya : ";
    getline(cin, plat);

    for(int i = 0; i < jumlahData; i++){
        if(dataMotor[i].plat == plat){
            cout << "\nMotor ditemukan.\n";
            cout << "Merk : " << dataMotor[i].merk << endl;
            cout << "Plat : " << dataMotor[i].plat << endl;
            cout << "Status sekarang : " << dataMotor[i].status << endl;
            cout << "Masukkan status baru (Tersedia/Disewa) : ";
            getline(cin, dataMotor[i].status);
            cout << "Status berhasil diubah menjadi : " << dataMotor[i].status << endl;
            return;
        }
    }
    cout << "Motor tidak ditemukan.\n";
}

void hapusMotor(){
    tampilkanMotor();
    
    if (jumlahData == 0) return;
    cin.ignore();
    string plat;
    cout << "Masukkan plat motor yang akan dihapus : ";
    getline(cin, plat);

    for(int i = 0; i < jumlahData; i++){
        if(dataMotor[i].plat == plat){
            for(int j = i; j < jumlahData - 1; j++){
                dataMotor[j] = dataMotor[j + 1];
            }
            jumlahData--;
            cout << "Data motor berhasil dihapus.\n";
            return;
        }
    }
    cout << "Motor tidak ditemukan.\n";
}

void partitionMotor(){
    cout << "\n=== MOTOR GEDE (MOGE) ===\n";
    cout << "Merk\tPlat\tStatus\n";
    cout << "----------------------------------\n";

    for (int i = 0; i < jumlahData; i++){
        if (dataMotor[i].jenis == "Moge"){
            cout << dataMotor[i].merk << "\t"
                 << dataMotor[i].plat << "\t"
                 << dataMotor[i].status << endl;
        }
    }

    cout << "\n=== MOTOR BIASA ===\n";
    cout << "Merk\tPlat\tStatus\n";
    cout << "----------------------------------\n";
    
    for (int i = 0; i < jumlahData; i++){
        if (dataMotor[i].jenis != "Moge"){
            cout << dataMotor[i].merk << "\t"
                 << dataMotor[i].plat << "\t"
                 << dataMotor[i].status << endl;
        }
    }
}

int main(){
    bacaFile();

    int pilih;
    do{
        cout << "\n===== MENU RENTAL MOTOR =====\n";
        cout << "1. Tambah Data Motor\n";
        cout << "2. Tampilkan Daftar Motor\n";
        cout << "3. Ubah Status Motor\n";
        cout << "4. Cari Motor (partial search)\n";
        cout << "5. Hapus Data Motor\n";
        cout << "6. Sorting (A-Z, Z-A, Merk/Plat/Status)\n";
        cout << "7. Partition Motor (Moge/Biasa)\n";
        cout << "8. Simpan & Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih){
            case 1: tambahMotor(); break;
            case 2: tampilkanMotor(); break;
            case 3: ubahStatus(); break;
            case 4: cariMotor(); break;
            case 5: hapusMotor(); break;
            case 6: sortingMenu(); break;
            case 7: partitionMotor(); break;
            case 8: simpanKeFile(); cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } 

    while(pilih != 8);
    return 0;
}
