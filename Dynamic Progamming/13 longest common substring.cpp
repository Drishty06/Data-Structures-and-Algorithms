// notes pg 36-37
        int m = x.length();
        int n = y.length();
        int dp[m + 1][n + 1];
        
        memset(dp, 0, sizeof(dp));
        
        // initialization
        for(int i = 0; i < m+1; i++)
        {
            dp[i][0] = 0;
        }
        for(int j = 0; j < n+1; j++)
        {
           dp[0][j] = 0;
        }
        
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if(x[i - 1] == y[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[m][n];
    }
