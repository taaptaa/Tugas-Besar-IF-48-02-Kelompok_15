#include "header.h"
using namespace std;


addressMobil createElmMobil(infotypeMobil data) {
    addressMobil P = new elmList_Mobil;
    info(P) = data;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirstMobil(addressSales S, addressMobil M) {
    if (child(S) == NULL) {
        child(S) = M;
    } else {
        next(M) = child(S);
        prev(child(S)) = M;
        child(S) = M;
    }
}


void insertLastMobil(addressSales S, addressMobil M) {
    if (child(S) == NULL) {
        child(S) = M;
    } else {
        addressMobil Q = child(S);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = M;
        prev(M) = Q;
    }
}


void insertAfterMobil(addressSales S, addressMobil Prec, addressMobil M) {
    if (Prec == NULL) return;

    next(M) = next(Prec);
    prev(M) = Prec;

    if (next(Prec) != NULL)
        prev(next(Prec)) = M;

    next(Prec) = M;
}

addressMobil findMobilPadaSales(addressSales S, string idMobil) {
    addressMobil M = child(S);

    while (M != NULL) {
        if (info(M).idMobil == idMobil) return M;
        M = next(M);
    }
    return NULL;
}
