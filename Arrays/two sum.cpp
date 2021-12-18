vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            mp[nums[i]] = i;
        }
        for(int i=0; i<n; i++)
        {
            if(mp.find((-nums[i] + target)) != mp.end() && mp[-nums[i] + target] > i)
            {
                ans.push_back(i);
                ans.push_back(mp[(-nums[i] + target)]);
            }
        }
        return ans;
    }
