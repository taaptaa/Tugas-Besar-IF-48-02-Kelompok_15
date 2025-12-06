#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED

#include "mobil.h" //
#include <iostream>
#include <string>
using namespace std;

#define next(P) P->next
#define info(P) P->info
#define child(P) P->mobil

struct infotypeSales {
    string idSales;
    string nama;
    string noTelp;
};

typedef struct elmList_Sales *addressSales;

struct elmList_Sales {
    infotypeSales info;
    addressSales next;

    ListMobil mobil;
};

struct ListSales {
    addressSales first;
};

void createListSales(ListSales &L);
addressSales createElmSales(string id, string nama, string noTelp);
void insertLastSales(ListSales &L, addressSales P);


void deleteFirstSales(ListSales &L, addressSales &P);
void deleteParentAndChild(ListSales &L, string idSales);


void showAllData(ListSales L);
addressSales searchSales(ListSales L, string idSales);
// testing

#endif
