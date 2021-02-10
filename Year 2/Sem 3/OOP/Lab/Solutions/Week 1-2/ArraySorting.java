import java.util.Scanner;
import java.lang.Math;

public class ArraySorting
{
    public static void main(String[] arg)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements in array: ");
        int n=sc.nextInt();
        
        int array[] = new int[n];
        int temp;
        
        for(int i=0; i<n; i++)
        {
            System.out.println("Enter elements of array: ");
            array[i]=sc.nextInt();
        }
        
        //descending
        for(int i=0; i<n; i++)
        {
            for(int ii=1; ii<n-i; ii++)
            {
                if(array[ii]>array[ii-1])
                {
                    temp=array[ii];
                    array[ii]=array[ii-1];
                    array[ii-1]=temp;
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            System.out.print(array[i]+" ");
        }
        
        //ascending
        for(int i=0; i<n; i++)
        {
            for(int ii=1; ii<n-i; ii++)
            {
                if(array[ii]<array[ii-1])
                {
                    temp=array[ii];
                    array[ii]=array[ii-1];
                    array[ii-1]=temp;
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            System.out.print(array[i]+" ");
        }
    }
}