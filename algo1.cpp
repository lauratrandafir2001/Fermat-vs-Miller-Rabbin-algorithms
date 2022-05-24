// C++ program to find the smallest twin in given range
#include <bits/stdc++.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#define ITERATIONS 50
using namespace std;

long long power(long long a, unsigned int n, int p)
{
    long long res = 1;
    a = a % p; // Update 'a' if 'a' >= p

    while (n > 0)
    {
        // If n is odd, multiply 'a' with result
        if (n & 1)
            res = (res * a) % p;

        // n must be even now
        n = n >> 1; // n = n/2
        a = (a * a) % p;
    }
    return res;
}

/*Recursive function to calculate gcd of 2 numbers*/
int gcd(unsigned int a, long long b)
{
    if (a < b)
        return gcd(b, a);
    else if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

// Higher value of k increases probability of correct
// result.
bool isPrime(unsigned int n, int k) //k is the number of iterations
{
    // Corner cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    while (k > 0)
    {
        // Pick a random number in [2..n-2]
        // Above corner cases make sure that n > 4
        long long a = 2 + rand() % (n - 4);

        // Checking if a and n are co-prime
        if (gcd(n, a) != 1)
            return false;

        // Fermat's little theorem
        if (power(a, n - 1, n) != 1)
            return false;

        k--;
    }

    return true;
}

int main()

{

    int k = ITERATIONS;
    int nb_of_primes = 0;
    ifstream file1;
    file1.open("test.in", ios_base::in);
    string line;
    getline(file1, line);
    sscanf(line.c_str(), "%d", &nb_of_primes);
    int l = 0;
    int *array_with_primes = {0};
    array_with_primes = (int *)malloc((nb_of_primes + 1) * sizeof(int));
    while (!file1.eof())
    {
        getline(file1, line); //we read from file
        int t = 0;
        sscanf(line.c_str(), "%d", &t);
        if (isPrime(t, k)) //we test if the number is prime
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
