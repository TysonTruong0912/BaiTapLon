# HUONG DAN SU DUNG – HE THONG QUAN LY THU VIEN

---

## GIOI THIEU

Chuong trinh quan ly thu vien chay tren cua so lenh (terminal/cmd).  
Khi khoi dong, he thong tu dong tai du lieu da luu, hien thi **Dashboard tong quan**
roi vao **Menu chinh** de nguoi dung thao tac.

---

## KHOI DONG CHUONG TRINH

```
./library          (Linux / macOS)
library.exe        (Windows)
```

Man hinh dau tien hien thi **Dashboard** gom:

| Chi so | Y nghia |
|---|---|
| Tong so sach | So dau sach dang quan ly |
| Dang duoc muon | Tong so luot sach hien dang cho muon |
| Sinh vien | Tong so sinh vien da dang ky |
| Phieu muon | Tong so phieu muon trong he thong |
| Con nhieu / Sap het / Da het | Phan loai tinh trang ton kho sach |
| Qua han | So phieu muon da vuot ngay tra |
| Hom nay | Ngay hien tai cua he thong |

> Nhan **Enter** de vao Menu chinh.

---

## MENU CHINH

```
[1]  Them sach
[2]  Hien thi danh sach sach
[3]  Tim sach theo ID
[4]  Hien thi danh sach sinh vien
[5]  Hien thi danh sach phieu muon
[6]  Muon sach
[7]  Them sinh vien
[8]  Tim sinh vien theo Ma SV
[9]  Xoa sinh vien
[10] Luu / Tai file sinh vien
[11] Tra sach
[12] Xem Dashboard tong quan
[13] Kiem tra phieu qua han
[14] Tinh tien phat cho sinh vien
[15] Dem so luong sinh vien
[16] Tra cuu sinh vien theo ten
[17] Sua thong tin sinh vien
[0]  Thoat chuong trinh
```

> **Luu y nhap lieu:** Tat ca o nhap so (ID, so luong, lua chon menu) deu co
> kiem tra loi. Neu nhap sai (chu, ky tu dac biet...) man hinh se hien thi
> `[LOI]` va yeu cau nhap lai ngay tai cho, khong can khoi dong lai.

---

## CHI TIET TUNG CHUC NANG

---

### [1] THEM SACH

**Muc dich:** Nhap them sach moi vao he thong.

**Cac buoc thuc hien:**
1. Chon `[1]` tu menu chinh.
2. Nhap **so luong sach** can them (vi du: `3` de them 3 cuon).
3. Voi moi cuon sach, lan luot nhap:
   - **ID sach** – so nguyen, dung de dinh danh (vi du: `101`).
   - **Ten sach** – chuoi van ban tu do (vi du: `Lap Trinh C Co Ban`).
   - **So luong** – so ban co san (vi du: `5`).
4. Sau khi nhap xong tat ca, man hinh hien thi `[OK] Them sach thanh cong!`.

**Vi du nhap:**
```
Nhap so luong sach can them: 1
--- Sach thu 1/1 ---
Nhap ID       : 101
Nhap ten sach : Lap Trinh C Co Ban
Nhap so luong : 5
```

---

### [2] HIEN THI DANH SACH SACH

**Muc dich:** Xem toan bo sach dang co trong he thong.

**Thong tin hien thi:** ID | Ten sach | So luong

**Mau hien thi so luong:**
- **Xanh la** – con nhieu (> 2 ban)
- **Vang** – sap het (1–2 ban)
- **Do** – da het (0 ban)

---

### [3] TIM SACH THEO ID

**Muc dich:** Tra cuu nhanh thong tin mot cuon sach cu the.

**Cac buoc thuc hien:**
1. Chon `[3]`.
2. Nhap **ID sach** can tim (vi du: `101`).
3. He thong hien thi: ID, ten sach, so luong ton kho.
4. Neu khong co sach voi ID do: hien thi `[LOI] Khong tim thay sach voi ID nay!`.

---

### [4] HIEN THI DANH SACH SINH VIEN

**Muc dich:** Xem toan bo sinh vien da dang ky trong he thong.

**Thong tin hien thi:** STT | Ma SV | Ho ten

---

### [5] HIEN THI DANH SACH PHIEU MUON

**Muc dich:** Xem tat ca phieu muon sach hien tai.

**Thong tin hien thi:** STT | ID Sach | Ma SV | Ngay muon | Ngay tra

---

### [6] MUON SACH

**Muc dich:** Tao phieu muon sach cho sinh vien.

