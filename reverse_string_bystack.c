#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node *top = NULL;

struct node{
	char data;
	struct node *next;
};

void printStack(){
	struct node *temp = top;
	while(temp!=NULL){
		printf("%c, ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//push data onto top of the stack
struct node *Push(char data){
	printf("push called\n");
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
char Pop(){
	struct node *temp = top;
	top = top->next;
	char a = temp->data;
	free(temp);
	return a;
}

//print the data at the top of the stack
void Top(){
	printf("Top:%d\n",top->data);
}

bool isEmpty(){
	printf("isEmpty called\n");
	if(top==NULL){
		return true;
	}else{
		return false;
	}
}

void main(){
	//try and reverse a string
	char a[] = "burgir";
	int len = strlen(a);
	
	printf("len is %d\n", strlen(a));
	
	printf("%s\n", a);
	
	for(int i=0; a[i] != '\0'; i++){
		top = Push(a[i]);
	}
	printStack();	
	
	for(int i=0; i<len ; i++){
		a[i] = Pop();
	}
	
	int i = 0;
	while(!isEmpty){
		a[i] = Pop();
	}	
	
	printf("string reversed is %s", a);
}

