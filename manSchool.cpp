#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int jumlahSiswa = 0; 
int jumlahGuru = 0;

struct Datasiswa {
    string nama;
    int noAbsen;
    int nis;
    int nisn;
    string kelas;
    string alamat;
};

struct Dataguru {
    string nama;
    string npdn;
    string alamat;
    int lamaMengajar;
    string mapel[5];
};

struct Kelas {
    string namaKelas;
    int jumlahSiswa;
    Dataguru waliKelas;
    Datasiswa siswa[50];
};

struct Sekolah {
    Dataguru guru[10];
    Datasiswa siswa[100];
    Kelas kelas[5];
};

Sekolah sekolah;

void inputSiswa() {
    cout << "Masukkan jumlah siswa: ";
    cin >> jumlahSiswa;
    cin.ignore();
    for (int i = 0; i < jumlahSiswa; i++) {
        cout << "\nData Siswa ke-" << i + 1 << ":\n";
        cout << "Nama: ";
        getline(cin, sekolah.siswa[i].nama);
        cout << "No Absen: ";
        cin >> sekolah.siswa[i].noAbsen;
        cout << "NIS: ";
        cin >> sekolah.siswa[i].nis;
        cout << "NISN: ";
        cin >> sekolah.siswa[i].nisn;
        cin.ignore();
        cout << "Kelas: ";
        getline(cin, sekolah.siswa[i].kelas);
        cout << "Alamat: ";
        getline(cin, sekolah.siswa[i].alamat);
    }
}

void tampilSiswa() {
    cout << "\nData Siswa:\n";
    for (int i = 0; i < jumlahSiswa; i++) {
        cout << "Nama: " << sekolah.siswa[i].nama << " | No Absen: " << sekolah.siswa[i].noAbsen
             << " | NIS: " << sekolah.siswa[i].nis << " | NISN: " << sekolah.siswa[i].nisn
             << " | Kelas: " << sekolah.siswa[i].kelas << " | Alamat: " << sekolah.siswa[i].alamat << endl;
    }
    system("pause");
}

void inputGuru() {
    cout << "Masukkan jumlah guru: ";
    cin >> jumlahGuru;
    cin.ignore();
    for (int i = 0; i < jumlahGuru; i++) {
        cout << "\nData Guru ke-" << i + 1 << ":\n";
        cout << "Nama: ";
        getline(cin, sekolah.guru[i].nama);
        cout << "NPDN: ";
        getline(cin, sekolah.guru[i].npdn);
        cout << "Alamat: ";
        getline(cin, sekolah.guru[i].alamat);
        cout << "Lama Mengajar (tahun): ";
        cin >> sekolah.guru[i].lamaMengajar;
        cin.ignore();
        for (int j = 0; j < 3; j++) {
            cout << "Mata Pelajaran " << j + 1 << ": ";
            getline(cin, sekolah.guru[i].mapel[j]);
        }
    }
}

void tampilGuru() {
    cout << "\nData Guru:\n";
    for (int i = 0; i < jumlahGuru; i++) {
        cout << "Nama: " << sekolah.guru[i].nama << " | NPDN: " << sekolah.guru[i].npdn
             << " | Alamat: " << sekolah.guru[i].alamat << " | Lama Mengajar: " << sekolah.guru[i].lamaMengajar << " tahun" << endl;
        cout << "Mata Pelajaran: ";
        for (int j = 0; j < 3; j++) {
            cout << sekolah.guru[i].mapel[j] << (j < 2 ? ", " : "");
        }
        cout << endl;
    }
    system("pause");
}

void cariSiswaSentinel(int jumlahSiswa, int nis) {
    sekolah.siswa[jumlahSiswa].nis = nis; 
    int i = 0;
    while (sekolah.siswa[i].nis != nis) {
        i++;
    }
    if (i < jumlahSiswa)
        cout << "\nData Siswa ditemukan: " << sekolah.siswa[i].nama << " dari kelas " << sekolah.siswa[i].kelas << endl;
    else
        cout << "\nData Siswa tidak ditemukan!" << endl;
}

void cariSiswaLinear(int jumlahSiswa, int nis) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahSiswa; i++) {
        if (sekolah.siswa[i].nis == nis) {
            cout << "\nData Siswa ditemukan: " << sekolah.siswa[i].nama << " dari kelas " << sekolah.siswa[i].kelas << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
        cout << "\nData Siswa tidak ditemukan!" << endl;
}
void menuInput(){
    int menuInput;
    do{
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(32) << setfill(' ') << "MENU INPUT DATA" << setw(18) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|Pilihan Menu : " << setw(35) << setfill(' ') << "|" << endl;
    cout << "|1. Data Siswa  " << setw(35) << setfill(' ') << "|" << endl;
    cout << "|2. Data Guru   " << setw(35) << setfill(' ') << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan Pilihan Menu : ";cin>>menuInput;
    if (menuInput==1)
    {
    inputSiswa();
    } else if (menuInput==2)
    {
    inputGuru();
    }
    if (menuInput!=1&&menuInput!=2)
    {
    cout<<"Input yang anda masukkan salah"<<endl;
    system("pause");
    }
    
    } while (menuInput!=1&&menuInput!=2);
}
void menuOutput(){
    int menuOutput;
    do{
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU OUTPUT DATA" << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|Pilihan Menu : " << setw(35) << setfill(' ') << "|" << endl;
    cout << "|1. Data Siswa  " << setw(35) << setfill(' ') << "|" << endl;
    cout << "|2. Data Guru   " << setw(35) << setfill(' ') << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan Pilihan Menu : ";cin>>menuOutput;
    if (menuOutput==1){
        tampilSiswa();
    }else if (menuOutput==2)
    {
        tampilGuru();
    }else if (menuOutput!=1&&menuOutput!=2)
    {
    cout<<"Input yang anda masukkan salah"<<endl;
    system("pause");
    }
    }while (menuOutput!=1&&menuOutput!=2);
}

void mainMenu(){
    int menu;
    do{
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(32) << setfill(' ') << "MANAJEMEN SEKOLAH" << setw(18) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|Pilihan Menu : " << setw(35) << setfill(' ') << "|" << endl;
    cout << "|1. Input Data  " << setw(35) << setfill(' ') << "|" << endl;
    cout << "|2. Output Data " << setw(35) << setfill(' ') << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan Pilihan Menu : ";
    cin >> menu;
    if (menu == 1)
    {
    menuInput();
    }else if (menu == 2){
    menuOutput();
    } else if (menu !=1 && menu !=2)
    {
    cout<<"Input yang anda masukkan salah"<<endl;
    system("pause");
    }
    
    } while (menu !=1 && menu !=2);
}

int main() {
    string kembali;
    do{
        mainMenu();
    do{
        cout<<"Kembali Ke Menu?(y/n) : ";getline(cin>>ws,kembali);
        if (kembali != "n" && kembali != "N" && kembali != "y" && kembali !="Y")
        {
            cout<<"Input yang anda masukkan salah"<<endl;
            system("pause");
        } 
    } while (kembali != "n" && kembali != "N" && kembali != "y" && kembali !="Y");
    }while (kembali == "y"||kembali=="Y");
  
    int nis;
    cout << "\nMasukkan NIS untuk pencarian (Sentinel): ";
    cin >> nis;
    cariSiswaSentinel(jumlahSiswa, nis);
    
    cout << "\nMasukkan NIS untuk pencarian (Linear): ";
    cin >> nis;
    cariSiswaLinear(jumlahSiswa, nis);
    return 0;
}
