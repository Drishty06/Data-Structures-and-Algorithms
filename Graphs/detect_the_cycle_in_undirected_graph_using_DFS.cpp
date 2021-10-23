// problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
    
    bool cycleDetectionUsingDfs(int curr, int prev, vector<int> &visited, vector<int> adj[])
    {
        visited[curr] = 1;
        for(auto it: adj[curr])
        {
            if(visited[it] == 0)
            {
                if(cycleDetectionUsingDfs(it, curr, visited, adj)) return true;
            }
            else if(prev != it)
            {
                return true;
            }
        }
        return false;
    }
    
     bool isCycle(int v, vector<int> adj[]) 
    {
        vector<int> visited(v, 0);
        for(int i=0; i<v; i++) // loop to ensure all connected components are covererd
        {
            if(visited[i] == 0)
            {
                if(cycleDetectionUsingDfs(i, -1, visited, adj)) return true;
            }
        }
        return false;
    }
