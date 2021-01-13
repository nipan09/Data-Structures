#include <bits/stdc++.h>
using namespace std;

class BST{
	public:
	int data;
	BST* right;
	BST* left;
};

BST* create(int data){
	BST* node = new BST;
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;
	
	return node;
}

// INSERT
BST* insert(BST* node, int data){
	if(node==nullptr) return create(data);
	
	/*
	 Since at null, node/bst node is created and resturned to "it's" root,
	 the corresponding direction of root (which was null earlier) is likned with that node. 
	*/
	
	if(data < node->data)
		node->left = insert(node->left, data);
	else if(data >= node->data)
		node->right = insert(node->right, data);
	
	return node;
}

// SEARCH
void search(BST* node, int key){
	if(!node) cout<<"Doesn't exist";
	
	else if(node->data == key) cout<<"Found";
	
	else if(node->data > key)
		search(node->left, key);
		
	else if(node->data < key)
		search(node->right, key);
}

BST* FindMin(BST* root);

// DELETE
BST* Delete(BST* root, int data){
	if(!root) return root;
	else if(data < root->data) root->left = Delete(root->left, data);
	else if(data > root->data) root->right = Delete(root->right, data);
	else{
		
		// Case 1: No child
		if(root->right==NULL and root->left==NULL){
			delete root;			// delete(in cpp)/free(in c) will de-allocate memory 
			root = NULL;		    // now root has its adrress, so set it as NULL
		}
		
		//case 2: One child
		else if(root->left==NULL){
			BST* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right==NULL){
			BST* temp = root;
			root = root->left;
			delete temp;
		}
		
		/*
		 case 3: Two children. 
		 Checking for right subtree min value as root should have max
		 from left and right subtree i.e. minimum from right subtree alone.
		*/
		
		else{
			BST* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
		return root;
}
			
int main(){
	BST* root = NULL;
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 50);
	root = insert(root, 40);
	root = insert(root, 60);
	
	root = Delete(root, 40);
	search(root, 40);
	
	return 0;
}

// Finding minimum from the subtree.
BST* FindMin(BST* root){
	BST* temp = root;
	while(temp and temp->left!=NULL)
		temp = temp->left;
	return temp;
}
	
