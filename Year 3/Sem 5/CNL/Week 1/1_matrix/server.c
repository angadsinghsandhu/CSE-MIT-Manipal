// UDP client-server program where client sends rows 
// of a matrix to the server combines them together as a 
// two dimensional matrix and display the same.
// Server Side

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



#define PORT 5000
#define MAXLINE 1000

int main()
{
	char buffer[100];
	int serversockfd, len, n;
	struct sockaddr_in servaddr, cliaddr;
	bzero(&servaddr, sizeof(servaddr));



	// Create a UDP Socket
	servsockfd = socket(AF_INET, SOCK_DGRAM, 0);		
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	servaddr.sin_family = AF_INET;


	// bind server address to socket descriptor
	bind(servsockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	
	//receive the datagram
	len = sizeof(cliaddr);  
	n = recvfrom(servsockfd, buffer, sizeof(buffer),0, (struct sockaddr*)&cliaddr,&len);
	buffer[n] = '\0';
	puts(buffer);
	
	//Echoing back to the client
    sendto(servsockfd, buffer, n, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr));
    getchar();
	
	// close the descriptor
	//close(servsockfd);

	return 0;
}