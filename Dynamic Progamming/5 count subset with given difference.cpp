// s1 - s2 = diff
// s1 + s2 = totalSum
// s1 = (totalSum + diff)/2
// countSubsetWithGivenDiff(diff) = countSubsetWithGivenSum(s1)
// problem reduced to count subsets with given sum
// refer notes pg: 21-22
int countSubsetWithGivenDiff(vector<int>& nums, int diff) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
  
        if((totalSum + diff) % 2 != 0) return 0; 
        int sum1 = (totalSum + diff) / 2;
  
        int dp[n+1][sum1 + 1];      
        for(int i=0; i<n+1; i++)
        {
            dp[i][0] = 1;
        }
        for(int j=0; j<sum1+1; j++)
        {
            dp[0][j] = 0;
        }
        
        // step 2: recursive code to iterative code
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum1+1; j++)
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
       return dp[n][sum1];
}
    
