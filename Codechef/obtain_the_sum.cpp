// problem link: https://www.codechef.com/START11C/problems/BIGARRAY
#include <bits/stdc++.h>
using namespace std;

int main() 
{
   long long int t;
   cin>>t;
   for(int i=0; i<t; i++)
   {
     long long int n, s, sum;
     cin>>n>>s;
     sum =((n*(n+1))/2);
     if(sum - s >0 && sum-s <= n) cout<<sum-s<<endl;
     else cout<<-1<<endl;
   }
   return 0;
}
