    int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        if(intervals.size() == 1) return ans;
        int ans_idx = 0;
        
        for(int i=0; i<n-1; i++)
        {
           if(ans[ans_idx][1] >= intervals[i+1][0])
           {
               ans[ans_idx][1] = max(ans[ans_idx][1], intervals[i+1][1]);
           }
           else
           {
               ans.push_back(intervals[i+1]);
               ans_idx++;
           }
        }
        return ans;
    }
