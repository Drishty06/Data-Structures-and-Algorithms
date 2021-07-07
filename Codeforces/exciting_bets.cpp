// problem link: https://codeforces.com/contest/1543/problem/A
// idea: (during the contest) I tried the question for 4-5 test cases and luckily after a lot research got a pettern which all of them satisfied

#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t ; i++)
	{
		long long int a,b;
        cin>>a>>b;
        cout<<abs(a-b)<<" ";
        long long int diff, count;
        diff=abs(a-b);
        
        if(diff != 0)
        {
            long long int temp=(a % diff);
            count=min(temp, abs(temp-diff));
            cout<<count<<endl;
        }
        else cout<<"0"<<endl;
	}
	return 0;
}
