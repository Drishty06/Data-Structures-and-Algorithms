// bridge: edge which when removed, increases number of connected components.
// concept of dfs tree, forward edge and backward edge: https://www.youtube.com/watch?v=S7fIqu1LgJw
//  ▶back edges; creates a cycle, connects descendent to ancestors and can never be bridges
// there are 3 cases while doing dfs traversal: 1. node in the adjacency list is,
//      1. its direct parent - forward edge - no need to do anything
//      2. already visited node but not its parent - back edge -> its ancestor - low[curr] = min(low[curr], in[child])
//      3. not visited - dfs call
// https://www.youtube.com/watch?v=ECKTyseo2H8


#include <bits/stdc++.h>
using namespace std;

void dfs(int it, int parent, int &timer, vector<int> &visited, vector<int> adj[], vector<int> &inTime, vector<int> &lowestTime)
{ 
	visited[it] = 1;
	inTime[it] = lowestTime[it] = timer++;
	
	for(auto child: adj[it])
	{
		if(child == parent) continue; // case 01: parent
		if(visited[child] == 1) // case 02: when it is visited and not a parent - that means it is an ancestor
		{
			lowestTime[it] = min(lowestTime[it], inTime[child]);
		}
		else // case 03 - not visited - dfs call
		{
			dfs(child, it, timer, visited, adj, inTime, lowestTime);
			
			if(lowestTime[child] > inTime[it]) // if lowTime oof previous node is lower than inTime of current node, it showws current node is still connected via another path - not a bridge. but if is higher - bridge
			{
				cout<<it<<" - "<<child<<" is a bridge"<<endl;
			}
			lowestTime[it] = min(lowestTime[it], lowestTime[child]);
		}
	}
}

int main() 
{ 
	int nodes, edges;
	cin>>nodes>>edges;

	vector<int> adj[nodes+1];
	for(int i=0; i<edges; i++)
	{
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int timer = 0;
	// we need to maintain three vectors: visited, inTime, lowestTime if we have to find all bridges
    vector<int> visited(nodes, 0);
    vector<int> inTime(nodes, -1); // if two nodes lie on the same path from root to leaf: lower in time - ancestor and higher in time - descendant
    vector<int> lowestTime(nodes, -1); // lowest ancestor which can be reached directly from that point
	for(int i=0; i<nodes; i++)
	{
		if(!visited[i]) dfs(i, -1, timer, visited, adj, inTime, lowestTime);
	}
	return 0;
}
