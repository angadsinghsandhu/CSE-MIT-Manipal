#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

__host__ __device__ void printMatrix(const char * string, int * A, int width) {
  printf("%s\n", string);
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      printf("%d, ", A[i * width + j]);
    }
    printf("\n");
  }
  printf("\n");
}
__host__ void clearMatrix(int * A, int width) {
  for (int i = 0; i < width; i++)
    for (int j = 0; j < width; j++)
      A[i * width + j] = 0;
}
__global__ void multiplyMatrixKernel_2a(int * A, int * B, int * C, int width) {
  int row = threadIdx.y;
  int k = 0;
  for (int i = 0; i < width; i++) {
    k = 0;
    for (int j = 0; j < width; j++)
      k += A[row * width + j] * B[i + width * j];
    C[row * width + i] = k;
  }
}
__global__ void multiplyMatrixKernel_2b(int * A, int * B, int * C, int width) {
  int col = threadIdx.x;
  int k = 0;
  for (int i = 0; i < width; i++) {
    k = 0;
    for (int j = 0; j < width; j++)
      k += A[i * width + j] * B[col + j * width];
    C[i * width + col] = k;
  }
}

__global__ void multiplyMatrixKernel_2c(int * A, int * B, int * C, int width) {
  int col = threadIdx.x;
  int row = threadIdx.y;
  int k = 0;
  for (int i = 0; i < width; i++)
    k += A[row * width + i] * B[col + i * width];
  C[row * width + col] = k;
}

void multiplyMatrix(int * h_A, int * h_B, int * h_C, int width) {
  int * d_A, * d_B, * d_C;
  int size = width * width * sizeof(int);
  
  cudaMalloc((void ** ) & d_A, size);
  cudaMalloc((void ** ) & d_B, size);
  cudaMalloc((void ** ) & d_C, size);
  cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
  cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);
  cudaMemcpy(d_C, h_C, size, cudaMemcpyHostToDevice);
  
  dim3 dimBlock(1, 1, 1);
  dim3 dimGrid(1, 1, 1);
  
  dimBlock.x = 1;
  dimBlock.y = width;
  dimBlock.z = 1;
  multiplyMatrixKernel_2a <<< dimGrid, dimBlock >>> (d_A, d_B, d_C, width);
  cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);
  printMatrix("A*B: (from 2a kernel): ", h_C, width);
  clearMatrix(h_C, width);
  cudaMemcpy(d_C, h_C, size, cudaMemcpyHostToDevice);

  dimBlock.x = width;
  dimBlock.y = 1;
  dimBlock.z = 1;
  multiplyMatrixKernel_2b <<< dimGrid, dimBlock >>> (d_A, d_B, d_C, width);
  cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);
  printMatrix("A*B: (from 2b kernel): ", h_C, width);
  clearMatrix(h_C, width);
  cudaMemcpy(d_C, h_C, size, cudaMemcpyHostToDevice);

  dimBlock.x = width;
  dimBlock.y = width;
  dimBlock.z = 1;
  multiplyMatrixKernel_2c <<< dimGrid, dimBlock >>> (d_A, d_B, d_C, width);
  cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);
  printMatrix("A*B: (from 2c kernel): ", h_C, width);

  cudaFree(d_A);
  cudaFree(d_B);
  cudaFree(d_C);
}

int main() {
  int * A, * B, * C, k=1;
  int width = 3;
  int size = width * width * sizeof(int);
  A = (int * ) calloc(width * width, sizeof(int));
  B = (int * ) calloc(width * width, sizeof(int));
  C = (int * ) calloc(width * width, sizeof(int));
  
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < width; j++) {
      A[i * width + j] = rand() % 10;
      B[i * width + j] = rand() % 11;
      k++;
    }
  }
  printMatrix("A:", A, width);
  printMatrix("B:", B, width);
  multiplyMatrix(A, B, C, width);
  return 0;
}