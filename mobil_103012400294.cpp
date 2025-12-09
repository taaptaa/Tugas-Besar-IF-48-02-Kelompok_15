#include "header.h"

using namespace std;

void insertFirstSales(ListSales &L, addressSales P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        next(P) = L.first;
        L.first = P;
    }
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

void insertAfterSales(ListSales &L, addressSales Prec, addressSales P) {
    if (Prec != NULL) {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstSales(ListSales &L, addressSales &P) {
    if (L.first != NULL) {
        P = L.first;
        L.first = next(P);
        next(P) = NULL;
    }
}

void deleteLastSales(ListSales &L, addressSales &P) {
    if (L.first != NULL) {
        if (next(L.first) == NULL) {  // hanya 1 elemen
            P = L.first;
            L.first = NULL;
        } else {
            addressSales Q = L.first;
            while (next(next(Q)) != NULL) {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
        }
        next(P) = NULL;
    }
}

void deleteAfterSales(ListSales &L, addressSales Prec, addressSales &P) {
    if (Prec != NULL && next(Prec) != NULL) {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
