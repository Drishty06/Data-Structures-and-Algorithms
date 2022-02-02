// refer notes pg: 29-32
    // RECURSION - TLE
    // -------------------------------------------------------------------------------
    /*
    int coinChangeRecursive(int amount, vector<int>& coins, int i)
    {
        if(i == -1) return INT_MAX-1; // all elements covered
        if(amount == 0) return 1; // we can make the goven amount by the choices we took, so number of ways++
        
        if(coins[i] > amount) return coinChangeRecursive(amount, coins, i-1);
        // if current coin is greater than amount, we move to next coin without changing the amount 
        
        return min(coinChangeRecursive(amount - coins[i], coins, i) + 1, coinChangeRecursive(amount, coins, i-1));
    }
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();
         int ans = coinChangeRecursive(amount, coins, n-1)-1;
         if(ans >= INT_MAX-2) return -1;
         return ans;
    }
    */
    // -------------------------------------------------------------------------------
    
    // 2. MEMOIZATION - accepted
    // -------------------------------------------------------------------------------
    /*
    int memo[12 + 1][10000 + 1];
    
    int coinChangeMemo(int amount, vector<int>& coins, int i)
    {
        if(i == -1) return INT_MAX-1; // all elements covered
        if(amount == 0) return 1; // we can make the goven amount by the choices we took, so number of ways++
        if(memo[i][amount] != -1) return memo[i][amount];
        
        if(coins[i] > amount) return memo[i][amount] = coinChangeMemo(amount, coins, i-1);
        // if current coin is greater than amount, we move to next coin without changing the amount 
        
        return memo[i][amount] = min(coinChangeMemo(amount - coins[i], coins, i) + 1, coinChangeMemo(amount, coins, i-1));
    }
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();
         memset(memo, -1, sizeof(memo));
         int ans = coinChangeMemo(amount, coins, n-1)-1;
         if(ans >= INT_MAX-2) return -1;
         return ans;
    }
    */
    // -------------------------------------------------------------------------------
    
    // 3. TABULATION:
    // -------------------------------------------------------------------------------
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[n + 1][amount + 1];
        
        // initialization: refer notes pg: 29-32
        // (0, 0) => 
        for(int j=0; j<=amount; j++)
        {
            dp[0][j] = INT_MAX - 1;
        }
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 0;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=amount; j++)
            {
                if(coins[i-1] <= j)
                {
                    dp[i][j] = min(dp[i][j - coins[i-1]] + 1, dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][amount] >= INT_MAX-2) return -1;
        return dp[n][amount];
    }
