#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} SinhVien;

int main() {
    SinhVien sv[100];
    int n = 0; 

    FILE *fptr = fopen("students.txt", "r");
   
    while (1) {
	    int result = fscanf(fptr, "%d. %49[^-] -- %d tuoi", &sv[n].id, sv[n].name, &sv[n].age);
	
	    if (result != 3) {
	        break;
	    }
	    n++;
	}

    fclose(fptr);

    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s -- %d tuoi\n", sv[i].id, sv[i].name, sv[i].age);
    }

    return 0;
}
