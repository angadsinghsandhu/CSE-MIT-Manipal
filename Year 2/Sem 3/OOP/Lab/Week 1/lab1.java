// package 

import java.util.Scanner;

class lab1{
    public static void main(String args[]){
        // instantiating variables
        int num, n;
        
        // creating scanner class
        Scanner sc = new Scanner(System.in);

        // PART - 1
        System.out.print("Enter a number to check for prime : ");
        num = sc.nextInt();

        if(isPrime(num)) {
            System.out.println("Entered Number is Prime");
        } else {
            System.out.println("Entered Number is not Prime");
        }

        // PART - 2
        System.out.print("Enter number of prime numbers to be foumd : ");
        n = sc.nextInt();

        printPrime(n);

        sc.close();
    }

    private static void printPrime(int n) {
        int j=2;
        System.out.print("Prime Numbers are : ");
        
        while(n != 0){
            if(isPrime(j)){
                System.out.print(String.format("%d ", j));
                n--;
            }
            j++;
        }

        System.out.println("");
    }

    public static Boolean isPrime(int num) {
        for(int i = 2; i <= num/2; i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
}