// problem link: https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1#
// union of two arrays using hashing
// time complexity: O(m+n)

int doUnion(int a[], int n, int b[], int m)  
{
	unordered_set <int> s;
	for(int i=0; i<n; i++)
	{
		s.insert(a[i]); 
	}

	for(int i=0; i<m; i++)
	{
		s.insert(b[i]); 
	}

	return b.size();
}
