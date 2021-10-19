// Program to reverse a file and store it in another file

#include <stdio.h>
  
int main()
{
	FILE *fa, *fb;
	fa = fopen("q2a.c", "r");
	fb = fopen("q2b.c", "w+");

	int ca;
	long int pos;

	// Moving pointer to end
    fseek(fa, -1, SEEK_END);

    // Getting position of last pos
    pos = ftell(fa);

    // printing size of file
    printf("Size of File : %ld\n", pos);

    while(pos >= 0){
    	ca = getc(fa);
    	putc(ca, fb);

    	// Moving pointer to a one position back
    	pos--;
    	fseek(fa, pos, SEEK_SET);
    }

    // Moving pointer to end
    fseek(fa, 0, SEEK_END);

    
    fclose(fa);
    fclose(fb);
    return 0;
}


