#include <iostream>

using namespace std;

typedef struct Node{
	int data;
	struct Node* next;
}node;

node* newnode(int data){
	node* ptr = new node;
	ptr->data = data;
	ptr->next = NULL;

	return ptr;
}

node* insert(node* head, int data){
	if(head == NULL)
		return newnode(data);
	node* tmp = head;

	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = newnode(data);

	return head;
}

void disp(node* head){
	node* tmp = head;

	while(tmp != NULL){
		cout<<tmp->data<<"->";
		tmp = tmp->next;
	}
	cout<<"NULL\n";
}

void rec_reverse(node** head){
	node* curr, *Next;

	curr = *head;
	Next = curr->next;

	if(curr == NULL)
		return;

	if(Next == NULL)
		return;

	rec_reverse(&Next);
	curr->next->next = curr;
	curr->next = NULL;

	*head = Next;
}

node* reverse(node* head){
	node *curr, *prev, *Next;

	curr = head;
	prev = NULL;

	while(curr != NULL){
		Next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = Next;
	}

	head = prev;

	return head;
}

int main(){
	int t,n,d;
	cin>>t;

	while(t--){
		cin>>n;
		node* head = NULL;
		cin>>d;
		head = insert(head, d);
		for(int i=1; i<n; i++){
			cin>>d;
			insert(head, d);
		}

		disp(head);
		head = reverse(head);
		disp(head);
	}
}