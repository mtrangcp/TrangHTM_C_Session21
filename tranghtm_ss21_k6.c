#include <stdio.h>
#include <string.h>

int main(){
	char ch ;
	FILE *fptr1, *fptr6 ;
	fptr1 = fopen("bt01.txt", "r");
	fptr6 = fopen("bt06.txt", "w");
	
	while (1) {
		ch = fgetc(fptr1);
		if (ch == EOF) {
	        break; 
	    }
        fputc(ch, fptr6);
    }
	
	fclose(fptr1);
	fclose(fptr6);

	return 0;
}

