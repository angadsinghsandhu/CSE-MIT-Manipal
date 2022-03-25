#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	int rank, size, arr[50], recv[20], n;
	float avg, sum;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	if(rank == 0)
	{
		printf("Enter a number : ");
		scanf("%d",&n);

		printf("Enter %d elements : ",n*size);
		for(int i=0;i<n*size;i++)
			scanf("%d",&arr[i]);
	}

	MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(arr,n,MPI_INT,recv,n,MPI_INT,0,MPI_COMM_WORLD);

	for(int i=0;i<n;i++)
		avg += recv[i];

	avg /= n;

	printf("Average of values in process %d : is %f.\n",rank,avg);

	MPI_Reduce(&avg,&sum,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);

	sum /= size;

	if(rank == 0)
		printf("Total average of all values is %f.\n",sum);

	MPI_Finalize();
}