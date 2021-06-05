#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adjList;

void graph(int src, int dest){
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

int main(){
	int size;
	cout<<"Size: ";
	cin>>size;
	
	adjList.resize(size);
	
	int src, dest;
	cout<<"Give the edges: "<<endl;
	for(int i=0; i<size; i++){
		cin>>src>>dest;
		graph(src, dest);
	}
	
	cout<<"The graph is: "<<endl;
	for(int i=0; i<size; i++){
		cout<<i<<"-> ";
		for(int v:adjList[i]) cout<<v<<" ";
		cout<<endl;
	}
	
	return 0;
}

