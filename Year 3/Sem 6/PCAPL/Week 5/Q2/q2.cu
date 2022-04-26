#include <cuda.h>
#include <stdlib.h>
#include <stdio.h>

__global__ void selectionSortKernel<<< 1, n >>>(float * unsorted_arr, float * sorted_arr, int n) {
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  float key = unsorted_arr[idx];
  int pos = 0;
  for (int i = 0; i < n; i++) {
    if (unsorted_arr[i] < key || (unsorted_arr[i] == key && i < idx))
      pos++;
  }
  sorted_arr[pos] = key;
}

void selectionSort(float * unsorted_arr, float * sorted_arr, int n) {
  int size = n * sizeof(float);
  float * d_unsorted_arr;
  float * d_sorted_arr;

  cudaMalloc((void ** ) & d_unsorted_arr, size);
  cudaMalloc((void ** ) & d_sorted_arr, size);
  cudaMemcpy(d_unsorted_arr, unsorted_arr, size, cudaMemcpyHostToDevice);
  selectionSortKernel(d_unsorted_arr, d_sorted_arr, n);
  cudaMemcpy(sorted_arr, d_sorted_arr, size, cudaMemcpyDeviceToHost);
  cudaFree(d_unsorted_arr);
  cudaFree(d_sorted_arr);
}

int main() {
  float * h_unsorted_arr, * h_sorted_arr;
  int n = 5;
  int size = n * sizeof(float);
  h_unsorted_arr = (float * ) malloc(size);
  h_sorted_arr = (float * ) malloc(size);

  for (int i = 0; i < 5; i++)
    h_unsorted_arr[i] = rand() % 50;
  
  selectionSort(h_unsorted_arr, h_sorted_arr, n);
  printf("unsorted_arr: ");
  for (int i = 0; i < n; i++)
    printf("%f, ", h_unsorted_arr[i]);
  printf("\n\n");

  printf("sorted_arr: ");
  for (int i = 0; i < n; i++)
    printf("%f, ", h_sorted_arr[i]);
  printf("\n");
  return 0;
}