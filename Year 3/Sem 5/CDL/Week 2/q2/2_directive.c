// Program to discard preprocessor directives from the given input ‘C’ file.

#include <stdio.h>
#include <stdlib.h>

int main(){
	// declaring file pointers and variables
	FILE *fa, *fa_, *fb;
	int ca, ca_, flag_1 = 0, flag_2 = 0;

	// opening files
	fa = fopen("q2_src.c", "r");
	fa_ = fopen("q2_src.c", "r");
	fb = fopen("q2_res.c", "w+");

	// checking if file oprns
	if (fa == NULL){
		printf("Cannot open file \n");
		exit(0); 
	}

	// initializing ca
	ca = getc(fa);

	// initializing ca_
	ca_ = getc(fa_);

	// going through the document
	while(ca != EOF){

		// check if '#' is encountered
		if(ca == '#'){

			// check if it is actually a directive
			while(ca_ != '\n'){
				if(ca_ == '<') flag_1 = 1;
				if(ca_ == '>') flag_2 = 1;
				ca_ = getc(fa_);
			}

			ca_ = getc(fa_);


			if(flag_1==1 && flag_2==1){		// removing directive
				flag_2 = 0;
				flag_1 = 0;

				while(ca != '\n'){
					ca = getc(fa);
				}

				ca = getc(fa);
				continue;
			} else {						// keeping sentence with #
				flag_2 = 0;
				flag_1 = 0;

				while(ca != '\n'){
					putc(ca, fb);
					ca = getc(fa);
				}

				putc(ca, fb);
				ca = getc(fa);
				continue;
			}
		}

		// keeping all other charaters
		putc(ca, fb);
		ca = getc(fa);
		ca_ = getc(fa_);
	}

	// closing files
	fclose(fa);
	fclose(fa_);
	fclose(fb);
	return 0;
}