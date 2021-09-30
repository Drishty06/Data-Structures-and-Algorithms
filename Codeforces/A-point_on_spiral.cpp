// problem link: 
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int x, y, ans;
	cin>>x>>y;
	long int maxi = max(abs(x), abs(y));
	ans = 4*(maxi-1); // ans=4
	//cout<<ans;
	bool check = true;
	if( x == 1 && y == 0) 
	{
		ans = 0;
		check = false;
	}
	if(x == 0 && y == 0)
	{
		ans= 0;
		check = false;
	}
	if(((abs(x) != abs(y) || (abs(abs(x) - abs(y)) == 1 && x>0 && y<0 ))) && check == true) 
	{
		if(x == maxi) ans +=1;
		else if((-x) == maxi) ans+= 3;
		else if(y == maxi) ans+= 2;
		else if((-y) == maxi) ans+=4;
	}
	else if(((abs(x) == abs(y) )) && check == true)
	{
		if(x>0 && y>0) ans+=1;
		if(x<0 && y>0) ans+=2;
		if(x<0 && y<0) ans+=3;
		if(x>0 && y<0) ans+=4;
	}
	if (abs(abs(x) - abs(y)) == 1 && x>0 && y<0 && check == true) ans-=1;
	cout<<ans;
	return 0;
}
