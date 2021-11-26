// Demonstrate creation, writing to, and reading from a pipe.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
 
int main(int argc, char *argv[])
{
    int n, i=0;
    int fd[2];
    char buf[1025];
    char *data = "Hello How Are You";

    // creating
    pipe(fd);

    // Writing
    while(i<strlen(data)){
        write(fd[1],data,strlen(data));
        i++;
    }
    
    // reading
    i=0;
    while(i<strlen(data)){
        if(n=read(fd[0],buf,1024)>=0)
        {
            buf[n]='\0';
            printf("Read %d bytes from pipe\"%s\"\n",n,buf);
        } else
            perror("Read");
        exit(0);
        i++;
    }
}