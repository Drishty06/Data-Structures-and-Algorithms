// insertion sort algorithm visualizer: https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/visualize/
// time complexity: BEST CASE:    O(N) 
//                  AVERAGE CASE: O(N^2)
//                  WORST CASE:   O(N^2)
// space complexity: O(1)
// STABLE
// IN PLACE
// elements to left of current position of iterator are always arranged such that they are sorted
void insertionsort(int arr[], int n)
{
	for(int i=1; i<n; i++)
	{
		int temp=arr[i];
		int j=i-1;
		while(j >= 0 && arr[j] > temp) // if current element is smaller than the element to its left 
		{                              // then swap it until all the previous reach their correct position
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp; // when every element reaches its correct position, store temp to current position
	}
}
