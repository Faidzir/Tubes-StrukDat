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
    cout << "=========LIST Barang========\n";
    while(Q != NULL){
        cout << info(Q) << endl;
        Q = next(Q);
    }
    cout << "============================\n";
    cout << endl;
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
    cout << "=========LIST TOKO==========\n";
    while(Q != NULL){ // add show child

        cout << info(Q) << endl;
        adr_sewa S = firstSewa(Q);
        if(S != NULL){
            int i = 1;
            while(S != NULL){
                cout << i << ". " << info(info(S)) << endl;
                S = next(S);
            }
            cout << endl;
        }
        Q = next(Q);

    }
    cout << "============================\n";
    cout << endl;
}

adr_sewa createElmSewa(adr_barang barang){
    adr_sewa P = new elmSewa;
    info(P) = barang;
    next(P) = NULL;
    return P;
}

void insertLastSewa(listToko &LT, adr_sewa S, adr_toko T){
    if(T == NULL){
        cout << "Toko Not Found\n";
    }else if (firstSewa(T) == NULL){
        firstSewa(T) = S;
    }else{
        adr_sewa Q = firstSewa(T);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = S;
    }
}

void deleteLastToko(listToko &LT, adr_toko &T){
    if(first(LT) == NULL){
        cout << "=======LIST KOSONG=======\n";
    }else if (next(first(LT)) == NULL){
        T = first(LT);
        first(LT) = NULL;
    }else{
        adr_toko Q = first(LT);
        while(next(next(Q))!= NULL){
            Q = next(Q);
        };
        T = next(Q);
        next(Q) = NULL;
    }
}

void deleteFirstBarang(listBarang &LB, adr_barang &B){
    if(first(LB) == NULL){
        cout << "=======LIST KOSONG=======\n";
    }else if (next(first(LB)) == NULL){
        B = first(LB);
        first(LB) = NULL;
    }else{
        B = first(LB);
        first(LB) = next(B);
        next(B) =NULL;
    }

}
