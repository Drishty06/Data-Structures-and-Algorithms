
    // problem link: https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> s;
        vector<long long> vec;
        vec.push_back(-1);
        s.push(arr[n-1]);
        for(int i=n-2; i>=0; i--)
        {
            while(s.empty() == false && arr[i] >= s.top()) s.pop();
            if(s.empty()) vec.push_back(-1);
            else vec.push_back(s.top());
            s.push(arr[i]);
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
