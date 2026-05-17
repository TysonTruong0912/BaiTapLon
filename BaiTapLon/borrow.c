#include "borrow.h"
#include "book.h"
#include "reader.h"
#include "ui.h"

/* ===== KHOI TAO ===== */

void initBorrowList(ListBorrow *l) {
    l->head = NULL;
}

/* ===== CAP PHAT NODE ===== */

NodeBorrow *createBorrow(Borrow b) {
    NodeBorrow *p = (NodeBorrow *)malloc(sizeof(NodeBorrow));
    if (!p) {
        inThongBao("Cap phat vung nho that bai!", 0);
        return NULL;
    }
    p->data = b;
    p->next = NULL;
    return p;
}

/* ===== CHEN VAO CUOI ===== */

void insertBorrow(ListBorrow *l, Borrow b) {
    NodeBorrow *p = createBorrow(b);
    NodeBorrow *temp;
    if (!p) return;
    if (!l->head) { l->head = p; return; }
    temp = l->head;
    while (temp->next) temp = temp->next;
    temp->next = p;
}

/* ===== HIEN THI DANH SACH PHIEU MUON ===== */

void showBorrowList(ListBorrow l) {
    NodeBorrow *i;
    int stt = 1;
    inTieuDe("DANH SACH MUON SACH");

    if (!l.head) {
        inThongBao("Chua co phieu muon nao!", 2);
        nhanPhimTiepTuc();
        return;
    }

    printf("\n");
    SET_COLOR(COLOR_CYAN);
    printf("  %-4s  %-8s  %-12s  %-12s  %-12s\n",
           "STT", "ID SACH", "MA SV", "NGAY MUON", "NGAY TRA");
    inDuongNgang(64);
    SET_COLOR(COLOR_WHITE);

    for (i = l.head; i != NULL; i = i->next, stt++) {
        if (stt % 2 == 0) SET_COLOR(COLOR_GRAY);
        else               SET_COLOR(COLOR_WHITE);
        printf("  %-4d  %-8s  %-12s  %-12s  %-12s\n",
               stt,
               i->data.idSach,
               i->data.idSinhVien,
               i->data.ngayMuon,
               i->data.ngayTra);
    }

    inDuongNgang(64);
    SET_COLOR(COLOR_WHITE);
    nhanPhimTiepTuc();
}

/* ===== MUON SACH ===== */

void muonSach(ListBorrow *lb) {
    Borrow b;
    int    idSach, found, i;

    inTieuDe("MUON SACH");

    printf("\n  Nhap ID sach      : ");
    SET_COLOR(COLOR_YELLOW);
    idSach = nhapSoNguyen();
    SET_COLOR(COLOR_WHITE);

    printf("  Nhap ID sinh vien : ");
    SET_COLOR(COLOR_YELLOW);
    fgets(b.idSinhVien, sizeof(b.idSinhVien), stdin);
    b.idSinhVien[strcspn(b.idSinhVien, "\n")] = 0;
    SET_COLOR(COLOR_WHITE);

    printf("  Nhap ngay muon    : ");
    SET_COLOR(COLOR_YELLOW);
    fgets(b.ngayMuon, sizeof(b.ngayMuon), stdin);
    b.ngayMuon[strcspn(b.ngayMuon, "\n")] = 0;
    SET_COLOR(COLOR_WHITE);

    printf("  Nhap ngay tra     : ");
    SET_COLOR(COLOR_YELLOW);
    fgets(b.ngayTra, sizeof(b.ngayTra), stdin);
    b.ngayTra[strcspn(b.ngayTra, "\n")] = 0;
    SET_COLOR(COLOR_WHITE);

    found = 0;
    for (i = 0; i < h; i++) {
        if (ds[i].id == idSach) {
            found = 1;
            if (ds[i].soLuong > 0) {
                ds[i].soLuong--;
                sprintf(b.idSach, "%d", idSach);
                insertBorrow(lb, b);

                printf("\n");
                SET_COLOR(COLOR_GREEN);
                printf("  +-------------------------------+\n");
                printf("  |    MUON SACH THANH CONG       |\n");
                printf("  +-------------------------------+\n");
                SET_COLOR(COLOR_WHITE);
                printf("  | Sach    : %-20s|\n", ds[i].tensach);
                printf("  | Con lai : ");
                SET_COLOR(COLOR_GREEN);
                printf("%-20d", ds[i].soLuong);
                SET_COLOR(COLOR_WHITE);
                printf("|\n");
                SET_COLOR(COLOR_GREEN);
                printf("  +-------------------------------+\n");
                SET_COLOR(COLOR_WHITE);
            } else {
                inThongBao("Sach da het! Khong the muon.", 0);
            }
            break;
        }
    }

    if (!found)
        inThongBao("Khong tim thay sach voi ID nay!", 0);

    nhanPhimTiepTuc();
}

