int maxPower(string s) {
        int len = s.length();
        int currStringCount = 1, maxStringCount = 1;
        
        for(int i=0; i<len; i++)
        {
            if(s[i] == s[i + 1])
            {
                currStringCount++;
                maxStringCount = max(currStringCount, maxStringCount);
            }
            else
            {
                currStringCount = 1;
            }
        }
        return maxStringCount;
    }
