#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

// Define Tree Node
typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
} TreeNode;

// Define Circular Queue
typedef TreeNode* element;
typedef struct{
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// Define error()
void error(char *message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// Define init_queue()
void init_queue(QueueType *q){
	q->front = q->rear = 0;
}

// Define is_empty()
int is_empty(QueueType *q){
	return q->front == q->rear;
}

// Define is_full()
int is_full(QueueType *q){
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// Define enqueue()
void enqueue(QueueType *q, element item){
	if(is_full(q)) error("포화 상태");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// Define dequeue()
element dequeue(QueueType *q){
	if(is_empty(q)) error("공백 상태");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// Define level_order()
void level_order(TreeNode *ptr){
	QueueType q;
	init_queue(&q);

	if(ptr==NULL) return;
	enqueue(&q, ptr);
	while(!is_empty(&q)){
		ptr = dequeue(&q);
		printf("[%d] ", ptr->data);
		if(ptr->left) enqueue(&q, ptr->left);
		if(ptr->right) enqueue(&q, ptr->right);
	}
}

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

// main
int main(){
	printf("레벨 순회 = ");
	level_order(root);
	printf("\n");
	return 0;
}

