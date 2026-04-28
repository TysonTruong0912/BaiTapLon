#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ===== MAU SAC CONSOLE ===== */

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define SET_COLOR(c) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c)
#define COLOR_WHITE    15
#define COLOR_CYAN     11
#define COLOR_YELLOW   14
#define COLOR_GREEN    10
#define COLOR_RED      12
#define COLOR_GRAY      8
#define COLOR_BLUE      9
#define COLOR_MAGENTA  13
#else
#define CLEAR_SCREEN() system("clear")
#define SET_COLOR(c)   printf("\033[%sm", c)
#define COLOR_WHITE    "0;37"
#define COLOR_CYAN     "0;36"
#define COLOR_YELLOW   "0;33"
#define COLOR_GREEN    "0;32"
#define COLOR_RED      "0;31"
#define COLOR_GRAY     "0;90"
#define COLOR_BLUE     "0;34"
#define COLOR_MAGENTA  "0;35"
#endif

/* ===== CAU TRUC DU LIEU ===== */

typedef struct {
    int  id;
    char tensach[100];
    int  soLuong;
} Sach;

typedef struct {
    char idSach[50];
    char idSinhVien[50];
    char ngayMuon[50];
    char ngayTra[50];
} Borrow;

typedef struct {
    char idSV[50];
    char tenSV[100];
} Reader;

typedef struct NodeReader {
    Reader            data;
    struct NodeReader *next;
} NodeReader;

typedef struct NodeBorrow {
    Borrow            data;
    struct NodeBorrow *next;
} NodeBorrow;

typedef struct {
    NodeReader *head;
} ListReader;

typedef struct {
    NodeBorrow *head;
} ListBorrow;

/* ===== BIEN TOAN CUC ===== */

extern Sach ds[100];
extern int  h;

/* ===== KHAI BAO HAM GIAO DIEN ===== */

void inDuongNgang(int n);
void inDuongDon(int n);
void inTieuDe(const char *tieuDe);
void inTieuDeApp(void);
void inThongBao(const char *msg, int loai);
void nhanPhimTiepTuc(void);

#endif /* COMMON_H */
