    // notes pg: 10-13
    // given an array arr and sum, check if there is any subset with given sum
    bool subsetSum(vector<int>& arr, int sum, int n)
    {
        bool dp[n + 1][sum + 1];
        // initializing values
        for(int i=0; i<n+1; i++)
        {
            dp[i][0] = true;
        }
        for(int j=0; j<sum+1; i++)
        {
            dp[0][j] = false;
        }
        // filing the matrix
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = ((dp[i-1][j - arr[i-1]]) || dp[i-1][j]));
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
