/*
==PSUDOCODE==
Middle-school procedure for computing gcd(m, n)
Step 1 Find the prime factors of m.
Step 2 Find the prime factors of n.
Step 3 Identify all the common factors in the two prime expansions found in
Step 1 and Step 2. (If p is a common factor occurring pm and pn times
in m and n, respectively, it should be repeated min{pm, pn} times.)
Step 4 Compute the product of all the common factors and return it as the
greatest common divisor of the numbers given
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_ARR_SIZE [4096]

void prime_gen(int number, int * primes) {
  int i = 0, j;
  for(i = 2; i<=number; i++)
    primes[i] = i;

    i = 2;
    int opcount = 0;
    while ((i*i) <= number)
    {
      opcount++;
        if (primes[i] != 0)
        {
            for(j=2; j<number; j++)
            {
                if (primes[i]*j > number)
                    break;
                else
                    primes[primes[i]*j]=0;
            }
        }
        i++;
    }

    printf("Opcount for sieve = %d\n", opcount);
}

int prime_factorization(int n, int * factor_arr) {
  int primes MAX_ARR_SIZE;
  prime_gen(n, primes);
  int factor = 0;
  int m = 0;
  int opcount = 0;
  for(int i = 0; i <= n; i++) {
    if (primes[i] == 0) {
      continue;
    }
    m = primes[i];
    if ( n % m == 0 ) {
        opcount++;
        n = n / m;
        factor_arr[factor++] = m;
        i--;
    }
  }
  printf("Operation count for prime factors = %d\n", opcount);
  return factor - 1;
}

int gcd(int m, int n) {
  int m_factors MAX_ARR_SIZE;
  int n_factors MAX_ARR_SIZE;
  int result MAX_ARR_SIZE;
  int mf_size = prime_factorization(m, m_factors);
  int nf_size = prime_factorization(n, n_factors);

  int i = 0, j = 0, k = 0, opcount = 0;
  while(i <= mf_size && j <= nf_size) {
    opcount++;
    if ( m_factors[i] > n_factors[j] ) {
      j++;
    } else if ( m_factors[i] < n_factors[j] ) {
      i++;
    } else {
      result[k++] = m_factors[i];
      i++;
      j++;
    }
  }

  int gcd = 1;
  int opcount_ = 0;
  for (int i = 0; i < k; i++) {
    opcount_++;
    gcd *= result[i];
  }

  printf("Operation count for muliplication of factors = %d\n", opcount_);
  printf("Number of operations for middle school = %d\n", opcount);
  return gcd;
}

int main() {
  int n, m;
  printf("Enter m: ");
  scanf("%d", &n);
  printf("Enter n: ");
  scanf("%d", &m);
  printf("The GCD of a %d and %d is %d", m, n, gcd(m, n));
  return 0;
}