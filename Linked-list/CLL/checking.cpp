// checking for circular linked list

#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
};

Node* head = nullptr;

Node* create(int data){
	Node* node = new Node;
	node->data = data;
	node->next = nullptr;
	
	return node;
}

void insert_end(int data){
	Node* node = create(data);
	if(head==nullptr)
		head = node;
	else{
		Node* temp = node;
		while(temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

bool check(){
	Node* temp = head->next;
	while(temp!=nullptr and temp!=head)
		temp = temp->next;
	if(temp==head)
		return true;
	else
		return false;
}
	
	
int main(){
	for(int i=0; i<5; i++)
		insert_end(i);
	Node* temp = head;
	
	//joining end node and head to form circular linked list.
	while(temp->next)
		temp=temp->next;
	temp->next = head;
	
	bool res = check();
	cout<<res;
	return 0;
}
	
	
	
