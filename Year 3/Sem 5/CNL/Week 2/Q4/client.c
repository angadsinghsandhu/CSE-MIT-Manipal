/*
mplement concurrent Remote Math Server  To perform arithmetic operations in the server 
and display the result at the client. The client accepts  two integers  and anoperator 
from the user and sends it to the server. The server then receives integers andoperator. 
The server will performs the operation on integers and sends result back tothe client which 
is displayed on the client screen. Then both the processes terminate.
*/
// client side

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
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
    int sockfd,retval;char ch;
    int recedbytes,sentbytes, recans;
    struct sockaddr_in serveraddr;
    obj_ptr buffer = (obj_ptr)malloc(sizeof(obj1));
    obj_ptr buffer1 = (obj_ptr)malloc(sizeof(obj1));
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1)
        printf("\nSocket Creation Error");
    printf("\nSocket ID : %d\n",sockfd);
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
    retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    if(retval==-1)
        printf("Connection error");
    do
    {
    	printf("Do you want to request? Yes/Stop\n");
        scanf("%c",&ch);
        scanf("%[^\n]%*c",(buffer->ans));
        if(strcmp(buffer->ans,"stop")==0) 
        {
            puts("Stopping");
            sentbytes=send(sockfd,buffer,sizeof(buffer),0);
            close(sockfd);
        }
        else 
        {
        	printf("Enter in form a op b : ");
        	scanf("%lf %c %lf",&buffer->a, &buffer->op, &buffer->b);
        	sentbytes=send(sockfd,buffer,sizeof(obj1),0);
       		recedbytes=recv(sockfd,buffer1,sizeof(obj1),0);
        	printf("Result is: %.2lf \n",buffer1->r);
        }
    } while(strcmp(buffer->ans, "stop") != 0);
}