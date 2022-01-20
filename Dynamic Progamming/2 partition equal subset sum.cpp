// https://leetcode.com/problems/partition-equal-subset-sum/submissions/
// notes pg: 14-15

    // 1. recursion: TLE
    // TC: O(2^N)
    // SC: O(N) for recursive stack
    // if we have an array whose total sum is odd then we cannot divide it into 2 equal parts
    // so total sum needs to be even to partition it into 2 equal parts
    // now we need not to search for 2 different subsets with totalSum/2 
    // because if there is single subset present with sum = totalSum/2, automatically there will other such subset
    // idea: for every element, there are 2 choices, to include it, or not to include it.
    // so we call two recursive calls for each element 
    // ---------------------------------------------------------------------------
    /*
    bool canPartitionRecursion(vector<int>& nums, int sum, int i)
    {
        if(sum == 0) return true;
        if(i == nums.size() || sum < 0) return false;
        return (canPartitionRecursion(nums, sum-nums[i], i+1) || canPartitionRecursion(nums, sum, i+1));
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0; i<n; i++)
        {
            totalSum += nums[i];
        }
        if(totalSum % 2 != 0) return false;
        return canPartitionRecursion(nums, totalSum/2, 0);
    }
    */
    // ----------------------------------------------------------------------------

    // 2. memoization: refer page 7 of notes to see how to convert recursion to memoization code easily
    // TLE
    // TC: O(N * SUM)
    // SC: O(N * SUM) + recursive calls
    // ----------------------------------------------------------------------------
    /*
     bool dp[200+1][10000 + 1];
     bool canPartitionRecursion(vector<int>& nums, int sum, int i)
     {
        if(sum == 0) return true;
        if(i == nums.size() || sum < 0) return false;
        if(dp[i][sum] != false) return dp[i][sum];
        return dp[i][sum] = (canPartitionRecursion(nums, sum-nums[i], i+1) || canPartitionRecursion(nums, sum, i+1));
     }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int totalSum = 0;
        for(int i=0; i<n; i++)
        {
            totalSum += nums[i];
        }
        if(totalSum % 2 != 0) return false;
        return canPartitionRecursion(nums, totalSum/2, 0);
    }
    */
    // -----------------------------------------------------------------------------
    // 3. bottom up approach: as per aditya verma's playlist
    // TC: O(N * SUM)
    // SC: O(N * SUM)
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int totalSum = 0;
        for(int i=0; i<n; i++)
        {
            totalSum += nums[i];
        }
        if(totalSum % 2 != 0) return false;
        
        bool dp[n+1][totalSum/2 + 1];
        int sum = totalSum/2;
        // step 1: initialization
        // what i thought for initialization: (which is incorrect)
        // **************************************
        // for eg: if n = 2 arr[] = {1, 2} and sum = 0: I cannot divide 1+2 into 2 subsets such that their sum is 0
        // so dp[i][0] = false
        // for eg: if n = 0 and sum = 3: I cannot divide empty subset into two subsets with sum 0
        // so dp[0][j] = false
        // **************************************
        // initialization: since here we are already said non empty array nums and still we want the value when n = 0 so this is not possible to understand by the examples i mentioned above. So we consider the same logic what we use for Subset Sum problem.
        // --------------------------------------------------------------------------------------------
        // step 1: initialization: 
        
        for(int i=0; i<n+1; i++)
        {
            dp[i][0] = true;
        }
        for(int j=0; j<sum+1; j++)
        {
            dp[0][j] = false;
        }
        
        // step 2: recursive code to iterative code
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = ((dp[i-1][j - nums[i-1]]) || dp[i-1][j]); 
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
       return dp[n][sum];
    }
