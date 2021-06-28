// problem link: https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1
int maxLen(int arr[], int n)
    {
        unordered_map <int, int> mp; // this map stores array element as keys and first occurrence of that array element as value 
        int sum = 0, ans = 0;
        
        for(int i=0; i<n; i++)
        {
            // trick: replace all os with -1 and wohooo the problem is then similar to longest subarray with 0 sum
            if(arr[i] == 0) sum+=(-1); // prefix sum
            else sum+=arr[i];
            if(sum == 0) // for handling edge case eg: arr = 2, 3, 6 x=5-> prefix sum = 2 5 11 
            {            // so if this loop is not included then the above mentioned example proves out to be wrong
                ans = i+1;
            }
            if(mp.find(sum) == mp.end())
            {
                mp.insert({sum, i}); // incase its the first occurrence of that element then we store its index 
            }
            if(mp.find(sum) != mp.end()) // in case such array with x sum is available
            {
                ans = max(ans, i-mp[sum]);
            }
        }
        return ans;
    }
