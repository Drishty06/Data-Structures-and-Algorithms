// problem link: https://codeforces.com/contest/1579/problem/A
#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		string s;
		cin>>s;
		long int len = s.length(), aAndc=0, b=0;
		for(int j=0; j<len;j++)
		{
			if(s[j]== 'A' || s[j]== 'C') aAndc++;
			else b++;
		}
		if(b == aAndc) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
