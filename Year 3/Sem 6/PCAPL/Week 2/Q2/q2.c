#include<mpi.h>
#include<stdio.h>

int main(int argc, char* argv[])
{
	int size,rank,n;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Status status;

	if(rank == 0)
	{
		printf("Enter number: ");
		scanf("%d",&n);
		printf("Sending -- %d -- to all processes \n",n);

		for(int i=0;i<size-1;i++)
			MPI_Send(&n,sizeof(int),MPI_INT,i+1,0,MPI_COMM_WORLD);
	}

	else 
	{
		MPI_Recv(&n,sizeof(int),MPI_INT,0,0,MPI_COMM_WORLD,&status);
		printf("Received -- %d -- from process 0 in process %d \n",n,rank);
	}

}