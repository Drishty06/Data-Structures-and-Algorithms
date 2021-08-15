// problem link: https://www.hackerrank.com/contests/lgm-heist/challenges/most-frequent-prime-number#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
  if(n == 1) return false;
  for(int i=2; i*i<=n; i++)
  {
    if(n % i == 0) return false;
  }
  return true;
}

int main() 
{ 
    long int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        long int n;
        cin>>n;
        long long int arr[n];
        for(int j=0; j<n; j++)
        {
            cin>>arr[j];
        }
        unordered_map<long int, long int> mp;
        for(int j=0; j<n; j++)
        {
            if(isPrime(arr[j]) || arr[j] == 2)
            {
                mp[arr[j]]++;
            }
        }
        // for(auto x: mp)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        long int  max=0, ans=INT_MAX;
        for(auto x: mp)
        {
            if(x.second > max) 
            {
                max = x.second;
                ans = x.first;
            }
            if(x.second == max && x.first < ans) 
            {
                max = x.second;
                ans = x.first;
            }
            
        }
        if(max == 0) cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
