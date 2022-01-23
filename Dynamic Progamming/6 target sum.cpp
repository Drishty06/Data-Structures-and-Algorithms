// problem link: https://leetcode.com/problems/target-sum/
    // notes pg:22-23
    // intuition is similar to problem 4.1 last stone weight II
    // approach is totally simialr to problem - count subset with given difference
    // eg: [1, 1, 2, 3] target = 1
    // ans = 3
    // one of the ans: +1 -1 -2 +3 
    // => this is equivalent to 1+3 - (2+1), that is dividing the array into two subsets such that their difference is equal to target
    // exactly similar to count subset with given difference
    // s1-s2 = target
    // s1+s2 = totalSum
    // s1 = (totalSum + target)/2 
    // don't forget to cover the case when target can be negative
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if((totalSum + target) % 2 != 0 || totalSum < abs(target)) return 0;
        int s1 = (totalSum + target) /2;
        
        int dp[n + 1][s1 + 1];
        
        // initialization
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 1; // empty subset always possible when sum = 0
        }
        for(int j=1; j<=s1; j++)
        {
            dp[0][j] = 0; // empty subset always possible when sum = 0
        }
        
        // converting recursive code to iterative code
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=s1; j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = (dp[i-1][j - nums[i-1]] + dp[i-1][j]);
                }
                else 
                {
                    dp[i][j] = dp[i-1][j]; // capacity of knapsack remains as it is
                }
            }
        }
         
        return dp[n][s1];
    }
