#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1024

__global__ void CUDACount(char* A, int* cnt){
    int idx = threadIdx.x;

    if(A[idx] == 'a')
        atomicAdd(cnt, 1);
}

int main(){
    char A[N];
    char *d_A;

    int count=0, *d_count, res;

    cudaError_t err = cudaGetLastError();

    printf("Enter String : ");
    scanf("%s", A);
    printf("String : %s\n", A);

    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 1 : %s\n", cudaGetErrorString(err));

    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    cudaEventRecord(start, 0);
    
    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 2 : %s\n", cudaGetErrorString(err));

    cudaMalloc((void**)&d_A, strlen(A)*sizeof(char));
    cudaMalloc((void**)&d_count, sizeof(int));
    cudaMalloc((void**)&res, sizeof(int));

    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 3 : %s\n", cudaGetErrorString(err));

    cudaMemcpy(d_count, &count, sizeof(int), cudaMemcpyHostToDevice);
    
    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 3.5 : %s\n", cudaGetErrorString(err));
        
    cudaMemcpy(d_A, A, strlen(A)*sizeof(char), cudaMemcpyHostToDevice);


    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 4 : %s\n", cudaGetErrorString(err));

    CUDACount<<<1, strlen(A)>>>(d_A, d_count);

    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 5 : %s\n", cudaGetErrorString(err));

    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);

    float elapsedTime;
    cudaEventElapsedTime(&elapsedTime, start, stop);
    

    cudaMemcpy(&res, d_count, sizeof(int), cudaMemcpyDeviceToHost);
    printf("Total Occurances of 'a' = %d\n", res);

    cudaFree(d_A);
    cudaFree(d_count);
    return 0;

}
