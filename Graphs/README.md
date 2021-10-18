### graphs' theory:
* 1. Undirected graph: having no orientation of edges. ie., edge (x, y) is identical to edge (y, x)
* 2. Directed graph: edges have orientation. ie., edge (x, y) is NOT identical to edge (y, x)
* 3. cyclic graphs: if we can reach any node via some other path then there is a cycle in the graph
* 4. acyclic graphs: opposite of cyclic graphs
* 5. degree of graphs: number of edges(incoming or outgoing)
* 6. weighted graphs: where edges have a value
* 7. connected graph: a graph which has a path between every pair of vertices
### graph representation:
* 1. adjacency matrix: nodes = n create a matrix of adj[n+1][n+1] where <br>
     adj[ i ][ j ] = 1 if ith node is connected to jth node and <br>
     adj[ i ][ j ] = 0 if ith node is not connected to jth node <br>
* 2. adjacency list: nodes = n. adjacency list = <b>vector<int> adj[ n+1 ] </b> in case of non-weighted graph <br>
     in case of weighted graph  adjacency list = <b>vector<pair<int, int>> adj[ n+1 ] </b>  
     ```
     int main()
     {
        int nodes, edges;
        cin>>nodes>>edges;
        vector<int> adj[n+1];
        for(int i=0; i<edges; i++)
        {
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u); // this line is not be written for directed graphs
        }
     }
     ```
### Graph traversal techniques: 
*  Depth first search DFS:     
     ```
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
     ```
*  Breadth first search BFS:     
     ```
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
     ```
                                                                                                             
     
