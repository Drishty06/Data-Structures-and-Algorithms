// problem link: https://www.codechef.com/LTIME97C/problems/CHFRICH/
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t ; i++)
	{
		long long int a,b,x;
        cin>>a>>b>>x;
        cout<<(b-a)/x<<endl;
	}
	return 0;
}
