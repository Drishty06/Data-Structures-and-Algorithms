// problem: to find first occurrence of x in a sorted array
// naive approach is to traverse thru the array from 0 to n and note where the first occurrence is: O(n) time complexity
// but this could be done in O(log n) time complexity using iterative and recursive binary search
// iterative is better than recursive since the latter takes extra space for recursive calls

// iterative:
int first_occ(int arr[], int n, int x)
{
  int low=0, high=n-1;
  while(low >= high)
  {
    int mid = (low+high)/2;
    if(arr[mid] > x) high = mid-1;
    else if(arr[mid] < x) low = mid+1;
    else
    {
      if(mid == 0 || arr[mid-1] != arr[mid]) return mid;
      else high = mid-1;
    }
  }
}

// recursive
int first_occ(int arr[], int low, int high, int x, int n)
{
    if (high >= low) 
    {
        int mid = low + (high-low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x) return mid;
        else if (x > arr[mid]) return first(arr, (mid + 1), high, x, n);
        else return first(arr, low, (mid - 1), x, n);
    }
    return -1;
}
