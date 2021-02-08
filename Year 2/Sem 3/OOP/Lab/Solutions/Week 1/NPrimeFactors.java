import java.util.Scanner;
import java.lang.Math;

public class NPrimeFactors
{
    public static int isPrime(int num)
    {
        if(num==2 || num%2!=0)
            return 1;
        else
            return 0;
    }
    public static void main(String[] arg)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter N: ");
        int N = sc.nextInt();
        int counter=0, num=2;
        
        while(counter<N)
        {
            if(isPrime(num)==1)
            {
                System.out.print(num+" ");
                counter++;
            }
            num++;
        }
        
    }
}