// C++ program Miller-Rabin primality test
#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#define ITERATIONS 10
using namespace std;

// It returns (x^y) % p
long long power(long long x, unsigned int y, int p)
{
    long long res = 1;
    x = x % p;
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// This function is called for all k trials. It returns
// false if n is composite and returns true if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
bool miillerTest(int d, int n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    long long a = 2 + rand() % (n - 4);

    // Compute a^d % n
    long long x = power(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }

    // Return composite
    return false;
}

// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(int n, int k)
{
    // Corner cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    // Find r such that n = 2^d * r + 1 for some r >= 1
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Iterate given nber of 'k' times
    for (int i = 0; i < k; i++)
        if (!miillerTest(d, n))
            return false;

    return true;
}

int main()
{

    int k = ITERATIONS; // Number of iterations
    int nb_of_primes = 0;
    ifstream file1;
    file1.open("test.in", ios_base::in);
    std::string line;
    getline(file1, line);                      //we get the first line of the file
    sscanf(line.c_str(), "%d", &nb_of_primes); //we transform the char returned by getline() into an int
    int l = 0;                                 //array iterator
    int *array_with_primes = {0};
    array_with_primes = (int *)malloc((nb_of_primes + 1) * sizeof(int));
    while (!file1.eof())
    {
        getline(file1, line);
        int t = 0;
        sscanf(line.c_str(), "%d", &t); //we transfor the char line into an int
        if (isPrime(t, k))              //verify if the number is prime
        {
            array_with_primes[l] = t; //if the number is prime we put it in the array
            l++;
        }
    }
    ofstream fout;
    fout.open("test.out", ios_base::out);
    int primes_counter = 0;
    for (int i = 0; i < nb_of_primes; i++)
    {
        if (array_with_primes[i])
        {
            primes_counter++;
        }
    }
    fout << primes_counter << endl; //we write in file the numbers of prime
    for (int i = 0; i < nb_of_primes; i++)
    {
        if (array_with_primes[i])
        {
            fout << array_with_primes[i] << endl; //we write the primes found
        }
    }
    free(array_with_primes);
    return 0;
}