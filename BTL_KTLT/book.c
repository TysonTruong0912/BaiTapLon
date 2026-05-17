#include "book.h"
#include "ui.h"

/* ===== BIEN TOAN CUC ===== */
/* Khai bao chinh tai day, cac file khac dung qua extern trong common.h */
Sach ds[MAX_SACH];
int  h = 0;

/* ===== PHAN TICH NGAY ===== */

int parseDate(const char *s, struct tm *out) {
    memset(out, 0, sizeof(struct tm));
    if (!s || s[0] == '\0') return 0;
    if (sscanf(s, "%d/%d/%d",
               &out->tm_mday, &out->tm_mon, &out->tm_year) != 3)
        return 0;
    out->tm_mon  -= 1;     /* struct tm: thang 0-11 */
    out->tm_year -= 1900;  /* struct tm: nam tinh tu 1900 */
    out->tm_hour  = 12;    /* Tranh loi do doi gio mua he */
    mktime(out);
    return 1;
}

/* ===== THEM SACH ===== */

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
        ds[h].id = nhapSoNguyen();
        SET_COLOR(COLOR_WHITE);

        printf("  Nhap ten sach : ");
        SET_COLOR(COLOR_YELLOW);
        fgets(ds[h].tensach, sizeof(ds[h].tensach), stdin);
        ds[h].tensach[strcspn(ds[h].tensach, "\n")] = 0;
        SET_COLOR(COLOR_WHITE);
        getchar();

        printf("  Nhap so luong : ");
        SET_COLOR(COLOR_YELLOW);
        ds[h].soLuong = nhapSoNguyen();
        SET_COLOR(COLOR_WHITE);

        h++;
    }
    inThongBao("Them sach thanh cong!", 1);
    nhanPhimTiepTuc();
}

/* ===== HIEN THI DANH SACH SACH ===== */

void hienThiSach(void) {
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
        else             SET_COLOR(COLOR_GRAY);

        printf("  %-6d  %-35s  ", ds[i].id, ds[i].tensach);

        if      (ds[i].soLuong == 0) SET_COLOR(COLOR_RED);
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

/* ===== TIM SACH THEO ID ===== */

void timTheoID(void) {
    int id, tim, i;
    inTieuDe("TIM SACH THEO ID");

    printf("\n  Nhap ID can tim: ");
    SET_COLOR(COLOR_YELLOW);
    id = nhapSoNguyen();
    SET_COLOR(COLOR_WHITE);

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
            SET_COLOR(COLOR_YELLOW); printf("%-22d|\n", ds[i].id);
            SET_COLOR(COLOR_WHITE);
            printf("  | Ten sach : ");
            SET_COLOR(COLOR_YELLOW); printf("%-22s|\n", ds[i].tensach);
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

    if (!tim)
        inThongBao("Khong tim thay sach voi ID nay!", 0);

    nhanPhimTiepTuc();
}
