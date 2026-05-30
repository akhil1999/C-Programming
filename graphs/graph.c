#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"graph.h"

struct mygraph{
	int numnodes;
	bool **edges;
};

graph* create_graph(int numnodes){
	graph* g = malloc(sizeof(graph));

	if(g == NULL){
		 return NULL;
	}
	
	g->numnodes = numnodes;
	g->edges = (bool **) calloc(g->numnodes, sizeof(bool*));
	
	if(g->edges == NULL){
		free(g);
		return NULL;
	}
	
	for(int i=0; i<numnodes; i++){
		g->edges[i] = (bool*) calloc(g->numnodes, sizeof(bool));
		if(g->edges[i] == NULL){
			destroy_graph(g);
			return NULL;
		}
	}
	
	return g;
}

void destroy_graph(graph* g){
	if(g->edges == NULL){
		return;
	}
	
	for(int i=0; i<g->numnodes; i++){
		if(g->edges[i] != NULL){
			free(g->edges[i]);
		}
	}
	free(g->edges);
	free(g);
}

void print_graph(graph* g){
	printf("graph{\n");
	for(int i=0; i<g->numnodes; i++){
		for(int j=0; j<g->numnodes; j++){
			if(g->edges[i][j] == 1){
				printf("%d--%d;\n", i,j);
			}
		}
	}
	printf("}\n");
}

bool add_edge(graph *g, unsigned int from_node, unsigned int to_node){
	if(has_edge(g, from_node, to_node)){
		return false;
	}
	g->edges[from_node][to_node] = true;
	return true;
}

bool has_edge(graph *g, unsigned int from_node, unsigned int to_node){
	return g->edges[from_node][to_node];
}

int main(){
	graph *g = create_graph(1024);
	for(int i=0; i<1024; i++){
		add_edge(g, 0, i);
	}
	print_graph(g);
	destroy_graph(g);
	return 0;
}
