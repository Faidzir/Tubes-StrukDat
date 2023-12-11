#include "tokoSewa.h"

void createListToko(listToko &LT){
    first(LT) = NULL;
}

void createListBarang(listBarang &LB){
    first(LB) = NULL;
}

adr_barang createElmBarang(infotype namaBarang){
    adr_barang P = new elmBarang;
    info(P) = namaBarang;
    next(P) = NULL;
    return P;
}
void insertLastBarang(listBarang &LB, adr_barang P){
    if(first(LB) == NULL){
        first(LB) = P;
    }else{
        adr_barang Q = first(LB);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }

}

void showBarang(listBarang LB){
    adr_barang Q = first(LB);
    while(Q != NULL){
        cout << info(Q) << endl;
        Q = next(Q);
    }
}

adr_toko createElmToko(infotype namaToko){
    adr_toko Q = new elmToko;
    info(Q) = namaToko;
    firstSewa(Q) = NULL;
    next(Q) =NULL;
    return Q;
}

void insertFirstToko(listToko &LT, adr_toko Q){
    if(first(LT) == NULL){
        first(LT) = Q;
    }else{
        next(Q) = first(LT);
        first(LT) = Q;
    }
}

void showToko(listToko LT){
    adr_toko Q = first(LT);
    while(Q != NULL){ // add show child
        cout << info(Q) << endl;
        Q = next(Q);
    }
}
