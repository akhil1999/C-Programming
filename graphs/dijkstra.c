#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"weighted_graph.h"
#include<limits.h>
#include"priority_queue.h"

int dijkstra(WeightedGraph* g, int source, int destination){
	//distance array of int initially storing INF or here, INT_MAX!
	int* distance = malloc(sizeof(int) * (g->numVertices+1));
	for(int i=0;i<=g->numVertices; i++){
		distance[i] = INT_MAX;
	}
	
	//visited array of booleans
	bool* visited = calloc((g->numVertices+1), sizeof(bool));
	distance[source] = 0;
	
	//create a priority queue for storing the nodes and getting the minimum distanced neighbour.
	//on popping the minimum element in the pq will be returned as it is a min heap.
	PQ* pq = allocatePQ();
	push(pq, source, 0);
	while(!isPQEmpty(pq)){
		PQNode current = pop(pq);
		int vertex = current.vertex;
		if(visited[vertex]) continue;
		
		if(vertex == destination){
			printf("PQ");
			printPQ(pq);
			return distance[destination];
		}
		
		EdgeNode* edge = g->adjlist[vertex];
		
		while(edge!=NULL){
			int neighbour = edge->destination;
			int weight = edge->weight;
			
			int newDistance = distance[vertex] + weight;
			
			if(newDistance < distance[neighbour]){
				distance[neighbour] = newDistance;
				push(pq, neighbour, newDistance);
			}
			edge = edge->next;
		}
	}
}

int main(int argc, char* argv[]){
	WeightedGraph* g = allocateGraph(8);
	if(g == NULL){
		printf("graph not allocated\n");
		return -1;
	}
	addEdge(g, 1, 3, 3);
	addEdge(g, 1, 6, 2);
	addEdge(g, 3, 5, 1);
	addEdge(g, 3, 6, 2);
	addEdge(g, 3, 4, 4);
	addEdge(g, 6, 5, 3);
	addEdge(g, 6, 2, 6);
	addEdge(g, 6, 7, 5);
	addEdge(g, 4, 2, 1);
	addEdge(g, 7, 2, 2);
	addEdge(g, 5, 2, 2);
	printGraph(g);

	printf("min distance from %d to %d is %d\n", 1, 7, dijkstra(g, 1, 7));
	destroyGraph(g);
	return 0;
}
