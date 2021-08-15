// problem link: https://www.hackerrank.com/contests/lgm-heist/challenges/encode-the-string
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    long int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        string str;
        cin>>str;
        long long int len = str.length(), count = 1;
        int j;
        for(j=1; j<len; j++)
        {
            if(j == 1 ) 
            {
                if(str[j] != str[0])
                {
                    cout<<1<<str[0];
                    count = 1;
                    //cout<<"hi";
                    
                }
                else count++;
                continue;
            }
            if(j != 1 && str[j] == str[j-1])
            {
                if(count < 9)
                {
                    count++;
                }
                else
                {
                    cout<<count<<str[j];
                    count=1;
                }
            }
            else 
            {
                if(count == 0) count =1;
                cout<<count<<str[j-1];
                count=1;
            }
           // cout<<j<<" " <<count<<endl;

            
        }
        cout<<count<<str[j-1]<<endl;
    }
    return 0;
}
