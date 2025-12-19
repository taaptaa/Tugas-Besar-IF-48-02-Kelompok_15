#include "header.h"
#include <iomanip>

using namespace std;

/* ============================================================
   DELETE FIRST MOBIL
   ============================================================ */
void deleteFirstMobil(addressSales S, addressMobil &M) {
    M = child(S);
    if (M != NULL) {
        child(S) = next(M);
        if (child(S) != NULL)
            prev(child(S)) = NULL;

        next(M) = prev(M) = NULL;
    }
}

/* ============================================================
   DELETE LAST MOBIL
   ============================================================ */
void deleteLastMobil(addressSales S, addressMobil &M) {
    if (child(S) == NULL) {
        M = NULL;
        return;
    }

    M = child(S);

    // satu elemen
    if (next(M) == NULL) {
        child(S) = NULL;
    } else {
        while (next(M) != NULL) {
            M = next(M);
        }
        next(prev(M)) = NULL;
    }

    prev(M) = next(M) = NULL;
    delete M;   // ✅ WAJIB
}


/* ============================================================
   DELETE AFTER MOBIL
   ============================================================ */
void deleteAfterMobil(addressSales S, addressMobil Prec, addressMobil &M) {
    if (Prec == NULL || next(Prec) == NULL) {
        M = NULL;
        return;
    }

    M = next(Prec);
    next(Prec) = next(M);

    if (next(M) != NULL)
        prev(next(M)) = Prec;

    next(M) = prev(M) = NULL;
    delete M;
}


/* ============================================================
   DELETE MOBIL BERDASARKAN ID
   ============================================================ */
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

/* ============================================================
   SHOW MOBIL PER SALES
   ============================================================ */
void viewMobilSales(addressSales S) {
    cout << "=========================================================================================\n";
    cout << "                     LIST MOBIL SALES : " << info(S).nama << endl;
    cout << "=========================================================================================\n";

    if (child(S) == NULL) {
        cout << "Tidak ada mobil.\n";
        cout << "=========================================================================================\n";
        return;
    }
    cout << fixed << setprecision(0);
    // Header kolom
    cout << left
         << setw(4)  << "No"
         << setw(8)  << "ID"
         << setw(12) << "Merk"
         << setw(12) << "Tipe"
         << setw(8)  << "Tahun"
         << setw(15) << "Harga"
         << setw(10) << "Terjual"
         << endl;

    cout << "-----------------------------------------------------------------------------------------\n";

    addressMobil M = child(S);
    int no = 1;

    while (M != NULL) {
        cout << left
             << setw(4)  << no++
             << setw(8)  << info(M).idMobil
             << setw(12) << info(M).merk
             << setw(12) << info(M).tipe
             << setw(8)  << info(M).tahun
             << setw(15) << info(M).harga
             << setw(10) << info(M).jumlahTerjual
             << endl;

        M = next(M);
    }

    cout << "=========================================================================================\n";
}

