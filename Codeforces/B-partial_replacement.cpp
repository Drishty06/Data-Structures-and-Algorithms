// problem link: https://codeforces.com/problemset/problem/1506/B
// idea is to find first occuring star and last occurring star
// and then keep on checking at every distance k if there is a need to convert star to cross

#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long long int t;
	cin>>t;
	for(int z=0; z<t; z++)
	{
		long long int n, k;
		cin>>n>>k;
		string s;
		cin>>s;
		long long int len = s.length();
		long long int start, end, ans=0;
		bool first = false;
		
		for(int i=0; i<len; i++)
		{
			if(s[i] == '*' && first == false)
			{
				start = end = i;
				first = true;
			}

			if(s[i] == '*') end = i;
		}
		// *....*..*.*...*  k=5

		if(start == end) ans = 1;
		else 
		{
			long int dist_from_last_appeared_star=1, star = start;
			for(int i=start+1; i<end; i++)
			{
				if(s[i] == '*') star = i;
				if(dist_from_last_appeared_star == k) 
				{
					ans++;
					dist_from_last_appeared_star = i-star;
				}
				dist_from_last_appeared_star++;
			}
			ans += 2;

		}

		cout<<ans<<endl;		
	}
	return 0;
}
