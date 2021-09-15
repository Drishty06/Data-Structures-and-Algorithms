// problem link: https://www.codechef.com/START11C/problems/FILLGRID
#include <bits/stdc++.h>
using namespace std;

int main() 
{
   long long int t;
   cin>>t;
   for(int i=0; i<t; i++)
   {
     long int n;
     cin>>n;
     if(n != 2)
     {
         for(int j=0; j<n; j++)
         {
             for(int k=0; k<n; k++)
             {
                 if(k == j) cout<<-1<<" ";
                 else cout<<1<<" ";
             }
             cout<<endl;
         }
     }
     else 
     {
         cout<<-1<<" "<<-1<<endl;
         cout<<-1<<" "<<-1<<endl;
     }
   }
   return 0;
}
