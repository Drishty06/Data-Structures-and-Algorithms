#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	int t;
	cin>>t;
	for(int i=0; i<t ; i++)
	{
		int xa,xb,ya,yb;
		cin>>xa>>xb>>ya>>yb;
		cout<<(ya/xa)+(yb/xb)<<endl;
	}
	return 0;
}
