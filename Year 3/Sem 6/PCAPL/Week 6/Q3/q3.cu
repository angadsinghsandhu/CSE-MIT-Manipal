#include<stdio.h>
#include<stdlib.h>
#include<cuda.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

/*
Sparce Matrix Multiplication
*/

__global__ void spvm(int num_rows, int *data, int *col_indices, int *row_ptr, int *x, int *y)
{
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    if(row < num_rows)
    {
        int dot=0;
        int row_start = row_ptr[row];
        int row_end = row_ptr[row+1];

        for(int elem= row_start; elem<row_end; elem++)
        {
            dot += data[elem] * x[col_indices[elem]];
        }
        y[row] = dot;
    }
}

int main()
{
    int m,n;
    printf("Enter rows and col : ");
    scanf("%d%d",&m,&n);

    int** arr = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        arr[i] = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements : \n",m*n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);

    int *x = (int*)malloc(n*sizeof(int));
    int *y = (int*)malloc(n*sizeof(int));
    printf("Enter vector X(%d elements) : ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&x[i]);

    int data[20], col_indices[20], row_ptr[20];
    int count = 0;
    row_ptr[0] = 0;
    for(int i=0;i<m;i++)
    {
        int c = 0;
        for(int j=0;j<n;j++)
            if(arr[i][j] != 0)
            {
                c++;
                data[count] = arr[i][j];
                col_indices[count++] = j;
            }

        row_ptr[i+1] = row_ptr[i] + c;  
    }

    int *d_data, *d_col_indices, *d_row_ptr, *d_x, *d_y;
    cudaMalloc((void**)&d_data,count*sizeof(int));
    cudaMalloc((void**)&d_col_indices,count*sizeof(int));
    cudaMalloc((void**)&d_row_ptr,(m+1)*sizeof(int));
    cudaMalloc((void**)&d_x,n*sizeof(int));
    cudaMalloc((void**)&d_y,m*sizeof(int));

    cudaMemcpy(d_data,data,count*sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(d_col_indices,col_indices,count*sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(d_row_ptr,row_ptr,(m+1)*sizeof(int),cudaMemcpyHostToDevice);
    cudaMemcpy(d_x,x,n*sizeof(int),cudaMemcpyHostToDevice);
    
    spvm<<<1,m>>>(m,d_data,d_col_indices,d_row_ptr,d_x,d_y);
    
    cudaMemcpy(y,d_y,m*sizeof(int),cudaMemcpyDeviceToHost);
    
    printf("\n\n");
    for(int i=0;i<m;i++)
        printf("%d  ",y[i]);
    printf("\n\n");

    cudaFree(d_data);
    cudaFree(d_col_indices);
    cudaFree(d_row_ptr);
    cudaFree(d_x);
}

