// coin change problem 2 of leetcode = coin change problem 1 of notes
// problem link: https://leetcode.com/problems/coin-change-2/

// intuition: 
    // why recursion? => because we have choices for coins 
    // why knapsack? => because we have a fixed capacity which is amount and we have choices for coins whether to include them or not
    // why unbounded knapsack? => because for every coin, we can include it multiple times as well, ie., there unlimited supply of coins
    
    // 1. RECURSION: TLE
    // -------------------------------------------------------------------------------
    /*
    int coinChange2Recursive(int amount, vector<int>& coins, int i)
    {
        if(i == -1) return 0; // all elements covered
        if(amount == 0) return 1; // we can make the goven amount by the choices we took, so number of ways++
        
        if(coins[i] > amount) return coinChange2Recursive(amount, coins, i-1);
        // if current coin is greater than amount, we move to next coin without changing the amount 
        
        return coinChange2Recursive(amount - coins[i], coins, i) + coinChange2Recursive(amount, coins, i-1);
        // for every coin we have 2 choices, 1. to include it and 2. not to include it
        // int first choice we consider the case as unprocessed as if we can take that coin once, we can take it multiple times as well, so we again pass the same index.
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return coinChange2Recursive(amount, coins, n-1);
    }
    */
    
    // 2. MEMOIZATION: accepted
    // -------------------------------------------------------------------------------
    /*
    int memo[300 + 1][5000 + 1];    
    int coinChange2Memo(int amount, vector<int>& coins, int i)
    {
        if(i == -1) return 0;
        if(amount == 0) return 1;
        if(memo[i][amount] != -1) return memo[i][amount];
        
        if(coins[i] > amount) return memo[i][amount] = coinChange2Memo(amount, coins, i-1);
        
        return memo[i][amount] = (coinChange2Memo(amount - coins[i], coins, i) + coinChange2Memo(amount, coins, i-1));
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(memo, -1, sizeof(memo));
        return coinChange2Memo(amount, coins, n-1);
    }
    */
    
    // 3. DP: 
    // -------------------------------------------------------------------------------
     
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[300 + 1][5000 + 1]; 
        // initialize the matrix
        // (0, 0) n=0, arr[]={}, sum=0: ans => empty subset = 1 way
        // (1, 0) n=0, arr[]={1}, sum=0: ans => empty subset = 1 way
        // (0, 1) n=0, arr[]={}, sum=1: ans => not possible = 0 way
        
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 1;
        }
        for(int j=0; j<=amount; j++)
        {
            dp[0][j] = 0;
        }
        
        // converting recurive code to iterative
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=amount; j++)
            {
                if(coins[i-1] <= j)
                {
                    dp[i][j] = (dp[i][j - coins[i-1]] + dp[i-1][j]);
                }
                else 
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
