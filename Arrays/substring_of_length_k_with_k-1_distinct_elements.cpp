// problem link: https://practice.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1/?category[]=sliding-window&category[]=sliding-window&difficulty[]=1&page=1&sortBy=submissions&query=category[]sliding-windowdifficulty[]1page1sortBysubmissionscategory[]sliding-window#
int countOfSubstrings(string str, int k) {
        // window sliding technique
        // count array method
        long int count[26]={0}, distinct=0,ans=0,n=str.length();
        for(int i=0; i<k; i++)
        {
            count[str[i]-97]++; // counting impressions/frequencies of letters in the first window
        }
        
        for(int j=k; j<=n; j++)
        {
            for(int i=0; i<26; i++)
            {
                if(count[i] == 1) distinct++; // counting distinct elements
            }
            
            
            if(distinct+1 == k-1) 
            {
                ans++;
            }
            distinct=0;
            count[str[j]-97]++; // sliding the window
            count[str[j-k]-97]--;
        
        }
        
        return ans;
    }
