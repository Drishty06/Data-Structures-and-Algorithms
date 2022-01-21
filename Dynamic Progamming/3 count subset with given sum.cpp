// similar to partition equal subset with just few changes
// refer notes to understand the similarities
// notes pg 15-16
int countSubsetWithGivenSum(vector<int>& nums, int sum) {
        int n = nums.size();
        
        int dp[n+1][sum + 1];      
        for(int i=0; i<n+1; i++)
        {
            dp[i][0] = 1;
        }
        for(int j=0; j<sum+1; j++)
        {
            dp[0][j] = 0;
        }
        
        // step 2: recursive code to iterative code
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = ((dp[i-1][j - nums[i-1]]) + dp[i-1][j]); 
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
       return dp[n][sum];
    }
