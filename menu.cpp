#include "header.h"


void welcomeScreen() {
    system("cls");
    cout << "\n\n\n";
    cout << "\t==================================================================\n";
    cout << "\t||                                                              ||\n";
    cout << "\t||               APLIKASI MANAJEMEN DATA SHOWROOM               ||\n";
    cout << "\t||             (Implementasi Multi-Linked List C++)             ||\n";
    cout << "\t||                                                              ||\n";
    cout << "\t==================================================================\n";
    cout << "\n\n";
    cout << "\t                 Selamat Datang di Program Admin.\n";
    cout << "\t               Silakan tekan Enter untuk masuk...";
    cin.get();
}

void menuAdmin(ListSales &L){
    welcomeScreen();
    int option = -99;
    while (option != 0) {
        system("cls");
        system("cls");
        cout << "=========================================\n";
        cout << "          DASHBOARD PROGRAM SHOWROOM      \n";
        cout << "=========================================\n";
        cout << " 1. Menu Parent (Sales)\n";
        cout << " 2. Menu Child  (Mobil)\n";
        cout << "-----------------------------------------\n";
        cout << " 0. Keluar Program\n";
        cout << "=========================================\n";
        cout << " Pilih menu : ";



        if (!(cin >> option)) {
            cout << "\nInput harus berupa angka!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            option = -99;
            system("pause");
        } else {

            switch(option) {
                case 1:
                    menuParent(L);
                    break;
                case 2:
                    menuChild(L);
                    break;
                case 0:

                    break;
                default:

                    cout << "\nMenu tidak tersedia (Pilih 1, 2, atau 0).\n";
                    system("pause");
                    break;
            }
        }
    }
}




void menuParent(ListSales &L){
    int option = -99;
    infotypeSales data;
    addressSales P, Prec;

    while (option != 0) {
        system("cls");
        cout << "============================================\n";
        cout << "        MENU MANAJEMEN DATA SALES            \n";
        cout << "============================================\n";
        cout << " 1. Insert First Sales\n";
        cout << " 2. Insert Last Sales\n";
        cout << " 3. Insert After Sales\n";
        cout << "--------------------------------------------\n";
        cout << " 4. Delete First Sales\n";
        cout << " 5. Delete Last Sales\n";
        cout << " 6. Delete After Sales\n";
        cout << "--------------------------------------------\n";
        cout << " 7. View Sales\n";
        cout << " 8. Lihat Score Sales\n";
        cout << "--------------------------------------------\n";
        cout << " 0. Kembali ke Menu Admin\n";
        cout << "============================================\n";
        cout << " Pilih menu : ";

        if (!(cin >> option)) {
            cout << "\nInput harus berupa angka!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            option = -99;
            system("pause");
        }
        else {

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
                    system("cls");
                    viewSales(L);
                    system("pause");
                    break;

                case 8:
                    system("cls");
                    hitungScoreSales(L);
                    system("pause");
                    break;

                case 0:
                    break;

                default:
                    cout << "\nMenu tidak tersedia (Pilih 0-8).\n";
                    system("pause");
                    break;
            }
        }
    }
}

