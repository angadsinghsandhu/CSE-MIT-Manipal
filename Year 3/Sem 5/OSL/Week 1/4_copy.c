// Write a program to copy character-by character copy is accomplished using
// calls to the functions referenced in stdio.h

#include<stdio.h>
#include <unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{ 
    char c;
    int inp, outp;
    if(argc != 3)
    {
        printf("Arguments less than 3");
        exit(1);
    }
    inp = open(argv[1], O_RDWR);
    outp = open(argv[2], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    if(inp == -1 || outp == -1)
    {
        printf("File cannot be opened\n");
        exit(1);
    }
    while(read(inp, &c, 1) == 1)
        write(outp, &c, 1);
    
    printf("Copied\n");
    exit(0);
}
