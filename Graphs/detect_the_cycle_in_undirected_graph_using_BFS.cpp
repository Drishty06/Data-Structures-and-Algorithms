// problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
    // using BFS algo
    // 1. just like implementation of BFS, use a queue
    // 2. but this time queue will be storing the node as well as its previous node
    // 3. similarly like other questions, run one for loop to ensure to cover all connected components
    // 4. then simply do bfs traversal
    // 5. take a node and if is not visited, add the node and its prev node into the queue
    // 6. if any of the node is found visited and it is not the previous node, 
    //    then it means that there existed some other path to reach same place as well, there's a cycle !
    
    bool cycleDetectionUsingBfs(int i, vector<int> &visited, vector<int> adj[], int v)
    {
        queue<pair<int, int>> q;
        visited[i] = true;
        q.push({i, -1});
        while(! q.empty())
        {
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            
            for(auto it: adj[node])
            {
                if(visited[it] == 0)
                {
                    q.push({it, node});
                    visited[it] = 1;
                }
                else if(prev != it)
                {
                    return true;
                }
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
                if(cycleDetectionUsingBfs(i, visited, adj, v)) return true;
            }
        }
        return false;
    }
