#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void help() { 
    printf("USAGE: inode [name_of_file]\n");
}

int main(int argc, char * argv[]) { 
    if ( argc != 2 ) { 
        help(); 
        exit(EXIT_FAILURE);
    }

    struct stat curr_stat;
    int r_val = lstat( argv[1], &curr_stat ); 
    
    if ( r_val < 0 ) { 
        perror("lstat"); 
        exit(EXIT_FAILURE);
    }
    printf("Inode number: %ld\n", curr_stat.st_ino);

}
