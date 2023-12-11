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
                i++;
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

void deleteFirstBarang(listBarang &LB, adr_barang &B, listToko &LT){
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

    adr_toko T = first(LT);
    while(T != NULL){
        adr_sewa S = firstSewa(T);
        adr_sewa Q = NULL;
        while(S != NULL){
            if(info(S) == B){
                if(firstSewa(T) == S){
                    firstSewa(T) = next(S);
                    next(S) = NULL;
                    S = firstSewa(T);
                }
                else if (next(S) == NULL){
                    next(Q) = NULL;
                    S = next(S);
                }else{
                    next(Q) = next(S);
                    next(S) = NULL;
                    S = next(Q);
                }
                Q = S;
            }else{
                Q = S;
                S = next(S);
            }

        }
        T = next(T);
    }
}

void showBarangToko(listToko &LT, infotype toko){
    adr_toko T = first(LT);
    bool found = false;
    while(T != NULL && !found){
        if(info(T) == toko){
            found = true;
        }else{
            T = next(T);
        }
    }
    adr_sewa S = firstSewa(T);
    cout << "List Barang Yang Disewakan Toko " << toko << "\n" ;
    int i = 1;
    while(S != NULL){
        cout << i << ". " << info(info(S)) << endl;
        S = next(S);
        i++;
    }
}

void showAllSewa(listToko LT,infotype barang){
    adr_toko T = first(LT);
    while(T != NULL){
        bool found = false;
        adr_sewa S = firstSewa(T);
        while(S != NULL && !found){
            if(info(info(S)) == barang){
                found = true;
            }else{
                S = next(S);
            }
        }
        if(found){
            cout << "Nama Toko:" << info(T) << endl;
        }
        T = next(T);
    }
}
