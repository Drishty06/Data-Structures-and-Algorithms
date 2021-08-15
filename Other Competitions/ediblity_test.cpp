// problem link: https://www.hackerrank.com/contests/lgm-heist/challenges/edibility-test/problem
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    long int t, n;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>n;
        long long int arr[n], one = 0, two = 0;
        for(int j=0; j<n; j++)
        {
            cin>>arr[j];
            if(j < n/2) one+=arr[j];
            else two+=arr[j];
          
        }
        
         if(one == two ) cout<<"GOOD"<<endl;
            else cout<<"SPOILT"<<endl;
    }
    return 0;
}
