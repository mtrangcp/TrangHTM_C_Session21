#include <stdio.h>
#include <string.h>


typedef struct{
	int id;
	char name[50] ;
	int age ;
} SinhVien;

int main(){
	int n ;
	printf("\nNhap so luong: ");
	scanf("%d", &n);
	
	SinhVien sv[100];
	
	FILE *fptr = fopen("students.txt", "w");
	
	for ( int i = 0; i<n ; i++ ){
		printf("\nNhap thong tin sv thu %d: ", i+1);
		sv[i].id = i+1;
		
		fflush(stdin);
		printf("\nTen: ");
		fgets(sv[i].name , 50, stdin);
		sv[i].name[strlen(sv[i].name) -1 ] = '\0' ;
		
		printf("Tuoi: ");
		scanf("%d", &sv[i].age);
		
		fprintf(fptr, "%d. %s -- %d tuoi \n", sv[i].id, sv[i].name, sv[i].age );
	}
	
	fclose(fptr);

	return 0;
}

