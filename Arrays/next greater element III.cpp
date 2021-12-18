int nextGreaterElement(int n) {
        string num = to_string(n);
        int len = num.length();
        if(next_permutation(num.begin(), num.end()))
        {
            long ans = stol(num);
            if(ans > INT_MAX) return -1;
            return ans;
        }

        return -1;
        
    }