/* ===== TRA SACH ===== */

void traSach(ListBorrow *lb) {
    char        idSinhVien[50];
    char        idSachStr[50];
    int         idSach;
    NodeBorrow *p, *truoc;
    int         found, i;

    inTieuDe("TRA SACH");

    printf("\n  Nhap ID sach can tra : ");
    SET_COLOR(COLOR_YELLOW);
    idSach = nhapSoNguyen();
    SET_COLOR(COLOR_WHITE);

    printf("  Nhap ID sinh vien    : ");
    SET_COLOR(COLOR_YELLOW);
    fgets(idSinhVien, sizeof(idSinhVien), stdin);
    idSinhVien[strcspn(idSinhVien, "\n")] = 0;
    SET_COLOR(COLOR_WHITE);

    sprintf(idSachStr, "%d", idSach);

    p     = lb->head;
    truoc = NULL;
    found = 0;
    i     = 0;

    while (p != NULL) {
        if (strcmp(p->data.idSach,     idSachStr)  == 0 &&
            strcmp(p->data.idSinhVien, idSinhVien) == 0)
        {
            found = 1;

            /* Tang so luong sach lai */
            for (i = 0; i < h; i++) {
                if (ds[i].id == idSach) { ds[i].soLuong++; break; }
            }

            /* Xoa phieu muon khoi danh sach */
            if (truoc == NULL) lb->head    = p->next;
            else               truoc->next = p->next;
            free(p);

            printf("\n");
            SET_COLOR(COLOR_GREEN);
            printf("  +-------------------------------+\n");
            printf("  |    TRA SACH THANH CONG        |\n");
            printf("  +-------------------------------+\n");
            SET_COLOR(COLOR_WHITE);
            printf("  | ID Sach : %-20s|\n", idSachStr);
            printf("  | Ma SV   : %-20s|\n", idSinhVien);
            if (i < h) {
                printf("  | Con lai : ");
                SET_COLOR(COLOR_GREEN);
                printf("%-20d", ds[i].soLuong);
                SET_COLOR(COLOR_WHITE);
                printf("|\n");
            }
            SET_COLOR(COLOR_GREEN);
            printf("  +-------------------------------+\n");
            SET_COLOR(COLOR_WHITE);
            break;
        }
        truoc = p;
        p     = p->next;
    }

    if (!found)
        inThongBao("Khong tim thay phieu muon phu hop!", 0);

    nhanPhimTiepTuc();
}

/* ===== TINH SO NGAY TRE HAN ===== */

long soNgayTre(const char *ngayTra) {
    struct tm tTra;
    time_t    tNow, tTra_t;
    double    diff;

    if (!parseDate(ngayTra, &tTra)) return -1;

    tTra_t = mktime(&tTra);
    time(&tNow);

    diff = difftime(tNow, tTra_t);
    if (diff <= 0) return 0;
    return (long)(diff / 86400.0);
}

/* ===== KIEM TRA QUA HAN ===== */

