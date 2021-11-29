int longestOnes(vector<int>& nums, int k) {
        int size = nums.size();
        int start = 0, end = 0;
        int len = 0, ans = 0;
        
        while(end < size)
        {
            if(nums[end] == 0)
            {
                k--;
            }
            
            if(k >= 0)
            {
                len++;
                ans = max(ans, len);
            }
            
            else
            {
                while(k < 0)
                {
                    if(nums[start] == 0)
                    {
                        k++;
                    }
                    start++;
                    len = end - start + 1;
                }
            }
            end++;
        }
        return ans;
    }
};
// code for longest substring with atmost k distinct elements
// string longestSubstringWuthAtmostKDistinct(string s, int k) {
//         int size = s.length();
//         int start = 0, end = 0;
//         int len = 0, ans = 0;
//         unordered_map<char, int> mp;
        
//         while(end < size)
//         {
//             if(mp[s[end]] == 0) // distinct
//             {
//                 k--;
//             }
            
//             if(k >= 0)
//             {
//                 len++;
//                 mp[s[end++]];
//                 ans = max(ans, len);
//             }
            
//             else
//             {
//                 mp[s[end]]++;
//                 while(k < 0)
//                 {
//                     if(mp[s[start]] == 1)
//                     {
//                         k++;
//                     }
//                     mp[s[start]]--;
//                     start++;
//                     len = end - start + 1;
//                 }
//             }
//             end++;
//         }
//         if(ans != 0) {
//             return s.substr(start, ans);
//         }
//     return "";
//     }
