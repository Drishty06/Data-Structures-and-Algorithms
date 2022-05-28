// refer que 19
int minInsertions(string x){
        int m = x.length();
        int n = m;
        string y = x;
        reverse(y.begin(), y.end());
        
        int dp[m + 1][n + 1];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i < m + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if(x[i - 1] == y[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        int LCSlen = dp[m][n];
        return m - LCSlen;
    }
