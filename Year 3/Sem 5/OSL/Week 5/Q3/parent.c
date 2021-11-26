/*
Write a C program to implement one side of FIFO.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<limits.h>
#include<fcntl.h>
#include<sys/msg.h>
#include<sys/stat.h>
#include<string.h>
 
 
#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 10000
 

int main(int argc, char *argv[])
{
    int pipe_fd;
    int res;
    int open_mode1=O_WRONLY;
    int open_mode2=O_RDONLY;
    int n=0;
    char buffer[BUFFER_SIZE+1];
    
    if(access(FIFO_NAME,F_OK)==-1)
    {
        res=mkfifo(FIFO_NAME,0777);
        
        if(res!=0)
        {
            fprintf(stderr, "Could not create file%s\n",FIFO_NAME);
            exit(EXIT_FAILURE); 
        }
    }
        
    printf("You can start chatting with User 2 now\n");
    
    while(1)
    {
        pipe_fd=open(FIFO_NAME,open_mode2);
        
        printf("\nText from User 1:  ");
        res=read(pipe_fd,buffer,BUFFER_SIZE);
        printf("%s\n",buffer );
        close(pipe_fd);
        
        printf("Wait for User 1 reply...\n");
        pipe_fd=open(FIFO_NAME,open_mode1);
        
        printf("\nEnter Text to send User 1:  ");
        fgets(buffer,BUFFER_SIZE,stdin);
        res=write(pipe_fd,buffer,BUFFER_SIZE);
        
        close(pipe_fd); 
        
    
    }
    
    (void)close(pipe_fd);
    
    
    printf("Process %d Finished\n",getpid());
    exit(EXIT_SUCCESS);
}