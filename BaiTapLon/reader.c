#include "reader.h"
#include "ui.h"
#include "book.h"
#include "borrow.h"  /* Can soNgayTre() khi tra cuu */

/* ===== KHOI TAO ===== */

void initReaderList(ListReader *l) {
    l->head = NULL;
}

/* ===== CAP PHAT NODE ===== */

NodeReader *createReader(Reader r) {
    NodeReader *p = (NodeReader *)malloc(sizeof(NodeReader));
    if (!p) {
        inThongBao("Cap phat vung nho that bai!", 0);
        return NULL;
    }
    p->data = r;
    p->next = NULL;
    return p;
}

/* ===== CHEN VAO CUOI ===== */

void insertReader(ListReader *l, Reader r) {
    NodeReader *p = createReader(r);
    NodeReader *temp;
    if (!p) return;
    if (!l->head) { l->head = p; return; }
    temp = l->head;
    while (temp->next) temp = temp->next;
    temp->next = p;
}

/* ===== TIM THEO MSSV ===== */

NodeReader *findReader(ListReader l, char id[]) {
    NodeReader *p = l.head;
    while (p != NULL) {
        if (strcmp(p->data.idSV, id) == 0) return p;
        p = p->next;
    }
    return NULL;
}

/* ===== GIAO DIEN TIM SINH VIEN ===== */

void timReader(ListReader l) {
    char id[50];
    NodeReader *p;
    inTieuDe("TIM SINH VIEN THEO MA SV");

    printf("\n  Nhap Ma SV can tim: ");
    SET_COLOR(COLOR_YELLOW);
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;
    SET_COLOR(COLOR_WHITE);

    p = findReader(l, id);
    if (p != NULL) {
        printf("\n");
        SET_COLOR(COLOR_GREEN);
        printf("  +----------------------------------+\n");
        printf("  |        KET QUA TIM KIEM          |\n");
        printf("  +----------------------------------+\n");
        SET_COLOR(COLOR_WHITE);
        printf("  | Ma SV  : ");
        SET_COLOR(COLOR_YELLOW); printf("%-24s|\n", p->data.idSV);
        SET_COLOR(COLOR_WHITE);
        printf("  | Ho ten : ");
        SET_COLOR(COLOR_YELLOW); printf("%-24s|\n", p->data.tenSV);
        SET_COLOR(COLOR_WHITE);
        SET_COLOR(COLOR_GREEN);
        printf("  +----------------------------------+\n");
        SET_COLOR(COLOR_WHITE);
    } else {
        inThongBao("Khong tim thay sinh vien voi Ma SV nay!", 0);
    }

    nhanPhimTiepTuc();
}

/* ===== XOA THEO MSSV (NOI BO) ===== */

void deleteReader(ListReader *l, char id[]) {
    NodeReader *p    = l->head;
    NodeReader *truoc = NULL;

    /* Truong hop xoa node dau */
    if (p != NULL && strcmp(p->data.idSV, id) == 0) {
        l->head = p->next;
        free(p);
        inThongBao("Xoa sinh vien thanh cong!", 1);
        return;
    }

    /* Tim node can xoa */
    while (p != NULL && strcmp(p->data.idSV, id) != 0) {
        truoc = p;
        p     = p->next;
    }

    if (p == NULL) {
        inThongBao("Khong tim thay sinh vien voi Ma SV nay!", 0);
        return;
    }

    truoc->next = p->next;
    free(p);
    inThongBao("Xoa sinh vien thanh cong!", 1);
}

/* ===== GIAO DIEN XOA SINH VIEN ===== */

void xoaReader(ListReader *l) {
    char id[50];
    inTieuDe("XOA SINH VIEN");

    printf("\n  Nhap Ma SV can xoa: ");
    SET_COLOR(COLOR_YELLOW);
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;
    SET_COLOR(COLOR_WHITE);

    deleteReader(l, id);
    nhanPhimTiepTuc();
}

/* ===== GIAO DIEN THEM SINH VIEN ===== */