void kiemTraQuaHan(ListBorrow lb, ListReader lr) {
    NodeBorrow *p;
    int         stt      = 1;
    int         coQuaHan = 0;
    long        tongPhat = 0;
    int         i;

    inTieuDe("CANH BAO: PHIEU MUON QUA HAN");

    for (p = lb.head; p != NULL; p = p->next) {
        NodeReader *r;
        char        tenSV[100];
        long        ngayTre  = soNgayTre(p->data.ngayTra);
        long        tienPhat;

        if (ngayTre <= 0) continue;  /* Chua qua han hoac ngay khong hop le */

        /* In tieu de bang lan dau */
        if (!coQuaHan) {
            printf("\n");
            SET_COLOR(COLOR_CYAN);
            printf("  %-4s  %-8s  %-14s  %-12s  %-9s  %-12s\n",
                   "STT", "ID SACH", "MA SINH VIEN", "HAN TRA",
                   "TRE(ngay)", "TIEN PHAT");
            inDuongNgang(70);
            SET_COLOR(COLOR_WHITE);
            coQuaHan = 1;
        }

        tienPhat  = ngayTre * TIEN_PHAT_MOI_NGAY;
        tongPhat += tienPhat;

        if (ngayTre > 7) SET_COLOR(COLOR_RED);
        else             SET_COLOR(COLOR_YELLOW);

        /* Tim ten sinh vien */
        strcpy(tenSV, "???");
        for (r = lr.head; r != NULL; r = r->next) {
            if (strcmp(r->data.idSV, p->data.idSinhVien) == 0) {
                strncpy(tenSV, r->data.tenSV, sizeof(tenSV) - 1);
                break;
            }
        }

        printf("  %-4d  %-8s  %-14s  %-12s  ",
               stt++, p->data.idSach,
               p->data.idSinhVien, p->data.ngayTra);

        SET_COLOR(COLOR_RED);
        printf("%-11ld", ngayTre);
        SET_COLOR(COLOR_YELLOW);

        /* In tien phat co dau phan cach nghin */
        if (tienPhat >= 1000000L)
            printf("%ld.%03ld.%03ld VND\n",
                   tienPhat / 1000000,
                   (tienPhat % 1000000) / 1000,
                   tienPhat % 1000);
        else if (tienPhat >= 1000L)
            printf("%ld.%03ld VND\n",
                   tienPhat / 1000, tienPhat % 1000);
        else
            printf("%ld VND\n", tienPhat);

        SET_COLOR(COLOR_WHITE);

        /* In ten sinh vien o dong tiep theo */
        SET_COLOR(COLOR_GRAY);
        printf("        ");
        for (i = 0; i < 8; i++) printf(" ");
        printf("Ten SV: %s\n", tenSV);
        SET_COLOR(COLOR_WHITE);
    }

    if (!coQuaHan) {
        inThongBao("Khong co phieu muon nao qua han!", 1);
        nhanPhimTiepTuc();
        return;
    }

    inDuongNgang(70);

    SET_COLOR(COLOR_CYAN);
    printf("  Tong so phieu qua han : ");
    SET_COLOR(COLOR_RED);
    printf("%d phieu\n", stt - 1);

    SET_COLOR(COLOR_CYAN);
    printf("  Tong tien phat du kien: ");
    SET_COLOR(COLOR_YELLOW);
    if (tongPhat >= 1000000L)
        printf("%ld.%03ld.%03ld VND\n",
               tongPhat / 1000000,
               (tongPhat % 1000000) / 1000,
               tongPhat % 1000);
    else
        printf("%ld.%03ld VND\n", tongPhat / 1000, tongPhat % 1000);

    SET_COLOR(COLOR_GRAY);
    printf("  (Muc phat: %ld VND/ngay)\n", TIEN_PHAT_MOI_NGAY);
    SET_COLOR(COLOR_WHITE);

    nhanPhimTiepTuc();
}

/* ===== TINH TIEN PHAT CHO 1 SINH VIEN ===== */

