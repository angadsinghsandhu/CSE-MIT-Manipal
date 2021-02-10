import java.util.Scanner;
import java.lang.Math;

public class MatrixAddition
{
    public static void main(String arg[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter matrix height: ");
        int rows=sc.nextInt();
        System.out.print("Enter matrix width: ");
        int cols=sc.nextInt();
        int matrix1[][]=new int[rows][cols];
        int matrix2[][]=new int[rows][cols];
        
        System.out.println("Matrix 1: ");
        for(int i=0; i<rows; i++)
        {
            for(int ii=0; ii<cols; ii++)
            {
                System.out.print("Enter value "+i+", "+ii+": ");
                matrix1[i][ii]=sc.nextInt();
            }
        }
        
        System.out.println("Matrix 2: ");
        for(int i=0; i<rows; i++)
        {
            for(int ii=0; ii<cols; ii++)
            {
                System.out.print("Enter value "+i+", "+ii+": ");
                matrix2[i][ii]=sc.nextInt();
            }
        }
        
        for(int i=0; i<rows; i++)
        {
            for(int ii=0; ii<cols; ii++)
            {
                matrix2[i][ii]=matrix1[i][ii]+matrix2[i][ii];
                System.out.print(matrix2[i][ii]+" ");
            }
            System.out.println();
        }
    }
}