     void DFS(int vertex, vector<int> &visited, vector<int> adj[], vector<int> &ans)
    {
        visited[vertex] = 1;
        ans.push_back(vertex);
        for(int i=0; i<adj[vertex].size(); i++)
        {
            int child = adj[vertex][i];
            if(visited[child] == 0)
            {
                DFS(child, visited, adj, ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int vertices, vector<int> adj[]) 
    {
        vector<int> visited(vertices, 0), ans;
        // for loop is for unconnected components
        for (int i=0; i<vertices; i++)
        {
            if (visited[i] == 0) {
                DFS(i, visited, adj, ans);
            }
        }
        return ans;
    }   
