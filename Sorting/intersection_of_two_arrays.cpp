// problem link: https://leetcode.com/problems/intersection-of-two-arrays/
vector<int> intersection(vector<int>& vec1, vector<int>& vec2) {
        vector<int> result;
        long int i=0,j=0,k=0;
        long int len1=vec1.size(), len2=vec2.size();
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        
        while(i < len1 && j < len2)
        {
            if(vec1[i] == vec2[j]) // equality condition
            {
                if(k != 0)
                {
                    if(vec1[i] != result[k-1]) // to avoid similar elements
                    {
                        result.push_back(vec1[i]);
                        i++;
                        j++;
                        k++;
                    }
                    else
                    {
                        i++;
                        j++;
                    }
    
                }
                else
                {
                    result.push_back(vec1[i]);
                    i++;
                    j++;
                    k++;
                }
            }
            else if(vec1[i] < vec2[j]) i++;
            
            else if(vec2[j] < vec1[i]) j++;
        }
        
        return result;
}
