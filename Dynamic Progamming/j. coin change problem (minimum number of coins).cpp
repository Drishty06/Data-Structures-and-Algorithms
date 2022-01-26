// refer notes pg: 29-32
int coinChange(vector<int>& coin, int sum)
    {
        int n = coin.size();
        int dp[n + 1][sum + 1];
        // initializing values
        for(int j=0; j<=sum; i++)
        {
            dp[0][j] = INT_MAX-1;
            if(j % arr[0] != 0)
            {
              dp[1][j] = INT_MAX-1;
            }
            else
            {
              dp[1][j] = j/arr[0];
            }
        }
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 0;
        }
        // filing the matrix
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(coin[i-1] <= j)
                {
                    dp[i][j] = min(dp[i][j - coin[i-1]] + 1, dp[i-1][j]));
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
