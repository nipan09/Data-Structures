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
Node* create(int data){
	Node* node = new Node;
	node->data = data;
	node->prev = nullptr;
	node->next = nullptr;
	
	return node;
}

//INSERT_END
void insert_end(int data){
	Node* node = create(data);
	if(head==nullptr){
		head = node;
		old = head;				//old is allocated with the address of head
	}
	else{
		node->prev = old;
		old->next = node;		//old node now stores the address of next address
		old = node;				//old is allocated the address of new node
	}
}


//INSERT_BEGIN
void insert_begin(int data){
	Node* node = create(data);
	node->next = head;
	head->prev = node;
	head = node;
}

//INSERT_POSITION	
void insert_post(int data, int post){
	Node* node = create(data);
	Node* temp = head;
	Node* curr = temp->next;

	int count = 1;
	while(count<(post-1)){
		temp = temp->next;
		curr = temp->next;
		count++;
	}
	node->next = curr;
	curr->prev = node;
	temp->next = node;
	node->prev = temp;
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
		insert_end(i);
	insert_begin(9);
	insert_post(8,3);
	insert_post(7,5);
	display();
	return 0;
}
		
		
	
