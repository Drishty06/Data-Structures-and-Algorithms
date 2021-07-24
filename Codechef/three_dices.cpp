// problem link: https://www.codechef.com/START6B/problems/THREDICE
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int x, y;
		cin>>x>>y;
		long int temp = 6-x-y;
		if(x+y < 6)
		{
    		double answer = temp/6.0;
    		answer = floor(answer * 1000000) / 1000000;
    		cout<<fixed<<setprecision(6)<<answer<<endl;
		}
		else cout<<"0"<<endl;
	}
	return 0;
}
