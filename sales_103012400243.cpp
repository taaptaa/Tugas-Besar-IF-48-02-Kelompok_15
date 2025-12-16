#include "header.h"

using namespace std;

void createListSales(ListSales &L) {
    L.first = NULL;
}

addressSales createElmSales(infotypeSales data) {
    addressSales P = new elmList_Sales;
    info(P) = data;
    next(P) = NULL;
    child(P) = NULL;
    return P;
}

addressSales findElemenSales(ListSales L, string idSales) {
    addressSales P = L.first;

    while (P != NULL) {
        if (info(P).idSales == idSales) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void viewSales(ListSales L) {
    addressSales S = L.first;

    if (S == NULL) {
        cout << "Data sales kosong.\n";
        return;
    }

    cout << "\n=== DAFTAR SALES ===\n";
    while (S != NULL) {
        cout << "ID   : " << info(S).idSales << endl;
        cout << "Nama : " << info(S).nama << endl;
        cout << "Telp : " << info(S).noTelp << endl;
        cout << "---------------------------\n";
        S = next(S);
    }
}

void hitungMobilTerjualPerMerk(ListSales L) {
    cout << "\n=== TOTAL MOBIL TERJUAL PER MERK ===\n";

    string merkList[100];
    int totalList[100];
    int n = 0;

    addressSales S = L.first;

    while (S != NULL) {
        addressMobil M = child(S);

        while (M != NULL) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (merkList[i] == info(M).merk) {
                    totalList[i] += info(M).jumlahTerjual;
                    found = true;
                    break;
                }
            }

            if (!found) {
                merkList[n] = info(M).merk;
                totalList[n] = info(M).jumlahTerjual;
                n++;
            }

            M = next(M);
        }
        S = next(S);
    }

    if (n == 0) {
        cout << "Belum ada data mobil.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << merkList[i] << " : " << totalList[i] << " unit terjual\n";
    }
}

void hitungScoreSales(ListSales L) {
    cout << "\n=== SCORE SALES (BERDASARKAN TOTAL TERJUAL) ===\n";

    if (L.first == NULL) {
        cout << "Data sales kosong.\n";
        return;
    }

    addressSales S = L.first;
    addressSales bestSales = NULL;
    int maxTotal = -1;

    while (S != NULL) {
        int total = 0;
        addressMobil M = child(S);

        while (M != NULL) {
            total += info(M).jumlahTerjual;
            M = next(M);
        }

        cout << "Sales " << info(S).nama
             << " (ID: " << info(S).idSales << ")"
             << " -> Total terjual: " << total << endl;

        if (total > maxTotal) {
            maxTotal = total;
            bestSales = S;
        }

        S = next(S);
    }

    if (bestSales != NULL) {
        cout << "\n=== SALES TERBAIK ===\n";
        cout << "Nama  : " << info(bestSales).nama << endl;
        cout << "ID    : " << info(bestSales).idSales << endl;
        cout << "Total : " << maxTotal << " unit terjual\n";
    }
}
