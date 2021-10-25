/*
Concurrent Severs : Write a TCP concurrent Echo server and simple client.
*/

// client side
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>
#include<arpa/inet.h>

#include <unistd.h>
#include <netdb.h>


int main(){
    int len,result,sockfd,n=1;
    struct sockaddr_in address;
    char ch[256],buf[256];

    //Create a socket for the client

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //Name the socket as agreed with the server
    address.sin_family=AF_INET;
    address.sin_addr.s_addr=inet_addr("172.16.57.237"); // **
    address.sin_port=htons(10200);
    len = sizeof(address);
    
    //Connect your socket to the server’s socket
    result=connect(sockfd,(struct sockaddr *)&address,len);

    if(result==-1){        
        perror("\nCLIENT ERROR");
        exit(1);
    }

    //You can now read and write via sockfd (Logic for problem mentioned here)
    printf("\nENTER STRING\t");
    fgets(ch, 256, stdin);
    ch[strlen(ch)]='\0';
    write(sockfd,ch,strlen(ch));
    printf("STRING SENT BACK FROM SERVER IS .....");

    while(n){ 
        n=read(sockfd,buf,sizeof(buf)); 
        puts(buf);
    }
}

// **- indicates replace this address with your systems IP address

