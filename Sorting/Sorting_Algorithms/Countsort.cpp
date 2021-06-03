// count sort algorithm visualizer: https://visualgo.net/en/sorting
// for more info: https://www.youtube.com/watch?v=imqr13aIBAY
// time complexity: BEST CASE:    O(N+k) 
//                  AVERAGE CASE: O(N+k)
//                  WORST CASE:   O(N+k)
// space complexity: O(N+k)
// STABLE
	void countsort(int arr[], int n)
	{
		int k=arr[0];
		for(int i=0; i<n; i++) // finding maximum elements from the array
		{
			k= max(k, arr[i]);
		}
		int count[k]={0};     // declaring count array to check the frequencies/occurences of all the numbers
                          // initializing all elements to zero
		for(int i=1; i<n; i++)
		{
			count[arr[i]]++;    // finding the frequencies of various numbers less than maximum(here k) and building count array
		}
		for(int i=1; i<=k; i++)
		{
			count[i]+=count[i-1]; // to get the position of that element in the final array we check the total number of elements smaller than that particular number
		}
		int output[n];
		for(int i=n-1; i>=0; i--) // alloting positions
		{
			output[--count[arr[i]] = arr[i];
		}
			
		for(int i=0; i<n; i++)   // copying output array to arr
		{
			arr[i]=output[i];
		}
	 }

