int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0, major;
        for(int i=0; i<n; i++)
        {
            if(count == 0) 
            {// current element can be considered as candidate
                major = nums[i];
            }
            if (nums[i] == major) count++;
            else count--;
        }
        return major;
    }
