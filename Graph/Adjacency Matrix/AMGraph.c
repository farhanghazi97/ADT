#include  <stdio.h>
#include  <stdbool.h>

#include  "AMGraph.h"
#include  "Queue.h"

int main(void) {

	int size;
	printf("\nEnter size of graph: ");
	scanf("%d" , &size);
	Graph my_graph = CreateGraph(size);
	DisplayGraph(my_graph);

	char ch;
	printf("\nPress H to bring up the graph interface\n");
	while((ch = getchar()) != 'E') {
		if (ch == 'I') {
			InsertEdge(my_graph);
		} else if (ch == 'S') {
			DisplayGraph(my_graph);
		} else if (ch == 'D') {
			RemoveEdge(my_graph);
		} else if (ch == 'H') {
			printf("\nWelcome to the graph interface\n");
			printf("------------------------------\n");
			printf("I = Insert an edge into the graph\n");
			printf("D = Delete an edge from the graph\n");
			printf("S = Display the entire graph\n");
			printf("H = Help interface\n");
			printf("E = Exit program\n");
			printf("------------------------------\n");
		}
	}
	FreeGraph(my_graph);	
}


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
	printf("\nTotal number of vertices : %d\n" , graph->nV);
	printf("Total number of edges : %d\n\n" , graph->nE);
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

bool Adjacent(Graph g , Vertex v , Vertex w) {

	if(g->edges[v][w] == 1) {
		return true;
	} else {
		return false;
	}

}

void BFSGraph (Graph graph) {

	Queue queue = CreateNode(10);
    queue = CreateQueue(queue  , 10);


}


