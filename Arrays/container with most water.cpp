int maxArea(vector<int>& arr) {
        // we will have left as 0th index and right as last index 
        // so we are starting with maximum width and then we are in search of maximum height if we reducing width
        int size = arr.size();
        int left = 0, right = size-1, ans = 0;
        while(right > left)
        {
            int lh = arr[left];
            int rh = arr[right]; 
            int width = right - left;
            int height = min(lh, rh);
            
            ans = max(ans, width*height);
            if(lh > rh) 
            {
                right--;
            } 
            else
            {
                left++;
            }
        }
        return ans;
    }
