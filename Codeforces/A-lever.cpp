// problem link: https://codeforces.com/problemset/problem/376/A
// centre of mass question
#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	string s;
	cin>>s;
	long long int len = s.length();
	long long int left=0, right=0, pivot=0;
 
	for(int j=0; j<len; j++)
	{
		if(s[j] == '^')
		{
			pivot = j;
			break;
		}
	}
	for(int i=0; i<len; i++)
	{
		if(i < pivot && s[i] >= '1' && s[i] <= '9')
		{
			left += ((s[i]-48) * (i-pivot));
		}
 
		if(i > pivot && s[i] >= '1' && s[i] <= '9')
		{
			right += (s[i]-48) * (i-pivot);
		}
		
	}
	//cout<<left<<" "<<right;
	if(left + right == 0) cout<<"balance"<<endl;
	else if(left + right < 0) cout<<"left"<<endl;
	else cout<<"right"<<endl;
	return 0;
} 
