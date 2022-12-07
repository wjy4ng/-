#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

// Define ArrayList
typedef int element;
typedef struct{
	element array[MAX_LIST_SIZE];
	int size;
} ArrayListType;

// Define init()
void init(ArrayListType *L){
	L->size = 0;
}

// Define error()
void error(char *message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// Define is_empty()
int is_empty(ArrayListType *L){
	return L->size == 0;
}

// Define is_full()
int is_full(ArrayListType *L){
	return L->size == MAX_LIST_SIZE;
}

// Define insert()
void insert(ArrayListType *L, int pos, element item){
	if(!is_full(L) && (pos>=0) && (pos<=L->size)){
		for(int i=(L->size-1); i>=pos; i--){
			L->array[i+1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

// Define insert_first()
void insert_first(ArrayListType *L, element item){
	for(int i=(L->size-1); i>=0; i--){
		L->array[i+1] = L->array[i];
	}
	L->array[0] = item;
	L->size++;
}	

// Define insert_last()
void insert_last(ArrayListType *L, element item){
	if(L->size >= MAX_LIST_SIZE) error("List Overflow...");
	L->array[L->size++] = item;
}

// Define delete()
element delete(ArrayListType *L, int pos){
	element item;
	
	if(pos<0 || pos>=L->size) error("pos error...");
	item = L->array[pos];
	for(int i=pos; i<(L->size-1); i++){
		L->array[i] = L->array[i+1];
	}
	L->size--;
	return item;
}

// Define get_entry()
element get_entry(ArrayListType *L, int pos){
	if(pos<0 || pos>=MAX_LIST_SIZE) error("pos error...");
	return L->array[pos];
}

// Define get_length()
int get_length(ArrayListType *L){
	return L->size;
}

// Define print_list()
void print_list(ArrayListType *L){
	for(int i=0; i<L->size; i++) printf("%d, ", L->array[i]);
	printf("\n");
}

// main
int main(){
	ArrayListType L;
	
	init(&L);
	for(int i=0; i<5; i++) insert_last(&L, i);
	print_list(&L);

	printf("%d", get_length(&L));
}

