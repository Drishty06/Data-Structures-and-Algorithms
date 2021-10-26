// problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
    // using dfs:
    // we take two arrays - visited and dfs visit
    // visited[] of any no. is 1 if it is visited and dfsvisit[] of any no. is 1 if it is visited in that particular iteration of dfs. if not found in that dfs then making it 0 everytime we leave that dfs call
    
    bool detectCycle(int curr, vector<int> &visited, vector<int> &dfsVisit, vector<int> adj[])
    {
        visited[curr] = 1;
        dfsVisit[curr] = 1;
        
        for(auto it: adj[curr])
        {
            if(! visited[it])
            {
                if(detectCycle(it, visited, dfsVisit, adj)) return true;
            }
            else if(dfsVisit[it] == 1)
            {
                return true;
            }
        }
        dfsVisit[curr] = 0;
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> visited(v, 0);
        vector<int> dfsVisit(v, 0);
        for(int i=0; i<v; i++) //  to cover all connected components 
        {
            if(! visited[i])
            {
                if(detectCycle(i, visited, dfsVisit, adj)) return true;
            }
        }
        return false;
    }
