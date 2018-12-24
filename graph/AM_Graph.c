#include  <stdio.h>
#include "AM_Graph.h"

int main(void) {

	int size;
	printf("Enter size of graph: ");
	scanf("%d" , &size);
	Graph my_graph = CreateGraph(size);
	DisplayGraph(my_graph);

	char ch;
	while((ch = getchar()) != 'E') {
		if (ch == 'I') {
			InsertEdge(my_graph);
		} else if (ch == 'S') {
			DisplayGraph(my_graph);
		} else if (ch == 'D') {
			RemoveEdge(my_graph);
		}
	}
	FreeGraph(my_graph);
	
}
