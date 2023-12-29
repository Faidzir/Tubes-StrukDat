#include "tokoSewa.h"
int main()
{
    listToko LT;
    listBarang LB;

//    Initialization List
    createListToko(LT);
    createListBarang(LB);

//=============Insert Data Parent==================
//========Insert Data Toko/First List==============
    infoToko toko;
    toko.nama = "TJ Mart";
    toko.id = "1";
    toko.tahun = 2000;
    adr_toko Q = createElmToko(toko);
    insertFirstToko(LT,Q);
    toko.nama = "Yogya";
    toko.id = "2";
    toko.tahun = 1999;
    Q = createElmToko(toko);
    insertFirstToko(LT,Q);
    toko.nama = "TransMart";
    toko.id = "3";
    toko.tahun = 1500;
    Q = createElmToko(toko);
    insertFirstToko(LT,Q);



//========Insert Data Barang/Second List==============
    infoBarang barang;
    barang.nama = "DVD Player";
    barang.id = "1";
    barang.jenis = "Electronic";
    adr_barang P = createElmBarang(barang);
    insertLastBarang(LB,P);
    barang.nama = "Ember";
    barang.id = "2";
    barang.jenis = "Rumah Tangga";
    P = createElmBarang(barang);
    insertLastBarang(LB,P);
    barang.nama = "Playstation 1";
    barang.id = "3";
    barang.jenis = "Electronic";
    P = createElmBarang(barang);
    insertLastBarang(LB,P);
//    showBarang(LB);

//Insert Barang to Toko
    adr_sewa S = createElmSewa(first(LB));
    adr_toko T = first(LT);
    insertLastSewa(LT,S,T);
    S = createElmSewa(next(first(LB)));
    T = next(T);
    insertLastSewa(LT,S,T);
    S = createElmSewa(next(next(first(LB))));
    T = next(T);
    insertLastSewa(LT,S,T);



//=========Show Barang yang disewa oleh suatu toko=======
//    showBarangToko(LT,toko);
//=========Show Toko yang menyewakan suatu barang========
//    showAllSewa(LT,barang);

//============Menu===========
    int pil = 1;
    cout << "========WELCOME==========\n";
    while(pil != 0){
        cout << "1. Lihat Toko & Barang yang Disewakan\n";
        cout << "2. Lihat Semua Barang yang tersedia\n";
        cout << "3. Tambahkan Toko\n";
        cout << "4. Tambahkan Barang\n";
        cout << "5. Tambahkan Barang yang disewakan Suatu Toko\n";
        cout << "6. Tampilkan Barang yang tersedia pada suatu Toko\n";
        cout << "7. Tampilkan Toko yang menyewakan suatu barang\n";
        cout << "8. Tampilkan Toko yang paling banyak dan paling sedikit menyewakan barang\n";
        cout << "9. Hapus Daftar Toko\n";
        cout << "10. Hapus Daftar Barang\n";
        cout << "11. Hapus Barang Suatu Toko\n";
        cout << "0. Keluar Dari Program\n";
        cout << endl;
        cout << "Masukkan Input: ";
        cin >> pil;
        menu(pil,LT,LB);
    }

    return 0;
}
