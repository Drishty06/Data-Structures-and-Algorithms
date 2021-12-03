int rob(vector<int>& nums) {
        
        int size = nums.size();
        int oddSum = 0, evenSum = 0;
        for(int i=0; i<size; i++)
        {
            if(i % 2 == 0)
            {
                evenSum +=nums[i];
                evenSum = max(evenSum, oddSum);
            }
            else
            {
                oddSum += nums[i];
                oddSum = max(evenSum, oddSum);
            }
        }
        return max(oddSum, evenSum);
        
    }

