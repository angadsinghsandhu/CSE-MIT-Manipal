#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int rank, size, l;
	char str[50], ch[10], str1[20], str2[20];


	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank==0)
	{
		printf("Enter String 1 (of length %d): ", size);
		scanf("%s", str1);
		printf("Enter String 2 (same length) : ");
		scanf("%s", str2);
		
		l = strlen(str1);
		printf("String 1 : %s\n", str1);		// string	
		printf("String 2 : %s\n", str2);		// length	
	} 

	// MPI_Bcast (Address, Count, Datatype, Root, Comm);
	MPI_Bcast(&l, 1, MPI_INT, 0, MPI_COMM_WORLD);

	// MPI_Scatter(SendBuff, Sendcount, SendDatatype, RecvBuff, Recvcount, RecvDatatype, Root, Comm)
	MPI_Scatter(str1, 1, MPI_CHAR, &ch[0], 1, MPI_CHAR, 0, MPI_COMM_WORLD);
	MPI_Scatter(str2, 1, MPI_CHAR, &ch[1], 1, MPI_CHAR, 0, MPI_COMM_WORLD);

	ch[2] = '\0';

	// MPI_Gather( SendAddress, Sendcount, SendDatatype, RecvAddress, RecvCount, RecvDatatype, Root, Comm);
	MPI_Gather(ch, 2, MPI_CHAR, str, 2, MPI_CHAR, 0, MPI_COMM_WORLD);

	if(rank==0){
		str[l*2] = '\0';
		printf("string is : %s\n", str);
	}


	MPI_Finalize();
	return 0;
}