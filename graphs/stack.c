#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void push(Stack* stack, int data){
	if(stack == NULL){
		printf("stack is not allocated!\n");
		return;
	}
	StackNode* new_node = malloc(sizeof(StackNode));
	if(new_node == NULL){
		printf("StackNode malloc() failed!\n");
		return;
	}
	
	new_node->data = data;
	
	if(stack->head == NULL){
		new_node->next = NULL;
		stack->head = new_node;
		return;
	}
	
	new_node->next = stack->head;
	stack->head = new_node;
	return;
}

int pop(Stack* stack){
	StackNode* temp = stack->head;
	if(temp == NULL){
		return -1;
	}
	StackNode* temp1 = temp->next;
	int data = temp->data;
	free(temp);
	stack->head = temp1;
	return data;
}

void printStack(Stack* stack){
	StackNode* temp = stack->head;
	while(temp!=NULL){
		printf("%d,", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}

bool isStackEmpty(Stack* stack){
	if(stack->head != NULL){
		return false;
	}
	return true;
}

int topStack(Stack* stack){
	if(stack->head == NULL){
		return -1;
	}
	return stack->head->data;
}

Stack* allocateStack(){
	Stack* mystack = malloc(sizeof(Stack));
	if(mystack == NULL){
		printf("allocate stack malloc() failed!\n");
		return NULL;
	}
	mystack->head = NULL;
	return mystack;
}

void destroyStack(Stack* stack){
	StackNode* temp = stack->head;
	while(temp != NULL){
		StackNode* next = temp->next;
		free(temp);
		temp = next;
	}
	free(stack);
	return;
}

/*int main(){*/
/*	Stack* mystack = allocateStack();*/
/*	if(mystack == NULL){*/
/*		printf("Failed to allocate stack!\n");*/
/*		return -1;*/
/*	}*/
/*	push(mystack, 1);*/
/*	push(mystack, 2);*/
/*	push(mystack, 3);*/
/*	printStack(mystack);*/
/*	printf("isStackEmpty():%d\n", isStackEmpty(mystack));*/
/*	printf("pop:%d\n", pop(mystack));*/
/*	printf("pop:%d\n", pop(mystack));*/
/*	printf("pop:%d\n", pop(mystack));*/
/*	printStack(mystack);*/
/*	printf("isStackEmpty():%d\n", isStackEmpty(mystack));*/
/*	destroyStack(mystack);*/
/*	return 0;*/
/*}*/
