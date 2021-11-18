// problem link: https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
    // bridge: edge which when removed, increases number of connected components.
    // concept of dfs tree, forward edge and backward edge: https://www.youtube.com/watch?v=S7fIqu1LgJw
    //  ▶back edges; creates a cycle, connects descendent to ancestors and can never be bridges
    // there are 3 cases while doing dfs traversal: 1. node in the adjacency list is,
    //      1. its direct parent - forward edge - no need to do anything
    //      2. already visited node but not its parent - back edge -> its ancestor - low[curr] = min(low[curr], in[child])
    //      3. not visited - dfs call
    // https://www.youtube.com/watch?v=ECKTyseo2H8
    
    void dfs(int it, int c, int d, vector<int> &visited, vector<int> adj[])
    {
        visited[it] = 1;
        for(auto i: adj[it])
        {
            if((it == c && i == d) || (it == d && i == c)) continue; // parent condition as well as ancestor condition both covered
            if(! visited[i])
            {
                dfs(i, c, d, visited, adj);
            }
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // we need to maintain three vectors: visited, inTime, lowestTime if we have to find all bridges
        vector<int> visited(V, 0);
        // vector<int> inTime;
        // vector<int> lowestTime;
        
        dfs(c, c, d, visited, adj);
        if(! visited[d])
        {
            return 1;
        }
        return 0;
    }
