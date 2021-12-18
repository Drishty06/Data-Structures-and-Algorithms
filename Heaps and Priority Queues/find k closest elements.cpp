vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
	    vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<n; i++)
        {
            pq.push({abs(arr[i] - x), arr[i]});	
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        for(int i=0; i<k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
