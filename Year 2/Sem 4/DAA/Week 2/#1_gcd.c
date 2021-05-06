/*
==PSUDOCODE==
ALGORITHM EuclidGCD(m, n) 
//Computes gcd(m, n) by Euclid’s algorithm 

//Input: Two nonnegative, not-both-zero integers m and n 
//Output: Greatest common divisor of m and n 

while n ≠ 0 
do 
    r ←m mod n 
    m←n 
    n←r  
    return m 

Euclid’s algorithm for computing gcd(m, n)
Step 1 If n = 0, return the value of m as the answer and stop; otherwise,
proceed to Step 2.
Step 2 Divide m by n and assign the value of the remainder to r.
Step 3 Assign the value of n to m and the value of r to n. Go to Step 1
*/


#include<stdio.h> 

unsigned int EuclidGCD(unsigned int m, unsigned int n) {       
    unsigned int r;       
    int  opcount = 0; // variable to count how many times the basic operation executes.       
    while(n!=0) {                 
        opcount++;                  
        r = m %n;                 
        m = n;                 
        n=r;       
    }      
    printf("\nOperation count= %d\n", opcount);       
    return m; 
}  

int  main() {                 
    unsigned int m,n;                 
    printf("Enter the two numbers whose GCD has to be calculated : \n");                 
    scanf("%d", &m);                 
    scanf("%d", &n);                 
    printf("\nGCD of two numbers using Euclid’s method is %d",                                
    EuclidGCD(m,n));  
    return 0; 
}