void themReader(ListReader *l) {
    char tiepTuc;
    inTieuDe("THEM SINH VIEN (READER)");

    do {
        Reader r;

        printf("\n  Nhap ID sinh vien : ");
        SET_COLOR(COLOR_YELLOW);
        fgets(r.idSV, sizeof(r.idSV), stdin);
        r.idSV[strcspn(r.idSV, "\n")] = 0;
        SET_COLOR(COLOR_WHITE);

        printf("  Nhap ten sinh vien: ");
        SET_COLOR(COLOR_YELLOW);
        fgets(r.tenSV, sizeof(r.tenSV), stdin);
        r.tenSV[strcspn(r.tenSV, "\n")] = 0;
        SET_COLOR(COLOR_WHITE);

        insertReader(l, r);
        inThongBao("Them sinh vien thanh cong!", 1);

        printf("  Tiep tuc them? (y/n): ");
        SET_COLOR(COLOR_YELLOW);
        scanf("%c", &tiepTuc);
        SET_COLOR(COLOR_WHITE);
        getchar();

    } while (tiepTuc == 'y' || tiepTuc == 'Y');

    nhanPhimTiepTuc();
}

/* ===== HIEN THI DANH SACH SINH VIEN ===== */

void showReaderList(ListReader l) {
    NodeReader *i;
    int stt = 1;
    inTieuDe("DANH SACH SINH VIEN");

    if (!l.head) {
        inThongBao("Chua co sinh vien nao!", 2);
        nhanPhimTiepTuc();
        return;
    }

    printf("\n");
    SET_COLOR(COLOR_CYAN);
    printf("  %-5s  %-15s  %-30s\n", "STT", "MA SV", "HO TEN");
    inDuongNgang(58);
    SET_COLOR(COLOR_WHITE);

    for (i = l.head; i != NULL; i = i->next, stt++) {
        if (stt % 2 == 0) SET_COLOR(COLOR_GRAY);
        else               SET_COLOR(COLOR_WHITE);
        printf("  %-5d  %-15s  %-30s\n", stt, i->data.idSV, i->data.tenSV);
    }

    inDuongNgang(58);
    SET_COLOR(COLOR_WHITE);
    nhanPhimTiepTuc();
}

/* ===== DEM SO SINH VIEN ===== */

int demReader(ListReader l) {
    int         soLuong = 0;
    NodeReader *p       = l.head;
    while (p != NULL) { soLuong++; p = p->next; }
    return soLuong;
}

/* ===== SUA THONG TIN SINH VIEN ===== */

void suaReader(ListReader *l) {
    char id[50];
    NodeReader *p;
    inTieuDe("SUA THONG TIN SINH VIEN");

    printf("\n  Nhap MSSV can sua : ");
    SET_COLOR(COLOR_YELLOW);
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;
    SET_COLOR(COLOR_WHITE);

    p = findReader(*l, id);
    if (p == NULL) {
        inThongBao("Khong tim thay sinh vien nay!", 0);
        nhanPhimTiepTuc();
        return;
    }

    /* Hien thi thong tin hien tai */
    printf("\n");
    SET_COLOR(COLOR_CYAN);
    printf("  +----------------------------------+\n");
    printf("  |       THONG TIN HIEN TAI         |\n");
    printf("  +----------------------------------+\n");
    SET_COLOR(COLOR_WHITE);
    printf("  | Ma SV  : ");
    SET_COLOR(COLOR_YELLOW); printf("%-24s|\n", p->data.idSV);
    SET_COLOR(COLOR_WHITE);
    printf("  | Ho ten : ");
    SET_COLOR(COLOR_YELLOW); printf("%-24s|\n", p->data.tenSV);
    SET_COLOR(COLOR_WHITE);
    SET_COLOR(COLOR_CYAN);
    printf("  +----------------------------------+\n");
    SET_COLOR(COLOR_WHITE);

    /* Cap nhat ten moi */
    printf("\n  Nhap ten moi : ");
    SET_COLOR(COLOR_YELLOW);
    fgets(p->data.tenSV, sizeof(p->data.tenSV), stdin);
    p->data.tenSV[strcspn(p->data.tenSV, "\n")] = 0;
    SET_COLOR(COLOR_WHITE);

    /* Cap nhat ID moi */
    printf("  Nhap ID moi  : ");
    SET_COLOR(COLOR_YELLOW);
    fgets(p->data.idSV, sizeof(p->data.idSV), stdin);
    p->data.idSV[strcspn(p->data.idSV, "\n")] = 0;
    SET_COLOR(COLOR_WHITE);

    inThongBao("Cap nhat thong tin sinh vien thanh cong!", 1);
    nhanPhimTiepTuc();
}

