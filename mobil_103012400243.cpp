#include "header.h"

using namespace std;

void deleteFirstMobil(addressSales S, addressMobil &M) {
    M = child(S);
    if (M != NULL) {
        child(S) = next(M);
        if (child(S) != NULL)
            prev(child(S)) = NULL;

        next(M) = prev(M) = NULL;
    }
}

void deleteLastMobil(addressSales S, addressMobil &M) {
    M = child(S);
    if (M == NULL) return;

    // kalau elemen cuma satu
    if (next(M) == NULL) {
        child(S) = NULL;
    } else {
        while (next(M) != NULL) {
            M = next(M);
        }
        next(prev(M)) = NULL;
    }
    prev(M) = next(M) = NULL;
}

void deleteAfterMobil(addressSales S, addressMobil Prec, addressMobil &M) {
    if (Prec == NULL) return;
    M = next(Prec);
    if (M != NULL) {
        next(Prec) = next(M);
        if (next(M) != NULL)
            prev(next(M)) = Prec;

        next(M) = prev(M) = NULL;
    }
}

void deleteMobilFromSales(addressSales S, string idMobil) {
    addressMobil M = child(S);

    while (M != NULL) {
        if (info(M).idMobil == idMobil) {

            // kasus delete first
            if (M == child(S)) {
                child(S) = next(M);
                if (child(S) != NULL)
                    prev(child(S)) = NULL;
            }
            // kasus delete tengah/last
            else {
                prev(M)->next = next(M);
                if (next(M) != NULL)
                    prev(next(M)) = prev(M);
            }

            delete M;
            return;
        }
        M = next(M);
    }
}

void viewMobilSales(addressSales S) {
    cout << "\n===== LIST MOBIL SALES: " << info(S).nama << " =====\n";

    if (child(S) == NULL) {
        cout << "Tidak ada mobil.\n";
        return;
    }

    addressMobil M = child(S);
    while (M != NULL) {
        cout << "ID: " << info(M).idMobil
             << " | Merk: " << info(M).merk
             << " | Tipe: " << info(M).tipe
             << " | Tahun: " << info(M).tahun
             << " | Harga: " << info(M).harga
             << " | Terjual: " << info(M).jumlahTerjual
             << endl;

        M = next(M);
    }
}

