// almost similar to question 17 discussed in video no 25 of aditya verma's playlist
 int minDistance(string x, string y) {
        int m = x.length();
        int n = y.length();
        
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
        return m - LCSlen + n - LCSlen;
    }
