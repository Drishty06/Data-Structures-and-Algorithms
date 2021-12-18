// approach 1: brute force
    
    vector<int> findEvenNumbers(vector<int>& arr) {
        // i for hundred position
        // j for ten position
        // k for unit position
        vector<int> res;
        unordered_set<int> s;
        int len = arr.size();
        for(int i=0; i<len; i++)
        {
            for(int j=0; j<len; j++)
            {
                for(int k=0; k<len; k++)
                {
                    if(arr[k]%2==0 && arr[i]!=0 && i!=j && j!=k && k!=i)
                    {
                        s.insert(arr[i]*100+arr[j]*10+arr[k]);
                    }
                }
            }
        }
        
        for(auto x:s)
        {
            res.push_back(x);
        }
        
        sort(res.begin(),res.end());
        
        return res;
    }
