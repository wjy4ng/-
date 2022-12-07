#include <stdio.h>
#include <stdlib.h>

// Define Circular Linked List
typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

// Define print_list()
void print_list(ListNode *head){
	ListNode *p;

	if(head==NULL) return;
	p = head->link;
	do{
		printf("%d->", p->data);
		p = p->link;
	} while(p!=head);
	printf("%d->", p->data);
}

// Define insert_first()
ListNode* insert_first(ListNode *head, element data){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = data;

	if(head==NULL){
		head = p;
		p->link = head;
	}
	else{
		p->link = head->link;
		head->link = p;
	}
	return head;
}

// Define insert_last()
ListNode* insert_last(ListNode *head, element data){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = data;

	if(head==NULL){
		head = p;
		p->link = head;
	}
	else{
		p->link = head->link;
		head->link = p;
		head = p;
	}
	return head;
}



// main
int main(){
	ListNode *head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);

	print_list(head);
	return 0;
}

