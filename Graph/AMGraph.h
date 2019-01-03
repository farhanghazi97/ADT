#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Vertex;

typedef struct GraphRep * Graph;

typedef struct GraphRep {
	Vertex nV;
	Vertex nE;
	int ** edges;
} GraphRep;

Graph CreateGraph  (int size);
 void DisplayGraph (Graph graph);
 void InsertEdge   (Graph graph);
 void RemoveEdge   (Graph graph);
 void FreeGraph    (Graph graph);
 bool Adjacent     (Graph g , Vertex v , Vertex w);