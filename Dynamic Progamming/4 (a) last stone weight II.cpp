// problem link: https://leetcode.com/problems/last-stone-weight-ii/submissions/
    // intuition: for every example, actually we are adding certin elements and we are subtracting certain elements
    // for eg: 2 7 4 1 8 1 
    // => (8-7)  (4-2)  (1-1) lets say in first go we smashed these stones
    // => 1 2 0 - in the second go we can smash 2 and 1 and weight of left stone will be 1 which is minimum
    // => basically this is equivalent to (8-7) - (4-2) + (1-1) = 8 + 2 + 1 - 7 - 4 - 1
    // => 8 + 2 + 1 - 7 - 4 - 1 this is equal to (8, 2, 1) - (7, 4, 1) 
    // => overall it is equal to divding the stones array such that their difference is least - which gives us least weight
    // therefore, this is exactly similar to minimum subset sum difference
    // approach: recursion -> memoization -> optimized dp 
    // ------------------------------------------------------------------------------------
    
    // 1. recursion: TLE
    // approach: for every element I have 2 choices, whether to give it "+" sign or "-" sign
    // as we can either add that elemnt or subtract it
    // then we find out by which path we get the minimum answer as we want total sum to be as least as possible
    // so once we cover all elements we check what is the sum:
    //      => if negative: not possible as remaining stone cannot have negative weight, so we return infinity
    //      => if positive: then we return whatever the currSum was, and then check from which sign we are getting minimum answer
    
    // ------------------------------------------------------------------------------------
    
    /*
    int lastStoneWeightIIRecursive(vector<int>& stones, int n, int i, int currSum)
    {
        if(i == n)
        {
            if(currSum < 0) return INT_MAX;
            else return currSum;
        }
        return min(lastStoneWeightIIRecursive(stones, n, i+1, currSum + stones[i]), lastStoneWeightIIRecursive(stones, n, i+1, currSum - stones[i]));
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        
        int minWeight = lastStoneWeightIIRecursive(stones, n, 0, 0);
        return minWeight;        
    }
    */
    
    // -------------------------------------------------------------------------------------------
    
    // 2.(a) memoization(Aditya Verma's style):  TLE
    // 1. matrix
    // just add 2 lines in recursive code that if we find a case which is already pre-computed, then we don't do recursive calls for the same
    
    //--------------------------------------------------------------------------------------------

    /*
    int memo[30 + 1][3000 + 1];
    
    int lastStoneWeightIIRecursive(vector<int>& stones, int n, int i, int currSum)
    {
        if(i == n)
        {
            if(currSum < 0) return INT_MAX;
            else return currSum;
        }
        if(currSum > 0 && memo[i][currSum] != -1)
        {
            return memo[i][currSum];
        }
        if(currSum > 0) return memo[i][currSum] = min(lastStoneWeightIIRecursive(stones, n, i+1, currSum + stones[i]), lastStoneWeightIIRecursive(stones, n, i+1, currSum - stones[i]));
        else return min(lastStoneWeightIIRecursive(stones, n, i+1, currSum + stones[i]), lastStoneWeightIIRecursive(stones, n, i+1, currSum - stones[i]));
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        memset(memo, -1, sizeof(memo));
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        
        int minWeight = lastStoneWeightIIRecursive(stones, n, 0, 0);
        return minWeight;        
    }
    */
    
    // --------------------------------------------------------------------------------------------
        
    // 2.(b) memoisation method 2: 
    // rather than giving two choices of + and - until last index it would be better if we keep diving the sum into 2 parts and at end return absolute sum
    
    // -------------------------------------------------------------------------------------------
    
    /*
    int memo[30 + 1][3000 + 1];
    
    int lastStoneWeightIIRecursive(vector<int>& stones, int n, int i, int sum1, int sum2)
    {
        if(i == n)
        {
            return abs(sum1-sum2);
        }
        if(memo[i][sum1] != -1)
        {
            return memo[i][sum1];
        }
        return memo[i][sum1] = min(lastStoneWeightIIRecursive(stones, n, i+1, sum1 + stones[i], sum2), lastStoneWeightIIRecursive(stones, n, i+1, sum1, sum2 + stones[i]));
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        memset(memo, -1, sizeof(memo));
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        
        int minWeight = lastStoneWeightIIRecursive(stones, n, 0, 0, 0);
        return minWeight;        
    }
    */
    
    // ---------------------------------------------------------------------------------------------
    
    // 3. optimized dp approach(aditya verma's style)
    // => converting recursive code to iterative code
    
    //----------------------------------------------------------------------------------------------    
    
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        
        // dp part is exactly same as minimum subset sum difference problem
        
        bool dp[n + 1][totalSum + 1];
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n+1; i++)
        {
            dp[i][0] = true;
        }
        for(int j=1; j<totalSum+1; j++)
        {
            dp[0][j] = false;
        }
        // filing the matrix
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<totalSum+1; j++)
            {
                if(stones[i-1] <= j)
                {
                    dp[i][j] = ((dp[i-1][j - stones[i-1]]) || dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int minWeight = INT_MAX;
        
	    for(int i=totalSum/2; i>=0; i--)
	    {
	        if(dp[n][i] == true) 
	        {
	            minWeight = totalSum - (2*i);
	            break;
	        }
	    }
	    return minWeight;       
   }
