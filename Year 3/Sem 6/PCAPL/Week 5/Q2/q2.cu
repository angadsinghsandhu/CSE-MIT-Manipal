#include <cuda.h>
#include <stdlib.h>
#include <stdio.h>

__global__ void selectionSortKernel<<< 1, n >>>(float * arr, float * lst, int n) {
  int idx = threadIdx.x + blockIdx.x * blockDim.x;
  float key = arr[idx];
  int pos = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] < key || (arr[i] == key && i < idx))
      pos++;
  }
  lst[pos] = key;
}

void selectionSort(float * arr, float * lst, int n) {
  int size = n * sizeof(float);
  float *d_arr, *d_lst;

  cudaMalloc((void ** ) & d_arr, size);
  cudaMalloc((void ** ) & d_lst, size);
  cudaMemcpy(d_arr, arr, size, cudaMemcpyHostToDevice);
  selectionSortKernel(d_arr, d_lst, n);
  cudaMemcpy(lst, d_lst, size, cudaMemcpyDeviceToHost);
  cudaFree(d_arr);
  cudaFree(d_lst);
}

int main() {
  float * h_arr, * h_lst;
  int n = 5, size = n * sizeof(float);
  h_arr = (float * ) malloc(size);
  h_lst = (float * ) malloc(size);

  for (int i = 0; i < 5; i++)
    h_arr[i] = rand() % 50;
  
  selectionSort(h_arr, h_lst, n);
  printf("arr: ");
  for (int i = 0; i < n; i++)
    printf("%f, ", h_arr[i]);
  printf("\n\n");

  printf("lst: ");
  for (int i = 0; i < n; i++)
    printf("%f, ", h_lst[i]);
  printf("\n");
  return 0;
}