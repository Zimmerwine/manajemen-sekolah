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
    int npdn;
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
    if (jumlahSiswa == 0)
    {
    cout<<"Data Siswa Belum Diinput\n";
    cout<<"Silahkan Input Data Terlebih Dahulu\n";
    } else {
        cout << "\nData Siswa:\n";
        for (int i = 0; i < jumlahSiswa; i++) {
            cout << "Nama: " << sekolah.siswa[i].nama << " | No Absen: " << sekolah.siswa[i].noAbsen
                 << " | NIS: " << sekolah.siswa[i].nis << " | NISN: " << sekolah.siswa[i].nisn
                 << " | Kelas: " << sekolah.siswa[i].kelas << " | Alamat: " << sekolah.siswa[i].alamat << endl;
        }
    }
    
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
        cin>>sekolah.guru[i].npdn;
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
    if (jumlahGuru == 0)
    {
    cout<<"Data Guru Belum Diinput\n";
    cout<<"Silahkan Input Data Terlebih Dahulu\n";
    } else {
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
    }
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

void cariGuruLinear(int jumlahGuru, int npdn) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahGuru; i++) {
        if (sekolah.guru[i].npdn == npdn) {
            cout << "\nData Guru ditemukan: " << sekolah.guru[i].npdn << " dengan nama " << sekolah.guru[i].nama << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
        cout << "\nData Guru tidak ditemukan!" << endl;
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

void bubbleSortSiswa() {
    for (int i = 0; i < jumlahSiswa - 1; i++) {
        for (int j = 0; j < jumlahSiswa - i - 1; j++) {
            if (sekolah.siswa[j].nis > sekolah.siswa[j + 1].nis) {
                swap(sekolah.siswa[j], sekolah.siswa[j + 1]);
            }
        }
    }
    cout << "\nData siswa telah diurutkan berdasarkan NIS (ascending).\n";
    system("pause");
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
        bubbleSortSiswa();
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

void menuCariSiswa(){
    int inputnis;
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU PENCARIAN DATA SISWA" << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan NIS Siswa : ";cin>>inputnis;
    cariSiswaSentinel(jumlahSiswa,inputnis);
}

void menuCariGuru(){
    int inputnpdn;
    system("cls");
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "|" << setw(33) << setfill(' ') << "MENU PENCARIAN DATA GURU " << setw(17) << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan NPDN Guru : ";cin>>inputnpdn;
    cariGuruLinear(jumlahGuru,inputnpdn);
}

void menuCari(){
        int menuCari;
        do{
        system("cls");
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|" << setw(33) << setfill(' ') << "MENU PENCARIAN DATA" << setw(17) << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "|Pilihan Menu : " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|1. Data Siswa  " << setw(35) << setfill(' ') << "|" << endl;
        cout << "|2. Data Guru   " << setw(35) << setfill(' ') << "|" << endl;
        cout << "+" << setw(50) << setfill('=') << "+" << endl;
        cout << "Masukkan Pilihan Menu : ";cin>>menuCari;
        if (menuCari==1){
        menuCariSiswa();
        }else if (menuCari==2){
        menuCariGuru();
        }else if (menuCari!=1&&menuCari!=2)
        {
        cout<<"Input yang anda masukkan salah"<<endl;
        system("pause");
        }
        }while (menuCari!=1&&menuCari!=2);
    
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
    cout << "|3. Cari Data   " << setw(35) << setfill(' ') << "|" << endl;
    cout << "+" << setw(50) << setfill('=') << "+" << endl;
    cout << "Masukkan Pilihan Menu : ";
    cin >> menu;
    if (menu == 1)
    {
    menuInput();
    }else if (menu == 2){
    menuOutput();
    }else if (menu == 3){
    menuCari();
    }else if (menu !=1 && menu !=2 && menu !=3){
    cout<<"Input yang anda masukkan salah"<<endl;
    system("pause");
    }
    } while (menu !=1 && menu !=2 && menu !=3);
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

}