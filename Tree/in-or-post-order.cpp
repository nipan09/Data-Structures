#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
};


Node* create_end(int data){
	Node* node = new Node;
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;
	
	return node;
}

Node* insert(Node* node, int data){
	if(node==nullptr) return create_end(data);
	
	if(data < node->data)
		node->left = insert(node->left, data);
	else if(data >= node->data)
		node->right = insert(node->right, data);
	return node;
}

void postorder(Node* root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data;
	}
}

void inorder(Node* root){
	if(root){
		inorder(root->left);
		cout<<root->data;
		inorder(root->right);
	}
}

void preorder(Node* root){
	if(root){
		cout<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}
		
int main(){
	/*
			9
		  /   \
		 7    14
	   /  \  /  \
	  5   8 11  16
	 
	 */
	Node* root = nullptr;
	root = insert(root,9);
	insert(root,7);
	insert(root,5);
	insert(root,8);
	insert(root,14);
	insert(root,11);
	insert(root,16);
	
	preorder(root);
	cout<<'\n';
	inorder(root);
	cout<<'\n';
	postorder(root);

	return 0;
}
	
	
