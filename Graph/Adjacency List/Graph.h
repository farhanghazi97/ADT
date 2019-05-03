#include <stdio.h>
#include <stdlib.h>

typedef struct AdjNode    		* AdjList;
typedef struct GraphRep   		* Graph;
typedef struct VertexData 		* VList;
typedef struct ShortestPathData * SPDataArray;
typedef struct PredNode 		* PNode;

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

typedef struct PredNode {
	int vertex;
	PNode next;
} PredNode;

typedef struct ShortestPathData {
	int      * dist_array;
	PNode 	 * pred_array;
} ShortestPathData;

Graph   	newGraph     (int size);
AdjList 	newAdjNode   (int vertex , int weight);
VList 		newVDataNode (void);
SPDataArray	newSPDNode 	 (int vertices);
PNode 		newPredNode(int vertex);

void    BFS 			  (Graph g , int source);
void    DFS 			  (Graph g , int source);
void 	Dijkstra		  (Graph g , int src);

AdjList outListfromVertex (Graph g , int vertex);
AdjList inListfromVertex  (Graph g , int vertex);
int  	NodeVertex 	 	  (AdjList node);
int     nOutLinks	 	  (VList node);
int 	nInLinks	 	  (VList node);
void    InsertLink  	  (Edge  e , Graph g);
void 	RemoveLink   	  (Graph g , int src , int dest);
void 	showGraph         (Graph g);
void 	freeGraph 	 	  (Graph g);
void 	FreeSPDataArray	  (SPDataArray SPNode);
