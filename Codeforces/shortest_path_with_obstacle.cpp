// problem link: https://codeforces.com/contest/1547/problem/A
#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t ; i++)
	{
		long long int xa,xb,xf,ya,yb,yf,ans;
        cin>>xa>>ya;
        cin>>xb>>yb;
        cin>>xf>>yf;
        if(xa != xb && ya != yb) ans=(abs(xa-xb)+abs(ya-yb));
        if(xa == xb)
        {
            if(xf == xa && ((yf < ya && yf > yb) || (yf > ya && yf < yb)))
            {
                ans=abs(ya-yb)+2;
            }
            else
            {
                ans=abs(ya-yb);
            }
        }
        if(ya == yb )
        {
            if(yf == ya && ((xf < xa && xf > xb) || xf > xa && xf < xb))
            {
                ans=abs(xa-xb)+2;
            }
            else
            {
                ans=abs(xa-xb);
            }
        }
        cout<<ans<<endl;
        
	}
	return 0;
}
