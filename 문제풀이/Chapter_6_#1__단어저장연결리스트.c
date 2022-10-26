#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 구조체
typedef struct{
	char name[100];
} element;

typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

// 노드 ADT 구현
ListNode* insert_first(ListNode *head, element value);
ListNode* insert(ListNode *head, ListNode *pre, element value);
ListNode* delete_first(ListNode *head);
ListNode* delete(ListNode *head, ListNode *pre);
void print_list(ListNode *head);
element get_entry(ListNode *head, int index);
int get_length(ListNode *head);



// 메인 함수
int main(){
	ListNode *head = NULL;
	element data;

	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);

	return 0;
}



ListNode* insert_first(ListNode *head, element value){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode *head, ListNode *pre, element value){
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode *head){
	ListNode *removed;
	if(head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode *head, ListNode *pre){
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode *head){
	for(ListNode *p=head; p!=NULL; p=p->link){
		printf("%s->", p->data.name);
	}
	printf("NULL\n");
}

element get_entry(ListNode *head, int index){
	ListNode *p;

	p = head;
	for(int i=0; i<index; i++, p=p->link){
		if(p==NULL) break;
	}
	return p->data;
}

int get_length(ListNode *head){
	ListNode *p;
	int count=0;

	p = head;
	while(p != NULL){
		count++;
		p = p->link;
	}
	return count;
}



