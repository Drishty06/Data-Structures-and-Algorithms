// problem link: https://www.codechef.com/START8C/problems/PENALTY
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
	    long int one=0, two=0, n;
		for(int j=0; j<10; j++)
    	{
    		cin>>n;
    		if(j % 2 == 0 && n == 1) two++;
    		else 
    		{
    		    if(n == 1)one++;
    		}
    	}
    	if(one == two) cout<<"0"<<endl;
    	if(one>two) cout<<"2"<<endl;
    	if(two > one) cout<<"1"<<endl;
	}
	return 0;
}
