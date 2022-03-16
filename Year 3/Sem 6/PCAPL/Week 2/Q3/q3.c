#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	int size,rank,arr[50],n;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Status status;

	if(rank == 0)
	{
		printf("Enter array of size %d : ",size);

		for(int i=0;i<size;i++)
			scanf("%d",&arr[i]);

		n = arr[size-1];

		int bSize = MPI_BSEND_OVERHEAD + sizeof(arr);
		int* buf = (int*)malloc(bSize);

		MPI_Buffer_attach(buf,bSize);
		for(int i=0;i<size-1;i++)
			MPI_Bsend(&arr[i],1,MPI_INT,i+1,0,MPI_COMM_WORLD);

		MPI_Buffer_detach(&buf,&bSize);
	}
	else 
	{
		int num;
		MPI_Recv(&num,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);

		if(rank % 2 == 0)
			printf("Process %d : received %d from root process, after squaring : %d\n",rank,num,num*num);

		else
			printf("Process %d : received %d from root process, after cubing : %d\n",rank,num,num*num*num);

	}

	MPI_Finalize();
}