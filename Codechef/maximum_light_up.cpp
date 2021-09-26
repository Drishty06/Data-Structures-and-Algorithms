// problem link: https://www.codechef.com/START13B/problems/DIWALI1
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int p, a, b, c, x,y, ans;
		cin>>p>>a>>b>>c>>x>>y;
		if((a*x+b) < (a*y +c)) ans = (p/(a*x +b));
		else ans= (p/(a*y +c));
		cout<<ans<<endl;
	}
	return 0;
}
