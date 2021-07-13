// problem link: https://codingcompetitions.withgoogle.com/kickstart/round/00000000004361e3/000000000082b813
#include <bits/stdc++.h>
using namespace std;

int check(int r2, int c2, int dl, int dr, int ans)
{
    if((r2 == c2 && (r2%2 == 0 && c2%2 == 0))  && (r2 == dl && (r2%2 == 0 && dl%2==0)) && (r2 == dr && (r2%2 == 0 && dr%2 == 0))) return 4;
    else if(((r2 == c2 && r2 == dl) &&(r2%2 == 0 && c2%2 == 0 && dl%2 == 0))||((r2 == c2 && r2 == dr) &&(r2%2 == 0 && c2%2 == 0 && dr%2 == 0))||((r2 == dr && r2 == dl) &&(r2%2 == 0 && dr%2 == 0 && dl%2 == 0))|| ((c2 == dl && c2 == dr) &&(dr%2 == 0 && c2%2 == 0 && dl%2 == 0)))
    return 3;
    else if(((r2 == c2 && (r2%2 == 0 && c2%2 == 0))|| (r2 == dl &&(r2%2 == 0 && dl%2 == 0))|| (r2 == dr &&(r2%2 == 0 && dr%2 == 0)) || (c2 == dl && (c2%2 == 0 && dl%2 == 0)) || (c2 == dr &&(dr%2 == 0 && c2%2 == 0)) || (dl == dr && (dl%2 == 0 && dr%2 == 0))))
    return 2;
    else if((r2%2 == 0 || c2%2 == 0 || dl%2 == 0 || dr%2 == 0))return 1;
    return 0;
}
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		long long int g00, g01, g02, g10, g12, g20, g21, g22;
		long long int ans=0;
		long long int r2, c2, dl, dr;
		cin>>g00>>g01>>g02;
		cin>>g10>>g12;
		cin>>g20>>g21>>g22;
		if(g01-g00 == g02-g01) ans+=1;
		if(g21-g20 == g22-g21) ans+=1;
		if(g10-g00 == g20-g10) ans+=1;
		if(g12-g02 == g22-g12) ans+=1;
		r2 = g12+g10;
		c2 = g21+g01;
		dl = g22+g00;
		dr = g20+g02;
        
		ans+=check(r2, c2, dl, dr, ans);
        
		
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}
