// problem link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// video explanation on my youtube channel: https://www.youtube.com/watch?v=KM4vZQg8jSs
bool m_bouquets_possible(vector<int>& bloomDay, int m, int k, int mid)
    {
        int n = bloomDay.size();
        int flower=0, bouquet=0;
        for(int i=0; i<n; i++)
        {
            if(bloomDay[i] <= mid) flower++;
            else flower=0;
            
            if(flower >= k) 
            {
                bouquet++;
                flower=0;
            }
            
        }
        if(bouquet >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int left = *min_element(bloomDay.begin(),bloomDay.end());
        int right = *max_element(bloomDay.begin(),bloomDay.end());
        int result=-1;
        
        if(bloomDay.size() < m*k) return -1;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(m_bouquets_possible(bloomDay, m, k, mid))
            {
                result = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
            
        }
        return result;
        
    }
