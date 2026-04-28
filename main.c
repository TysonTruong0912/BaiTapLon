#include "sach.h"
#include "reader_borrow.h"

/* ===== MENU ===== */

void veMenu() {
    int i;
    inTieuDeApp();

    printf("\n");
    SET_COLOR(COLOR_CYAN);
    printf("  +");
    for (i = 0; i < 56; i++) printf("-");
    printf("+\n");

    SET_COLOR(COLOR_WHITE);
    printf("  |  ");
    SET_COLOR(COLOR_GREEN);
    printf("[1]");
    SET_COLOR(COLOR_WHITE);
    printf(" Them sach                                       |\n");

    printf("  |  ");
    SET_COLOR(COLOR_GREEN);
    printf("[2]");
    SET_COLOR(COLOR_WHITE);
    printf(" Hien thi danh sach sach                        |\n");

    printf("  |  ");
    SET_COLOR(COLOR_GREEN);
    printf("[3]");
    SET_COLOR(COLOR_WHITE);
    printf(" Tim sach theo ID                               |\n");

    printf("  |  ");
    SET_COLOR(COLOR_BLUE);
    printf("[4]");
    SET_COLOR(COLOR_WHITE);
    printf(" Hien thi danh sach sinh vien                   |\n");

    printf("  |  ");
    SET_COLOR(COLOR_BLUE);
    printf("[5]");
    SET_COLOR(COLOR_WHITE);
    printf(" Hien thi danh sach phieu muon                  |\n");

    printf("  |  ");
    SET_COLOR(COLOR_YELLOW);
    printf("[6]");
    SET_COLOR(COLOR_WHITE);
    printf(" Muon sach                                       |\n");

    printf("  |  ");
    SET_COLOR(COLOR_BLUE);
    printf("[7]");
    SET_COLOR(COLOR_WHITE);
    printf(" Them sinh vien                                  |\n");

    SET_COLOR(COLOR_CYAN);
    printf("  +");
    for (i = 0; i < 56; i++) printf("-");
    printf("+\n");

    printf("  |  ");
    SET_COLOR(COLOR_RED);
    printf("[0]");
    SET_COLOR(COLOR_WHITE);
    printf(" Thoat chuong trinh                              ");
    SET_COLOR(COLOR_CYAN);
    printf("|\n");

    printf("  +");
    for (i = 0; i < 56; i++) printf("-");
    printf("+\n");
    SET_COLOR(COLOR_WHITE);

    printf("\n  ");
    SET_COLOR(COLOR_YELLOW);
    printf("  Lua chon cua ban: ");
    SET_COLOR(COLOR_WHITE);
}

void menu(ListReader *lr, ListBorrow *lb) {
    int choice;
    int n;

    do {
        veMenu();
        scanf("%d", &choice);
        getchar();

        CLEAR_SCREEN();

        switch (choice) {
            case 1:
                inTieuDe("THEM SACH MOI");
                printf("\n  Nhap so luong sach can them: ");
                SET_COLOR(COLOR_YELLOW);
                scanf("%d", &n);
                SET_COLOR(COLOR_WHITE);
                getchar();
                themSach(n);
                break;

            case 2:
                hienThiSach();
                break;

            case 3:
                timTheoID();
                break;

            case 4:
                showReaderList(*lr);
                break;

            case 5:
                showBorrowList(*lb);
                break;

            case 6:
                muonSach(lb);
                break;

            case 7:
                themReader(lr);
                break;

            case 0:
                CLEAR_SCREEN();
                SET_COLOR(COLOR_CYAN);
                printf("\n\n  Cam on da su dung he thong!\n\n");
                SET_COLOR(COLOR_WHITE);
                break;

            default:
                inThongBao("Lua chon khong hop le! Vui long chon lai.", 2);
                nhanPhimTiepTuc();
                break;
        }

    } while (choice != 0);
}

/* ===== MAIN ===== */

int main() {
    ListReader lr;
    ListBorrow lb;

    initReaderList(&lr);
    initBorrowList(&lb);

    menu(&lr, &lb);

    return 0;
}
