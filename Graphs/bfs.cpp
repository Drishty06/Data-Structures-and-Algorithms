     vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        vector<int> bfs;
        vector<int> visited(v, 0);
        
                queue<int> q;
                q.push(0);
                visited[0] = 1;
                while(! q.empty())
                {
                    int top = q.front();
                    q.pop();
                    bfs.push_back(top);
                    
                    for(int i=0; i<adj[top].size(); i++)
                    {
                        int child = adj[top][i];
                        if(visited[child] == 0)
                        {
                            q.push(child);
                            visited[child] = 1;
                        }
                    }
                }
        return bfs;
    }    
