// problem link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1/?category[]=sliding-window&category[]=sliding-window&page=1&sortBy=submissions&query=category[]sliding-windowpage1sortBysubmissionscategory[]sliding-window#
    // idea: first of all we use simple window sliding technique but we want a data structure that can give us maximum of k elements in o(1) time
    // we use deque for the same 
    // 1. we store k elements in a deque
    // 2. we store in such a way that we take care of following 2 points:
    //    * if current number is greater than last element of deque then we pop the last element unitl current element is greater than or equal to dq.back element
    //    * and if is smaller than we simply push the index of newly added item to the back of deque
    // 3. then we run a loop from i=k and remove all the previous elements - the ones eith index greater than i-k
    // 4. repeating step 2 again
    
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> dq;
        vector <int> vec;
        
        for(int i=0; i<k; i++)
        {
            while(dq.empty() == false && arr[dq.back()] <= arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        for(int i=k; i<n; i++)
        {
            vec.push_back(arr[dq.front()]);
            while(dq.empty() == false && dq.front() <= i-k)
            {
                dq.pop_front();
            }
            while(dq.empty() == false && arr[dq.back()] <= arr[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);

        }
        vec.push_back(arr[dq.front()]);
        
        
        return vec;
        
    }
