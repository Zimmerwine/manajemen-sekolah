void outputDataGuru(Dataguru* &arrayGuru, int &jumlah_guru){
    if (jumlah_guru == 0) {
        cout << "Data Guru Belum Diinput\nSilahkan Input Data Terlebih Dahulu\n";
    } else {
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
    
}