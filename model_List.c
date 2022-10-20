#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct{
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

void init(ArrayListType *list);
void error(char *message);
void insert(ArrayListType *L, int pos, element item);
void insert_last(ArrayListType *L, element item);
void insert_first(ArrayListType *L, element item);
element delete(ArrayListType *L, int pos);
void clear(ArrayListType *L);
element get_entry(ArrayListType *L, int pos);
int get_length(ArrayListType *L);
int is_empty(ArrayListType *L);
int is_full(ArrayListType *L);
void print_list(ArrayListType *L);



int main(){
	ArrayListType list;

	init(&list);
	for(int i=0; i<5; i++){
		insert(&list, 0, i);
		print_list(&list);
	}

	return 0;
}






void init(ArrayListType *L){
	L->size = 0;
}

void error(char *message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void insert(ArrayListType *L, int pos, element item){
	if(!is_full(L) && (pos >= 0) && (pos <= L->size)){
		for(int i=(L->size-1); i>=pos; i--){
			L->array[i+1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

void insert_last(ArrayListType *L, element item){
	if(L->size >= MAX_LIST_SIZE) error("리스트 오버플로우");
	L->array[L->size++] = item;
}

void insert_first(ArrayListType *L, element item){
	for(int i=(L->size-1); i>=0; i--){
		L->array[i+1] = L->array[i];
	}
	L->array[0] = item;
	L->size++;
}

element delete(ArrayListType *L, int pos){
	element item;

	item = L->array[pos];
	for(int i=pos; i<(L->size-1); i++){
		L->array[i] = L->array[i+1];
	}
	L->size--;
	return item;
}

void clear(ArrayListType *L){
	L->size = 0;
}

element get_entry(ArrayListType *L, int pos){
	return L->array[pos];
}

int get_length(ArrayListType *L){
	return L->size;
}

int is_empty(ArrayListType *L){
	return L->size == 0;
}

int is_full(ArrayListType *L){
	return L->size == MAX_LIST_SIZE;
}

void print_list(ArrayListType *L){
	for(int i=0; i<L->size; i++){
		printf("%d->", L->array[i]);
	}
	printf("\n");
}


