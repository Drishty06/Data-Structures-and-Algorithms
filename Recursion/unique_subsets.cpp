problem link: https://practice.geeksforgeeks.org/problems/subsets-1587115621/1#

    // if you are wondering that the below code is recursion without base case and still working - then 
    // reason: because return value is void and recursive call is inside the for loop and so if the loop condition fails there won't be any recursive call and it will simply return
    void subset_generator(vector<int> &original_arr, vector<vector<int>> &result, vector<int> &helper, int index)
    {
        // for every array element we have two choices:
        // 1. add it in subarray
        // 2. not adding it in sub array
        // on the basis of this we form the recursive tree
        result.push_back(helper); 
    
        for(int i=index; i<original_arr.size(); i++)
        {
            // since array is in sorted form so we check if the previous element is similar to current element to avoid duplicates
            if(i != index && original_arr[i] == original_arr[i-1]) continue; 
            helper.push_back(original_arr[i]);
            subset_generator(original_arr, result, helper, i+1); // acc to choice 1: adding the next element
            helper.pop_back(); // pop back refers to removing the lastly added element
            // we do pop back for choice 2: i.e., considering subset without adding current element
        }
    }
    
    vector<vector<int>> AllSubsets(vector<int> original_arr, int size)
    {
        vector<vector<int>> result; // stores final result
        vector<int> helper; // temporary array
        int index=0;
        // since it is mentioned that we have to print subsets in sorted form:
        sort(original_arr.begin(), original_arr.end());
        subset_generator(original_arr, result, helper, index);
        return result;
    }
