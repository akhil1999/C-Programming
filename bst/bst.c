#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"
#include <stdbool.h>
#include <unistd.h>

int timesCalled = 0;
int numberOfNodes = 0;

struct bstNode* root;

struct bstNode* getNewNode(int data){
	struct bstNode* newNode = (struct bstNode*) malloc(sizeof(struct bstNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct bstNode* Insert(struct bstNode* root, int data){
	//tree empty, so create a new tree
	if(root == NULL){
		root = getNewNode(data);
	}else if(data <= root->data){
		root->left = Insert(root->left,data);
	}else{
		root->right = Insert(root->right,data);
	}
	return root;
}

bool bstSearch(struct bstNode* root, int data){
	if(root == NULL){
		return false;
	}else if(root->data == data){
		return true;
	}else if(data <= root->data){
		return bstSearch(root->left,data);
	}else{
		return bstSearch(root->right, data);
	}
}

int findMin(struct bstNode* root){
	int min = 0;
	if(root->left != NULL){
		min = findMin(root->left);
	}else{
		return root->data;
	}
}

int findMax(struct bstNode* root){
	int max = 0;
	if(root->right != NULL){
		max = findMax(root->right);
	}else{
		return root->data;
	}
}

int max(int a, int b){
	if(a > b){
		return a;
	}else if(a < b){
		return b;
	}else{
		return a;
	}
}

int findHeight(struct bstNode* root){
	timesCalled++;
	//return -1 if only one node detected / last node
	if(root == NULL) {
		return -1;
	}
	return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void findNodes(struct bstNode* root){
	if(root == NULL){
		return;
	}else{
		numberOfNodes++;
	}
	findNodes(root->left);
	findNodes(root->right);
}

//BFS
void levelOrderTraversal(struct bstNode* root){
	sleep(1);
	if(root==NULL){
		return;
	}
	while(!isQueueEmpty()){
		root = dequeue();
		if(root == NULL){
			break;
		} else {
			printf("%d,\n", root->data);
		}
		if(root->left != NULL){
			enqueue(root->left);
		}
		if(root->right != NULL){
			enqueue(root->right);
		}
	}
}

//DFS 1
void preorderTraversal(struct bstNode* root){
	if(root == NULL){
		return;
	}else{
		printf("%d\n", root->data);
	}
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

//DFS 2
void inorderTraversal(struct bstNode* root){
	if(root == NULL){
		return;
	}
	inorderTraversal(root->left);
	printf("%d\n", root->data);
	inorderTraversal(root->right);
}

//DFS 3
void postorderTraversal(struct bstNode* root){
	if(root == NULL){
		return;
	}
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d\n", root->data);
}

void main(){
	root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	root = Insert(root, 1);
	root = Insert(root, -69);
	root = Insert(root, 22);
	root = Insert(root, 23);
	printf("min:%d\n", findMin(root));
	printf("max:%d\n", findMax(root));
	printf("height:%d\n", findHeight(root));
	printf("times findHeight called:%d\n", timesCalled);
	findNodes(root);
	printf("number of nodes:%d\n", numberOfNodes);
/*	levelOrderTraversal(root);*/
	printf("isQueueEmpty?:%d\n", isQueueEmpty());

	enqueue(root);
/*	levelOrderTraversal(root);*/
	preorderTraversal(root);
/*	printQueue();*/
	postorderTraversal(root);
	inorderTraversal(root);
}
