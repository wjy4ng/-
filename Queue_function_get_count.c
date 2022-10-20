#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct{
	element data[MAX_QUEUE_SIZE];
	int rear;
	int front;
} QueueType;


void init_queue(QueueType *q);
int is_full(QueueType *q);
int is_empty(QueueType *q);
void enqueue(QueueType *q, int item);
element dequeue(QueueType *q);
element peek(QueueType *q);
void error(char *message);
void queue_print(QueueType *q);
void get_count(QueueType *q);

int main(){
	QueueType q;
	init_queue(&q);

	for(int i=0; i<3; i++){
		enqueue(&q, i);
		queue_print(&q);
		get_count(&q);
	}

	for(int i=0; i<3; i++){
		dequeue(&q);
		queue_print(&q);
		get_count(&q);
	}
}


void error(char *message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q){
	q->rear = q->front = 0;
}

int is_full(QueueType *q){
	return ((q->rear+1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(QueueType *q){
	return ((q->rear) == (q->front));
}

void enqueue(QueueType *q, int item){
	if(is_full(q)) error("큐 포화상태!");
	q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
	q->data[(q->rear)] = item;
}

element dequeue(QueueType *q){
	if(is_empty(q)) error("큐 공백상태!");
	q->front = (q->front+1) % MAX_QUEUE_SIZE;
	return q->data[(q->front)];
}

element peek(QueueType *q){
	if(is_empty(q)) error("큐 공백상태!");
	return q->data[(q->front+1) % MAX_QUEUE_SIZE];
}

void queue_print(QueueType *q){
	printf("QUEUE(rear=%d, front=%d) = ", q->rear, q->front);
	if(!is_empty(q)){
		int i=q->front;
		do{
			i = (i+1) % MAX_QUEUE_SIZE;
			printf("%d | ", i);
			if(i == q->rear) break;
		} while(i != q->front);
	}
	printf("\n");
}

void get_count(QueueType *q){
	printf("큐 요소의 개수 : %d\n", (q->rear - q->front));
}

