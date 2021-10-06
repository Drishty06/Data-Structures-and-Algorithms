// problem link: https://codeforces.com/problemset/problem/1469/A
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long long int t;
	cin>>t;
	for(int z=0; z<t; z++)
	{
		string s;
		cin>>s;
		long long int len = s.length();

		if(len % 2 != 0 || s[0] == ')' || s[len-1] == '(') 
		{
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}
	return 0;
}
