// problem link: https://www.codechef.com/LTIME98C/problems/BUTYPAIR

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
		long int pair = n*(n-1); 
		long int arr[n];
		map<long int, long int> mp;
		for(int j=0; j<n; j++)
		{
		    cin>>arr[j];
		    mp[arr[j]]++;
		}
		
		for(auto k:mp)
		{
		    if(k.second > 1) pair = pair - ((k.second) * (k.second-1));
		}
		cout<<pair<<endl;
		
		
	}
	return 0;
}
