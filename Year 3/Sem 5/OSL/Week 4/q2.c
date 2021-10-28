#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h> 
#include <grp.h>

void help() { 
    printf("USAGE: stat [name_of_file]\n");
}


void pp(int r_val, char * str) { 
    if ( r_val == 0 ) { 
        printf("-");
    } else { 
        printf("%s", str);
    }
}

void print_filetype(mode_t m) { 
    if ( S_ISREG(m) ) { 
        printf("Regular file");
    } else if ( 
        S_ISDIR(m) ) { printf("Directory");
    } else if ( 
        S_ISCHR(m) ) { printf("Character device");
    } else if ( 
        S_ISBLK(m) ) { printf("Block device");
    } else if ( 
        S_ISFIFO(m) ) { printf("Named pipe");
    } else if ( 
        S_ISLNK(m) ) { printf("Symbolic link");
    } else if ( 
        S_ISSOCK(m) ) { printf("Socket");
    }
}


int main(int argc, char * argv[]) { 
    if ( argc != 2 ) { 
        help(); 
        exit(EXIT_FAILURE);
    }

    struct stat curr_stat; 
    struct passwd * file_usr = NULL; 
    struct group * file_grp = NULL; 
    int r_val = lstat( argv[1], &curr_stat );

    if ( r_val < 0 ) { 
        perror("lstat"); 
        exit(EXIT_FAILURE);
    }

    mode_t m = curr_stat.st_mode;
    printf("Inode number: %ld\n", curr_stat.st_ino); 
    printf("Device id: %ld\n", curr_stat.st_dev); 
    printf("Mode: %d\n", m); 
    printf("File permissions: "); 
    
    pp( m & S_IRUSR, "r" ); 
    pp( m & S_IWUSR, "w" ); 
    pp( m & S_IXUSR, "x" ); 
    pp( m & S_IRGRP, "r" ); 
    pp( m & S_IWGRP, "w" ); 
    pp( m & S_IXGRP, "x" ); 
    pp( m & S_IROTH, "r" ); 
    pp( m & S_IWOTH, "w" ); 
    pp( m & S_IXOTH, "x" ); 
    
    printf("\n"); 
    printf("File type: "); 
    print_filetype(m); 
    printf("\n");

    file_usr = getpwuid(curr_stat.st_uid);
    
    if ( file_usr == NULL ) { 
        perror("getpwuid"); exit(EXIT_FAILURE);
    }
    
    file_grp = getgrgid(curr_stat.st_gid); 
    
    if ( file_grp == NULL ) { 
        perror("getgrgid"); 
        exit(EXIT_FAILURE);
    }

    printf("UID: %d(%s)\n", curr_stat.st_uid, file_usr->pw_name); 
    printf("GID: %d(%s)\n", curr_stat.st_gid, file_grp->gr_name); 
    printf("Size: %ld bytes\n", curr_stat.st_size); 
    printf("Block size: %ld\n", curr_stat.st_blksize); 
    printf("No of blocks used: %ld\n", curr_stat.st_blocks); 
    printf("Last access time: %s", ctime(&curr_stat.st_atime)); 
    printf("Last modified time: %s", ctime(&curr_stat.st_mtime));
    printf("Last status change time: %s", ctime(&curr_stat.st_ctime)); 
    free(file_usr); 
    free(file_grp);
}
