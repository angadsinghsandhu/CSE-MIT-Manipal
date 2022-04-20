#include <cuda.h>

#include <stdlib.h>

#include <stdio.h>

__global__
void oddEven(float * arr, int n) {
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  if (idx % 2 == 1 && idx + 1 < n) {
    if (arr[idx] > arr[idx + 1]) {
      float temp = arr[idx];
      arr[idx] = arr[idx + 1];
      arr[idx + 1] = temp;
    }
  }
}
__global__
void evenOdd(float * arr, int n) {
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  if (idx % 2 == 0 && idx + 1 < n) {
    if (arr[idx] > arr[idx + 1]) {
      float temp = arr[idx];
      arr[idx] = arr[idx + 1];
      arr[idx + 1] = temp;
    }
  }
}
void oddEvenTranspositionSort(float * arr, int n) {
  int size = n * sizeof(float);
  float * d_arr;
  cudaMalloc((void ** ) & d_arr, size);
  cudaMemcpy(d_arr, arr, size, cudaMemcpyHostToDevice);
  for (int i = 0; i <= n / 2; i++) {
    oddEven << < 1, n >>> (d_arr, n);
    evenOdd << < 1, n >>> (d_arr, n);
  }
  cudaMemcpy(arr, d_arr, size, cudaMemcpyDeviceToHost);
  cudaFree(d_arr);
}
int main() {
  float * h_arr;
  int n = 5;
  int size = n * sizeof(float);
  h_arr = (float * ) malloc(size);
  for (int i = 0; i < 5; i++) {
    h_arr[i] = rand() % 50;
  }
  printf("unsorted_arr: ");
  for (int i = 0; i < n; i++) {
    printf("%f, ", h_arr[i]);
  }
  printf("\n\n");
  oddEvenTranspositionSort(h_arr, n);
  printf("sorted_arr: ");
  for (int i = 0; i < n; i++) {
    printf("%f, ", h_arr[i]);
  }
  printf("\n");
  return 0;
}