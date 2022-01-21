// problem link: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/#
    // notes pg: 16-21
	int minDifference(int arr[], int n)  { 
	    int sum = accumulate(arr, arr+n, 0);
	    bool dp[n + 1][sum + 1];
    
	    // initializing values
        for(int i=0; i<n+1; i++)
        {
            dp[i][0] = true;
        }
        for(int j=1; j<sum+1; j++)
        {
            dp[0][j] = false;
        }
        // filing the matrix
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = ((dp[i-1][j - arr[i-1]]) || dp[i-1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
	    int minDiff = INT_MAX;
	    
	    for(int i=sum/2; i>=0; i--)
	    {
	        if(dp[n][i] == true) 
	        {
	            minDiff = sum - (2*i);
	            break;
	        }
	    }
	    return minDiff;
	} 
