import java.util.Scanner;
import java.lang.Math;

public class LinearSearch
{
    public static int findVal(int val, int array[])
    {
        for(int i=0; i<array.length; i++)
        {
            if(array[i]==val)
                return i;
        }
        return -1;
    }
    
    public static void main(String arg[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements in array: ");
        int n=sc.nextInt();
        
        int array[] = new int[n];
        
        for(int i=0; i<n; i++)
        {
            System.out.println("Enter elements of array: ");
            array[i]=sc.nextInt();
        }
        
        System.out.print("Enter value to search: ");
        int val = sc.nextInt();
        
        if(findVal(val, array)==-1)
            System.out.print("Value not found!");
        else
            System.out.print("Found at index "+findVal(val, array));
    }
}