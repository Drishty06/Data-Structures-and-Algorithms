// problem link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1/?category[]=sliding-window#
// window sliding technique
vector<int> subarraySum(int arr[], int n, int s)
    {
        // using window sliding technique
        long long int sum=arr[0],start;
        vector<int> ans;
        start=0;
        
        for(int i=1; i<=n; i++)
        {
           
            while(sum > s && start < i-1)
            {
                sum-=arr[start]; // if sum is greater than the required sum than we decrement the starting elements
                start++;
            }
            if(sum == s) // if sum = required sum than returning the function back
            {
                ans.push_back(start+1);
                ans.push_back(i);
                return ans;
                
            }
            if(i < n) // if iterator has not reached to last element that expanding the window by adding new elements
            {
                sum+=arr[i];
            }
        }
        ans.push_back(-1);
        return ans;
    
    }
