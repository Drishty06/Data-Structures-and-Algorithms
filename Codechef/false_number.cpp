// problem link: https://www.codechef.com/LTIME97C/problems/FALSNUM
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t ; i++)
	{
		string str,str2;
		cin>>str;
		if(str[0] != '1') 
		{
		    str2='1';
		    str.insert(0, str2);
		}
		else
		{
		    str2='0';
		    str.insert(1, str2);
		}
		cout<<str<<endl;
		
	}
	return 0;
}
