#include <bits/stdc++.h>
using namespace std;
// let one = number of 1s and two = number of 2s
// 12 - no
// 22 - no
// two = 1 - no
// two = 2 - no
// for 1s - zero losses - if 11 -> (=) and 12 -> (+ or =) taking = as common, whenever we see 1 we draw the match
// for 2s - atleast one win - if 21 -> (=, -) but as discussed above we will take only = condition
// and for 22 - we form a pattern - like ith player will win against i+1th 2 and last 2 will win against first 2
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int j=0; j<t; j++)
	{
		long int n;
		cin>>n;
		string s;
		cin>>s;
        vector<int> vec;
		for(int i=0; i<n; i++)
		{
			if(s[i] == '2') vec.push_back(i);
		}
		long int two = vec.size();
		if(two == 1 || two == 2)
		{
			cout<<"NO"<<endl;
			continue;
		}
		vector<string> ans(n, string(n, '='));
		for(int i=0; i<n; i++)
		{
			ans[i][i] = 'X';
		}
		for(int i=0; i<two; i++)
		{
			int x = vec[i], y = vec[(i+1) % two]; // circular selecting twos
			ans[x][y] = '+';
			ans[y][x] = '-';
		}
		cout<<"YES"<<endl;
		for(int i=0; i<n; i++) cout<<ans[i]<<endl;
	}
	return 0;
}
