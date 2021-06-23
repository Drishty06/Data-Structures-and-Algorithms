// problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
int maxProfit(vector<int>& arr) {
        int n = arr.size(),index;
        // kadane's algorithm
        int mini=arr[0], maxi=0;
        for(int i=0; i<n; i++)
        {
            mini = min(arr[i], mini);
            maxi = max(arr[i]-mini, maxi);       
        }
        return maxi;
    }
