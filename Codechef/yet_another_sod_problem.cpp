// problem link: https://www.codechef.com/LTIME100B/problems/SOD3/
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long long int l, r, ans;
		cin>>l>>r;
		ans=(r/3)-(l/3);
		if(l%3 == 0 ) ans++;
		
		cout<<ans<<endl;
	}
	return 0;
}
