int findMinArrowShots(vector<vector<int>>& points) {
        int size = points.size();
        sort(points.begin(), points.end());
        int minimum = points[0][0];
        int maximum = points[0][1];
        int ans = 1;
        for(int i=1; i<size; i++)
        {
            if(points[i][0] >= minimum && points[i][0] <= maximum)
            {
                minimum = max(minimum, points[i][0]);
                maximum = min(maximum, points[i][1]);
            }
            else
            {
                ans++;
                minimum = points[i][0];
                maximum = points[i][1];
            }
        }
        return ans;
    }
