#include <stdio.h>
#include <stdlib.h>
#include "model_Queue.h"
#define MAX_VERTICES 50
#define MAX_QUEUE_SIZE 10

// Define Graph Node
typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
} GraphNode;

// Define Graph Type
typedef struct GraphType{
	int n;
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;

// Define init()
void init(GraphType *g){
	g->n = 0;

	for(int v=0; v<MAX_VERTICES; v++) g->adj_list[v] = NULL;
}

// Define insert_vertex()
void insert_vertex(GraphType *g, int v){
	if((g->n + 1) > MAX_VERTICES){
		fprintf(stderr, "정점 번호 오류");
		exit(1);
	}
	g->n++;
}

// Define insert_edge()
void insert_edge(GraphType *g, int u, int v){
	GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

// Define print_adj_list()
void print_adj_list(GraphType *g){
	for(int i=0; i<g->n; i++){
		GraphNode *p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while(p){
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

// Define dfs_list()
int visited[MAX_VERTICES];
void dfs_list(GraphType *g, int v){
	visited[v] = 1;
	printf("정점 %d -> ", v);
	for(GraphNode *p=g->adj_list[v]; p; p=p->link){
		if(!visited[p->vertex]) dfs_list(g, p->vertex);
	}
}

// Define bfs_list()
void bfs_list(GraphType *g, int v){
	QueueType q;
	init_queue(&q);

	visited[v] = 1;
	printf("%d 방문 -> ", v);
	enqueue(&q, v);
	while(!is_empty(&q)){
		v = dequeue(&q);
		for(GraphNode *p=g->adj_list[v]; p; p=p->link){
			if(!visited[p->vertex]){
				visited[p->vertex] = 1;
				printf("%d 방문 -> ", p->vertex);
				enqueue(&q, p->vertex);
			}
		}
	}
}



// main
int main(){
	GraphType *g = (GraphType *)malloc(sizeof(GraphType));
	init(g);

	for(int i=0; i<4; i++) insert_vertex(g,i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_list(g);

	printf("Depth First Search\n");
	dfs_list(g, 0);
	printf("\n\n");

	free(g);
	for(int i=0; i<MAX_VERTICES; i++) visited[i] = 0;

	g = (GraphType *)malloc(sizeof(GraphType));
	init(g);

	for(int i=0; i<6; i++) insert_vertex(g,i);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);
	print_adj_list(g);


	printf("Breadth First Search\n");
	bfs_list(g, 0);
	printf("\n");

	free(g);
	return 0;
}

