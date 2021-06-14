// problem link: https://www.codechef.com/JUNE21C/problems/CHFHEIST/
#include <bits/stdc++.h>
using namespace std;
// p+p+..(d times)
// p+p+..(d times) + q+q+..(d times)
// p+p+..(d times) + 2*(q+q+..(d times))

// rather than using loop use simple mathematics
// my first code had the mistake with "m" 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t ; i++)
	{
		long int D,d,p,q;
		cin>>D>>d>>p>>q;
		long int n; // splitting on the basis of whether D is divisible by d 
		if(D % d == 0) 
		{
		    n=(D/d);
		    cout<<((p*d*n) + ((q*d)*((n-1)*(n))/2) )<<endl;
		}
		else 
		{
		    n=(D/d);
		    long int m = D%d;
		    long int sum = ((p*d*(n)) + ((q*d)*(((n)*(n-1)))/2) );
		    sum = sum + (m*(p + q*(n)));
		    cout<<sum<<endl;
		}
		
	}
	return 0;
}

