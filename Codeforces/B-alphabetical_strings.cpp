// problem link: https://codeforces.com/contest/1547/problem/B
#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int j=0; j<t; j++)
	{
		string str;
        cin>>str;
        int check[26] = {0};
        long int n=str.length();
        bool flag=1;
        if(n <=2 )
        {
            if(n == 1) 
            {
                if(str[0] != 'a') cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
            else{
                if((str[0] == 'a' && str[1] == 'b') || str[0] == 'b' && str[1] == 'a')
                {
                    cout<<"YES"<<endl;
                }
                else cout<<"NO"<<endl;
            }
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                check[str[i]-97]++;
            }
            for(int i=0; i<n; i++)
            {
                if(check[i] == 0)
                {
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                for(int i=1; i<n-1; i++)
                {
                    if(str[i] > str[i-1] && str[i] > str[i+1])
                    {
                        cout<<"NO"<<endl;
                        flag=0;
                        break;
                    }
                }
 
            }
            if(flag == 1) cout<<"YES"<<endl;
        }    
	}
	return 0;
