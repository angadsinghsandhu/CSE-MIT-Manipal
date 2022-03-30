#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
	int rank, size, elem, ttl_cnt, cnt=0, mat[3][3];

	MPI_Init(&argc,&argv);

	int error_code;
	error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
	Error_Handler(error_code);

	error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	Error_Handler(error_code);

	if(rank==0)
	{
		printf("Enter 3x3 Matrix : \n");
		
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				scanf("%d", &mat[i][j]);
			}
		}

		printf("Enter Element to be searched : ");
		scanf("%d", &elem);
	} 

	for(int i=0; i<3; i++)
		MPI_Bcast(mat[i], 3, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&elem, 1, MPI_INT, 0, MPI_COMM_WORLD);

	for(int j=0; j<3; j++){
		if(mat[rank][j] == elem)
			cnt++;
	}

	MPI_Reduce (&cnt, &ttl_cnt, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if(rank==0)
		printf("The count of element '%d' in Matrix is : '%d'\n", elem, ttl_cnt);
	
	MPI_Finalize();
}