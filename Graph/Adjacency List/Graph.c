#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "Graph.h"
#include "Queue.h"
#include "Stack.h"

Graph newGraph (int size) {
	Graph new_graph = malloc(sizeof(GraphRep));
	assert(new_graph != NULL);
	new_graph->nV = size;
	new_graph->OutLinks   = malloc(size * sizeof(AdjList));
	new_graph->InLinks    = malloc(size * sizeof(AdjList));
	new_graph->VDataArray = malloc(size * sizeof(VList));
	for(int i = 0; i < size; i++) {
		new_graph->OutLinks[i] = NULL;
		new_graph->InLinks[i] = NULL;
		new_graph->VDataArray[i] = newVDataNode();
	}
	return new_graph;
}

AdjList newAdjNode (int vertex , int weight) {
	AdjList new_node = malloc(sizeof(AdjNode));
	assert(new_node != NULL);
	new_node->vertex = vertex;
	new_node->weight = weight;
	new_node->next = NULL;
}

VList newVDataNode(void) {
	VList new_node = malloc(sizeof(VertexData));
	assert(new_node != NULL);
	new_node->nIn = 0;
	new_node->nOut = 0;
	return new_node;
}

void InsertLink (Edge e , Graph g) {

	AdjList new_node_out = newAdjNode(e.dest , e.weight);
	new_node_out->next = g->OutLinks[e.src];
	g->OutLinks[e.src] = new_node_out;
	g->VDataArray[e.src]->nOut++;

	AdjList new_node_in = newAdjNode(e.src , e.weight);
	new_node_in->next = g->InLinks[e.dest];
	g->InLinks[e.dest] = new_node_in;
	g->VDataArray[e.dest]->nIn++;

}

void RemoveLink (Graph g , int src , int dest) {

	// INVALID INPUT DOES NOT ALTER LIST (NO OPERATION PERFOMED)
	AdjList curr_out = outListfromVertex (g , src);
	AdjList curr_in  = inListfromVertex  (g , dest);

	// UPDATE OUTLINKS
	if(curr_out != NULL) {
		if(NodeVertex(curr_out) == dest) {
			// REMOVE FROM HEAD
			AdjList temp = curr_out;
			g->OutLinks[src] = curr_out->next;
			free(temp);
			temp = NULL;
			g->VDataArray[src]->nOut--;
		} else {
			while(curr_out->next != NULL) {
				if(NodeVertex(curr_out->next) == dest) {
					if(curr_out->next->next == NULL) {
						// REMOVE FROM TAIL
						AdjList temp = curr_out->next;
						curr_out->next = NULL;
						free(temp);
						temp = NULL;
						break;
					} else {
						// REMOVE INBETWEEN HEAD AND TAIL
						AdjList temp = curr_out->next;
						curr_out->next = curr_out->next->next;
						free(temp);
						temp = NULL;
						g->VDataArray[src]->nOut--;
						break;
					}
				}
				curr_out = curr_out->next;
			}
			printf("\n");
		}
	}

	//UPDATE INLINKS
	if(curr_in != NULL) {
		if(NodeVertex(curr_in) == src) {
			// REMOVE FROM HEAD
			AdjList temp = curr_in;
			g->InLinks[dest] = curr_in->next;
			free(temp);
			temp = NULL;
			g->VDataArray[dest]->nIn;
		} else {
			while(curr_in->next != NULL) {
				if(NodeVertex(curr_in->next) == src) {
					if(curr_in->next->next == NULL) {
						AdjList temp = curr_in->next;
						curr_in->next = NULL;
						free(temp);
						temp = NULL;
						g->VDataArray[dest]->nIn--;
						break;
					} else {
						// REMOVE FROM INBETWEEN HEAD AND TAIL
						AdjList temp = curr_in->next;
						curr_in->next = curr_in->next->next;
						free(temp);
						temp = NULL;
						g->VDataArray[dest]->nIn--;
						break;
					}
				}
				curr_in = curr_in->next;
			}
			printf("\n");
		}
	}
}

void showGraph (Graph g) {
	for(int i = 0; i < g->nV; i++) {
		printf("DATA FOR VERTEX %d\n" , i);
		AdjList curr_out = outListfromVertex(g , i);
		if(curr_out != NULL) {
			printf("OutLinks: ");
			while(curr_out != NULL) {
				printf("%d -> %d (%d) " , i , curr_out->vertex , curr_out->weight);
				curr_out = curr_out->next;
			}
			printf("(Size : %d)\n" , nOutLinks(g->VDataArray[i]));
		}
		AdjList curr_in = inListfromVertex(g , i);
		if(curr_in != NULL) {
			printf("InLinks: ");
			while(curr_in != NULL) {
				printf("%d <- %d (%d) " , i , curr_in->vertex , curr_in->weight);
				curr_in = curr_in->next;
			}
			printf("(Size : %d)\n" , nInLinks(g->VDataArray[i]));
		}
		printf("\n");
	}
}

