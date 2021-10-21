#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
void main() 
{
    int sockfd;
    int len;
    struct sockaddr_in address;
    struct tm * timeinfo;
    int result;
    char *reply;
    int hour,mins,sec,pid;
    /*  Create a socket for the client.  */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    /*  Name the socket, as agreed with the server.  */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = 9734;
    len = sizeof(address);
    /*  Now connect our socket to the server socket. */
    result = connect(sockfd, (struct sockaddr *)&address, len);
    
    if(result == -1)
    {
        perror("oops: client2");
        exit(1);
    }
    
    /*  We can now read/write via sockfd.  */
    printf(" Sending request to get the time\n");
    read(sockfd, &hour , 1);
    read(sockfd, &mins , 1);
    read(sockfd, &sec , 1);
    read(sockfd, &pid , 1);
    printf("%d:%d:%d", hour, mins, sec);
    printf(" The process id is: %d",pid);
    close(sockfd);
    exit(0);
}
