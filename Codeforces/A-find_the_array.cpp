// problem link: https://codeforces.com/contest/1550/problem/A
#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(double x) 
{   
   if(x - (int)x == 0) return true;
   return false;
} 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long int n, ans;
        cin>>n;
        double root = sqrt(n);
        
        if(isPerfectSquare(root)) ans = (int) root;
        else ans = ((int) root)+1;             
        cout<<ans<<endl;
        
        
	}
	return 0;
}
