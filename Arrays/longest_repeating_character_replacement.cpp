 int characterReplacement(string s, int k) {
        unordered_map <char, int> freq; 
        int start = 0, end = 0;
        int highestFreq = 0;
        int ans = 0;
        int size = s.length();
        
        while(end < size)
        {
            freq[s[end]]++;
            int currFreq = freq[s[end]];
            highestFreq = max(currFreq, highestFreq);
            // since atmost k characters can be replaced
            if((end - start + 1 - highestFreq) > k)
            {
                freq[s[start]]--;
                start++;
            }
            ans = max(ans, end - start+1);
            end++;
        }
        return ans;
    }
