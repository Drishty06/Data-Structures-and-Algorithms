int longestUniqueSubsttr(string str)
{
        // window sliding technique
        // initializing count array elements to zero
        // logic is to check whether similar elements are present 
        // and if yes then we find the first occurence of that element and cut the length of string from there
        long int n=str.length(),count[256]={0},start=0,end=0,ans=0;
        
        for(end=0; end<n; end++)
        {
            count[str[end]]++;
            while(count[str[end]] > 1) // reducing until we find the repeating element
            {
                count[str[start]]--;
                start++;
            }
            ans=max(ans, end-start+1); // to calculate maximum length
        }
        
        return ans;
    }
