#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
	int rank, size;
	float ans;

	MPI_Init(&argc,&argv);

	int error_code;
	error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
	error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	Error_Handler(error_code);

	float val = 1 + pow(((rank + 0.5)/(size - 1)),2);
	float final = 4 / (val * (size - 1));

	MPI_Reduce(&final,&ans,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);
	
	if(rank == 0)
		printf("The value of pi is : %.5f\n",ans);

	MPI_Finalize();
}