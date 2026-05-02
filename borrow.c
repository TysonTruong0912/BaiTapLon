#include "borrow.h"
#include "sach.h"

/* ===== HAM NOI BO ===== */

static NodeBorrow *createBorrow(Borrow b) {
    NodeBorrow *p = (NodeBorrow*)malloc(sizeof(NodeBorrow));
    if (!p) {
        printf("cap phat vung nho that bai!\n");
        return NULL;
    }
    p->data = b;
    p->next = NULL;
    return p;
}

/* ===== KHOI TAO ===== */

void initBorrowList(ListBorrow *l) {
    l->head = NULL;
}

/* ===== THEM ===== */

void insertBorrow(ListBorrow *l, Borrow b) {
    NodeBorrow *p    = createBorrow(b);
    NodeBorrow *temp;
    if (!p) return;
    if (!l->head) { l->head = p; return; }
    temp = l->head;
    while (temp->next) temp = temp->next;
    temp->next = p;
}

/* ===== HIEN THI ===== */

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
        else              SET_COLOR(COLOR_WHITE);
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
    int idSach, found, i;

    inTieuDe("MUON SACH");

    printf("\n  Nhap ID sach      : ");
    SET_COLOR(COLOR_YELLOW);
    scanf("%d", &idSach);
    SET_COLOR(COLOR_WHITE);
    getchar();

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
                printf("  | Sach   : %-21s|\n", ds[i].tensach);
                printf("  | Con lai: %-21d|\n", ds[i].soLuong);
                SET_COLOR(COLOR_GREEN);
                printf("  +-------------------------------+\n");
                SET_COLOR(COLOR_WHITE);
            } else {
                inThongBao("Sach da het! Khong the muon.", 0);
            }
            break;
        }
    }

    if (!found) {
        inThongBao("Khong tim thay sach voi ID nay!", 0);
    }

    nhanPhimTiepTuc();
}

void traSach(ListBorrow *lb) {
    char idSinhVien[50];
    char idSachStr[50];
    int idSach;
    NodeBorrow *p, *truoc;
    int found, i;

    inTieuDe("TRA SACH");

    printf("\n  Nhap ID sach can tra : ");
    SET_COLOR(COLOR_YELLOW);
    scanf("%d", &idSach);
    SET_COLOR(COLOR_WHITE);
    getchar();

    printf("  Nhap ID sinh vien    : ");
    SET_COLOR(COLOR_YELLOW);
    fgets(idSinhVien, sizeof(idSinhVien), stdin);
    idSinhVien[strcspn(idSinhVien, "\n")] = 0;
    SET_COLOR(COLOR_WHITE);

    sprintf(idSachStr, "%d", idSach);

    /* Tim phieu muon trung khop */
    p     = lb->head;
    truoc = NULL;
    found = 0;

    while (p != NULL) {
        if (strcmp(p->data.idSach, idSachStr) == 0 &&
            strcmp(p->data.idSinhVien, idSinhVien) == 0)
        {
            found = 1;

            /* Tang so luong sach trong kho */
            for (i = 0; i < h; i++) {
                if (ds[i].id == idSach) {
                    ds[i].soLuong++;
                    break;
                }
            }

            /* Xoa phieu muon khoi danh sach */
            if (truoc == NULL)
                lb->head = p->next;
            else
                truoc->next = p->next;
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
