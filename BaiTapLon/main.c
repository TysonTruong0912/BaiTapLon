#include "common.h"
#include "ui.h"
#include "book.h"
#include "reader.h"
#include "borrow.h"
#include "menu.h"

/*
 * main.c  –  Diem vao chuong trinh He Thong Quan Ly Thu Vien
 *
 * Thu tu khoi dong:
 *   1. Khoi tao cac danh sach lien ket (sinh vien, phieu muon)
 *   2. Doc du lieu da luu tu file sinhvien.txt (neu co)
 *   3. Hien thi Dashboard tong quan
 *   4. Vao vong lap menu chinh cho den khi nguoi dung chon thoat
 */
int main(void) {
    ListReader lr;
    ListBorrow lb;

    /* Khoi tao danh sach rong */
    initReaderList(&lr);
    initBorrowList(&lb);

    /* Tai du lieu tu file (khong bao loi neu file chua ton tai) */
    readFile(&lr, &lb, "sinhvien.txt");

    /* Man hinh chao + Dashboard */
    hienThiDashboard(lr, lb);

    /* Vong lap menu chinh */
    menu(&lr, &lb);

    return 0;
}
