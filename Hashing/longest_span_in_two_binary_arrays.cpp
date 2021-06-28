// problem link: https://practice.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1/?category[]=sliding-window&category[]=sliding-window&difficulty[]=1&page=1&sortBy=submissions&query=category[]sliding-windowdifficulty[]1page1sortBysubmissionscategory[]sliding-window
int longestCommonSum(bool arr1[], bool arr2[], int n) 
    {
         unordered_map <int, int> mp; // this map stores array element as keys and first occurrence of that array element as value 
        int sum = 0, ans = 0;
        int temp[n];
        
        // logic: subtract 2nd array from the 1st and then this question is converted to the longest subarray with 0 sum
        for(int i=0; i<n; i++)
        {
            temp[i]=arr1[i]-arr2[i];
        }
        
        for(int i=0; i<n; i++)
        {
            sum+=temp[i];
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
