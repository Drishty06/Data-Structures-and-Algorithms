// problem link: https://codeforces.com/contest/1535/problem/A
#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t ; i++)
	{
		int s[4];
		cin>>s[0]>>s[1]>>s[2]>>s[3];
		long int p1=max(s[0], s[1]);
		long int p2=max(s[2], s[3]);
		sort(s, s+4);
		if((p1 == s[2] && p2 == s[3]) || (p2 == s[2] && p1 == s[3]) ) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
