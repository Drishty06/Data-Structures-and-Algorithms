// problem Link : https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1#
    bool isMatch(string wild, int i, string pattern, int j)
    {
        if(i == wild.length() && j == pattern.length()) // case 1: when both iterators reach the end of both strings simultaneously 
        {
            return true;
        }
        
        if(wild[i] == pattern[j] || wild[i] == '?') // case 2: if that's a ? then we need to skip one character from each of the strings
        {                                           // case 3: similarly if the characters of both the strings are similar then we increment both the iterators by one as well
            return isMatch(wild, i+1, pattern, j+1);
        }
        
        if(wild[i] == '*') // case 4: if it is a *:
        {                    // sub-case 1: we have to count element of pattern
                             // sub case 2: we don't have to count element of pattern
            return isMatch(wild, i+1, pattern, j) || isMatch(wild, i, pattern, j+1);
        }
        return false;
    }
    bool match(string wild, string pattern)
    {
        return isMatch(wild,0,pattern,0);
    }


// ALTERNATIVE SOLUTION: https://leetcode.com/problems/wildcard-matching/discuss/17810/Linear-runtime-and-constant-space-solution
