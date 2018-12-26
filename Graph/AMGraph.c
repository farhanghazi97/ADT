#include  <stdio.h>
#include "AMGraph.h"

int main(void) {

	int size;
	printf("Enter size of graph: ");
	scanf("%d" , &size);
	Graph my_graph = CreateGraph(size);
	DisplayGraph(my_graph);

	char ch;
	printf("Press H to bring up the graph interface\n");
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
