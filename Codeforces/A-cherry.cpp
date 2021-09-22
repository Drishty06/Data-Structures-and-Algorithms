// problem link: https://codeforces.com/contest/1554/problem/A

#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int n;
        cin>>n;
        long long int arr[n], pdt=0;
        for(int j=0; j<n; j++)
        {
            cin>>arr[j];
        }
        for(int j=1; j<n; j++)
        {
            pdt = max(pdt, arr[j]*arr[j-1]);
        }
        cout<<pdt<<endl;
	}
	return 0;
}
