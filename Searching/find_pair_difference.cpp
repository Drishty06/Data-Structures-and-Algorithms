// problem link: https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#
// two pointer approach
// we used to place one pointer at the beginning and other at the end in case of sum
// but here, if with decrease high from end still we may get difference less than x and increasing the low pointer may also result in the same
// we cannot judge the criteria using this
// so for the difference, we place one pointer at 0 and other at index 1
bool findPair(int arr[], int size, int x){
    sort(arr, arr+size);
    int low=0;
    int high=1;
    while(low < size && high < size)
    {
        if(arr[high] - arr[low] == x && low != high) return true; // to avoid the failing case when difference=0. when low=high in that case we can get diff 0 but that is obviously not correct 
        else if(arr[high] - arr[low] < x) high++;
        else low++;
    }
    return false;
}
