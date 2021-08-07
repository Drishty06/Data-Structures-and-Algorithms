// problem link: https://codedrills.io/contests/icpc-amritapuri-2020-preliminary-round/problems/the-married-unmarried-riddle
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		string str, ans;
		cin>>str;
		long int len = str.length();
		bool flag = false;
		if(len == 1) ans = "No";
		if(len == 2) 
		{
			if(str == "MU" || str == "M?") 
			{
				ans = "Yes";
				flag = true;
			}
			else 
			{
				ans = "No";
				flag = true;
			}
		}
		if(len > 2)
		{
			if(str[0] == '?') str[0] = 'U';
			if(str[len-1] == '?') str[len-1] = 'M';
			for(int i=1; i<len; i++)
			{
				
				
					if(str[i] == '?') 
					{
						if(str[i-1] == 'M')
						{
							str[i] = 'M';
						}
						else{
							str[i] = 'U';
						}
					}
					if(str[i-1] == 'M' && str[i] == 'U') 
					{
						ans = "Yes";
						flag= true;
						break;
					}
				
				
			}
			if(flag == false) ans = "No";

		}
		cout<<ans<<endl;
		

		
	}
	return 0;
}
