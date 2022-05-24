//https://stackoverflow.com/questions/33426414/find-all-carmichael-numbers-in-a-given-interval-a-b-c
//https://www.geeksforgeeks.org/sieve-of-eratosthenes/

#include <bits/stdc++.h>
using namespace std;
#define NUMBERS_1_6 20
#define SUP_LIMIT_1_6 1001
#define NUMBERS_6_12 50
#define SUP_LIMIT_7_12 10001
#define NUMBERS_13_18 100
#define INF_LIMIT 10000
#define SUP_LIMIT_13_18 100000
#define NUMBERS_19_24 10000
#define CH_NB 10
#define RAND 10001
#define RAND_2 100001
#define MAX 1000000

int *SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    int *v;
    v = (int *)malloc(n * sizeof(int));

    // Print all prime numbers
    int k = 0;
    for (int p = 2; p <= n; p++)
    {

        if (prime[p])
        {
            v[k] = p;
            k++;
        }
    }
    return v;
}

void create_tests_for_random(ofstream &fout)
{
    int c = 0;
    fout << NUMBERS_1_6 << endl;
    while (c < NUMBERS_1_6)
    {
        int l = random() % SUP_LIMIT_1_6;
        fout << l << endl;
        c++;
    }
}

void create_tests_only_for_primes(ofstream &fout, int *v)
{
    int c = 0;
    fout << NUMBERS_6_12 << endl;
    while (c < NUMBERS_6_12)
    {
        int l = random() % SUP_LIMIT_7_12;
        if (v[l] != 0)
        {
            fout << v[l] << endl; //we write it from the array with primes
            c++;
        }
    }
}

void create_tests_for_primes_and_random(ofstream &fout, int *v)
{
    int c = 0;
    fout << NUMBERS_13_18 << endl;
    while (c < NUMBERS_6_12)
    {
        int l = random() % RAND_2;
        int t = random() % RAND_2;
        if (v[l] != 0 && v[l] >= INF_LIMIT && v[l] <= SUP_LIMIT_13_18 && t >= INF_LIMIT && t <= SUP_LIMIT_13_18)
        {
            fout << v[l] << endl; //one prime number
            fout << t << endl;    //one random number
            c++;
        }
    }
}

// utility function to find gcd of two numbers
int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

// utility function to find pow(x, y) under
// given modulo mod
int power(int x, int y, int mod)
{
    if (y == 0)
        return 1;
    int temp = power(x, y / 2, mod) % mod;
    temp = (temp * temp) % mod;
    if (y % 2 == 1)
        temp = (temp * x) % mod;
    return temp;
}

// This function receives an integer n and
// finds if it's a Carmichael number

unsigned int modexp(unsigned int a, unsigned int p, unsigned int n)
{
    unsigned long long b;
    switch (p)
    {
    case 0:
        return 1;
    case 1:
        return a % n;
    default:
        b = modexp(a, p / 2, n);
        b = (b * b) % n;
        if (p % 2 == 1)
            b = (b * a) % n;
        return b;
    }
}

bool isCarmichaelNumber(int n)
{
    int a, s;
    int factor_found = 0;
    if (n % 2 == 0)
        return 0;
    //else:
    s = sqrt(n);
    a = 2;
    while (a < n)
    {
        if (a > s && !factor_found)
        {
            return 0;
        }
        if (gcd(a, n) > 1)
        {
            factor_found = 1;
        }
        else
        {
            if (modexp(a, n - 1, n) != 1)
            {
                return 0;
            }
        }
        a++;
    }
    return 1; //is a carmichael
}

int *generate_charmichael_numbers(int p)
{
    int k = 0;
    int *array_for_charmichael = (int *)malloc(50 * sizeof(int));
    for (int i = 0; i < MAX; i++)
    {
        if (isCarmichaelNumber(i))
        {
            array_for_charmichael[k] = i;
            k++;
        }
    }
    return array_for_charmichael;
}

