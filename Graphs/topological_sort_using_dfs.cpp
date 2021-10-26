// problem link: https://practice.geeksforgeeks.org/problems/topological-sort/1
	// topological sort: lineaar ordering of vertices, such that if there is an edge from u->v, u appears before v in that ordering
	// using dfs
	
	
	void topoUsingDfs(int curr, vector<int> &visited, vector<int> &topo, vector<int>adj[])
	{
	    visited[curr] = 1;
	    for(auto it: adj[curr])
	    {
	        if(! visited[it]) topoUsingDfs(it, visited, topo, adj);
	    }
	    topo.push_back(curr);
	}
	
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int> visited(v, 0);
	    vector<int> topo;
        for(int i=0; i<v; i++) //  to cover all connected components 
        {
            if(! visited[i])
            {
                topoUsingDfs(i, visited, topo, adj);
            }
        }
        reverse(topo.begin(), topo.end());
        return topo;
    }
