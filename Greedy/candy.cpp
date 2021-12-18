int candy(vector<int>& ratings) {
        // in one go compare with previous elements
        // in other go compare with next elements
        int n = ratings.size();
        vector<int>left(n, 1), right(n, 1);
        
        //traverse left to right and compare curr value with left side value
        for(int i=1; i<n; i++)
            if(ratings[i] > ratings[i-1]) left[i] = left[i-1]+1;
              
         //traverse right to left and compare curr value with right side value
        for(int i=n-2; i>=0; i--)
            if(ratings[i] > ratings[i+1]) right[i] = right[i+1]+1;
        
        int ans = 0;
        for(int i=0; i<n; i++)
            ans += max(left[i], right[i]);
        
        return ans;       
    }
