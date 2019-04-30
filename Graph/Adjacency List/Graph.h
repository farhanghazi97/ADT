#include <stdio.h>
#include <stdlib.h>

typedef struct AdjNode    * AdjList;
typedef struct GraphRep   * Graph;
typedef struct VertexData * VList;

typedef struct GraphRep {
	int nV;
	AdjList * OutLinks;
	AdjList * InLinks;
	VList   * VDataArray;
} GraphRep;

typedef struct AdjNode {
	int vertex;
	int weight;
	AdjList next;
} AdjNode;

typedef struct Edge {
	int src;
	int dest;
	int weight;
} Edge;

typedef struct VertexData {
	int nIn;
	int nOut;
} VertexData;

Graph   newGraph     	  (int size);
AdjList newAdjNode   	  (int vertex , int weight);
AdjList outListfromVertex (Graph g , int vertex);
AdjList inListfromVertex  (Graph g , int vertex);
VList 	newVDataNode 	  (void);

int  	NodeVertex 	 	  (AdjList node);
int     nOutLinks	 	  (VList node);
int 	nInLinks	 	  (VList node);
void    InsertLink  	  (Edge  e , Graph g);
void 	RemoveLink   	  (Graph g , int src , int dest);
void    BFS 			  (Graph g , int source);
void 	showGraph         (Graph g);
void 	freeGraph 	 	  (Graph g);
