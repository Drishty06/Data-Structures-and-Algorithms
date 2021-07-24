// problem link: https://www.codechef.com/START6B/problems/JOKRBTMN
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int n, m, l;
        cin>>n>>m>>l;
        unordered_map <int, int> mp;
        for(int j=0; j<m; j++)
        {
            long int k;
            cin>>k;
            for(int it=0; it<k; it++)
            {
                long int input;
                cin>>input;
                mp[input] = j;
            }
        }
        long int strip[l], count=1;
        for(int it=0; it<l; it++)
        {
            cin>>strip[it];
        }
        for(int it=0; it<l-1; it++)
        {
            if(mp[strip[it]] != mp[strip[it+1]]) count++;
        }
        cout<<count<<endl;


	}
	return 0;
}
