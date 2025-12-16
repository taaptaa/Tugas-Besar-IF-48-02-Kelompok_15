#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

/* ============================================================
   MACRO
   ============================================================ */
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define child(P) P->child

typedef struct elmList_Sales* addressSales;

/* ============================================================
   BAGIAN MOBIL (Child DLL)
   ============================================================ */
struct infotypeMobil {
    string merk;
    string tipe;
    string tahun;
    string idMobil;
    double harga;
    int jumlahTerjual;
};

typedef struct elmList_Mobil* addressMobil;

struct elmList_Mobil {
    infotypeMobil info;
    addressMobil next;
    addressMobil prev;
};

/* ---- FUNGSI MOBIL ---- */
addressMobil createElmMobil(infotypeMobil data);
void insertFirstMobil(addressSales S, addressMobil M);
void insertLastMobil(addressSales S, addressMobil M);
void insertAfterMobil(addressSales S, addressMobil Prec, addressMobil M);
void deleteFirstMobil(addressSales S, addressMobil &M);
void deleteLastMobil(addressSales S, addressMobil &M);
void deleteAfterMobil(addressSales S, addressMobil Prec, addressMobil &M);
void deleteMobilFromSales(addressSales S, string idMobil);
addressMobil findMobilPadaSales(addressSales S, string idMobil);
void viewMobilSales(addressSales S);

/* ============================================================
   BAGIAN SALES (Parent SLL)
   ============================================================ */
struct infotypeSales {
    string idSales;
    string nama;
    string noTelp;
};

struct elmList_Sales {
    infotypeSales info;
    addressSales next;
    addressMobil child;
};

struct ListSales {
    addressSales first;
};

/* ---- FUNGSI SALES ---- */
void createListSales(ListSales &L);
addressSales createElmSales(infotypeSales data);
void insertFirstSales(ListSales &L, addressSales P);
void insertLastSales(ListSales &L, addressSales P);
void insertAfterSales(ListSales &L, addressSales Prec, addressSales P);
void deleteFirstSales(ListSales &L, addressSales &P);
void deleteLastSales(ListSales &L, addressSales &P);
void deleteAfterSales(ListSales &L, addressSales Prec, addressSales &P);
addressSales findElemenSales(ListSales L, string idSales);
void viewSales(ListSales L);
void hitungMobilTerjualPerMerk(ListSales L);
void hitungScoreSales(ListSales L);

/* ============================================================
   MENU
   ============================================================ */
void menuAdmin(ListSales &L);
void menuParent(ListSales &L);
void menuChild(ListSales &L);

#endif // HEADER_H_INCLUDED