/* ===== TRA CUU SINH VIEN THEO TEN ===== */

void tracuuSinhVien(ListReader l, ListBorrow lb) {
    char        ten[100];
    int         soKQ = 0;
    NodeReader *pSV;

    inTieuDe("TRA CUU SINH VIEN THEO TEN");

    printf("\n  Nhap ten (hoac mot phan ten) can tim: ");
    SET_COLOR(COLOR_YELLOW);
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = 0;
    SET_COLOR(COLOR_WHITE);

    for (pSV = l.head; pSV != NULL; pSV = pSV->next) {
        NodeBorrow *pPhieu;
        int         soSachMuon = 0;

        if (strstr(pSV->data.tenSV, ten) == NULL) continue;

        soKQ++;
        printf("\n");
        SET_COLOR(COLOR_CYAN);
        printf("  +--------------------------------------------------+\n");
        SET_COLOR(COLOR_YELLOW);
        printf("  | MSSV   : %-40s|\n", pSV->data.idSV);
        printf("  | Ho ten : %-40s|\n", pSV->data.tenSV);
        SET_COLOR(COLOR_CYAN);
        printf("  +--------------------------------------------------+\n");
        SET_COLOR(COLOR_WHITE);

        /* Quet cac phieu muon cua sinh vien nay */
        for (pPhieu = lb.head; pPhieu != NULL; pPhieu = pPhieu->next) {
            int   idSach;
            char *tenSach = "Khong ro";
            int   i;
            long  tre;

            if (strcmp(pPhieu->data.idSinhVien, pSV->data.idSV) != 0)
                continue;

            idSach = atoi(pPhieu->data.idSach);
            for (i = 0; i < h; i++) {
                if (ds[i].id == idSach) { tenSach = ds[i].tensach; break; }
            }

            /* In tieu de bang lan dau */
            if (soSachMuon == 0) {
                printf("\n");
                SET_COLOR(COLOR_CYAN);
                printf("  %-4s  %-22s  %-12s  %-12s\n",
                       "STT", "TEN SACH", "NGAY MUON", "HAN TRA");
                inDuongNgang(60);
                SET_COLOR(COLOR_WHITE);
            }

            soSachMuon++;
            tre = soNgayTre(pPhieu->data.ngayTra);

            if (tre > 0) SET_COLOR(COLOR_RED);
            else         SET_COLOR(COLOR_WHITE);

            printf("  %-4d  %-22s  %-12s  %-12s",
                   soSachMuon, tenSach,
                   pPhieu->data.ngayMuon,
                   pPhieu->data.ngayTra);

            if (tre > 0) {
                SET_COLOR(COLOR_RED);
                printf("  [TRE %ld NGAY]", tre);
            }
            printf("\n");
            SET_COLOR(COLOR_WHITE);
        }

        if (soSachMuon == 0) {
            SET_COLOR(COLOR_GRAY);
            printf("  Sinh vien chua muon sach nao.\n");
            SET_COLOR(COLOR_WHITE);
        } else {
            inDuongNgang(60);
            SET_COLOR(COLOR_CYAN);
            printf("  Tong: %d cuon dang muon.\n", soSachMuon);
            SET_COLOR(COLOR_WHITE);
        }
    }

    printf("\n");
    if (soKQ == 0) {
        inThongBao("Khong tim thay sinh vien co ten phu hop!", 0);
    } else {
        SET_COLOR(COLOR_GREEN);
        printf("  => Tim thay %d sinh vien.\n", soKQ);
        SET_COLOR(COLOR_WHITE);
    }

    nhanPhimTiepTuc();
}
