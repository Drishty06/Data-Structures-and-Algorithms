// print x^n using recursion:
// naive way isuse the logic: x*func(x, n)
// to optimize it we use logarithimic logic: x^n = x^n/2 * x^n/2 if n---->even
//                                           x^n = x^n/2 * x^n/2 * x if n---->odd
int power(int x, int n)
{
  if(n == 0) return 1;
  int temp = power(x, n/2);
  int ans = temp*temp;
  if(n % 2 == 0)
  {
    ans = ans*x;
  }
  return ans;
}
