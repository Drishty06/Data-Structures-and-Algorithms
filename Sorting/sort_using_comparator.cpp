// watch this for more info: https://www.youtube.com/watch?v=3pvZhwp0U9w
//Given an array of integers, sort it in such a way that the odd numbers appear
//first and the even numbers appear later. 
//The odd numbers should be sorted in descending order and 
//the even numbers should be sorted in ascending order.
#include <bits/stdc++.h>
using namespace std;
bool comparator(int a, int b)
{
    if(a%2!=0 && b%2!=0)
    {
        return a>b;
    }
    else if(a%2==0 && b%2==0)
    {
        return a<b;
    }
    else
    {
        if(a%2==0) return false;
    }
    return true;
}

int main() 
{ 
	int n;
	cin>>n;
    int arr[n];
	for(int i=0; i<n ; i++)
	{
		cin>>arr[i];
	}
    sort(arr, arr+n, comparator);
    for(int i=0; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
