// problem link: https://practice.geeksforgeeks.org/problems/maximum-sum-of-subarray-less-than-or-equal-to-x4033/1/?category[]=sliding-window&category[]=sliding-window&difficulty[]=0&page=1&sortBy=submissions&query=category[]sliding-windowdifficulty[]0page1sortBysubmissionscategory[]sliding-window#
// window sliding technique
int findMaxSubarraySum(long long arr[], int n, long long x)
	{
	    // little modification of kadane's Algorithm
        int best=0,sum=0,start=0,j;
        
        for(j=0; j<=n; j++)
        {
            if(sum <= x)
            {
                best=max(best,sum);
            }
             
            
            while(sum+arr[j] > x && start < j)
            {
                sum-=arr[start]; // if sum is greater than the required sum than we decrement the starting elements
                start++;
            }
            sum+=arr[j];
        }
        
        
        return best;
        
	}  
