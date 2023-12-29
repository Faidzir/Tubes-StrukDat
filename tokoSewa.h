#ifndef TOKOSEWA_H_INCLUDED
#define TOKOSEWA_H_INCLUDED
#include <iostream>
using namespace std;
typedef struct elmSewa *adr_sewa;//pointer ElmSewa
typedef struct elmToko *adr_toko;//pointer ElmToko
typedef struct elmBarang *adr_barang;//pointer ElmBarang
#define first(L) ((L).first)
#define info(P) ((P)->info)
#define next(P) ((P)->next)
#define firstSewa(P) ((P)->firstSewa)
struct elmSewa{
    adr_barang info;
    adr_sewa next;//nextSewa
};

struct infoToko{
    string nama;
    string id;
    int tahun;
};

struct elmToko{
    infoToko info;
    adr_sewa firstSewa;
    adr_toko next;//nextToko
};


//Elemen Barang

struct infoBarang{
    string nama;
    string id;
    string jenis;
};

struct elmBarang{
    infoBarang info;
    adr_barang next;//nextBarang
};

struct listToko{
    adr_toko first;
};

struct listBarang{
    adr_barang first;
};

void createListToko(listToko &LT);
void createListBarang(listBarang &LB);
adr_barang createElmBarang(infoBarang barang);
adr_toko createElmToko(infoToko toko);
adr_sewa createElmSewa(adr_barang barang);
void insertLastBarang(listBarang &LB, adr_barang P);
void insertFirstToko(listToko &LT, adr_toko Q);
void showToko(listToko LT);
void showBarang(listBarang LB);
void insertLastSewa(listToko &LT, adr_sewa S, adr_toko T);
void deleteToko(listToko &LT, string ID);
void deleteBarang(listBarang &LB, string id,listToko &LT);
void deleteBarangToko(listToko &LT, string idToko, string idBarang);
void showBarangToko(listToko &LB, adr_toko T);
void showAllSewa(listToko LT,infoBarang barang);
void menu(int x, listToko &LT, listBarang &LB);
void maxMin(listToko LT);
bool found(adr_toko T, adr_barang B);
#endif // TOKOSEWA_H_INCLUDED
