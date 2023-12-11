#ifndef TOKOSEWA_H_INCLUDED
#define TOKOSEWA_H_INCLUDED
#include <iostream>
using namespace std;
typedef string infotype;
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


struct elmToko{
    infotype info;
    adr_sewa firstSewa;
    adr_toko next;//nextToko
};


//Elemen Barang

struct elmBarang{
    infotype info;
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
adr_barang createElmBarang(infotype namaBarang);
adr_toko createElmToko(infotype namaToko);
adr_sewa createElmSewa(adr_barang barang);
void insertLastBarang(listBarang &LB, adr_barang P);
void insertFirstToko(listToko &LT, adr_toko Q);
void showToko(listToko LT);
void showBarang(listBarang LB);
void insertLastSewa(listToko &LT, adr_sewa S, adr_toko T);
void deleteLastToko(listToko &LT, adr_toko &T);
void deleteFirstBarang(listBarang &LB, adr_barang &B);
#endif // TOKOSEWA_H_INCLUDED
