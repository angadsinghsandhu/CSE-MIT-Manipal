import java.util.Scanner;
class Calculator
{
    public int largest(int a, int b, int c)
    {
        if((a>b)&&(a>c))
        {
            return a;
        }
        else if(b>c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
    
     public static void main(String args[])
     {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a: ");
        int a =sc.nextInt();
        System.out.print("Enter b: ");
        int b =sc.nextInt();
        System.out.print("Enter c: ");
        int c =sc.nextInt();
        
        Calculator test_obj = new Calculator();
        
        int largest_no = test_obj.largest(a, b, c);
        System.out.println("Largest number of the three is: "+largest_no);
     }
}