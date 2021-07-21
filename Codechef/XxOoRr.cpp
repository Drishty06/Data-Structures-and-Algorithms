// to be updated after 12th july
// problem link: https://www.codechef.com/JULY21B/problems/XXOORR
// logic: to make any array element to zero we have to xor it with the same number
// since we have to multiply it with powers of two we have to bring the array element to any such powers of two using xor
// so we write all the numbers in binary format and check if we have 1s colliding at the same place and if yes then we club them
// steps: 1. creating 32 sized array to store 32 bits of every array element
//        2. storing binary representation of every element into it and appending the answer
//        3. using a logic to take "k" into account as mentioned in lines 41 and 42f

#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	long int t;
	cin>>t;
	for(int j=0; j<t; j++)
	{
		long int n,k;
		cin>>n>>k;
		long long int arr[n], temp, rem, ans=0;
		for(int i=0; i<n; i++)
		{
		    cin>>arr[i];
		}
		int count[32]={0};
		for(int i=0; i<n; i++)
		{
		    temp = arr[i];
		    int index=31;
		    while(temp > 0) //storing binary representation
		    {
		        rem = temp%2;
		        count[index]+=rem;
		        temp/=2;
		        index--;
		    }
		}

		for(int i=31; i>=0; i--) // taking k into account
		{
		    if(count[i] % k == 0) ans += (count[i]/k); 
		    else ans += (count[i]/k)+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
