// refer notes pg: 25-27
int rodCutting(vector<int>& length, vector<int>& price, int n)
    {
        int len = length.size();
        int dp[n + 1][len + 1];
        // initializing values
        for(int i=0; i < n+1; i++)
        {
            dp[i][0] = 0;
        }
        for(int j=0; j<len+1; i++)
        {
            dp[0][j] = 0;
        }
        // filing the matrix
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<len+1; j++)
            {
                if(length[i-1] <= j)
                {
                    dp[i][j] = max(price[i-1] + dp[i][j - length[i-1]], dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][len];
    }
