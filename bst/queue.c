#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <stdbool.h>

struct node* head = NULL;

void enqueue(struct bstNode* bstNodePtr){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	struct node* temp1 = head;
	temp->bstNodePtr = bstNodePtr;
	
	if(bstNodePtr==NULL){
		return;
	}

	if(head == NULL){
		head = temp;
		temp->link = NULL;
		return;
	}
	
	while(temp1->link!=NULL){
		temp1 = temp1->link;
	}

	temp->link = NULL;
	temp1->link = temp;
}

struct bstNode* dequeue(){
	struct bstNode* temp = head->bstNodePtr;
	struct node* temp1 = head;
	head = head->link;
	free(temp1);
	return temp;
}

void printQueue(){
	struct node* saved_head_ptr = head;
	while(head!=NULL){
		printf("%d,", head->bstNodePtr->data);
		head = head->link;
	}
	printf("\n");
	//restore head
	head = saved_head_ptr;
}

bool isQueueEmpty(){
	if(head == NULL){
		return true;
	}else{
		return false;
	}
}

/*void main(){*/
/*	struct bstNode* ptr = (struct bstNode*) malloc(sizeof(struct bstNode));*/
/*	*/
/*	struct bstNode* ptrLeft = (struct bstNode*) malloc(sizeof(struct bstNode));*/
/*	ptrLeft->data = 8;*/
/*	ptrLeft->left = NULL;*/
/*	ptrLeft->right = NULL;*/
/*	*/
/*	struct bstNode* ptrRight = (struct bstNode*) malloc(sizeof(struct bstNode));*/
/*	ptrRight->data = 15;*/
/*	ptrRight->left = NULL;*/
/*	ptrRight->right = NULL;*/
/*	*/
/*	ptr->data = 10;*/
/*	ptr->left = ptrLeft;*/
/*	ptr->right = ptrRight;*/

/*	//enqueue root node, children left node and right node*/
/*	enqueue(ptr);*/
/*	enqueue(ptrLeft);*/
/*	enqueue(ptrRight);*/
/*	printQueue();*/
/*	*/
/*	dequeue();*/
/*	printQueue();*/
/*	dequeue();*/
/*	printQueue();*/
/*		dequeue();*/
/*	printQueue();*/
/*}*/
