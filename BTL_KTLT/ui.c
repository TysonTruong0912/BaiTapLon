#include "ui.h"

/* ===== HAM NHAP SO NGUYEN CO KIEM TRA LOI ===== */

int nhapSoNguyen(void) {
    int  giatri;
    int  kiemTra;
    char kyTu;

    while (1) {
        kiemTra = scanf("%d", &giatri);
        if (kiemTra == 1) {
            kyTu = getchar();
            if (kyTu == '\n') {
                return giatri;          /* Hop le */
            } else {
                /* Co ky tu la sau so -> loai bo phan con lai */
                while (kyTu != '\n' && kyTu != EOF)
                    kyTu = getchar();
                SET_COLOR(COLOR_RED);
                printf("  [LOI] chi nhan gia tri so, vui long nhap lai: ");
                SET_COLOR(COLOR_YELLOW);
            }
        } else {
            /* scanf that bai (nhap chu, ky tu dac biet...) */
            while ((kyTu = getchar()) != '\n' && kyTu != EOF);
            SET_COLOR(COLOR_RED);
            printf("  [LOI] can phai nhap gia tri la so nguyen, vui long nhap lai: ");
            SET_COLOR(COLOR_YELLOW);
        }
    }
}

/* ===== HAM VE GIAO DIEN ===== */

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

