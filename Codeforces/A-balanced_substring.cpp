#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
        long int len;
        cin>>len;
		string s;
        cin>>s;
        bool check = false;
        for(int i=1; i<len; i++)
        {
            if((s[i] == 'a' && s[i-1] == 'b') || (s[i] == 'b' && s[i-1] == 'a'))
            {
                cout<<i<<" "<<i+1<<endl;
                check = true;
                break;
            }
        }
        if(check == false) cout<<"-1 -1"<<endl;
	}
	return 0;
}
