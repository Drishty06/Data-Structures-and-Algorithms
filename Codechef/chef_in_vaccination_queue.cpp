// problem link: https://www.codechef.com/START13B/problems/VACCINQ/
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
	    long int n, p, x,y;
	    cin>>n>>p>>x>>y;
	    long int arr[n], t=0;
	    for(int j=0; j<n; j++)
	    {
	        cin>>arr[j];
	        if(j+1 <= p)
	        {
	            if(arr[j] == 1) t+=y;
	            else t+=x;
	        }
	    }
	    cout<<t<<endl;
		
	}
	return 0;
}
