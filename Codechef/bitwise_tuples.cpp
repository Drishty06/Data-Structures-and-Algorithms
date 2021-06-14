// problem link: https://www.codechef.com/JUNE21C/problems/BITTUP
// firstly tried the brute force approach by variable number of for loops and tried to observe the pattern
// and interestingly found an equation which satisfied all the test cases: (2^n - 1)^m
// but here binary exponention is used as well since modulo along with exponention
// for more info on binary exponention: https://cp-algorithms.com/algebra/binary-exp.html
#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long num) 
{
    a%=num;
    long long res=1;
    while(b > 0) 
    {
        if (b & 1) res = res * a % num;
        a = a * a % num;
        b /= 2;
    }
    return res;
}
int main() 
{ 
	long int t,n,m;
	cin>>t;
	for(int i=0; i<t ; i++)
	{
		cin>>n>>m;
		cout<<power((power(2,n,1000000007)-1),m,1000000007)<<endl;
	}
	return 0;
}

