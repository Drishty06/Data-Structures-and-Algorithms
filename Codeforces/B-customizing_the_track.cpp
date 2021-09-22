// problem link: https://codeforces.com/contest/1543/problem/B
// tried it for multiple test cases and noted the pattern and sectionized the code

#include <bits/stdc++.h>
using namespace std;
 
int main() 
{ 
	long int t;
	cin>>t;
	for(int i=0; i<t ; i++)
	{
		long long int n;
        cin>>n;
        long long int arr[n], sum=0, temp;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum % n == 0) cout<<"0"<<endl;
        else if(sum < n)
        {
            cout<<(sum*(n-sum))<<endl;
        }
        else 
        {
            temp=sum-((sum/n)*n);
            cout<<temp*(n-temp)<<endl;
        }
	}
	return 0;
}
