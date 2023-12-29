#include "tokoSewa.h"

void createListToko(listToko &LT){
    first(LT) = NULL;
}

void createListBarang(listBarang &LB){
    first(LB) = NULL;
}

adr_barang createElmBarang(infoBarang barang){
    adr_barang P = new elmBarang;
    info(P).nama = barang.nama;
    info(P).id = barang.id;
    info(P).jenis = barang.jenis;
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
        cout << "Nama: " << info(Q).nama << endl;
        cout << "ID: " << info(Q).id << endl;
        cout << "Jenis: " << info(Q).jenis << endl;
        Q = next(Q);
        cout << endl;
    }
    cout << "============================\n";
    cout << endl;
}

adr_toko createElmToko(infoToko toko){
    adr_toko Q = new elmToko;
    info(Q).nama = toko.nama;
    info(Q).id = toko.id;
    info(Q).tahun = toko.tahun;
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
    cout << "=========LIST TOKO & BARANG==========\n";
    while(Q != NULL){ // add show child
        cout  << "Nama: " << info(Q).nama << endl;
        cout  <<  "ID: "<< info(Q).id << endl;
        cout  << "Tahun: " << info(Q).tahun << endl;
        adr_sewa S = firstSewa(Q);
        if(S != NULL){
            int i = 1;
            while(S != NULL){
                cout << i << ". Nama: " << info(info(S)).nama << endl;
                cout << "   ID: " << info(info(S)).id << endl;
                cout << "   Jenis: " << info(info(S)).jenis << endl;
                S = next(S);
                i++;
            }
            cout << endl;
        }
        Q = next(Q);
        cout << endl;

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

void deleteToko(listToko &LT, string ID){
    adr_toko Q = first(LT);
    while(Q != NULL && info(Q).id != ID){
        Q = next(Q);
    }
    if(Q == NULL){
        cout << "----Toko Tidak Ditemukan----\n";
    }else{
        adr_toko P;
        if(Q == first(LT)){
            if(next(first(LT)) == NULL){
                P = first(LT);
                first(LT) = NULL;
                delete(P);
            }else{
                P = Q;
                first(LT) = next(P);
                next(P) = NULL;
                delete(P);
            }
        }else if (next(Q) == NULL){
            P = first(LT);
            while(next(P) != Q){
                P = next(P);
            }
            next(P) = NULL;
            delete(Q);
        }else{
            P = first(LT);
            while(next(P) != Q){
                P = next(P);
            }
            next(P) = next(Q);
            delete(Q);
        }
    }
}

void deleteBarang(listBarang &LB, string id, listToko &LT){
//    if(first(LB) == NULL){
//        cout << "=======LIST KOSONG=======\n";
//    }else if (next(first(LB)) == NULL){
//        B = first(LB);
//        first(LB) = NULL;
//    }else{
//        B = first(LB);
//        first(LB) = next(B);
//        next(B) =NULL;
//    }

    adr_barang B = first(LB);
    while(B != NULL && info(B).id != id ){
        B = next(B);
    }

    if(B == NULL){
        cout << "---- Barang Tidak Ditemukan ----\n";
    }else{
        if(B == first(LB)){
            if(next(first(LB)) == NULL){
                first(LB) = NULL;
            }else{
                first(LB) = next(B);
            }
        }else{
            adr_barang Q = first(LB);
            while(next(Q) != B){
                Q = next(Q);
            }
            next(Q) = next(B);
        }
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

void showBarangToko(listToko &LT, adr_toko T){
    adr_sewa S = firstSewa(T);
    int i = 1;
    cout << "=====Barang yang Disewakan======\n";
    while(S != NULL){
        cout << i << ". " << info(info(S)).nama << endl;
        S = next(S);
        i++;
    }
    cout << endl;
}

void showAllSewa(listToko LT,infoBarang barang){
    adr_toko T = first(LT);
    while(T != NULL){
        bool found = false;
        adr_sewa S = firstSewa(T);
        while(S != NULL && !found){
            if(info(info(S)).id == barang.id){
                found = true;
            }else{
                S = next(S);
            }
        }
        if(found){
            cout << "Nama Toko:" << info(T).nama << endl;
        }
        T = next(T);
    }
}

adr_toko findToko(listToko LT, string id){
    adr_toko T = first(LT);
    while(T != NULL){
        if(info(T).id == id){
            return T;
        }
        T = next(T);
    }
    return NULL;
}

adr_barang findBarang(listBarang LB, string id){
    adr_barang B = first(LB);
    while(B != NULL){
        if(info(B).id == id){
            return B;
        }
        B = next(B);
    }
    return NULL;
}

bool found(adr_toko T, adr_barang B){
    adr_sewa S = firstSewa(T);
    while(S != NULL){
        if(info(S) == B){
            return true;
        }
        S = next(S);
    }
    return false;
}

void maxMin(listToko LT){
    int max = -1;
    int min = 9999999;
    adr_toko tMax = NULL;
    adr_toko tMin = NULL;
    adr_toko T = first(LT);
    while(T != NULL){
        int count = 0;
        adr_sewa S = firstSewa(T);
        while(S != NULL){
            count++;
            S = next(S);
        }
        if(count < min){
            min = count;
            tMin = T;
        }
        if(count > max){
            max = count;
            tMax = T;
        }
        T = next(T);
    }
    cout << "Toko Terbanyak yang menyewakan Barang: " << info(tMax).nama << endl;
    cout << "Toko Tersedikit yang menyewakan Barang: " << info(tMin).nama << endl;
    cout << "==========================\n";
}

void deleteBarangToko(listToko &LT, string idToko, string idBarang){
    adr_toko T = first(LT);
    while(T != NULL && info(T).id != idToko){
        T = next(T);
    }
    if(T == NULL){
        cout << "---- Toko Tidak Ditemukan ----\n";
    }else{
        adr_sewa S = firstSewa(T);
        while(S != NULL && info(info(S)).id != idBarang){
            S = next(S);
        }
        if(S == NULL){
            cout << "---- Barang Tidak Ditemukan ----\n";
        }else{
            if(S == firstSewa(T)){
                firstSewa(T) = next(S);
            }else{
                adr_sewa Q = firstSewa(T);
                while(next(Q) != S){
                    Q = next(Q);
                }
                next(Q) = next(S);
            }
        }

    }
}

void menu(int x, listToko &LT, listBarang &LB){
    if(x == 1){
        showToko(LT);
    }else if(x == 2){
        showBarang(LB);
    }else if(x == 3){
        infoToko toko;
        cout << "Masukan ID Toko: ";
        cin >> toko.id;
        cout << "Masukan Nama Toko: ";
        cin >> toko.nama;
        cout << "Masukan Tahun Toko: ";
        cin >> toko.tahun;
        adr_toko T = createElmToko(toko);
        insertFirstToko(LT,T);
    }else if (x == 4){
        infoBarang barang;
        cout << "Masukan ID Barang: ";
        cin >> barang.id;
        cout << "Masukan Nama Barang: ";
        cin >> barang.nama;
        cout << "Masukan Jenis Barang: ";
        cin >> barang.jenis;
        adr_barang B = createElmBarang(barang);
        insertLastBarang(LB,B);
    }else if (x == 5){
        string id;
        cout << "=====Pilih Toko====\n";
        showToko(LT);
        cout << "Masukkan ID Toko: ";
        cin >> id;
        adr_toko T = findToko(LT,id);
        if(T == NULL){
            cout << "Maaf toko tidak ditemukan!\n";
        }else{
            cout << "=======Pilih Barang=======\n";
            showBarang(LB);
            cout << "Masukkan ID Barang: ";
            cin >> id;
            adr_barang B = findBarang(LB,id);
            if(B == NULL){
                cout << "Maaf barang tidak ditemukan!\n";
            }else{
                if(!found(T,B)){
                    adr_sewa S = createElmSewa(B);
                    insertLastSewa(LT,S,T);
                }

            }

        }
    }else if (x == 6){
        string id;
        cout << "======Pilih Toko========\n";
        showToko(LT);
        cout << "Masukan ID Toko: ";
        cin >> id;
        adr_toko T = findToko(LT,id);
        showBarangToko(LT,T);
    }else if (x == 7){
        string id;
        cout << "=======Pilih Barang========\n";
        showBarang(LB);
        cout << "Masukan ID Barang: ";
        cin >> id;
        adr_toko T = first(LT);
        while(T != NULL){
            adr_sewa S = firstSewa(T);
            while(S != NULL){
                if(info(info(S)).id == id){
                    cout << info(T).nama << endl;
                }
                S = next(S);
            }
            T = next(T);
        }
        cout << endl;
    }else if (x == 8){
        maxMin(LT);
    }else if (x == 9){
        string id;
        showToko(LT);
        cout << "Masukkan ID toko yang ingin dihapus: ";
        cin >> id;
        deleteToko(LT,id);
    }else if(x == 10){
        string id;
        showBarang(LB);
        cout << "Masukkan ID barang yang ingin dihapus: ";
        cin >> id;
        deleteBarang(LB,id,LT);
    }else if (x == 11){
        string idToko, idBarang;
        showToko(LT);
        cout << "Masukkan ID Toko: ";
        cin >> idToko;
        cout << "Masukkan ID Barang: ";
        cin >> idBarang;
        deleteBarangToko(LT,idToko,idBarang);
    }
}
