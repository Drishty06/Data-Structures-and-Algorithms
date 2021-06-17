int search(int arr[], int low, int high, int x){
        
        int mid=(low+high)/2;
        while(low <= high)
        {
            if(arr[mid] == x) return mid;
            if(arr[mid] > arr[low]) // left half sorted
            {
                if(x >= arr[low] && x < arr[mid]) // x lies in the left half
                {
                    high=mid-1;
                    return search(arr, low, high, x);
                }
                else // x lies in the right half
                {
                    low=mid+1;
                    return search(arr, low, high, x);
                }
            }
            else // right half is sorted
            {
                if(x > arr[mid] && x<=arr[high]) // xlies in right half
                {
                    low=mid+1;
                    return search(arr, low, high, x);
                }
                else // x lies in left half
                {
                    high=mid-1;
                    return search(arr, low, high, x);
                    
                }
                
            }
        }
        return -1;
    }
