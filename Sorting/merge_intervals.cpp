// problem link: https://leetcode.com/problems/merge-intervals/submissions/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged;
                
        int start=intervals[0][0],end=intervals[0][1];
        // start and end keeps the track of merged intervals' range
            
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i][0]>=start && intervals[i][0]<=end) // if the next interval merges with the previous one.
            {
                end=max(end,intervals[i][1]); // end of merged interval is maximum of end of previous interval and current interval
            }
            else
            {
                merged.push_back({start,end}); // once merging stops, we add the newly merged range to final answer
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        
         merged.push_back({start,end});
        return merged;
    }
