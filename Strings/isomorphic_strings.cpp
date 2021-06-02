// problem link: https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1
// based on count array method

bool areIsomorphic(string str1, string str2)
    {
        int len1=str1.length();
        int len2=str2.length();
        if(len1 != len2) return false; // if string lengths are unequal
        
        int box1[256]={0}; // creating two count arrays to store th impression of characters in it
        int box2[256]={0};
        for(int i=0; i<len1; i++)
        {
            box1[str1[i]]++; // incrementing elements'ascii value
            box2[str2[i]]++;
            if(box1[str1[i]] != box2[str2[i]]) // checking if frequency is different 
            {
                return false;
            }
        }
        return true;
        
