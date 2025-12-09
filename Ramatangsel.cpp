#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <windows.h> // buat fungsi sleep

using namespace std;

// definisi warna biar keren
#define RESET       "\033[0m"
#define HITAM       "\033[30m"
#define MERAH       "\033[31m"
#define HIJAU       "\033[32m"
#define KUNING      "\033[33m"
#define BIRU        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define PUTIH       "\033[37m"
#define TEBAL       "\033[1m"
#define ABU         "\033[90m"

// background warna
#define BG_MERAH    "\033[41m"
#define BG_HIJAU    "\033[42m"
#define BG_KUNING   "\033[43m"
#define BG_BIRU     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"

struct Motor{
    string merk;
    string plat;
    string status;
    string jenis;
};

Motor dataMotor[200];
int jumlahData = 0;

// fungsi bantuan

string toUpperCase(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

void pauseScreen() {
    cout << "\nTekan " << TEBAL << "Enter" << RESET << " untuk kembali...";
    cin.get(); 
    system("cls"); 
}

void headerLogo(){
    cout << CYAN;
    cout << "  ____      _    __  __    _      ____  _____ _   _ _____    _    _     \n";
    cout << " |  _ \\    / \\  |  \\/  |  / \\    |  _ \\| ____| \\ | |_   _|  / \\  | |    \n";
    cout << " | |_) |  / _ \\ | |\\/| | / _ \\   | |_) |  _| |  \\| | | |   / _ \\ | |    \n";
    cout << " |  _ <  / ___ \\| |  | |/ ___ \\  |  _ <| |___| |\\  | | |  / ___ \\| |___ \n";
    cout << " |_| \\_\\/_/   \\_\\_|  |_/_/   \\_\\ |_| \\_\\_____|_| \\_| |_| /_/   \\_\\_____|\n";
    cout << KUNING << "\n                       Sistem Manajemen Rental Motor" << RESET;
    cout << BIRU << "\n==========================================================================\n" << RESET;
}

// bagian data

bool cekPlatAda(string p){
    string pKapital = toUpperCase(p); 
    for(int i = 0; i < jumlahData; i++){
        if(dataMotor[i].plat == pKapital) return true;
    }
    return false;
}

void bacaFile(){
    ifstream file("rental.txt");
    jumlahData = 0;
    while(file.good()){
        string tempMerk, tempPlat, tempStatus, tempJenis;
        getline(file, tempMerk, '|');
        getline(file, tempPlat, '|');
        getline(file, tempStatus, '|');
        getline(file, tempJenis, '\n');
        if(tempMerk != ""){
            dataMotor[jumlahData].merk = tempMerk;
            dataMotor[jumlahData].plat = tempPlat;
            dataMotor[jumlahData].status = tempStatus;
            dataMotor[jumlahData].jenis = tempJenis;
            jumlahData++;
        }
    }
    file.close();
}

// fungsi simpan dan keluar yg udah dirombak
void simpanDanKeluar(){
    // tulis ke file txt
    ofstream file("rental.txt");
    for (int i = 0; i < jumlahData; i++){
        file << dataMotor[i].merk << "|" << dataMotor[i].plat << "|" 
             << dataMotor[i].status << "|" << dataMotor[i].jenis << "\n";
    }
    file.close();

    // info kalo udah kesimpen
    cout << "\n\t" << HIJAU << "[INFO] Data berhasil disimpan/ diamankan." << RESET << endl;
    
    // delay dikit
    Sleep(800); 

    // animasi loading bar
    system("cls");
    
    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t      " << CYAN << "Sedang Memuat..." << RESET << "\n\n";
    cout << "\t\t\t\t";

    // looping buat bar
    for (int i = 0; i < 26; i++) {
        cout << BG_HIJAU << " " << RESET; 
        Sleep(50); 
    }
    
    // bersihin layar
    system("cls");

    // tampilan hanupis dan credit
    cout << "\n\n\n";
    // tulisan hanupis di tengah
    cout << "\t\t\t                        " << KUNING << TEBAL << "HANUPIS!" << RESET << endl;
    cout << "\n";
    
    // kotak credit kelompok
    cout << "\t\t\t" << BIRU << "======================================================" << RESET << endl;
    cout << "\t\t\t" << BIRU << "|" << RESET << "                                                    " << BIRU << "|" << RESET << endl;
    // nama kelompok
    cout << "\t\t\t" << BIRU << "|" << RESET << "    Created By Kelompok Rama Masuk Unpad Tangsel    " << BIRU << "|" << RESET << endl;
    cout << "\t\t\t" << BIRU << "|" << RESET << "                                                    " << BIRU << "|" << RESET << endl;
    // garis tengah
    cout << "\t\t\t" << BIRU << "|" << ABU << "   ----------------------------------------------   " << BIRU << "|" << RESET << endl;
    cout << "\t\t\t" << BIRU << "|" << RESET << "                                                    " << BIRU << "|" << RESET << endl;
    // list anggota
    cout << "\t\t\t" << BIRU << "|" << RESET << "    1. Rangga Rassya Raditya       140810250041     " << BIRU << "|" << RESET << endl;
    cout << "\t\t\t" << BIRU << "|" << RESET << "    2. Muhammad Rama Naradya       140810250086     " << BIRU << "|" << RESET << endl;
    cout << "\t\t\t" << BIRU << "|" << RESET << "    3. M Rangga Tri Utama Abdillah 140810250095     " << BIRU << "|" << RESET << endl;
    cout << "\t\t\t" << BIRU << "|" << RESET << "                                                    " << BIRU << "|" << RESET << endl;
    cout << "\t\t\t" << BIRU << "======================================================" << RESET << endl;
    
    cout << "\n\n";
}

// fungsi buat nampilin data

void tampilkanMotor(){
    if (jumlahData == 0) {
        cout << MERAH << "\n[INFO] Data motor masih kosong!" << RESET << endl;
        return;
    }
    cout << "\n" << BIRU << "==========================================================================" << RESET << endl;
    cout << left << setw(4) << "No" << setw(25) << "Merk (Max 22)" << setw(15) << "Plat" << setw(15) << "Status" << setw(10) << "Jenis" << endl;
    cout << BIRU << "==========================================================================" << RESET << endl;
    for(int i = 0; i < jumlahData; i++){
        string warnaStatus = (dataMotor[i].status == "Tersedia") ? HIJAU : MERAH;
        // ganti moge jadi kuning
        string warnaJenis = (dataMotor[i].jenis == "Moge") ? KUNING : CYAN;
        
        cout << left << setw(4) << i + 1 
             << setw(25) << dataMotor[i].merk 
             << setw(15) << dataMotor[i].plat 
             << warnaStatus << setw(15) << dataMotor[i].status << RESET 
             << warnaJenis << setw(10) << dataMotor[i].jenis << RESET << endl;
    }
    cout << BIRU << "--------------------------------------------------------------------------" << RESET << endl;
}

void partitionMotor(){
    if (jumlahData == 0) {
        cout << MERAH << "\n[INFO] Data motor masih kosong!" << RESET << endl;
        return;
    }

    cout << "\n" << BG_BIRU << PUTIH << "   KATEGORI: MOTOR GEDE (MOGE)              " << RESET << endl;
    cout << BIRU << "--------------------------------------------------------------------------" << RESET << endl;
    cout << left << setw(25) << "Merk" << setw(15) << "Plat" << setw(15) << "Status" << endl;
    cout << BIRU << "--------------------------------------------------------------------------" << RESET << endl;
    
    int countMoge = 0;
    for (int i = 0; i < jumlahData; i++){
        if (dataMotor[i].jenis == "Moge"){
            string warnaStatus = (dataMotor[i].status == "Tersedia") ? HIJAU : MERAH;
            cout << left << setw(25) << dataMotor[i].merk 
                 << setw(15) << dataMotor[i].plat 
                 << warnaStatus << setw(15) << dataMotor[i].status << RESET << endl;
            countMoge++;
        }
    }
    if(countMoge == 0) cout << ABU << "   (Tidak ada data Moge)" << RESET << endl;

    cout << "\n" << BG_BIRU << PUTIH << "   KATEGORI: MOTOR BIASA (REGULER)        " << RESET << endl;
    cout << BIRU << "--------------------------------------------------------------------------" << RESET << endl;
    cout << left << setw(25) << "Merk" << setw(15) << "Plat" << setw(15) << "Status" << endl;
    cout << BIRU << "--------------------------------------------------------------------------" << RESET << endl;
    
    int countBiasa = 0;
    for (int i = 0; i < jumlahData; i++){
        if (dataMotor[i].jenis != "Moge"){
            string warnaStatus = (dataMotor[i].status == "Tersedia") ? HIJAU : MERAH;
            cout << left << setw(25) << dataMotor[i].merk 
                 << setw(15) << dataMotor[i].plat 
                 << warnaStatus << setw(15) << dataMotor[i].status << RESET << endl;
            countBiasa++;
        }
    }
    if(countBiasa == 0) cout << ABU << "   (Tidak ada data Motor Biasa)" << RESET << endl;
    
    cout << "\n" << ABU << "Total: " << countMoge << " Moge + " << countBiasa << " Biasa = " << jumlahData << " Motor." << RESET << endl;
}

void sortingLogic(){
    int pilih, arah;
    cout << "\n" << BG_KUNING << HITAM << " --- PENGATURAN SORTING --- " << RESET << endl;
    cout << CYAN << " Kategori : " << RESET << "[1] Merk   [2] Plat   [3] Status" << endl;
    cout << " Pilih    > "; cin >> pilih;
    cout << CYAN << " Urutan   : " << RESET << "[1] A-Z (Naik)   [2] Z-A (Turun)" << endl;
    cout << " Pilih    > "; cin >> arah;
    cin.ignore(); 

    for(int i = 0; i < jumlahData - 1; i++){
        int idx = i;
        for (int j = i + 1; j < jumlahData; j++){
            string a, b;
            if (pilih == 1){ a = dataMotor[j].merk; b = dataMotor[idx].merk;}
            else if (pilih == 2){ a = dataMotor[j].plat; b = dataMotor[idx].plat;}
            else { a = dataMotor[j].status; b = dataMotor[idx].status;} 
            
            if((arah == 1 && a < b) || (arah == 2 && a > b)) idx = j;
        }
        swap(dataMotor[i], dataMotor[idx]); 
    }
    cout << HIJAU << "\n Sorting selesai! Tampilan diperbarui." << RESET;
}

// menu menu

void menuLihatLaporan(){
    int displayMode = 1; 
    bool stay = true;

    while(stay){
        system("cls");
        headerLogo();

        if(displayMode == 1){
            cout << KUNING << "MODE: TABEL DATA STANDAR (SEMUA)" << RESET << endl;
            tampilkanMotor();
        } else {
            partitionMotor();
        }

        cout << "\n" << BG_BIRU << PUTIH << " OPSI: " << RESET << " ";
        cout << "[1] Sorting Data   ";
        cout << "[2] Laporan Jenis   ";
        cout << "[3] Tabel Standar   ";
        cout << "[4] Kembali";
        
        cout << "\n\nPilih > ";
        int subPilih;
        
        if(cin >> subPilih){
            switch(subPilih){
                case 1: sortingLogic(); break; 
                case 2: displayMode = 2; break;
                case 3: displayMode = 1; break;
                case 4: stay = false; break;
                default: cout << MERAH << "Pilihan tidak ada." << RESET;
            }
        } else {
            cin.clear(); cin.ignore(1000, '\n');
            stay = false;
        }
    }
}

// operasi utama

void tambahMotor(){
    bool tambahLagi = true; 
    cin.ignore(); 

    while(tambahLagi) {
        system("cls"); 
        headerLogo(); 
        cout << "\n" << BG_HIJAU << HITAM << " --- FORM TAMBAH DATA --- " << RESET << endl;

        do {
            cout << CYAN << "Masukkan Merk (Max 22 char) : " << RESET; 
            getline(cin, dataMotor[jumlahData].merk);
            if(dataMotor[jumlahData].merk.empty()) cout << MERAH << "[ERROR] Wajib diisi!\n" << RESET;
            else if(dataMotor[jumlahData].merk.length() > 22) { cout << MERAH << "[ERROR] Kepanjangan!\n" << RESET; dataMotor[jumlahData].merk = ""; }
        } while (dataMotor[jumlahData].merk.empty());

        while(true){
            string inputPlat; 
            cout << CYAN << "Masukkan Plat (Max 12 char) : " << RESET; 
            getline(cin, inputPlat);
            inputPlat = toUpperCase(inputPlat);
            if(inputPlat.empty()) cout << MERAH << "[ERROR] Wajib diisi!\n" << RESET;
            else if(inputPlat.length() > 12) cout << MERAH << "[ERROR] Kepanjangan!\n" << RESET;
            else if(cekPlatAda(inputPlat)) cout << MERAH << "[ERROR] Plat sudah ada!\n" << RESET;
            else { dataMotor[jumlahData].plat = inputPlat; break; }
        }

        int pil;
        while(true){ 
            cout << CYAN << "Status (" << BG_HIJAU << " 1.Tersedia " << RESET << " / " << BG_MERAH << " 2.Disewa " << RESET << CYAN << ")   : " << RESET; 
            if(cin >> pil && (pil==1||pil==2)){ dataMotor[jumlahData].status = (pil==1)?"Tersedia":"Disewa"; cin.ignore(); break; } 
            cin.clear(); cin.ignore(1000,'\n'); cout << MERAH << "Pilih 1 atau 2!\n" << RESET; 
        }
        
        while(true){ 
            // ganti warna moge jadi kuning background
            cout << CYAN << "Jenis  (" << BG_KUNING << HITAM << " 1.Moge " << RESET << " / " << BG_CYAN << " 2.Biasa " << RESET << CYAN << ")       : " << RESET; 
            if(cin >> pil && (pil==1||pil==2)){ dataMotor[jumlahData].jenis = (pil==1)?"Moge":"Biasa"; cin.ignore(); break; } 
            cin.clear(); cin.ignore(1000,'\n'); cout << MERAH << "Pilih 1 atau 2!\n" << RESET; 
        }

        jumlahData++;
        cout << HIJAU << "\n[SUKSES] Data " << dataMotor[jumlahData-1].merk << " berhasil disimpan!\n" << RESET;

        cout << "\n============================================\n";
        cout << "       Ingin Menambahkan Data Lagi?         \n";
        cout << "============================================\n";
        cout << "  " << BG_HIJAU << HITAM << " [1] TAMBAH LAGI " << RESET << "      " << BG_MERAH << PUTIH << " [2] KEMBALI MENU " << RESET << "\n";
        cout << "\nPilihan > ";
        
        int konfirmasi;
        while(true){
            if(cin >> konfirmasi){
                if(konfirmasi == 1){ tambahLagi = true; cin.ignore(); break; } 
                else if(konfirmasi == 2){ tambahLagi = false; cin.ignore(); break; }
            }
            cout << MERAH << "Pilih 1 atau 2: " << RESET;
            cin.clear(); cin.ignore(1000, '\n');
        }
    }
}

void ubahStatus(){
    bool editLagi = true;
    cin.ignore(); 

    while(editLagi){
        system("cls");
        headerLogo();
        cout << "\n" << BG_KUNING << HITAM << " --- FORM UBAH STATUS --- " << RESET << endl;
        
        tampilkanMotor();
        if (jumlahData == 0) { 
            cout << MERAH << "Data Kosong. Tekan Enter kembali..." << RESET; 
            cin.get(); 
            return; 
        }

        string plat;
        bool found = false;

        while(!found){
            cout << "\n" << CYAN << "Masukkan Plat Motor (Ketik " << MERAH << "0" << CYAN << " untuk batal): " << RESET; 
            getline(cin, plat);
            if(plat == "0") return; 
            plat = toUpperCase(plat);
            
            for(int i = 0; i < jumlahData; i++){
                if(dataMotor[i].plat == plat){
                    found = true;
                    cout << "\n" << BIRU << "--------------------------------------------------" << RESET << endl;
                    cout << " Motor Ditemukan : " << KUNING << dataMotor[i].merk << RESET << endl;
                    cout << " Status Saat Ini : " << (dataMotor[i].status == "Tersedia" ? HIJAU : MERAH) << dataMotor[i].status << RESET << endl;
                    cout << BIRU << "--------------------------------------------------" << RESET << endl;
                    
                    int pil;
                    while(true){ 
                        cout << CYAN << "Ubah Menjadi (" << BG_HIJAU << " 1.Tersedia " << RESET << " / " << BG_MERAH << " 2.Disewa " << RESET << CYAN << ") : " << RESET; 
                        if(cin >> pil && (pil==1||pil==2)){ 
                            dataMotor[i].status = (pil==1)?"Tersedia":"Disewa"; 
                            cin.ignore(); 
                            cout << "\n" << HIJAU << "[SUKSES] Status berhasil diupdate menjadi: " << dataMotor[i].status << RESET << endl;
                            break; 
                        } cin.clear(); cin.ignore(1000,'\n'); cout << MERAH << " [ERROR] Masukkan angka 1 atau 2!" << RESET << endl;
                    }
                }
            }
            if(!found) cout << MERAH << " [ERROR] Plat nomor tidak ditemukan. Cek lagi tabel di atas." << RESET << endl;
        }

        cout << "\n============================================\n";
        cout << "       Ingin Mengubah Status Lain?          \n";
        cout << "============================================\n";
        cout << "  " << BG_HIJAU << HITAM << " [1] UBAH LAGI " << RESET << "      " << BG_MERAH << PUTIH << " [2] KEMBALI MENU " << RESET << "\n";
        cout << "\nPilihan > ";
        
        int konfirmasi;
        while(true){
            if(cin >> konfirmasi){
                if(konfirmasi == 1){ editLagi = true; cin.ignore(); break; } 
                else if(konfirmasi == 2){ editLagi = false; cin.ignore(); break; }
            }
            cout << MERAH << "Pilih 1 atau 2: " << RESET; cin.clear(); cin.ignore(1000, '\n');
        }
    }
}

void hapusMotor(){
    bool hapusLagi = true;
    cin.ignore(); 

    while(hapusLagi){
        system("cls");
        headerLogo();
        cout << "\n" << BG_MERAH << PUTIH << " --- FORM HAPUS DATA MOTOR --- " << RESET << endl;

        tampilkanMotor();
        if (jumlahData == 0) {
            cout << MERAH << "Data Kosong. Tekan Enter kembali..." << RESET;
            cin.get();
            return;
        }

        string plat;
        cout << "\n" << CYAN << "Masukkan Plat yang akan DIHAPUS (Ketik " << MERAH << "0" << CYAN << " untuk batal): " << RESET;
        getline(cin, plat);

        if(plat == "0") return; 

        plat = toUpperCase(plat);
        bool found = false;

        for(int i = 0; i < jumlahData; i++){
            if(dataMotor[i].plat == plat){
                found = true;
                string warnaStatus = (dataMotor[i].status == "Tersedia") ? HIJAU : MERAH;

                cout << "\n" << BIRU << "--------------------------------------------------" << RESET << endl;
                cout << " Motor Ditemukan  : " << KUNING << dataMotor[i].merk << RESET << endl;
                cout << " Plat Nomor       : " << CYAN << dataMotor[i].plat << RESET << endl;
                cout << " Status           : " << warnaStatus << dataMotor[i].status << RESET << endl;
                cout << BIRU << "--------------------------------------------------" << RESET << endl;
                
                char yakin;
                cout << BG_MERAH << PUTIH << " YAKIN INGIN MENGHAPUS PERMANEN? " << RESET << " (" << HIJAU << "y" << RESET << "/" << MERAH << "n" << RESET << ") : ";
                cin >> yakin;
                cin.ignore(); 

                if(yakin == 'y' || yakin == 'Y'){
                    for(int j = i; j < jumlahData - 1; j++){
                        dataMotor[j] = dataMotor[j + 1];
                    }
                    jumlahData--;
                    
                    system("cls");
                    headerLogo();
                    cout << "\n" << BG_MERAH << PUTIH << " --- FORM HAPUS DATA MOTOR --- " << RESET << endl;
                    tampilkanMotor(); 
                    
                    cout << "\n" << HIJAU << "[SUKSES] Data motor berhasil dihapus dari sistem." << RESET << endl;
                } else {
                    cout << "\n" << KUNING << "[INFO] Penghapusan dibatalkan." << RESET << endl;
                }
                break; 
            }
        }

        if(!found){
            cout << "\n" << MERAH << "[ERROR] Plat nomor tidak ditemukan." << RESET << endl;
        }

        cout << "\n" << BIRU << "==========================================================================" << RESET << endl;
        cout << "                        " << KUNING << "INGIN MENGHAPUS LAINNYA?" << RESET << endl;
        cout << "          " << BG_MERAH << PUTIH << " [1] HAPUS LAGI " << RESET << "       " << BG_BIRU << PUTIH << " [2] KEMBALI MENU " << RESET << endl;
        cout << BIRU << "==========================================================================" << RESET << endl;
        
        cout << "\nPilihan > ";
        int konfirmasi;
        while(true){
            if(cin >> konfirmasi){
                if(konfirmasi == 1){ hapusLagi = true; cin.ignore(); break; } 
                else if(konfirmasi == 2){ hapusLagi = false; cin.ignore(); break; }
            }
            cin.clear(); cin.ignore(1000, '\n'); cout << MERAH << "Pilih 1 atau 2: " << RESET;
        }
    }
}

void cariMotor(){
    bool cariLagi = true;
    cin.ignore(); 

    while(cariLagi){
        system("cls");
        headerLogo();
        cout << "\n" << BG_BIRU << PUTIH << " --- PENCARIAN SMART SEARCH --- " << RESET << endl;
        cout << CYAN << "Ketik kata kunci (Merk / Plat / Status / Jenis): " << RESET;
        
        string keyword;
        getline(cin, keyword);
        keyword = toUpperCase(keyword);

        int countFound = 0;
        
        cout << "\n" << BIRU << "==========================================================================" << RESET << endl;
        cout << left << setw(4) << "No" << setw(25) << "Merk" << setw(15) << "Plat" << setw(15) << "Status" << setw(10) << "Jenis" << endl;
        cout << BIRU << "==========================================================================" << RESET << endl;

        for(int i = 0; i < jumlahData; i++){
            string m = toUpperCase(dataMotor[i].merk);
            string p = toUpperCase(dataMotor[i].plat);
            string s = toUpperCase(dataMotor[i].status);
            string j = toUpperCase(dataMotor[i].jenis);

            if(m.find(keyword) != string::npos || p.find(keyword) != string::npos || s.find(keyword) != string::npos || j.find(keyword) != string::npos) {
                string warnaStatus = (dataMotor[i].status == "Tersedia") ? HIJAU : MERAH;
                // mosenya juga kuning
                string warnaJenis = (dataMotor[i].jenis == "Moge") ? KUNING : CYAN;
                cout << left << setw(4) << i + 1 << setw(25) << dataMotor[i].merk << setw(15) << dataMotor[i].plat << warnaStatus << setw(15) << dataMotor[i].status << RESET << warnaJenis << setw(10) << dataMotor[i].jenis << RESET << endl;
                countFound++;
            }
        }
        cout << BIRU << "--------------------------------------------------------------------------" << RESET << endl;

        if(countFound > 0) cout << HIJAU << "Ditemukan " << countFound << " data yang cocok." << RESET << endl;
        else cout << MERAH << "Tidak ada data yang cocok dengan kata kunci: " << keyword << RESET << endl;

        cout << "\n" << BIRU << "==========================================================================" << RESET << endl;
        cout << "                        " << KUNING << "INGIN MENCARI DATA LAIN?" << RESET << endl;
        cout << "          " << BG_HIJAU << HITAM << " [1] CARI LAGI " << RESET << "       " << BG_MERAH << PUTIH << " [2] KEMBALI MENU " << RESET << endl;
        cout << BIRU << "==========================================================================" << RESET << endl;
        
        cout << "\nPilihan > ";
        int konfirmasi;
        while(true){
            if(cin >> konfirmasi){
                if(konfirmasi == 1){ cariLagi = true; cin.ignore(); break; } 
                else if(konfirmasi == 2){ cariLagi = false; cin.ignore(); break; }
            }
            cout << MERAH << "Pilih 1 atau 2: " << RESET; cin.clear(); cin.ignore(1000, '\n');
        }
    }
}

// dashboard utama

int main(){
    system("color 07"); 
    bacaFile();

    int pilih;
    do{
        system("cls"); 
        headerLogo(); 

        cout << "  " << BG_BIRU << PUTIH << " [1] TAMBAH DATA BARU " << RESET << "\t\t" << BG_BIRU << PUTIH << " [4] CARI MOTOR       " << RESET << endl;
        cout << "\n";
        cout << "  " << BG_BIRU << PUTIH << " [2] LIHAT & LAPORAN  " << RESET << "\t\t" << BG_BIRU << PUTIH << " [5] HAPUS MOTOR      " << RESET << endl;
        cout << "\n";
        cout << "  " << BG_BIRU << PUTIH << " [3] UBAH STATUS      " << RESET << "\t\t" << BG_BIRU << PUTIH << " [6] SIMPAN & KELUAR  " << RESET << endl;
        
        cout << BIRU << "\n==========================================================================\n" << RESET;
        cout << "Pilih Menu " << KUNING << "[1-6]" << RESET << ": ";

        if (!(cin >> pilih)) { cout << MERAH << "Input Error!\n" << RESET; cin.clear(); cin.ignore(1000, '\n'); continue; }

        switch (pilih){
            case 1: tambahMotor(); break;
            case 2: menuLihatLaporan(); break; 
            case 3: ubahStatus(); break;
            case 4: cariMotor(); break;
            case 5: hapusMotor(); break;
            case 6: simpanDanKeluar(); return 0; 
            default: cout << MERAH << "Pilihan salah.\n" << RESET; pauseScreen();
        }
    } while(pilih != 6);

    return 0;
}