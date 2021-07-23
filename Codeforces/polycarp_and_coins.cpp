// problem link:

#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long long int n, c1, c2;
        cin>>n;
        if(n % 3 == 0)
        {
            c1=(n/3);
            c2=(n/3);
        }
        else if((n-1) % 3 == 0)
        {
            c1=(n+2)/3;
            c2=(n-1)/3;
            if(c1+2*c2 != n) swap(c1,c2);
        }
        else
        {
            c1=(n+1)/3;
            c2=(n-2)/3;
            if(c1+2*c2 != n) swap(c1,c2);
        }
        cout<<c1<<" "<<c2<<endl;
	}
	return 0;
}
