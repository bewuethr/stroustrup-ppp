// Chapter 04, exercise 11: find all primes between 1 and 100
// Exercise 12: find all primes from 1 to given value max
// Exercise 13: find primes from 1 to 100 using the Sieve of Eratosthenes
// Exercise 14: find primes from 1 to given value max using the Sieve
// Exercise 15: find first n primes using Sieve of Eratosthenes

#include "../lib_files/std_lib_facilities.h"

vector<int> primes_norm;

bool is_prime(int n)
{
    for (int i = 0; primes_norm[i]<=sqrt(n); ++i) {
        if (n%primes_norm[i]==0)
            return false;
    }
    return true;
}

int main()
{
    cout << "How many primes should I find?\n";
    int n_primes = 0;
    cin >> n_primes;
    primes_norm.push_back(2);
    int i = 3;
    while (primes_norm.size() < n_primes) {
        if (is_prime(i))
            primes_norm.push_back(i);
        cout << i << endl;
        i+=2;
    }
}
