// problem link: https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1
// approach 1: by simply combining first occurrence and last occurrence codes
// TIME COMPLEXITY: O(log n)
// SPACE COMPLEXITY: O(1)
int first_occ(int arr[], int n, int x)
    {
      int low=0, high=n-1;
      while(low <= high)
      {
        int mid = (low+high)/2;
        if(arr[mid] > x) high = mid-1;
        else if(arr[mid] < x) low = mid+1;
        else
        {
          if((mid == 0 || x > arr[mid-1]) && arr[mid] == x) return mid;
          else high = mid-1;
        }
      }
      return -1;
    }
    
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
    
	int count(int arr[], int n, int x) {
	    int last = last_occ(arr, n, x);
	    int first = first_occ(arr, n, x);
	    if(first == -1 || last == -1) return 0;
	    else return last-first+1;
	}

// approach 2: using upper and lower bounds (STL)
int count(int arr[], int n, int x) {
	    int last = upper_bound(arr, arr+n, x)-arr-1;
	    int first=lower_bound(arr, arr+n, x)-arr;
	    if (first == n) return 0;
      else return last-first+1;
	}
