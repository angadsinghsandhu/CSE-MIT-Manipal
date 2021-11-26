/*
Write a producer and consumer program in C using the FIFO queue. 
The producer should write a set of 4 integers into the FIFO queue 
and the consumer should display the 4 integers.
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
#define BUFFER_SIZE 1000
 
 
int main(int argc, char *argv[])
{
    int pipe_fd;
    int res;
    int open_mode=O_WRONLY;
    int n=0;
    char buffer[BUFFER_SIZE+1];
    
    if(access(FIFO_NAME,F_OK)==-1)
    {
        res=mkfifo(FIFO_NAME,0777);
        if(res!=0)
        {
            fprintf(stderr, "Could not create file%s\n",FIFO_NAME );
            exit(EXIT_FAILURE);    
        }
    }
    
    printf("Process %d opening FIFO O_WRONLY\n",getpid());
    pipe_fd=open(FIFO_NAME,open_mode);
    printf("Process %d result %d\n",getpid(),pipe_fd);
    
    if (pipe_fd!=-1)
    {
        printf("Enter 4 numbers\n");
        
        while(n<4)
        {
            scanf("%s",buffer);
            res=write(pipe_fd,buffer,BUFFER_SIZE);
            
            if(res==-1)
            {
                fprintf(stderr, "Write Error on Pipe\n");
                exit(EXIT_FAILURE);
            }
            n++;
        }
        (void)close(pipe_fd);
    }
    else
        exit(EXIT_FAILURE);
    
    printf("Process %d Finished\n",getpid() );
    exit(EXIT_SUCCESS);
 
}