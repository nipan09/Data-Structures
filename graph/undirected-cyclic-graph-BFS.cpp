#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int src, dest;
};

class Graph{
	public:
	vector<vector<int>> adjList;
	
	Graph(vector<Edge> &edges, int N){
		adjList.resize(N);
		
		for(auto &edge: edges){
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};


struct Node{
	int v, parent;
};


/*
 *Case may be like:
     4---3---5
     |       |
     |       |
     1-------2 
  
  * 3 is the parent of 5.
  * So, while going for adjList, if we choose again 3,
  * then its a visited node and also its a parent, no cycle.
  * But if we let suppose 2, if its visited but 5 is not derived from 2,
  * then a cycle is there.
 */

bool BFS(Graph &graph, int src, int N){
	bool visited[N] = {false};
	
	visited[src] = true;
	queue<Node>q;
	q.push({src,-1});
	
	while(!q.empty()){
		Node node = q.front();
		q.pop();
		
		for(int u:graph.adjList[node.v]){
			// if not visited, push it in the queue with current node being the parent.
			if(!visited[u]){
				visited[u]= true;
				
				q.push({u,node.v});
			}
			
			// if visited but not the parent
			else if(u!=node.parent) return true;
		}
	}
	return false;
}	


int main(){
		vector<Edge> edges=
		{
			{1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
			{5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}, {6, 10}
		};
		
		int N = 13;
		
		Graph graph(edges,N);
		
		if (BFS(graph, 1, N))
			cout<<"The graph contains a cycle";
		else 
			cout<<"The graph doesn't have a cycle";
		
		return 0;
}
