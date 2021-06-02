// Problem link: https://leetcode.com/problems/permutation-in-string/
// My YouTube Code Explanation video😎: https://www.youtube.com/watch?v=grfC-Nk09zo

 bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        int count[256]={0}, window[256]={0}; // two arrays to store the impressions of characters of s1 and a window of s2
        int len1=s1.length();
        int len2=s2.length();
        for(int i=0; i<len1; i++) 
        {
            count[s1[i]]++; // count array stores the impressions of characters of s1 string
            window[s2[i]]++; // window array stores the impression of first window of string s2 
        }
        for(int k=len1; k<=len2; k++)
        {
            for(int j=0; j<256; j++)
            {
                if(count[j] != window[j]) // comparing all the elements of both the arrays
                {                         
                    break;
                }
                else 
                {
                    if(j == 255) // if same till last character then returning true
                    {
                        return true;
                    }
                }
            }
            window[s2[k]]++; // sliding window technique
            window[s2[k-len1]]--; // removing the very first element of window and adding a new upcoming element
        }
         return false;
    }
