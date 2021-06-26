// problem link: https://www.codechef.com/LTIME97C/problems/UNONE
// looking at the problem statement it seemed as bit manipulation complicated question but soon realizd that it was just a tiny logic
// logic: - ugliness score increases by 2 ways: 1. due to consecutive ones inside the number like "10110"
//                                              2. due to combination of ending ones with other number like "101" and "110"
//        - we cannot do anything for the 1st part but for the second part we can somehow try to break the chain by combining elements which have 0 at the end
//        - to have last element as zero we need even numbers which have last number always as zero 
//        - we first group all the even elements first and then the odd elements
//        - eg: for 3 5 6 8 4 possible ans can be: 6 8 4 5 3

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
		long long int arr[n],even[n],odd[n],count1=0,count2=0;
		for(int j=0; j<n; j++)
		{
		    cin>>arr[j]; 
		    if(arr[j] % 2 == 0)
		    {
		        even[count1]=arr[j];
		        count1++;
		    }
		    else
		    {
		        odd[count2]=arr[j];
		        count2++;
		    }
		}
	
		while(count1)
		{
		    cout<<even[count1-1]<<" ";
		    count1--;
		}
		while(count2)
		{
		    cout<<odd[count2-1]<<" ";
		    count2--;
		}
		cout<<"\n";
	}
	return 0;
}