void inTieuDeApp(void) {
    int i;
    CLEAR_SCREEN();
    SET_COLOR(COLOR_CYAN);
    printf("\n  +");
    for (i = 0; i < 56; i++) printf("=");
    printf("+\n");

    printf("  |");
    SET_COLOR(COLOR_YELLOW);
    printf("            HE THONG QUAN LY THU VIEN             ");
    SET_COLOR(COLOR_CYAN);
    printf("      |\n");

    printf("  |");
    SET_COLOR(COLOR_GRAY);
    printf("               Sinh Vien Quan Ly Sach               ");
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

void nhanPhimTiepTuc(void) {
    SET_COLOR(COLOR_GRAY);
    printf("\n  Nhan Enter de tiep tuc...");
    SET_COLOR(COLOR_WHITE);
    getchar();
}

/* ===== DASHBOARD ===== */

void hienThiDashboard(ListReader lr, ListBorrow lb) {
    int i;
    int tongDauSach = h;
    int dangMuon    = 0;
    int soSinhVien  = 0;
    int soPhieuMuon = 0;
    int conNhieu    = 0;
    int sapHet      = 0;
    int daHet       = 0;
    int quaHan      = 0;

    NodeReader *pr;
    NodeBorrow *pb;
    time_t      now;
    struct tm  *tinfo;
    char        ngayHom[30];

    /* --- Thong ke trang thai sach --- */
    for (i = 0; i < h; i++) {
        if      (ds[i].soLuong == 0) daHet++;
        else if (ds[i].soLuong <= 2) sapHet++;
        else                         conNhieu++;
    }

    /* --- Thong ke sinh vien --- */
    for (pr = lr.head; pr != NULL; pr = pr->next) soSinhVien++;

    /* --- Thong ke phieu muon & qua han --- */
    for (pb = lb.head; pb != NULL; pb = pb->next) {
        soPhieuMuon++;
        dangMuon++;
        if (strlen(pb->data.ngayTra) == 0              ||
            strcmp(pb->data.ngayTra, "chua tra") == 0  ||
            strcmp(pb->data.ngayTra, "Chua tra") == 0)
        {
            quaHan++;
        }
    }

    /* --- Lay ngay hom nay --- */
    time(&now);
    tinfo = localtime(&now);
    strftime(ngayHom, sizeof(ngayHom), "%d/%m/%Y", tinfo);

    /* ========== Ve khung Dashboard ========== */
    CLEAR_SCREEN();
    SET_COLOR(COLOR_CYAN);
    printf("\n  +");
    for (i = 0; i < 56; i++) printf("=");
    printf("+\n");

    printf("  |");
    SET_COLOR(COLOR_YELLOW);
    printf("              HE THONG QUAN LY THU VIEN           ");
    SET_COLOR(COLOR_CYAN);
    printf("      |\n");

    printf("  |");
    SET_COLOR(COLOR_GRAY);
    printf("               Sinh Vien Quan Ly Sach               ");
    SET_COLOR(COLOR_CYAN);
    printf("    |\n");

    printf("  +");
    for (i = 0; i < 56; i++) printf("=");
    printf("+\n");

    printf("  ||");
    SET_COLOR(COLOR_YELLOW);
    printf("              DASHBOARD TONG QUAN                 ");
    SET_COLOR(COLOR_CYAN);
    printf("    ||\n");

    printf("  +");
    for (i = 0; i < 56; i++) printf("-");
    printf("+\n");

    /* Dong 1: Tong so sach | Con nhieu */
    printf("  ||  ");
    SET_COLOR(COLOR_GREEN);  printf("[]");
    SET_COLOR(COLOR_WHITE);  printf(" Tong so sach : ");
    SET_COLOR(COLOR_YELLOW); printf("%-4d", tongDauSach);
    SET_COLOR(COLOR_WHITE);  printf("  ");
    SET_COLOR(COLOR_GREEN);  printf(" []");
    SET_COLOR(COLOR_WHITE);  printf(" Con nhieu  : ");
    SET_COLOR(COLOR_GREEN);  printf("%-3d", conNhieu);
    SET_COLOR(COLOR_CYAN);   printf("        ||\n");

    /* Dong 2: Dang duoc muon | Sap het */
    printf("  ||  ");
    SET_COLOR(COLOR_BLUE);   printf("[]");
    SET_COLOR(COLOR_WHITE);  printf(" Dang duoc muon: ");
    SET_COLOR(COLOR_YELLOW); printf("%-4d", dangMuon);
    SET_COLOR(COLOR_WHITE);  printf("  ");
    SET_COLOR(COLOR_YELLOW); printf("[]");
    SET_COLOR(COLOR_WHITE);  printf(" Sap het    : ");
    SET_COLOR(COLOR_YELLOW); printf("%-3d", sapHet);
    SET_COLOR(COLOR_CYAN);   printf("        ||\n");

    /* Dong 3: Sinh vien | Da het */
    printf("  ||  ");
    SET_COLOR(COLOR_MAGENTA); printf("[]");
    SET_COLOR(COLOR_WHITE);   printf(" Sinh vien     : ");
    SET_COLOR(COLOR_YELLOW);  printf("%-4d", soSinhVien);
    SET_COLOR(COLOR_WHITE);   printf("  ");
    SET_COLOR(COLOR_RED);     printf("[]");
    SET_COLOR(COLOR_WHITE);   printf(" Da het     : ");
    SET_COLOR(COLOR_RED);     printf("%-3d", daHet);
    SET_COLOR(COLOR_CYAN);    printf("        ||\n");

    /* Dong 4: Phieu muon | Qua han */
    printf("  ||  ");
    SET_COLOR(COLOR_BLUE);   printf("[]");
    SET_COLOR(COLOR_WHITE);  printf(" Phieu muon    : ");
    SET_COLOR(COLOR_YELLOW); printf("%-4d", soPhieuMuon);
    SET_COLOR(COLOR_WHITE);  printf("  ");
    SET_COLOR(COLOR_YELLOW); printf("[]");
    SET_COLOR(COLOR_WHITE);  printf(" Qua han    : ");
    SET_COLOR(COLOR_RED);    printf("%-3d", quaHan);
    SET_COLOR(COLOR_CYAN);   printf("        ||\n");

    /* Duong phan cach */
    printf("  +");
    for (i = 0; i < 56; i++) printf("-");
    printf("+\n");

    /* Dong ngay */
    printf("  ||  ");
    SET_COLOR(COLOR_GRAY);  printf("(O) Hom nay: ");
    SET_COLOR(COLOR_WHITE); printf("%-37s", ngayHom);
    SET_COLOR(COLOR_CYAN);  printf("  ||\n");

    printf("  +");
    for (i = 0; i < 56; i++) printf("=");
    printf("+\n");
    SET_COLOR(COLOR_WHITE);

    printf("\n");
    SET_COLOR(COLOR_GRAY);
    printf("  [Nhan Enter de vao menu chinh...]\n");
    SET_COLOR(COLOR_WHITE);
    getchar();
}
