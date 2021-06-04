#include<stdio.h> 
int opcount = 0;

void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++) 
	{ 
		opcount++;
		if (arr[j] < pivot) 
		{ 
			i++;
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 

		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

int main() 
{ 
	int n;
	printf("enter total no. of elements in an array: \n");
	scanf("%d",&n);
	int arr[n];
	printf("enter elements : \n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	quickSort(arr, 0, n-1); 
	printf("Sorted array: \n"); 
	printArray(arr, n);
	printf("Opcount: %d\n", opcount); 
	return 0; 
} 