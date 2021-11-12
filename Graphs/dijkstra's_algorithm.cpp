// Dijkstra's algorithm: to find shortest path from to source node to every other node
// 1. Mark initial distance from the source as infinite.
// 2. Create an empty priority_queue PQ. Every item of PQ is a pair (weight, vertex). 
// Weight is used as the first item of pair as the first item is by default used to compare two pairs.
// 3. Insert source vertex into PQ and make its distance as 0.
// 4. Until the priority queue defined as PQ does not become empty. Perform the operations a and b.
// 		a. Extract minimum distance vertex from PQ and let it be u.
// 		b. Loop through all adjacent of u and do
// 		   Following for every vertex v.
// 		   If there is a shorter path to v through u.
// 			If dist[v] > dist[u] + weight(u, v) // distance of ( v) > distance of (u) and weight from u to v
// 			Update distance of v, i.e., do
// 			dist[v] = dist[u] + weight(u, v)
// 			Insert v into the pq (Even if v is already there)
// 			Loop through the dist[] array to print the shortest paths from source to all the vertices

#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	int n, m, source;
	cin>>n>>m;
	vector<pair<int, int>> adj[n+1]; // adjacency list for weighted graph

	int a, b, weight;
	for(int i=0; i<m; i++)
	{
		cin>>a>>b>>weight;
		adj[a].push_back(make_pair(b, weight));
		adj[b].push_back(make_pair(a, weight));
	}
	
	cin>>source;
	// Dijkstra's algorithm uses min heap
	// algo starts:

	// this is the syntax to declare min heap priority queue
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {dist, fromWhichNode}
	vector<int> distTo(n+1, INT_MAX); // distance vector storing minimum distance. initially set to infinity

	distTo[source] = 0; // minimum dist of source from source = 0
	pq.push(make_pair(0, source));

	while(! pq.empty())
	{
		int dist = pq.top().first;
		int prev = pq.top().second;
		cout<<dist<<prev;
		pq.pop();

		for(auto it: adj[prev])
		{
			int next = it.first; // node
			int nextDist = it.second; // weight
			if(distTo[next] > distTo[prev] + nextDist)
			{
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}

	cout<<"The distances from source, "<<source<<", are"<<endl;
	for(int i=1; i<=n; i++)
	{
		cout<<distTo[i]<<" ";
	}

	return 0;
}
