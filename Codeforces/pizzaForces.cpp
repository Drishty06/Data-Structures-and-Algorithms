// problem link: https://codeforces.com/contest/1555/problem/A
// logic:
// 1. time taken to make one small slice = 15/6 = 2.5
//                           medium slice = 20/8 = 2.5
//                           large slice = 25/10 = 2.5
// that means time taken by each slice is equivalent for all sizes
// 2. ow we want a number extremely closest to n
// so that koi extra slices mate time na apvo pde
// and magic is that every even number will always be fitted into that equation
// because we have 6s + 8m + 10 l
// and we want this number to be extremely closest to n
// since all even numbers are valid and will fir into above equation
// and in case that's a odd number, we have to reach to exactly next even number


#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long long int n, ans;
        cin>>n;
        if(n <= 6) ans = 15;
        else if(n % 2 != 0) ans = 2.5 * (n+1);
        else ans = 2.5 * n;
        cout<<ans<<endl;
        
    
	}
	return 0;
}
