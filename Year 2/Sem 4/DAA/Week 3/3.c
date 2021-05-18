#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

int size;
int opcount;
int *kc;
int *dkc;

bool subset(int arr[], int n, int sum, int a[])
{
    int *k;
    int *dk;
    k = (int *)calloc(size, sizeof(int));
    dk = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        k[i] = a[i];
        dk[i] = a[i];
    }
    if (sum == 0)
    {
        printf("Possible to partition\n");
        printf("Subset 1: ");
        for (int i = 0; i < size; i++)
        {
            if (a[i])
                printf("%d ", a[i]);
        }
        printf("\nSubset 2: ");
        int flag;
        for (int i = 0; i < size; i++)
        {
            flag = 1;
            for (int j = 0; j < size; j++)
            {
                if (arr[i] == a[j])
                    flag = 0;
            }
            if (flag)
                printf("%d ", arr[i]);
        }
        printf("\n");
        return true;
    }
    if (n == 0 && sum != 0)
        return false;
    dk[n - 1] = 0;
    opcount++;
    return subset(arr, n - 1, sum, k) || subset(arr, n - 1, sum - arr[n - 1], dk);
}

bool partition(int arr[], int n) {
    int sum = 0;
    kc = (int *)calloc(size, sizeof(int));
    dkc = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        kc[i] = arr[i];
        dkc[i] = arr[i];
    }
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return false;
    return subset(arr, n, sum / 2, arr);
}

int main()
{
    printf("Enter size of set: \n");
    scanf("%d", &size);
    int *arr = (int *)calloc(size, sizeof(int));
    printf("Enter the set: \n");
    for (int j = 0; j < size; j++)
    {
        scanf("%d", &arr[j]);
    }
    opcount = 0;
    bool flag = partition(arr, size);
    if (flag)
        printf("");
    else
        printf("Not possible to partition\n");
    printf("\nopcount = %d\n", opcount);
    return 0;
}