 int subarraysWithAtMostKDistinct(vector<int> nums, int k)
    {
        unordered_map<int, int> freq;
        int size = nums.size();
        int start = 0, end = 0;
        int total = 0;
        
        while(end < size)
        {
            if(freq[nums[end]] == 0) // distinct
            {
                k--;
            }
            
            if(k >= 0)
            {
                freq[nums[end]]++;
            }
            
            else
            {
                freq[nums[end]]++;
                while(k < 0)
                {
                    if(freq[nums[start]] == 1)
                    {
                        k++;
                    }
                    freq[nums[start]]--;
                    start++;
                }
            }
            end++;
            total += end-start+-1;
        }

        return total;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int atMostKdistinct = subarraysWithAtMostKDistinct(nums, k);
        
        int atMostK_1distinct = subarraysWithAtMostKDistinct(nums, k-1);
        
        return atMostKdistinct - atMostK_1distinct;
    }
