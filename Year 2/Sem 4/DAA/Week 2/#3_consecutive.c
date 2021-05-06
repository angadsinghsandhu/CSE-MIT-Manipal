/*
==PSUDOCODE==
Consecutive integer checking algorithm for computing gcd(m, n)
Step 1 Assign the value of min{m, n} to t.
Step 2 Divide m by t. If the remainder of this division is 0, go to Step 3;
otherwise, go to Step 4.
Step 3 Divide n by t. If the remainder of this division is 0, return the value of
t as the answer and stop; otherwise, proceed to Step 4.
Step 4 Decrease the value of t by 1. Go to Step 2
*/

#include <stdio.h>
#include <stdlib.h>

int opcount = 0; // variable to count how many times the basic operation executes. 

int gcd(int m, int n) {
    int t = m > n ? n: m;
  
    while(m % t != 0 || n % t != 0) {
      opcount++;
      t--;
    }

    return t;
}

int main() {
	int i;
	int a, b;

    printf("Enter the two numbers whose GCD has to be calculated : \n");
	scanf("%d%d", &a, &b);

	int g = gcd(a, b);
    printf("\nOperation count= %d\n", opcount);   
	printf("GCD = %d\n", g);
}