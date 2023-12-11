#include "tokoSewa.h"
int main()
{
    listToko LT;
    listBarang LB;

    //Initialization List
    createListToko(LT);
    createListBarang(LB);

//    //Insert List Barang
//

//
//    //Insert List Toko
//
//
//    //Insert Barang Sewa
//    adr_sewa S = createElmSewa(first(LB));
//    insertLastSewa(LT,S,first(LT));


//=============Insert Data Parent==================
//========Insert Data Toko/First List==============
    adr_toko Q = createElmToko("TJ Mart");
    insertFirstToko(LT,Q);
    Q = createElmToko("Tel-U Electronic");
    insertFirstToko(LT,Q);
    Q = createElmToko("Sukapura Rental");
    insertFirstToko(LT,Q);

//========Insert Data Barang/Second List==============
    adr_barang P = createElmBarang("DVD Player");
    insertLastBarang(LB,P);
    P = createElmBarang("Playstation 1");
    insertLastBarang(LB,P);
    P = createElmBarang("Television OLED 4K HD++");
    insertLastBarang(LB,P);

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


////=========Show All Data Parent=====================
//=======Show Data Toko==============
    showToko(LT);
////=======Show Data Barang===========
//    showBarang(LB);
//
////=========Delete Parent Data=====================
//=========Delete First List Toko======================
    deleteLastToko(LT,Q);
    showToko(LT);
//=========Delete Last List Barang======================
    deleteFirstBarang(LB,P);
    showBarang(LB);
    showToko(LT);
    return 0;
}
