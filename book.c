#include "sach.h"

/* ===== BIEN TOAN CUC ===== */

Sach ds[100];
int  h = 0;

/* ===== HAM GIAO DIEN ===== */

void inDuongNgang(int n) {
    int i;
    SET_COLOR(COLOR_GRAY);
    for (i = 0; i < n; i++) printf("-");
    printf("\n");
    SET_COLOR(COLOR_WHITE);
}

void inDuongDon(int n) {
    int i;
    SET_COLOR(COLOR_GRAY);
    for (i = 0; i < n; i++) printf("=");
    printf("\n");
    SET_COLOR(COLOR_WHITE);
}

void inTieuDe(const char *tieuDe) {
    int len   = (int)strlen(tieuDe);
    int total = 56;
    int pad   = (total - len - 2) / 2;
    int i;

    printf("\n");
    SET_COLOR(COLOR_CYAN);
    printf("  +");
    for (i = 0; i < total; i++) printf("-");
    printf("+\n");

    printf("  |");
    for (i = 0; i < pad; i++) printf(" ");
    SET_COLOR(COLOR_YELLOW);
    printf("%s", tieuDe);
    SET_COLOR(COLOR_CYAN);
    for (i = 0; i < total - pad - len; i++) printf(" ");
    printf("|\n");

    printf("  +");
    for (i = 0; i < total; i++) printf("-");
    printf("+\n");
    SET_COLOR(COLOR_WHITE);
}

void inTieuDeApp() {
    int i;
    CLEAR_SCREEN();
    SET_COLOR(COLOR_CYAN);
    printf("\n  +");
    for (i = 0; i < 56; i++) printf("=");
    printf("+\n");

    printf("  |");
    SET_COLOR(COLOR_YELLOW);
    printf("          HE THONG QUAN LY THU VIEN              ");
    SET_COLOR(COLOR_CYAN);
    printf("      |\n");

    printf("  |");
    SET_COLOR(COLOR_GRAY);
    printf("               Sinh Vien Quan Ly Sach              ");
    SET_COLOR(COLOR_CYAN);
    printf("    |\n");

    printf("  +");
    for (i = 0; i < 56; i++) printf("=");
    printf("+\n");
    SET_COLOR(COLOR_WHITE);
}

void inThongBao(const char *msg, int loai) {
    printf("\n  ");
    if (loai == 1) {
        SET_COLOR(COLOR_GREEN);
        printf("[OK] ");
    } else if (loai == 0) {
        SET_COLOR(COLOR_RED);
        printf("[LOI] ");
    } else {
        SET_COLOR(COLOR_YELLOW);
        printf("[!] ");
    }
    SET_COLOR(COLOR_WHITE);
    printf("%s\n", msg);
}

void nhanPhimTiepTuc() {
    SET_COLOR(COLOR_GRAY);
    printf("\n  Nhan Enter de tiep tuc...");
    SET_COLOR(COLOR_WHITE);
    getchar();
}

/* ===== HAM SACH ===== */

void themSach(int n) {
    int i;
    inTieuDe("THEM SACH MOI");

    for (i = 0; i < n; i++) {
        printf("\n");
        SET_COLOR(COLOR_CYAN);
        printf("  --- Sach thu %d/%d ---\n", i + 1, n);
        SET_COLOR(COLOR_WHITE);

        printf("  Nhap ID       : ");
        SET_COLOR(COLOR_YELLOW);
        scanf("%d", &ds[h].id);
        SET_COLOR(COLOR_WHITE);
        getchar();

        printf("  Nhap ten sach : ");
        SET_COLOR(COLOR_YELLOW);
        fgets(ds[h].tensach, sizeof(ds[h].tensach), stdin);
        ds[h].tensach[strcspn(ds[h].tensach, "\n")] = 0;
        SET_COLOR(COLOR_WHITE);

        printf("  Nhap so luong : ");
        SET_COLOR(COLOR_YELLOW);
        scanf("%d", &ds[h].soLuong);
        SET_COLOR(COLOR_WHITE);
        getchar();

        h++;
    }
    inThongBao("Them sach thanh cong!", 1);
    nhanPhimTiepTuc();
}

void hienThiSach() {
    int i;
    inTieuDe("DANH SACH SACH");

    if (h == 0) {
        inThongBao("Danh sach trong!", 2);
        nhanPhimTiepTuc();
        return;
    }

    printf("\n");
    SET_COLOR(COLOR_CYAN);
    printf("  %-6s  %-35s  %-10s\n", "ID", "TEN SACH", "SO LUONG");
    inDuongNgang(58);
    SET_COLOR(COLOR_WHITE);

    for (i = 0; i < h; i++) {
        if (i % 2 == 0) SET_COLOR(COLOR_WHITE);
        else            SET_COLOR(COLOR_GRAY);

        printf("  %-6d  %-35s  ", ds[i].id, ds[i].tensach);

        if (ds[i].soLuong == 0)      SET_COLOR(COLOR_RED);
        else if (ds[i].soLuong <= 2) SET_COLOR(COLOR_YELLOW);
        else                         SET_COLOR(COLOR_GREEN);

        printf("%-10d\n", ds[i].soLuong);
        SET_COLOR(COLOR_WHITE);
    }

    inDuongNgang(58);
    SET_COLOR(COLOR_GRAY);
    printf("  Tong cong: %d sach\n", h);
    SET_COLOR(COLOR_WHITE);
    nhanPhimTiepTuc();
}

void timTheoID() {
    int id, tim, i;
    inTieuDe("TIM SACH THEO ID");

    printf("\n  Nhap ID can tim: ");
    SET_COLOR(COLOR_YELLOW);
    scanf("%d", &id);
    SET_COLOR(COLOR_WHITE);
    getchar();

    tim = 0;

    for (i = 0; i < h; i++) {
        if (ds[i].id == id) {
            printf("\n");
            SET_COLOR(COLOR_GREEN);
            printf("  +----------------------------------+\n");
            printf("  |        KET QUA TIM KIEM          |\n");
            printf("  +----------------------------------+\n");
            SET_COLOR(COLOR_WHITE);
            printf("  | ID       : ");
            SET_COLOR(COLOR_YELLOW);
            printf("%-22d|\n", ds[i].id);
            SET_COLOR(COLOR_WHITE);
            printf("  | Ten sach : ");
            SET_COLOR(COLOR_YELLOW);
            printf("%-22s|\n", ds[i].tensach);
            SET_COLOR(COLOR_WHITE);
            printf("  | So luong : ");
            if (ds[i].soLuong == 0) SET_COLOR(COLOR_RED);
            else                    SET_COLOR(COLOR_GREEN);
            printf("%-22d|\n", ds[i].soLuong);
            SET_COLOR(COLOR_WHITE);
            SET_COLOR(COLOR_GREEN);
            printf("  +----------------------------------+\n");
            SET_COLOR(COLOR_WHITE);
            tim = 1;
        }
    }

    if (!tim) {
        inThongBao("Khong tim thay sach voi ID nay!", 0);
    }

    nhanPhimTiepTuc();
}
