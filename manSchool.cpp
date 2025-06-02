#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
// Struct
struct Datasiswa {
    string nama;
    string noAbsen;
    string nis;
    string nisn;
    string kelas;
    string alamat;
};

struct Dataguru {
    string nama;
    string npdn;
    string alamat;
    string lamaMengajar;
    string mapel;
};

void tambahDataSiswaKeFile(Datasiswa* &arraySiswa, int &jumlah_siswa, string &namaFileSiswa);
void inputFileGuru(Dataguru* &arrayGuru, int &jumlah_guru, string &namaFileGuru);
//fungsi tambah panjang array siswa
void addStudentLength(Datasiswa* &arr, int &kapasitas, int tambahan) {
    Datasiswa* temp = new Datasiswa[kapasitas + tambahan];
    for (int i = 0; i < kapasitas; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    kapasitas += tambahan;
}
// fungsi input data siswa
void inputDataSiswa(Datasiswa* &arraySiswa, int &kapasitas, int &jumlah_siswa, string &namaFileSiswa){
    int n;
    string temp;
    cout << "Masukkan jumlah siswa: ";
    getline(cin >> ws, temp);
    stringstream(temp) >> n;
    if(jumlah_siswa + n > kapasitas){
        addStudentLength(arraySiswa, kapasitas, n);
    }
    for(int i = 0; i < n; i++){
        cout << "Masukkan nama: "; getline(cin >> ws, arraySiswa[jumlah_siswa].nama);
        cout << "Masukkan no absen: "; getline(cin >> ws, arraySiswa[jumlah_siswa].noAbsen);
        cout << "Masukkan nis: "; getline(cin >> ws, arraySiswa[jumlah_siswa].nis);
        cout << "Masukkan nisn: "; getline(cin >> ws, arraySiswa[jumlah_siswa].nisn);
        cout << "Masukkan kelas: "; getline(cin >> ws, arraySiswa[jumlah_siswa].kelas);
        cout << "Masukkan alamat: "; getline(cin >> ws, arraySiswa[jumlah_siswa].alamat);
        jumlah_siswa++;
    }
    tambahDataSiswaKeFile(arraySiswa, jumlah_siswa, namaFileSiswa);
}
//fungsi sorting siswa dgn bubblesort
void sortingSiswa(Datasiswa* arraySiswa, int &jumlah_siswa){
    for(int i = 0; i < jumlah_siswa - 1; i++){
        for(int j = 0; j < jumlah_siswa - i - 1; j++){
            int nis_j = stoi(arraySiswa[j].nis);
            int nis_j1 = stoi(arraySiswa[j + 1].nis);
            if(nis_j > nis_j1){
                swap(arraySiswa[j], arraySiswa[j+1]);
            }
        }
    }
}
//output data siswa rekursif
void tampilSiswaRekursif(Datasiswa* siswa, int index, int &jumlah_siswa) {
    if (index >= jumlah_siswa) return;
    cout << "Nama: " << siswa[index].nama
         << " | No Absen: " << siswa[index].noAbsen
         << " | NIS: " << siswa[index].nis
         << " | NISN: " << siswa[index].nisn
         << " | Kelas: " << siswa[index].kelas
         << " | Alamat: " << siswa[index].alamat << endl;
    tampilSiswaRekursif(siswa, index + 1, jumlah_siswa);
}

void tampilSiswa(Datasiswa* siswa, int &jumlah_siswa) {
    if (jumlah_siswa == 0) {
        cout << "Data Siswa Belum Diinput\nSilahkan Input Data Terlebih Dahulu\n";
    } else {
        cout << "\nData Siswa:\n";
        sortingSiswa(siswa, jumlah_siswa);
        tampilSiswaRekursif(siswa, 0, jumlah_siswa);
    }
}
//tambah data siswa ke file
void tambahDataSiswaKeFile(Datasiswa* &arraySiswa, int &jumlah_siswa, string &namaFileSiswa){
    ofstream file(namaFileSiswa);
    sortingSiswa(arraySiswa, jumlah_siswa);
    for(int i = 0; i < jumlah_siswa; i++){
        file << arraySiswa[i].nama << "," 
             << arraySiswa[i].noAbsen << "," 
             << arraySiswa[i].nis << "," 
             << arraySiswa[i].nisn << ","
             << arraySiswa[i].kelas << ","
             << arraySiswa[i].alamat << "\n";
    }
    file.close();
}
//hapus data siswa cari dari nis
void deleteSiswa(Datasiswa* &arraySiswa, int &jumlah_siswa, string &nis, string &namaFileSiswa) {
    bool found = false;
    for (int i = 0; i < jumlah_siswa; i++) {
        if (arraySiswa[i].nis == nis) {
            found = true;
            for (int j = i; j < jumlah_siswa - 1; j++) {
                arraySiswa[j] = arraySiswa[j + 1];
            }
            jumlah_siswa--;
            tambahDataSiswaKeFile(arraySiswa, jumlah_siswa, namaFileSiswa);
            cout << "Data siswa dengan NIS " << nis << " berhasil dihapus." << endl;
            return;
        }
    }
    if (!found) {
        cout << "Data tidak ditemukan." << endl;
    }
}
// baca file data siswa
void bacaFileSiswa(Datasiswa* &arraySiswa, int &jumlah_siswa, int &kapasitas, string &namaFileSiswa){
    ifstream file(namaFileSiswa);
    string line;
    jumlah_siswa = 0;

    while (getline(file, line)) {
        if (jumlah_siswa >= kapasitas) {
            addStudentLength(arraySiswa, kapasitas, 2);
        }
        stringstream ss(line);
        string item;
        getline(ss, arraySiswa[jumlah_siswa].nama, ',');
        getline(ss, arraySiswa[jumlah_siswa].noAbsen, ',');
        getline(ss, arraySiswa[jumlah_siswa].nis, ',');
        getline(ss, arraySiswa[jumlah_siswa].nisn, ',');
        getline(ss, arraySiswa[jumlah_siswa].kelas, ',');
        getline(ss, arraySiswa[jumlah_siswa].alamat, '\n');
        jumlah_siswa++;
    }

    file.close();
    cout << "Data berhasil dibaca dari file." << endl;
}
// cari siswa sentinel search
void cariSiswaSentinel(Datasiswa* &arraySiswa, int &jumlahSiswa, string nis) {
    for (int i = 0; i < jumlahSiswa; i++) {
    if (arraySiswa[i].nis == nis) {
        cout << "\nData Siswa ditemukan: " << arraySiswa[i].nama << " dari kelas " << arraySiswa[i].kelas << endl;
        return;
    }
    }
    cout << "\nData Siswa tidak ditemukan!" << endl;

}
// update data siswa 
void updateDataSiswa(Datasiswa* &arraySiswa, int &jumlah_siswa, string &namaFileSiswa) {
    string cariNis;
    cout << "Masukkan NIS siswa yang ingin diupdate: ";
    getline(cin >> ws, cariNis);
    bool ditemukan = false;
    for (int i = 0; i < jumlah_siswa; i++) {
        if (arraySiswa[i].nis == cariNis) {
            ditemukan = true;
            cout << "Data lama:\n";
            cout << "Nama   : " << arraySiswa[i].nama << endl;
            cout << "No Absen: " << arraySiswa[i].noAbsen << endl;
            cout << "NISN   : " << arraySiswa[i].nisn << endl;
            cout << "Kelas  : " << arraySiswa[i].kelas << endl;
            cout << "Alamat : " << arraySiswa[i].alamat << endl;

            cout << "\nMasukkan data baru:\n";
            cout << "Nama: "; getline(cin >> ws, arraySiswa[i].nama);
            cout << "No Absen: "; getline(cin >> ws, arraySiswa[i].noAbsen);
            cout << "NISN: "; getline(cin >> ws, arraySiswa[i].nisn);
            cout << "Kelas: "; getline(cin >> ws, arraySiswa[i].kelas);
            cout << "Alamat: "; getline(cin >> ws, arraySiswa[i].alamat);
            tambahDataSiswaKeFile(arraySiswa, jumlah_siswa, namaFileSiswa);
            cout << "\nData berhasil diperbarui.\n";
            break;
        }
    }
    if (!ditemukan) {
        cout << "Siswa dengan NIS tersebut tidak ditemukan." << endl;;
    }
}
//----------------------------------------------------------------------------------------------------------------//
//fungsi tambah panjang array guru
void addTeacherLength(Dataguru* &arr, int &kapasitas_guru, int tambahan) {
    Dataguru* temp = new Dataguru[kapasitas_guru + tambahan];
    for (int i = 0; i < kapasitas_guru; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    kapasitas_guru += tambahan;
}
// fungsi input data guru
void inputDataGuru(Dataguru* &arrayGuru, int &kapasitas_guru, int &jumlah_guru, string &namaFileGuru){
    int n;
    string temp;
    cout << "Masukkan jumlah guru: ";
    getline(cin >> ws, temp);
    stringstream(temp) >> n;
    if(jumlah_guru + n > kapasitas_guru){
        addTeacherLength(arrayGuru, kapasitas_guru, n);
    }
    for(int i = 0; i < n; i++){
        cout << "Masukkan nama: "; getline(cin >> ws, arrayGuru[jumlah_guru].nama);
        cout << "Masukkan NPDN: "; getline(cin >> ws, arrayGuru[jumlah_guru].npdn);
        cout << "Masukkan alamat: "; getline(cin >> ws, arrayGuru[jumlah_guru].alamat);
        cout << "Masukkan lama mengajar: "; getline(cin >> ws, arrayGuru[jumlah_guru].lamaMengajar);
        cout << "Masukkan mapel yang diampu: "; getline(cin >> ws, arrayGuru[jumlah_guru].mapel);
        jumlah_guru++;
    }
    inputFileGuru(arrayGuru, jumlah_guru, namaFileGuru);
}
// menu cari guru
void cariGuruLinear(Dataguru* &arrayGuru, int jumlahGuru, string npdn) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahGuru; i++) {
        if (arrayGuru[i].npdn == npdn) {
            cout << "\nData Guru ditemukan: " << arrayGuru[i].npdn << " dengan nama " << arrayGuru[i].nama << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
        cout << "\nData Guru tidak ditemukan!" << endl;
}
// menu sorting guru
void sortingGuru(Dataguru* &arrayGuru, int &jumlah_guru){
    for(int i = 0; i < jumlah_guru - 1; i++){
        for(int j = 0; j < jumlah_guru - i - 1; j++){
            if(arrayGuru[j].npdn > arrayGuru[j + 1].npdn){
                swap(arrayGuru[j], arrayGuru[j+1]);
            }
        }
    }
}
// output data guru
void outputDataGuru(Dataguru* &arrayGuru, int &jumlah_guru){
    sortingGuru(arrayGuru, jumlah_guru);
    for(int i = 0; i < jumlah_guru; i++){
        cout << "Nama guru: " << arrayGuru[i].nama << endl;
        cout << "NPDN guru: " << arrayGuru[i].npdn << endl;
        cout << "Alamat: " << arrayGuru[i].alamat << endl;
        cout << "Lama mengajar: " << arrayGuru[i].lamaMengajar << endl;
        cout << "Mapel: " << arrayGuru[i].mapel << endl;
        cout << endl;
    }
}
// input data file guru
void inputFileGuru(Dataguru* &arrayGuru, int &jumlah_guru, string &namaFileGuru){
    sortingGuru(arrayGuru, jumlah_guru);
    ofstream file(namaFileGuru);
    if(!file.is_open()){
        cout << "File tidak ada" << endl;
        return;
    }
    for(int i = 0; i < jumlah_guru; i++){
        file << arrayGuru[i].nama << "," 
             << arrayGuru[i].npdn << "," 
             << arrayGuru[i].alamat << "," 
             << arrayGuru[i].lamaMengajar << ","
             << arrayGuru[i].mapel << "\n";
    }
    file.close();
}
// baca file guru
void bacaFileGuru(Dataguru* &arrayGuru, int &jumlah_guru, int &kapasitas_guru, string &namaFileGuru){
    ifstream file(namaFileGuru);
    if(!file.is_open()){
        cout << "Tidak ada file yang terbuka" << endl;
        return;
    }
    string line;
    jumlah_guru = 0;

    while (getline(file, line)) {
        if (jumlah_guru >= kapasitas_guru) {
            addTeacherLength(arrayGuru, kapasitas_guru, 2);
        }
        stringstream ss(line);
        string item;
        getline(ss, arrayGuru[jumlah_guru].nama, ',');
        getline(ss, arrayGuru[jumlah_guru].npdn, ',');
        getline(ss, arrayGuru[jumlah_guru].alamat, ',');
        getline(ss, arrayGuru[jumlah_guru].lamaMengajar, ',');
        getline(ss, arrayGuru[jumlah_guru].mapel, '\n');
        jumlah_guru++;
    }
    file.close();
    cout << "Data berhasil dibaca dari file." << endl;
}
// hapus data file guru 
void deleteGuru(Dataguru* &arrayGuru, int &jumlah_guru, string &npdn, string &namaFileGuru){
    bool found = false;
    for (int i = 0; i < jumlah_guru; i++) {
        if (arrayGuru[i].npdn == npdn) {
            found = true;
            for (int j = i; j < jumlah_guru - 1; j++) {
                arrayGuru[j] = arrayGuru[j + 1];
            }
            jumlah_guru--;
            inputFileGuru(arrayGuru, jumlah_guru, namaFileGuru);
            cout << "Data guru dengan NPDN " << npdn << " berhasil dihapus." << endl;
            return;
        }
    }
    if (!found) {
        cout << "Data tidak ditemukan." << endl;
    }
}
// update data file guru 
void updateDataGuru(Dataguru* &arrayGuru, int &jumlah_guru, string &namaFileGuru){
    string cariNpdn;
    cout << "Masukkan NPDN guru yang ingin diupdate: ";
    getline(cin >> ws, cariNpdn);
    bool ditemukan = false;
    for (int i = 0; i < jumlah_guru; i++) {
        if (arrayGuru[i].npdn == cariNpdn) {
            ditemukan = true;
            cout << "Data lama:\n";
            cout << "Nama   : " << arrayGuru[i].nama << endl;
            cout << "NPDN: " << arrayGuru[i].npdn << endl;
            cout << "Alamat   : " << arrayGuru[i].alamat << endl;
            cout << "Lama mengajar  : " << arrayGuru[i].lamaMengajar << endl;
            cout << "Mapel : " << arrayGuru[i].mapel << endl;
            cout << endl;
            cout << "\nMasukkan data baru:\n";
            cout << "Nama: "; getline(cin >> ws, arrayGuru[i].nama);
            cout << "NPDN: "; getline(cin >> ws, arrayGuru[i].npdn);
            cout << "Alamat: "; getline(cin >> ws, arrayGuru[i].alamat);
            cout << "Lama mengajar: "; getline(cin >> ws, arrayGuru[i].lamaMengajar);
            cout << "Mapel: "; getline(cin >> ws, arrayGuru[i].mapel);
            inputFileGuru(arrayGuru, jumlah_guru, namaFileGuru);
            cout << "\nData berhasil diperbarui.\n";
            break;
        }
    }
    if (!ditemukan) {
        cout << "Guru dengan NPDN tersebut tidak ditemukan." << endl;
    }
}

// menu input
void menuInput(Datasiswa* &arraySiswa, int &kapasitas, int &jumlah_siswa, string &namaFileSiswa, Dataguru* &arrayGuru, int &kapasitas_guru, int &jumlah_guru, string &namaFileGuru) {
    int menuInput;
    do {
        system("cls");
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|" << setw(32) << setfill(' ') << "MENU INPUT DATA" << setw(18) << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|Pilihan Menu : " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|1. Data Siswa  " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|2. Data Guru   " << setw(35) << setfill(' ') << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "Masukkan Pilihan Menu : ";cin>>menuInput;
        if (menuInput != 1 && menuInput != 2)
        {
          cout<<"Invalid Input"<<endl;
          system("pause");
        }
        switch (menuInput) {
            case 1: inputDataSiswa(arraySiswa, kapasitas, jumlah_siswa, namaFileSiswa); break;
            case 2: inputDataGuru(arrayGuru, kapasitas_guru, jumlah_guru, namaFileGuru); break;
        }
    } while (menuInput != 1 && menuInput != 2);
}
//menu output
void menuOutput(Datasiswa* &arraySiswa, int &kapasitas, int &jumlah_siswa, Dataguru* &arrayGuru, int &kapasitas_guru, int &jumlah_guru){
    int menuoutput;
    do{
        system("cls");
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|" << setw(33) << setfill(' ') << "MENU OUTPUT DATA" << setw(17) << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|1. Data Siswa  |\n|2. Data Guru   |\n";
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "Masukkan Pilihan Menu : ";
        cin >> menuoutput;
        if(menuoutput != 1 && menuoutput != 2){
            cout<<"Invalid Input"<<endl;
            system("pause");
        }
        switch(menuoutput){
            case 1: tampilSiswa(arraySiswa, jumlah_siswa); break;
            case 2: outputDataGuru(arrayGuru, jumlah_guru); break;
        }
    }while(menuoutput != 1 && menuoutput != 2);
}
// menu cari siswa
void menuCariSiswa(Datasiswa* &arraySiswa, int &jumlah_siswa) {
    string inputnis;
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU PENCARIAN DATA SISWA" << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan NIS Siswa : ";
    cin >> inputnis;
    cariSiswaSentinel(arraySiswa, jumlah_siswa, inputnis);
}

// Menu cari guru
void menuCariGuru(Dataguru* &arrayGuru, int &jumlah_guru) {
    string inputnpdn;
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU PENCARIAN DATA GURU " << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan NPDN Guru : ";
    cin >> inputnpdn;
    cariGuruLinear(arrayGuru, jumlah_guru, inputnpdn);
}

// Menu cari data
void menuCari(Datasiswa* &arraySiswa, int &jumlah_siswa, Dataguru* &arrayGuru, int &jumlah_guru) {
    int menuCari;
    do {
        system("cls");
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|" << setw(33) << setfill(' ') << "MENU PENCARIAN DATA" << setw(17) << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|1. Data Siswa  |\n|2. Data Guru   |\n";
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "Masukkan Pilihan Menu : ";
        cin >> menuCari;

        switch (menuCari) {
            case 1: menuCariSiswa(arraySiswa, jumlah_siswa); break;
            case 2: menuCariGuru(arrayGuru, jumlah_guru); break;
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    } while (menuCari != 1 && menuCari != 2);
}
// menu update siswa
void menuUpdateSiswa(Datasiswa* &arraySiswa, int &jumlah_siswa, string &namaFileSiswa) {
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU UPDATE DATA SISWA" << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    updateDataSiswa(arraySiswa, jumlah_siswa, namaFileSiswa);
    system("pause");
}
// menu update guru 
void menuUpdateGuru(Dataguru* &arrayGuru, int &jumlah_guru, string &namaFileGuru) {
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU UPDATE DATA GURU" << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    updateDataGuru(arrayGuru, jumlah_guru, namaFileGuru);
    system("pause");
}
//menu update
void menuUpdate(Datasiswa* &arraySiswa, int &jumlah_siswa, string &namaFileSiswa, Dataguru* &arrayGuru, int &jumlah_guru, string &namaFileGuru){
    int menuupdate;
    do{
        system("cls");
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|" << setw(33) << setfill(' ') << "MENU UPDATE DATA" << setw(17) << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|1. Data Siswa  |\n|2. Data Guru   |\n";
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "Masukkan Pilihan Menu : ";
        cin >> menuupdate;
        switch (menuupdate) {
            case 1: menuUpdateSiswa(arraySiswa, jumlah_siswa, namaFileSiswa); break;
            case 2: menuUpdateGuru(arrayGuru, jumlah_guru, namaFileGuru); break;
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    }while(menuupdate != 1 && menuupdate != 2);
}
// menu delete siswa
void menuDeleteSiswa(Datasiswa* &arraySiswa, int &jumlah_siswa, string &namaFileSiswa) {
    string nis;
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU HAPUS DATA SISWA" << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan NIS siswa yang ingin dihapus: ";
    getline(cin >> ws, nis);
    deleteSiswa(arraySiswa, jumlah_siswa, nis, namaFileSiswa);
    system("pause");
}
// menu delete guru
void menuDeleteGuru(Dataguru* &arrayGuru, int &jumlah_guru, string &namaFileGuru) {
    string npdn;
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU HAPUS DATA GURU" << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan NPDN guru yang ingin dihapus: ";
    getline(cin >> ws, npdn);
    deleteGuru(arrayGuru, jumlah_guru, npdn, namaFileGuru);
    system("pause");
}
// menu delete
void menuDelete(Datasiswa* &arraySiswa, int &jumlah_siswa, string &namaFileSiswa, Dataguru* &arrayGuru, int &jumlah_guru, string &namaFileGuru){
    int menudelete;
    do{
        system("cls");
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|" << setw(33) << setfill(' ') << "MENU DELETE DATA" << setw(17) << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|1. Data Siswa  |\n|2. Data Guru   |\n";
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "Masukkan Pilihan Menu : ";
        cin >> menudelete;
        switch (menudelete) {
            case 1: menuDeleteSiswa(arraySiswa, jumlah_siswa, namaFileSiswa); break;
            case 2: menuDeleteGuru(arrayGuru, jumlah_guru, namaFileGuru); break;
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    }while(menudelete != 1 && menudelete != 2);
}
// main menu
void mainMenu(Datasiswa* &arraySiswa, int &jumlah_siswa, int &kapasitas, string &namaFileSiswa, Dataguru* &arrayGuru, int &jumlah_guru, int &kapasitas_guru, string &namaFileGuru){
    int menu;
    do {
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|" << setw(32) << setfill(' ') << "MANAJEMEN SEKOLAH" << setw(18) << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|Pilihan Menu : " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|1. Input Data  " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|2. Output Data " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|3. Cari Data   " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|4. Update Data   " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|5. Delete Data   " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|6. Keluar   " << setw(35) << setfill(' ') << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "Masukkan Pilihan Menu : ";
        cin >> menu;
        switch (menu) {
            case 1: menuInput(arraySiswa, kapasitas, jumlah_siswa, namaFileSiswa, arrayGuru, kapasitas_guru, jumlah_guru, namaFileGuru); break;
            case 2: menuOutput(arraySiswa, kapasitas, jumlah_siswa, arrayGuru, kapasitas_guru, jumlah_guru); break;
            case 3: menuCari(arraySiswa, jumlah_siswa, arrayGuru, jumlah_guru); break;
            case 4: menuUpdate(arraySiswa, jumlah_siswa, namaFileSiswa, arrayGuru, jumlah_guru, namaFileGuru); break;
            case 5: menuDelete(arraySiswa, jumlah_siswa, namaFileSiswa, arrayGuru, jumlah_guru, namaFileGuru); break;
            case 6: cout << "Keluar dari program" << endl; exit(0);
            default: cout << "Input yang anda masukkan salah\n"; system("pause"); break;
        }
    } while (menu != 6);
}

// Fungsi main
int main() {
    string namaFileSiswa = "datasiswa.txt";
    string namaFileGuru = "dataguru.txt";
    int kapasitas_guru = 2;
    int jumlah_siswa = 0;
    int kapasitas_siswa = 2;
    int jumlah_guru = 0;
    string kembali;
    Datasiswa* arraySiswa = new Datasiswa[kapasitas_siswa];
    Dataguru* arrayGuru = new Dataguru[kapasitas_guru];
    bacaFileSiswa(arraySiswa, jumlah_siswa, kapasitas_siswa, namaFileSiswa);
    bacaFileGuru(arrayGuru, jumlah_guru, kapasitas_guru, namaFileGuru);
    do {
        mainMenu(arraySiswa, jumlah_siswa, kapasitas_siswa, namaFileSiswa, arrayGuru, jumlah_guru, kapasitas_guru, namaFileGuru);
        do {
            cout << "Kembali Ke Menu?(y/n) : ";
            getline(cin >> ws, kembali);
            if (kembali != "n" && kembali != "N" && kembali != "y" && kembali != "Y") {
                cout << "Input yang anda masukkan salah\n";
                system("pause");
            }
        } while (kembali != "n" && kembali != "N" && kembali != "y" && kembali != "Y");
    } while (kembali == "y" || kembali == "Y");
    delete[] arraySiswa;
    delete[] arrayGuru;
    return 0;
}
