// problem link: https://codeforces.com/contest/1542/problem/B
// try to make a tree of all such possiblities and
// it can be noticed that every such number will be of the type:
// a^x + y*b = n --> (n - temp) % b == integer --> temp*=a;
#include <bits/stdc++.h>
using namespace std;

bool checker(long long int n, long long int a, long long int b)
{
    long long int x=1;
    while(x <= n)
    {
        if((n - x) % b == 0)
        {
            return true;
        }
        if(a == 1) break;
        x*=a;
    }        
    return false;
}
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t ; i++)
	{
		long long int n, a, b;
        cin>>n>>a>>b;
        if(checker(n, a, b)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
	}
	return 0;
}
