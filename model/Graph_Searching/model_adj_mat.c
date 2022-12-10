#include <stdio.h>
#include <stdlib.h>
#include "model_Queue.h"
#define MAX_VERTICES 50
#define MAX_QUEUE_SIZE 10

// Define Graph Type
typedef struct GraphType{
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// Define init()
void init(GraphType *g){
	g->n = 0;

	for(int r=0; r<MAX_VERTICES; r++)
		for(int c=0; c<MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
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
void insert_edge(GraphType *g, int start, int end){
	if(start>=g->n || end>=g->n){
		fprintf(stderr, "정점 번호 오류");
		exit(1);
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

// Define print_adj_mat()
void print_adj_mat(GraphType *g){
	for(int i=0; i<g->n; i++){
		for(int j=0; j<g->n; j++) printf("%d ", g->adj_mat[i][j]);
		printf("\n");
	}
}

// Define dfs_mat()
int visited[MAX_VERTICES];
void dfs_mat(GraphType *g, int v){
	visited[v] = 1;

	printf("정점 %d -> ", v);
	for(int i=0; i<g->n; i++){
		if(!visited[i] && g->adj_mat[v][i]) dfs_mat(g, i);
	}
}

// Define bfs_mat()
void bfs_mat(GraphType *g, int v){
	QueueType q;
	init_queue(&q);

	visited[v] = 1;
	printf("%d 방문 -> ", v);
	enqueue(&q, v);
	while(!is_empty(&q)){
		v = dequeue(&q);
		for(int i=0; i<g->n; i++){
			if(!visited[i] && g->adj_mat[v][i]){
				visited[i] = 1;
				printf("%d 방문 -> ", i);
				enqueue(&q, i);
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
	print_adj_mat(g);

	printf("Depth First Search\n");
	dfs_mat(g, 0);
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
	print_adj_mat(g);


	printf("Breadth First Search\n");
	bfs_mat(g, 0);
	printf("\n");

	free(g);
	return 0;
}

