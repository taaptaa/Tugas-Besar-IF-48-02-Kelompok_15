#include "mobil.h"

void createListMobil(ListMobil &L) {
    L.first = NULL;
    L.last = NULL;
}

addressMobil createElmMobil(string merk, string tipe, string tahun, double harga) {
    addressMobil P = new elmList_Mobil;
    info(P).merk = merk;
    info(P).tipe = tipe;
    info(P).tahun = tahun;
    info(P).harga = harga;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertLastMobil(ListMobil &L, addressMobil P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        prev(P) = L.last;
        next(L.last) = P;
        L.last = P;
    }
}

// Implementasikan deleteFirst, deleteLast, deleteAfter sesuai materi DLL
void deleteFirstMobil(ListMobil &L, addressMobil &P) {
    if(L.first != NULL){
        P = L.first;
        if(L.first == L.last){
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = next(P);
            prev(L.first) = NULL;
            next(P) = NULL;
        }
    }
}

void showMobil(ListMobil L) {
    addressMobil P = L.first;
    if (P == NULL) {
        cout << "   (Tidak ada mobil yang dipromosikan)" << endl;
    }
    while (P != NULL) {
        cout << "   -> " << info(P).merk << " " << info(P).tipe
             << " (" << info(P).tahun << ") - Rp" << info(P).harga << endl;
        P = next(P);
    }
}

