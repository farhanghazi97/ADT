#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"

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