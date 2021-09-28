// problem link: https://codeforces.com/contest/1579/problem/E1
#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		deque<int> d;
		long int n;
		cin>>n;
		long int arr[n];
		
		for(int j=0; j<n; j++)
		{
			cin>>arr[j];
 
		}
		d.push_back(arr[0]);
		for(int j=1; j<n; j++)
		{
			long int top=d.front();
			if(arr[j] <top) d.push_front(arr[j]);
			else d.push_back(arr[j]);
		}
 
		for (auto it = d.begin(); it != d.end(); ++it) cout <<*it<<" ";
		cout<<endl;
		
	}
	return 0;
}
