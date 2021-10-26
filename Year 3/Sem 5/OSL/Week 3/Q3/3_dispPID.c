/*
Program to create a child process. 
Display the process IDs of the process, 
parent and child(s) in both the 
parent and child process.
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
            pid_t curr_pid = getpid();
            printf("[**] PID of child process: %d\n", curr_pid);
            
            // exiting from the parent program
            exit(0);
        }
        break;

        // in case of parent class
        default: {
            // getting and printing PID
            pid_t curr_pid = getpid();
            printf("[*] PID of parent process: %d\n", curr_pid);
            

            // waiting for child process to finish executing
            printf("[*] Waiting for child\n");
            wait(NULL);
            printf("[*] Child process finished execution\n");
            
            // exiting from the parent program
            exit(0);
        }
    }
}