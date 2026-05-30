#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*#include"graph.h"*/

typedef struct mygraph graph;

struct mygraph{
	int numnodes;
	struct ListNode** adjlist;
};

struct ListNode{
	int data;
	struct ListNode* next;
};

struct ListNode* insertNode(int data, struct ListNode* head){
	struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
	if(new_node == NULL){
		return head;
	}
	new_node->data = data;
	if(head == NULL){
		new_node->next = NULL;
		head = new_node;
		return head;
	}
	new_node->next = head;
	head = new_node;
	return head;
}

struct ListNode* deleteNode(struct ListNode* head){
	if(head == NULL){
		 return NULL;
	}
	struct ListNode* temp = head->next;
	free(head);
	return temp;
}

void printList(struct ListNode* head){
	while(head!=NULL){
		printf("%d,", head->data);
		head = head->next;
	}
	printf("\n");
	return;
}

bool hasItem(int data, struct ListNode* head){
	while(head!=NULL){
		if(data == head->data) return true;
		head = head->next;
	}
	return false;
}

graph* create_graph(int numnodes){
	graph* g = calloc(1, sizeof(graph));
	
	if(g == NULL){
		return NULL;
	}
	
	g->numnodes = numnodes;
	g->adjlist = (struct ListNode**) calloc(numnodes, sizeof(struct ListNode*));
	
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
	
	//clear individual lists and then clear the adjlist ptr as well
	for(int i=0; i<g->numnodes; i++){
		while(g->adjlist[i]!=NULL){
			g->adjlist[i] = deleteNode(g->adjlist[i]);
		}
	}
	free(g->adjlist);
	free(g);
	return;
}

void print_graph(graph* g){
	printf("graph{\n");
	struct ListNode* temp;
	for(int i=0; i<g->numnodes; i++){
		temp = g->adjlist[i];
		while(temp != NULL){
			printf("%d--%d\n", i, temp->data);
			temp = temp->next;
		}
	}
	printf("}\n");
}

void add_edge(graph *g, unsigned int from_node, unsigned int to_node){
	g->adjlist[from_node] = insertNode(to_node, g->adjlist[from_node]);
	return;
}

bool has_edge(graph *g, unsigned int from_node, unsigned int to_node){
	return hasItem(to_node, g->adjlist[from_node]);
}

int main(){
	graph *g = create_graph(1024);
	for(int i=0; i<1024; i++){
		add_edge(g, 0, i);
	}
	print_graph(g);
/*	printf("has_edge from %d to %d:%d\n", 0, 1, has_edge(g, 0, 7));*/
	destroy_graph(g);
	return 0;
}
