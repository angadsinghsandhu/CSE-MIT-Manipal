// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>

// Creating OpenCl Kernel (i.e OpenCl Function)
const char* programSource = 
"_kernel void vecadd(_global int *A, _global int *B, _global int *C){   \n"
"    // getting WI's (Work-Item's) unique id                            \n"
"    int idx = get_global_id(0);                                        \n" 
"    // Adding Corresponding locations of 'A' and 'B' to store in 'C'   \n"
"    C[idx] = A[idx] + B[idx];}                                         \n"
;

// host code
int main(){
    // // STEP 0
    // host data buffers
    int *A = NULL;
    int *B = NULL;
    int *C = NULL;

    // elements in each array (number of WIs)
    const int elements = 2048;

    // size of data in bytes
    size_t datasize = sizeof(int) * elements;

    // dynamically allocating memory on host
    A = (int*)malloc(datasize);
    B = (int*)malloc(datasize);
    C = (int*)malloc(datasize);

    // initialize input buffer
    for(int i=0; i<elements; i++){
        A[i] = i;
        B[i] = i;
    }

    // ststus to check output of each API call
    cl_int status;

    // // STEP 1 : Discover and Initialize PLatforms

    cl_uint num_platforms = 0;
    cl_platform_id platforms = NULL;

    status = clGetPlatformIDs(0, NULL, &num_platforms); // get number of platforms
    platforms = (cl_platform_id*) malloc(num_platforms*sizeof(cl_platform_id)); // alocating space for eah plartform
    status = clGetPLatformIDs(num_platforms, platforms, NULL);  // filling in platform info

    // // STEP 2 : Discover and Initialize Devices
    cl_uint num_devices = 0;
    cl_device_id devices = NULL;

    status = clGetDeviceIDs(0, NULL, &num_devices); // get number of devices
    devices = (cl_device_id*) malloc(num_devices * sizeof(cl_device_id)); // alocating space for each device
    status = clGetDeviceInfo(num_devices, devices, NULL); // filling in device info

    // // STEP 3 : Creating Context
    // create context and assoiate with devices 
    cl_context context = clCreateContext(NULL, num_devices, devices, NULL, NULL, &status);

    // // STEP 4 : Creating Command Queue
    // create command queue and associate with context and device
    cl_command_queue cmdQueue = clCreateCommandQueue(context, devices[0], 0, &status);

    // // STEP 5 : Create Device Buffer
    // creating buffer to store host input and output.
    cl_mem bufA = clCreateBuffer(context, CL_MEM_READ_ONLY, datasize, NULL, &status);
    cl_mem bufB = clCreateBuffer(context, CL_MEM_READ_ONLY, datasize, NULL, &status);
    cl_mem bufC = clCreateBuffer(context, CL_MEM_WRITE_ONLY, datasize, NULL, &status);

    // // STEP 6 : Write Host Data to device buffers
    // write input arrays to Device bufers
    status = clEnqueueWriteBuffer(cmdQueue, bufA, CL_FALSE, 0, datasize, A, 0, NULL, NULL);
    status = clEnqueueWriteBuffer(cmdQueue, bufB, CL_FALSE, 0, datasize, B, 0, NULL, NULL);

    // // STEP 7 : Create and Compile The Program
    cl_program program = clCreateProgramWithSource(context, 1, (const char **) &programSource, NULL, &status);
    status = clBuildProgram(program, num_devices, devices, NULL, NULL, NULL);

    // // STEP 8 : Creating The Kernel
    cl_kernel kernel = clCreateKernel(program, "vecadd", &status);

    // // STEP 9 : Set Kernel Argements
    status = clSetKernelArg(kernel, 0, sizeof(cl_mem), bufA);
    status |= clSetKernelArg(kernel, 1, sizeof(cl_mem), bufB);
    status |= clSetKernelArg(kernel, 2, sizeof(cl_mem), bufC);

    // // STEP 10 : Configure Work-Item Structure
    size_t GlobalWorkSize[1] = { elements };  

    // // STEP 11 : Enqueue Kernel for Execution
    status = clEnqueueNDRangeKernel(cmdQueue, kernel, 1, NULL, GlobalWorkSize, NULL, 0, NULL, NULL);

    // // STEP 12 : Read Output Buffer Back to Host
    status = clEnqueueReadBuffer(cmdQueue, bufC, CL_TRUE, 0, datasize, C, 0, NULL, NULL);

    // verifying results
    int result = 1;
    for(int i=0; i<elements; i++){
        if(C[i] != A[i] + B[i]){
            result = 0;
            break;
        }
    }

    if(reult == 1)
        printf("Output is Correct");
    else
        printf("Output is Incorrect");

    // // STEP 13 : Release OpenCL resources
    clReleaseKernal(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(cmdQueue);
    clReleaseMemObject(bufA);
    clReleaseMemObject(bufB);
    clReleaseMemObject(bufC);
    clReleaseContext(context);
    free(A);
    free(B);
    free(C);
    free(platforms);
    free(devices);

}


