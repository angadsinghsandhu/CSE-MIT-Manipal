const char* programSource = 
_kernel void 180mat(_global int *mat, _global int *matNew, __constant int n){
    // getting WI's (Work-Item's) unique id
    int idx = get_global_id(0);

    // getting the row and column of the matrix
    int i = idx / n;
    int j = idx % n;

    // getting the 180 roatation index of matrix
    int i_ = (n-1) - i;
    int j_ = (n-1) - j;

    // creating roatated matrix
    matNew[i_][j_] = mat[i][j];
}