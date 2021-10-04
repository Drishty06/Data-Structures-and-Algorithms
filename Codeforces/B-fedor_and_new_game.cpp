// problem link: https://codeforces.com/problemset/problem/467/B 
#include <bits/stdc++.h>
using namespace std;
 
int kthBit(unsigned int n, unsigned int k)
{		
	return ((n & (1 << (k - 1))) >> (k - 1));		
}
 
int main() 
{ 
	long int n, m, k, count=0, diff=0, maxi=0;
	cin>>n>>m>>k;
	long int arr[m+1];
	for(int i=0; i<m+1; i++)
	{
		cin>>arr[i];
		if(maxi < arr[i]) maxi = arr[i];
	}
	
	for(int i=0; i<m; i++)
	{
		diff=0;
		for(int j=0; j<=(int)(log2(maxi)+1); j++)
		{
			 if(kthBit(arr[i], j) != kthBit(arr[m], j)) diff++;
		}
		if(diff <= k) count++;
	}
 
	cout<<count<<endl;
} 
