// problem link: https://www.codechef.com/START8C/problems/JAVELIN
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t, n, m, x;
	cin>>t;
	for(int i=0; i<t; i++)
	{
	    long long int k=0, idx=0, y=0;
		cin>>n>>m>>x;
		long long int arr[n], ans[n], extra[n];
		unordered_map<int, int> mp;

		for(int j=0; j<n; j++)
		{
		    cin>>arr[j];
		    if(arr[j] >= m) 
		    {
		        k++;
		        ans[idx++]=j;
		    }
		    else
		    {
		       // cout<<"x"<<x<<j<<endl;
		        extra[y] = arr[j];
		        mp[arr[j]] = j;
		        y++;
		        
		    }
		    
		}
		//y--;
	
		//cout<<"x"<<x<<endl;
		if(k < x)
		{
		    sort(extra, extra+y);
		  //  	for(int index=0; index<y; index++)
		  //  {
		  //      cout<<extra[index]<<" ";
		  //  }
		    for(int j=y-1; j>=0; j--)
		    {
		        if(k < x)
		        {
		            ans[idx] = mp[extra[j]];
		            k++;
		            idx++;
		        }
		        else break;
		    }
		    sort(ans, ans+k);
		    cout<<k<<" ";
		    for(int index=0; index<k; index++)
		    {
		        cout<<ans[index]+1<<" ";
		    }
		}
		else
		{
		    sort(ans, ans+k);
		    cout<<k<<" ";
		    for(int index=0; index<k; index++)
		    {
		        cout<<ans[index]+1<< " ";
		    }
		    
		}
		cout<<endl;
		
	}
	return 0;
}
