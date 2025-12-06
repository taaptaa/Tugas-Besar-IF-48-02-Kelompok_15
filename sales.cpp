#include "sales.h"

void createListSales(ListSales &L) {
    L.first = NULL;
}

addressSales createElmSales(string id, string nama, string noTelp) {
    addressSales P = new elmList_Sales;
    info(P).idSales = id;
    info(P).nama = nama;
    info(P).noTelp = noTelp;
    next(P) = NULL;

    // SANGAT PENTING: Inisialisasi List Child saat Parent dibuat
    createListMobil(child(P));

    return P;
}

void insertLastSales(ListSales &L, addressSales P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        addressSales Q = L.first;
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void showAllData(ListSales L) {
    addressSales P = L.first;
    while (P != NULL) {
        cout << "[SALES] " << info(P).nama << " - ID: " << info(P).idSales << endl;
        // Panggil fungsi show child milik sales ini
        showMobil(child(P));
        cout << "----------------------------------------" << endl;
        P = next(P);
    }
}

addressSales searchSales(ListSales L, string idSales) {
    addressSales P = L.first;
    while (P != NULL) {
        if (info(P).idSales == idSales) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
