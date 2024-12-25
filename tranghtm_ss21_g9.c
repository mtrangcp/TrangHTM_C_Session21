#include <stdio.h>
#include <string.h>

typedef struct{
	char id[20];
	char name[50];
	char author[50];
	float price ;
	char category[50] ;
} Books;

void addInfo( Books book[], int *n );
void saveInfo( Books book[], int n );
void getInfo( Books book[], int n );
void showInfo( Books book[], int n );

int main(){
	int choice, check = -1, n = 0 ;
	Books book[100];
	
	do {
		printf("\n---------Menu-------------");
		printf("\n1. Nhap so luong va thong tin sach ");
		printf("\n2. Luu thong tin sach vao file ");
		printf("\n3. Lay thong tin sach tu file ");
		printf("\n4. Hien thi thong tin ");
		printf("\n5. Thoat ");
		printf("\nLua chon cua ban: ");
		scanf("%d", &choice);
		
		switch ( choice){
			case 1:{
				check = 1;
				addInfo(book, &n);
				break;
			}
			case 2:{
				if ( check == -1 ){
				 	printf("\nMang rong, vui long chon cn1!");
				}else{
					saveInfo(book, n);
				}
				break;
			}
			case 3:{
				if ( check == -1 ){
				 	printf("\nMang rong, vui long chon cn1!");
				}else{
					getInfo(book, n);
				}
				break;
			}
			case 4:{
				if ( check == -1 ){
				 	printf("\nMang rong, vui long chon cn1!");
				}else{
					showInfo(book, n);
				}
				break;
			}
			case 5:{
				printf("\nBan chon thoat!");
				break;
			}
			default:{
				printf("\nVui long chon dung(1-5)!");
				break;
			}
		}
	}while ( choice != 5 ) ;
	return 0;
}

void addInfo( Books book[], int *n ){
	printf("\nNhap so luong sach: ");
	scanf("%d", n);
	fflush(stdin);
	
	for ( int i = 0; i< *n; i++){
		printf("\nNhap thong tin sach thu %d: ", i+1  );
		fflush(stdin);
		printf("\nNhap ma sach: ");
		fgets(book[i].id, 20, stdin );
		book[i].id[strlen(book[i].id) -1] = '\0' ;
		
		printf("Nhap ten sach: ");
		fgets(book[i].name, 20, stdin );
		book[i].name[strlen(book[i].name) -1] = '\0' ;
		
		printf("Nhap tac gia: ");
		fgets(book[i].author, 20, stdin );
		book[i].author[strlen(book[i].author) -1] = '\0' ;
		
		printf("Nhap the loai: ");
		fgets(book[i].category, 20, stdin );
		book[i].category[strlen(book[i].category) -1] = '\0' ;
		
		printf("Nhap gia tien: ");
		scanf("%f", &book[i].price );
	}
}

void saveInfo( Books book[], int n ){
	FILE *fptr = fopen("ss21-xs9.bin", "wb");
	for ( int i = 0; i<n ; i++){
		fwrite( &book[i], sizeof(Books), 1, fptr);
	}
	fclose(fptr);
	printf("\nDa luu thanh cong!");
}

void getInfo( Books book[], int n ){
	FILE *fptr = fopen("ss21-xs9.bin", "rb");
	for ( int i = 0; i<n ; i++){
		fread( &book[i], sizeof(Books), 1, fptr);
	}
	fclose(fptr);
	printf("\nDa lay du lieu thanh cong!");
}
void showInfo( Books book[], int n ){
	printf("\nDanh sach: ");
	for ( int i = 0; i<n ; i++){
		printf("\n\n%s. %s ", book[i].id , book[i].name );
		printf("\nTac gia: %s", book[i].author );
		printf("\nThe loai: %s", book[i].category );
		printf("\nGia tien: %.2f", book[i].price );
	}
}

