// problem link: https://codeforces.com/contest/1541/problem/A
#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	int t;
	cin>>t;
	for(int i=0; i<t ; i++)
	{
		int n;
		cin>>n;
		if(n % 2 == 0)
		{
		    for(int j=0; j<n-1; j+=2)
		    {
		        cout<<j+2<<" "<<j+1<<" ";
		    }
		}
		else
		{
		    for(int j=0; j<n-3; j+=2)
		    {
		        cout<<j+2<<" "<<j+1<<" ";
		    }
		    
		    cout<<n<<" "<<n-2<<" "<<n-1;
		}
		cout<<"\n";
	}
	return 0;
}
