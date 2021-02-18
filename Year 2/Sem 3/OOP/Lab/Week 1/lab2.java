import java.util.Scanner;

// package `Year 2.Sem 3.OOP.Lab.Week 1`;

public class lab2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int len, m, n;
        
        // PART - 1
        System.out.print("Enter the Length of the Array : ");
        len = sc.nextInt();
        int[] arr = new int[len];
        
        System.out.println("Enter the Elements of the Array : ");
        for (int i=0; i<len;i++)
            arr[i] = sc.nextInt();

        bubSort(arr);

        // PART - 2
        System.out.println("\n\nEnter the Length of the Matrices : ");
        m = sc.nextInt();
        n = sc.nextInt();
        int[][] mat1 = new int[m][n];
        int[][] mat2 = new int[m][n];
        
        System.out.print("Enter the Elements of the Matrix 1 : \n");
        for (int i=0; i<m;i++)
            for (int j=0; j<m;j++)
                mat1[i][j] = sc.nextInt();

        System.out.print("\nEnter the Elements of the Matrix 2 : \n");
        for (int i=0; i<m;i++)
            for (int j=0; j<m;j++)
                mat2[i][j] = sc.nextInt();

        matAdd(mat1, mat2);

        sc.close();
    }

    private static void matAdd(int[][] mat1, int[][] mat2) {
        for(int i=0; i<mat1.length; i++)
            for(int j=0; j<mat1[0].length; j++)
                mat1[i][j] += mat2[i][j];

        printMat(mat1);
    }

    private static void printMat(int[][] mat) {
        System.out.print("\nThe Matrix is : \n");
        for(int i=0; i<mat.length; i++){
            for(int j=0; j<mat[0].length; j++)
                System.out.print(String.format("%d ", mat[i][j]));
            System.out.println("");
        }
    }

    private static void bubSort(int[] arr) {
        int len = arr.length;

        for(int i=0; i<arr.length; i++)
            for(int j=0; j<len; j++){
                if(arr[i] > arr[i+1]){
                    // swapping
                    arr[i] += arr[i+1];
                    arr[i+1] = arr[i] - arr[i+1];
                    arr[i] -= arr[i+1];
                }
                len--;
            }

            printArr(arr);
    }

    private static void printArr(int[] arr) {
        System.out.print("The Array is : ");
        for(int i=0; i<arr.length; i++){
            System.out.print(String.format("%d ", arr[i]));
        }
    }
}
