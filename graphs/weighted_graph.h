#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

typedef struct EdgeNode{
	unsigned int destination;
	unsigned int weight;
	struct EdgeNode* next;
}EdgeNode;

typedef struct WeightedGraph{
	unsigned int numVertices;
	EdgeNode** adjlist;
}WeightedGraph;

WeightedGraph* allocateGraph(unsigned int numVertices);
void destroyGraph(WeightedGraph* graph);

void addEdge(WeightedGraph* graph, unsigned int source, unsigned int destination, unsigned int weight);
bool hasEdge(WeightedGraph *graph, unsigned int source, unsigned int destination);
void printGraph(WeightedGraph* graph);

#endif
