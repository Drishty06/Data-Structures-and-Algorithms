// problem link: https://practice.geeksforgeeks.org/problems/topological-sort/1
	// topological sort: linear ordering of vertices, such that if there is an edge from u->v, u appears before v in that ordering
	// using bfs
	// kahn's algorithm
	// using the basic property of topological sort, 
	// any element whose indegree is 0 that means there isn't any incoming edge, that means it is not depended on any node (that usko iss node se pehle ana hoga) so basically it doesnt has that responsiblity to come before any node, so it can be first
	// now all the nodes which were present in adjacency list of node with indegree 0, has lost the dependency on it since we already included that node in our topo vector
	// so we reduce the indegree of such nodes
	// so likewise we keep on adding elements with indegree 0 and then pick up element from queue, analyse elements present in its adjacency list and once done, we pop the element from adjacency list
	
	void topoUsingBfs(vector<int> &topo, vector<int>adj[], vector<int> &indegree, queue<int> &q)
	{
	    while(! q.empty())
	    {
	        int curr = q.front();
	        q.pop();
	        topo.push_back(curr);
	        
	        for(auto it: adj[curr])
	        {
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	}
	
	vector<int> topoSort(int v, vector<int> adj[]) 
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
	    
	    vector<int> topo;
	    
        for(int i=0; i<v; i++) 
        {
            if(indegree[i] == 0) q.push(i);
        }
        
        topoUsingBfs(topo, adj, indegree, q);
        
        return topo;
    }
