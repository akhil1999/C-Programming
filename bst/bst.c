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

struct bstNode* findMinPtr(struct bstNode* root){
	printf("findMinPtr called\n");
	struct bstNode* min = NULL;
	if(root->left != NULL){
		min = findMinPtr(root->left);
	}else{
		return root;
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

int* array;
//custom inorder traversal to insert into array
void inorderTraversalToArray(struct bstNode* root){
	if(root == NULL){
		return;
	}
	inorderTraversalToArray(root->left);
	*(array) = root->data;
	array++;
	inorderTraversalToArray(root->right);
}

bool isBST(struct bstNode* root, int* array){
	int a[numberOfNodes];
	bool isBST = true;
	//feed the nodes value from inorder into an array
	for(int i=0; i<numberOfNodes-1; i++){
		if(array[i]>array[i+1]){
			isBST = false;
		}
	}
	return isBST;
}


//animesh sir based way
struct bstNode* Delete(struct bstNode* root, int data){
	printf("current node:%d\n", root->data);
	if(root == NULL){
		return root;
	}else if(data < root->data){
		root->left = Delete(root->left, data);
	}else if(data > root->data){
		root->right = Delete(root->right, data);
	}else{
		//case 1 : no child
		if(root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
		}
		
		//case 2: one child 
		else if(root->left == NULL){
			struct bstNode* temp = root;
			root = root->right;
			free(temp);
		}
		
		else if(root->right == NULL){
			struct bstNode* temp = root;
			root = root->left;
			free(temp);
		}
		
		else{
			struct bstNode* temp = findMinPtr(root->right);
			printf("min:%d\n", temp->data);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

//inorder successor



void main(){
	root = NULL;
/*	root = Insert(root, 15);*/
/*	root = Insert(root, 10);*/
/*	root = Insert(root, 20);*/
/*	root = Insert(root, 25);*/
/*	root = Insert(root, 8);*/
/*	root = Insert(root, 12);*/
/*	root = Insert(root, 1);*/
/*	root = Insert(root, -69);*/
/*	root = Insert(root, 22);*/
/*	root = Insert(root, 23);*/
/*	printf("min:%d\n", findMin(root));*/
/*	printf("max:%d\n", findMax(root));*/
/*	printf("height:%d\n", findHeight(root));*/
/*	printf("times findHeight called:%d\n", timesCalled);*/
/*	findNodes(root);*/
/*	printf("number of nodes:%d\n", numberOfNodes);*/
/*	levelOrderTraversal(root);*/
/*	printf("isQueueEmpty?:%d\n", isQueueEmpty());*/

/*	enqueue(root);*/
/*	levelOrderTraversal(root);*/
/*	preorderTraversal(root);*/
/*	printQueue();*/
/*	postorderTraversal(root);*/
/*	inorderTraversal(root);*/
	
	//custom array
/*	int a[numberOfNodes];*/

/*	array = &a[0];*/
/*	int* arrayPtr = &a[0];*/
/*	*/
/*	for(int i = 0 ; i < 10 ; i++) {*/
/*		*(arrayPtr+i) = 0;*/
/*	}*/
/*		*/
/*	inorderTraversalToArray(root);*/
/*	for(int i = 0 ; i < 10 ; i++) {*/
/*		printf("%d,", *(arrayPtr+i));*/
/*	}*/
/*	*/
/*	printf("isBST?:%d", isBST(root, arrayPtr));*/
	root = Insert(root, 12);
	root = Insert(root, 5);
	root = Insert(root, 3);
	root = Insert(root, 1);
	root = Insert(root, 7);
	root = Insert(root, 9);
	root = Insert(root, 8);
	root = Insert(root, 11);
	root = Insert(root, 15);
	root = Insert(root, 13);
	root = Insert(root, 14);
	root = Insert(root, 17);
	root = Insert(root, 20);
	root = Insert(root, 18);

	preorderTraversal(root);
	
	Delete(root, 17);
	printf("\n");
	preorderTraversal(root);
}
