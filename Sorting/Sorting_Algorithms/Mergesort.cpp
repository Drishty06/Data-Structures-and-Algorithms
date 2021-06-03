// merge sort algorithm visualizer: https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/visualize/
// time complexity: BEST CASE:    O(N logN) 
//                  AVERAGE CASE: O(N logN)
//                  WORST CASE:   O(N logN)
// space complexity: O(N)
// STABLE

void mergesort(int arr[] ,int start ,int end)
{
  if(start < end) 
  {
    int mid = start+(end-start)/2; // this is used instead of (start+end)/2 because this will be out of range of range if start and end are large numbers        
    mergesort(arr, start ,mid);    // sort the 1st part of array 
    mergesort(arr, mid+1 ,end);    // sort the 2nd part of array
    // merge the both parts by comparing elements of both the parts.
    merge(arr, start, mid, end);   
   }                    
}
void merge(int arr, int start, int mid, int end)
{
  int temp[end-start+1];
  int i=start, j=mid+1, k=start; // using two pointers where 1st is pointing to starting of one half of array and 2nd to other half
  while(i <= mid && j <= end)
  {
    if(arr[i] < arr[j]) //comparing two parts of arrays  
    {
      temp[k]=arr[i];
      i++;
    }
    else
    {
      temp[k]=arr[j];
      j++;
    }
    k++;
  }
  
  if(i > mid) // if one of the half of array is exhausted then all the elements of other half of array is added directly to temp array
  {
    while(j <= end)
    {
      temp[k]=arr[j];
      k++;
      j++;
    }
  }
  else
  {
    while(i <= mid)
    {
      temp[k]=arr[i];
      i++;
      k++;
    }
  }
  
  for(int a=start; a<=end; a++) // storing the elements of temp to arr
  {
    arr[a]=temp[a];
  }
  
}
