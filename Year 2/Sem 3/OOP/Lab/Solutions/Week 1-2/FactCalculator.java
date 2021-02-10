import java.util.Scanner;
import java.lang.Math;

public class FactCalculator
{
    public static int fact(int num)
    {
        if(num==0)
            return 0;
        
        if (num==1)
            return 1;
        
        return(num*fact(num-1));
    }
    
    public static void main(String[] arg)
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter N: ");
        int N=sc.nextInt();
        System.out.print("Enter R: ");
        int R=sc.nextInt();
        
        System.out.println("Result is: "+fact(N)/(fact(R)*fact(N-R)));
    }
}