// problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
    // using bfs:
    // direct implementation of kahn's algorithm
    
    void topoUsingBfs(int &counter, vector<int>adj[], vector<int> &indegree, queue<int> &q)
	{
	    while(! q.empty())
	    {
	        int curr = q.front();
	        q.pop();
	        counter++;
	        
	        for(auto it: adj[curr])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	}
	
	bool isCyclic(int v, vector<int> adj[]) 
	{
	    vector<int> indegree(v, 0);
	    
	    for(int i=0; i<v; i++) // loop to calculate indegree of nodes
	    {
	        for(auto it: adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    int counter=0;
	    
        for(int i=0; i<v; i++) 
        {
            if(indegree[i] == 0) q.push(i);
        }
        
        topoUsingBfs(counter, adj, indegree, q);
        
        if(counter == v) return false;
        return true;
    }
