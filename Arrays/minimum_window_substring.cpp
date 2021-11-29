// -------------------------------------------------------------------------------------------------------
    // best approach using one map
    
    string minWindow(string s, string t) 
    {
        int tLen = t.length(),sLen = s.length();
        int count = tLen; // initally count will have total elements present in t string and
        // if we find a char in s which is present in t then we will decrement the count
        
        unordered_map<char, int> window;
        // initially this map stores freq of all characters present in t
        // then while traversing through s, we will decrease the freq of every char in s in this window map. if an element is not present in, its freq will become negative in window map
        
        for(int i=0; i<tLen; i++)
        {
            window[t[i]]++;
        }
        
        // initialize 2 pointers 
        int start = 0, end = 0, minLen = INT_MAX, minStart = 0;
        while(end < sLen)
        {
            if(window[s[end]]>0) // if char in s is present in window map and its freq is not negative yet that means that that char has to a part of valid substring. also count--
            {
                count--;
            }
            window[s[end]]--;// we have added that element into consideration and now its freq has to be decreased
            end++;
            
            
                while(count == 0) // minimize the window from start until all the required elements are present and elements with negative frequency are removed // if window is valid substring then we try to minimize the window by removing characters with negative frequency --> in this case count will be zero as all required number of elements are present in selected window
                {
                    if(end - start < minLen)
                    {
                        minStart = start;
                        minLen = end - start;
                    }
                    window[s[start]]++;    // since now we are removing the starting elements which are not making any different to validity of string but just increasing its length. so we add those elements back to map
                    
                    if(window[s[start]] > 0) // char present in t
                    {
                        count++;
                    }
                    start++;
                }
            
        }
        if(minLen != INT_MAX)
        {
            return s.substr(minStart, minLen);
        }
        return "";
    }
    
    
    // -------------------------------------------------------------------------------------------------
    // my first interview approach
//     void minimizingWindow(string &windowString, unordered_map<char, int> &sMap, unordered_map<char, int> tMap)
//     {
//         while()        
//     }
//     string minWindow(string s, string t) {
//         unordered_map<char, int> tMap; // char, frequency
//         int tLen = t.length(), sLen = s.length();
                
//         for(int i=0; i<tLen; i++)
//         {
//             tMap[t[i]]++;
//         }
        
//         unordered_map<char, int> sMap; // char, frequency
//         string windowString = "", ansString = "";
//         int found = 0;
//         bool firstTIme = true;
//         // 1. element present tMap
//         // 2. element is not present in tMap: a. sMap is empty - nothing to do anything
//         //                                    b. sMap is not empty - element present in bw of element present in tMap - consider
//         // two cases to be considered are 1 and 2.(b)
//         for(int i=0; i<sLen; i++)
//         {
//             if(tMap.find(s[i]) != tMap.end())// element present in t string
//             {
//                 // 2nd condition - freq of that char in tMap is greater than its freq in sMap\
//                 if(tMap[s[i]] > sMap[s[i]])
//                 {
//                     found++;
//                     windowString += s[i]; // appending current character
//                     sMap[s[i]]++;
//                     if(found == tLen) // all elements with required freq are now found in substring
//                     {
//                         if(firstTime)
//                         {
//                             // perform operations on windowString
//                             minimizingWindow(windowString, sMap, tMap);
//                             ansString = windowString;
//                         }
//                         else
//                         {
//                             if(ansString.len() > windowString.len())
//                             {
//                                 ansString = windowString;
//                             }
//                             // perform operations on windowString
//                             minimizingWindow(windowString, sMap, tMap);
//                         }
//                     }
//                 }
//             }
//             else // if element is not present in t string (2.(b) case)
//             {
//                 if(! sMap.empty()) // 2.(b) case
//                 {
//                     windowString += s[i];
//                 }
//             }
//         }
    // -------------------------------------------------------------------------------------------------------------
    
    // one of the best apporoach using just one map leetcode discussion
    // https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
    // the approach will be using two pointers and one map
    // below is the code which I loved the most💙
    // --------------------------------------------------------------------------------------------------------
            // 1. Use two pointers: start and end to represent a window.
            // 2. Move end to find a valid window.
            // 3. When a valid window is found, move start to find a smaller window.
            // To check if a window is valid, we use a map to store (char, count) for chars in t. And use counter for the number of chars of t to be found in s. The key part is m[s[end]]--;. We decrease count for each char in s. If it does not exist in t, the count will be negative.

            // To really understand this algorithm, please see my code which is much clearer, because there is no code like if(map[s[end++]]++>0) counter++;.

            // string minWindow(string s, string t) {
            // 	unordered_map<char, int> m;
            // 	// Statistic for count of char in t
            // 	for (auto c : t) m[c]++;
            // 	// counter represents the number of chars of t to be found in s.
            // 	size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
            // 	size_t size = s.size();

            // 	// Move end to find a valid window.
            // 	while (end < size) {
            // 		// If char in s exists in t, decrease counter
            // 		if (m[s[end]] > 0)
            // 			counter--;
            // 		// Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
            // 		m[s[end]]--;
            // 		end++;
            // 		// When we found a valid window, move start to find smaller window.
            // 		while (counter == 0) {
            // 			if (end - start < minLen) {
            // 				minStart = start;
            // 				minLen = end - start;
            // 			}
            // 			m[s[start]]++;
            // 			// When char exists in t, increase counter.
            // 			if (m[s[start]] > 0)
            // 				counter++;
            // 			start++;
            // 		}
            // 	}
            // 	if (minLen != INT_MAX)
            // 		return s.substr(minStart, minLen);
            // 	return "";
            // }
    // -------------------------------------------------------------------------------------------------------------
    
    