void tinhTienPhatSV(ListBorrow lb) {
    char        idSV[50];
    NodeBorrow *p;
    int         coPhieu  = 0;
    long        tongPhat = 0;

    inTieuDe("TINH TIEN PHAT SINH VIEN");

    printf("\n  Nhap Ma SV: ");
    SET_COLOR(COLOR_YELLOW);
    fgets(idSV, sizeof(idSV), stdin);
    idSV[strcspn(idSV, "\n")] = 0;
    SET_COLOR(COLOR_WHITE);

    printf("\n");
    SET_COLOR(COLOR_CYAN);
    printf("  %-8s  %-12s  %-10s  %-12s\n",
           "ID SACH", "HAN TRA", "TRE(ngay)", "TIEN PHAT");
    inDuongNgang(50);
    SET_COLOR(COLOR_WHITE);

    for (p = lb.head; p != NULL; p = p->next) {
        long ngayTre;
        long phat;

        if (strcmp(p->data.idSinhVien, idSV) != 0) continue;

        coPhieu = 1;
        ngayTre = soNgayTre(p->data.ngayTra);

        printf("  %-8s  %-12s  ", p->data.idSach, p->data.ngayTra);

        if (ngayTre < 0) {
            SET_COLOR(COLOR_GRAY);
            printf("%-10s  %-12s\n", "N/A", "N/A");
        } else if (ngayTre == 0) {
            SET_COLOR(COLOR_GREEN);
            printf("%-10s  %-12s\n", "Chua tre", "0 VND");
        } else {
            phat      = ngayTre * TIEN_PHAT_MOI_NGAY;
            tongPhat += phat;
            SET_COLOR(COLOR_RED);
            printf("%-10ld  ", ngayTre);
            SET_COLOR(COLOR_YELLOW);
            if (phat >= 1000L)
                printf("%ld.%03ld VND\n", phat / 1000, phat % 1000);
            else
                printf("%ld VND\n", phat);
        }
        SET_COLOR(COLOR_WHITE);
    }

    if (!coPhieu) {
        inThongBao("Khong tim thay phieu muon cua sinh vien nay!", 0);
        nhanPhimTiepTuc();
        return;
    }

    inDuongNgang(50);
    SET_COLOR(COLOR_CYAN);
    printf("  Tong tien phat phai nop: ");
    SET_COLOR(COLOR_YELLOW);
    if (tongPhat == 0) {
        SET_COLOR(COLOR_GREEN);
        printf("0 VND (Khong co phieu nao qua han)\n");
    } else if (tongPhat >= 1000L) {
        printf("%ld.%03ld VND\n", tongPhat / 1000, tongPhat % 1000);
    } else {
        printf("%ld VND\n", tongPhat);
    }
    SET_COLOR(COLOR_WHITE);

    nhanPhimTiepTuc();
}

/* ===== GHI FILE ===== */

void writeToFile(ListReader l, ListBorrow lb, char filename[]) {
    NodeReader *p;
    NodeBorrow *q;
    FILE       *f = fopen(filename, "w");

    if (f == NULL) {
        inThongBao("Khong mo duoc file de ghi!", 0);
        return;
    }

    fprintf(f, "[READER]\n");
    for (p = l.head; p != NULL; p = p->next)
        fprintf(f, "%s|%s\n", p->data.idSV, p->data.tenSV);

    fprintf(f, "[BORROW]\n");
    for (q = lb.head; q != NULL; q = q->next)
        fprintf(f, "%s|%s|%s|%s\n",
                q->data.idSach, q->data.idSinhVien,
                q->data.ngayMuon, q->data.ngayTra);

    fclose(f);
    inThongBao("Da luu du lieu vao file thanh cong!", 1);
}

/* ===== DOC FILE ===== */

void readFile(ListReader *l, ListBorrow *lb, char filename[]) {
    char line[200];
    int  section = 0;
    FILE *f      = fopen(filename, "r");

    if (f == NULL) {
        inThongBao("File chua ton tai, se tao moi khi luu.", 2);
        return;
    }

    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "[READER]") == 0) { section = 1; continue; }
        if (strcmp(line, "[BORROW]") == 0) { section = 2; continue; }
        if (line[0] == '\0') continue;

        if (section == 1) {
            Reader r;
            if (sscanf(line, "%49[^|]|%99[^\n]", r.idSV, r.tenSV) == 2)
                insertReader(l, r);
        } else if (section == 2) {
            Borrow b;
            if (sscanf(line, "%49[^|]|%49[^|]|%49[^|]|%49[^\n]",
                       b.idSach, b.idSinhVien, b.ngayMuon, b.ngayTra) == 4)
                insertBorrow(lb, b);
        }
    }

    fclose(f);
    inThongBao("Da tai du lieu tu file thanh cong!", 1);
}

/* ===== GIAO DIEN LUU / TAI FILE ===== */

void luuVaDoc(ListReader *l, ListBorrow *lb) {
    int chon;
    inTieuDe("LUU / TAI FILE SINH VIEN");

    printf("\n");
    SET_COLOR(COLOR_CYAN);
    printf("  [1] Luu danh sach ra file\n");
    printf("  [2] Tai danh sach tu file\n");
    printf("  [0] Quay lai\n");
    SET_COLOR(COLOR_WHITE);

    printf("\n  Chon: ");
    SET_COLOR(COLOR_YELLOW);
    chon = nhapSoNguyen();
    SET_COLOR(COLOR_WHITE);

    if      (chon == 1) writeToFile(*l, *lb, "sinhvien.txt");
    else if (chon == 2) readFile(l, lb, "sinhvien.txt");

    nhanPhimTiepTuc();
}
