// problem link: https://www.codechef.com/START6B/problems/CRICRANK
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int r1, w1, c1, r2, w2, c2, a=0, b=0;
		cin>>r1>>w1>>c1;
		cin>>r2>>w2>>c2;
		if(r1 > r2) a++;
		else b++;
		if(c1 > c2) a++;
		else b++;
		if(w1 > w2) a++;
		else b++;
		if(a > b) cout<<"A"<<endl;
		else cout<<"B"<<endl;
	}
	return 0;
}
