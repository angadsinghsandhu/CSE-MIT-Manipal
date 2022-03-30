#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

#define BUFSIZE 100

void Error_Handler(int error_code) {
  if (error_code != MPI_SUCCESS) {
    char error_string[BUFSIZE];
    int length_of_error_string, error_class;
    MPI_Error_class(error_code, & error_class);
    MPI_Error_string(error_code, error_string, & length_of_error_string);
    printf("%d %s\n", error_class, error_string);
  }
}

int main(int argc, char* argv[])
{
	int rank, size, n, fact = 1, ans = 0;

	
	MPI_Init(&argc,&argv);
	
	int error_code;
	error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
	Error_Handler(error_code);

	error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	Error_Handler(error_code);

	for(int i=1;i<=rank;i++)
		fact *= i;

	error_code = MPI_Scan(&fact,&ans,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
	Error_Handler(error_code);

	printf("Process %d : partial sum = %d\n",rank,ans);

	MPI_Finalize();
}