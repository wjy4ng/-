#include <stdio.h>
#include <stdlib.h>

// Define Polynomial ListNode
typedef struct ListNode{
	int coef;
	int expon;
	struct ListNode *link;
} ListNode;

// Define Linked List Header
typedef struct ListType{
	int size;
	ListNode *head;
	ListNode *tail;
} ListType;

// Define error()
void error(char *message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// Define create()
ListType* create(){
	ListType *p = (ListType *)malloc(sizeof(ListType));

	p->size = 0;
	p->head = p->tail = NULL;
}

// Define insert_last()
void insert_last(ListType *p, int coef, int expon){
	ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));

	if(tmp == NULL) error("overflow...");
	tmp->coef = coef;
	tmp->expon = expon;
	if(p->tail == NULL) p->head = p->tail = tmp;
	else{
		p->tail->link = tmp;
		p->tail = tmp;
	}
	p->size++;
}

// Define poly_add()
void poly_add(ListType *L1, ListType *L2, ListType *L3){
	ListNode *a = L1->head;
	ListNode *b = L2->head;
	int sum;

	while(a&&b){
		if(a->expon == b->expon){
			sum = a->coef + b->coef;
			if(sum!=0) insert_last(L3, sum, a->expon);
			a=a->link; b=b->link;
		}
		else if(a->expon > b->expon){
			insert_last(L3, a->coef, a->expon);
			a=a->link;
		}
		else{
			insert_last(L3, b->coef, b->expon);
			b=b->link;
		}
	}

	for(; a!=NULL; a=a->link) insert_last(L3, a->coef, a->expon);
	for(; b!=NULL; b=b->link) insert_last(L3, b->coef, b->expon);
}

// Define poly_print()
void poly_print(ListType *p){
	ListNode *tmp = p->head;
	printf("polynomial = ");
	for(;tmp; tmp = tmp->link) printf("%d^%d + ", tmp->coef, tmp->expon);
	printf("\n");
}



// main
int main(){
	ListType *L1, *L2, *L3;

	L1 = create();
	L2 = create();
	L3 = create();

	insert_last(L1, 3, 12);
	insert_last(L1, 2, 8);
	insert_last(L1, 1, 0);

	insert_last(L2, 8, 12);
	insert_last(L2, -3, 10);
	insert_last(L2, 10, 6);

	poly_print(L1);
	poly_print(L2);

	poly_add(L1, L2, L3);
	poly_print(L3);

	free(L1); free(L2); free(L3);
}

