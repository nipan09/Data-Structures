#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
		public:
		int data;
		Node* next;
};

//BEGINNING
Node* insert_at_beginning(Node* head, int data){
	Node* node = new Node;
	node->data = data;
	node->next = head;
	head = node;
	return head;
}


//SPECIFIC POSITION
Node* insert_at(Node* head, int data, int post){
	Node* temp = head;			//temp ptr to store add of head
	Node* curr;
	
	//new node
	Node* node = new Node;	//ptr and mem declaration
	node->data = data;		
	
	int count=1;				//count 1 @ head
	while(count<post){
		curr = temp;
		temp=temp->next;
		count++;
	}
	
	node->next = temp;
	curr->next = node;
	
	return head;
}
	
	
//END
Node* insert_at_end(Node* head, int data){
	Node* node = new Node;   //declaring ptr and allocating address to it
	node->data = data; 
	node->next = nullptr;
	if(head==nullptr)			
		head = node;
	
	else{
		Node* temp = head;
		while(temp->next)
			temp = temp->next;
		temp->next = node;
	}
	return head;
}
	

int main(){
	Node* head; //a pointer
	head = new Node;  //memory allocation to ptr
	head = nullptr;   //null to ptr
	head = insert_at_end(head,1);
	head = insert_at_end(head,2);
	head = insert_at_end(head,3);
	head = insert_at_beginning(head,0);
	head = insert_at(head,4,2);
	
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	
	return 0;
}

