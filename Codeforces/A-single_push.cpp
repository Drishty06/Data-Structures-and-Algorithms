// problem link: https://codeforces.com/problemset/problem/1253/A
// if - first different  - note its diff
// else - difference should be zero or similar to prev element's difference

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
		long int a[n], b[n];
		bool check = false;
		bool ans = true;
		long int diff;

		for(int j=0; j<n; j++)
		{
			cin>>a[j];
		}
		for(int j=0; j<n; j++)
		{
			cin>>b[j];
		}
		for(int j=0; j<n; j++)
		{
			if(check == false && (b[j]-a[j]) >0) 
			{
				// first different element
				check = true;
				diff = b[j]-a[j];
				continue;
			}
			if((b[j] - a[j] < 0) || (check == true && b[j]-a[j] != diff && b[j]-a[j] != 0) || (j != 0 && check == true && b[j]-a[j] != 0 && (b[j]-a[j] != b[j-1]-a[j-1])))
			{
				ans = false;
				// cout<<b[j]<<endl;
				break;
			}
		}
		if(ans == false) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
