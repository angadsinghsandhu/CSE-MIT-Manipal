#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	int rank, size, N, A[10], B[10], c, i;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	MPI_Status status;

	if(rank==0)
	{

		N = 6;
		fprintf(stdout,"Enter %d values : \n", N);
		fflush(stdout);

		for(i=0; i<N; i++)
			scanf("%d", &A[i]);
	}

	// MPI_Scatter(SendBuff, Sendcount, SendDatatype, RecvBuff, Recvcount, RecvDatatype, Root, Comm)
	MPI_Scatter(A, 1, MPI_INT, &c, 1, MPI_INT, 0, MPI_COMM_WORLD);
	fprintf(stdout, "I have received %d in process : %d\n", c, rank);

	c = c*c;
	// MPI_Gather( SendAddress, Sendcount, SendDatatype, RecvAddress, RecvCount, RecvDatatype, Root, Comm);
	MPI_Gather(&c, 1, MPI_INT, B, 1, MPI_INT, 0, MPI_COMM_WORLD);


	if(rank==0){
		fprintf(stdout, "The Result gathered in the root\n");
		fflush(stdout);

		for(i=0; i<N; i++)
			fprintf(stdout, "%d \t", B[i]);
		printf("\n");
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}