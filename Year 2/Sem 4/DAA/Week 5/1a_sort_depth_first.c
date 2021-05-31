// Q1a
#include<stdio.h>
#include<stdlib.h>
#define Max_Size 50

int opcount = 0, n;

typedef struct {
	int arr[Max_Size];
	int top;
} stk;

void init(stk *s)
{
	s->top = -1;
}

int isEmpty(stk *s)
{
	if (s->top == -1)
		return 1;

	return 0;
}

void push(stk *s, int item)
{
	if (s->top == Max_Size - 1)
	{
		printf("stkueue Overflow");
		exit(0);
	}

	s->arr[++s->top] = item;
}

int pop(stk *s)
{
	if (!isEmpty(s))
		return (s->arr[s->top++]);

	return -1;
}

void display(stk *s)
{
	printf("\n");

	for (int i = s->top; i >= 0; i--)
		printf("%d\t", s->arr[i]);
}

int isPresent(stk *s, int j)
{
	for (int i = s->top; i >= 0; i--)
		if (s->arr[i] == j)
			return 1;

	return 0;
}
void top_sort_dfs(int i, int visited[], int a[][n], stk *s)
{
	int j;
	visited[i] = 1;

	for (j = 0; j < n; j++) 
	{
		opcount++;
		if (!visited[j] && a[i][j] == 1)
			top_sort_dfs(j, visited, a, s);
	}
	
	push(s, i);
}

int main()
{
	int i, j;
	printf("Enter number of vertices : ");
	scanf("%d", &n);
	
	int a[n][n], visited[n];
	printf("\nEnter adjecency matrix of the graph : \n");
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) 
		{
			//printf("\n %d and %d  ",i,j);
			scanf("%d", &a[i][j]);
		}

	for (i = 0; i < n; i++)
		visited[i] = 0;
	
	printf("\nEnter the node to start: ");
	int p;
	scanf("%d", &p);
	
	stk s;
	init(&s);
	
	top_sort_dfs(p, visited, a, &s);
	
	for (j = 0; j < n; j++)
		if (visited[j] == 0)
			top_sort_dfs(j, visited, a, &s);

	display(&s);

	printf("\n\n\nOperation Count=%d", opcount);
	return 0;
}