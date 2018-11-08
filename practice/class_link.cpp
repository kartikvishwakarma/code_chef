/*
	2 -> 4 -> 3
	5 -> 6 -> 4
*/

#include <iostream>

using namespace std; 

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

 void insert(ListNode& head, int data);
 void show(ListNode& head);

 int main(){
 	ListNode head1 = ListNode(2);

 	insert(head1, 4);
 	insert(head1, 3);

 	ListNode head2 = ListNode(5);
 	insert(head2, 6);
 	insert(head2, 4);


 	cout << head1.val << ' ' << head1.next<< ' ' << head1.next.next << '\n';
 	//show(head1);
 }

 void insert(ListNode &head1, int data){
 	ListNode ptr = head1;
 	while(ptr.next){
 		//cout << ptr->val << " --> ";
 		ptr = ptr.next;
 	}

 	ListNode tmp = ListNode(data);
 	ptr.next = &tmp;
 }

 void show(ListNode& head){
 	ListNode *tmp = &head;

 	while(tmp->next){
 		cout << tmp->val << ' ';
 		tmp = tmp->next;
 	}
 }