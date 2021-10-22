//TCP Client program

#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>

#define MAX 5
#define PORT 10200
#define SA struct sockaddr

void clifunc(int sockfd)
{
   int buff[MAX];
   int n;

   bzero(buff, sizeof(buff));
   printf("Enter the array : ");

   for(int i=0;i<MAX;i++) scanf("%d",&buff[i]);

   n = 0;
   n=write(sockfd, buff, sizeof(buff));        
   if(n==sizeof(buff))

   {    
       printf("Sent array succesfully:\n");
   }

   bzero(buff, sizeof(buff));
   n=read(sockfd, buff, sizeof(buff));
   if(n==sizeof(buff))
   {    
       printf("Received sorted array succesfully:");
       for(int i=0;i<MAX;i++) printf("%d ",buff[i]);
   }

}


int main()
{
   int sockfd, connfd;
   struct sockaddr_in servaddr, cli;


   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd == -1) {
       printf("socket creation failed...\n");
       exit(0);
   }
   else
       printf("Socket successfully created..\n");

   bzero(&servaddr, sizeof(servaddr));

   // assign IP, PORT
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
   servaddr.sin_port = htons(PORT);

   // connect the client socket to server socket
   if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
       printf("connection with the server failed...\n");
       exit(0);
   }

   else
       printf("connected to the server..\n");

   // function for client
   clifunc(sockfd);

   // close the socket
   close(sockfd);

}
