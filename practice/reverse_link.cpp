#include <iostream>

using namespace std;

typedef struct S{
	int data;
	struct S *next;
}Node;

Node* newnode(int data);
Node* insert(Node* head, int data);
void show(Node* head);
Node* reverse(Node* head);

int main(){
	Node* head = NULL;

	for(int i=1; i<=9; i++){
		head = insert(head, i);
		//cout << head->data << ' ';
	}

	show(head);
	head = reverse(head);
	show(head);
	
}

Node* newnode(int data){
	Node* ptr = new Node();
	ptr->data = data;
	ptr->next = NULL;

	return ptr;
}

Node* insert(Node* head, int data){
	if(head == NULL)
		return newnode(data);

	head->next =  insert(head->next, data);

	return head;
}

void show(Node* head){
	if(head == NULL){
		cout << '\n';
		return;
	}
	cout << head->data << ' ';
	show(head->next);
}

Node* reverse(Node* head){
	Node* prev, *curr, *n_next;
	prev = NULL;
	curr = head;
	n_next;

	while(curr){
		n_next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n_next;		
	}

	return prev;
}
