// problem link: https://codeforces.com/contest/1551/problem/B1

#include <bits/stdc++.h>
using namespace std;
 
int countDistinct(string s, int n) 
{ 
 
    unordered_map<char, int> m; 
  
    for (int i = 0; i < n; i++) { 
        m[s[i]]++; 
    } 
    long int count=0, len=m.size();
     
    for (auto i : m)
    {
        if(i.second >=2) count++;
    }
    
    return (m.size()+count);
} 
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		string s;
        cin>>s;
        long int n=s.length(),k;
        k=countDistinct(s, n);
        cout<<k/2<<endl;
	}
	return 0;
}
