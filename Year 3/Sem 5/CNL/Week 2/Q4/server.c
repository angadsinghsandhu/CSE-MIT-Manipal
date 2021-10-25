/*
mplement concurrent Remote Math Server  To perform arithmetic operations in the server 
and display the result at the client. The client accepts  two integers  and anoperator 
from the user and sends it to the server. The server then receives integers andoperator. 
The server will performs the operation on integers and sends result back tothe client which 
is displayed on the client screen. Then both the processes terminate.
*/
// server side

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#define MAXSIZE 150
#define PORT 5000
#define MAXLINE 1000

typedef struct obj 
{
    double a,b,r;
    char op;
    char ans[10];
} obj1,*obj_ptr;

void main()
{
    int sockfd,newsockfd,retval;
    socklen_t actuallen;
    int recedbytes,sentbytes, sentans;
    struct sockaddr_in serveraddr,clientaddr;
    obj_ptr buffer = (obj_ptr)malloc(sizeof(obj1));
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1)
        printf("\nSocket creation error");
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
    bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    puts("Server Running");
    listen(sockfd,1);
    actuallen=sizeof(clientaddr);
    newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen); 
    do
    {
        recv(newsockfd,buffer,sizeof(obj1),0);
        if(strcmp(buffer->ans, "stop") == 0)
        {
            puts("Stopping");
            close(sockfd);
            close(newsockfd);
        }
        else
        {
            printf("Client [%s:%d] requested: %.2lf %c %.2lf\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port), buffer->a, buffer->op, buffer->b);
            switch (buffer->op)
            {
                case '+': buffer->r = buffer->a + buffer->b;
                    break;
                case '-': buffer->r = buffer->a - buffer->b;
                    break;
                case '*': buffer->r = buffer->a * buffer->b;
                    break;
                case '/': buffer->r = buffer->a / buffer->b;
                    break;
                case '%': buffer->r = buffer->a / buffer->b;
                    break;
                default:
                    break;
            }
            sentbytes = send(newsockfd,buffer,sizeof(obj1),0);
        }
   } while(strcmp(buffer->ans, "stop") != 0);
}