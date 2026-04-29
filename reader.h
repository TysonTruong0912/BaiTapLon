#ifndef READER_H
#define READER_H

#include "common.h"

/* ===== HAM READER ===== */

void        initReaderList    (ListReader *l);
void        insertReader      (ListReader *l, Reader r);
NodeReader *findReader        (ListReader l, char id[]);

void        themReader        (ListReader *l);
void        timReader         (ListReader l);
void        xoaReader         (ListReader *l);
void        showReaderList    (ListReader l);

void        writeReaderToFile (ListReader l,  char filename[]);
void        readReaderFromFile(ListReader *l, char filename[]);
void        luuVaDoc          (ListReader *l);

#endif /* READER_H */
