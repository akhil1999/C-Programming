#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int stack[50];

int top = -1;

int isEmpty(){
	if(top == -1){
	return 1;
	}else{
	return 0;
	}
}

void Push(int x){
	top++;
	stack[top] = x;
	return;
}

void Pop(){
	stack[top] = 0;
	top--;
	return;
}

int Top(){
	return stack[top];
}

void printStack(){
	if(top==-1){
		printf("stack empty bruh\n");
		return;
	}
	int i = 0;
	while(stack[i] != 0){
		printf("%d, ",stack[i]);
		i++;
	}
	printf("\n");
}

void main(){
	printf("isEmpty %d\n", isEmpty());
	Push(1);
	Push(2);
	Push(3);
	printStack();
	Pop();
	printStack();
	printf("Top:%d\n", Top());	
}
