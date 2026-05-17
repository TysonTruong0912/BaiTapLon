# ============================================================
#  Makefile – He Thong Quan Ly Thu Vien
#  Su dung: make          -> build
#           make clean    -> xoa file trung gian va binary
#           make rebuild  -> clean roi build lai
# ============================================================

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -g
TARGET  = library

# Danh sach tat ca cac file .o can lien ket
OBJS =  ui.o     \
        book.o   \
        reader.o \
        borrow.o \
        menu.o   \
        main.o

# ---- Quy tac mac dinh: build binary ----
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo ""
	@echo "  [OK] Build thanh cong -> ./$(TARGET)"
	@echo ""

# ---- Quy tac bien dich tung file .c -> .o ----
# Moi file .o phu thuoc vao common.h; them header rieng neu can

ui.o: ui.c ui.h common.h
	$(CC) $(CFLAGS) -c ui.c -o ui.o

book.o: book.c book.h ui.h common.h
	$(CC) $(CFLAGS) -c book.c -o book.o

reader.o: reader.c reader.h ui.h book.h common.h
	$(CC) $(CFLAGS) -c reader.c -o reader.o

borrow.o: borrow.c borrow.h book.h reader.h ui.h common.h
	$(CC) $(CFLAGS) -c borrow.c -o borrow.o

menu.o: menu.c menu.h ui.h book.h reader.h borrow.h common.h
	$(CC) $(CFLAGS) -c menu.c -o menu.o

main.o: main.c common.h ui.h book.h reader.h borrow.h menu.h
	$(CC) $(CFLAGS) -c main.c -o main.o

# ---- Don dep ----
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "  [OK] Da xoa cac file trung gian va binary."

rebuild: clean all

.PHONY: all clean rebuild
