#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
};

Node* top = nullptr;

//node creation
Node* create(int data){
	Node* node = new Node;	//declaring ptr and allocating memory to it
	node->data = data;		//same as (*node).data()
	node->next = top;
	
	return node;
}

//PUSH
void push(int data){
	Node* node = create(data);
	top = node;
}

//POP
void pop(){
	top = top->next;
}

void display(){
	Node* head = top;
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
}

int main(){
	push(2);
	push(3);
	push(4);
	pop();
	display();
	return 0;
}
