////////////////////////////////////////
// Fold a linked list
///////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
};

Node* create(int data){
	Node* node = new Node;
	node->data = data;
	node->next = nullptr;
	return node;
}

//REVERSE
void reverse(Node** head){
	Node* temp = *head;
	Node* curr;
	 while(temp->next){
		 curr = temp->next;
		 temp->next = curr->next;
		 curr->next = *head;
		 *head = curr;
	 }
}

//FOLD
void fold(Node* head){
	Node* slow = head;
	Node* fast = slow->next;
	
	while(fast and fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	
	Node* head2 = slow->next;
	slow->next = nullptr;
	
	reverse(&head2);
	
	Node* temp = create(-1);
	Node* curr = temp;
	while(head || head2){
		if(head){
			curr->next = head;
			curr = curr->next;
			head = head->next;
		}
		
		if(head2){
			curr->next = head2;
			curr = curr->next;
			head2 = head2->next;
		}
	}
	temp = temp->next;
	
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
	
	

int main(){
	Node* head = new Node;
	head->data = 0;
	head->next = nullptr;
	
	Node* temp = head;
	Node* node;
	
	for(int i=1; i<5; i++){
		node = create(i);
		temp->next = node;
		temp = temp->next;
	}
	
	fold(head);
	
	return 0;
}
	
