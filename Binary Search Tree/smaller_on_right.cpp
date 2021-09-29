// problem link: https://practice.geeksforgeeks.org/problems/smaller-on-right4318/1/?track=P100-Binary%20Search%20Tree&batchId=197
// idea is to traverse array from right to left and add elements into the set(which uses self balancing bst)
// for each element we need to find the element just smaller than current element so we use lower bound for this


int countSmallerRight(int arr[], int n) {
    
    set<int>s;
    int smallerOnRight =0;
    for(int i=n-1; i>=0; i--)
    {
        s.insert(arr[i]);
        auto it = s.lower_bound(arr[i]);
        if(distance(s.begin(),it) > smallerOnRight) smallerOnRight= distance(s.begin(),it);
    }
    return smallerOnRight;
}
