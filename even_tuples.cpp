// problem link: https://www.codechef.com/START6B/problems/ETU
P#include <bits/stdc++.h>
using namespace std;


int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int n, q;
        cin>>n>>q;
        long int arr[n], odd[n+1], even[n+1], e=0, o=0;
        odd[0]=0, even[0]=0;
        for(int j=0; j<n; j++)
        {
            cin>>arr[j];
            if(arr[j]% 2 == 0) 
            {
                even[j+1]=(++e);
                odd[j+1]=o;
            }
            else 
            {
                even[j+1]=e;
                odd[j+1]=(++o);
            }
        }
        long int l, r, ans=0;
        for(int j=0; j<q; j++)
        {
            cin>>l>>r;
            long int n_odd = odd[r]-odd[l-1]; 
            long int n_even = even[r]-even[l-1];
            ans = n_even*(n_odd*(n_odd-1))/2 + (n_even*(n_even-1)*(n_even-2))/6;
            cout<<ans<<endl;
        }

	}
	return 0;
}
