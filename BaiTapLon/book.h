#ifndef BOOK_H
#define BOOK_H

#include "common.h"

/* ===== HAM QUAN LY SACH ===== */

/* Them n cuon sach moi vao mang ds[] */
void themSach(int n);

/* Hien thi toan bo danh sach sach */
void hienThiSach(void);

/* Tim sach theo ID, hien thi thong tin neu tim thay */
void timTheoID(void);

/* Phan tich chuoi ngay "DD/MM/YYYY" thanh struct tm */
int parseDate(const char *s, struct tm *out);

#endif /* BOOK_H */
