// Print the reverse of the linked list without actually reversing it


#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
};

void reverse(Node* head){
	if(head==nullptr)
		return;
	reverse(head->next);
	
	cout<<head->data<<" ";
}
	

int main(){
	Node* head = new Node;
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
	
	reverse(head);
	
	return 0;
}
