#ifndef MOBIL_H_INCLUDED
#define MOBIL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

// Tipe Data Mobil
struct infotypeMobil {
    string merk;
    string tipe;
    string tahun;
    double harga;
};

typedef struct elmList_Mobil *addressMobil;

struct elmList_Mobil {
    infotypeMobil info;
    addressMobil next;
    addressMobil prev;
};

struct ListMobil {
    addressMobil first;
    addressMobil last;
};

// Primitif Dasar
void createListMobil(ListMobil &L);
addressMobil createElmMobil(string merk, string tipe, string tahun, double harga);
void insertLastMobil(ListMobil &L, addressMobil P);
void deleteFirstMobil(ListMobil &L, addressMobil &P);
void deleteLastMobil(ListMobil &L, addressMobil &P);
void deleteAfterMobil(addressMobil Prec, addressMobil &P);
void showMobil(ListMobil L);

#endif
