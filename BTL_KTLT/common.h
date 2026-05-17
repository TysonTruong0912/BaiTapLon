#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* ===== HANG SO ===== */
#define TIEN_PHAT_MOI_NGAY    2000L
#define SO_NGAY_MUON_MAC_DINH 14
#define MAX_SACH              100

/* ===== MACRO MAU SAC & MAN HINH (da nen tang) ===== */
#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN()  system("cls")
    #define SET_COLOR(c)    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c)
    #define COLOR_WHITE     15
    #define COLOR_CYAN      11
    #define COLOR_YELLOW    14
    #define COLOR_GREEN     10
    #define COLOR_RED       12
    #define COLOR_GRAY       8
    #define COLOR_BLUE       9
    #define COLOR_MAGENTA   13
#else
    #define CLEAR_SCREEN()  system("clear")
    #define SET_COLOR(c)    printf("\033[%sm", c)
    #define COLOR_WHITE     "0;37"
    #define COLOR_CYAN      "0;36"
    #define COLOR_YELLOW    "0;33"
    #define COLOR_GREEN     "0;32"
    #define COLOR_RED       "0;31"
    #define COLOR_GRAY      "0;90"
    #define COLOR_BLUE      "0;34"
    #define COLOR_MAGENTA   "0;35"
#endif

/* ===== CAU TRUC DU LIEU ===== */

/* Thong tin mot cuon sach */
typedef struct {
    int  id;
    char tensach[100];
    int  soLuong;
} Sach;

/* Thong tin mot phieu muon */
typedef struct {
    char idSach[50];
    char idSinhVien[50];
    char ngayMuon[50];
    char ngayTra[50];
} Borrow;

/* Thong tin mot sinh vien (doc gia) */
typedef struct {
    char idSV[50];
    char tenSV[100];
} Reader;

/* Node danh sach lien ket sinh vien */
typedef struct NodeReader {
    Reader           data;
    struct NodeReader *next;
} NodeReader;

/* Node danh sach lien ket phieu muon */
typedef struct NodeBorrow {
    Borrow           data;
    struct NodeBorrow *next;
} NodeBorrow;

/* Danh sach sinh vien */
typedef struct {
    NodeReader *head;
} ListReader;

/* Danh sach phieu muon */
typedef struct {
    NodeBorrow *head;
} ListBorrow;

/* ===== BIEN TOAN CUC (khai bao trong book.c) ===== */
extern Sach ds[MAX_SACH];   /* Mang luu sach */
extern int  h;              /* So luong sach hien co */

#endif /* COMMON_H */
