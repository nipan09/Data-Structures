// DEPTH FIRST SEARCH

#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int src, dest;
};

class Graph{
	public:
	vector<vector<int>> adjList;
	
	Graph(vector<Edge>&edges, int N){
		adjList.resize(N);
		
		for(auto &edge: edges){
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};

bool iscyclic(Graph &graph, int v, bool visited[], int parent){
	visited[v] = true;
	
	for(int i: graph.adjList[v]){
		if(!visited[i]){
			if(iscyclic(graph,i,visited,v)) return true;
		}
		else if(i!=parent) return true;
	}
	return false;
}

int main(){
	vector<Edge>edges = 
	{
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}, {11, 12}
	};
	
	int N=13;
	
	bool visited[N] = {false};
	Graph graph(edges,N);
	
	if (iscyclic(graph,1,visited,-1)) cout<<"The graph contains a cycle";
	else cout<<"The graph doesn't contain a cycle";
	
	return 0;
}
