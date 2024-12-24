#include <stdio.h>
#include <string.h>

int main(){
	int n;
	printf("\nNhap so dong: ");
	scanf("%d", &n);
	fflush(stdin);
	
	FILE *fptr = fopen("bt05.txt", "w");
	
	for ( int i = 0; i<n ; i++){
		char str[100];
		printf("Nhap dong %d: ", i+1);
		fgets(str, 100, stdin);
		str[strlen(str) -1] = '\0';
		fprintf(fptr, "%s\n", str);
	}
	fclose(fptr);
	
	fptr = fopen("bt05.txt", "r");
	printf("\n\nKet qua: \n");
	for ( int i = 0; i<n ; i++){
		char str[100];
		fgets(str, 100, fptr);
		printf("Dong %d: %s", i+1, str);
	}
	
	fclose(fptr);

	return 0;
}
