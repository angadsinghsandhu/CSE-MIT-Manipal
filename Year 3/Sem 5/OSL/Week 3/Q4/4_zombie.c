/*
Create a zombie hild process, 
and allow the init process to adopt it. 
Run the process as a background process 
and run the "ps" command 
*/

// imports
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main() {

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

            // getting and printing PID
            pid_t curr_ppid = getppid();
            printf("[**] Current parent: %d\n", curr_ppid);

            // Sleeping...
            for(int i = 0; i < 10; i++) {
                sleep(1);
                printf("[**] Sleeping child for %d seconds...\n", i + 1);
            }

            // getting and printing PID
            curr_ppid = getppid();
            printf("[**] Current parent: %d\n", curr_ppid);

            // exiting from the child program
            exit(0);
        }
        break;

        // in case of parent class
        default: {
            // showing the current running process
            printf("[**] Executing ps\n");
            execl("/bin/ps", "ps", NULL);

            // exiting from the parent program
            exit(0);
        }
    }
}