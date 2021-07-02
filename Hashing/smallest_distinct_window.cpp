// problem link: https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1
// my Youtube explanation video: https://www.youtube.com/watch?v=BMaTDPa2oh8
// window sliding + two pointer approach
// string aabcbcdbca
string findSubString(string str)
    {
        int count[256] = {0}; // used to store unique characters from the string
        int distinct = 0; // stores number of distinct characters in the string
        int n = str.length();
        
        for(int i=0; i<n; i++) 
        {
            if(count[str[i]] == 0)
            {
                count[str[i]] = 1;
                distinct++;
            }
        }
        // count -> a = 1. b = 1, c = 1, d = 1
        // left and right pointers for two pointer approach
        int left = 0;
        int len = n, distinct_elements = 0; // stores the distinct elements in the selected window
        int window[256]={0}; // stores the occurrences of characters in the selected window
        
        for(int right=0; right<n; right++)
        {
            window[str[right]]++; // updating window
            
            if(window[str[right]] == 1) // incase it is the first occurrence of particular character
            {
                distinct_elements++;
            }
            
            if(distinct_elements == distinct) // in case the selected window has number of distinct elements same as that in original 
            {                                 // we start on shrinking the size of window
                while(window[str[left]] > 1) 
                {
                    if(window[str[left]] > 1)
                    {
                        window[str[left]]--;
                    }
                    left++;
                }
                len = min(len, right-left+1); // updating the length according to the positions of right and left pointers
            }
        }
        return (str.substr(left, len));  
    }
