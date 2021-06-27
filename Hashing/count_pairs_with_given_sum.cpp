// count pairs with given sum
// problem link: https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
// there can be multiple approachs for the same like two pointer and all but here we use hashing

int getPairsCount(int arr[], int n, int k) 
{
	int getPairsCount(int arr[], int n, int k) 
{
	int count=0;
	unordered_map <int, int> mp; // to store frequency of elements
	for(int i=0; i<n; i++)
	{
		int x=k-arr[i]; 
		if(mp.find(x) == mp.end()) // if any such pair is not found then in that case we just update the frequency
		{
		    mp[arr[i]]++;
		}
		else
		{
		    count+=mp[x];  // else we update count and increment it with frequency of the element since all such pairs are to be counted
		    mp[arr[i]]++;
		}
	}
	return count;
}
}
 
