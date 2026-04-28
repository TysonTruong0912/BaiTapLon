#include "reader_borrow.h"
#include "sach.h"

/* ============ READER ============ */

void initReaderList(ListReader *l) {
    l->head = NULL;
}

static NodeReader *createReader(Reader r) {
    NodeReader *p = (NodeReader*)malloc(sizeof(NodeReader));
    if (!p) {
        printf("cap phat vung nho that bai!\n");
        return NULL;
    }
    p->data = r;
    p->next = NULL;
    return p;
}

void insertReader(ListReader *l, Reader r) {
    NodeReader *p    = createReader(r);
    NodeReader *temp;
    if (!p) return;
    if (!l->head) { l->head = p; return; }
    temp = l->head;
    while (temp->next) temp = temp->next;
    temp->next = p;
}

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
        inThongBao("Them Reader thanh cong!", 1);

        printf("  Tiep tuc them? (y/n): ");
        SET_COLOR(COLOR_YELLOW);
        scanf("%c", &tiepTuc);
        SET_COLOR(COLOR_WHITE);
        getchar();

    } while (tiepTuc == 'y' || tiepTuc == 'Y');

    nhanPhimTiepTuc();
}

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
        else              SET_COLOR(COLOR_WHITE);
        printf("  %-5d  %-15s  %-30s\n", stt, i->data.idSV, i->data.tenSV);
    }

    inDuongNgang(58);
    SET_COLOR(COLOR_WHITE);
    nhanPhimTiepTuc();
}

/* ============ BORROW ============ */

void initBorrowList(ListBorrow *l) {
    l->head = NULL;
}

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

void insertBorrow(ListBorrow *l, Borrow b) {
    NodeBorrow *p    = createBorrow(b);
    NodeBorrow *temp;
    if (!p) return;
    if (!l->head) { l->head = p; return; }
    temp = l->head;
    while (temp->next) temp = temp->next;
    temp->next = p;
}

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
