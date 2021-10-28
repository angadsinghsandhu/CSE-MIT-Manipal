#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include <unistd.h>


void help() { 
    printf("USAGE: symlink [name_of_file] [name_of_destination_file]\n");
}

int main(int argc, char * argv[]) { 
    if ( argc != 3 ) { 
        help();
        exit(EXIT_FAILURE);
    }

    int r_val = symlink(argv[1], 
    argv[2]);

    if ( r_val < 0 ) { 
        perror("link"); 
        exit(EXIT_FAILURE);
    } 
    
    char * path = realpath(argv[2], NULL);

    if ( path == NULL ) { 
        perror("realpath"); 
        exit(EXIT_FAILURE);
    } 
    
    printf("Path to hard link: %s\nEnter to exit: ", path); 
    getc(stdin);
    
    r_val = unlink(argv[2]); 
    
    if ( r_val < 0 ) {
        perror("unlink"); 
        exit(EXIT_FAILURE);
    }
    
    free(path);
}
