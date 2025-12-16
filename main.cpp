#include "header.h"

using namespace std;

/* ============================================================
   VARIABEL GLOBAL
   ============================================================ */
ListSales L;

/* ============================================================
   MAIN PROGRAM
   ============================================================ */
int main() {
    createListSales(L);

    addressSales S;
    addressMobil M;

    // =========================
    // SALES 1
    // =========================
    infotypeSales s1 = {"S001", "Andi Wijaya", "081234567890"};
    S = createElmSales(s1);
    insertLastSales(L, S);

    M = createElmMobil({"Toyota", "Avanza", "2022", "M001", 280000000, 5});
    insertLastMobil(S, M);
    M = createElmMobil({"Honda", "Brio", "2021", "M002", 170000000, 7});
    insertLastMobil(S, M);
    M = createElmMobil({"Daihatsu", "Xenia", "2023", "M003", 300000000, 4});
    insertLastMobil(S, M);

    // =========================
    // SALES 2
    // =========================
    infotypeSales s2 = {"S002", "Budi Santoso", "082345678901"};
    S = createElmSales(s2);
    insertLastSales(L, S);

    M = createElmMobil({"Toyota", "Fortuner", "2020", "M004", 520000000, 3});
    insertLastMobil(S, M);
    M = createElmMobil({"Mitsubishi", "Pajero", "2021", "M005", 550000000, 2});
    insertLastMobil(S, M);

    // =========================
    // SALES 3
    // =========================
    infotypeSales s3 = {"S003", "Citra Lestari", "083456789012"};
    S = createElmSales(s3);
    insertLastSales(L, S);

    M = createElmMobil({"Honda", "HRV", "2022", "M006", 375000000, 6});
    insertLastMobil(S, M);
    M = createElmMobil({"Wuling", "Alvez", "2023", "M007", 300000000, 5});
    insertLastMobil(S, M);
    M = createElmMobil({"Suzuki", "XL7", "2021", "M008", 290000000, 4});
    insertLastMobil(S, M);

    // =========================
    // SALES 4
    // =========================
    infotypeSales s4 = {"S004", "Dewi Anggraini", "084567890123"};
    S = createElmSales(s4);
    insertLastSales(L, S);

    M = createElmMobil({"Hyundai", "Creta", "2022", "M009", 410000000, 3});
    insertLastMobil(S, M);
    M = createElmMobil({"Toyota", "Rush", "2020", "M010", 320000000, 2});
    insertLastMobil(S, M);

    // =========================
    // MENU
    // =========================
    menuAdmin(L);

    cout << "\nProgram selesai.\n";
    return 0;
}
