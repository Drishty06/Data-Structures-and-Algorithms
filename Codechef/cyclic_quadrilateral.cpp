// problem link: https://www.codechef.com/START5B/problems/CYCLICQD
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a+c == 180 && b+d == 180) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
	}
	return 0;
}
