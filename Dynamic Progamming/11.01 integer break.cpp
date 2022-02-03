// intuition: 
    // 1. for every n, we have 1 to n-1 elements, like for n=10, the subparts in which we can break it into is in the reange [1, 9]. for these numbers from 1-9, we have CHOICES for each element whether to include it or not to include it.
    // 2. we have been asked to MAXIMIZE the product
    // ----------------------------------------------------------------------------------------
    // from points 1 and 2 we can say that since we have choices and asked for maximization, it is a dp problem. ~IDENTIFICATION 01 DONE!
    // ----------------------------------------------------------------------------------------
    // 3. here we have maximum capacity of n, that is we cannot hold elements more than the sum of n. so this is resembling W in knapsack problems.
    // 4. for any element, we can have its mulltiple occurences like, in case of n =10, I can have 3+3+3+2. so here 3 occured multiple times.
    // ----------------------------------------------------------------------------------------
    // from point 3, we can understant that ir is a knapsack problem, and from point 4, we can understant that it is unbounded knapsack problem. ~IDENTIFICATION 02 DONE!
    // unbounded knapsack problem!
    // ---------------------------------------------------------------------------------------
    
    // 1. RECURSION: ACCEPTED BUT CAN BE OPTIMIZED
    // ---------------------------------------------------------------------------------------
    /*
    int integerBreakRecursive(int capacity, int i, int n) // returns product
    {
        if(capacity == 0) // the elements which we chose are summing up to n
        {
            return 1; // if that permutation of elements is summing up to n then we return 1 as the product
        }
        if(i > capacity || capacity < 0 || i > n) // if current element is greater than the capacity of knapsack or the total sum is becoming greater than n - not possible permutation - therefore we return product 0
        {
            return 0;
        }
        return max(integerBreakRecursive(capacity-i, i, n)*i ,integerBreakRecursive(capacity, i+1, n));   
    }
    
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        return integerBreakRecursive(n, 1, n);
    }
    */
    // -------------------------------------------------------------------------------
    
    // 2. MEMOIZATION: accepted
    // -------------------------------------------------------------------------------
    
    
    int memo[58 + 1][58 + 1];
    int integerBreakMemo(int capacity, int i, int n) // returns product
    {
        if(capacity == 0) // the elements which we chose are summing up to n
        {
            return 1; // if that permutation of elements is summing up to n then we return 1 as the product
        }
        if(i > capacity || capacity < 0 || i > n) // if current element is greater than the capacity of knapsack or the total sum is becoming greater than n - not possible permutation - therefore we return product 0
        {
            return 0;
        }
        if(memo[i][capacity] != -1) 
        {
            return memo[i][capacity];
        }
        return memo[i][capacity] = max(integerBreakMemo(capacity-i, i, n)*i ,integerBreakMemo(capacity, i+1, n));   
    }
    
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        memset(memo, -1, sizeof(memo));
        return integerBreakMemo(n, 1, n);
    }
    
    // ----------------------------------------------------------------------------------
    
    // 3. TABULATION: 
    // ----------------------------------------------------------------------------------
    // leaving as of now, its a 1D dp question
    
