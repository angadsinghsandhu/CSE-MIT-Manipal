#include "mpi.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
	int rank,size,x;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;

	if(rank==0)
	{
		printf("Enter a value in master process: ");
		scanf("%d",&x);

		// MPI_Send
		// (&Msg, Count, Datatype, Destination, Tag, Comm);
		MPI_Send(&x,1,MPI_INT,1,1,MPI_COMM_WORLD);
		fprintf(stdout,"I have sent %d from process 0\n",x);
		fflush(stdout);
	}
	else
	{
		// MPI_Recv
		// (&Msg, Count, Datatype, Source, Tag, Comm, &status);
		MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"I have received %d in process 1\n",x);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}