void create_tests_for_charmichael_and_random(ofstream &fout, int *v)
{
    int c = 0;
    int d = 0;
    int l = 0;
    fout << NUMBERS_19_24 << endl;
    while (c < CH_NB) //we will have 10 charmichael numbers for every test()
    {
        l = random() % 43;
        fout << v[l] << endl;
        c++;
    }
    while (d < (NUMBERS_19_24 - CH_NB))
    {
        l = random() % RAND;
        fout << l << endl;
        d++;
    }
}

int main()
{
    ofstream fout1;
    ofstream fout2;
    ofstream fout3;
    ofstream fout4;
    ofstream fout5;
    ofstream fout6;
    ofstream fout7;
    ofstream fout8;
    ofstream fout9;
    ofstream fout10;
    ofstream fout11;
    ofstream fout12;
    ofstream fout13;
    ofstream fout14;
    ofstream fout15;
    ofstream fout16;
    ofstream fout17;
    ofstream fout18;
    ofstream fout19;
    ofstream fout20;
    ofstream fout21;
    ofstream fout22;
    ofstream fout23;
    ofstream fout24;

    fout1.open("test1.in");
    create_tests_for_random(fout1);
    fout2.open("test2.in");
    create_tests_for_random(fout2);
    fout3.open("test3.in");
    create_tests_for_random(fout3);
    fout4.open("test4.in");
    create_tests_for_random(fout4);
    fout5.open("test5.in");
    create_tests_for_random(fout5);
    fout6.open("test6.in");
    create_tests_for_random(fout6);

    int n = SUP_LIMIT_7_12; //for the tests 7-12 the numbers are between 0-10000
    int *array1;
    array1 = SieveOfEratosthenes(n);

    fout7.open("test7.in");
    create_tests_only_for_primes(fout7, array1);
    fout8.open("test8.in");
    create_tests_only_for_primes(fout8, array1);
    fout9.open("test9.in");
    create_tests_only_for_primes(fout9, array1);
    fout10.open("test10.in");
    create_tests_only_for_primes(fout10, array1);
    fout11.open("test11.in");
    create_tests_only_for_primes(fout11, array1);
    fout12.open("test12.in");
    create_tests_only_for_primes(fout12, array1);
    int m = SUP_LIMIT_13_18; //for the tests 13-18 the numbers are between 10000-100000,
    int *array2 = (int *)malloc(m * sizeof(int));
    array2 = SieveOfEratosthenes(m);

    fout13.open("test13.in");
    create_tests_for_primes_and_random(fout13, array2);
    fout14.open("test14.in");
    create_tests_for_primes_and_random(fout14, array2);
    fout15.open("test15.in");
    create_tests_for_primes_and_random(fout15, array2);
    fout16.open("test16.in");
    create_tests_for_primes_and_random(fout16, array2);
    fout17.open("test17.in");
    create_tests_for_primes_and_random(fout17, array2);
    fout18.open("test18.in");
    create_tests_for_primes_and_random(fout18, array2);

    int p = MAX; //for the tests 19-24 the numbers we generate are between 0-1000000
    int *array_charmichael = generate_charmichael_numbers(p);
    fout19.open("test19.in");
    create_tests_for_charmichael_and_random(fout19, array_charmichael);
    fout20.open("test20.in");
    create_tests_for_charmichael_and_random(fout20, array_charmichael);
    fout21.open("test21.in");
    create_tests_for_charmichael_and_random(fout21, array_charmichael);
    fout22.open("test22.in");
    create_tests_for_charmichael_and_random(fout22, array_charmichael);
    fout23.open("test23.in");
    create_tests_for_charmichael_and_random(fout23, array_charmichael);
    fout24.open("test24.in");
    create_tests_for_charmichael_and_random(fout24, array_charmichael);
    free(array_charmichael);
    free(array1);
    free(array2);
    return 0;
}