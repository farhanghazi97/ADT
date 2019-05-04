#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
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

PNode newPredNode(int vertex) {
	PNode newPNode = malloc(sizeof(PredNode));
	newPNode->vertex = vertex;
	newPNode->next = NULL;
	return newPNode;
}

SPDataArray	newSPDNode (int vertices) {
	SPDataArray newSPNode = malloc(sizeof(SPDataArray));
	newSPNode->vertices = vertices;
	newSPNode->dist_array = malloc(vertices * sizeof(int));
	newSPNode->pred_array = malloc(vertices * sizeof(PredNode));
	for(int i = 0; i < vertices; i++) {
		newSPNode->dist_array[i] = INT_MAX;
		newSPNode->pred_array[i] = NULL;
	}
	return newSPNode;
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

void FreeSPDataArray (SPDataArray SPNode) {
	free(SPNode->dist_array);
	for(int i = 0; i < SPNode->vertices; i++) {
		PNode curr = SPNode->pred_array[i];
		while(curr != NULL) {
			PNode temp = curr;
			free(temp);
			curr = curr->next;
		}
	}
	free(SPNode->pred_array);
	free(SPNode);
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
		AdjList curr = outListfromVertex(g , vertex);
		while(curr != NULL) {
			if(visited[curr->vertex] == 0) {
				visited[curr->vertex] = 1;
				new_queue = Enqueue(new_queue , curr->vertex , curr->weight);
			}
			curr = curr->next;
		}
	}
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
		AdjList curr = outListfromVertex(g , vertex);
		while(curr != NULL) {
			if(visited[curr->vertex] == 0) {
				new_stack = Push(new_stack , curr->vertex);
				visited[curr->vertex] = 1;
			}
			curr = curr->next;
		}
	}
}

bool isCyclicAux (Graph g , int vertex , int * visited , int * stack) {
	if(visited[vertex] == 0) {
		visited[vertex] = 1;
		stack[vertex] = 1;
		AdjList curr = outListfromVertex(g , vertex);
		while(curr != NULL) {
			if(!visited[curr->vertex] && isCyclicAux(g , curr->vertex , visited, stack)) {
				return true;
			} else if(stack[curr->vertex] == 1){
				return true;
			}
			curr = curr->next;
		}
	}
	stack[vertex] = 0;
	return false;
}

bool isCyclic (Graph g) {
	int * visited = calloc(g->nV , sizeof(int));
	int * stack   = calloc(g->nV , sizeof(int));
	for(int i = 0; i < g->nV; i++) {
		if(isCyclicAux(g , i , visited, stack)) {
			return true;
		}
	}
	return false;
}

bool Adjacent(Graph g , int src , int dest) {
	bool flag = false;
	AdjList curr = outListfromVertex(g , src);
	while(curr != NULL) {
		if(curr->vertex == dest) {
			flag = true;
			break;
		}
		curr = curr->next;
	}
	return flag;
}

bool isComplete(Graph g) {
	bool flag = true;
	for(int i = 0; i < g->nV; i++) {
		for(int j = 0; j < g->nV; j++) {
			if(i == j) continue;
			if(!Adjacent(g , i , j)) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}

// Evaluates shortest path to every reachable vertex from source vertex
void Dijkstra(Graph g , int src) {

	// INITIALISE SPDISTARRAY
	SPDataArray newSP = newSPDNode(g->nV);

	// INITIALISE PRIORITY QUEUE
	Queue new_queue = newQueue();

	// ENQUEUE SOURCE NODE
	new_queue = Enqueue(new_queue , src , 0);

	// DIST FROM SOURCE TO SOURCE IS 0
	newSP->dist_array[src] = 0;

	// WHILE QUEUE IS NOT EMPTY , SEARCH THROUGH GRAPH FROM SOURCE NODE AND
	// FIND SHORTEST PATH TO EVERY OTHER NODE (PROVIDED IT IS REACHABLE)
	while(!QueueIsEmpty(new_queue)) {
		int extracted_vertex = Dequeue(new_queue);
		AdjList curr = outListfromVertex(g , extracted_vertex);
		while(curr != NULL) {
			if(newSP->dist_array[curr->vertex] >= newSP->dist_array[extracted_vertex] + curr->weight) {
				if(newSP->pred_array[curr->vertex] == NULL) {
					newSP->pred_array[curr->vertex] = newPredNode(extracted_vertex);
				} else {
					PNode pred_curr = newSP->pred_array[curr->vertex];
					while(pred_curr->next != NULL) {
						pred_curr = pred_curr->next;
					}
					pred_curr->next = newPredNode(extracted_vertex);
				}
				newSP->dist_array[curr->vertex] = newSP->dist_array[extracted_vertex] + curr->weight;
				new_queue = Enqueue(new_queue , curr->vertex , curr->weight);
			}
			curr = curr->next;
		}
	}

	// BY NOW , DIJKSTRA WOULD HAVE EVALUATED SHORTEST PATH TO REACHABLE NODES
	// MARK UNREACHABLE NODES WITH -1
	for(int i = 0; i < g->nV; i++) {
		if(newSP->dist_array[i] == INT_MAX) {
			newSP->dist_array[i] = -1;
		}
	}

	// PRINT SHORTEST DIST ARRAY
	printf("From source vertex %d\n" , src);
	for(int i = 0; i < g->nV; i++) {
		printf("shortest distance to %d = %d\n" , i , newSP->dist_array[i]);
		if(newSP->dist_array[i] != -1) {
			if(newSP->pred_array[i] != NULL && newSP->pred_array[i]->vertex != src) {
				printf("[%d] -> " , src);
			}
			PNode curr = newSP->pred_array[i];
			while(curr != NULL) {
				printf("[%d] -> " , curr->vertex);
				curr = curr->next;
			}
			printf("[%d]\n" , i);
		}
	}

	FreeQueue(new_queue);
	FreeSPDataArray(newSP);
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
