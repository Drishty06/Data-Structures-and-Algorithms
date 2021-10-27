// we didn't use simple bfs as used in this https://www.youtube.com/watch?v=hwCWi7-bRfI&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=16
// because lets say you want to do it using DFS
// yes you can do it using DFS , but consider the case when you already updated a node's distance by a dfs() call and 
// lets say its 7 and as it is DFS then its obvious that you also have updated all the nodes in its segment of DFS call . 
// now you have reached to the same node from different dfs() call and now the distance is 4 , 
// so in order to update all the nodes which were affected by the DFS call previously on the node considering distance as 7 , 
// you now again have to do the same so that its updated with new min distance.
// Same is the scenario for the simple BFS approach.
// These multiple time DFS/BFS calls degrades the Time Complexity, hence Topological Ordering save you from that overhead as you already know which nodes will come after the current node , so you keep on updating it .

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {

public:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited)
    {
        vector<int> parent(V, -1);
     
        // Create a queue for BFS
        queue<pair<int,int>> q;
     
        visited[s] = true;
        q.push({s, -1});
     
        while (!q.empty()) {
     
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
     
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
public:
	bool isCycle(int V, vector<int>adj[]){
	    vector<int> vis(V, 0); 
	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) {
	            if(checkForCycle(i, V, adj, vis)) return true; 
	        }
	    }
	    
	    return false; 
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
