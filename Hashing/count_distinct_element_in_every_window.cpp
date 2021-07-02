// problem link: https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1/?category[]=sliding-window&category[]=sliding-window&page=1&sortBy=submissions&query=category[]sliding-windowpage1sortBysubmissionscategory[]sliding-window#
vector <int> countDistinct (int arr[], int n, int k)
    {
        vector <int> ans;
        unordered_map <int, int> mp;
        int left=0, right=0;
        for(right=0; right<n; right++)
        {
            if(right-left < k)
            {
                mp[arr[right]]++;
            }
            else
            {
                ans.push_back(mp.size());
                mp[arr[left]]--;
                mp[arr[right]]++;
                if(mp[arr[left]] <= 0) mp.erase(arr[left]); // this is step where generally the mistake occures since not including this will give wrong answers
                left++;
                
            }
        }
        ans.push_back(mp.size());
        return ans;
    }
