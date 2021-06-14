// problem: to find last occurrence of x in a sorted array
// naive approach is to traverse thru the array from 0 to n and note where the last occurrence is: O(n) time complexity
// but this could be done in O(log n) time complexity using iterative and recursive binary search
// iterative is better than recursive since the latter takes extra space for recursive calls

// iterative:
int last_occ(int arr[], int n, int x)
    {
      int low = 0, high = n-1;
      while(low <= high)
      {
        int mid = (low+high)/2;
        if(arr[mid] < x) low = mid+1;
        else if(arr[mid] > x) high = mid-1;
        else
        {
          if((mid == n-1 || x < arr[mid+1]) && arr[mid] == x) return mid;
          else low = mid+1;
        }
      }
      return -1;
    }

// Recursive:
int last_occ(int arr[], int low, int high, int n, int x)
{
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(arr[mid] > x) return last_occ(arr, low, mid-1, n);
    else if(arr[mid] < x) return last_occ(arr, mid+1, high, n);
    else
    {
      if(mid == n-1 || arr[mid] != arr[mid+1]) return mid;
      else return last_occ(arr, mid+1, high, n);
    }
  }
  return -1;
}
