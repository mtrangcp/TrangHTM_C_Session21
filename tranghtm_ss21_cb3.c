#include <stdio.h>
#include <string.h>

int main(){
	char str[100];
	printf("\nNhap text: ");
	fgets(str, 100, stdin);
	str[strlen(str) -1] = '\0' ;
	
	FILE *fptr = fopen("bt01.txt", "a");
	fprintf(fptr, "\n%s", str);
	
	fclose(fptr);

	return 0;
}

