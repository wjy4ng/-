#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

// set_init()
void set_init(int n){
	for(int i=0; i<n; i++) parent[i] = -1;
}

// set_find()
int set_find(int curr){
	if(parent[curr] == -1) return curr;
	while(parent[curr] != -1) curr = parent[curr];
	return curr;
}

// set_union()
void set_union(int a, int b){
	int root1 = set_find(a);
	int root2 = set_find(b);
	if(root1 != root2) parent[root1] = root2;
}

// struct Edge
struct Edge{
	int start, end, weight;
};

// GraphType
typedef struct GraphType{
	int n;
	struct Edge edges[2*MAX_VERTICES]; // 2배인 이유?
} GraphType;

// graph_init()
void graph_init(GraphType *g){
	g->n = 0;
	for(int i=0; i<2*MAX_VERTICES; i++){
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

// insert_edge()
void insert_edge(GraphType *g, int start, int end, int w){
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}

// compare()
int compare(const void* a, const void* b){
	struct Edge *x = (struct Edge*)a;
	struct Edge *y = (struct Edge*)b;
	return (x->weight - y->weight);
}

// kruskal()
void kruskal(GraphType *g){
	int edge_accepted=0;
	int sset, eset;
	struct Edge e;

	set_init(g->n);
	qsort(g->edges, g->n, sizeof(struct Edge), compare);

	printf("Kruskal Minimum Spanning Tree \n");
	int k=0;

	while(edge_accepted < (g->n - 1)){
		e = g->edges[k];
		sset = set_find(e.start);
		eset = set_find(e.end);
		if(sset != eset){
			printf("Select edge (%d, %d) %d\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(sset, eset);
		}
		k++;
	}
}



// main
int main(){
	GraphType *g = (GraphType *)malloc(sizeof(GraphType));
	graph_init(g);

	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);

	kruskal(g);
	free(g);
	return 0;
}

