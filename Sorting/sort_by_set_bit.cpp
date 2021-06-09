    // problem link: https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1#
    // expected time complexity: O(n log n) and space complexity o(1)
    // naive approach: using an auxillary array and storing countbits value using bit manipulation = TLE
    // better approach: since we have a parameter(countbits) on the basis of which array has to be sorted therefore comparators in inbuilt sort is bestly suited
    //                  and using countbits by bit manipulation = TLE
    // efficient approach: using STL function __inbuilt_popcount which gives countbits and all this in a comparator function = ACCEPTED
    // checkout: STL functions repo -> bit manipulation -> countbits.cpp
    // to get more info on __inbuilt_popcount(int n)

    static bool comparator(int a,int b) // not using static here threw an error
    {
        return __builtin_popcount(a) > __builtin_popcount(b);
    }
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr,arr+n,comparator); // by simply using sort gave an error so used stable_sort
    }
