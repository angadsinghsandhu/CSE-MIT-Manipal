#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	int size, rank;
	int x = 10,y = 5,ans=0;

	// if(argc != 4)
	// {
	// 	printf("Code is meant to run with 4 process only.\n");
	// 	exit(0);
	// }

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank == 0)
	{
		ans = x+y;
		printf("Process %d : Sum = %d.\n",rank,ans);
	}
	else if(rank == 1)
	{
		ans = x-y;
		printf("Process %d : Difference = %d.\n",rank,ans);
	}
	else if(rank == 2)
	{
		ans = x*y;
		printf("Process %d : Product = %d.\n",rank,ans);
	}
	else if(rank == 3)
	{
		ans = x/y;
		printf("Process %d : Ratio = %d.\n",rank,ans);
	}

	MPI_Finalize();
}