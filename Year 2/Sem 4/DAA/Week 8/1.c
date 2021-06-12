// Q1
#include <stdio.h> 
#include <stdlib.h> 

int opCount = 0;
void HeapTopDown(int nameArray[], int startingIndex)
{
    int parentalDominance = (startingIndex - 1) / 2;
    while (parentalDominance >= 0)
    {
        opCount++;
        if (nameArray[parentalDominance] < nameArray[startingIndex])
        {
            int temp = nameArray[parentalDominance];
            nameArray[parentalDominance] = nameArray[startingIndex];             
            nameArray[startingIndex] = temp;
            startingIndex = parentalDominance;             
            parentalDominance = (startingIndex - 1) / 2;
        } else
            return;
    }
} 

void main() {
    int heapArray[20];     
    int size;     
    int i;     
    int j;

    printf("Enter the size of elements : ");
    scanf("%d", &size);    
    printf("Enter the elements : ");     
    
    for (i = 0; i < size; i++) {
        scanf("%d", &heapArray[i]);         
        printf("\n");
        printf("The Array is getting in Heap : \n\n");
        HeapTopDown(heapArray, i);         
        for (j = 0; j <= i; j++)             
        printf("%d ", heapArray[j]);
        printf("\n");
    }     
    
    printf("\n\n");
    printf("Orgnized Heap Array is : \n\n");
    
    for (i = 0; i < size; i++)         
        printf("%d\t", heapArray[i]);
    
    printf("\n\n");
    printf("Opcount of HeapTopDown is = %d ", opCount);     
    printf("\n\n\n");
    exit(0);
}
