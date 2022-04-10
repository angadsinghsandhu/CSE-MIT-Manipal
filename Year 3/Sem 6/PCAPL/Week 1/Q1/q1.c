#include<mpi.h>
#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
	int size, rank;
	int x;


	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	printf("Enter x:\n");
	scanf("%d",&x);

	int ans = pow(x,rank);

	printf("Value of pow(%d,%d) from process %d is %d.\n",x,rank,rank,ans);

	MPI_Finalize();
}