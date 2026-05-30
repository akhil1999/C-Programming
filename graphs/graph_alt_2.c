#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"list.h"
#include"queue.h"
#include"stack.h"

typedef struct mygraph graph;

struct mygraph{
	int numnodes;
	List** adjlist;
};

graph* create_graph(int numnodes){
	graph* g = calloc(1, sizeof(graph));
	
	if(g == NULL){
		return NULL;
	}
	
	g->numnodes = numnodes;
	g->adjlist = calloc(numnodes, sizeof(List*));
	
	if(g->adjlist == NULL){
		free(g);
		return NULL;
	}
	
	return g;
}

void destroy_graph(graph* g){
	if(g->adjlist == NULL){
		return;
	}
	
	for(int i=0; i<g->numnodes; i++){
		if(g->adjlist[i]!=NULL){
		destroyList(g->adjlist[i]);
		}
	}
	free(g->adjlist);
	free(g);
	return;
}

void print_graph(graph* g){
	printf("graph{\n");
	ListNode* temp;
	for(int i=0; i<g->numnodes; i++){
		if(g->adjlist[i] !=NULL){
		temp = g->adjlist[i]->head;
		while(temp!=NULL){
			printf("%d--%d\n", i, temp->data);
			temp = temp->next;
		}
		}
	}
	printf("}\n");
}

void add_edge(graph* g, unsigned int from_node, unsigned int to_node){
/*	g->adjlist[from_node] = insertNode(to_node, g->adjlist[from_node]);*/
	if(g->adjlist[from_node] == NULL){
		printf("allocating list..\n");
		g->adjlist[from_node] = allocateList();
	}
	addToList(g->adjlist[from_node], (int)to_node);
/*	g->adjlist[to_node] = insertNode(from_node, g->adjlist[to_node]);*/
	if(g->adjlist[to_node] == NULL){
		printf("allocating list..\n");
		g->adjlist[to_node] = allocateList();
	}
	addToList(g->adjlist[to_node], (int)from_node);
	return;
}

bool has_edge(graph* g, unsigned int from_node, unsigned int to_node){
	return hasItem(g->adjlist[from_node], to_node);
}

void graphBFS(graph* g, unsigned int data){
	//Breadth First Traversal of a Graph.
	//let's just print all the adjacency lists for now
	ListNode* temp;
/*	for(int i=0; i<g->numnodes; i++){*/
/*		temp = g->adjlist[i];*/
/*		while(temp!=NULL){*/
/*		printf("%d,", temp->data);*/
/*		temp = temp->next;*/
/*		}*/
/*		printf("\n");*/
/*	}*/
	
	printf("BFS\n");
	//we also need a visited marking array
	bool* visited = calloc(g->numnodes, sizeof(bool));
	Queue* q = allocateQueue();
	enqueue(q, data);
	int queue_front;
	while(!isEmpty(q)){
		queue_front = frontQueue(q);
		dequeue(q);
		if(visited[queue_front] == 0){
			printf("%d,", queue_front);
			visited[queue_front] = true;
		}
		temp = g->adjlist[queue_front]->head;
		while(temp != NULL){
			if(visited[temp->data] == 0){
				enqueue(q, temp->data);
			}
			temp = temp->next;
		}
	}
	printf("\n");
	destroyQueue(q);
	free(visited);
	return;
}

bool* visited;

void graphDFS(graph* g, unsigned int data){
	visited[data] = true;
	printf("%d,", data);
	ListNode* temp = g->adjlist[data]->head;
	while(temp!=NULL){
		if(!visited[temp->data]){
			graphDFS(g, temp->data);
		}
		temp = temp->next;
	}
	return;
}

void graphDFSIterative(graph* g, unsigned int data){
	Stack* stack = allocateStack();
	push(stack, (int)data);
	visited[data] = true;
	int temp_data;
	while(!isStackEmpty(stack)){
		temp_data = pop(stack);
		printf("%d,", temp_data);
		ListNode* temp = g->adjlist[temp_data]->head;
		while(temp!=NULL){
			if(!visited[temp->data]){
				push(stack, temp->data);
				visited[temp->data] = true;
			}
			temp = temp->next;
		}
	}
	destroyStack(stack);
	printf("\n");
	return;
}

int main(){
	graph *g = create_graph(9);
	add_edge(g, 1, 2);
	add_edge(g, 1, 3);
	add_edge(g, 2, 5);
	add_edge(g, 2, 6);
	add_edge(g, 3, 4);
	add_edge(g, 3, 7);
	add_edge(g, 4, 8);
	add_edge(g, 7, 8);
	
	print_graph(g);
	visited = calloc(g->numnodes, sizeof(bool));
	graphBFS(g, 1);
	graphDFS(g, 1);
	free(visited);
	visited = calloc(g->numnodes, sizeof(bool));
	printf("\n");
	graphDFSIterative(g, 1);
	free(visited);
	destroy_graph(g);
	return 0;
}
