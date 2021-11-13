// optimized solution of prim's algorithm: using priority queue
// which makes time complexity (n+e) + nlog n 
// Minimum spanning tree
// spanning tree of a graph is a tree which has exactly n number of nodes and n-1 number of edges
// minimum spanning tree means the summation of weights of the edges is minimum
// Prim's algo steps:
// Initialize the minimum spanning tree with a vertex chosen at random.
// Find all the edges that connect the tree to new vertices, find the minimum and add it to the tree
// Keep repeating step 2 until we get a minimum spanning tree

#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	int nodes, edges, source;
	cin>>nodes>>edges;
	vector<pair<int, int>> adj[nodes+1]; // adjacency list for weighted graph

	int a, b, weight;
	for(int i=0; i<edges; i++)
	{
		cin>>a>>b>>weight;
		adj[a].push_back(make_pair(b, weight));
		adj[b].push_back(make_pair(a, weight));
	}

	// optimized solution for prim's algorithm:
	// we take 3 vectors
	vector<bool> mst(nodes, false); // element which is getting included in the mst is marked true here
	vector<int> parent(nodes, -1); // parent of the next element (this is mainly used while printing output)
	vector<int> key(nodes, INT_MAX); // edge weights which are to be considered - all initialized with infinity

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	key[0] = 0; // initializing with first node which is 0th node and making its key 0
	pq.push({0, 0});

	for(int i=0; i<nodes-1; i++) // loop which runs n-1 times for n-1 edges
	{
		// int minimum_of_keys = INT_MAX, u;
		// for(int j=0; j<nodes; j++) // loop to find the minimum of keys which is not already present in mst
		// {
		// 	if(mst[j] == false && key[j] < minimum_of_keys)
		// 	{
		// 		minimum_of_keys = key[j];
		// 		u = j;
		// 	}
		// }

		// WE REPLACE ABOVE SECTION WITH MIN HEAP PRIORITY QUEUE WHICH CAN GIVE MIN IN LOG N TIME AND
		// TIME COMPLEXITY TO TRAVERSE THRU EACH ADJACENCY LIST ITEM IS O(N+E) AND NOT N^2
		int u = pq.top().second;
		pq.pop();

		mst[u] = true;
		for(auto it: adj[u]) // to iterate over the adjacency list elements and changing parent and key values if current weight is less than prev key
		{
			int connected_node = it.first;
			int weight = it.second;
			if(mst[connected_node] == false && weight < key[connected_node])
			{
				parent[connected_node] = u;
				pq.push({key[connected_node], connected_node});
				key[connected_node] = weight;
			}
		}

	}
	for(int i=1; i<nodes; i++)
	{
		cout<<parent[i]<<"-"<<i<<endl;
	}

	return 0;
}
