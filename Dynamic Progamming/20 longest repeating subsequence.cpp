// refer notes pg: 42
int longestRepeatingSubseq(string x) {
        int m = x.length();
        int n = m;
        string y = x;
  
        int dp[m + 1][n + 1];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i < m + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if(x[i - 1] == y[j - 1] && i != j)
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[m][n] / 2;
    }
