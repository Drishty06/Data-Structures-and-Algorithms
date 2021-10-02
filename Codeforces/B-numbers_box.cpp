// problem link: https://codeforces.com/problemset/problem/1447/B
// if there are even number of non-positive numbers (number >= 0) then ans will be equal to sum all elements simply
// if there are odd number of non-positive numbers(number >= 0) then ans will be equal to sum all elements - min_absolute value from all elements
 
#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int z=0; z<t; z++)
	{
		long int n, m;
		cin>>n>>m;
		long int a[n][m], total_abs_sum=0, mini = INT_MAX, ans, negative=0;
 
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cin>>a[i][j];
				total_abs_sum += abs(a[i][j]);
				if(a[i][j] <= 0) negative++;
				if(abs(a[i][j]) < mini) mini = abs(a[i][j]);
			}
		}
 
		if(negative% 2 != 0) ans = total_abs_sum - (2*abs(mini));
		else ans = total_abs_sum;
		cout<<ans<<endl;
		
	}
} 
