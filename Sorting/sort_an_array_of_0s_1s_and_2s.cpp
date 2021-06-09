// problem link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#
// 1. naive approach is to simply use sort function.
    //    time complexity: O(n log n) and space complexity O(1)
    // 2. in 3 traversals of array place the 0s, 1s, and 2s and appropriate position using temp array
    //    time complexity: O(n) and space complexity O(n)
    // 3. single traversal of array - most optimized approach (shown below)
    //    time complexity: O(n) and space complexity O(1)
    void sort012(int arr[], int n)
    {
        // method is known as DNF sort
        // using 3 pointers low, mid and high
        int low=0, mid=0, high=n-1;
        
        while(mid <= high)
        {
            switch(arr[mid])
            {
                case 0: swap(arr[mid], arr[low]);
                low++;
                mid++;
                break;
                
                case 1: 
                mid++;
                break;
                
                case 2: swap(arr[mid], arr[high]);
                high--;
                
            }
        }
    }
