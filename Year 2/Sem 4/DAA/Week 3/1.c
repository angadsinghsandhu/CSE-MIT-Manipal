#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int opcount;

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void bubblesort(int *arr, int n) {
	int i, j;
	opcount=0;
	int flag=0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n - 1 - i; ++j) {
			opcount++;
			if (*(arr + j) > *(arr + j + 1)) {
				flag=1;

				swap(arr + j, arr + j + 1);
			}
		}
		if(flag==0)
			break;
	}
	printf("Operation count is = %d\n", opcount);
}

int main(){
    int *a, *b;
    int i,n = 5;
    int bc, wc;
    FILE *output;
    output = fopen("bubbleSort.csv", "w+");
    fprintf(output, "inputsize, worstcount, bestcount\n");
    
    for (int j=0; j < 10; j++) {
        wc=0;
        bc=0;
        a = (int *)malloc(sizeof(int)*n);
        b = (int *)malloc(sizeof(int)*n);
        
        for (int k=0; k< n; k++){
        a[k] = n-k;
                b[k] = k+1;
        }

        printf("Elements of worst array: \n");
        for(i=0;i<n;i++)
        printf("%d   ",a[i]);
        printf("\n");
            
        printf("Elements of best array: \n");
        for(i=0;i<n;i++)
        printf("%d   ",b[i]);
        printf("\n");
        
        printf("Sorting worst array...\n");
        bubblesort(a,n);
        
        wc=opcount;
        printf("Sorting best array...\n");
        bubblesort(b,n);
        bc=opcount;
        printf("Elements after bubble sort ");
        
        for(i=0;i<n;i++)
        printf("%d   ",a[i]);
        fprintf(output, "%d, %d, %d\n", n, wc, bc);
        printf("\n\n\n\n");
        free(a);
            free(b);
        n = n + 5;
    }
        fclose(output);
    return 0;
}