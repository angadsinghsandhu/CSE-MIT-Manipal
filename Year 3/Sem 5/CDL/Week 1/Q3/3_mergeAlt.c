// Program to merge 2 files alternatively

#include <stdio.h>
  
int main()
{
	FILE *fa, *fb, *fr;
	fa = fopen("q3a.c", "r");
	fb = fopen("q3b.c", "r");
    fr = fopen("q3res.c", "w+");

	int ca, cb, flag=1;

	ca = getc(fa);
    cb = getc(fb);

    while(ca != EOF && cb != EOF){
        // printf("flag : %d\n", flag);
        if(flag==1){
            while(ca != '\n'){
                putc(ca, fr);
                ca = getc(fa);
            }
            putc(ca, fr);
            ca = getc(fa);
            flag=2;
        } else {
            while(cb != '\n'){
                putc(cb, fr);
                cb = getc(fb);
            }
            putc(cb, fr);
            cb = getc(fb);
            flag=1;
        }
    }

    while(!feof(fa)){
        putc(ca, fr);
        ca = getc(fa);
    }

    while(!feof(fb)){
        putc(cb, fr);
        cb = getc(fb);
    }

    
    fclose(fa);
    fclose(fb);
    return 0;
}