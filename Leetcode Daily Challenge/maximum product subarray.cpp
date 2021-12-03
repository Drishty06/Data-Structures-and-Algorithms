int maxProduct(vector<int>& nums) {
        // problem is only when we see a negative number
        int maxPdt = nums[0], minPdt = nums[0], best = nums[0];
        int n = nums.size();
        
        for(int i=1; i<n; i++)
        {
            if(nums[i] < 0)
            {
                swap(maxPdt, minPdt);
            }
            maxPdt = max(nums[i], maxPdt*nums[i]);
            minPdt = min(nums[i], minPdt*nums[i]);
            best = max(maxPdt, best);
        }
        return best;
    }
