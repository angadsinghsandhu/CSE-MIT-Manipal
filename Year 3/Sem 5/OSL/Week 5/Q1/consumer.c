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
    int open_mode=O_RDONLY;
    int n=0;
    char buffer[BUFFER_SIZE+1];
    memset(buffer,'\0',sizeof(buffer));
    
    printf("Process %d opening FIFO O_RDONLY\n",getpid());
    pipe_fd=open(FIFO_NAME,open_mode);
    printf("Process %d result %d\n",getpid(),pipe_fd);
    
    if (pipe_fd!=-1)
    {
        do
        {
            res=read(pipe_fd,buffer,BUFFER_SIZE);
            printf("%s\n",buffer );
            n++;
        }while(n<4);
        
        (void)close(pipe_fd);
    }
    
    else
        exit(EXIT_FAILURE);
    
    printf("Process %d Finished, %d bytes read\n",getpid(),n );
    exit(EXIT_SUCCESS);
}