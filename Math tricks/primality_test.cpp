// used for: Given a number n, check if it is prime or not
// a*b=n
// For a divisor a, b one of the divisors lies above sqrt(n) and one will be below sqrt(n)
// time complexity : O (sqrt (n))

bool isPrime(int n)
{
  if(n == 1) return false;
  for(int i=2; i*i<=n; i++)
  {
    if(n % i == 0) return false;
  }
  return true;
}
