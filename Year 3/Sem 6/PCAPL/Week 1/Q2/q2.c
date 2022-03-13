#include<mpi.h>
#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
	int size, rank;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank % 2 == 0)
	{
		printf("Process %d : Hello\n",rank);
	}

	else
		printf("Process %d : World\n",rank);



	MPI_Finalize();
}