#include <bits/stdc++.h>
using namespace std;

class BST{
	public:
	int data;
	BST* left;
	BST* right;
};

BST* create(int data){
	BST* node = new BST;
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;

	return node;
}

BST* insert(BST* node, int data){
	if(node==nullptr) return create(data);
	else if(data < node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}

int height(BST* root);

void bfs(BST* root, int level){
	if(root==NULL) return;
	if(level==1) cout<<root->data<<" ";
	else if(level>1){
		bfs(root->left, level-1);
		bfs(root->right, level-1);
	}
}

void printLevelOrder(BST* root){
	int level = height(root);
	for(int i=1; i<=level; i++)
		bfs(root, i);
}
	
		
int main(){
	BST* root = nullptr;
	root = insert(root,5);
	root = insert(root,3);
	root = insert(root,4);
	root = insert(root,2);
	root = insert(root,6);
	root = insert(root,9);
	
	printLevelOrder(root);
	return 0;
}

int height(BST* root){
	if(root==NULL) return 0;

	return 1+max(height(root->right), height(root->left));
}
