// problem link: https://www.codechef.com/LTIME98C/problems/CHFSPL
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int a, b, c, max;
		cin>>a>>b>>c;
		if(a+b > b+c) max = a+b;
		else max = b+c;
		if(max < a+c) max = a+c;
		cout<<max<<endl;
		
	}
	return 0;
}
