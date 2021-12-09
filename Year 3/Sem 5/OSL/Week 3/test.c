/*
C Program to block a parent process, until 
the child completes using a wait system call 
*/

// imports
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main() {
    int fd, res, n, i, num;
    char buffer[100], ch;

    res = open("loc", O_RDWR);

    if (res == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // creating child and parent process 
    // storing process id in `r_val`
    printf("[*] Starting parent process\n");
    int r_val = fork();

    // switching between different processes
    switch(r_val) {
        
        // in case some error occurs in creation
        case -1: {
                perror("[*] fork\n");
                exit(EXIT_FAILURE);
            }
            break;
        
        // in case of child process
        case 0: {
                printf("[**] Inside child process\n");

                strcpy(buffer, "1 2 3 4");

                // adding values to the file descriptor
                write(fd, buffer, sizeof(buffer));

                // exiting from the child program
                exit(0);
            }
            break;

        // in case of parent class
        default: {
                printf("[*] Waiting for child\n");

                // waiting for child process to finish executing
                wait(NULL);
                printf("[*] Child process finished execution\n");

                bzero(buffer, sizeof(buffer));

                n = read(fd, buffer, sizeof(buffer));
                buffer[n] = '\0';

                for(i=0; i<n; i++) {
                    ch = buffer[i];
                    if(ch == ' ') {
                        printf("\n");
                    } else {
                        num = (int) ch - 48;
                        printf("%d", num);
                    }
                }

                while(ch != '\0') {
                    
                }

                printf("[*] %s\n", buffer);
                
                // exiting from the parent program
                exit(0);
            }
    }
}

