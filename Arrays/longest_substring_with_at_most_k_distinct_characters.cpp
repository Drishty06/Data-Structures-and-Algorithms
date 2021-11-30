string longestSubstringWuthAtmostKDistinct(string s, int k) {
        int size = s.length();
        int start = 0, end = 0;
        int len = 0, ans = 0;
        unordered_map<char, int> mp;
        
        while(end < size)
        {
            if(mp[s[end]] == 0) // distinct
            {
                k--;
            }
            
            if(k >= 0)
            {
                len++;
                mp[s[end++]];
                ans = max(ans, len);
            }
            
            else
            {
                mp[s[end]]++;
                while(k < 0)
                {
                    if(mp[s[start]] == 1)
                    {
                        k++;
                    }
                    mp[s[start]]--;
                    start++;
                    len = end - start + 1;
                }
            }
            end++;
        }
        if(ans != 0) {
            return s.substr(start, end - start + 1);
        }
    return "";
    }
