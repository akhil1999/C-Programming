#include <stdio.h>
#include <stdlib.h>

struct node *top = NULL;

struct node{
	int data;
	struct node *next;
};

void printStack(struct node *top){
	while(top!=NULL){
		printf("%d, ", top->data);
		top = top->next;
	}
	printf("\n");
}


//push data onto top of the stack
struct node *Push(int data, struct node *top){
	struct node *new_node = (struct node*) malloc(sizeof(struct node));
	//assign data to the node anyways
	new_node->data = data;
	//if the stack is empty, allocate one node and return the ptr
	if(top==NULL){
		new_node->next = NULL;
		return new_node;
	}
	
	//second case is that the stack is not empty, need to create a link
	new_node->next = top;
	top = new_node;
	return top;
}

//pop data from top of the stack
struct node *Pop(){
	struct node *temp = top;
	top = top->next;
	free(temp);
	return top;
}

//print the data at the top of the stack
void Top(){
	printf("Top:%d\n",top->data);
}

void isEmpty(){
	if(top==NULL){
		printf("Stack is empty\n");
	}else{
		printf("Stack exists\n");
	}
}

void main(){
	isEmpty();
	top = Push(1, top);
	top = Push(2, top);
	top = Push(3, top);
	top = Push(9, top);
	printStack(top);
	top = Pop();
	printStack(top);
	Top();
	isEmpty();
}
