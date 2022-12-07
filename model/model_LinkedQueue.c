#include <stdio.h>
#include <stdlib.h>

// Define Queue Node
typedef int element;
typedef struct QueueNode{
	element data;
	struct QueueNode *link;
} QueueNode;

// Define Linked Queue
typedef struct{
	QueueNode *front, *rear;
} LinkedQueueType;

// Define init()
void init(LinkedQueueType *q){
	q->front = q->rear = 0;
}

// Define is_empty()
int is_empty(LinkedQueueType *q){
	return q->front == NULL;
}

// Define is_full()
int is_full(LinkedQueueType *q){
	return 0;
}

// Define enqueue()
void enqueue(LinkedQueueType *q, element data){
	QueueNode *tmp = (QueueNode *)malloc(sizeof(QueueNode));
	tmp->data = data;
	tmp->link = NULL;
	
	if(is_empty(q)){
		q->front = tmp;
		q->rear = tmp;
	}
	else{
		q->rear->link = tmp;
		q->rear = tmp;
	}
}

// Define dequeue()
element dequeue(LinkedQueueType *q){
	QueueNode *tmp = q->front;
	element data;

	if(is_empty(q)){
		fprintf(stderr, "큐 비어있음");
		exit(1);
	}
	else{
		data = tmp->data;
		q->front = q->front->link;
		if(q->front == NULL) q->rear = NULL;
		free(tmp);
		return data;
	}
}

// Define print_queue()
void print_queue(LinkedQueueType *q){
	for(QueueNode *p=q->front; p!=NULL; p=p->link){
		printf("%d->", p->data);
	}
	printf("NULL\n");
}


// main
int main(){
	LinkedQueueType queue;
	init(&queue);

	for(int i=0; i<3; i++){
		enqueue(&queue, i+1);
		print_queue(&queue);
	}

	for(int i=0; i<3; i++){
		dequeue(&queue);
		print_queue(&queue);
	}
	return 0;
}

