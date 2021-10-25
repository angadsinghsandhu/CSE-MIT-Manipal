/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main() {
    printf("[*] Starting parent process\n");
    int r_val = fork();
    
    
    switch(r_val) {
        case -1: {
            perror("[*] fork\n");
            exit(EXIT_FAILURE);
        }
        break;

        case 0: {
            printf("[**] Inside child process\n");
            pid_t curr_ppid = getppid();
            printf("[**] Current parent: %d\n", curr_ppid);
            for(int i = 0; i < 10; i++) {
            sleep(1);
            printf("[**] Sleeping child for %d seconds...\
            n", i + 1);
            }
            curr_ppid = getppid();
            printf("[**] Current parent: %d\n", curr_ppid);
            exit(0);
        }
        break;

        default: {
            printf("[**] Executing ps\n");
            execl("/bin/ps", "ps", NULL);
            exit(0);
        }
    }
}
