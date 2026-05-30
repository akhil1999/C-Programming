#ifndef STACK_H
#define STACK_H

#include<stdbool.h>

typedef struct StackNode{
	int data;
	struct StackNode* next;
} StackNode;

typedef struct Stack{
	struct StackNode* head;
} Stack;

Stack* allocateStack();
void destroyStack(Stack* stack);
void push(Stack* stack, int data);
int pop(Stack* stack);
void printStack(Stack* stack);
bool isStackEmpty(Stack* stack);
int topStack(Stack* stack);

#endif
