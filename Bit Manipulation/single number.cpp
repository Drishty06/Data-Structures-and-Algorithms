int singleNumber(vector<int>& nums) {
        // xor operation
        int n = nums.size();
        int Xor = nums[0];
        for(int i=1; i<n; i++)
        {
            Xor ^= nums[i];
        }
        return Xor;
    }
