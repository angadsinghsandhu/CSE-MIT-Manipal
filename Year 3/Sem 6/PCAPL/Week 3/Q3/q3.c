#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int rank, size, l, r, v=0, c, sum=0, cArr[10];
	char str[50], ch[10];


	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if(rank==0)
	{
		printf("Enter String (with length divisible by '%d') : ", size);
		scanf("%s", str);
		l = strlen(str);
	} 

	// MPI_Bcast (Address, Count, Datatype, Root, Comm);
	MPI_Bcast(&length, 1, MPI_INT, 0, MPI_COMM_WORLD);

	r = (l/size);

	// MPI_Scatter(SendBuff, Sendcount, SendDatatype, RecvBuff, Recvcount, RecvDatatype, Root, Comm)
	MPI_Scatter(str, r, MPI_CHAR, ch, r, MPI_CHAR, 0, MPI_COMM_WORLD);

	ch[r] = '\0';

	for(int i=0; i<r; i++){
		if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u' || 
			ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'I' || ch[i] == 'O' || ch[i] == 'U')
	            v++;
	}

	c = r - v;

	// MPI_Gather( SendAddress, Sendcount, SendDatatype, RecvAddress, RecvCount, RecvDatatype, Root, Comm);
	MPI_Gather(&c, 1, MPI_INT, cArr, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if(rank==0){
		for(int i=0; i<size; i++){
			printf("Number of consonents in process %d : %d\n", i, cArr[i]);
			sum += cArr[i];
		}
		printf("\nThe total Number of non-vovels are : %d\n", sum);
	}


	MPI_Finalize();
	return 0;
}