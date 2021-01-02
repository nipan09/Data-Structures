#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
	public:
	int data;
	Node* next;
};

void delete_at_end(Node* head){
	Node* temp = head;
	while(temp->next->next)
		 temp = temp->next;
	temp->next = nullptr;
}

Node* delete_head(Node* head){
	head=head->next;
	return head;
}

void delete_at_position(Node* head, int post){
	Node* temp = head;
	Node* curr=temp;
	
	int count = 1;
	while(count<post){
		curr = temp;
		temp = temp->next;
		count++;
	}
	curr = temp->next;
}
		
int main(){
	Node* head; //a pointer
	head = new Node;  //memory allocation to ptr
	head->data = 0;
	head->next = nullptr;
	Node* temp = head;
	
	for(int i=1; i<5; i++){
		Node* node = new Node;
		node->data = i;
		node->next = nullptr;
		temp->next = node;
		temp = temp->next;
	}
	
	delete_at_end(head);
	delete_at_position(head,1);
	head = delete_head(head);
	
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	return 0;
}
