#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"weighted_graph.h"

EdgeNode* addToEdgeList(EdgeNode* adjlist, unsigned int destination, unsigned int weight){
	EdgeNode* new_node = malloc(sizeof(EdgeNode));
	if(new_node == NULL){
		printf("edgenode malloc failed\n");
		return NULL;
	}
	if(adjlist == NULL){
		new_node->next = NULL;
		adjlist = new_node;
		new_node->destination = destination;
		new_node->weight = weight;
		return new_node;
	}
	new_node->next = adjlist;
	adjlist = new_node;
	new_node->destination = destination;
	new_node->weight = weight;
	return adjlist;
}

bool hasItem(EdgeNode* adjlist, unsigned int destination){
	while(adjlist!=NULL){
		if(adjlist->destination == destination){
			return true;
		}
		adjlist=adjlist->next;
	}
	return false;
}

bool hasEdge(WeightedGraph *graph, unsigned int source, unsigned int destination){
	if(hasItem(graph->adjlist[source], destination)){
		return true;
	}
	return false;
}

void addEdge(WeightedGraph* graph, unsigned int source, unsigned int destination, unsigned int weight){
/*	if(graph == NULL){*/
/*		printf("graph is NULL, please allocate it first\n");*/
/*		return;*/
/*	}*/
	
	if(hasEdge(graph, source, destination)){
		return;
	}else{
		graph->adjlist[source] = addToEdgeList(graph->adjlist[source], destination, weight);
	}
	return;
}

void destroyList(EdgeNode* adjlist){
	if(adjlist == NULL){
		return;
	}
	EdgeNode* temp;
	while(adjlist!=NULL){
		temp = adjlist->next;
		free(adjlist);
		adjlist = temp; 
	}
	return;
}

void destroyGraph(WeightedGraph* graph){
	if(graph == NULL){
		printf("Graph already NULL\\n");
		return;
	}
	for(unsigned int i=0; i<graph->numVertices; i++){
		destroyList(graph->adjlist[i]);
	}
	free(graph->adjlist);
	free(graph);
	return;
}

WeightedGraph* allocateGraph(unsigned int numVertices){
	WeightedGraph* mygraph = malloc(sizeof(WeightedGraph));
	if(mygraph == NULL){
		printf("graph malloc failed!\n");
		return NULL;
	}
	mygraph->numVertices = numVertices;
	mygraph->adjlist = calloc(numVertices, sizeof(EdgeNode*));
	return mygraph;
}

void printGraph(WeightedGraph* g){
	printf("graph{\n");
	EdgeNode* temp;
	for(int i=0; i<g->numVertices; i++){
		if(g->adjlist[i] !=NULL){
			temp = g->adjlist[i];
			while(temp!=NULL){
				printf("%d--%d [label=%d,weight=%d]\n", i, temp->destination, temp->weight, temp->weight);
				temp = temp->next;
			}
		}
	}
	printf("}\n");
}

/*int main(int argc, char* argv[]){*/
/*	WeightedGraph* g = allocateGraph(8);*/
/*	if(g == NULL){*/
/*		printf("graph not allocated\n");*/
/*		return -1;*/
/*	}*/
/*	addEdge(g, 1, 3, 3);*/
/*	addEdge(g, 1, 6, 2);*/
/*	addEdge(g, 3, 5, 1);*/
/*	addEdge(g, 3, 6, 2);*/
/*	addEdge(g, 3, 4, 4);*/
/*	addEdge(g, 6, 5, 3);*/
/*	addEdge(g, 6, 2, 6);*/
/*	addEdge(g, 6, 7, 5);*/
/*	addEdge(g, 4, 2, 1);*/
/*	addEdge(g, 7, 2, 2);*/
/*	addEdge(g, 5, 2, 2);*/
/*	printGraph(g);*/
/*	destroyGraph(g);*/
/*	return 0;*/
/*}*/
