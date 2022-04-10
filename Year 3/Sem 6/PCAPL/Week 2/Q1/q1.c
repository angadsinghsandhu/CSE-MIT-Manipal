#include<mpi.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	int size,rank;
	char word[20];

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Status status;

	if(rank == 0)
	{
		printf("Enter word: ");
		scanf("%s",word);
		printf("Sending -- %s -- to process 1\n",word);
		MPI_Ssend(&word,sizeof(word),MPI_CHAR,1,0,MPI_COMM_WORLD);

		MPI_Recv(&word,sizeof(word),MPI_CHAR,1,1,MPI_COMM_WORLD,&status);
		printf("Received -- %s -- from process 1\n",word);
	}

	else if(rank == 1)
	{
		MPI_Recv(&word,sizeof(word),MPI_CHAR,0,0,MPI_COMM_WORLD,&status);
		printf("Received -- %s -- from process 0\n",word);

		for (int counter = 0; counter <= strlen(word); counter++) 
		{
        	if (word[counter] >= 'A' && word[counter] <= 'Z')
            	word[counter] = word[counter] + 32; //convert into lower case
        	else if (word[counter] >= 'a' && word[counter] <= 'z')
            	word[counter] = word[counter] - 32; //convert into upper case
    	}

    	printf("String after toggle each characters: %s\n", word);

		printf("Sending -- %s -- to process 0\n",word);
		MPI_Ssend(&word,sizeof(word),MPI_CHAR,0,1,MPI_COMM_WORLD);
	}
	MPI_Finalize();
}