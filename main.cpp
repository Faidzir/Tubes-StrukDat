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
    showToko(LT);


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
    showBarang(LB);

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


//=========Show All Data Parent=====================
//=======Show Data Toko==============
//    showToko(LT);
//=======Show Data Barang===========
//    showBarang(LB);
//
//=========Delete Parent Data=====================
//=========Delete First List Toko======================
//    deleteLastToko(LT,Q);
//    showToko(LT);
//=========Delete Last List Barang======================
//    deleteFirstBarang(LB,P,LT);
//    showBarang(LB);
//    showToko(LT);
//
//=========Show Barang yang disewa oleh suatu toko=======
//    showBarangToko(LT,"Tel-U Electronic");
//=========Show Toko yang menyewakan suatu barang========
//    showAllSewa(LT,"Playstation 1");
    return 0;
}
