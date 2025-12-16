#include "header.h"

void menuAdmin(ListSales &L){
    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Admin============\n";
        cout << "|| 1. Parent (Sales)         ||\n";
        cout << "|| 2. Child  (Mobil)         ||\n";
        cout << "|| 0. Back                   ||\n";
        cout << "===============================\n";
        cout << "Choose your option : ";
        cin >> option;

        switch(option) {
           case 1:
              menuParent(L);   
              break;
           case 2:
              menuChild(L);    
              break;
        }
    }
}




void menuParent(ListSales &L){
    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu Parent ============\n";
        cout << "|| 1. Insert First Sales           ||\n";
        cout << "|| 2. Insert Last Sales            ||\n";
        cout << "|| 3. Insert After Sales           ||\n";
        cout << "|| 4. Delete First Sales           ||\n";
        cout << "|| 5. Delete Last Sales            ||\n";
        cout << "|| 6. Delete After Sales           ||\n";
        cout << "|| 7. View Sales                   ||\n";
        cout << "|| 8. Lihat Score Sales            ||\n"; 
        cout << "|| 0. Back                         ||\n";
        cout << "====================================\n";
        cout << "Choose your option : ";
        cin >> option;


        infotypeSales data;
        addressSales P, Prec;

        switch(option){
            case 1:
                cout << "ID   : "; cin >> data.idSales;
                cout << "Nama : "; cin >> data.nama;
                cout << "Telp : "; cin >> data.noTelp;
                P = createElmSales(data);
                insertFirstSales(L, P);
                break;

            case 2:
                cout << "ID   : "; cin >> data.idSales;
                cout << "Nama : "; cin >> data.nama;
                cout << "Telp : "; cin >> data.noTelp;
                P = createElmSales(data);
                insertLastSales(L, P);
                break;

            case 3: {
                string idPrec;
                cout << "Insert setelah ID Sales: ";
                cin >> idPrec;
                Prec = findElemenSales(L, idPrec);
                if (Prec != NULL) {
                    cout << "ID   : "; cin >> data.idSales;
                    cout << "Nama : "; cin >> data.nama;
                    cout << "Telp : "; cin >> data.noTelp;
                    P = createElmSales(data);
                    insertAfterSales(L, Prec, P);
                } else {
                    cout << "Sales tidak ditemukan\n";
                    system("pause");
                }
                break;
            }

            case 4:
                deleteFirstSales(L, P);
                break;

            case 5:
                deleteLastSales(L, P);
                break;

            case 6: {
                string idPrec;
                cout << "Delete setelah ID Sales: ";
                cin >> idPrec;
                Prec = findElemenSales(L, idPrec);
                if (Prec != NULL) {
                    deleteAfterSales(L, Prec, P);
                } else {
                    cout << "Sales tidak ditemukan\n";
                    system("pause");
                }
                break;
            }

            case 7:
                viewSales(L);
                system("pause");
                break;

            case 8:   // ✅ OPSI BARU
                system("cls");
                hitungScoreSales(L);
                system("pause");
                break;
        }
    }
}

void menuChild(ListSales &L){
    int option = -99;
    while (option != 0) {
        system("cls");
        cout << "========== Menu Child (Mobil) ==========\n";
        cout << "|| 1. Insert First Mobil             ||\n";
        cout << "|| 2. Insert Last Mobil              ||\n";
        cout << "|| 3. Insert After Mobil             ||\n";
        cout << "|| 4. Delete First Mobil             ||\n";
        cout << "|| 5. Delete Last Mobil              ||\n";
        cout << "|| 6. Delete After Mobil             ||\n";
        cout << "|| 7. View Mobil per Sales           ||\n";
        cout << "|| 0. Back                           ||\n";
        cout << "=======================================\n";
        cout << "Choose: ";
        cin >> option;

        string idSales, idMobil;
        addressSales S;
        addressMobil M, PrecM;
        infotypeMobil data;

        switch(option){
            case 1:
                cout << "ID Sales: "; cin >> idSales;
                S = findElemenSales(L, idSales);
                if (S != NULL) {
                    cout << "ID Mobil: "; cin >> data.idMobil;
                    cout << "Merk    : "; cin >> data.merk;
                    cout << "Tipe    : "; cin >> data.tipe;
                    cout << "Tahun   : "; cin >> data.tahun;
                    cout << "Harga   : "; cin >> data.harga;
                    cout << "Terjual : "; cin >> data.jumlahTerjual;
                    M = createElmMobil(data);
                    insertFirstMobil(S, M);
                } else {
                    cout << "Sales tidak ditemukan.\n";
                    system("pause");
                }
                break;


            case 2:
                cout << "ID Sales: "; cin >> idSales;
                S = findElemenSales(L, idSales);
                if (S != NULL) {
                    cout << "ID Mobil: "; cin >> data.idMobil;
                    cout << "Merk    : "; cin >> data.merk;
                    cout << "Tipe    : "; cin >> data.tipe;
                    cout << "Tahun   : "; cin >> data.tahun;
                    cout << "Harga   : "; cin >> data.harga;
                    cout << "Terjual : "; cin >> data.jumlahTerjual;
                    M = createElmMobil(data);
                    insertLastMobil(S, M);
                }
                break;

            case 3:
                cout << "ID Sales: "; cin >> idSales;
                S = findElemenSales(L, idSales);
                if (S != NULL) {
                    cout << "Insert after ID Mobil: ";
                    cin >> idMobil;
                    PrecM = findMobilPadaSales(S, idMobil);
                    if (PrecM != NULL) {
                        cout << "ID Mobil: "; cin >> data.idMobil;
                        cout << "Merk    : "; cin >> data.merk;
                        cout << "Tipe    : "; cin >> data.tipe;
                        cout << "Tahun   : "; cin >> data.tahun;
                        cout << "Harga   : "; cin >> data.harga;
                        cout << "Terjual : "; cin >> data.jumlahTerjual;
                        M = createElmMobil(data);
                        insertAfterMobil(S, PrecM, M);
                    }
                }
                break;

            case 4:
                cout << "ID Sales: "; cin >> idSales;
                S = findElemenSales(L, idSales);
                if (S != NULL) deleteFirstMobil(S, M);
                break;

            case 5:
                cout << "ID Sales: "; cin >> idSales;
                S = findElemenSales(L, idSales);
                if (S != NULL) deleteLastMobil(S, M);
                break;

            case 6:
                cout << "ID Sales: "; cin >> idSales;
                S = findElemenSales(L, idSales);
                if (S != NULL) {
                    cout << "Delete after ID Mobil: ";
                    cin >> idMobil;
                    PrecM = findMobilPadaSales(S, idMobil);
                    if (PrecM != NULL)
                        deleteAfterMobil(S, PrecM, M);
                }
                break;

            case 7:
                cout << "ID Sales: "; cin >> idSales;
                S = findElemenSales(L, idSales);
                if (S != NULL) viewMobilSales(S);
                system("pause");
                break;
        }
    }
}
