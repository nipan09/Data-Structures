#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node* prev;
};

Node* old = nullptr;
Node* head = nullptr;
Node* curr = head;

//Node creation
void create(int data){
	Node* node = new Node;
	node->data = data;
	node->prev = nullptr;
	node->next = nullptr;
	
	if (head==nullptr){
		head = node;
		old = node;
	}
	else{
		node->prev = old;
		old->next = node;
		old = node;
	}
}

//DELETE_BEGIN
void delete_begin(){
	head = head->next;
	head->prev = nullptr;
}
	
//DELETE_POST
void delete_post(int post){
	int count = 1;
	Node* temp = head;
	Node* curr = temp->next;
	
	while(count<(post-1)){
		temp = temp->next;
		curr = temp->next;
		count++;
	}
	curr = curr->next;
	temp->next = curr;
	curr->prev = temp;
}	

//DELETE_END
void delete_end(){
	Node* temp = head;
	while(temp->next->next)
		temp = temp->next;
	temp->next = nullptr;
}
	
//DISPLAY
void display(){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
}		


int main(){
	for(int i=0; i<5; i++)
		create(i);
	delete_begin();
	delete_post(3);
	delete_end();
	display();
	return 0;
}
	
