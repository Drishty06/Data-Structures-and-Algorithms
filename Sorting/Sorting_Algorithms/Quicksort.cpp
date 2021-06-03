// quicksort algorithm visualizer: https://www.youtube.com/watch?v=MZaf_9IZCrc (lomuto partition)
// time complexity: BEST CASE:    O(N logN) 
//                  AVERAGE CASE: O(N logN)
//                  WORST CASE:   O(N^2)
// space complexity: O(log N)
// NOT STABLE
// quicksort basically uses 3 types of partition methods: 1. naive 2. lomuto 3. hoare
void quicksort(int arr[], int low, int high) 
{
   if(low < high) 
   {        
         //stores the position of pivot element
         int piv_pos = partition(arr, low, high);     
         quicksort(arr, low, piv_pos -1); //sorts the left side of pivot.
         quicksort(arr, piv_pos +1, high);   //sorts the right side of pivot.
   }
}
int partition(int arr[], int low, int high) // lomuto partition
	{
	    //in basic lomuto partition, pivot is last element 
	    int pivot=arr[high];
	    // we use two counter variables i and j 
	    int i=low-1;  // initially i points to element before first element 
	    int j=low;    // and j points to first element of array
	    for(j=low; j<high-1; j++)
	    {
	        if(arr[j] < arr[pivot])
	        {
	            i++;
	            swap(arr[i], arr[j]);
	        }
	    }
	    swap(arr[i+1], arr[high]);
	    //after this pivot gets its correct space in the array and 
	    // elements before it are lower than it and elements after it are higher than it
	    return i+1;
	}
// just to know about another partition method, checkout the code snippet given below
// hoare's partition
	
	/* This function takes first element as pivot, and places
	   all the elements smaller than the pivot on the left side
	   and all the elements greater than the pivot on
	   the right side. It returns the index of the last element
	   on the smaller side*/
	int partition(int arr[], int low, int high)
	{
	    int pivot = arr[low];
	    int i = low - 1, j = high + 1;
	 
	    while (true) 
      {
        // Find leftmost element greater than
	      // or equal to pivot
	    do 
      {
        i++;
	    } while (arr[i] < pivot);
        // Find rightmost element smaller than
	      // or equal to pivot
	    do 
      {
        j--;
	    } while (arr[j] > pivot);
        // If two pointers met.
        if (i >= j)  return j;
	      swap(arr[i], arr[j]);
	    }
}

