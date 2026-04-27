#include<stdio.h>
#include<string.h>

typedef struct {
    int id;
    char tensach[100];
    int soLuong;
} Sach;

   Sach ds[100];
    int h = 0;
    



void themSach(int n) {
	  for(int i =0; i < n; i++) {
    printf("\nNhap ID: ");
    scanf("%d", &ds[i].id);
    getchar();

    printf("Nhap ten sach: ");
    fgets(ds[h].tensach, sizeof(ds[h].tensach), stdin);
    ds[h].tensach[strcspn(ds[h].tensach, "\n")] = 0;

  

    printf("Nhap so luong: ");
    scanf("%d", &ds[h].soLuong);
   
    h++;

  ;}
    
    printf(" Them thanh cong!\n");
}


void hienThi() {
    if( h== 0) {
        printf("\nDanh sach rong!\n");
        return;
    }

    printf("\n     DANH SACH SACH     \n");
    for(int i = 0; i < h; i++) {
        printf("\nID: %d", ds[i].id);
        printf("\nTen sach: %s", ds[i].tensach);
     
        printf("\nSo luong: %d\n", ds[i].soLuong);
    }
}


void timTheoID() {
    int id;
    printf("\nNhap ID can tim: ");
    scanf("%d", &id);

    int tim = 0;

    for(int i = 0; i < h; i++) {
        if(ds[i].id == id) {
            printf("\n    Sach tim thay    \n");
            printf("ID: %d\n", ds[i].id);
            printf("Ten: %s\n", ds[i].tensach);
         
            printf("So luong: %d\n", ds[i].soLuong);
            tim = 1;
        }
    }

    if(tim == 0) {
        printf("Khong tim thay sach!\n");
    }
}




int main() {
 
    int chon;
    int  thoat;
    int n;
    do {
        printf("\n     QUAN LY THU VIEN      ");
        printf("\n1. Them sach");
        
        printf("\n2. Hien thi danh sach");
        printf("\n3. Tim sach theo ID");
        printf("\n0. Thoat");
        printf("\nChon: ");
        scanf("%d", &chon);

        switch(chon) {
            case 1:{
			
		printf ("Ban muon them bao nhieu loai sach:");
		scanf("%d",&n);
                themSach(n);
				}
                
                break;
            case 2:
                hienThi();
                break;
            case 3:
                timTheoID();
                break;
            case 0:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while(chon != 0);

    return 0;
}