**Cac buoc thuc hien:**
1. Chon `[6]`.
2. Nhap **ID sach** muon muon.
3. Nhap **ID sinh vien** (Ma SV).
4. Nhap **ngay muon** theo dinh dang `DD/MM/YYYY` (vi du: `01/06/2025`).
5. Nhap **ngay tra** theo dinh dang `DD/MM/YYYY` (vi du: `15/06/2025`).
6. He thong kiem tra:
   - Neu sach **con hang**: giam ton kho 1 ban, tao phieu muon, hien thi xac nhan.
   - Neu sach **het hang**: hien thi `[LOI] Sach da het! Khong the muon.`
   - Neu **khong tim thay ID sach**: hien thi thong bao loi.

**Vi du nhap:**
```
Nhap ID sach      : 101
Nhap ID sinh vien : SV001
Nhap ngay muon    : 01/06/2025
Nhap ngay tra     : 15/06/2025
```

---

### [7] THEM SINH VIEN

**Muc dich:** Dang ky sinh vien moi vao he thong.

**Cac buoc thuc hien:**
1. Chon `[7]`.
2. Nhap **ID sinh vien** (Ma SV, vi du: `SV001`).
3. Nhap **ho ten sinh vien** (vi du: `Nguyen Van An`).
4. He thong hoi `Tiep tuc them? (y/n)`:
   - Nhap `y` de tiep tuc them sinh vien moi.
   - Nhap `n` de ket thuc.

---

### [8] TIM SINH VIEN THEO MA SV

**Muc dich:** Tra cuu thong tin sinh vien theo ma so.

**Cac buoc thuc hien:**
1. Chon `[8]`.
2. Nhap **Ma SV** can tim (vi du: `SV001`).
3. He thong hien thi Ma SV va ho ten neu tim thay.
4. Neu khong co: hien thi `[LOI] Khong tim thay sinh vien voi Ma SV nay!`

---

### [9] XOA SINH VIEN

**Muc dich:** Xoa mot sinh vien khoi danh sach.

**Cac buoc thuc hien:**
1. Chon `[9]`.
2. Nhap **Ma SV** can xoa.
3. He thong xoa va hien thi `[OK] Xoa sinh vien thanh cong!`.
4. Neu khong tim thay: hien thi thong bao loi.

> **Luu y:** Viec xoa sinh vien khong tu dong xoa phieu muon lien quan.
> Nen kiem tra va tra het sach truoc khi xoa sinh vien.

---

### [10] LUU / TAI FILE

**Muc dich:** Luu du lieu hien tai ra file hoac tai lai du lieu da luu.

**Cac buoc thuc hien:**
1. Chon `[10]`.
2. Chon tiep:
   - `[1]` **Luu** – ghi toan bo sinh vien va phieu muon vao file `sinhvien.txt`.
   - `[2]` **Tai** – doc du lieu tu file `sinhvien.txt` vao he thong.
   - `[0]` **Quay lai** – huy, khong lam gi.

> **Luu y quan trong:**
> - Du lieu **chi duoc giu lai** sau khi tat chuong trinh neu da chon **Luu**.
> - Moi lan khoi dong, chuong trinh **tu dong tai** du lieu tu file (neu file ton tai).
> - File `sinhvien.txt` nam cung thu muc voi file chay.

---

### [11] TRA SACH

**Muc dich:** Xu ly tra sach, xoa phieu muon, tang lai ton kho.

**Cac buoc thuc hien:**
1. Chon `[11]`.
2. Nhap **ID sach** can tra.
3. Nhap **ID sinh vien** tra sach.
4. He thong tim phieu muon khop voi ca hai thong tin:
   - Neu tim thay: xoa phieu muon, tang ton kho +1, hien thi xac nhan.
   - Neu khong tim thay: hien thi `[LOI] Khong tim thay phieu muon phu hop!`

---

### [12] XEM DASHBOARD TONG QUAN

**Muc dich:** Xem lai man hinh tong quan bat cu luc nao trong qua trinh su dung.

Noi dung tuong tu man hinh khoi dong (xem phan **KHOI DONG** o tren).

---

### [13] KIEM TRA PHIEU QUA HAN

**Muc dich:** Liet ke tat ca phieu muon da vuot ngay tra kem thong tin tien phat.

**Thong tin hien thi moi phieu:**
- ID sach | Ma sinh vien | Han tra | So ngay tre | Tien phat

