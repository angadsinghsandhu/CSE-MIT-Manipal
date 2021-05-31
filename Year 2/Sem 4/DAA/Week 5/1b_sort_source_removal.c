#include <stdio.h>
#include <stdlib.h>

int n;
int **adjacency_matrix;
int *visited;

void topologicalSort(int **adjacency_matrix)
{
	int i, j, k;
	for (j = 0; j < n; j++)
	{
		if (visited[j] == 0)
		{
			i = 0;
			while (i < n)
			{
				if (adjacency_matrix[i][j] == 1)
					break;
				i++;
			}
			if (i == n)
			{
				visited[j] = 1;
				printf("%d   ", j);
				for (k = 0; k < n; k++)
				{
					adjacency_matrix[j][k] = 0;
				}
				topologicalSort(adjacency_matrix);
			}
			if (i < n)
			{
				continue;
			}
		}
	}
}

int main()
{
	printf("Enter the number of vertices\n");
	scanf("%d", &n);
	adjacency_matrix = (int **)calloc(n, sizeof(int *));
	visited = (int *)calloc(n, sizeof(int));
	int i, j;
	for (i = 0; i < n; ++i)
	{
		visited[i] = 0;
		adjacency_matrix[i] = (int *)calloc(n, sizeof(int));
	}
	printf("Enter the adjacency_matrix\n");
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			scanf("%d", &adjacency_matrix[i][j]);
		}
	}
	printf("The Topological Sort:\n");
	topologicalSort(adjacency_matrix);

	return 0;
}
