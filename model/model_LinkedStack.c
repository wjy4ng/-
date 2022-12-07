#include <stdio.h>
#include <stdlib.h>

// Define Stack Node
typedef int element;
typedef struct StackNode{
	element data;
	struct StackNode *link;
} StackNode;

// Define Linked Stack
typedef struct{
	StackNode *top;
} LinkedStackType;

// Define init()
void init(LinkedStackType *s){
	s->top = NULL;
}

// Define is_empty()
int is_empty(LinkedStackType *s){
	return s->top == NULL;
}

// Define is_full()
int is_full(LinkedStackType *s){
	return 0;
}

// Define push()
void push(LinkedStackType *s, element data){
	StackNode *tmp = (StackNode *)malloc(sizeof(StackNode));
	tmp->data = data;

	tmp->link = s->top;
	s->top = tmp;
}

// Define pop()
element pop(LinkedStackType *s){
	if(is_empty(s)){
		fprintf(stderr, "스택이 비어있음");
		exit(1);
	}
	else{
		StackNode *tmp = s->top;
		element data = tmp->data;

		s->top = s->top->link;
		free(tmp);
		return data;
	}
}

// Define peek()
element peek(LinkedStackType *s){
	if(is_empty(s)){
		fprintf(stderr, "스택이 비어있음");
		exit(1);
	}
	else{
		return s->top->data;
	}
}

// Define print_stack()
void print_stack(LinkedStackType *s){
	for(StackNode *p=s->top; p!=NULL; p=p->link){
		printf("%d->", p->data);
	}
	printf("NULL\n");
}



// main
int main(){
	LinkedStackType s;
	init(&s);

	for(int i=0; i<3; i++){
		push(&s, i);
		print_stack(&s);
	}

	for(int i=0; i<3; i++){
		pop(&s);
		print_stack(&s);
	}
	return 0;
}

