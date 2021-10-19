/*
TCP client which sends a string to a server program. 
Server displays the string along with client IP and ephemeral 
port number. Server then responds to the client by echoing back 
the string in uppercase. The process continues until one of them types “QUIT”.
*/
// Client Side


#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#include <ctype.h> 
#include <string.h>

#define MAX 50


void clifunc(int sockfd)
{
	//send string
	//print returned string
	//if returned string is quit, quit
	
	char buff[MAX];
	int n=0,recv_len=0;
	
	while(1)
	{
		memset(buff,0,sizeof(buff));
		printf("Type message\n");
		//while((buff[n++]=getchar())!='\n');
		scanf("%s",buff);
		write(sockfd,buff,sizeof(buff));
		
		if(strcmp("quit",buff)==0)
		{
			printf("client closing\n");
			return;
		}
		
		memset(buff,0,sizeof(buff));
		n=read(sockfd,buff,sizeof(buff));
		buff[n]='\n';
		printf("%s\n",buff );
	}
	}


int main(int argc, char const *argv[])
{
	int sockfd;
    int len;
    struct sockaddr_in server_address;
    int result;
    char ch;

    sockfd=socket(AF_INET,SOCK_STREAM,0);

    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_address.sin_port=htons(7280);
    len=sizeof(server_address);

    result=connect(sockfd,(struct sockaddr*)&server_address,len);
    
    if(result == -1)
    {
    	printf("connection error\n");
    	exit(0);
    }


    clifunc(sockfd);
    close(sockfd);

    return 0;
	
}