#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1024

__global__ void CUDACount(char* A, char* B, int* len, int* wordLen, int* cnt){
    int idx = threadIdx.x, flag=1;
    
    if(idx + *wordLen <= *len){
        for(int i=0; i<*wordLen; i++){
            if(A[idx + i] != B[i]){
                flag = 0;
                break;
            }
        }

        if(flag==1)
            atomicAdd(cnt, 1);
    }
}

int main(){
    char A[N], B[N];
    char *d_A, *d_B;

    int count=0, len, wordLen,res;
    int *d_count, *d_len, *d_wordLen;

    cudaError_t err = cudaGetLastError();

    printf("Enter String : ");
    scanf("%s", A);
    printf("String : %s\n\n", A);

    printf("Enter Word to be searched in String : ");
    scanf("%s", B);
    printf("Word : %s\n\n", B);

    len = strlen(A);
    wordLen = strlen(B);

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
    cudaMalloc((void**)&d_B, strlen(B)*sizeof(char));
    cudaMalloc((void**)&d_count, sizeof(int));
    cudaMalloc((void**)&d_len, sizeof(int));
    cudaMalloc((void**)&d_wordLen, sizeof(int));
    cudaMalloc((void**)&res, sizeof(int));

    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 3 : %s\n", cudaGetErrorString(err));

    cudaMemcpy(d_count, &count, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_len, &len, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_wordLen, &wordLen, sizeof(int), cudaMemcpyHostToDevice);
    
    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 3.5 : %s\n", cudaGetErrorString(err));
        
    cudaMemcpy(d_A, A, strlen(A)*sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, strlen(B)*sizeof(char), cudaMemcpyHostToDevice);


    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 4 : %s\n", cudaGetErrorString(err));

    CUDACount<<<1, strlen(A)>>>(d_A, d_B, d_len, d_wordLen, d_count);

    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 5 : %s\n", cudaGetErrorString(err));

    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);

    float elapsedTime;
    cudaEventElapsedTime(&elapsedTime, start, stop);
    

    cudaMemcpy(&res, d_count, sizeof(int), cudaMemcpyDeviceToHost);
    printf("Total Occurances of '%s' = %d\n", B, res);

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_len);
    cudaFree(d_wordLen);
    cudaFree(d_count);
    return 0;

}
