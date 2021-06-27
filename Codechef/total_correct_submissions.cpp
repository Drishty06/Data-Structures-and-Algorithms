// problem link: https://www.codechef.com/START5B/problems/TOTCRT/
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int>& a,
         pair<string, int>& b)
{
    return a.second < b.second;
}

void sort(unordered_map<string, int>& M)
{
  
    // Declare vector of pairs
    vector<pair<string, int> > A;
  
    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : M) {
        A.push_back(it);
    }
  
    // Sort using comparator function
    sort(A.begin(), A.end(), cmp);
  
    // Print the sorted value
    for (auto& it : A) {
  
        cout <<  it.second << " " ;
    }
}
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t; i++)
    	{
		long int n;
        unordered_map <string,int> mp;
        cin>>n;
        for(int j=0; j<3*n; j++)
        {
            string s;
            cin>>s;
            long int value;
            cin>>value;
            mp[s]+=value;
        }
        sort(mp);
        cout<<"\n";
	}
	return 0;
}
