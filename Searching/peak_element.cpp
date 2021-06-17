int peak(int arr[], int low, int high, int n)
{
   int mid = (low+high)/2;
   if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid]))
   {
       return mid;
   }
   // If middle element is not peak and its left neighbour is greater than it, then left half must have a peak element
    else if (mid > 0 && arr[mid - 1] > arr[mid])
    {
        return peak(arr, low, (mid - 1), n);
    }
    // If middle element is not peak and its right neighbour is greater than it, then right half must have a peak element
    else
        return peak(arr, (mid + 1), high, n);
}
int peakElement(int arr[], int n)
{
    return peak(arr, 0, n-1, n);
}
