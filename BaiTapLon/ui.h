#ifndef UI_H
#define UI_H

#include "common.h"

/* ===== HAM VE GIAO DIEN ===== */

/* Ve duong ngang '-' voi do dai n */
void inDuongNgang(int n);

/* Ve duong doi '=' voi do dai n */
void inDuongDon(int n);

/* In hop tieu de can giua */
void inTieuDe(const char *tieuDe);

/* In banner chinh cua ung dung (co xoa man hinh) */
void inTieuDeApp(void);

/* In thong bao: loai=1 -> OK (xanh), 0 -> LOI (do), khac -> canh bao (vang) */
void inThongBao(const char *msg, int loai);

/* Hien thi "Nhan Enter de tiep tuc..." va cho nguoi dung nhan phim */
void nhanPhimTiepTuc(void);

/* ===== HAM NHAP CO KIEM TRA LOI ===== */

/* Nhap so nguyen, tu dong bao loi va yeu cau nhap lai neu khong hop le */
int nhapSoNguyen(void);

/* ===== DASHBOARD ===== */

/* Hien thi man hinh tong quan (thong ke sach, muon, sinh vien, qua han) */
void hienThiDashboard(ListReader lr, ListBorrow lb);

#endif /* UI_H */
