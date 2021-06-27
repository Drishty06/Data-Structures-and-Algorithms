// problem link: https://www.codechef.com/START5B/problems/BLITZ3_2/
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int a,b,n;
        cin>>n>>a>>b;
        cout<<(2*(180+n) - a - b)<<endl;       
	}
	return 0;
}
