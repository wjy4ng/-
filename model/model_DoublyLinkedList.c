#include <stdio.h>
#include <stdlib.h>

// Define Doubly Linked List
typedef int element;
typedef struct DListNode{
	element data;
	struct DListNode *llink;
	struct DListNode *rlink;
} DListNode;

// Define init()
void init(DListNode *head){
	head->llink = head;
	head->rlink = head;
}

// Define dinsert()
void dinsert(DListNode *head, element data){
	DListNode *p = (DListNode *)malloc(sizeof(DListNode));
	p->data = data;
	p->llink = head;
	p->rlink = head->rlink;
	head->rlink->llink = p;
	head->rlink = p;
}

// Define ddelete()
void ddelete(DListNode *head, DListNode *removed){
	if(removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

// Define print_dlist()
void print_dlist(DListNode *head){
	for(DListNode *p = head->rlink; p!=head; p=p->rlink){
		printf("<-| %d |->", p->data);
	}
	printf("\n");
}



// main
int main(){
	DListNode *head = (DListNode *)malloc(sizeof(DListNode));
	init(head);

	for(int i=0; i<5; i++){
		dinsert(head, i);
		print_dlist(head);
	}

	for(int i=0; i<5; i++){
		ddelete(head, head->rlink);
		print_dlist(head);
	}

	free(head);
	return 0;
}

