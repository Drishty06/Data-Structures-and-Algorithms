// problem link: https://www.codechef.com/LTIME98C/REDALERT
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int n, d, h, level=0, zero = 0;
		cin>>n>>d>>h;
		long int arr[n];
		bool alert = false;
		for(int j=0; j<n; j++)
		{
		    cin>>arr[j];
		}
		for(int j=0; j<n; j++)
		{
		    if(arr[j] != 0) 
		    {
		        level += arr[j];
		        if(level > h)
		        {
		            cout<<"YES"<<endl;
		            alert = true;
		            break;
		        }
		    }
		    else 
		    {
		        level = max(zero, level - d);
		    }
		}
		if(alert == false) cout<<"NO"<<endl;
		
	}
	return 0;
}
