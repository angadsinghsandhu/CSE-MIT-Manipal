#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MASK_WIDTH 5
#define WIDTH 10

/* 
do 1D convolution
1 - with mask in global memory
2 - with mask in shared memory
3 - with mask in constant memory
*/

__constant__ int d_Mc[MASK_WIDTH];

__global__ void convolution_global_memory(int *A, int *M, int *R){
	
	int i = blockIdx.x*blockDim.x+threadIdx.x;
	float val = 0;
	int start = i-(MASK_WIDTH/2);
    

	for(int j =0; j<MASK_WIDTH;j++){
		if(start+j >=0 && start+j < WIDTH){
			val+= A[start+j]*M[j];
		}
	}
	R[i]=val;
}

__global__ void convolution_shared_memory(int *A, int *M, int *R){
    __shared__ int d_Ms[MASK_WIDTH];
    for(int i=0; i<MASK_WIDTH; i++)
        d_Ms[i] = M[i];
    
    int i = blockIdx.x*blockDim.x+threadIdx.x;
	float val = 0;
	int start = i-(MASK_WIDTH/2);
    

	for(int j =0; j<MASK_WIDTH;j++){
		if(start+j >=0 && start+j < WIDTH){
			val+= A[start+j]*d_Ms[j];
		}
	}
	R[i]=val;
}

__global__ void convolution_constant_memory(int *A, int *R){
    int i = blockIdx.x*blockDim.x+threadIdx.x;
	float val = 0;
	int start = i-(MASK_WIDTH/2);
    
	for(int j =0; j<MASK_WIDTH;j++){
        if(start+j >=0 && start+j < WIDTH){
            val+= A[start+j] * d_Mc[j];
		}
	}
	R[i]=val;
}

int main(){
    int A[WIDTH], M[MASK_WIDTH], R[WIDTH];
    int *d_A, *d_M, *d_R;

    for(int i=0; i<WIDTH; i++){
        A[i] = rand() % 10;
        R[i] = 0;

        if(i < MASK_WIDTH)
            M[i] = rand() % 10;
    }

    printf("Input Matrix : ");
    for(int i=0; i<WIDTH; i++){
        printf("%d ", A[i]);
    }

    printf("\nMask Matrix : ");
    for(int i=0; i<MASK_WIDTH; i++){
        printf("%d ", M[i]);
    }
    printf("\n\n");

    cudaError_t err;

    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 1 : %s\n", cudaGetErrorString(err));

    cudaMalloc((void**)&d_A, WIDTH*sizeof(int));
    cudaMalloc((void**)&d_M, MASK_WIDTH*sizeof(int));
    cudaMalloc((void**)&d_R, WIDTH*sizeof(int));

    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 2 : %s\n", cudaGetErrorString(err));

    cudaMemcpy(d_A, A, WIDTH*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_M, M, MASK_WIDTH*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_R, R, WIDTH*sizeof(int), cudaMemcpyHostToDevice);

    if(cudaGetLastError() != cudaSuccess)
        printf("CUDA Error Occured 3 : %s\n", cudaGetErrorString(cudaGetLastError()));


    // Q2a
    convolution_global_memory<<<1, WIDTH>>>(d_A, d_M, d_R);

    // // Q2b
    // convolution_shared_memory<<<1, WIDTH>>>(d_A, d_M, d_R);

    // // Q2c
    // cudaMemcpyToSymbol(d_Mc, M, MASK_WIDTH*sizeof(int));
    // convolution_constant_memory<<<1, WIDTH>>>(d_A, d_R);

    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 4 : %s\n", cudaGetErrorString(err));

    cudaMemcpy(R, d_R, WIDTH*sizeof(int), cudaMemcpyDeviceToHost);

    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 5 : %s\n", cudaGetErrorString(err));


    printf("Resultant Matrix after convolution : ");
    for(int i=0; i<WIDTH; i++){
        printf("%d ", R[i]);
    }
    printf("\n");

    cudaFree(d_A);
    cudaFree(d_M);
    cudaFree(d_R);
    return 0;
}
