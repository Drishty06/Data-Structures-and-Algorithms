// refer notes pg: 27-29
    int coinChange(vector<int>& coin, int sum)
    {
        int n = coin.size();
        int dp[n + 1][sum + 1];
        // initializing values
        for(int i=0; i < n+1; i++)
        {
            dp[i][0] = 1;
        }
        for(int j=1; j<len+1; i++)
        {
            dp[0][j] = 0;
        }
        // filing the matrix
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
                if(coin[i-1] <= j)
                {
                    dp[i][j] = dp[i][j - coin[i-1]] + dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
