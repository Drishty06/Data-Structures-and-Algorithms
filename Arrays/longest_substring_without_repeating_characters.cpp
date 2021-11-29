// my 1st code with lil help
    // tc = O(2n) because we will only stop endPointer when suplicate number somes and will iterate back and go uptil its first occurenece. now since this is occuring simultaneously and it is equivalent to run 2 separate for loops so tc is o(2n ) rather than o(n^2)
//     int lengthOfLongestSubstring(string str) {
        
//         int len = str.length(), maxLen = 0, startPointer = 0; 
//         unordered_set<char> currString;
//         for(int endPointer = 0; endPointer < len; endPointer++)
//         {
//             // unique element
//             if(currString.find(str[endPointer]) == currString.end())
//             {
//                 currString.insert(str[endPointer]);
                 
//                 maxLen = max(maxLen, endPointer - startPointer + 1);
//             }
            
//             // not unique
//             else
//             {
//                 currString.erase(str[startPointer]);
                
//                 startPointer++;
//                 endPointer--;
//             }
//         }
//         return maxLen;
//     }
    
    // map solution 
    
    int lengthOfLongestSubstring(string s) {
        
        map<char, int> charMap;
        int start = -1;
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (charMap.count(s[i]) != 0) {
                start = max(start, charMap[s[i]]);
            }
            charMap[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        
        return maxLen;
    }
     
