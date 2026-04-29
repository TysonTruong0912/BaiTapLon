#ifndef BORROW_H
#define BORROW_H

#include "common.h"

/* ==== HAM BORROW ===== */

void initBorrowList (ListBorrow *l);
void insertBorrow   (ListBorrow *l, Borrow b);
void showBorrowList (ListBorrow l);
void muonSach       (ListBorrow *lb);

#endif /* BORROW_H */
