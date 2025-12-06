#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED

#include "mobil.h" // Parent wajib include Child
#include <iostream>
#include <string>
using namespace std;

#define next(P) P->next
#define info(P) P->info
#define child(P) P->mobil // Akses ke list child

struct infotypeSales {
    string idSales;
    string nama;
    string noTelp;
};

typedef struct elmList_Sales *addressSales;

struct elmList_Sales {
    infotypeSales info;
    addressSales next;

    // INI KUNCINYA: List Child ada di dalam Node Parent
    ListMobil mobil;
};

struct ListSales {
    addressSales first;
};

void createListSales(ListSales &L);
addressSales createElmSales(string id, string nama, string noTelp);
void insertLastSales(ListSales &L, addressSales P);

// Fungsi untuk menghapus Parent (Hati-hati, anaknya harus dihapus dulu!)
void deleteFirstSales(ListSales &L, addressSales &P);
void deleteParentAndChild(ListSales &L, string idSales);

// Fungsi Utama Showroom
void showAllData(ListSales L);
addressSales searchSales(ListSales L, string idSales);

#endif
