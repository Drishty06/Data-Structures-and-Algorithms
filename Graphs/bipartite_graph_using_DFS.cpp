// problem link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1
// using DFS
// if there exists a cycle in the graph and if cycle length is odd = false
// else always true
// so basically now we will have color array instead of visited array where we will be storing the colors 
// and ensuring that adjacent ones are of different colors by using 0 as one color and 1 as another color
// we will then traverse in bfs manner and if the next node is -1 then we will change color[that node] = 0 if color[curr] = 1 and vice versa
// and if it is already colored then we will check if the colors are opposite. if they are not, then we will simply return false

    bool isBipartitenUsingDfs(int curr, vector<int> &color, vector<int> adj[])
    {
        if(color[curr] == -1) color[curr] = 1;
            for(auto it: adj[curr])
            {
                if(color[it] == -1)
                {
                    if(color[curr] == 1) color[it] = 0;
                    else color[it] = 1;
                    
                    if(! isBipartitenUsingDfs(it, color, adj))
                    {
                        return false;
                    }
                }
                else if(color[curr] == color[it])
                {
                    // cout<<"hi"<<endl;
                    return false;
                }
                
            }

        return true;
    }

	bool isBipartite(int v, vector<int>adj[])
	{
	    vector<int> color(v, -1);
        for(int i=0; i<v; i++) // loop to ensure all connected components are covererd
        {
            if(color[i] == -1)
            {
                if(! isBipartitenUsingDfs(i, color, adj)) return false;
            }
        }
        return true;
	}
