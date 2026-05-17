#ifndef BORROW_H
#define BORROW_H

#include "common.h"

/* ===== HAM QUAN LY PHIEU MUON / TRA SACH ===== */

/* Khoi tao danh sach phieu muon rong */
void initBorrowList(ListBorrow *l);

/* Cap phat va tra ve mot node phieu muon moi */
NodeBorrow *createBorrow(Borrow b);

/* Chen phieu muon vao cuoi danh sach */
void insertBorrow(ListBorrow *l, Borrow b);

/* Hien thi toan bo danh sach phieu muon */
void showBorrowList(ListBorrow l);

/* Giao dien muon sach: nhap thong tin, giam so luong sach */
void muonSach(ListBorrow *lb);

/* Giao dien tra sach: xoa phieu muon, tang so luong sach */
void traSach(ListBorrow *lb);

/* Tinh so ngay tre han tu ngayTra den hom nay
   Tra ve: >0 = so ngay tre, 0 = chua tre, -1 = ngay khong hop le */
long soNgayTre(const char *ngayTra);

/* Hien thi canh bao tat ca phieu muon qua han kem tien phat */
void kiemTraQuaHan(ListBorrow lb, ListReader lr);

/* Giao dien tinh tong tien phat cho mot sinh vien cu the */
void tinhTienPhatSV(ListBorrow lb);

/* Luu danh sach sinh vien & phieu muon ra file */
void writeToFile(ListReader l, ListBorrow lb, char filename[]);

/* Doc danh sach sinh vien & phieu muon tu file */
void readFile(ListReader *l, ListBorrow *lb, char filename[]);

/* Giao dien chon luu hoac tai file */
void luuVaDoc(ListReader *l, ListBorrow *lb);

#endif /* BORROW_H */
