#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

// Define Heap Type
typedef struct{
	int key;
} element;
typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// Define create()
HeapType* create(){
	return (HeapType *)malloc(sizeof(HeapType));
}

// Define init()
void init(HeapType *h){
	h->heap_size = 0;
}

// Define insert_max_heap()
void insert_max_heap(HeapType *h, element item){
	int i = ++(h->heap_size);

	while(i!=1 && item.key > h->heap[i/2].key){
		h->heap[i] = h->heap[i/2];
		i /= 2;
	}
	h->heap[i] = item;
}

// Define delete_max_heap()
element delete_max_heap(HeapType *h){
	int parent=1, child=2;
	element item = h->heap[1];
	element tmp = h->heap[(h->heap_size)--];

	while(child <= h->heap_size){
		if((child<h->heap_size) && (h->heap[child].key < h->heap[child+1].key)) child++;
		if(tmp.key >= h->heap[child].key) break;
		
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;	
	}
	h->heap[parent] = tmp;
	return item;
}

// Define heap_sort()
void heap_sort(element a[], int n){
	HeapType *h = create();
	init(h);

	for(int i=0; i<n; i++) insert_max_heap(h, a[i]);
	for(int i=n-1; i>=0; i--) a[i] = delete_max_heap(h);
	free(h);
}

// main
int main(){
	element e1={10}, e2={5}, e3={30};
	element e4, e5, e6;
	HeapType *heap;

	heap = create();
	init(heap);

	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	e4 = delete_max_heap(heap);
	printf("<%d> ", e4.key);

	e5 = delete_max_heap(heap);
	printf("<%d> ", e5.key);

	e6 = delete_max_heap(heap);
	printf("<%d>\n", e6.key);

	free(heap);
	/********************************/
	#define SIZE 8

	element list[SIZE] = {23, 56, 11, 9, 56, 99, 27, 34};
	heap_sort(list, SIZE);
	for(int i=0; i<SIZE; i++) printf("%d ", list[i].key);
	printf("\n");

	return 0;
}

