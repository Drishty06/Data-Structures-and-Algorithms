// selection sort algorithm visualizer: https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/visualize/
// time complexity: BEST CASE:    O(N^2) 
//                  AVERAGE CASE: O(N^2)
//                  WORST CASE:   O(N^2)
// space complexity: O(1)
// UNSTABLE
// IN-PLACE ALGORITHM
// it works on finding minimum element in each iteration and swap it 
void selectionsort(int arr[], int n) 
{
  int min;        
  // reduces the effective size of the array by one in each iteration
  for(int i=0; i<n-1 ;i++)  
  {
    // assuming the first element to be the minimum of the unsorted array 
    min = i ;
    // gives the effective size of the unsorted array 
    for(int j=i+1; j<n; j++) 
    {
      if(arr[j] < arr[min])  
      {     
        min = j ;
      }
    }
     // putting minimum element on its proper position.
    swap(A[min], arr[i]); 
  }
}
