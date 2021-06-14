// problem link: https://www.codechef.com/JUNE21C/problems/SHROUTE/
// firstly i did this using an approach having nested loops but then optimized it O(n)
// logic: create to arrays. one to store occurences of "1" from starting (since station having 1 will have the train which will be moving towards right)
// and the second to store the occurences of "2" from end (since the stations having 2 will have the trains which will be moving towards right)
// these to arrays store the index of the nearest 1 and 2 respectively
// later we substract the final destination from the respective index and find the minimum of the too

#include <bits/stdc++.h>
using namespace std;
int main() 
{ 
	long int t, n, m;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>n>>m;
		long int train[n];
		long int arr[m];
		long int left[n], right[n];
		for(int j=0; j<n; j++) // input: train status on each chefland
		{
		    cin>>train[j];
		}
		
		for(int j=0; j<m; j++) // input: final destination a traveller wants to reach
		{
		    cin>>arr[j];
		}
		
		long int temp=-1, result; // temp=-1 is store those index as -1 where we don't have any 1 on its left and similarly, and 2 on its right
		
		for(int k=0; k<n; k++) // traversing from start and storing index of nearest 1 in the "right" array
		{
		    if(train[k] == 1) temp=k;
		    right[k]=temp;
		}
		temp=-1;
		
		for(int k=n-1; k>=0; k--) // traversing from end and storing the index of nearest 2 in the "left" array
		{
		    if(train[k] == 2) temp=k;
		    left[k]=temp;
		}
		left[0]=0; // to cover the corner case : even if there's no train at station 1, still there won't be any time required since passenger is initially at station 1 only
		right[0]=0;
		for(int j=0; j<m; j++)
		{
		    if(left[arr[j]-1] == -1 && right[arr[j]-1] == -1) result=-1; // the case when the destination doesn't have any 1s on its left nor any 2s on its right
		    else if(right[arr[j]-1] == -1 && left[arr[j]-1] != -1) result=(left[arr[j]-1]-arr[j]+1); // these two cases cover when any one of the, is -1
		    else if(left[arr[j]-1] == -1 && right[arr[j]-1] != -1) result=(arr[j]-right[arr[j]-1]-1);
		    else result=min((left[arr[j]-1]-arr[j]+1), (arr[j]-right[arr[j]-1]-1)); // and if none of them is -1 then we calculate the minimum for the same
		    cout<<result<<" ";
		}
	     
		 cout<<"\n";
		
	}
	return 0;
}
