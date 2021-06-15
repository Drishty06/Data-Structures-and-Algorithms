    // problem link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
    // time complexity: O(N log N)
    // space complexity: O(1)

    bool allocation_is_possible(int arr[], int n, int m, int mid)
    {
        int allocated_students=1, pages=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] > mid) return false; // if that element cannot be added to any atudent
            if(pages + arr[i] > mid) // in case it exceeds mid then wew allocate next book to the next student
            {
                allocated_students++;
                pages=arr[i];
            }
            else
            {
                pages+=arr[i]; // and if it still lies under mid, then we simply keep on adding the books
            }
        }
        if(allocated_students > m) return false; // if number of allocated stuednts are greater than m = return false
        else return true;
    }
    // binary search based efficient approach
    // firstly we find the search space
    // for this we calculate minimum possible ans when n=m (minimum of all elements)
    // maximum ans will be when m=1 (summation of all elements of array)
    int findPages(int arr[], int n, int m) 
    {
        int start = *min_element(arr, arr+n); // minimum element of array
        int end = accumulate(arr, arr+n, 0);  // sum of all elements of array
        int ans = -1;
        while(start <= end) // normal binary search
        {
            int mid = (start+end)/2;
            
            if(allocation_is_possible(arr, n, m, mid)) // this checks if selcting this as mid could distribute the books into m students or not
            {
                ans = mid; // if yes then updating the ans and eliminating right half search range
                end = mid-1;
            }
            else
            {
                start=mid+1; // if no then eliminating left half search range
            }
            
        }
        
    }
