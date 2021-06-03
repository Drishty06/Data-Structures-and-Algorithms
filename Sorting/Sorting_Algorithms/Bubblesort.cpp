// bubble sort algorithm visualizer: https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/visualize/
// time complexity: BEST CASE:    O(N^2) (but bubble sort can be modified and that results in O(N) best case time complexity)
//                  AVERAGE CASE: O(N^2)
//                  WORST CASE:   O(N^2)
// space complexity: O(1)
// STABLE
// IN-PLACE ALGORITHM
// largest element goes to the top just like bubble in every iteration
void bubblesort( int arr[], int n) 
{
    int temp;
    for(int k=0; k<n-1; k++) 
    {
        // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations
        for(int i = 0; i < n-k-1; i++) 
        {
            if(arr[i] > arr[ i+1]) 
            {                
              // swapping of positions 
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

// optimized version of bubblesort which results in O(N) best case time complexity
void bubblesort(int arr[], int n) 
{
  int swapped;
  int i, j; 
	for(i=0; i<n-1; i++)    
	{
    swapped=false;
    // Last i elements are already in place 
    for(j=0; j<n-i-1; j++) 
    {
      if(arr[j] > arr[j+1])
      {
        swap(arr[j], arr[j+1]);   
		    swapped=true; // if for a particular iteration, swapping of elements occurs then it is yet not sorted 
      }               // and hence marking swapped variable as true
	  }
		if(swapped == false) // if for a particular iteration, there was no swapping seen than that means array is already sorrted so we break furthur iterations 
		{
			break;
		}
	}
} 
