// problem link: https://www.codechef.com/START11C/problems/FACEDIR/
#include <bits/stdc++.h>
using namespace std;

int main() 
{
   long long int t;
   cin>>t;
   
   for(int i=0; i<t; i++)
   {
     long int x;
     cin>>x;
     if(x%4 == 0) cout<<"North"<<endl;
     if(x%4 == 1) cout<<"East"<<endl;
     if(x%4 == 2) cout<<"South"<<endl;
     if(x%4 == 3) cout<<"West"<<endl;
   }
   return 0;
}
