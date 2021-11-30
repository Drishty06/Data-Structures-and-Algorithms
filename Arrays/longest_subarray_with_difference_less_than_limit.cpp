// time complexity = O(2n) = O(n)
    int longestSubarray(vector<int>& nums, int limit) {
        // since map will be storing elements in sorted order
        map<int, int> mp{ {nums[0], 0} }; 
        int start = 0, end = 0;
        int ans = 0;
        int size = nums.size();
        int maxOfWindow, minOfWindow;
        
        while(end < size)
        {
            
            mp[nums[end]]++;
            maxOfWindow = (--mp.end())->first; // because we want element just before end so --
            minOfWindow = mp.begin()->first;
            // cout<<maxOfWindow<<minOfWindow<<endl;
            
            if(maxOfWindow - minOfWindow <= limit) // valid window
            {
                ans = max(ans, end - start + 1);
            }
            else
            { // minimize the window until it becomes valid
                while(maxOfWindow - minOfWindow > limit)
                {
                    mp[nums[start]]--;
                    if(mp[nums[start]] == 0) // if disitnct element then remove it from mao
                    {
                        mp.erase(nums[start]);
                    }
                    start++;
                    maxOfWindow = mp.end()->first; // again updating min and max as removed element can be min or max
                    minOfWindow = mp.begin()->first;
                }
            }
            end++;
        }
        return ans;
    }
