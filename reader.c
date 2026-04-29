#include "reader.h"

/* ===== HAM NOI ===== */

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

static void deleteReader(ListReader *l, char id[]) {
    NodeReader *p     = l->head;
    NodeReader *truoc = NULL;

    if (p != NULL && strcmp(p->data.idSV, id) == 0) {
        l->head = p->next;
        free(p);
        inThongBao("Xoa sinh vien thanh cong!", 1);
        return;
    }

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

/* ===== KHOI TAO ===== */

void initReaderList(ListReader *l) {
    l->head = NULL;
}

/* ===== THEM ===== */

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

/* ===== TIM ===== */

NodeReader *findReader(ListReader l, char id[]) {
    NodeReader *p = l.head;
    while (p != NULL) {
        if (strcmp(p->data.idSV, id) == 0) return p;
        p = p->next;
    }
    return NULL;
}

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
        SET_COLOR(COLOR_YELLOW);
        printf("%-24s|\n", p->data.idSV);
        SET_COLOR(COLOR_WHITE);
        printf("  | Ho ten : ");
        SET_COLOR(COLOR_YELLOW);
        printf("%-24s|\n", p->data.tenSV);
        SET_COLOR(COLOR_WHITE);
        SET_COLOR(COLOR_GREEN);
        printf("  +----------------------------------+\n");
        SET_COLOR(COLOR_WHITE);
    } else {
        inThongBao("Khong tim thay sinh vien voi Ma SV nay!", 0);
    }

    nhanPhimTiepTuc();
}

/* ===== XOA ===== */

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

/* ===== HIEN THI ===== */

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

/* ===== FILE ===== */

void writeReaderToFile(ListReader l, char filename[]) {
    NodeReader *p;
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        inThongBao("Khong mo duoc file de ghi!", 0);
        return;
    }
    for (p = l.head; p != NULL; p = p->next) {
        fprintf(f, "%s|%s\n", p->data.idSV, p->data.tenSV);
    }
    fclose(f);
    inThongBao("Da luu du lieu sinh vien vao file thanh cong!", 1);
}

void readReaderFromFile(ListReader *l, char filename[]) {
    Reader r;
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        inThongBao("File chua ton tai, se tao moi khi luu.", 2);
        return;
    }
    while (fscanf(f, "%49[^|]|%99[^\n]\n", r.idSV, r.tenSV) == 2) {
        insertReader(l, r);
    }
    fclose(f);
    inThongBao("Da tai du lieu sinh vien tu file thanh cong!", 1);
}

void luuVaDoc(ListReader *l) {
    int chon;
    inTieuDe("LUU / TAI FILE SINH VIEN");

    printf("\n");
    SET_COLOR(COLOR_CYAN);
    printf("  [1] Luu danh sach sinh vien ra file\n");
    printf("  [2] Tai danh sach sinh vien tu file\n");
    printf("  [0] Quay lai\n");
    SET_COLOR(COLOR_WHITE);
    printf("\n  Chon: ");
    SET_COLOR(COLOR_YELLOW);
    scanf("%d", &chon);
    SET_COLOR(COLOR_WHITE);
    getchar();

    if (chon == 1)      writeReaderToFile(*l, "nguoimuon.txt");
    else if (chon == 2) readReaderFromFile(l,  "nguoimuon.txt");

    nhanPhimTiepTuc();
}
