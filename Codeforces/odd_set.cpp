// problem link: https://codeforces.com/contest/1542/problem/A
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
        long long int arr[2*n], even=0, odd=0;
        for(int j=0; j<2*n; j++)
        {
            cin>>arr[j];
            if(arr[j] % 2 == 0) even++;
            else odd++;
        }
        if(even == odd) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
	}
	return 0;
}