void freeGraph (Graph g) {
	for(int i = 0; i < g->nV; i++) {
		AdjList curr_out = g->OutLinks[i];
		while(curr_out != NULL) {
			AdjList temp = curr_out;
			free(temp);
			curr_out = curr_out->next;
		}
		AdjList curr_in = g->InLinks[i];
		while(curr_in != NULL) {
			AdjList temp = curr_in;
			free(temp);
			curr_in = curr_in->next;
		}
		VList curr = g->VDataArray[i];
		free(curr);
	}
	free(g->OutLinks);
	free(g->InLinks);
	free(g->VDataArray);
	free(g);
}

// Prints all vertices reachable from source
void BFS (Graph g , int source) {

	int * visited = calloc(g->nV , sizeof(int));
	Queue new_queue = newQueue();
	new_queue = Enqueue(new_queue , source , 0);
	visited[source] = 1;

	while(!QueueIsEmpty(new_queue)) {
		int vertex = Dequeue(new_queue);
		printf("%d | " , vertex);
		AdjList neighbours = outListfromVertex(g , vertex);
		while(neighbours != NULL) {
			if(visited[neighbours->vertex] == 0) {
				new_queue = Enqueue(new_queue , neighbours->vertex , neighbours->weight);
				visited[neighbours->vertex] = 1;
			}
			neighbours = neighbours->next;
		}
	}
	printf("\n");
	free(visited);
	FreeQueue(new_queue);
}

// Prints all vertices reachable from source
void DFS (Graph g , int source) {

	int * visited = calloc(g->nV , sizeof(int));
	Stack new_stack = newStack();
	new_stack = Push(new_stack , source);
	visited[source] = 1;

	while(!StackIsEmpty(new_stack)) {
		int vertex = Pop(new_stack);
		printf("%d | " , vertex);
		AdjList neighbours = outListfromVertex(g , vertex);
		while(neighbours != NULL) {
			if(visited[neighbours->vertex] == 0) {
				new_stack = Push(new_stack , neighbours->vertex);
				visited[neighbours->vertex] = 1;
			}
			neighbours = neighbours->next;
		}
	}
	printf("\n");
	free(visited);
	FreeStack(new_stack);
}


void Dijkstra(Graph g , int src) {

	int dist[g->nV];

	// INTILISE DIST ARRAY TO INF SINCE WE DONT KNOW ANY
	// SHORTEST DISTANCE
	for(int i = 0; i < g->nV; i++) {
		dist[i] = INT_MAX;
	}

	// INITIALISE PRIORITY QUEUE
	Queue new_queue = newQueue();

	// ENQUEUE SOURCE NODE
	new_queue = Enqueue(new_queue , src , 0);

	// DIST FROM SOURCE TO SOURCE IS 0
	dist[src] = 0;

	// WHILE QUEUE IS NOT EMPTY , SEARCH THROUGH GRAPH FROM SOURCE NODE AND
	// FIND SHORTEST PATH TO EVERY OTHER NODE (PROVIDED IT IS REACHABLE)
	while(!QueueIsEmpty(new_queue)) {
		int extracted_vertex = Dequeue(new_queue);
		AdjList curr = outListfromVertex(g , extracted_vertex);
		while(curr != NULL) {
			if(dist[curr->vertex] > dist[extracted_vertex] + curr->weight) {
				dist[curr->vertex] = dist[extracted_vertex] + curr->weight;
				new_queue = Enqueue(new_queue , curr->vertex , curr->weight);
			}
			curr = curr->next;
		}
	}

	// BY NOW , DIJKSTRA WOULD HAVE EVALUATED SHORTEST PATH TO REACHABLE NODES
	// MARK UNREACHABLE NODES WITH -1
	for(int i = 0; i < g->nV; i++) {
		if(dist[i] == INT_MAX) {
			dist[i] = -1;
		}
	}

	// PRINT SHORTEST DIST ARRAY
	printf("From source vertex %d\n" , src);
	for(int i = 0; i < g->nV; i++) {
		printf("shortest distance to %d = %d\n" , i , dist[i]);
	}
}

int NodeVertex(AdjList node) {
	return node->vertex;
}

int nOutLinks(VList node) {
	return node->nOut;
}

int nInLinks(VList node) {
	return node->nIn;
}

AdjList outListfromVertex (Graph g , int vertex) {
	return g->OutLinks[vertex];
}

AdjList inListfromVertex (Graph g , int vertex) {
	return g->InLinks[vertex];
}
