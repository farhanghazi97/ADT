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
	int 	   vertices;
	int      * dist_array;
	PNode 	 * pred_array;
} ShortestPathData;

// ALLOCATORS
Graph   	newGraph     (int size);
AdjList 	newAdjNode   (int vertex , int weight);
VList 		newVDataNode (void);
SPDataArray	newSPDNode 	 (int vertices);
PNode 		newPredNode(int vertex);

// SEARCHING
void    BFS 			  (Graph g , int source);
void    DFS 			  (Graph g , int source);

// PATH FINDING
void 	Dijkstra		  (Graph g , int src);

// CYCLE DETECTION
bool	isCyclic		  (Graph g);
bool 	isCyclicAux		  (Graph g , int vertex , int * visited , int * stack);
bool 	isComplete		  (Graph g);

// MISCELLANEOUS HELPERS
AdjList outListfromVertex (Graph g , int vertex);
AdjList inListfromVertex  (Graph g , int vertex);
int  	NodeVertex 	 	  (AdjList node);
int     nOutLinks	 	  (VList node);
int 	nInLinks	 	  (VList node);
bool 	Adjacent		  (Graph g , int src , int dest);
void    InsertLink  	  (Edge  e , Graph g);
void 	RemoveLink   	  (Graph g , int src , int dest);

// DEALLOCATORS
void 	showGraph         (Graph g);
void 	freeGraph 	 	  (Graph g);
void 	FreeSPDataArray	  (SPDataArray SPNode);
