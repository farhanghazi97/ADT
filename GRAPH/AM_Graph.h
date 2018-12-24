#include <stdio.h>
#include <stdlib.h>

typedef int Vertex;

typedef struct GraphRep * Graph;

typedef struct GraphRep {
	Vertex nV;
	Vertex nE;
	int ** edges;
} GraphRep;

Graph CreateGraph (int size);
void DisplayGraph (Graph graph);
void InsertEdge (Graph graph);
void RemoveEdge (Graph graph);
void FreeGraph (Graph graph);

Graph CreateGraph (int size) {
	Graph new_graph = malloc(sizeof(Graph));
	new_graph->nV = size;
	new_graph->nE = 0;
	new_graph->edges = malloc(size * sizeof(int *));
	for(int i = 0; i < size; i++) {
		new_graph->edges[i] = calloc(size ,  sizeof(int));
	}
	return new_graph;
	
}

void DisplayGraph (Graph graph) {
	for(int i = 0; i < graph->nV; i++){
		for(int j = 0; j < graph->nV; j++){
			printf("%d " , graph->edges[i][j]);
		}
		printf("\n");
	}		
}

void InsertEdge (Graph graph) {

	int x , y;

	printf("Enter x co-ord : ");
	scanf("%d" , &x);

	printf("Enter y co-ord : ");
	scanf("%d" , &y);

	if(x <= graph->nV && y < graph->nV) {
		graph->edges[x][y] = 1;
		graph->edges[y][x] = 1;
		graph->nE++;
	} else {
		printf("Co-ords exceed graph size!\n");
	}
}

void RemoveEdge (Graph graph) {
	
	int x , y;

	printf("Enter x co-ord : ");
	scanf("%d" , &x);

	printf("Enter y co-ord : ");
	scanf("%d" , &y);

	if(x <= graph->nV && y <= graph->nV) {
		graph->edges[x][y] = 0;	
		graph->edges[y][x] = 0;
		graph->nE--;
	} else {
		printf("Co-ords exceed graph size\n"); 
	}
	
}

void FreeGraph (Graph graph) {

	for(int i = 0; i < graph->nV; i++) {
		free(graph->edges[i]);
	}	
	free(graph->edges);
	free(graph);
}
