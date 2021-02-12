#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* right;
	Node* left;
	int ht;   // store height.
};

Node* create(int data){
	Node* node = new Node;
	node->data = data;
	node->right = nullptr;
	node->left = nullptr;
	node->ht = 1;
	
	return node;
}

int height(Node* root);
int getBalance(Node* root);
Node* rightRotate(Node* root);
Node* leftRotate(Node* root);

Node* insert(Node* node, int key){
	if(node==NULL) return create(key);
	
	if(key < node->data) node->left = insert(node->left, key);
	else if(key > node->data) node->right = insert(node->right, key);
	else return node;    //equal keys are not allowed in BST
	
	node->ht = 1+max(height(node->left), height(node->right));
	
	int balance = getBalance(node);
	
	if(balance > 1 and key < node->left->data) return rightRotate(node);  //left left case
	if(balance < -1 and key > node->right->data) return leftRotate(node); //right right case
	
	if(balance > 1 and key > node->left->data){     //Left Right case
		node->left = leftRotate(node->left);
		return rightRotate(node);  
	}
	
	if(balance < -1 and key < node->right->data){   //Right Left case
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

void preOrder(Node* root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
	
int main(){
	Node* root = NULL;
	 root = insert(root, 10);
	 root = insert(root, 20);
	 root = insert(root, 30);
	 root = insert(root, 40);
	 root = insert(root, 50);
	 root = insert(root, 25);
	 
/* The constructed AVL Tree would be 
             30 
            / \ 
           20  40 
          / \   \ 
         10 25   50 
    */
	 
	 preOrder(root);
}

int height(Node* node){
	if(node==NULL) return 0;
	return node->ht;
}

int getBalance(Node* node){
	return (height(node->left) - height(node->right));
}

Node* rightRotate(Node* node){
/* The function has to do both Single Right (RL) and Right Right (LL).
 * So, node->left to temp.
 * Now, node->left has to take the values greater than the value or null.
 * temp->right has those values, so node->left points to temp->right.
 */
	Node* y = node->left;
	node->left = y->right;
	y->right = node;
	
	node->ht = 1 + max(height(node->left), height(node->right));
	y->ht = 1 + max(height(y->left), height(y->right));
	
	return y;
}

Node* leftRotate(Node* node){
	Node* y = node->right;
	node->right = y->left;
	y->left = node;
	
	node->ht = 1 + max(height(node->right), height(node->left));
	y->ht = 1 + max(height(y->right), height(y->left));
	
	return y;
}
	
	
