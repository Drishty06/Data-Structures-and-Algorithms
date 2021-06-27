// intersection of two arrays using hashing
// time complexity: O(m+n)
// space complexity O(m)
int intersection(int a[], int m, int b[], int n)  
{
	unordered_set <int> s;
	for(int i=0; i<m; i++)
	{
		s.insert(a[i]); // acc to the properties of set, they ignore similar elements so no chance of repetation
	}

	int ans=0;

	for(int i=0; i<n; i++)
	{
		if(s.find(b[i]) != s.end())
		{
			ans++;
			s.erase(b[i]); // to avoid repetation 
		}
	}

	return ans;
}
