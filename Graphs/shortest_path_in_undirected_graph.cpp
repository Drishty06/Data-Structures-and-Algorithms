vector<int> shortestPathInUndirectedGraph(vector<int> adj[], int v, int src)
{
	vector<int> dist(v, INT_MAX);
	dist[src] = 0;
	q.push(src);
	queue<int> q;
            
    while(! q.empty())
    {
        int top = q.front();
        q.pop();
        
        for(auto i: adj[top])
        {
            if(dist[top]+1 < dist[i])
            {
				dist[i] = dist[top] + 1;
                q.push(i);
            }
        }
    }
	return dist;
}
