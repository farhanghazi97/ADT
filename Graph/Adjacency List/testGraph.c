#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Graph.h"
#include "Queue.h"

#define MAX_NODES 10

int main(void) {

	Graph new_graph = newGraph(MAX_NODES);

	char flag = 'N';

	Edge e;
	printf("Enter 'Y' to add connection\n");
	while((flag = getchar()) != 'N') {
		printf("\n");
		if(flag == 'Y') {
			printf("Enter source vertex: ");
			scanf("%d" , &e.src);
			printf("Enter destination vertex: ");
			scanf("%d" , &e.dest);
			printf("Enter weight between vertices: ");
			scanf("%d" , &e.weight);
			InsertLink(e , new_graph);
			printf("\nEnter 'Y' to add connection. Enter 'N' to stop\n");
		}
	}
	showGraph(new_graph);

	BFS(new_graph , 0);

	DFS(new_graph , 0);



	/*printf("\n----- TEST DELETE FUNCTION -----\n\n");

	int cont = 1;
	int src = 0;
	int dest = 0;

	while(cont != -1) {

		printf("\nEnter source vertex: ");
		scanf("%d" , &src);
		printf("Enter destination vertex: ");
		scanf("%d" , &dest);

		RemoveLink(new_graph , src , dest);
		showGraph(new_graph);

		printf("\nContinue removing?\n");
		scanf("%d" , &cont);
	}*/

	freeGraph(new_graph);
}
