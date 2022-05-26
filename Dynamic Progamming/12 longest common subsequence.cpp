// notes pg: 34-36
// recursion
    
//     int lcs(string x, string y, int m, int n)
//     {
//         if(n == 0 || m == 0) return 0;
        
//         if(x[m - 1] == y[n - 1]) return 1 + lcs(x, y, m-1, n-1);
//         else
//             return max(lcs(x, y, m, n-1), lcs(x, y, m-1, n));
//     }
    
//     int longestCommonSubsequence(string x, string y) {
//         int m = x.length();
//         int n = y.length();
        
//         return lcs(x, y, m, n);
//     }
    
    // memoization
    
//     int memo[1001][1001];
    
//     int lcs(string &x, string &y, int m, int n)
//     {
//         if(n == 0 || m == 0) return 0;
//         if(memo[m][n] != -1) return memo[m][n];
        
//         if(x[m - 1] == y[n - 1]) return memo[m][n] = 1 + lcs(x, y, m-1, n-1);
//         else
//             return memo[m][n] = max(lcs(x, y, m, n-1), lcs(x, y, m-1, n));
//     }
    
//     int longestCommonSubsequence(string x, string y) {
//         int m = x.length();
//         int n = y.length();
       
//         memset(memo, -1, sizeof(memo));
        
//         return lcs(x, y, m, n);
//     }
    
    // top down dp
    
    int longestCommonSubsequence(string x, string y) {
        int m = x.length();
        int n = y.length();
        int dp[m + 1][n + 1];
        
        memset(dp, 0, sizeof(dp));
        
        // initialization
        for(int i = 0; i < m+1; i++)
        {
            if(i == 0) dp[i][0] = 0;
        }
        for(int j = 0; j < n+1; j++)
        {
            if(j == 0) dp[0][j] = 0;
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
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
