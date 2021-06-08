// problem link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
// idea is to sort the array and then the difference of every m sized window and update minimum of that to the ans variable

long long findMinDiff(vector<long long> arr, long long n, long long m){
    sort(arr.begin(), arr.end());
    long int diff, end=m-1,start=0,ans=(arr[m-1]-arr[0]);
    while(end < n)
    {
        diff=arr[end] - arr[start];
        ans=min(ans, diff);
        start++;
        end++;
    }
    return ans;
    
    }   
