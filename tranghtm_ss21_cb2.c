#include <stdio.h>

int main(){
	FILE *fptr = fopen("bt01.txt", "r");
	int ch = fgetc(fptr);
	
	printf("%c", ch);
	
	fclose(fptr);

	return 0;
}

