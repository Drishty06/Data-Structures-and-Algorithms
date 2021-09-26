// problem link: https://www.codechef.com/START13B/problems/MAGDOORS
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
		long int len = s.length(),count=0;
		// 1 open
		if(s[0] == '0') count++;
		for(int j=1; j<len; j++)
		{
		    if(s[j] != s[j-1]) count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
