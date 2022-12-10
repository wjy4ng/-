#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct{
	element data[MAX_QUEUE_SIZE];
	int rear;
	int front;
} QueueType;

void error(char *message);
void init_queue(QueueType *q);
int is_full(QueueType *q);
int is_empty(QueueType *q);
void enqueue(QueueType *q, int item);
element dequeue(QueueType *q);
element peek(QueueType *q);
void queue_print(QueueType *q);
void get_count(QueueType *q);

