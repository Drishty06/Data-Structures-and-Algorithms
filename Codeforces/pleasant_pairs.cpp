// problem link: https://codeforces.com/contest/1541/problem/B
#include<bits/stdc++.h>
using namespace std;
 
void solve()
{
    long long int n;
    cin>>n;
    long long int arr[n];
    unordered_map<long long int,long long int> mp;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        mp[arr[i]] = i+1;     // this map stores array element as keys and its index as values
    }
    int ans=0;                // i*j = mp[i] + mp[j] (max(mp[i] + mp[j]) = n+n-1 = 2n-1) max summation value is when last two elements combine
    for(int i=1; i<=2*n; i++) // since array elements <= 2*n acc to problem
    {                         // i -> fixed
        if(mp.find(i) != mp.end())
        {
          for(int j=i+1; i*j<=2*n; j++) // condition of this for loop plays the major role
          {                              
            if(mp.find(j) != mp.end())
            {
                ans += (i*j==(mp[i]+mp[j]));
            }
          }
        }
    }
    cout<<ans<<endl;
} 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
