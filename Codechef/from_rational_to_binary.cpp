// problem link: https://www.codechef.com/LTIME97C/problems/REALBIN/
// logic I used: - when the fraction wil be a recurring decimal -> false else true
// to check the same we have the logc as:
// Express the denominator as the product of its prime factors.
// If the prime factorization contains only factors of 2 and 5, the decimal representation will terminate. If any factors other than 2 and 5 are present, the fraction will have a repeating decimal.
// for more info on the same visit: https://www.geeksforgeeks.org/find-recurring-sequence-fraction/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      long long int a,b;
        cin>>a>>b;
        if((b&(b-1))==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
  }
  return 0;
}
