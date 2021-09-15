// problem link: https://www.codechef.com/START11C/problems/MAX_DIFF
#include <bits/stdc++.h>
using namespace std;

int main() 
{
   long long int t;
   cin>>t;
   for(int i=0; i<t; i++)
   {
     long int n,s;
     cin>>n>>s;
     if(n >= s) cout<<s<<endl;
     else
     {
         cout<<2*n-s<<endl;
     }
   }
   return 0;
}
