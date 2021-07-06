// Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number. 
// The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so
// Suppose we need to answer q queries and  q<=million
// And check whether n is prime for n<=10^7
// Everytime we cannot run a loop since it will be O(n*q) = 10^13 - >not possible
// Therefore we preprocess the numbers by creating an extra array:
// Time complexity: O(N log(log N))
// Space complexity: O(N)
// for more info: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
//                https://www.youtube.com/watch?v=1K-NPoepIHc&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=4
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize all entries it as true.
    // A value in prime[i] will finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or equal to the square of it numbers which are multiple
            // of p and are less than p^2 are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
