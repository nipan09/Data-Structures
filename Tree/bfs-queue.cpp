#include <bits/stdc++.h>
using namespace std;

// BFS through Queue

class BST{
	public:
	int data;
	BST* right;
	BST* left;
};

BST* create(int data){
	BST* node = new BST;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BST* insert(BST* root, int data){
	if(root==NULL) return create(data);
	else if(data < root->data) 
		root->left = insert(root->left, data);
	else 
		root->right = insert(root->right, data);
	return root;
}


void bfs(BST* root){
	if(root==NULL) return;
	queue<BST*>q;
	q.push(root);
	
	while(q.empty()==false){
		BST* node = q.front();
		cout<< node->data <<" ";
		q.pop();
		
		if(node->left)
			q.push(node->left);
		if(node->right)
			q.push(node->right);
	}
}

int main(){
	/*
				30
			  /    \
			 20    40
		    /        \
		   15        50
		  /            \
		 10            60
	*/		
	BST* root = NULL;
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 20);
	root = insert(root, 50);
	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 60);
	
	bfs(root);
	return 0;
}
	
