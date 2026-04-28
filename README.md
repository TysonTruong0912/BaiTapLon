# HE THONG QUAN LY THU VIEN

## Yeu cau he thong

- Compiler: Dev C++ (MinGW)
- He dieu hanh: Windows (khuyen nghi), Linux/macOS deu chay duoc
- Khong can thu vien ngoai

---

## Cach bien dich va chay

**Tren Dev C++:**
1. Mo file `library.c` bang Dev C++
2. Nhan `F9` (Compile & Run) hoac vao menu `Execute > Compile & Run`

---

## Cau truc du lieu

### Sach (mang tinh)
```c
typedef struct {
    int  id;
    char tensach[100];
    int  soLuong;
} Sach;

Sach ds[100];   /* mang toi da 100 quyen sach */
int  h = 0;     /* so sach hien tai */
```

### Reader (danh sach lien ket don)
```c
typedef struct {
    char idSV[50];
    char tenSV[100];
} Reader;

typedef struct NodeReader {
    Reader           data;
    struct NodeReader *next;
} NodeReader;

typedef struct { NodeReader *head; } ListReader;
```

### Borrow (danh sach lien ket don)
```c
typedef struct {
    char idSach[50];
    char idSinhVien[50];
    char ngayMuon[50];
    char ngayTra[50];
} Borrow;

typedef struct NodeBorrow {
    Borrow           data;
    struct NodeBorrow *next;
} NodeBorrow;

typedef struct { NodeBorrow *head; } ListBorrow;
```

---

## Chuc nang chinh

### Menu chinh

```
[1] Them sach
[2] Hien thi danh sach sach
[3] Tim sach theo ID
[4] Hien thi danh sach sinh vien
[5] Hien thi danh sach phieu muon
[6] Muon sach
[7] Them sinh vien
[0] Thoat
```

### Mo ta tung chuc nang

**[1] Them sach** — Nhap so luong sach can them, sau do nhap lan luot ID, ten sach, so luong cho tung quyen. Du lieu luu vao mang `ds[]`.

**[2] Hien thi danh sach sach** — In toan bo sach hien co kem so luong. So luong 0 hien thi mau do, <= 2 mau vang, con lai mau xanh.

**[3] Tim sach theo ID** — Nhap ID, chuong trinh duyet mang `ds[]` va in thong tin quyen sach tuong ung. Bao loi neu khong tim thay.

**[4] Hien thi danh sach sinh vien** — Duyet `ListReader` va in so thu tu, ma SV, ho ten.

**[5] Hien thi danh sach phieu muon** — Duyet `ListBorrow` va in toan bo phieu muon gom ID sach, ma SV, ngay muon, ngay tra.

**[6] Muon sach** — Nhap ID sach, ma SV, ngay muon, ngay tra. Neu sach ton tai va con so luong > 0 thi giam `soLuong` di 1 va them node moi vao `ListBorrow`. Bao loi neu sach het hoac khong tim thay.

**[7] Them sinh vien** — Nhap ma SV va ho ten, them node moi vao `ListBorrow`. Co the them nhieu sinh vien lien tiep, nhap `y` de tiep tuc, `n` de dung.

---

## So do luong du lieu

```
ListReader (linked list)          ListBorrow (linked list)
+--------+                        +--------+
| head   | --> [Node] --> [Node]  | head   | --> [Node] --> [Node]
+--------+                        +--------+

ds[] (array, max 100)
[ Sach | Sach | Sach | ... ]
```

---
