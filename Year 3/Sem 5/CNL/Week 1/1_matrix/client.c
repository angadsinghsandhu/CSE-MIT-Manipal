// UDP client-server program where client sends rows 
// of a matrix to the server combines them together as a 
// two dimensional matrix and display the same.
// Client Side

/* 
FIXME : This code might be a little incomplete, 
FIXME : One possible fix is to send the marix by encoding 
FIXME : it as a string by fixing the first two letters in the string 
FIXME : as the dimention of the matrix followed by the rest of the matrix.
*/

#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT 5000
#define MAXLINE 1000

int main()
{
	char buffer[100];
	//char *message = "Hello Server";
	
	int sockfd, n,len;
	struct sockaddr_in servaddr, cliaddr;
	
	//using a square matrix of 3*2
	int row=0;
	printf("Enter the elements of the first row\n");
	int a ,b, c;
	scanf("%d %d %d",&a,&b, &c);
	
	printf("Enter the elements of the second row \n");
	int d ,e, f;
	scanf("%d %d %d",&d ,&e, &f);

	// clear servaddr
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	servaddr.sin_family = AF_INET;
	
	char message[5];

	message[0]=a+'0';
	message[1]=b+'0';
	message[2]=c+'0';
	message[3]=d+'0';
	message[4]=e+'0';

	// create datagram socket
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	sendto(sockfd, message, MAXLINE, 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
	len=sizeof(cliaddr);
    
    // waiting for response
	n=recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cliaddr,&len );
    buffer[n]='\0';
	printf("Message from Server is \n");
	
	//Just chck if it gives correct outpur or not , connection is already esablished 
	for(int i=0;i<3;i++)
	{	//hardcoded till 3 
		printf("The %d th element of the matrix is :- %d \n",i,buffer[i]);
	}
	
	getchar();
	
	// close the descriptor
	close(sockfd);

	return 0;
}