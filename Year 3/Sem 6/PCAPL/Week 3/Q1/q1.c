#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

int factorial(int n)
{
	int ans=1;

	for(int i=1;i<=n;i++)
		ans *= i;

	return ans;
}

int main(int argc, char* argv[])
{
	int rank, size, arr[20], recv, ans;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if(rank == 0)
	{
		printf("Enter %d numbers : ",size);

		for(int i=0;i<size;i++)
			scanf("%d",&arr[i]);
	}

	MPI_Scatter(arr,1,MPI_INT,&recv,1,MPI_INT,0,MPI_COMM_WORLD);

	int fact = factorial(recv);

	printf("Process %d : received %d from root process, factorial of received number is %d.\n",rank,recv,fact);

	MPI_Reduce(&fact,&ans,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

	if(rank == 0)
		printf("The sum of all factorials computed is %d.\n",ans);

	MPI_Finalize();
}