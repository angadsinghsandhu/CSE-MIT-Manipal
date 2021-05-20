#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int ans[1000], min = INT_MAX, opcount1 = 0, opcount2 = 0;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int r, int arr[][r + 1], int per[], int l)
{
	int i;
	if (l == r)
	{
		int sum = 0;
		for (i = 0; i <= r; i++)
		{
			opcount2++;
			int idx = per[i];
			sum += arr[i][idx];
		}
		if (sum < min)
		{
			for (i = 0; i <= r; i++)
			{
				int idx = per[i];
				ans[i] = arr[i][per[i]];
			}
			min = sum;
		}
	}
	else
	{
		for (i = l; i <= r; i++)
		{
			opcount1++;
			swap((per + l), (per + i));
			permute(r, arr, per, l + 1);
			swap((per + l), (per + i));
		}
	}
}

int main()
{
	int i, j, n;
	printf("Enter the size of the square matrix : ");
	scanf("%d", &n);
	int arr[n][n];
	printf("Enter the matrix : \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
			// arr[i][j]=1;
	}
	int per[n];
	for (i = 0; i < n; i++)
		per[i] = i;
	permute(n - 1, arr, per, 0);
	printf("Combination for minimum cost : ");
	for (i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\nThe Minimum Cost is : %d\n", min);
	printf("Opcount = %d\n", opcount1 > opcount2 ? opcount1 : opcount2);
	return 0;
}