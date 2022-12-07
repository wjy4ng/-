#include <stdio.h>
#include <stdlib.h>

// Define Singly Linked List
typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

// Define error()
void error(char *message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// Define insert()
ListNode* insert(ListNode *head, ListNode *pre, element value){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));

	p->data = value;
	p->link = pre->link;
	pre->link = p;

	return head;
}

// Define insert_first()
ListNode* insert_first(ListNode *head, element value){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));

	p->data = value;
	p->link = head;
	head = p;

	return head;
}

// Define delete()
ListNode* delete(ListNode *head, ListNode *pre){
	ListNode *removed;

	removed = pre->link;
	pre->link = removed->link;
	free(removed);

	return head;
}

// Define delete_first()
ListNode* delete_first(ListNode *head){
	ListNode *removed;

	if(head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);

	return head;
}

// Define get_entry()
element get_entry(ListNode *head, int index){
	ListNode *p = head;
	for(int i=0; i<index; i++){
		p = p->link;
	}
	return p->data;
}

// Define print_list()
void print_list(ListNode *head){
	for(ListNode *p=head; p!=NULL; p=p->link){
		printf("%d->", p->data);
	}
	printf("NULL\n");
}



// main
int main(){
	ListNode *head = NULL;

	for(int i=0; i<5; i++){
		head = insert_first(head, i);
		print_list(head);
	}
	printf("%d\n", get_entry(head, 4));
}

