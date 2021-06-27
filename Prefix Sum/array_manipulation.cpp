// array manipulation - hackerrank
// problem link: https://www.hackerrank.com/challenges/crush/problem
// based on prefix sum + hashing

#include <bits/stdc++.h>
using namespace std;
const int n = 1e7+10; // large sized arrays should be declared globally
long long int arr[n]; // globally declared arrays will be intialized to zero

int main() 
{ 
	long int m;
	cin>>n>>m;
	while(m--)
	{
		int a, ,b, d;
		cin>>a>>b>>d;
		arr[a] += d;
		arr[b+1] -= d;
		for(int i=1; i<=n; i++)
		{
			arr[i] +=arr[i-1];
		}
		long long int max = -1;
		for(int i=1; i<=n; i++)
		{
			if(max < arr[i]) max = arr[i];
		}
		cout<<max<<endl;
	}
	return 0;
}