void menuChild(ListSales &L){
    int option = -99;
    string idSales, idMobil;
    addressSales S;
    addressMobil M, PrecM;
    infotypeMobil data;

    while (option != 0) {
        system("cls");
        cout << "============================================\n";
        cout << "        MENU MANAJEMEN DATA MOBIL            \n";
        cout << "============================================\n";
        cout << " 1. Insert First Mobil\n";
        cout << " 2. Insert Last Mobil\n";
        cout << " 3. Insert After Mobil\n";
        cout << "--------------------------------------------\n";
        cout << " 4. Delete First Mobil\n";
        cout << " 5. Delete Last Mobil\n";
        cout << " 6. Delete After Mobil\n";
        cout << "--------------------------------------------\n";
        cout << " 7. View Mobil per Sales\n";
        cout << "--------------------------------------------\n";
        cout << " 0. Kembali ke Menu Admin\n";
        cout << "============================================\n";
        cout << " Pilih menu : ";


        if (!(cin >> option)) {
            cout << "\nInput harus berupa angka!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            option = -99;
            system("pause");
        } else {

            switch(option){
                case 1:
                    cout << "ID Sales: "; cin >> idSales;
                    S = findElemenSales(L, idSales);
                    if (S != NULL) {
                        cout << "ID Mobil: "; cin >> data.idMobil;
                        cout << "Merk     : "; cin >> data.merk;
                        cout << "Tipe     : "; cin >> data.tipe;
                        cout << "Tahun    : "; cin >> data.tahun;
                        cout << "Harga    : "; cin >> data.harga;
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
                        cout << "Merk     : "; cin >> data.merk;
                        cout << "Tipe     : "; cin >> data.tipe;
                        cout << "Tahun    : "; cin >> data.tahun;
                        cout << "Harga    : "; cin >> data.harga;
                        cout << "Terjual : "; cin >> data.jumlahTerjual;
                        M = createElmMobil(data);
                        insertLastMobil(S, M);
                    } else {
                        cout << "Sales tidak ditemukan.\n";
                        system("pause");
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
                            cout << "Merk     : "; cin >> data.merk;
                            cout << "Tipe     : "; cin >> data.tipe;
                            cout << "Tahun    : "; cin >> data.tahun;
                            cout << "Harga    : "; cin >> data.harga;
                            cout << "Terjual : "; cin >> data.jumlahTerjual;
                            M = createElmMobil(data);
                            insertAfterMobil(S, PrecM, M);
                        } else {
                            cout << "ID Mobil acuan (Prec) tidak ditemukan.\n";
                            system("pause");
                        }
                    } else {
                        cout << "Sales tidak ditemukan.\n";
                        system("pause");
                    }
                    break;

                case 4:
                    cout << "ID Sales: "; cin >> idSales;
                    S = findElemenSales(L, idSales);
                    if (S != NULL) {
                        deleteFirstMobil(S, M);
                        cout << "Mobil pertama berhasil dihapus (jika ada).\n";
                        system("pause");
                    } else {
                        cout << "Sales tidak ditemukan.\n";
                        system("pause");
                    }
                    break;

                case 5:
                    cout << "ID Sales: "; cin >> idSales;
                    S = findElemenSales(L, idSales);
                    if (S != NULL) {
                        deleteLastMobil(S, M);
                        cout << "Mobil terakhir berhasil dihapus (jika ada).\n";
                        system("pause");
                    } else {
                        cout << "Sales tidak ditemukan.\n";
                        system("pause");
                    }
                    break;

                case 6:
                    cout << "ID Sales: "; cin >> idSales;
                    S = findElemenSales(L, idSales);
                    if (S != NULL) {
                        cout << "Delete after ID Mobil: ";
                        cin >> idMobil;
                        PrecM = findMobilPadaSales(S, idMobil);
                        if (PrecM != NULL) {
                            deleteAfterMobil(S, PrecM, M);
                            cout << "Mobil setelah ID " << idMobil << " berhasil dihapus.\n";
                            system("pause");
                        } else {
                            cout << "Mobil acuan tidak ditemukan.\n";
                            system("pause");
                        }
                    } else {
                        cout << "Sales tidak ditemukan.\n";
                        system("pause");
                    }
                    break;

                case 7:
                    cout << "ID Sales: ";
                    cin >> idSales;
                    system("cls");

                    S = findElemenSales(L, idSales);
                    if (S != NULL) {
                        viewMobilSales(S);
                    } else {
                        cout << "Sales tidak ditemukan.\n";
                    }

                    cout << endl;
                    system("pause");
                    break;

                case 0:
                    break;

                default:
                    cout << "\nMenu tidak tersedia (Pilih 0-7).\n";
                    system("pause");
                    break;
            }
        }
    }
}
