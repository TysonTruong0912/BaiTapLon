#ifndef READER_H
#define READER_H

#include "common.h"

/* ===== HAM QUAN LY SINH VIEN (READER) ===== */

/* Khoi tao danh sach sinh vien rong */
void initReaderList(ListReader *l);

/* Cap phat va tra ve mot node moi chua du lieu r */
NodeReader *createReader(Reader r);

/* Chen sinh vien vao cuoi danh sach */
void insertReader(ListReader *l, Reader r);

/* Tim sinh vien theo MSSV, tra ve con tro node hoac NULL */
NodeReader *findReader(ListReader l, char id[]);

/* Giao dien tim sinh vien theo MSSV */
void timReader(ListReader l);

/* Xoa node sinh vien khoi danh sach theo id */
void deleteReader(ListReader *l, char id[]);

/* Giao dien xoa sinh vien */
void xoaReader(ListReader *l);

/* Giao dien them mot hoac nhieu sinh vien */
void themReader(ListReader *l);

/* Hien thi toan bo danh sach sinh vien */
void showReaderList(ListReader l);

/* Dem va tra ve so luong sinh vien */
int demReader(ListReader l);

/* Giao dien sua thong tin sinh vien */
void suaReader(ListReader *l);

/* Tra cuu sinh vien theo ten (ho tro tim kiem mo) va hien thi sach dang muon */
void tracuuSinhVien(ListReader l, ListBorrow lb);

#endif /* READER_H */
