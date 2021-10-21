// Program That takes C program as input, recognizes all the keywords and prints them in
// upper case.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

int main(){

	// declaring file pointers and variables
	FILE *fa;
	int ca, i=0, j, k;
	char buffer[100], ch, keywords[10][100] = {"int", "main", "if", "while", "do", "FILE", "char", "float", "continue", "break"};

	// opening files
	fa = fopen("q3.c", "r");

	// checking if file oprns
	if (fa == NULL){
		printf("Cannot open file \n");
		exit(0); 
	}

	// initializing ca
	ca = getc(fa);
	
	printf("=== Keyword Found in the Document ===\n");

	// going through the document
	while(ca != EOF){

		// skipping non alphanumeric
		if(isalpha(ca) == 0) {
			i=0;
			ca = getc(fa);
			continue;
		}
		
		// creating word
		while(isalpha(ca) != 0){
			buffer[i++] = ca;
			ca = getc(fa);
		}

		// adding null char to end
		buffer[i] = '\0';

		// matching and printing buffer
		for(j = 0; j<10; j++){
			if(strcmp(buffer, keywords[j]) == 0){
				for(k = 0; buffer[k] != '\0'; k++){
					printf("%c", toupper(ch));
				}
				printf("\n");
			}
		}
	}

	// closing files
	fclose(fa);
	return 0;
}