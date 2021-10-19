// Demonstrate the use of different conversion specifiers and resulting output
// to allow the items to be printed.

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main()
{
    int a = 133;
    float b = 42.56;
    char c = 'q';
    char s[] = "This is a string";
    
    printf(" int = %d\n float = %f\n char = %c\n string = %s\n hex for int = %x\n exp for float = %e\n", a, b, c, s, a, b);
        
    return 0;
}