**Mau canh bao:**
- **Vang** – tre tu 1 den 7 ngay
- **Do dam** – tre tren 7 ngay

**Cuoi bang:** Tong so phieu qua han va tong tien phat du kien.

**Cong thuc tinh tien phat:**
```
Tien phat = So ngay tre x 2.000 VND / ngay
```

> Neu khong co phieu nao qua han: hien thi `[OK] Khong co phieu muon nao qua han!`

---

### [14] TINH TIEN PHAT CHO SINH VIEN

**Muc dich:** Xem chi tiet tien phat cua **mot sinh vien cu the**.

**Cac buoc thuc hien:**
1. Chon `[14]`.
2. Nhap **Ma SV** can kiem tra.
3. He thong liet ke tat ca phieu muon cua sinh vien do kem:
   - **N/A** – ngay tra khong hop le
   - **Chua tre** – con trong han (mau xanh)
   - **So ngay tre + tien phat** – da qua han (mau do/vang)
4. Cuoi cung hien thi **tong tien phat phai nop**.

---

### [15] DEM SO LUONG SINH VIEN

**Muc dich:** Hien thi nhanh tong so sinh vien dang co trong he thong.

Chon `[15]`, he thong hien thi ngay so luong trong hop thong tin.

---

### [16] TRA CUU SINH VIEN THEO TEN

**Muc dich:** Tim sinh vien bang ten (ho tro tim kiem mo – khong can nhap day du).

**Cac buoc thuc hien:**
1. Chon `[16]`.
2. Nhap **mot phan ten** can tim (vi du: nhap `An` se tim tat ca SV co chu `An` trong ten).
3. Voi moi sinh vien tim duoc, he thong hien thi:
   - Ma SV va ho ten.
   - Danh sach sach dang muon (ten sach, ngay muon, han tra).
   - Canh bao `[TRE X NGAY]` neu co phieu qua han (mau do).
   - Neu chua muon sach nao: hien thi thong bao tuong ung.
4. Cuoi cung hien thi tong so sinh vien tim duoc.

**Vi du:** Nhap `Van` se tra ve tat ca sinh vien co ten chua chu `Van`.

---

### [17] SUA THONG TIN SINH VIEN

**Muc dich:** Cap nhat ho ten hoac Ma SV cho mot sinh vien.

**Cac buoc thuc hien:**
1. Chon `[17]`.
2. Nhap **Ma SV hien tai** cua sinh vien can sua.
3. He thong hien thi thong tin hien tai (Ma SV + ho ten).
4. Nhap **ten moi** (nhan Enter de xac nhan).
5. Nhap **ID moi** (nhan Enter de xac nhan).
6. Hien thi `[OK] Cap nhat thong tin sinh vien thanh cong!`

> **Luu y:** Neu thay doi Ma SV, can dam bao Ma SV moi khong trung voi sinh vien khac.

---

### [0] THOAT CHUONG TRINH

Chon `[0]` de ket thuc. He thong hien thi loi cam on va dong chuong trinh.

> **Nho luu truoc khi thoat** bang chuc nang `[10]` neu co thay doi du lieu.

---

## DINH DANG NGAY THANG

Tat ca ngay thang trong he thong deu nhap theo dinh dang:

```
DD/MM/YYYY
```

| Vi du | Y nghia |
|---|---|
| `01/06/2025` | Ngay 1 thang 6 nam 2025 |
| `31/12/2025` | Ngay 31 thang 12 nam 2025 |

---

## QUY TRINH SU DUNG CO BAN

```
Khoi dong chuong trinh
        |
        v
[7] Them sinh vien  ──>  [1] Them sach
        |                      |
        v                      v
   [6] Muon sach  <────────────+
        |
        v
   ... Sinh vien dang muon sach ...
        |
        v
  [11] Tra sach
        |
        v
  [10] Luu file  ──>  [0] Thoat
```

---

## CAC THONG BAO THUONG GAP

| Thong bao | Y nghia |
|---|---|
| `[OK] ...` (xanh) | Thao tac thanh cong |
| `[LOI] ...` (do) | Co loi, kiem tra lai thong tin nhap |
| `[!] ...` (vang) | Canh bao hoac thong tin can chu y |
| `[LOI] chi nhan gia tri so...` | Nhap sai kieu du lieu, vui long nhap lai so nguyen |
| `Sach da het! Khong the muon.` | Ton kho = 0, can bo sung sach truoc |
| `File chua ton tai, se tao moi khi luu.` | Lan dau chay, chua co file luu – binh thuong |
