// here passing vec as &arr worked but passing with value didnt work and the reason is that if we pass value it basically creates acopy of vec and takes o(n) time to copy
    bool JumpGame(vector<int> &arr, int index, vector<bool>&visited)
    {
        int size = arr.size();
        if(index < 0 || index > size - 1 || visited[index]) return false; 
        if(arr[index] == 0) return true; 
        visited[index] = true;
        return (JumpGame(arr, index+arr[index], visited) || JumpGame(arr, index-arr[index], visited)); 
        
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);;
        return JumpGame(arr, start, visited);        

    }
