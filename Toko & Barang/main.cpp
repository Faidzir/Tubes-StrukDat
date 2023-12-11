#include "tokoSewa.h"
int main()
{
    listToko LT;
    listBarang LB;

    //Initialization List
    createListToko(LT);
    createListBarang(LB);

    //Insert List Barang
    adr_barang P = createElmBarang("DVD Player");
    insertLastBarang(LB,P);
    P = createElmBarang("Playstation 1");
    insertLastBarang(LB,P);
    P = createElmBarang("Television OLED 4K HD++");
    insertLastBarang(LB,P);
//    showBarang(LB);

    //Insert List Toko
    adr_toko Q = createElmToko("TJ Mart");
    insertFirstToko(LT,Q);
    Q = createElmToko("Tel-U Electronic");
    insertFirstToko(LT,Q);
    Q = createElmToko("Sukapura Rental");
    insertFirstToko(LT,Q);
    showToko(LT);
    return 0;
}
