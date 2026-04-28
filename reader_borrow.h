#ifndef READER_BORROW_H
#define READER_BORROW_H

#include "common.h"

/* ===== KHAI BAO HAM READER ===== */

void initReaderList(ListReader *l);
void insertReader(ListReader *l, Reader r);
void themReader(ListReader *l);
void showReaderList(ListReader l);

/* ===== KHAI BAO HAM BORROW ===== */

void initBorrowList(ListBorrow *l);
void insertBorrow(ListBorrow *l, Borrow b);
void showBorrowList(ListBorrow l);
void muonSach(ListBorrow *lb);

#endif /* READER_BORROW_H */
