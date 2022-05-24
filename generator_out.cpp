#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

// Driver Program to test above function
int main()
{
    string test_name = " ";
    int m;
    cin >> test_name;
    ifstream file1;
    file1.open(test_name);
    std::string line;
    getline(file1, line);
    sscanf(line.c_str(), "%d", &m);

    int l = 0;
    int *array_with_primes;
    array_with_primes = (int *)malloc(m * sizeof(int));
    while (!file1.eof())
    {
        getline(file1, line);
        int t = 0;
        sscanf(line.c_str(), "%d", &t);
        if (isPrime(t))
        {
            array_with_primes[l] = t;
            l++;
        }
    }
    string test_name2 = " ";
    cin >> test_name2;
    ofstream fout;
    fout.open(test_name2);

    int primes_counter = 0;
    for (int i = 0; i < m; i++)
    {
        if (array_with_primes[i])
        {
            primes_counter++;
        }
    }
    fout << primes_counter << endl;

    for (int i = 0; i < m; i++)
    {
        if (array_with_primes[i])
        {
            fout << array_with_primes[i] << endl;
        }
    }
    free(array_with_primes);
    return 0;
}